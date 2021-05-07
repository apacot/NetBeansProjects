/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 12 novembre 2019, 13:18
 */

#include <stdio.h>
#include <stdlib.h>
#define NB_ELE 11
/*
 * 
 */
int main(int argc, char** argv) 
{
/* version 1
 * 
    int tab[NB_ELE];
    int tab2[NB_ELE];
    int i;
    
    for (i=0; i=NB_ELE-1;i++)
    {
        tab2[NB_ELE-1-i]=tab[i];
    }
    for (i=0; i=NB_ELE;i++)
    {
        tab[i]=tab2[i];
    }
    
    Fin version 1 */
    
    //---------------------------------Version 2-------------------------
    
    int tab[NB_ELE]={2,4,6,8,10,12,14,16,18,20,22};
    int i;
    int tempo;
    
    //inversion contenu tab
    for (i=0;i<NB_ELE/2;i++)
    {
        tempo=tab[NB_ELE-1-i];
        tab[NB_ELE-1-i]=tab[i];
        tab[i]=tempo;
    }
    
    return (EXIT_SUCCESS);
}

