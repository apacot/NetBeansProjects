/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: BOUGEOT
 *
 * Created on 21 octobre 2019, 14:26
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int jour;
    int mois;
    int naissance;
    
    
    char nom[49];
    char prenom[49];
    
    
    printf("jour de naissance: ");
    scanf("%d", &jour);
    printf("mois de naissance: ");
    scanf("%d", &mois);    
    printf("votre date de naissance est:");
    scanf("%d", &naissance);
    printf("votre date de naissance est le: %d/%d/%d\n",jour,mois,naissance);
    
   
    printf("votre nom : %s",nom);
    scanf("%s", nom);
    printf("votre prenom : %s",prenom);
    scanf("%s", prenom);
    printf("Bonjour %s %s",prenom,nom);
    return (EXIT_SUCCESS);
}

