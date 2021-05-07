/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 7 novembre 2019, 11:44
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
    int NB_MOTS;
    int i;
    
    printf("Quelle est votre phrase ?\n");
    gets(phrase);
    printf("Nous allons compter le nombre de mot\n");
    // Si il y'a au moins un mot, Initialiser la valeur de NB_MOTS à 1
    if (strlen(phrase) > 0)
    {
        NB_MOTS=1;
    }
    else
    {
        NB_MOTS=0;
    }
    //compter les mots
    for (i=0; i<strlen (phrase); i++)
    { //A chaque espace, compter un mot supplémentaire
        if(phrase[i] == ' ')
        {
            NB_MOTS++;
        }
    }
    printf("Voici le nombre de mot(s) : %d",NB_MOTS);   //afficher le nombre de mot(s)

    return (EXIT_SUCCESS);
}

