/* 
 * File:   exo3.h
 * Author: apacot
 *
 * Created on 19 novembre 2019, 13:45
 */

#ifndef EXO3_H
#define EXO3_H

#include <stdio.h>
#include <stdlib.h>
#define LARGEUR 15
#define HAUTEUR 9

float additionReels(float v1, float v2);
void afficherCarre(int);
int calculerCarre(int x);
float calculerDiscriminant(float,float,float);
void afficherRacine(float a,float b,float c);
void afficherUneLigne(int n);
void afficherUnCarre(int n);
void afficherUnRectangle(int largeur,int longueur);
int  compterSymbole(char chaine[], char symbole);
int verifTerminaison(char[], char[2]);
int nbCroix(unsigned char grille[LARGEUR][HAUTEUR]);
void initGrille(unsigned char grille[LARGEUR][HAUTEUR]);
void afficherGrille(unsigned char grille[LARGEUR][HAUTEUR]);
#endif /* EXO3_H */

