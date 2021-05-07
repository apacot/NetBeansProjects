/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 10 octobre 2019, 11:45
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBMAXCAR 255


int main(int argc, char** argv) 
{
    char chaine[NBMAXCAR];
    int i;
    int longueurChaine;
    printf("donnez votre chaîne de caractère : ");
    scanf("%s", chaine);
    longueurChaine=strlen(chaine);
    
    for(i=0;i<longueurChaine;i++)
    {
        printf("[%c]\n",chaine[i]);
    }
    
    return (EXIT_SUCCESS);
}

