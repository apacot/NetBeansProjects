/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 12 novembre 2019, 16:27
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

    char phrase[TAILLEMAX];
    int i;
    
    printf("Quelle est votre phrase ?\n");
    gets(phrase);
    printf("Votre phrase va être inversée\n");
    
     for (i=0;i<strlen (phrase);i++)
    {
        if (phrase[i]>='A' && phrase[i]<= 'Z')
        {
            phrase[i]=phrase[i]+32;
        }
        else 
        {
            if (phrase [i]>='a' && phrase[i]<= 'z')
            {
                phrase[i]=phrase[i]-32;
            }    
    }
    }
    
    printf("Voici votre phrase avec les majuscules et minuscules inversées :\n%s",phrase);
    
    return (EXIT_SUCCESS);
}

