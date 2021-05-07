/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mgirard
 *
 * Created on 4 novembre 2019, 20:31
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int val1;
    int val2;
    unsigned int resultat;
    printf("Donnez la première valeur:");
    scanf("%d", &val1);
    printf("Donnez la seconde valeur:");
    scanf("%d", &val2);
    resultat=val1+val2;
    printf("Le resultat est:%u",resultat);
    
    return (EXIT_SUCCESS);
}

