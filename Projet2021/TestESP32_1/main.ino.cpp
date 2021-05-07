/* 
 * File:   main.ino.cpp
 * Author: apacot
 *
 * Created on 15 janvier 2021, 09:50
 */

#include <Arduino.h>

int led = 22;
void setup()
{
    pinMode(led, OUTPUT);
}
void loop()
{
    digitalWrite(led, digitalRead(led) ^1);     //turn the state of LED
    delay(200);                                 // wait for a 0.2 second
}
