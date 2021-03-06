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

int main(int argc, char** argv) {
    int pid;
    int pidP1 = getpid();
    (void) signal(SIGUSR1, traitement); // rederoutage des signaux SIGUSR1 vers la fonction traitement

    //p1
    pid = fork();
    if (pid == 0) //p2
    {
        pid = fork();
        if (pid == 0) //p3
        {
            printf("P3 : pid = %d ppid = %d\n", getpid(), getppid());
            kill(pidP1, SIGUSR1);
        } else //p2
        {
            sleep(1);
            printf("P2 : pid = %d ppid = %d\n", getpid(), getppid());
            kill(pidP1, SIGUSR1);
        }

    } else //p1
    {
        pause();
        pause();
        printf("P1 : pid = %d ppid = %d\n", getpid(), getppid());
    }

    return (EXIT_SUCCESS);
}

