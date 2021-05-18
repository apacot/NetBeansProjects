#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>

const char *ssid = "BallonSondeAP";
const char *password = "BallonSonde2021";

WebServer server;
WebSocketsServer webSocket = WebSocketsServer(81);

WiFi.softAPConfig(IPAddress(192, 168, 5, 1), IPAddress(192, 168, 5, 1),IPAddress(255, 255, 255, 0));
WiFi.softAP(ssid,password);

