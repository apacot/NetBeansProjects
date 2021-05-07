/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 15 octobre 2019, 14:25
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int Debut;
    int Fin;
    int resultat;
    int valeur;
    int i;
   
    printf("Quelle est la borne début ?\n");
    scanf("%d",&Debut);
    printf("Quelle est la borne fin ?\n");
    scanf("%d",&Fin);
    printf("Quelle table de multiplication voulez-vous ?\n");
    scanf("%d",&valeur);

    for (i= Debut; i<= Fin; i++) 
    {
        resultat = i * valeur;
        printf("%dx%d = %d\n", i,valeur,resultat);
    }








    return (EXIT_SUCCESS);
}

