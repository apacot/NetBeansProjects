/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fonctionA()
{
    int uneVal;
    uneVal=53;
    return uneVal;
}
int fonctionB()
{
    int val;
    printf("donnez une valeur : ");
    scanf("%d",&val);
    return val;
}
void fonctionC(float x)
{
    printf("%f\n",x);
    x=3.14;
}
int fonctionD(float x1, float y1, float x2,float y2)
{
    int distanceEntiere;
    distanceEntiere=(int)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return distanceEntiere;
}
