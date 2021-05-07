/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 10 octobre 2019, 10:54
 */

#include <stdio.h>
#include <stdlib.h>
#define NBCASE 24

/*
 * 
 */
int main(int argc, char** argv) 
{
    float Note[NBCASE];      // initialiser le tableau de maniere interactive
    int i;
    for(i=0;i<NBCASE;i++)
    {
    printf("Donnez la note de l'élève %d : ",i+1);
    scanf("%f",&Note[i]);
    }
    // afficher les valeurs du tableau
    for (i=0;i<NBCASE; i++)
    {
        printf("L'élève %d a eu %.2f/20\n", i+1, Note[i]);
    }    
        
    
    
    
    
    return (EXIT_SUCCESS);
}

