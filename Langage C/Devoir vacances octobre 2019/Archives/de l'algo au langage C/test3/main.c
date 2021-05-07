/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: BOUGEOT
 *
 * Created on 22 octobre 2019, 19:46
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
    int choix;
    
    
    char nom[49];
    char prenom[49];
    
    
    printf("jour de naissance: ");
    scanf("%d", &jour);
    printf("mois de naissance: ");
    scanf("%d", &mois);    
    printf("votre date de naissance est:");
    scanf("%d", &naissance);
    printf("votre date de naissance est le: %d/%d/%d\n",jour,mois,naissance);
    if (naissance<=1999){
        printf("vous êtes autorisé à continuer\n");
    }
    else
        printf("desole vous êtes trop jeune\n");
    printf("Format d'affichage de votre date de naissance: \n 1-jj/mm/aaaa\n 2-jj-mm-aaaa\n 3-jj:mm:aaaa\n 4-jj.mm.aaaa\n");
    printf("Choissisez le format d'affichage (1,2,3 ou 4):");
    scanf("%d", &choix);
    switch(choix)
    {
        case 1:
            printf("%d/%d/%d",jour,mois,naissance); 
            break;
        case 2:
            printf("%d-%d-%d",jour,mois,naissance); 
            break;
        case 3:
            printf("%d:%d:%d",jour,mois,naissance);
            break;
        case 4:
            printf("%d.%d.%d",jour,mois,naissance); 
            break;
    }

    return (EXIT_SUCCESS);
}


