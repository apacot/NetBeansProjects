#include "compression_biblio.h"

void decompressBmp(char *src, char *dst) 
{
    FILE *ficSource;
    FILE *ficDestination;
    typeEnTeteFichierBmp enTeteFic;
    typeEnTeteImageBmp enTeteImg;
    typeCouleur palette[NBCOULEURS];
    int retour;
    unsigned int tailleFicDest;
    unsigned int tailleImgDest;
    unsigned int typeCompression;
    unsigned char repetition;
    unsigned char valeurOctet;
    unsigned char octet;
    unsigned int nbOctet;

    //ouverture du fichier source
    ficSource = fopen(src, "r");
    if (ficSource == NULL) 
    {
        printf("src %s\n", strerror(errno));
        exit(errno);
    }

    //ouverture du fichier destination
    ficDestination = fopen(dst, "w+");
    if (ficDestination == NULL) 
    {
        printf("dst %s\n", strerror(errno));
        exit(errno);
    }

    //lecture des en-tete fichier, image et palette du fichier source
    retour = fread(&enTeteFic, sizeof (typeEnTeteFichierBmp), 1, ficSource);
    if (retour != 1) 
    {
        printf("src ef %s\n", strerror(errno));
        exit(errno);
    }
    retour = fread(&enTeteImg, sizeof (typeEnTeteImageBmp), 1, ficSource);
    if (retour != 1) 
    {
        printf("src ei %s\n", strerror(errno));
        exit(errno);
    }
    retour = fread(&palette, sizeof (typeCouleur), 256, ficSource);
    if (retour != 256) 
    {
        printf("src pal %s\n", strerror(errno));
        exit(errno);
    }

    //ecriture des en-tete fichier, image et palette dans fichier destination
    retour = fwrite(&enTeteFic, sizeof (typeEnTeteFichierBmp), 1, ficDestination);
    if (retour != 1) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    retour = fwrite(&enTeteImg, sizeof (typeEnTeteImageBmp), 1, ficDestination);
    if (retour != 1) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    retour = fwrite(palette, sizeof (typeCouleur), 256, ficDestination);
    if (retour != 256) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    do {
        retour = fread(&repetition, sizeof (repetition), 1, ficSource);
        if (retour != 1) 
        {
            if (!feof(ficSource)) 
            {
                printf("src repet %s\n", strerror(errno));
                exit(errno);
            }
        }
        retour = fread(&valeurOctet, sizeof (valeurOctet), 1, ficSource);
        if (retour != 1) 
        {
            printf("src val %s\n", strerror(errno));
            exit(errno);
        }
        for (nbOctet = 0; nbOctet < repetition; nbOctet++) 
        {
            retour = fwrite(&valeurOctet, sizeof (valeurOctet), 1, ficDestination);
            if (retour != 1) 
            {
                printf("dst val %s\n", strerror(errno));
                exit(errno);
            }
        }

    } while (repetition != 00 || valeurOctet != 01);

    //fermer fichier source
    retour = fclose(ficSource);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    //positionnement à la taille fichier
    retour = fseek(ficDestination, 2, SEEK_SET);
    if (retour == -1) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    tailleFicDest = sizeof (typeEnTeteFichierBmp) + sizeof (typeEnTeteImageBmp) + sizeof (typeCouleur)*256 + enTeteImg.largeur * enTeteImg.hauteur;
    //ecriture sur taille fichier
    retour = fwrite(&tailleFicDest, sizeof (tailleFicDest), 1, ficDestination);
    if (retour != 1) 
    {
        printf("dst modif taille %s\n", strerror(errno));
        exit(errno);
    }

    //positionnement au type de compression
    retour = fseek(ficDestination, 24, SEEK_CUR);
    if (retour == -1) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    // ecriture du type compression (non compressé)
    typeCompression = 0;
    retour = fwrite(&typeCompression, sizeof (typeCompression), 1, ficDestination);
    if (retour != 1) 
    {
        printf("dst modif type %s\n", strerror(errno));
        exit(errno);
    }
    
    //ecriture de la taille image
    tailleImgDest = enTeteImg.largeur * enTeteImg.hauteur;
    retour = fwrite(&tailleImgDest, sizeof (tailleImgDest), 1, ficDestination);
    if (retour != 1) 
    {
        printf("dst modif taille img %s\n", strerror(errno));
        exit(errno);
    }
    
    //fermeture du fichier de destination
    retour = fclose(ficDestination);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
}

void compressBmp(char *src, char *dst) 
{

}