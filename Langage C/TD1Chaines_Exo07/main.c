/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 7 novembre 2019, 11:57
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
    int i;
    int tempo;
    
    printf("Quelle est votre phrase ?\n");
    gets(phrase);
    printf("Votre phrase va être inversée\n");
    
    for (i=0;i<strlen (phrase)/2;i++)
    {
        tempo=phrase[(strlen (phrase))-1-i];
        phrase[(strlen (phrase))-1-i]=phrase[i];
        phrase[i]=tempo;
    }
    
    printf("Voici votre phrase à l'envers : %s",phrase);
    return (EXIT_SUCCESS);
}

