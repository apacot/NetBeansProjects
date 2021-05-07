/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 3 octobre 2019, 10:46
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

/*
 * 
 */
int main(int argc, char** argv) {
    float ret;
    
    ret=equation(10,2,1);
    afficherValeur(ret);
    ret=polynome(4);
    afficherValeur(ret);
    

    return (EXIT_SUCCESS);
}

