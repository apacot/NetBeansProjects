/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 19 novembre 2019, 13:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "biblio.h"
#include <string.h>
#define LARGEUR 15
#define HAUTEUR 9
/*
 * 
 */


int main(int argc, char** argv) 
{
   /* exo 2
    * float val1;
    * float val2;
    */
    // int x=3; exo 4
    
   /* ---------- exo 6-7
    float a,b,c;
    
    printf("a : ");
    scanf("%f",&a);
    
    printf("b : ");
    scanf("%f",&b);
    
    printf("c : ");
    scanf("%f",&c);
    
    afficherRacine(a,b,c);
    */
   /* exo 2
    * printf("val1 : ");
    * scanf("%f",&val1);
    * printf("val2 : ");
    * scanf("%f",&val2);
    */
        
   // printf("resultat : %.2f\n",additionReels(val1,val2)); exo 2
   // printf("le carré de %d est %d\n",x, calculerCarre(x)); exo 4-5
    
    //afficherUneLigne(5); exo 8
    //afficherUnCarre(3); exo 9
    //afficherUnRectangle(10,4); exo 10
    // printf("il ya %d %c dans %s", compterSymbole("Bonjour",'o'),'o',"Bonjour");   exo 11
    
    /*  exo 12 
     * 
    int finEnER;
    char mot[27];
    char terminaison[2] = {'e','r'};
    
    printf("donnez un verbe : ");
    scanf("%s", mot);
    
    finEnER=verifTerminaison(mot, terminaison);
    if (finEnER == 1)
    {
        printf("%s se terminne bien en ER\n", mot);
    }
    else
    {
        printf("%s ne se termine pas en ER\n", mot);
    }    
    */ 
    
    unsigned char tab[LARGEUR][HAUTEUR];
    int x,y;
    unsigned char lettre;
    int chiffre;
    int nombreDeCroix;
    
    initGrille(tab);
    do
    {
        afficherGrille(tab);
        printf("ajouter une croix : lettreChiffre (ex: b4)\n");
        printf("fin avec a-1 : ");
        scanf(" %c%d",&lettre,&chiffre);
        if ((lettre>= 'a' && lettre <='o') && (chiffre>=1 && chiffre <= HAUTEUR))
        {
            tab[lettre-'a'][chiffre-1]='X';
        }
    }while (lettre != 'a' || chiffre != -1);
    nombreDeCroix=nbCroix(tab);
    printf("il y a %d croix \n",nombreDeCroix);
    
    return (EXIT_SUCCESS);
}


