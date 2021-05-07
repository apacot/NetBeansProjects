/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 14 novembre 2019, 10:23
 */

#include <stdio.h>
#include <stdlib.h>
#define NBCOL 5
#define NBLIGNE 3

/*
 * 
 */
int main(int argc, char** argv) 
{

    int tab[NBCOL][NBLIGNE];
    int col;
    int ligne;
    int cpt;
    
    cpt=0;
    //remplissage de tab
    for (ligne = 0; ligne < NBLIGNE; ligne++)
    {
        for (col = 0; col < NBCOL; col++) 
        {
            tab[col][ligne] = cpt;
            cpt++;
            
           //printf("%d ", tab[col][ligne]);
           //printf("Dans la case (%d;%d) il y a un %d\n", col, ligne, tab[col][ligne]);
        }
        
    }
    // affichage de tab
    for (ligne = 0; ligne < NBLIGNE; ligne++)
    {
        for (col = 0; col < NBCOL; col++) 
        {
            printf("%d ", tab[col][ligne]);
            
        }
        printf("\n");
    }
    return (EXIT_SUCCESS);
}

