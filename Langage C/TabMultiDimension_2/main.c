/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 14 novembre 2019, 11:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBMOTS 3
#define LONGMAXMOT 10

/*
 * 
 */
int main(int argc, char** argv) 
{

    char tabChaine[NBMOTS][LONGMAXMOT] = {"coucou", "salut", "hello"};
    int i;
    char mot[LONGMAXMOT];
    int motTrouve;
    
    motTrouve=0;
    
    printf("Donnez un mot : ");
    gets(mot);
    for(i=0;i<NBMOTS;i++){
    if (strcmp(tabChaine[i], mot) == 0) 
    {
        motTrouve=1;
    } 
    }
    if(motTrouve==1)
    {
        printf("mot trouve\n");
    }            
    else
    {
        printf("mot pas trouve");
    }
    return (EXIT_SUCCESS);
}

