/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 10 décembre 2019, 13:12
 */

#include "bilbio.h"
/*
 * 
 */
int main(int argc, char** argv) 
{

/*    
 *  Exo 1
     
    char *ptrCar;
    int *ptrEntier;
    float *ptrReel;
    char chaine[] = "1234568000A";
    int i;
    
    ptrCar = chaine;
    ptrEntier = (int *) chaine;
    ptrReel = (float *) chaine;
    
    for (i=0;i<3;i++)
    {
        printf("ptrCar    = %p     *ptrCar    = %c\n",ptrCar, *ptrCar);
        printf("ptrEntier = %p     *ptrEntier = %c\n", ptrEntier, *ptrEntier);
        printf("ptrReel   = %p     *ptrReel   = %f\n",ptrReel, *ptrReel);
        
        ptrCar++;
        ptrEntier++;
        ptrReel++;
        printf("\n");
    }
*/
    
/*
 *  Exo 5
    int nbMois;
    char *mois;
    
    printf("Numéro de mois : ");
    scanf("%d",&nbMois);
    mois = moisNom(nbMois);
    printf("Le mois numero %d est : %s\n",nbMois,mois);
*/
    
/*
 *  Exo 6
    char maChaine[255];
    char *chaineSansLesE;
    gets(maChaine);
    chaineSansLesE=supprimerE(maChaine);
    printf("chaine sans les e : %s \n",chaineSansLesE);
*/
    
/*
 *  Exo 7
    char *nom;
    nom = saisirChaine("Comment vous appelez-vous ? ");
    printf("Vous vous appelez : %s\n",nom);
    
*/
    
    return (EXIT_SUCCESS);
}

