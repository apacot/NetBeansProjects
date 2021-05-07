/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 2 octobre 2019, 09:19
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    float a;
    float b;
    float c;
    float delta;
    
    printf("Quelle est la valeur de a ?");
    scanf("%f", &a);
    printf("Quelle est la valeur de b ?");
    scanf("%f",&b);
    printf("Quelle est la valeur de c ?");
    scanf("%f",&c);
    delta=b*b-4*a*c;
    printf("La valeur de Delta :%f\n",delta);
    
    if (delta>=0)
        printf("il ya des solutions");
    else
        printf ("il n'y a pas de solutions");
    
    
    return (EXIT_SUCCESS);
}

