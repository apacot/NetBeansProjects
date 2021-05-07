
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblio.h"

void afficherFiche(char *nom, char *prenom, int age, float taille, float poids)
{
    printf("fiche récapitulative : \n");
    printf("- Identité \t: %s %s\n", prenom, nom);
    printf("- Age \t\t: %d ans\n", age);
    printf("- Poids \t: %.2fKg\n", poids);
    printf("- Taille \t: %.2fm\n", taille);
}
float calculerIMC(float taille, float poids)
{
    float imc;
    
    imc=poids/(taille*taille);
    return imc;
}
void afficherCorpulence(float imc)
{
    char tabCorpulence[7][TAILLEMAX] = {"famine","maigreur","normale","surpoids","obésité modérée","obésité sévère","obésité morbide"};
    float tabIMC[6] = {16.5,18.5,25,30,35,40};
    int posIMC=0;
    
    
    printf("\nVotre indice de masse corporelle est de %.1f\n", imc);
    
    if (imc < tabIMC[0])
    {
        printf("Votre corpulence est qualifiée de %s", tabCorpulence[0]); 
    }
    if (imc >= tabIMC[0] && imc <tabIMC[5])
    {
        while (tabIMC[posIMC] < imc)
        {
            posIMC++;
        }
        printf("Votre corpulence est qualifiée de %s", tabCorpulence[posIMC]);
    }
    if (imc>= tabIMC[5])
    {
        printf("Votre corpulence est qualifiée de %s", tabCorpulence[6]); 
    }
}
void afficherMenu()
{
    printf("\n Calculer votre poids idéal : \n");
    printf("1) Utiliser la Formule de Lorentz\n");
    printf("2) Utiliser la Formule de Devine\n");
    printf("3) Utiliser la Formule de Lorentz en tenant compte de l'âge (mais pas du genre)\n");
    printf("4) Appuyer sur 'q' pour quitter le menu de calcul de poids\n");
}
float calculerPoidsLorentz(char genre,float taille)
{
    float poidsIdeal;
    switch(genre)
    {
        case 'f':
            poidsIdeal = (taille*100)-100-(((taille*100)-150)/2.5);
            break;
        case 'h':
            poidsIdeal = (taille*100)-100-(((taille*100)-150)/4);
            break;
    }
    return poidsIdeal;
}
float calculerPoidsLorentzAge (int age, float taille)
{
    float poidsIdeal;
    poidsIdeal = 50+(((taille*100)-150)/4)+((age-20)/4.0);
    return poidsIdeal;
}
float calculerPoidsDevine(float taille, char genre)
{
    float poidsIdeal;
    switch(genre)
    {
        case 'f':
            poidsIdeal = 45.5+(2.3*((taille/0.0254)-60));
            break;
        case 'h':
            poidsIdeal = 50+(2.3*((taille/0.0254)-60));
            break;
    }
    return poidsIdeal;
}