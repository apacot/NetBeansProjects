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
        /*//conversion des donnees en chaine de caractère pour enregristrement dans la carte SD
        String sAltitude = String(donneesGPS.altitude);
        String sLatitude = String(donneesGPS.latitude);
        String sLongitude = String(donneesGPS.longitude);

        String sAnnee = String(laDate.annee);
        String sMois = String(laDate.mois);
        String sJour = String(laDate.jour);

        String sHeure = String(lHeure.heure);
        String sMinute = String(lHeure.minute);
        String sSeconde = String(lHeure.seconde);

        String sCpm = String(donneesCapteurs.cpm);
        String sPression = String(donneesCapteurs.pression);
        String sTemp = String(donneesCapteurs.temperature);
        String sHumidite = String(donneesCapteurs.humidite);*/

        /* //construction de la ligne de données à enregistrer dans la carte SD
         String messageSD = sAnnee + "-" + sMois + "-" + sJour + ";" + sHeure + ":" + sMinute + ":" + sSeconde + ";" + sLatitude
                 + ";" + sLongitude + ";" + sAltitude + ";" + sTemp + ";" + sPression + ";" + sCpm + ";" + sHumidite + ";";*/

        fichierCSV = SD.open("/TestCSV.csv", FILE_APPEND); //ouverture du fichier en modification
        if (!fichierCSV) {
            Serial.println("Echec ouverture du fichier");
        }
        if (fichierCSV.println("2021-05-03;09:57:48;48.508944;-2.762288;17051;-12;62;856;33;")) //écriture de la ligne de données dans la carte SD
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
    lesDonnees.date.mois = 04;
    lesDonnees.date.jour = 02;

    lesDonnees.heures.heure = 14;
    lesDonnees.heures.minute = 20;
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