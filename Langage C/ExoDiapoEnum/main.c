/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 12 décembre 2019, 10:24
 */

#include "enum_biblio.h"
/*
 * 
 */
int main(int argc, char** argv) 
{

/*  Exercice 1
 * 
    char *nomJour[7]={"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi"," dimanche"};
    jours aujourdhui=SAMEDI;
    printf("%s\n",nomJour[aujourdhui]) ;
*/
    char *chaine;
    boolean idem;
    chaine = saisirChaine("Donnez un mot à tester pour savoir si c'est un palindrome : ");
    
    idem=estUnPalindrome(chaine);
    
    if(idem==TRUE)
    {
        printf("c'est un palindrome");
    }
    else
    {
        printf("ce n'est pas un palindrome");
    }
    
       
    return (EXIT_SUCCESS);
}

