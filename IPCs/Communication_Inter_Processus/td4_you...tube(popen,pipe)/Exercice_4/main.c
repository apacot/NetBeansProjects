/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 29 septembre 2020, 11:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
/*
 * 
 */


// fonction de traitement du signal SIGUSR1

void traitement(int sig) 
{
    (void) signal(SIGUSR1, traitement);
    printf("un signal SIGUSR1 je suis pid :%d\n", getpid());
}

int main(int argc, char** argv) 
{
    int pid;
    int pidP3Envoi;
    int pidP3Recu;
    int tube[2];
    int pidP1 = getpid();
    int nbOctets;
    (void) signal(SIGUSR1, traitement); // rederoutage des signaux SIGUSR1 vers la fonction traitement

    //p1
    if (pipe(tube) == 0) 
    {
        pid = fork();
        if (pid == 0) //p2
        {
            pid = fork();
            if (pid == 0) //p3
            {
                pidP3Envoi=getpid();
                nbOctets = write(tube[1],&pidP3Envoi,sizeof(pid)); //ecriture dans le tube
                printf("P3 : pid = %d ppid = %d\n", getpid(), getppid());
                pause();

            } else //p2
            {
                printf("P2 : pid = %d ppid = %d\n", getpid(), getppid());  
                pause();
            }

        } else //p1
        {
            nbOctets = read(tube[0],&pidP3Recu,sizeof(pidP3Recu)); //lecture dans le tube
            printf("P1 : pid = %d ppid = %d\n", getpid(), getppid());
            kill(pid, SIGUSR1); // envoyer SIGUSR1 a P2
            kill(pidP3Recu, SIGUSR1); //envoyer SIGUSR1 a P3
        }
    }
    return (EXIT_SUCCESS);
}

