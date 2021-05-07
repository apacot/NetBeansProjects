#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <sys/timeb.h>


#ifndef _PENDU_H_
#define _PENDU_H_


#define NB_MAX_ERREUR 7
#define NB_MAX_LETTRES_POSSIBLE 26
#define NBMOTS 5
#define LONGUEURMAXMOT 25

/**
 * @brief affiche un menu proposant de jouer ou de quitter recupère la réponse du joueur 
 * @return une valeur positive si le joueur veut jouer et négative sinon
 */
int afficherMenu();


/**
 * @brief affiche le pendu en fonction du nombre d'erreurs passee en parametre
 * @param nroErreur nombre d'erreur
 */
void afficherPendu(int nroErreur);

/**
 * @brief Affiche les lettres deja proposees qui se trouve dans le tableau de lettre "histo" le nombre de lettre etant donne par nbLettre
 * @param histo tableau de l'historique des lettres
 * @param nbLettre nombre de lettres déjà proposées
 */
void afficherLettre(char *histo, int nbLettre);


/**
 * @brief test si le mot est similaire au mot à trouver
 * @param motATtrouver chaine de caractere correspondant au mot a trouver
 * @param motPropose chaine de caractere correspondant au mot proposé par le joueur
 * @return 0 si les mots sont identique
 */
int motEstTrouve(char *motATtrouver, char *motPropose);


/**
 * @brief remplace les - par la lettre propose dans le tableau mot courant si la lettre fait partie du mot a trouver
 * @param motATrouver chaine de caractere correspondant au mot a trouver
 * @param motCourant chaine de caractere correspondant au mot proposé par le joueur
 * @param lettrePropose lettre proposé par le joueur
 * @return 0 si la lettre etait dans le mot, 1 sinon
 */
int placerLettre(char *motATrouver,char *motCourant,char lettrePropose);


/**
 * @brief test si la lettre a déjà été proposée
 * @param lettresProposees tableau des lettres proposées par le joueur
 * @param nbLettreProposee nombre de lettre déjà proposés
 * @param lettre la lettre proposée par le joueur
 * @return  0 si la lettre a deja ete propose ou si ce n'est pas une lettre. 1 dans les autres cas
 */
int verifierLettrePropose(char *lettresProposees, int nbLettreProposee, char lettre);





/**
 * @brief met des - dans chaque case du tableau motCourant
 * @param motCourant le mot "proposition" du joueur
 * @param longueurMot taille du mot
 */
void initialiserMot(char *motCourant,int longueurMot);

/**
 * @brief attendre maxTime millisecondes
 * @param maxTime temps en millisecondes
 */
void msleep(unsigned int maxTime);
/**
 * @brief retourne un entier compris entre 0 et maxAlea
 * @param maxAlea
 * @return  retourne un entier compris entre 0 et maxAlea
 */
unsigned int aleatoire(unsigned int maxAlea);


#endif
