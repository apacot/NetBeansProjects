#include <Arduino.h> 
#include <WiFi.h>
const char *ssid = "ESP32AP";
const char *password = "totototo";

void setup() 
{
    Serial.begin(115200);
    delay(1000);
    Serial.println("\n");
    Serial.print("Creation du Point d'acces ...");
    WiFi.softAPConfig(IPAddress(192, 168, 5, 1), IPAddress(192, 168, 5, 1),IPAddress(255, 255, 255, 0));
    WiFi.softAP(ssid, password); //Initialisation avec WiFi.softAP / ssid et password
    
}

void loop() 
{
    Serial.print("Adresse IP: ");
    Serial.println(WiFi.softAPIP()); //Affiche l'adresse IP de l'ESP32 avec WiFi.SoftIP
    delay(5000);

}
