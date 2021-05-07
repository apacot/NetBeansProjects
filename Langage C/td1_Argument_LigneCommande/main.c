/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 12 décembre 2019, 11:14
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
// char **argv <-> argv[NBCHAINE][LONGUEURSCHAINES]
int main(int argc, char** argv) 
{
/*  Exercice 1 
    int i;    
    printf("Il y a %d paramètres\n",argc);
    
    for(i=0;i<argc;i++)
    {
        printf("argument %d: %s \n",i,argv[i]);
    }
*/
    
    char operateur;
    float val1, val2, resultat;
    // si il n'y a pas 3 args après le nom de l'executable, sortir du prog
    if (argc != 4)
    {
        printf("usage : %s + val1 val2 \n", argv[0]);
        exit(0);
    }
    //conversion des args et affectation dans les variables correspondantes
    sscanf(argv[1],"%c",&operateur);
    sscanf(argv[2],"%f",&val1);
    sscanf(argv[3],"%f",&val2);
    
    //tester l'operateur et affecter le résultat
    // de l'operation en fonction de l'opérateur
    switch(operateur)
    {
        case '+' :
            resultat = val1+val2;
            break;
        case '-' :
            resultat = val1-val2;
            break;
        case 'x' :
            resultat = val1*val2;
            break;
        case '/' : 
            resultat = val1/val2;
            break;
    }
    //afficher le resultat de l'operation
    printf("%.2f %c %.2f = %.2f\n",val1,operateur,val2,resultat);
    
    return (EXIT_SUCCESS);
}

