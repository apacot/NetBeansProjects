#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#define IP_LOCAL IPAddress(192,168,5,1)
#define GATEWAY IPAddress(192,168,5,1)
#define MASQUE IPAddress(255,255,255,0)

// Constantes
const char *ssid = "BallonSonde";
const char *password = "BallonSonde2021";

// Globales
AsyncWebServer server(80);
WebSocketsServer ws(81);

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
 * Functions
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

void setup() {

    // Start Serial port
    Serial.begin(115200);

    // Start access point
    WiFi.softAPConfig(IP_LOCAL, GATEWAY, MASQUE);
    WiFi.softAP(ssid, password);

    server.on("/", [](AsyncWebServerRequest * request) {

        request->send_P(200, "text/html", webpage);
    });

    server.onNotFound(notFound);

    server.begin();
    ws.begin();
    ws.onEvent(webSocketEvent);

}

void loop() {
    ws.loop();

    if (WiFi.softAPgetStationNum() == 0) {
        delay(50000); //attendre 5 minutes
        if (WiFi.softAPgetStationNum() == 0) //si toujours aucun client
        {
            WiFi.softAPdisconnect(false); //deconnecter le wifi
        }
    }
}