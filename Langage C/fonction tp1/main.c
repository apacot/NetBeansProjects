/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 26 novembre 2019, 14:51
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#include <string.h>
/*
 * 
 */
int main(int argc, char** argv) 
{

    char nom[TAILLEMAX];
    char prenom[TAILLEMAX];
    char genre, choix;
    int age;
    float taille, poids, imc, poidsIdeal;
    
    printf("|nom : ");
    gets(nom);
    printf("|prenom : ");
    gets(prenom);
        
    do
    {
        printf("|sexe (h ou f) : ");
        scanf(" %c",&genre);
        
    }while (genre !='h' && genre != 'f');
    
    printf("|age : ");
    scanf("%d",&age);
    printf("|taille (en mettre) : ");
    scanf("%f",&taille);
    printf("|poids (en kg) : ");
    scanf("%f",&poids);
    printf("\n");
    
    afficherFiche(nom, prenom, age, taille, poids);
    imc = calculerIMC(taille,poids);
    afficherCorpulence(imc);
    
    do{
        afficherMenu();
        printf("Votre choix : "); 
        scanf(" %c", &choix);
        switch(choix)
        {
            case '1':
                poidsIdeal = calculerPoidsLorentz(genre,taille);
                printf("Votre poids ideal selon la Formule de Lorentz est %.2f",poidsIdeal);
                break;
            case '2':
                poidsIdeal = calculerPoidsDevine(taille,genre);
                printf("Votre poids ideal selon la Formule de Devine est %.2f", poidsIdeal);
                break;
            case '3':
                poidsIdeal = calculerPoidsLorentzAge(age,taille);
                printf("Votre poids ideal selon la Formule de Lorentz en tenant compte de l'âge est %.2f", poidsIdeal);
                break;
        }    
    }while (choix != 'q');
    
    return (EXIT_SUCCESS);
}

