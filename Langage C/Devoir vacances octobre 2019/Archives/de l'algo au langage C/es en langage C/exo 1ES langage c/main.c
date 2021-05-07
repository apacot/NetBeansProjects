/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Mgirard
 *
 * Created on 4 novembre 2019, 20:14
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int x; 
    int y;
    int rayon;
    printf("Donnez les coordonnées en x du cercle:");
    scanf("%d", &x);
    printf("Donnez les coordonnées en y du cercle:");
    scanf("%d", &y);
    printf("Donnez le rayon du cercle:");
    scanf("%d", &rayon);
    printf("Le cercle est au coordonnées(%d,%d)et possède un rayon de %d", x,y,rayon);
    return (EXIT_SUCCESS);
}

