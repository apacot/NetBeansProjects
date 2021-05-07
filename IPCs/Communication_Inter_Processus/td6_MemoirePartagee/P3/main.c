/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 12 octobre 2020, 10:25
 */

/*
 * p3 :
 *  affichage des champs partagee
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "zone.h"



int main(int argc, char** argv) 
{
    zoneMemPartagee *zoneDePartage;
    key_t clef;
    int id;
    //creation clef de partage
    clef = ftok("/tmp/bidon",'a');
    if(clef==-1)
    {
        printf("pb ftok : %s\n",strerror(errno));
        exit(errno);
    }
    // creation du segment memoire partagee
    id = shmget(clef,sizeof(zoneMemPartagee),IPC_CREAT | 0600);
    if(id == -1)
    {
        printf("pb shmget : %s\n",strerror(errno));
        exit(errno);
    }
    // attribution adresse virtuelle du segment
    zoneDePartage = (zoneMemPartagee *)shmat(id,NULL,SHM_R); //attribution en R/W (lecture + ecriture)
    if(zoneDePartage == (void *)-1)
    {
        printf("pb shmat : %s\n",strerror(errno));
        exit(errno);
    }
    //boucle infini d'affichage
    while (1==1)
    {
        printf("Temperature : %.2f\n Pression : %d\nOrdre : %c\n", zoneDePartage->temp,zoneDePartage->press,zoneDePartage->ordre);
        sleep(2);
        
    }
    return (EXIT_SUCCESS);
}

