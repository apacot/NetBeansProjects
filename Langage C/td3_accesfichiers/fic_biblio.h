/* 
 * File:   fic_biblio.h
 * Author: apacot
 *
 * Created on 16 janvier 2020, 10:43
 */

#ifndef FIC_BIBLIO_H
#define FIC_BIBLIO_H

#define NBCOULEURS 256
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#pragma pack(push, 1)


typedef struct 
{
    unsigned char signature[2];
    unsigned int tailleFichier;
    unsigned int reserve;
    unsigned int adresse;
    
}typeEnTeteFichierBmp; //14

typedef struct
{
    unsigned int tailleEnTete;
    unsigned int largeur;
    unsigned int hauteur;
    unsigned short int nbPlan;
    unsigned short int bitParPixel;
    unsigned int typeCompression;
    unsigned int tailleImage;
    unsigned int resolutionHorizontale;
    unsigned int resolutionVerticale;
    unsigned int nbCouleursUtilisees;
    unsigned int nbCouleursImportantes;
    
}typeEnTeteImage; //40

typedef struct
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
        
}typeCouleur; //4

void afficheEnTeteFichierBmp(typeEnTeteFichierBmp enTete);
void afficheEnTeteImageBmp(typeEnTeteImage enTete);
void bleuirPalette(typeCouleur pal[]);
void verdirPalette(typeCouleur pal[]);
void rougirPalette(typeCouleur pal[]);
#endif /* FIC_BIBLIO_H */

