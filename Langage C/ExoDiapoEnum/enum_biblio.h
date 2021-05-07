/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   enum_biblio.h
 * Author: apacot
 *
 * Created on 12 décembre 2019, 10:25
 */

#ifndef ENUM_BIBLIO_H
#define ENUM_BIBLIO_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {LUNDI, MARDI,MERCREDI, JEUDI, VENDREDI, SAMEDI, DIMANCHE}jours;
typedef enum {TRUE, FALSE}boolean;
boolean estUnPalindrome(char *chaine);
char *saisirChaine(char *message);

#endif /* ENUM_BIBLIO_H */

