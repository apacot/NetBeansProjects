/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 28 janvier 2020, 13:16
 */

#include "compression_biblio.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    int i;
    char arg2;
       
    //TRAITEMENT
    
    printf("argc <- %d\n",argc);
    for(i=0;i<argc;i++)
    {
        printf("argv[%d] <- %s \n",i,argv[i]);
    }
    
    if (argc == 4)
    {
        //convertir le 2e argument en char
        sscanf(argv[1],"%c",&arg2);
        if (arg2 == 'd')
        {
            //appel a la fonction decompressBmp
            printf("decompression de %s dans %s\n",argv[2], argv[3]);
            decompressBmp(argv[2],argv[3]);            
        }
        if (arg2 == 'c')
        {            
            //appel a la fonction compressBmp
            printf("compression de %s dans %s\n",argv[2], argv[3]);
            compressBmp(argv[2],argv[3]);
        }
        
    }
    
    
    
    return (EXIT_SUCCESS);
}

