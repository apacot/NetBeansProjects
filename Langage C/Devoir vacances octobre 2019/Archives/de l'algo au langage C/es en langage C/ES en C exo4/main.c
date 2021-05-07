/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mgirard
 *
 * Created on 4 novembre 2019, 21:18
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char lettre;
    char i;
    int place;
    printf("Donnez une lettre:");
    scanf("%s",&lettre);
    for(i=1 ;i<26;i++)
    { 
        place=lettre-96;
    }
    printf("La place de la lettre est : %d", place);
    return (EXIT_SUCCESS);
}

