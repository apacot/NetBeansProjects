/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mgirard
 *
 * Created on 4 novembre 2019, 20:56
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float val1;
    float val2;
    float resultat;
    printf("Donnez la première valeur:");
    scanf("%f", &val1);
    printf("Donnez la seconde valeur:");
    scanf("%f", &val2);
    resultat=val1+val2;
    printf("Le resultat est:%f", resultat);
    
    return (EXIT_SUCCESS);
}

