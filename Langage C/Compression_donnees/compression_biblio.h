/* 
 * File:   compression_biblio.h
 * Author: apacot
 *
 * Created on 28 janvier 2020, 13:23
 */

#ifndef COMPRESSION_BIBLIO_H
#define COMPRESSION_BIBLIO_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define NBCOULEURS 256

#pragma pack(push, 1)

typedef struct
{
    unsigned char signature[2];
    unsigned int tailleFichier;
    unsigned int reserve;
    unsigned int adresseImg;

} typeEnTeteFichierBmp; //14

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
    unsigned int nbCouleursUtilises;
    unsigned int nbCouleursImportantes;
} typeEnTeteImageBmp;//40

typedef struct
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
    unsigned char a;
        
}typeCouleur;

void decompressBmp(char *src, char *dst);
void compressBmp(char *src, char *dst);

#endif /* COMPRESSION_BIBLIO_H */

