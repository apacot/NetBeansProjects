/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 1 octobre 2019, 14:13
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    float Note;
    scanf("%f", &Note);

    if (Note < 10)
        printf("Vous avez moins que la moyenne");
    else /* --> Note >=10 */
        if (Note > 10)
        printf("Vous avez plus que la moyenne");
    else /*--> Note=10 */
        printf("Vous avez la moyenne");

    return (EXIT_SUCCESS);
}

