/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mgirard
 *
 * Created on 4 novembre 2019, 20:59
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int a;
    int b;
    int resultat;
    printf("Donnez la première valeur:");
    scanf("%d", &a);
    printf("Donnez la seconde valeur:");
    scanf("%d", &b);
    resultat=a+b;
    printf("Le resultat est:%i", resultat);
     
    return (EXIT_SUCCESS);
}

