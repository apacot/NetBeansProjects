/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 1 octobre 2019, 14:41
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    float tempC;
    scanf("%f",&tempC);
    
    printf("Température en Fahrenheit"+(((tempC*9)/5))+32);
    return (EXIT_SUCCESS);
}

