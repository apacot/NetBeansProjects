/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 2 octobre 2019, 10:22
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    int heure;
    int minutes;
    float temps;
    float prix;
    
    prix=0;
    printf("Entrez le temps que vous allez rester dans le parking\n");
    printf("Heure :\n");
    scanf("%d",&heure);
    printf("Minutes:\n");
    scanf("%d",&minutes);
    
    temps=heure*60+minutes;
    printf("temps:%.2f\n",temps);
    
    if (temps<=60) 
    {
        printf("Prix :0,00€\n");
        printf ("Vous n'avez rien à payer");
    }
    if (temps>60 && temps<=150 ) 
    {
        temps=temps/15-4;
        printf("temps:%f en 1/4 d'heure\n",temps);
        prix=temps*0.5;
        printf("Prix :%.2f€",prix);
    }
    if (temps>150 && temps<=180)
    {
        temps=temps/15-4;
        printf("temps:%f en 1/4 d'heure\n",temps);
        prix=3+temps*0.4;
        printf("Prix:%.2f€", prix);
    }
    if (temps>180 && temps<420) 
    {
        temps=temps/15-4;
        printf("temps:%f en 1/4 d'heure\n",temps);
        prix=3+0.8+temps*0.2;
        printf("prix:%.2f€",prix);
    }
    if (temps>420) 
    {
        temps=temps/15-4;
        printf("temps:%f en 1/4 d'heure\n  ",temps);
        prix=3+0.8+0.2*16+temps*0.1;
        printf("prix:%.2f€",prix);
    }
        
        

    

   
        
    
    return (EXIT_SUCCESS);
}

