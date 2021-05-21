/* 
 * File:   main.ino.cpp
 * Author: antoine
 *
 * Created on 18 mai 2021, 11:19
 */

// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "BallonSondeAP";
const char* password = "BallonSonde2021";

bool ledState = 0;
const int ledPin = 2;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
  <head>
    <meta charset="utf-8">
    <title>BallonSonde2021</title>
    <style type="text/css">
      /* Mettez le code css ici. */
    </style>
    <script src="https://code.jquery.com/jquery-1.12.4.min.js"></script>
    <script type="text/javascript">
    $(document).ready(function() {
        // Récupérer la valeur actuelle de textarea
        var text = sDonnees;

        // Modifier le contenu de div
        $(".res").text(text);
    });
    </script>
  </head>
  <body>
    <div class="res"></div>
  </body>
</html>
)rawliteral";

void notifyClients() {
    ws.textAll(String(ledState));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
    AwsFrameInfo *info = (AwsFrameInfo*) arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
        data[len] = 0;
        if (strcmp((char*) data, "toggle") == 0) {
            ledState = !ledState;
            notifyClients();
        }
    }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
        void *arg, uint8_t *data, size_t len) {
    switch (type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            break;
        case WS_EVT_DISCONNECT:
            Serial.printf("WebSocket client #%u disconnected\n", client->id());
            break;
        case WS_EVT_DATA:
            handleWebSocketMessage(arg, data, len);
            break;
        case WS_EVT_PONG:
        case WS_EVT_ERROR:
            break;
    }
}

void initWebSocket() {
    ws.onEvent(onEvent);
    server.addHandler(&ws);
}

String processor(const String& var) {
    Serial.println(var);
    if (var == "STATE") {
        if (ledState) {
            return "ON";
        } else {
            return "OFF";
        }
    }
}

void setup() {
    // Serial port for debugging purposes
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Connect to Wi-Fi
    Serial.print("Creation du Point d'acces ...");
    WiFi.softAPConfig(IPAddress(192, 168, 5, 1), IPAddress(192, 168, 5, 1), IPAddress(255, 255, 255, 0));
    delay(1000);
    WiFi.softAP(ssid, password); //Initialisation avec WiFi.softAP / ssid et password

    initWebSocket();

    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
        request->send_P(200, "text/html", index_html, processor);
    });

    // Start server
    server.begin();
}

void loop() {
    Serial.print("Adresse IP: ");
    Serial.println(WiFi.softAPIP()); //Affiche l'adresse IP de l'ESP32 avec WiFi.SoftIP
    delay(1000);
}