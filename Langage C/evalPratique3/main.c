/*********************************************************
 *
 *  NOM 	: main.c 
 *  TYPE	: APPLICATION
 *  SUJET 	: simulation de jeu de golf
 *  Auteur apacot
 * 
 *  Created on 29 janvier 2020, 09:15
 *  Modified on 29 janvier 2020, 11:25
 *
 *  LIMITES	: 20 parcours maximum, 50 parties stockables au maxi
 *  CONTRAINTES	: sous linux pour avoir de la couleur
 *
  ********************************************************
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "golf.h"

int main( int argc, char *argv[] )
{
	
	typeScore *scores[NBMAXSCORES];
        
	/**********************************************
	declaration du tableau des parcours
	**********************************************/
        
        typeParcours *tab[NBMAXPARCOURS];

	int nbParcours = 0; // nombre de parcours disponibles
	int nbScores = 0;
	char choix;
	int nro, i;
	nbParcours = chargerParcours(tab);


	do
	{
        // appel de la fonction afficherMenu

            afficherMenu(nbParcours);
            printf( "votre choix ?" );
            scanf( " %c", &choix );
            choix = toupper( choix );

            switch ( choix )
            {

                case 'C':
                    nbParcours = creerParcours( tab, nbParcours );
                    sauvegarderParcours( tab, nbParcours );
                    break;

		case 'V':
                    afficherLesParcours( tab, nbParcours );
                    printf( "Numero du parcours a afficher :" );
                    scanf( " %d", &nro );
                    afficherUnParcours( tab, nro );
                    break;

                case 'J':
                    afficherLesParcours( tab, nbParcours );
                    printf( "Numero du parcours sur lequel vous voulez jouer :" );
                    scanf( " %d", &nro );
                    scores[nbScores++] = jouerParcours(tab[nro]);
                    break;

                case 'D':
                    afficherLesParcours( tab, nbParcours );
                    printf( "Numero du parcours sur lequel vous voulez jouer :" );
                    scanf( " %d", &nro );
                    jouerParcoursADeux(tab[nro]);
                    break;

		}
	}
	while ( choix != 'Q' );

	return EXIT_SUCCESS;
}
