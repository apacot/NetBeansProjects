/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 7 novembre 2019, 11:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 255

/*
 * 
 */
int main(int argc, char** argv) 
{
    char phrase[TAILLEMAX];
    int nbCons;
    int i;
    
    printf("Quelle est votre phrase ?\n");
    gets(phrase);
    printf("Nous allons compter le nombre de consonne\n");
    nbCons=0;
    // Compter les consonnes
    for (i=0; i<strlen (phrase); i++)
    { // Si le caractère courant est une lettre et une consonne
        if((phrase[i]>='a' && phrase[i]<='z') && (phrase[i] != 'a' && phrase[i] != 'e' && phrase[i] != 'i' && phrase[i] != 'o' && phrase[i] != 'u' && phrase[i] != 'y'))
        {
            nbCons++;
        }
    }
    printf("Il ya %d consonne(s)",nbCons);
    
    return (EXIT_SUCCESS);
}

