/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 1 octobre 2019, 16:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>

/*
 * 
 */
int main() {
    int ligne,colonne;
    InitialiserLeds();

    
    for (ligne = 0; ligne <= 7; ligne++)
    {
        Effacer();
        for (colonne = 0; colonne <8; colonne++)
    {    
        Allumer(ligne, colonne,VERT);
    }
    sleep(1);
    }    
        
        
    
    return 0;
}

