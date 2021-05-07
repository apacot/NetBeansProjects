/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 29 septembre 2020, 10:44
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
        //p1
	int pid1,pid2;
	int cpt=0;
	pid1 = fork();
	if ( pid1 == 0 ) //p2
	{
		cpt++;
		pid2 = fork();
		if ( pid2 == 0 ) //p3
		{ 
			cpt++;
			printf("dans petit fils cpt=%d a l'adresse %4X\n",cpt,&cpt);
		}
		else //p2
		{
			cpt++;
			printf("dans fils cpt=%d a l'adresse %4X\n",cpt,&cpt);
		}
	}
	else //p1
	{
		cpt++;
		printf("dans pere cpt=%d a l'adresse %4X\n",cpt,&cpt);
	}
    return (EXIT_SUCCESS);
}

