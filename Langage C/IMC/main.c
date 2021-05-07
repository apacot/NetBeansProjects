/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 1 octobre 2019, 14:27
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv)
{
    float IMC;
    scanf("%f",&IMC);
    
    if ((IMC>=18.5)&&(IMC<=25))
        printf("Vous êtes dans la norme");
    return (EXIT_SUCCESS);
}

