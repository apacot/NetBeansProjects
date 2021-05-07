/* 
 * File:   biblio_blackJack.h
 * Author: apacot
 *
 * Created on 18 décembre 2019, 09:32
 */

#ifndef BIBLIO_BLACKJACK_H
#define BIBLIO_BLACKJACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
//#include <ncurses.h>
#include <sys/timeb.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/random.h>
#define NBMAXCARTEMAIN 11
#define NBCARTE 52

typedef enum {PIQUE,TREFLE,COEUR,CARREAU}couleur;
typedef enum {RETOURNE,FACE}booleen;


typedef struct
{  
    int valeur;
    couleur couleurCarte;
    wchar_t visuel;
    booleen coteCarte;
    int coloration;
    int colorationFond;
    int x;  
    int y;    
    
}carte;

int calculerScore(carte mainj[], int nbCarte);
carte tirerCarte(carte Pioche[], int nbCartePioche);
int demanderMise(int solde);
unsigned int aleatoire(unsigned int maxAlea);
void msleep(unsigned int maxTime);
#endif /* BIBLIO_BLACKJACK_H */

