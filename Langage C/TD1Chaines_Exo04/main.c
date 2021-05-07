/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 7 novembre 2019, 11:37
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
    int NB_voy;
    int i;
    
    printf("Quelle est votre phrase ?\n");
    gets(phrase);
    printf("Nous allons compter le nombre de voyelle\n");
    NB_voy=0;
    for (i=0; i<strlen (phrase); i++)
    {
        if(phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'i' || phrase[i] == 'o' || phrase[i] == 'u' || phrase[i] == 'y')
        {
            NB_voy++;
        }
    }
    printf("Voici le nombre de voyelle : %d",NB_voy);
    
    return (EXIT_SUCCESS);
}

