/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   biblio.h
 * Author: apacot
 *
 * Created on 26 novembre 2019, 14:51
 */

#ifndef BIBLIO_H
#define BIBLIO_H

#include <stdlib.h>
#include <stdio.h>
#define TAILLEMAX 255

void afficherFiche(char *nom, char *prenom, int age, float taille, float poids);
float calculerIMC(float taille, float poids);
void afficherCorpulence(float imc);
void afficherMenu();
float calculerPoidsLorentz(char genre,float taille);
float calculerPoidsLorentzAge (int age, float taille);
float calculerPoidsDevine(float taille, char genre);


#endif /* BIBLIO_H */

