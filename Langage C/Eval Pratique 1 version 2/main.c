/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 16 octobre 2019, 10:21
 * Modified on 16 octobre 2019, 10:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/timeb.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/random.h>

// attendre un maxTime millisecondes

void msleep(unsigned int maxTime) {
    /*
    struct timespec {
    time_t tv_sec;        // secondes
    long   tv_nsec;       // nanosecondes
};
     */
    struct timespec req;
    struct timespec rem;
    time_t secondes = 0;
    long nanoSecondes = 0;
    if (maxTime >= 1000) {
        do {
            secondes++;
            maxTime -= 1000;
        } while (maxTime >= 1000);
    }
    nanoSecondes = maxTime * 1000000;
    req.tv_sec = secondes;
    req.tv_nsec = nanoSecondes;
    nanosleep(&req, &rem);

}

/**
 * 
 * @param maxAlea valeur max de l'aleatoire
 * @return retourne une valeur entiere E[0..maxAlea[
 */
unsigned int aleatoire(unsigned int maxAlea) {
    struct timeb t;
    float a, b;
    unsigned int nbmilli;
    ftime(&t);
    nbmilli = t.time * 1000 + t.millitm;
    srand(nbmilli);
    a = rand();
    b = (maxAlea * a) / RAND_MAX;
    msleep(250);
    return ( (unsigned int) b);


}

int main(int argc, char** argv) {
    int valAlea;
    int Alea1, Alea2, Alea3, Alea4;

   /* valAlea = aleatoire(9);
    Alea1 = valAlea;
    printf("Le 1er chiffre est : %d \n", valAlea);
    valAlea = aleatoire(9);
    Alea2 = valAlea;
    printf("Le 2e chiffre est : %d \n", valAlea);
    valAlea = aleatoire(9);
    Alea3 = valAlea;
    printf("Le 3e chiffre est : %d \n", valAlea);
    valAlea = aleatoire(9);
    Alea4 = valAlea;
    printf("Le 4e chiffre est : %d \n", valAlea);*/

    //-------------------------------------------mon code------------------------------------------------------------------
    // déclaration de variable (chaîne de caractère et entier)
    char pseudo[15];
    int chiffre1, chiffre2, chiffre3, chiffre4;
    int combi;
    int ok;
    char lettre;
    int essai;

    printf("Donnez votre pseudo : ");
    scanf("%s", pseudo); //le joueuer rentre son pseudo
    printf("Bonjour %s\n", pseudo);

    do {
        valAlea = aleatoire(9);
        Alea1 = valAlea;
        //printf("Le 1er chiffre est : %d \n", valAlea);
        valAlea = aleatoire(9);
        Alea2 = valAlea;
        //printf("Le 2e chiffre est : %d \n", valAlea);
        valAlea = aleatoire(9);
        Alea3 = valAlea;
       // printf("Le 3e chiffre est : %d \n", valAlea);
        valAlea = aleatoire(9);
        Alea4 = valAlea;
        //printf("Le 4e chiffre est : %d \n", valAlea);
        printf("Vous devez donner 4 chiffres compris entre 0 et 9\n"); //le joueur rentre ses 4 chiffres
        // réinitialiser les variables
        ok = 0;
        chiffre1=0;
        chiffre2=0;
        chiffre3=0;
        chiffre4=0;
        while (ok != 1) {
            printf("Chiffre 1 : ");
            scanf("%d", &chiffre1);
            printf("Chiffre 2 : ");
            scanf("%d", &chiffre2);
            printf("Chiffre 3 : ");
            scanf("%d", &chiffre3);
            printf("Chiffre 4 : ");
            scanf("%d", &chiffre4);

            //le programme affiche la combinaison rentrée par le joueur

            printf("Votre proposition est : %d%d%d%d\n", chiffre1, chiffre2, chiffre3, chiffre4);
            essai=1;

            if (chiffre1 == Alea1) //tester la combinaison du joueur, et voir si elle est identique à celle générée
            {
                if (chiffre2 == Alea2) 
                {
                    if (chiffre3 == Alea3) 
                    {
                        if (chiffre4 == Alea4) 
                        {
                            ok = 1;
                            printf("C'est la bonne combinaison\n"
                                    "Bravo %s vous avez trouve en %d coups !",pseudo,essai);
                        } 
                        else 
                        {
                            ok = 0;
                            printf("Ce n'est pas la bonne combinaison\n"
                                    "Veuillez réessayer\n");
                            essai=essai+1;                            
                        }
                    } 
                    else 
                    {
                        ok = 0;
                        printf("Ce n'est pas la bonne combinaison\n"
                                "Veuillez réessayer\n");
                        essai=essai+1;
                    }
                } 
                else
                {
                    ok = 0;
                    printf("Ce n'est pas la bonne combinaison\n"
                            "Veuillez réessayer\n");
                    essai=essai+1;
                }
            } 
            else 
            {
                ok = 0;
                printf("Ce n'est pas la bonne combinaison\n"
                        "Veuillez réessayer\n");
                essai=essai+1;
            }


        }
        printf("Voulez vous faire une autre partie (o/n)?");
        scanf(" %c",&lettre);
    } while (lettre!= 'n');
    printf("A bientot %s",pseudo);

    return (EXIT_SUCCESS);
}

