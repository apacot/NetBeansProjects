/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 15 janvier 2020, 10:35
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
 * 
 */
int main(int argc, char** argv) 
{

    int retour;
    FILE *fic;
    unsigned int largeur;
    unsigned int hauteur;
    unsigned int couleur;
    int i;
    
    //ouverture du fichier en lecture
    fic = fopen("/home/USERS/ELEVES/SNIR2019/imgBMP/plasmaRLE.bmp","r");
    if (fic == NULL) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    // on se positionne au 18e octet (à la largeur) 
    retour = fseek(fic,18,SEEK_SET);    
    if (retour == -1) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
    
    //lire la largeur
    retour = fread(&largeur,sizeof (largeur),1,fic);
    if (retour != 1) 
    {
            printf("%s\n", strerror(errno));
            exit(errno);
    }
    //afficher la largeur
    printf("largeur : %u\n",largeur);
        
    //lire la hauteur
    retour = fread(&hauteur,sizeof (hauteur),1,fic);
    if (retour != 1) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    //afficher la hauteur
    printf("hauteur : %u\n",hauteur);
    
    // on se positionne au 42e octet (20 octets après la position actuelle)(couleur) 
    retour = fseek(fic,20,SEEK_CUR);    
    if (retour == -1) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
    
    //lire la couleur
    retour = fread(&couleur,sizeof (couleur),1,fic);
    if (retour != 1) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    //afficher la couleur
    printf("%u couleurs\n",couleur);
    
    //fermer le fichier
    retour=fclose(fic);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    return (EXIT_SUCCESS);
}

