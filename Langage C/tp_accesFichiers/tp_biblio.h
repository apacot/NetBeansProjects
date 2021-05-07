/* 
 * File:   tp_biblio.h
 * Author: apacot
 *
 * Created on 22 janvier 2020, 09:56
 */

#ifndef TP_BIBLIO_H
#define TP_BIBLIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#pragma pack(push, 1)
#define TAILLEMAXNOM 50
#define TAILLEMAXPRENOM 50
#define NBACTIVITESMAX 5
#define NBADHERENTS 5000

typedef enum {NATATION,BASKETBALL,HANDBALL,SQUASH,TENNIS}sports;

typedef struct
{
    int jour;
    int mois;
    int annee;
    
} typeDate; //12

typedef struct
{
    char nom[TAILLEMAXNOM]; 
    char prenom[TAILLEMAXPRENOM];
    typeDate dateNaissance;
    unsigned int nbActivites;
    sports activites[NBACTIVITESMAX];
    unsigned int numCarte;
    
}typeAdherent; //50 + 50 +12 + 4 + 5*4 + 4 = 140
        
void afficherMenu(int nbAdherent);
void afficherDate(typeDate date);
void afficherActivite(sports activite);
void afficherUnAdherent(typeAdherent *ad);
void afficherLesAdherents(typeAdherent *ad[],int nb);
int ajouterUnAdherent(typeAdherent *tab[], int nb);
int supprimerUnAdherent(typeAdherent *tab[],int nro,int nb);
int supprimerTousLesAdherents(typeAdherent *tab[],int nb);
void sauvegarderAdherents (typeAdherent *tab[], int nbAdherent);
#endif /* TP_BIBLIO_H */

