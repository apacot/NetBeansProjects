/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 5 octobre 2020, 10:41
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define TAILLEMAX 255

/*
 * 
 */
int main(int argc, char** argv) 
{
    int pid;
    int tube1[2];
    int tube2[2];
    char chaineEnvois[TAILLEMAX];
    char chaineReception[TAILLEMAX];
    float reelEnvoi;
    float reelRecu;
    int nbOctets;

    //p1
    if(pipe(tube1)==0 && pipe(tube2)==0) //creation des tubes ok
    {
        pid=fork();
        if(pid == 0) //p2
        {
            //init buffer reception
            memset(chaineReception,'\0',TAILLEMAX);
            //lecture dans le tube1 (bloquant)
            nbOctets = read(tube1[0],chaineReception, TAILLEMAX);
            //affichage du message lu dans le tube1
            printf("message du père : %s\n", chaineReception);
            //init reel a envoyer
            reelEnvoi=23.04;
            //ecriture dans le tube2
            nbOctets= write(tube2[1],&reelEnvoi,sizeof(reelEnvoi));
        }
        else //p1
        {
            //init chaine a envoyer
            strcpy(chaineEnvois,"JE SUIS TON PERE");
            //ecriture dans le tube1
            nbOctets = write(tube1[1],chaineEnvois,strlen(chaineEnvois));
            //lecture dans le tube2 (bloquant)
            nbOctets = read(tube2[0],&reelRecu,sizeof(reelRecu));
            //ecriture dans le tube2
            printf("message du fils : %.2f\n", reelRecu);
        }
    }
    return (EXIT_SUCCESS);
}

