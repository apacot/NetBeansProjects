/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 22 septembre 2020, 10:33
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{

/*
    int retour;
    retour=system("uname -rom");
    if(retour==-1)
    {
        printf("pb avec l'appel de la fonction system");
        exit(0);
    }
 * 
*/
    fork();
    fork();
    fork();
    printf("* "); 
    
    return (EXIT_SUCCESS);
}

