/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 12 octobre 2020, 10:25
 */

/*
 * p1 :
 *  met à jour temperature et pression dans la zone partagee 
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

float randomF(){ 
	return ((float)100.0*(rand()/(RAND_MAX+0.1))); 
} 

int randomI(){ 
	return ((int)100.0*(rand()/(RAND_MAX+0.1))); 
}

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
    zoneDePartage = (zoneMemPartagee *)shmat(id,NULL,SHM_W); //attribution en R/W (lecture + ecriture)
    if(zoneDePartage == (void *)-1)
    {
        printf("pb shmat : %s\n",strerror(errno));
        exit(errno);
    }
    printf("Id du segment : %d\n", id);
    //boucle infini de changement temperature et pression
    while (1==1)
    {
        zoneDePartage->temp = randomF();
        sleep(1);
        zoneDePartage->press = randomI();
        sleep(2);
        
    }
    return (EXIT_SUCCESS);
}

