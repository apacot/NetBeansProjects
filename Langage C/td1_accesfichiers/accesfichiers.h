#ifndef ACCESFICHIERS__H
#define ACCESFICHIERS__H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#pragma pack(push, 1)
#define NBMAXCAR 50
#define NBPERSONNE 5

typedef struct personne
{
    char nom[NBMAXCAR];
    char prenom[NBMAXCAR];
    int age;
    float poids;
    char sexe; // 'f' ou 'm'
}typePersonne;


#endif /* ACCESFICHIERS__H */

