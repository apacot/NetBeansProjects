/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 18 décembre 2019, 09:32
 */

#include "biblio_blackJack.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int i;
    int valMainJoueur = 0;
    int valMainCroupier = 0;
    int valCarte = 0;
    int solde = 1000;
    int mise;
    int scoreJoueur;
    int scoreCroupier;
    int nbCarteJoueur = 0;
    int nbCarteCroupier = 0;
    int carteAlea;
    int nbCartePioche = NBCARTE;
    char carFin, choix;
    carte jeuCarte[NBCARTE + 1];
    carte mainJoueur[NBMAXCARTEMAIN];
    carte mainCroupier[NBMAXCARTEMAIN];
    carte Pioche[NBCARTE];
    carte valeurCarte;

    for (i = 0; i < 10; i++) {
        valeurCarte.valeur[i] = valeurCarte.valeur[i] + i + 1;
    }
    for (i = 10; i <= 12; i++) {
        valeurCarte.valeur[i] = 10;
    }
    valeurCarte.valeur[13] = 11;
    for (i = 0; i <= 13; i++) {
        printf("%d ", valeurCarte.valeur[i]);
    }
    do {
        // distribution des deux premieres cartes
        for (i = 0; i < 2; i++) {

            /*
                        carteAlea=aleatoire(nbCartePioche);
                        mainJoueur[i]=Pioche[carteAlea];
                        nbCartePioche--;
                        for (i=carteAlea;i<NBCARTE-1;i++)
                        {
                            Pioche[i]=Pioche[i+1];
                        }
             */
            mainJoueur[i] = tirerCarte(Pioche, nbCartePioche);
            nbCartePioche--;
            nbCarteJoueur++;
            mainCroupier[i] = tirerCarte(Pioche, nbCartePioche);
            nbCartePioche--;
            nbCarteCroupier++;

        }
        //2e carte face cachée
        mainJoueur[1].coteCarte = RETOURNE;
        mainCroupier[1].coteCarte = RETOURNE;

        //afficher les deux premières cartes



        //afficher le solde

        printf("\nVotre solde : %d\n", solde);
        //le joueur mise
        printf("Combien misez vous ?");
        mise = demanderMise(solde);
        solde -= mise;
        //remettre la 2e carte face visible

        mainJoueur[1].coteCarte = FACE;
        mainCroupier[1].coteCarte = FACE;

        //calculer les scores
        scoreJoueur = calculerScore(mainJoueur, nbCarteJoueur);
        scoreCroupier = calculerScore(mainCroupier, nbCarteCroupier);
        printf("Valeur totale de vos cartes : %d\n", scoreJoueur);

        //si le croupier a 21 avec ses deux premieres cartes, il ramasse toutes les mises sauf celles des joueurs
        // dans le même cas
        if (scoreCroupier == 21 && scoreJoueur != 21) {
            mise = 0; // la mise est perdu
        }

        // et si le joueurs a 21 dès le début et que le banquier n'en a pas, le joueurs se fait payer
        if (scoreJoueur == 21 && scoreCroupier != 21) {
            solde = mise + mise * 2;
        }
        //si le banquier n'a pas 21 dès le début, le jeu se poursuit
        if (scoreCroupier != 21) {
            //commencer avec le joueur à gauche
            //le joueur choisit ce qu'il veut faire (tirer, rester(servis)
            do {
                printf("Voulez vous tirer une carte ? (o/n) ");
                scanf("%c", &choix);
            } while (choix != 'o' && choix != 'n');

            //le joueur peut demander une carte au croupier tant que son score ne dépasse pas 21
            //quand le joueur ne veut plus prendre de carte, il "reste"
            while (scoreJoueur <= 21 && choix == 'o') {
                mainJoueur[i + 1] = tirerCarte(Pioche, nbCartePioche);
                nbCartePioche--;
                nbCarteJoueur++;
                i++;
                scoreJoueur = calculerScore(mainJoueur, nbCarteJoueur);
            }
            //si score joueur dépasse 21, il est "crevé" le banquier ramasse la mise
            if (scoreJoueur > 21) {
                mise = 0; // le joueur perd sa mise                
            }
            //le banquier se sert après que tous les joueurs soit servis
            //tant que la main du croupier vaut 16 ou moins, il tire une carte 
            while (scoreCroupier < 17) {
                mainCroupier[i + 1] = tirerCarte(Pioche, nbCartePioche);
                nbCartePioche--;
                nbCarteCroupier++;
                i++;
            }

            //si banquier a crevé, il paye les joueurs à égalité de leur mise.
            if (scoreCroupier > 21) {
                solde = solde + mise * 2;
            } else //sinon, il ramassse la mise des joueurs qui ont un score inférieur au sien
                //si égalité entre joueur et croupier, le croupier gagne
            {
                if (scoreJoueur <= scoreCroupier) {
                    mise = 0; //la mise est perdu
                } else //et paye ceux qui ont un score supérieur au sien
                {
                    solde = solde + mise * 2;
                }

            }

        }

    } while (solde != 0 || carFin != 'n');
















    //les cartes utilisées ne servent plus








    return (EXIT_SUCCESS);
}