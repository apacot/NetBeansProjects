/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 16 janvier 2020, 10:42
 */

#include "fic_biblio.h"

/*
 * 
 */
int main(int argc, char** argv) 
{
    FILE *ficSource;
    FILE *ficDestination;
    int retour;
    typeCouleur palette[NBCOULEURS];
    typeEnTeteFichierBmp enTeteFichier;
    typeEnTeteImage enTeteImage;
    unsigned char octet;

  
    //ouverture du fichier source
    ficSource = fopen(argv[1],"r");
    if (ficSource == NULL) 
    {
        printf("src %s\n", strerror(errno));
        exit(errno);
    }
    //ouverture du fichier destination
    ficDestination = fopen(argv[2],"w+");
    if (ficSource == NULL) 
    {
        printf("dst %s\n", strerror(errno));
        exit(errno);
    }
    
    retour = fread(&enTeteFichier,sizeof(typeEnTeteFichierBmp),1,ficSource);
    if (retour != 1)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    retour = fread(&enTeteImage,sizeof(typeEnTeteImage),1,ficSource);
    if (retour != 1)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    retour = fread(palette,sizeof(typeCouleur),256,ficSource);
    if (retour != 256)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    rougirPalette(palette);
    
    retour = fwrite(&enTeteFichier,sizeof(typeEnTeteFichierBmp),1,ficDestination);
    if (retour != 1)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    retour = fwrite(&enTeteImage,sizeof(typeEnTeteImage),1,ficDestination);
    if (retour != 1)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    retour = fwrite(palette,sizeof(typeCouleur),256,ficDestination);
    if (retour != 256)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    while (!feof(ficSource))
    {
        retour = fread(&octet, sizeof (octet), 1, ficSource);
        if (retour == 1)
        {
            retour = fwrite(&octet , sizeof (octet), 1, ficDestination);
            if (retour != 1)
            {
                printf("%s\n", strerror(errno));
            exit(errno);
            }
        }
        else
        {
            if (!feof(ficSource))
            {
                printf("%s\n", strerror(errno));
                exit(errno);
            }
        }
    }
    
    //fermer le fichier
    retour=fclose(ficSource);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    retour=fclose(ficDestination);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    return (EXIT_SUCCESS);
}

