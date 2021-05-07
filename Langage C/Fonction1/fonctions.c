/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "fonctions.h"


void afficherValeur(float val)
{
    printf("%f\n",val);
}

float equation(float x, float a, float b)
{
    float y;
    y=a*x+b;
    return y;
}

float polynome(float x)
{
    float y;
    y=2*x*x+3*x+4;
    return y;
}