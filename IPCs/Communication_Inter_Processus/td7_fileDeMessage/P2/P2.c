/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 2 novembre 2020, 11:47
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

int randomI()
{
    return ((int)100.0*(rand()/(RAND_MAX+0.1)));
}

char randomC()
{
    char tabCar[3]={'a','b','c'};
    int index=0;
    index=randomI()%3;
    return tabCar[index];
}

int main(int argc, char** argv) 
{
    struct donnees *zoneDePartage;
    key_t clef;
    int id;
    // creation de la clef de partage
    clef=ftok("/tmp/bidon",'a');
    if (clef==-1)
    {
        printf("pb ftok : %s\n",strerror(errno));
        exit(errno);
    }
    // creation du segment mémoire partagé
    id=shmget(clef,sizeof(struct donnees),IPC_CREAT | 0600);
    if (id==-1)
    {
        printf("pb shmget : %s\n",strerror(errno));
        exit(errno);
    }
    printf("id du segment : %d\n",id);
    // attribution adresse virtuelle du segment
    zoneDePartage = (struct donnees*)shmat(id,NULL,SHM_W);  // attribution en R/W
    if (zoneDePartage==(void *)-1)
    {
        printf("pb shmat : %s\n",strerror(errno));
        exit(errno);
    }
    // boucle infinie de changement de temperature et de pression
    while (1==1)
    {
        sleep(1);
    }
    
    return (EXIT_SUCCESS);
}

