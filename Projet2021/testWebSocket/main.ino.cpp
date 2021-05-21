//Libraries nécessaires
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

//Constantes
const char* ssid = "TestWebSocket";
const char* password = "totototo";

//variables globales
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void setup() {
    
}

void loop() {

}