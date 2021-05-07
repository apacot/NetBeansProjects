/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 19 novembre 2019, 13:10
 */

#include <stdio.h>
#include <stdlib.h>
#include "exo1.h"
/*
 * 
 */


int main(int argc, char** argv) 
{

    char genre;
    
    printf("vous êtes un homme ou une femme (h/f)? ");
    scanf("%c",&genre);
    
    afficherMenu(genre);
    
    //afficherMenu('h'); ---------------------> Exemple d'affichage 
            
    return (0);
}

