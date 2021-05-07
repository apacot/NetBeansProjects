/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Exo2.c
 * Author: apacot
 *
 * Created on 15 octobre 2019, 13:39
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int main(int argc, char** argv) {
//-----------------------------------------2.4----------------------------
    /*   char note;

       printf("Indiquez votre Lettre :\n");
       scanf("%c", &note);

       if (note=='A') 
       {
           printf("Vous avez un entre 16 et 20");
       }
       if (note=='B') 
       {
           printf("Vous avez entre 12 et 16");
       }
       if (note=='C') 
       {
           printf("Vous avez entre 8 et 12");
       }
       if (note=='D') 
       {
           printf("Vous avez entre 4 et 8");
       }
       if (note=='E') 
       {
           printf("Vous avez entre 0 et 4");
       }
     */
//------------------------------------------------------------------2.5--------------------------
    char lettre;
    printf("Quelle est votre lettre ?\n");
    scanf("%c", &lettre);

    switch (lettre) {

        case 'A':
            printf("Vous avez entre 16 et 20");
            break;
        case 'B':
            printf("Vous avez entre 12 et 16");
            break;
        case 'C':
            printf("Vous avez entre 8 et 12");
            break;
        case 'D':
            printf("Vous avez entre 4 et 8");
            break;
        case 'E':
            printf("Vous avez entre 0 et 4");
            break;


    }
    return (EXIT_SUCCESS);
}



