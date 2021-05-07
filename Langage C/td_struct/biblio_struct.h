/* 
 * File:   biblio_struct.h
 * Author: apacot
 *
 * Created on 17 décembre 2019, 13:32
 */

#ifndef BIBLIO_STRUCT_H
#define BIBLIO_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

#define NBCARMAXNOM 50
#define NBCARMAXPRENOM 50

typedef struct
{
    char nom[NBCARMAXNOM];
    char prenom[NBCARMAXPRENOM];
    unsigned int annee;
    float taille;
    float poids;
}typePersonne;

typePersonne creePersonne();
void affichePersonne(typePersonne personne);
typePersonne *creePersonnePtr();
void affichePersonnePtr(typePersonne *personne); 

typedef struct
{
    char nom[NBCARMAXNOM];
    char prenom[NBCARMAXPRENOM];
    char nbBadge[11];
    int nbActivite;
}typeAdherent;
typeAdherent *nouvelAdherent(typeAdherent personne);

#endif /* BIBLIO_STRUCT_H */

