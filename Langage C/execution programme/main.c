/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 8 octobre 2019, 13:22
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    int v1;
    short int v2;
    long int v3;
    
    unsigned int v4;
    unsigned short int v5;
    unsigned long int v6;
    
    float r1;
    double r2;
    
    char c1;
    unsigned char c2;
    
    printf("donnez v1\n");
    scanf("%d",&v1);
    printf("donnez v2\n");
    scanf("%hd",&v2);
    printf("donnez v3\n");
    scanf("%ld",&v3);
    printf("donnez v4\n");
    scanf("%d",&v4);
    printf("donnez v5\n");
    scanf("%hd",&v5);
    printf("donnez v6\n");
    scanf("%ld",&v6);
    printf("donnez r1\n");
    scanf("%f",&r1);
    printf("donnez r2\n");
    scanf("%lf",&r2);
    printf("donnez c1\n");
    scanf(" %c",&c1);
    printf("donnez c2\n");
    scanf(" %c",&c2);
    
    
    printf("v1 = %d \n",v1);
    printf("v2 = %hd \n",v2);
    printf("v3 = %ld \n",v3);
    
    printf("v4 = %d \n",v4);
    printf("v5 = %hd \n",v5);
    printf("v6 = %ld \n",v6);
    
    printf("r1 = %f \n",r1);
    printf("r2 = %f \n",r2);
    
    printf("c1 = %c \n",c1);
    printf("c2 = %c \n",c2);
    
    return (EXIT_SUCCESS);
}

