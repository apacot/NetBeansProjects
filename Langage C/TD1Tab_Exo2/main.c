/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 5 novembre 2019, 16:25
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
#define NB_JOUR 31
/*
 * 
 */
void msleep(unsigned int maxTime)
{
    /*
    struct timespec {
    time_t tv_sec;        // secondes
    long   tv_nsec;       // nanosecondes
};
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
     */
    struct timespec req;
    struct timespec rem;
    time_t secondes = 0;
    long nanoSecondes = 0;
    if (maxTime >= 1000)
    {
        do
        {
            secondes++;
            maxTime -= 1000;
        }
        while (maxTime >= 1000);
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
unsigned int aleatoire(unsigned int maxAlea)
{
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



int main(int argc, char** argv) 
{
    int temp[NB_JOUR];
    int jours;
    int tempmini;
    int tempmax;
    int i;
    //------------------saisie temperature------------------
    
    printf("Voici les température de chaque jour du mois : \n");
    
    for (i=0; i<NB_JOUR; i++)
    {
       
        //printf("Jour %d :",i+1);
        //scanf("%f",&temp[i]);
        temp[i]= aleatoire (28);
    }
    //----------------------- affichage des températures-------------
    
    for (i=0; i<NB_JOUR; i++)
    {
        printf("Jour %d : %d°C\n",i+1,temp[i]);
        usleep(500000);
    }
    sleep (1);
    //----------------recherche de la plus petite température----------
    
    tempmini=temp[0];
    jours=0;
    for (i=0; i<NB_JOUR;i++)
    {
        if (tempmini>temp[i])
        {
            tempmini=temp[i];
            jours=i;
        }
    }
    printf("La température la plus faible est %d °C au jour %d\n", tempmini,jours+1);
    
    sleep(1);
    //----------------recherche de la plus grande température----------
    
    tempmax=temp[0];
    jours=0;
    for (i=0; i<NB_JOUR;i++)
    {
        if (tempmax<temp[i])
        {
            tempmax=temp[i];
            jours=i;
        }
    }
    printf("La température la plus grande est %d °C au jour %d\n", tempmax,jours+1);
    
    
    return (EXIT_SUCCESS);
}

