#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include <FS.h>

#define SCK_PIN 14 //numéro de broche sck de l'esp32
#define MISO_PIN 2 //numéro de broche MISO de l'esp32
#define MOSI_PIN 15 //numéro de broche MOSI de l'esp32
#define CS_PIN 13 //numéro de broche CS de l'esp32

File fichierCSV;



void setup() {
    //initialisation connexion à l'esp
    Serial.begin(115200);
    
    SPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);
    delay(10);
    
    //initialisation CarteSD
    if (!SD.begin(CS_PIN, SPI, 4000000, "/sd"))
    {
        Serial.println("Erreur montage Carte SD");
        return;
    }
}

void loop() 
{
    fichierCSV = SD.open("/TestCSV.csv", FILE_APPEND);
    if(!fichierCSV)
    {
        Serial.println("Echec ouverture du fichier");
    }
    if(fichierCSV.println("2021-04-30;18:06:15;47,859968;5.456875;29999;5;62;856;38"))
    {
        Serial.println("Donnee enregistrée");
    }
    else
    {
        Serial.println("pb enregistrement donnee");
    }
    fichierCSV.close();
    delay(60000);
}