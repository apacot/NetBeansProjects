/**
 * @file taches.cpp
 * @brief Implémentation de la classe Taches
 * @version 1.0
 * @author Sofiane SABRI
 * @date 20/05/2021
 * @details Classe qui regroupe l'ensemble des taches utilisées 
 */

#include "taches.h"
#include <Arduino.h>
#include <Wire.h>
#include <BME280I2C.h>
#include <RadiationWatch.h>
#include <TinyGPS.h>
#include <SPI.h>
#include <FS.h>
#include <SD.h>
#include <WiFi.h>
#include <HardwareSerial.h>
#include "sigfox.h"
#include <string>
#include <WebServer.h>

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

SemaphoreHandle_t mutex;
RadiationWatch radiationWatch(32, 33);
TinyGPS gps;
HardwareSerial serialGps(SERIALGPS); // sur hardware serial 1
Sigfox BallonSig(27, 26, true);
File fichierCSV;
int compteurGPS = 0;
WebServer serveur(80);
String pageWeb;

/**
 * @brief Taches::Taches() constructeur de la classe Taches
 */

Taches::Taches() {

    mutex = xSemaphoreCreateMutex();

}

/**
 * @brief onRadiation() fonction de la classe RadiationWatch.h pour la récupération de données
 */

void onRadiation() {

    radiationWatch.uSvh();
    radiationWatch.uSvhError();
    radiationWatch.cpm();

}

/**
 * @brief Taches::tacheBME280 Reception des données du capteur BME280 et enregistrement dans la structure partagée
 * @param parameter
 */
void Taches::tacheBME280(void* parameter) {
    BME280I2C::Settings settings(
            BME280::OSR_X1,
            BME280::OSR_X1,
            BME280::OSR_X1, BME280::Mode_Forced,
            BME280::StandbyTime_1000ms,
            BME280::Filter_Off,
            BME280::SpiEnable_False,
            BME280I2C::I2CAddr_0x77 // 0x77 I2C address pour BME 280 Adafruit.
            );
    typeDonnees *capteurBme = (typeDonnees *) parameter;
    BME280I2C bme(settings);
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    while (!Serial) {
    } // Wait

    Wire.begin();

    while (!bme.begin()) {
        Serial.println("Could not find BME280 sensor!");
        delay(1000);
    }

    switch (bme.chipModel()) {
        case BME280::ChipModel_BME280:
            Serial.println("Found BME280 sensor! Success.");
            break;
        case BME280::ChipModel_BMP280:
            Serial.println("Found BMP280 sensor! No Humidity available.");
            break;
        default:
            Serial.println("Found UNKNOWN sensor! Error!");
    }
    for (;;) {

        float temp(NAN), hum(NAN), pres(NAN);
        BME280::TempUnit tempUnit(BME280::TempUnit_Celsius);
        BME280::PresUnit presUnit(BME280::PresUnit_hPa);

        bme.read(pres, temp, hum, tempUnit, presUnit);
        //ouverture du mutex
        xSemaphoreTake(mutex, portMAX_DELAY);
        capteurBme->DonneesCapteurs.temperature = temp;
        capteurBme->DonneesCapteurs.humidite = hum;
        capteurBme->DonneesCapteurs.pression = pres;
        //fermeture du mutex
        xSemaphoreGive(mutex);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(60000)); // reveille toutes les 60s
    }


}

/**
 * @brief Taches::tacheGPS Reception des données du GPS et enregistrement dans la structure partagée
 * @param parameter
 */
void Taches::tacheGPS(void* parameter) {
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    typeDonnees *capteurGps = (typeDonnees *) parameter;
    serialGps.begin(4800, SERIAL_8N1, 16, 17);
    Serial.print("Simple TinyGPS library v. ");
    Serial.println(TinyGPS::library_version());
    float lat, lon, alt;
    unsigned long date, time;
    unsigned long age;
    //HEURE
    byte seconde;
    byte minute;
    byte heure;
    //DATE
    byte jour;
    byte mois;
    byte hundredths;
    int annee;
    bool newData = false;
    unsigned long chars;
    unsigned short sentences, failed;
    for (;;) {

        // Pendant une seconde lecture des caractères envoyés par le GPS
        for (unsigned long start = millis(); millis() - start < 1000;) {
            while (serialGps.available()) {
                char c = serialGps.read();
                // Serial.write(c);   
                if (gps.encode(c)) // si des caratères sont reçus alors newdata = true
                    newData = true;
            }
        }
        if (newData) {

            gps.f_get_position(&lat, &lon, &age);
            gps.get_datetime(&date, &time, &age);
            gps.crack_datetime(&annee, &mois, &jour, &heure, &minute, &seconde, &hundredths, &age);
            alt = gps.f_altitude();
            heure = heure + 2;
            //ouverture du mutex
            xSemaphoreTake(mutex, portMAX_DELAY);
            capteurGps->position.latitude = lat;
            capteurGps->position.longitude = lon;
            capteurGps->position.altitude = alt;
            capteurGps->date.jour = jour;
            capteurGps->date.mois = mois;
            capteurGps->date.annee = annee;
            capteurGps->heures.heure = heure;
            capteurGps->heures.minute = minute;
            capteurGps->heures.seconde = seconde;

            //fermeture du mutex
            xSemaphoreGive(mutex);
        }

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(60000)); // reveille toutes les 60s



    }

}

/**
 * @brief Taches::tacheRadiations Reception des données du capteur de radiations et enregistrement dans la structure partagée
 * @param parameter
 */
void Taches::tacheRadiations(void* parameter) {
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    typeDonnees *capteurRadiation = (typeDonnees *) parameter;
    radiationWatch.setup();

    //Register the callbacks.
    radiationWatch.registerRadiationCallback(&onRadiation);

    for (;;) {

        radiationWatch.loop();
        //Ouverture du mutex
        xSemaphoreTake(mutex, portMAX_DELAY);
        capteurRadiation->DonneesCapteurs.cpm = radiationWatch.cpm();
        //fermeture du mutex

        xSemaphoreGive(mutex);

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(60000)); // reveille toutes les 60s

    }

}

/**
 * @brief Taches::tacheAffichage affichage des données de la structure partagée
 * @param parameter
 */
void Taches::tacheAffichage(void* parameter) {
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    //delay(5000);
    typeDonnees *data = (typeDonnees *) parameter;

    for (;;) {
        //ouverture du mutex
        xSemaphoreTake(mutex, portMAX_DELAY);
        //GPS
        Serial.print("LAT: ");
        Serial.print(data->position.latitude, 6);
        Serial.println(" ");
        Serial.print("LON: ");
        Serial.print(data->position.longitude, 6);
        Serial.println(" ");
        Serial.print("ALT: ");
        Serial.print(data->position.altitude);
        Serial.println(" ");
        Serial.print("date: ");
        Serial.print(data->date.jour);
        Serial.print("/");
        Serial.print(data->date.mois);
        Serial.print("/");
        Serial.print(data->date.annee);
        Serial.println(" ");
        Serial.print("heure: ");
        Serial.print(data->heures.heure);
        Serial.print("h");
        Serial.print(data->heures.minute);
        Serial.print("m");
        Serial.print(data->heures.seconde);
        Serial.print("s");
        Serial.println(" ");
        //Radiations
        Serial.print("CPM: ");
        Serial.print(data->DonneesCapteurs.cpm);
        Serial.println(" ");
        //BME280
        Serial.print("Temperature: ");
        Serial.print(data->DonneesCapteurs.temperature);
        Serial.print("°C");
        Serial.println(" ");
        Serial.print("Humidité: ");
        Serial.print(data->DonneesCapteurs.humidite);
        Serial.print("%HR");
        Serial.println(" ");
        Serial.print("Pression: ");
        Serial.print(data->DonneesCapteurs.pression);
        Serial.print("hPa");
        Serial.println(" ");
        //fermeture du mutex
        xSemaphoreGive(mutex);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(60000)); // reveille toutes les 60s
    }

}

/**
 * @brief Taches::tacheSigfox envoi d'un message sigfox avec les données de la structure partagée
 * @param parameter
 */
void Taches::tacheSigfox(void* parameter) {


    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    typeDonnees *dataSigfox = (typeDonnees *) parameter;
    BallonSig.begin();

    for (;;) // <- boucle infinie
    {
        // Verrouillage du mutex
        xSemaphoreTake(mutex, portMAX_DELAY);

        BallonSig.coderTrame(dataSigfox);
        // Déverrouillage du mutex
        xSemaphoreGive(mutex);
        BallonSig.envoyer(BallonSig.trame, sizeof (BallonSig.trame));




        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(600000)); // toutes les 600000 ms = 10 minutes
    }
}

/**
 * @brief Taches::tacheCarteSD 
 * @param parameter
 */

void Taches::tacheCarteSD(void* parameter) 
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    typeDonnees *dataSD = (typeDonnees *) parameter;
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
        String sDonnees = String(dataSD->date.annee) + "-";
        //si numéro du mois inférieur à 10 alors, ajout d'un 0 devant sinon, on ne fais rien 
        sDonnees += (dataSD->date.mois < 10 ? "0" + String(dataSD->date.mois) : String(dataSD->date.mois)) + "-";
        if (dataSD->date.jour < 10) {
            sDonnees += "0" + String(dataSD->date.jour) + " ";
        } else {
            sDonnees += String(dataSD->date.jour) + " ";
        }


        //conversion de l'heure
        if (dataSD->heures.heure < 10) {
            sDonnees += "0" + String(dataSD->heures.heure) + ":";
        } else {
            sDonnees += String(dataSD->heures.heure) + ":";
        }
        if (dataSD->heures.minute < 10) {
            sDonnees += "0" + String(dataSD->heures.minute) + ":";
        } else {
            sDonnees += String(dataSD->heures.minute) + ":";
        }
        if (dataSD->heures.seconde < 10) {
            sDonnees += "0" + String(dataSD->heures.seconde) + ";";
        } else {
            sDonnees += String(dataSD->heures.seconde) + ";";
        }

        //conversion de la position
        sDonnees += String(dataSD->position.latitude, {
            6
        }) + ";";
        sDonnees += String(dataSD->position.longitude, {
            6
        }) + ";";
        sDonnees += String(dataSD->position.altitude, {
            0
        }) + ";";

        //conversion des données des capteurs
        sDonnees += String(dataSD->DonneesCapteurs.temperature) + ";";
        sDonnees += String(dataSD->DonneesCapteurs.pression) + ";";
        sDonnees += String(dataSD->DonneesCapteurs.cpm) + ";";
        sDonnees += String(dataSD->DonneesCapteurs.humidite) + ";";
        //sDonnees += String(compteurGPS) + ";";

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

void handleRoot(typeDonnees *lesDonnees) {

    pageWeb = "<!DOCTYPE html>";
    pageWeb += "<head>";
    pageWeb += "<title>Ballon2021</title>";
    pageWeb += "<meta charset='UTF-8'>";
    pageWeb += "<meta name='viewport' content= width=device-width, initial-scale=1.0>";
    pageWeb += "<script>";
    pageWeb += "function afficherData() {";
    pageWeb += "document.getElementById('Date').innerHTML = '" + String(lesDonnees->date.jour) + "/" + String(lesDonnees->date.mois) + "/" + String(lesDonnees->date.annee) + "';";
    pageWeb += "document.getElementById('Heure').innerHTML = '" + String(lesDonnees->heures.heure) + ":" + String(lesDonnees->heures.minute) + ":" + String(lesDonnees->heures.seconde) + "';";
    pageWeb += "document.getElementById('Longitude').innerHTML = '" + String(lesDonnees->position.latitude,{6}) + "';";
    pageWeb += "document.getElementById('Latitude').innerHTML = '" + String(lesDonnees->position.longitude,{6}) + "';";
    pageWeb += "document.getElementById('Altitude').innerHTML = '" + String(lesDonnees->position.altitude) + "';";
    pageWeb += "document.getElementById('Temperature').innerHTML = '" + String(lesDonnees->DonneesCapteurs.temperature) +"';";
    pageWeb += "document.getElementById('Pression').innerHTML = '" + String(lesDonnees->DonneesCapteurs.pression) + "';";
    pageWeb += "document.getElementById('Radiation').innerHTML = '" + String(lesDonnees->DonneesCapteurs.cpm) + "';";
    pageWeb += "document.getElementById('Humidite').innerHTML = '" + String(lesDonnees->DonneesCapteurs.humidite) + "';";
    pageWeb += "}";
    pageWeb += "setInterval('afficherData()', 10000);";
    pageWeb += "</script>";
    pageWeb += "</head>";
    pageWeb += "<body>";
    pageWeb += "<div> <h1> BALLON SONDE 2021 </h1></div>";
    pageWeb += "<div><h2> Date : <span id = 'Date'></span></h2>";
    pageWeb += "<h2> Heure : <span id = 'Heure'></span></h2>";
    pageWeb += "<h2> Latitude : <span id = 'Latitude'></span></h2>";
    pageWeb += "<h2> Longitude : <span id = 'Longitude'></span></h2>";
    pageWeb += "<h2> Altitude (m): <span id = 'Altitude'></span></h2>";
    pageWeb += "<h2> Température (°C) : <span id = 'Temperature'></span></h2>";
    pageWeb += "<h2> Pression (hpa) : <span id = 'Pression'></span></h2>";
    pageWeb += "<h2> Radiation (cpm) : <span id = 'Radiation'></span></h2>";
    pageWeb += "<h2> Humidité (%HR) : <span id = 'Humidite'></span></h2></div>";

    pageWeb += "<form action = '/form' method = 'get'>";
    pageWeb += "<input type = 'submit' ID = 'boutonEnvoyer' value = 'EnvoyerTrame'>";
    pageWeb += "</form>";
    pageWeb += "</body";
    pageWeb += "</html>";

    serveur.send(200, "text/html", pageWeb);
}

void handleForm(typeDonnees *lesDonnees) {
    
    BallonSig.coderTrame(lesDonnees);
    bool ret = BallonSig.envoyer(BallonSig.trame, sizeof (BallonSig.trame));

    String pageOK;
    //bool ret = true;
    
    if (ret) {
        pageOK += "Trame envoyee avec succes";
    } else {
        pageOK += "Trame non envoyee, revenez sur la page precedente";
    }
    serveur.send(200, "text/plain", pageOK);
}

void handle_NotFound() { // Page Not found
    serveur.send(404, "text/plain", "404: Not found");
}

void Taches::tachePageWeb(void* parameter) // <- une tâche
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    typeDonnees *dataPageWeb = (typeDonnees *) parameter;

    serveur.on("/", handleRoot(dataPageWeb)); // Chargement de la page accueil
    serveur.on("/form", handleForm(dataPageWeb));
    serveur.onNotFound(handle_NotFound); // Chargement de la page Not found
    serveur.begin();

    for (;;) // <- boucle infinie
    {
        serveur.handleClient(); //attente de demande du client

        if (dataPageWeb->position.altitude >= 2000) {
            WiFi.mode(WIFI_OFF);
        }

        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(60000)); // toutes les 10 ms
    }
}


