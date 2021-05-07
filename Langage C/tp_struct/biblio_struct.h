/* 
 * File:   biblio_struct.h
 * Author: apacot
 *
 * Created on 7 janvier 2020, 13:18
 */

#ifndef BIBLIO_STRUCT_H
#define BIBLIO_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    
} typeDate;

typedef struct
{
    char nom[TAILLEMAXNOM];
    char prenom[TAILLEMAXPRENOM];
    typeDate dateNaissance;
    unsigned int nbActivites;
    sports activites[NBACTIVITESMAX];
    unsigned int numCarte;
    
}typeAdherent;
        
void afficherMenu(int nbAdherent);
void afficherDate(typeDate date);
void afficherActivite(sports activite);
void afficherUnAdherent(typeAdherent *ad);
void afficherLesAdherents(typeAdherent *ad[],int nb);
int ajouterUnAdherent(typeAdherent *tab[], int nb);
int supprimerUnAdherent(typeAdherent *tab[],int nro,int nb);
int supprimerTousLesAdherents(typeAdherent *tab[],int nb);
        
#endif /* BIBLIO_STRUCT_H */

