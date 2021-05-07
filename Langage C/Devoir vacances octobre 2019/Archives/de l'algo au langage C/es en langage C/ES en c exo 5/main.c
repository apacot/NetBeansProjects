/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mgirard
 *
 * Created on 4 novembre 2019, 21:04
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {

    char lettre;
    char lettre2;
    int resultat;
    int i;
    int place;
    int place2;
    printf("Donnez une lettre:");
    scanf("%s",&lettre);
    for(i=1 ;i<26;i++)
    { 
        place=lettre;
    }
    printf("Donnez la lettre numero 2:");
    scanf("%s",&lettre2);
    for(i=1 ;i<26;i++)
    { 
        place2=lettre2;
    }
    resultat=place-place2;
    printf("Le rang entre les deux lettres est:%d", resultat);
    return (EXIT_SUCCESS);
} 
