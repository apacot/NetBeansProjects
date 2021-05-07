/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mgirard
 *
 * Created on 4 novembre 2019, 21:34
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    char nom[50];
    char prenom[50];
    int age;
    int taille;
    int poids;
    char genre;
    printf("Entrez votre nom :");
    scanf("%s", nom);
    printf("Entrez votre prénom:");
    scanf("%s", prenom);
    printf("Entrez votre age :");
    scanf("%d", &age);
    printf("Entrez votre taille :");
    scanf("%d", &taille);
    printf("Entrez votre poids :");
    scanf("%i", &poids); 
    printf("Quel est votre genre (masulin ou feminin pas non-binaire) :");
    scanf("%s", &genre);    
    
    
    return (EXIT_SUCCESS);
}

