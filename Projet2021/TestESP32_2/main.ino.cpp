#include <Arduino.h>

/*
  Turns on an LED on for 0.2 second, then off for one second, repeatedly.
  The ESP32 has an internal blue LED at D2 (GPIO 02) 
*/
int led = 22;
int i = 0;
char message[100];
String valeur = "100";

void setup() 
{
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  digitalWrite(led, digitalRead(led) ^1);   // turn the LED 
  if (Serial.available() > 0)
  {
      valeur = Serial.readString();
  }
  delay(valeur.toInt());
  i++;
  Serial.println(i);
  
}