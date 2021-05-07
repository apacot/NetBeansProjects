/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 6 octobre 2020, 10:57
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/syscall.h>

typedef struct
{
    int v1;
    int v2;
    int v3;    
}laStruct;

laStruct zoneCommune;

void *threadT1(void *arg) 
{
    //int val = *(int *)arg; //correspond aux deux lignes en dessous
    int *ptr = (int *)arg; //ptr prend l'adresse de l'entier en paramètre
    int val = *ptr; // récupération du contenu pointé 
    printf("pid dans thread T1 : %d\n", getpid());
    printf("tid dans thread T1 : %d\n",syscall(SYS_gettid));
    zoneCommune.v1 = val;
    
    pthread_exit((void *) "");
}
void *threadT2(void *arg) 
{
    //int val = *(int *)arg; //correspond aux deux lignes en dessous
    int *ptr = (int *)arg; //ptr prend l'adresse de l'entier en paramètre
    int val = *ptr; // récupération du contenu pointé 
    printf("pid dans thread T2 : %d\n", getpid());
    printf("tid dans thread T2 : %d\n",syscall(SYS_gettid));
    zoneCommune.v2 = val;
    
    pthread_exit((void *) "");
}
void *threadT3(void *arg) 
{
    //int val = *(int *)arg; //correspond aux deux lignes en dessous
    int *ptr = (int *)arg; //ptr prend l'adresse de l'entier en paramètre
    int val = *ptr; // récupération du contenu pointé 
    printf("pid dans thread T3 : %d\n", getpid());
    printf("tid dans thread T3 : %d\n",syscall(SYS_gettid));
    zoneCommune.v3 = val;
    
    pthread_exit((void *) "");
}

int main() 
{
    int res;
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    void *thread_result;
    int val1,val2,val3;   
    val1 = 10;
    val2 = 20;
    val3 = 30;
    printf("pid dans main : %d\n", getpid());
    printf("tid dans main : %d\n", syscall(SYS_gettid));
    zoneCommune.v1 = 0;
    zoneCommune.v2 = 0;
    zoneCommune.v3 = 0;
    printf("zone commune avant thread : \nv1 : %d \nv2 : %d \nv3 : %d\n", zoneCommune.v1,zoneCommune.v2,zoneCommune.v3 );
    
    res = pthread_create(&t1, NULL, threadT1, (void *) &val1);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&t2, NULL, threadT2, (void *) &val2);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&t3, NULL, threadT3, (void *) &val3);
    if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    
    printf("attente de la fin du thread...\n");

    res = pthread_join(t1, &thread_result);
    if (res != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    printf("OK, valeur de retour du Thread join de t1 :%d\n",  zoneCommune.v1);
    res = pthread_join(t2, &thread_result);
    if (res != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    printf("OK, valeur de retour du Thread join de t2 :%d\n",  zoneCommune.v2);
    res = pthread_join(t3, &thread_result);
    if (res != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    printf("OK, valeur de retour du Thread join de t3 :%d\n",zoneCommune.v3);
    exit(EXIT_SUCCESS);
}

