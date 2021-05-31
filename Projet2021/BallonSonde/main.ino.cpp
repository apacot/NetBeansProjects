/* 
 * File:   main.ino.cpp
 * Author: PACOT ANTOINE
 *
 * Created on 26 avril 2021, 13:57
 */

#include <Arduino.h>
#include "sigfox.h"
#include <SD.h>
#include <WiFi.h>
#include <SPI.h>
#include <FS.h>
#include <string>
#include <WebServer.h>

//Constantes
#define SCK_PIN 14 //numéro de broche sck de l'esp32
#define MISO_PIN 2 //numéro de broche MISO de l'esp32
#define MOSI_PIN 15 //numéro de broche MOSI de l'esp32
#define CS_PIN 13 //numéro de broche CS de l'esp32

//configuration réseau pour le point d'accès WiFi
#define IP_LOCAL IPAddress(192,168,5,1) //adresse ip local de l'esp
#define GATEWAY IPAddress(192,168,5,1) //passerelle
#define MASQUE IPAddress(255,255,255,0) //masque de sous-réseaux

//ssid = nom du point d'accès et password = mot de passe
//pour le point d'accès WiFi
const char *ssid = "BallonSondeAP";
const char *password = "BallonSonde2021";

// Globales
Sigfox BallonSig(27, 26, true);
File fichierCSV;
SemaphoreHandle_t mutex = NULL; // Création d'un mutex
typeDonnees lesDonnees; //les données de la structure typeDonnees
WebServer serveur(80);
String pageWeb;

String convertirDonnees(typeDonnees lesDonnees){
    //Conversion + construction de la ligne de données à enregistrer dans la carte SD
        //conversion de la date
        String sDonnees = String(lesDonnees.date.annee) + "-";
        //si numéro du mois inférieur à 10 alors, ajout d'un 0 devant sinon, on ne fais rien 
        sDonnees += (lesDonnees.date.mois < 10 ? "0" + String(lesDonnees.date.mois) : String(lesDonnees.date.mois)) + "-";
        if (lesDonnees.date.jour < 10) {
            sDonnees += "0" + String(lesDonnees.date.jour) + " ";
        } else {
            sDonnees += String(lesDonnees.date.jour) + " ";
        }


        //conversion de l'heure
        if (lesDonnees.heures.heure < 10) {
            sDonnees += "0" + String(lesDonnees.heures.heure) + ":";
        } else {
            sDonnees += String(lesDonnees.heures.heure) + ":";
        }
        if (lesDonnees.heures.minute < 10) {
            sDonnees += "0" + String(lesDonnees.heures.minute) + ":";
        } else {
            sDonnees += String(lesDonnees.heures.minute) + ":";
        }
        if (lesDonnees.heures.seconde < 10) {
            sDonnees += "0" + String(lesDonnees.heures.seconde) + ";";
        } else {
            sDonnees += String(lesDonnees.heures.seconde) + ";";
        }

        //conversion de la position
        sDonnees += String(lesDonnees.position.latitude,{6}) + ";";
        sDonnees += String(lesDonnees.position.longitude,{6}) + ";";
        sDonnees += String(lesDonnees.position.altitude,{0}) + ";";

        //conversion des données des capteurs
        sDonnees += String(lesDonnees.DonneesCapteurs.temperature) + ";";
        sDonnees += String(lesDonnees.DonneesCapteurs.pression) + ";";
        sDonnees += String(lesDonnees.DonneesCapteurs.cpm) + ";";
        sDonnees += String(lesDonnees.DonneesCapteurs.humidite) + ";\n";
        
        return sDonnees;
}

void handleRoot() {

    pageWeb = "<!DOCTYPE html>"; //début page HTML
    pageWeb += "<head>";
    pageWeb += "<title>Ballon2021</title>";
    pageWeb += "<meta charset='UTF-8'>";
    pageWeb += "<meta name='viewport' content= width=device-width, initial-scale=1.0>";
    pageWeb += "</head>";
    pageWeb += "<body>";
    pageWeb += "<div> <h1> BALLON SONDE 2021 </h1> </div>";
    pageWeb += "<div><h2> Date : <span> " + String(lesDonnees.date.jour) + "/" + String(lesDonnees.date.mois) + "/" + String(lesDonnees.date.annee) + "</span></h2>";
    pageWeb += "<h2> Heure : <span>" + String(lesDonnees.heures.heure) + ":" + String(lesDonnees.heures.minute) + ":" + String(lesDonnees.heures.seconde) + "</span></h2>";
    pageWeb += "<h2> Latitude : <span>" + String(lesDonnees.position.latitude) + "</span></h2>";
    pageWeb += "<h2> Longitude : <span>" + String(lesDonnees.position.longitude) + "</span></h2>";
    pageWeb += "<h2> Altitude (m): <span>" + String(lesDonnees.position.altitude) + "</span></h2>";
    pageWeb += "<h2> Température (°C) : <span>" + String(lesDonnees.DonneesCapteurs.temperature) + "</span></h2>";
    pageWeb += "<h2> Pression (hpa) : <span>" + String(lesDonnees.DonneesCapteurs.pression) + "</span></h2>";
    pageWeb += "<h2> Radiation (cpm) : <span>" + String(lesDonnees.DonneesCapteurs.cpm) + "</span></h2>";
    pageWeb += "<h2> Humidité (%) : <span>" + String(lesDonnees.DonneesCapteurs.humidite) + "</span></h2></div>";
    
    pageWeb += "<form action = '' method = 'get' >";
    pageWeb += "<input type = 'submit' name = 'boutonEnvoyer' value = 'EnvoyerTrame'>";
    pageWeb += "</form>";
    pageWeb += "</body";
    pageWeb += "</html>";

    serveur.send(200, "text/html", pageWeb);
}

void handle_NotFound() { // Page Not found
    serveur.send(404, "text/plain", "404: Not found");
}

void tacheSigfox(void *pvParameters) // <- une tâche
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    BallonSig.begin();

    for (;;) // <- boucle infinie
    {
        // Verrouillage du mutex
        xSemaphoreTake(mutex, portMAX_DELAY);

        BallonSig.coderTrame(lesDonnees);
        BallonSig.envoyer(BallonSig.trame, sizeof (BallonSig.trame));

        // Déverrouillage du mutex
        xSemaphoreGive(mutex);

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(600000)); // toutes les 600000 ms = 10 minutes
    }
}

void tacheCarteSD(void *pvParameters) // <- une tâche
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    //initialisation systeme de fichier
    SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
    delay(10);

    //initialisation CarteSD
    if (!SD.begin(CS_PIN, SPI, 4000000, "/sd")) {
        Serial.println("Erreur montage Carte SD");
        return;
    }

    for (;;) // <- boucle infinie
    {
        // Verrouillage du mutex
        xSemaphoreTake(mutex, portMAX_DELAY);

        String sDonnees = convertirDonnees(lesDonnees);

        fichierCSV = SD.open("/TestCSV.csv", FILE_APPEND); //ouverture du fichier en modification
        if (!fichierCSV) {
            Serial.print("Echec ouverture du fichier\n");
        }
        if (fichierCSV.println(sDonnees)) //écriture de la ligne de données dans la carte SD
        {
            Serial.print("Donnee enregistrée\n");
        } else {
            Serial.print("pb enregistrement donnee\n");
        }
        fichierCSV.close();

        // Déverrouillage du mutex
        xSemaphoreGive(mutex);

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(60000)); // toutes les 60000 ms = 1 minute


    }
}

void tachePageWeb(void *pvParameters) // <- une tâche
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    
    serveur.on("/", handleRoot); // Chargement de la page accueil
    serveur.onNotFound(handle_NotFound); // Chargement de la page Not found
    serveur.begin();

    for (;;) // <- boucle infinie
    {
        serveur.handleClient(); //attente de demande du client
        
        if (lesDonnees.position.altitude >= 2000) {
            WiFi.mode(WIFI_OFF);
        }
        
        if(WiFi.softAPgetStationNum() ==0 )
        {
            delay(30000);
            if(WiFi.softAPgetStationNum() ==0 )
            {
                WiFi.mode(WIFI_OFF);
            }             
        }
        
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(10)); // toutes les 10 ms
    } 
}


void setup() {

    Serial.begin(115200); //initialisation de la liaison série à l'esp32
    delay(1000);

    //initialisation du mutex
    mutex = xSemaphoreCreateMutex();

    WiFi.persistent(false);
    
    // Configuration et création du point d'accès
    WiFi.softAPConfig(IP_LOCAL, GATEWAY, MASQUE);
    WiFi.softAP(ssid, password,1,false,1);

    //simulation de données

    lesDonnees.position.altitude = 1050;
    lesDonnees.position.latitude = 48.508944;
    lesDonnees.position.longitude = -2.762288;

    lesDonnees.date.annee = 2021;
    lesDonnees.date.mois = 05;
    lesDonnees.date.jour = 21;

    lesDonnees.heures.heure = 15;
    lesDonnees.heures.minute = 36;
    lesDonnees.heures.seconde = 40;

    lesDonnees.DonneesCapteurs.cpm = 6;
    lesDonnees.DonneesCapteurs.pression = 1005;
    lesDonnees.DonneesCapteurs.temperature = 20;
    lesDonnees.DonneesCapteurs.humidite = 33;

    /*
    xTaskCreate(
              tacheSigfox, // Task function.
              "tacheSigfox", // name of task. 
              10000, // Stack size of task 
              NULL, // parameter of the task 
              1, // priority of the task 
              NULL); // Task handle to keep track of created task 
     */
    /*
    xTaskCreate(
            tacheCarteSD, //Task function. 
            "tacheCarteSD", //name of task. 
            10000, //Stack size of task 
            NULL, //parameter of the task
            1, //priority of the task 
            NULL); //Task handle to keep track of created task
    */
    xTaskCreate(
            tachePageWeb, // Task function
            "tachePageWeb", // name of task
            40000, // Stack size of task
            NULL, // parameter of the task
            1, // priority of the task
            NULL); // Task handle to keep track of created task

}

void loop() {
    
    //gestion du serveur web
  serveur.handleClient();
  if (lesDonnees.position.altitude > 2000) // si l'altitude est supérieur à 2000 mètres, coupure du wifi et interruption du serveur web
  {
    serveur.stop();
    WiFi.mode(WIFI_OFF);
  }

}
