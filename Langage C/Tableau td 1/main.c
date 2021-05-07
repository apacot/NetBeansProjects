/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.c
 * Author: apacot
 *
 * Created on 5 novembre 2019, 14:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NB_CASES 5
/*
 * 
 */
int main(int argc, char** argv) 
{
    float notes[NB_CASES];
    int i;
    //---------------------Saisie des notes--------------------------
    
    for (i=0; i<NB_CASES; i++)
    {
        printf("Note de l'élève %d ?\n",i+1);
        scanf("%f",&notes[i]);
        
    }
    
    //------------------------Affichage des notes-------------------------
    
    for (i=0; i<NB_CASES; i++)
    {
        printf("L'élève numéro %d a eu la note %.1f/20 \n",i+1,notes[i]);
        sleep (1);
        
    }
    

    return (EXIT_SUCCESS);
}

