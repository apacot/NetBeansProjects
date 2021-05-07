/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 8 octobre 2019, 14:35
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    float numerateur;
    float diviseur;
    float quotient;
    
    printf("Valeur 1\n");
    scanf("%f",&numerateur);
    printf("Valeur 2\n");
    scanf("%f",&diviseur);
    quotient=numerateur/diviseur;
    printf("Le calcul est:%.2f/%.2f=%.2f",numerateur,diviseur,quotient);
    
    
    return (EXIT_SUCCESS);
}

