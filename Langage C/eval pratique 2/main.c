

/* 
 * File:   main.c
 * Author: 
 *
 * Created on 28 novembre 2019, 08:53
 * Modified on 
 * Description : Poker aux dés simplifié
 */

#include <stdio.h>
#include <stdlib.h>

#include "poker.h"

int main(int argc, char** argv)
{
   // exemple d'affichage avec des couleurs
   // printf("du texte en %svert%s mais juste le mot vert\n",GREEN,GREY);
    
    // initialisation et déclaration des variables
    char nom1[NBMAXCAR];
    char nom2[NBMAXCAR];
    char carFin;
    int age1, age2;
    int testAge1, testAge2, solde1, solde2, mise1, mise2, pot, i, posDes, score1, score2;
    int desJ1[NBDES];
    int desJ2[NBDES];

    // demander nom et age des 2 joueurs
    
    printf("Nom du joueur 1 : ");
    gets(nom1);
    printf("Age du joueur 1 : ");
    scanf("%d",&age1);
    printf("Nom du joueur 2 : ");
    scanf("%s",&nom2);
    printf("Age du joueur 2 : ");
    scanf("%d",&age2);
    
    
    // tester si les ages permettent de jouer
    testAge1 = testerAge(age1,AGELIMITE);
    testAge2 = testerAge(age2,AGELIMITE);
    
    // si oui faire la boucle de jeu    
    if (testAge1 == 0 && testAge2 == 0)
    {
        // boucle de jeu
        do
        {
            printf("\nLancement du poker\n");
            // initialiser les cagnottes
            printf("Le solde de départ pour chaque joueurs est de %d€ \n", SOLDEDEPART);
            solde1=solde2=SOLDEDEPART;
            // boucle de partie (fin si l'un des joueurs a un solde de 0)
            do
            {
                // chaque joueur mise
                printf("\n%s, combien misez vous ?", nom1);
                mise1 = demanderMise(solde1);
                solde1-=mise1;
                printf("\n%s, combien misez vous ?", nom2);
                mise2 = demanderMise(solde2);
                solde2-=mise2;
                pot = mise1 + mise2;
                printf("\nLe pot est de : %d€",pot);
                // lancement des des
                printf("\n%s, %s, vos dés sont lancés\n",nom1, nom2);
                for (i=0; i<NBDES;i++)
                {
                    desJ1[i]=lancerUnDes(NBFACES);
                    desJ2[i]=lancerUnDes(NBFACES);                                       
                }
                // afficher le résultat
                printf("\nVoici les dés de %s : ",nom1);
                afficherCombinaison(desJ1,NBDES);
                printf("\nVoici les dés de %s : ",nom2);
                afficherCombinaison(desJ2,NBDES);
                // choix du des a relancer pour chaque joueur et affichage de la nouvelle combinaison
                printf("\n%s,",nom1);
                posDes = demanderNumeroDeDes();
                if (posDes == -1)
                {
                    printf("\nVous avez choisi de ne changer aucun dés");
                }
                else
                {
                    printf("\nVous avez choisi de changer le %de dés", posDes);
                    desJ1[posDes-1]=lancerUnDes(NBFACES);
                }
                printf("\n%s,",nom2);
                posDes = demanderNumeroDeDes();
                if (posDes == -1)
                {
                    printf("\nVous avez choisi de ne changer aucun dés");
                }
                else
                {
                    printf("\nVous avez choisi de changer le %de dés", posDes);
                    desJ2[posDes-1]=lancerUnDes(NBFACES);
                }
                printf("\nVoici les nouveaux dés de %s : ",nom1);
                afficherCombinaison(desJ1,NBDES);
                printf("\nVoici les nouveaux dés de %s : ",nom2);
                afficherCombinaison(desJ2,NBDES);
                //calcul du score de chaque joueur
                score1 = calculerScore(desJ1,NBDES);
                score2 = calculerScore(desJ2,NBDES);
                // test du score du joueur 1 par rapport au score du joueur 2
                // affichage du gagnant et mise à jour des cagnottes
                if (score1>score2)
                {
                    printf("\nLe gagnant de cette manche est %s", nom1);
                    solde1+=pot;
                }
                else
                {
                    printf("\nLe gagnant de cette manche est %s", nom2);
                    solde2+=pot;
                }
                printf("\nLe solde restant de %s est de : %d€\n",nom1, solde1);
                printf("Le solde restant de %s est de : %d€\n",nom2, solde2);
                
            //fin de la boucle de partie            
            }while (solde1 != 0 && solde2 != 0);
            // tester qui a une cagnotte positive et afficher le vainqueur de la partie
            if (solde1>0)
            {
                printf("Le gagnant de la partie est %s\n", nom1);
            }
            else
            {
                printf("Le gagnant de la partie est %s\n", nom2);
            }
            // demander à rejouer (réponse possible uniquement 'o' ou 'n')
            // reposer la question si pas 'o' ou 'n'

            do
            {
                printf("Voulez vous rejouer ? (o/n)");
                scanf("%c",&carFin);
            }while (carFin != 'o' && carFin != 'n');
        // fin boucle jeu    
        }while (carFin != 'n');
     // afficher un message d'au revoir    
        printf("Merci d'avoir jouer, au revoir");
       
    }// sinon afficher un message et terminer le programme
    else
    {
        printf("L'un des deux joueurs n'a pas l'âge requis pour jouer au poker");
    }   
     
    
               
    
                
                
               
    
    
            
            
           
    
            
           
    
        
    
    


   






    return (EXIT_SUCCESS);
}

