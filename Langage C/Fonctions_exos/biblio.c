/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblio.h"
#include <string.h>
#include <math.h>
#define LARGEUR 15
#define HAUTEUR 9

float additionReels(float v1, float v2)
{
    float resultat;
    resultat=v1+v2;
    return resultat;
}
int calculerCarre(int x)
{
    return (x * x); 
}
void afficherCarre(int x)
{
    printf("le carré de %d est %d\n",x, calculerCarre(x));
}
float calculerDiscriminant(float a, float b, float c)
{
    float delta;
    delta = b*b -4*a*c;
    return delta;
}
void afficherRacine(float a,float b,float c)
{
    float x1,x2;
    float delta = calculerDiscriminant(a,b,c);
    printf("le discriminant est : %.2f\n",calculerDiscriminant(a,b,c));
    
    if (delta > 0)
    {
        x1 = (-1 * b - sqrt(delta)) / (2 * a);
        x2 = (-1 * b + sqrt(delta)) / (2 * a);
        printf("x1 = %.2f\n", x1);
        printf("x2 = %.2f\n", x2);
    }
    if (delta == 0)
    {
        x1 = (-1*b)/(2*a);
        printf("x1 = %.2f\n", x1);        
    }
}
void afficherUneLigne(int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%c",'*');
    }
    printf("\n");
}
void afficherUnCarre(int n)
{
    int i;
    for (i = 0; i < n ; i++)
    {
        afficherUneLigne(n);
    }    
}
void afficherUnRectangle(int largeur,int longueur)
{
    int i;
    for (i=0; i < longueur; i++)
    {
        afficherUneLigne(largeur);
    }    
}
int  compterSymbole(char chaine[], char symbole)
{
    int n =0;
    int i;
    
    for (i=0; i < strlen(chaine);i++)
    {
        if (chaine[i] == symbole)
        {
            n++;
        }
    }
    return n;
}
int verifTerminaison(char chaine[], char fin[2])
{
    char mot[50];
    char terminaison[2]={'e','r'};
    int n = strlen(chaine);
    int retour;
    if (chaine[n-1] == 'r' && chaine [n-2] == 'e')
    {
        retour=1;
    }
    else
    {
        retour=-1;
    }
    return retour;
}
int nbCroix(unsigned char grille[LARGEUR][HAUTEUR])
{
    int ligne, colonne;
    int nb=0;
    for (colonne = 0; colonne < HAUTEUR; colonne++)
    {
        for (ligne = 0; ligne < LARGEUR; ligne++)
        {
            if (grille[ligne][colonne] == 'X')
            {
                nb++;
            }
        }    
    }
    printf("nombre de croix : %d\n", nb);
    return nb;
}
void initGrille(unsigned char grille[LARGEUR][HAUTEUR])
{
    int x,y; 
    
    for (y=0; y<HAUTEUR;y++)
    {
        for (x=0; x<LARGEUR; x++)
        {
            grille[x][y]= '.';
        }
    }    
}
void afficherGrille(unsigned char grille[LARGEUR][HAUTEUR])
{
    int x,y;
    unsigned char lettre='A';
    printf(" ");
    for (x=0;x<LARGEUR;x++)
    {
        printf(" %c",lettre++);
    }
    printf("\n");
    for (y=0;y<HAUTEUR;y++)
    {
        printf("%d",y+1);
        for (x=0;x<LARGEUR;x++)
        {
            printf(" %c",grille[x][y]);
        }
        printf("\n");
    }
} 