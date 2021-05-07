/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 28 novembre 2019, 11:04
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    /* ---------------  diapo 9
    int *ptrInt; // pointeur sur entier
    char *ptrCaractere; // pointeur sur char
    float *ptrReel; //pointeur sur réel
    
    printf("taile de ptrInt : %d\n",sizeof(ptrInt));
    printf("taille de ptrCaractere : %d\n",sizeof (ptrCaractere));
    printf("taille de ptrReel : %d\n",sizeof(ptrReel));
    */
    /*---------------------- Diapo 17
    unsigned char *ptrOctet;
    int unEntier = 0x12345678, i;
    
    ptrOctet = (char *) &unEntier;
    for (i = 0; i<sizeof (unEntier);i++)
    {
        printf("%p : %hhx\n", ptrOctet, *ptrOctet);
        ptrOctet++;
    }
    */
    /*--------------------Diapo 21
    int tabA[10];
    int *ptrA;
    
    ptrA = tabA;
    ptrA = tabA + 9;
    ptrA = tabA + 10;
    ptrA = tabA +11;
    ptrA = tabA - 1;
    */
    return (EXIT_SUCCESS);
    
}

