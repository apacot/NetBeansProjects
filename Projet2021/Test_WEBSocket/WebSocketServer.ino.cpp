#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <WebSocketsServer.h>
#include <HardwareSerial.h>

const char *ssid = "BallonSondeAP";
const char *password = "BallonSonde2021";

WebServer server;
WebSocketsServer webSocket = WebSocketsServer(81);

