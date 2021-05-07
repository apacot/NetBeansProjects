/* 
 * File:   main.ino.cpp
 * Author: PACOT ANTOINE
 *
 * Created on 26 avril 2021, 13:57
 */

#include "sigfox.h"
#include <SD.h>
#include <WiFi.h>
#include <SPI.h>
#include <FS.h>

#define SCK_PIN 14 //numéro de broche sck de l'esp32
#define MISO_PIN 2 //numéro de broche MISO de l'esp32
#define MOSI_PIN 15 //numéro de broche MOSI de l'esp32
#define CS_PIN 3 //numéro de broche CS de l'esp32

Sigfox BallonSig(27, 26, true);
File fichierCSV;
const char *ssid = "BallonSondeAP";
const char *password = "totototo";
const int broche_CS = 13; //broche cs du module SD connecté à l'esp
typeDonnees lesDonnees;

void tacheSigfox(void *pvParameters) // <- une tâche
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    BallonSig.begin();

    for (;;) // <- boucle infinie
    {
        BallonSig.coderTrame(lesDonnees.position, lesDonnees.DonneesCapteurs);
        BallonSig.envoyer(BallonSig.trame, sizeof (BallonSig.trame));
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(600000)); // toutes les 600000 ms = 10 minutes
    }
}

void tacheCarteSD(void *pvParameters) // <- une tâche
{

    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
    delay(10);

    //initialisation CarteSD
    if (!SD.begin(CS_PIN, SPI, 4000000, "/sd")) {
        Serial.println("Erreur montage Carte SD");
        return;
    }

    for (;;) // <- boucle infinie
    {

        //Conversion + construction de la ligne de données à enregistrer dans la carte SD
        //conversion de la date
        String sDonnees = String(lesDonnees.date.annee)  + "-";
        sDonnees += (lesDonnees.date.mois<10 ? "0" +String(lesDonnees.date.mois):String(lesDonnees.date.mois)) + "-";
        sDonnees += String(lesDonnees.date.jour) + ";";
        
        //conversion de l'heure
        sDonnees += String(lesDonnees.heures.heure) + ":";
        sDonnees += String(lesDonnees.heures.minute) + ":";
        sDonnees += String(lesDonnees.heures.seconde) + ";";
        
        //conversion de la position
        sDonnees += String(lesDonnees.position.latitude) + ";";
        sDonnees += String(lesDonnees.position.longitude) + ";";
        sDonnees += String(lesDonnees.position.altitude) + ";";
        
        //conversion des données des capteurs
        sDonnees += String(lesDonnees.DonneesCapteurs.temperature) + ";";
        sDonnees += String(lesDonnees.DonneesCapteurs.pression) + ";";
        sDonnees += String(lesDonnees.DonneesCapteurs.cpm) +";";
        sDonnees += String(lesDonnees.DonneesCapteurs.humidite) +";";

        fichierCSV = SD.open("/TestCSV.csv", FILE_APPEND); //ouverture du fichier en modification
        if (!fichierCSV) {
            Serial.println("Echec ouverture du fichier");
        }
        if (fichierCSV.println(sDonnees)) //écriture de la ligne de données dans la carte SD
        {
            Serial.println("Donnee enregistrée");
        } else {
            Serial.println("pb enregistrement donnee");
        }
        fichierCSV.close();

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(10000)); // toutes les 60000 ms = 1 minute
    }
}

void tachePageWeb(void *pvParameters) // <- une tâche
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    
    for (;;) // <- boucle infinie
    {
        if (lesDonnees.position.altitude >= 2000) {
            WiFi.softAPdisconnect(true);
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(30000)); // toutes les 30000 ms = 30 secondes
    }
}

void setup() {
    Serial.begin(115200); //initialisation de la liaison série à l'esp32

    WiFi.softAPConfig(IPAddress(192, 168, 5, 1), IPAddress(192, 168, 5, 1), IPAddress(255, 255, 255, 0));
    WiFi.softAP(ssid, password); //création du point d'accès WIFI

    //simulation de données
    
    lesDonnees.position.altitude = 17051;
    lesDonnees.position.latitude = 48.508944;
    lesDonnees.position.longitude = -2.762288;

    lesDonnees.date.annee = 2021;
    lesDonnees.date.mois = 05;
    lesDonnees.date.jour = 07;

    lesDonnees.heures.heure = 15;
    lesDonnees.heures.minute = 36;
    lesDonnees.heures.seconde = 40;

    lesDonnees.DonneesCapteurs.cpm = 856;
    lesDonnees.DonneesCapteurs.pression = 62;
    lesDonnees.DonneesCapteurs.temperature = -12;
    lesDonnees.DonneesCapteurs.humidite = 33;

    xTaskCreate(
            tacheSigfox, /* Task function. */
            "tacheSigfox", /* name of task. */
            10000, /* Stack size of task */
            NULL, /* parameter of the task */
            1, /* priority of the task */
            NULL); /* Task handle to keep track of created task */

    xTaskCreate(
            tacheCarteSD, /* Task function. */
            "tacheCarteSD", /* name of task. */
            10000, /* Stack size of task */
            NULL, /* parameter of the task */
            1, /* priority of the task */
            NULL); /* Task handle to keep track of created task */

    xTaskCreate(
            tachePageWeb, /* Task function. */
            "tachePageWeb", /* name of task. */
            10000, /* Stack size of task */
            NULL, /* parameter of the task */
            1, /* priority of the task */
            NULL); /* Task handle to keep track of created task */

}

void loop() {

} 