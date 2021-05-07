/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 15 octobre 2019, 15:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    int ligne;
    int colonne;
    colonne = 7;

    InitialiserLeds();
    
    for (ligne= 0; ligne <= 7; ligne++) 
    {
        Allumer(ligne, ligne, VERT);
        Allumer(colonne, ligne, VERT);
        colonne=colonne-1;
        
    }
    





return (EXIT_SUCCESS);
}

