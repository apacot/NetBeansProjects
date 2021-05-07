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
    int tube[2];
    char chaineEnvois[TAILLEMAX];
    char chaineReception[TAILLEMAX];
    int nbOctets;

    //p1
    if(pipe(tube)==0) //creation du tube ok
    {
        pid=fork();
        if(pid == 0) //p2
        {
            //init buffer reception
            memset(chaineReception,'\0',TAILLEMAX);
            //lecture dans le tube (bloquant)
            nbOctets = read(tube[0],chaineReception, TAILLEMAX);
            //affichage du message lu dans le tube
            printf("message du père : %s\n", chaineReception);
        }
        else //p1
        {
            //init chaine a envoyer
            strcpy(chaineEnvois,"JE SUIS TON PERE");
            //ecriture dans le tube
            nbOctets = write(tube[1],chaineEnvois,strlen(chaineEnvois));
        }
    
    }
    
    
    
    return (EXIT_SUCCESS);
}

