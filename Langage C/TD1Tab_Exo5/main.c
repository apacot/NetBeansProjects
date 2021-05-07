/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 12 novembre 2019, 13:52
 */

#include <stdio.h>
#include <stdlib.h>
#define TAILLE 5
/*
 * 
 */
int main(int argc, char** argv)
{

    int tabATrier[TAILLE]={5,7,2,1,4};
    int tempo;
    int i;
    int iMin;
    int valMin;
    int j;
    
    for (i=0;i<TAILLE;i++)
    {
        valMin=tabATrier[i];
        iMin=i;
        for (j=i;j<TAILLE;j++)
        {
            if (valMin>tabATrier[j])
            {
                valMin=tabATrier[j];
                iMin=j;
            }
        }
    tempo=tabATrier[i];
    tabATrier[i]=valMin;
    tabATrier[iMin]=tempo;
    
    }        
    return (0);
}

