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
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>

//Constantes
#define SCK_PIN 14 //numéro de broche sck de l'esp32
#define MISO_PIN 2 //numéro de broche MISO de l'esp32
#define MOSI_PIN 15 //numéro de broche MOSI de l'esp32
#define CS_PIN 13 //numéro de broche CS de l'esp32

#define IP_LOCAL IPAddress(192,168,5,1) //adresse ip local de l'esp
#define GATEWAY IPAddress(192,168,5,1) //passerelle
#define MASQUE IPAddress(255,255,255,0) //masque de sous-réseaux

const char *ssid = "BallonSonde";
const char *password = "BallonSonde2021";

// Globales
Sigfox BallonSig(27, 26, true);
File fichierCSV;
AsyncWebServer server(80);
WebSocketsServer ws(81);
typeDonnees lesDonnees;

char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <title>Page WEB esp32</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script type="text/javascript">
            function coderEtEnvoyer()
            {
                coderTrame();
                setTimeout(function ()
                {
                    document.getElementById("Texte2").innerHTML = "2eTestDeTexteDansLeDiv";
                }, 5000);
            }
            ;

            function coderTrame() {
                document.getElementById("texteDonnees").innerHTML = "testTexteDansLaDiv";
            }
            ;

        </script>
    </head>
    <body>
        <div id="texteDonnees"></div>
        <div id="Texte2"></div>
        <input type="button" name="boutonEnvoyer" value="EnvoyerTrame" onclick="coderEtEnvoyer()">
    </body>
</html>

)=====";

/***********************************************************
 * Fonctions
 */

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Page Not found");
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch (type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
        {
            IPAddress ip = ws.remoteIP(num);
            Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

            // send message to client
            ws.sendTXT(num, "Connected from server");
        }
            break;
        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);
            String message = String((char*) (payload));
            Serial.println(message);

    }
}

// Création d'un mutex
SemaphoreHandle_t mutex = NULL;

void tacheSigfox(void *pvParameters) // <- une tâche
{
    delay(30000);

    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    BallonSig.begin();

    for (;;) // <- boucle infinie
    {
        // Verrouillage du mutex
        xSemaphoreTake(mutex, portMAX_DELAY);

        BallonSig.coderTrame(lesDonnees.position, lesDonnees.DonneesCapteurs);
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
        sDonnees += String(lesDonnees.DonneesCapteurs.humidite) + ";";

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

    server.on("/", [](AsyncWebServerRequest * request) {

        request->send_P(200, "text/html", webpage);
    });

    server.onNotFound(notFound);

    server.begin();
    ws.begin();
    ws.onEvent(webSocketEvent);

    for (;;) // <- boucle infinie
    {
        ws.loop();

        if (lesDonnees.position.altitude >= 2000) {
            WiFi.softAPdisconnect(true);
        }


        if (WiFi.softAPgetStationNum() == 0) {
            delay(50000); //attendre 5 minutes
            if (WiFi.softAPgetStationNum() == 0) //si toujours aucun client
            {
                WiFi.softAPdisconnect(false); //deconnecter le wifi
            }
        }
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(30000)); // toutes les 30000 ms = 30 secondes
    }
}

void setup() {

    Serial.begin(115200); //initialisation de la liaison série à l'esp32
    delay(1000);

    //initialisation du mutex
    mutex = xSemaphoreCreateMutex();

    // Configuration et création du point d'accès
    WiFi.softAPConfig(IP_LOCAL, GATEWAY, MASQUE);
    WiFi.softAP(ssid, password);

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
            20000, /* Stack size of task */
            NULL, /* parameter of the task */
            2, /* priority of the task */
            NULL); /* Task handle to keep track of created task */

}

void loop() {
    ws.loop();
} 