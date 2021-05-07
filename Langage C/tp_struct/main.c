/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 7 janvier 2020, 13:18
 */

#include "biblio_struct.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    typeAdherent * tabAdherent[NBADHERENTS];
    int compteurAdherent;
    int numAd;
    char choix;

    compteurAdherent = 0;

    do {
        afficherMenu(compteurAdherent);
        scanf("%c", &choix);
        switch (choix) {
                //Ajouter une fiche
            case 'a':
                compteurAdherent = ajouterUnAdherent(tabAdherent, compteurAdherent);
                break;
                //Supprimer une fiche
            case 's':
                printf("Quel numéro de fiche voulez-vous supprimer ? (entre 0 et %d) ", compteurAdherent - 1);
                scanf("%d", &numAd);
                compteurAdherent = supprimerUnAdherent(tabAdherent, numAd, compteurAdherent);
                break;
                //Modifier une fiche
            case 'm':
                printf("Quel numéro de fiche voulez-vous modifier ? (entre 0 et %d) ", compteurAdherent - 1);
                scanf("%d", &numAd);
                compteurAdherent = supprimerUnAdherent(tabAdherent, numAd, compteurAdherent);
                compteurAdherent = ajouterUnAdherent(tabAdherent, compteurAdherent);
                break;
                //Voir le contenu d'une fiche
            case 'v':
                printf("Quelle fiche voulez-vous voir ? (entre 0 et %d) ", compteurAdherent - 1);
                scanf("%d", &numAd);
                afficherUnAdherent(tabAdherent[numAd]);
                break;
                //Voir le contenu de l'ensemble des fiches
            case 'l':
                afficherLesAdherents(tabAdherent, compteurAdherent);
                break;
                //Supprimer toutes les fiches
            case 'e':
                compteurAdherent = supprimerTousLesAdherents(tabAdherent, compteurAdherent);
                break;
                //
        }
    } while (choix != 'q');
    return (EXIT_SUCCESS);
}

