/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 7 novembre 2019, 10:49
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLEMAX 255

/*
 * 
 */
int main(int argc, char** argv) 
{

    char chaine[TAILLEMAX];
    printf("Quelle est votre phrase ?\n");
    gets(chaine);
    printf("Votre phrase : %s",chaine);
    return (EXIT_SUCCESS);
}

