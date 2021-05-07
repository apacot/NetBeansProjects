/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 1 octobre 2019, 15:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <senseHat.h>
#include <unistd.h>

/*
 * 
 */
int main() {
    int ligne;
    int colonne;
    int touche;
    InitialiserLeds();
    InitialiserJoystick();
    colonne=7;
    do {
         for(ligne=0;ligne<=7;ligne++)
        {
                Allumer(0,ligne,ROUGE);
                Allumer(ligne,0,ROUGE);
                Allumer(7,ligne,ROUGE);
                Allumer(ligne,7,ROUGE);
        }
        sleep(1);
        Effacer();
        for (ligne = 0; ligne <= 7; ligne++) 
        {
            Allumer(ligne, ligne, VERT);
            Allumer(colonne, ligne, VERT);
            colonne=colonne-1;
        }
       
        touche = ScannerJoystick();
    } while (touche != KEY_ENTER);


    return 0;
}

