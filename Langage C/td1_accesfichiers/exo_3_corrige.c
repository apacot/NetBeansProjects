/* 
 * File:   main.c
 * Author: dbernard
 *
 * Created on 9 janvier 2020, 10:42
 * Modified on 9 janvier 2020, 10:42
 * Description : Lire un fichier texte du debut à la fin, caractere par caractere et compter le nombre de minuscule
 * avec fread
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int exo_3_corrige(int argc, char** argv)
{
    FILE *fic;
    int retour;
    int compteurMinus;
    unsigned char carac;
    compteurMinus = 0;
    //ouverture du fichier en lecture
    fic = fopen("/home/USERS/ELEVES/SNIR2019/fichierTexte.txt", "r");
    if (fic == NULL)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    //lire le fichier du debut à la fin caractere par caractere   
    // boucle de lecture
    while (!feof(fic))
    {
        // lire caractere
        retour = fread(&carac, sizeof (carac), 1, fic);
        if (retour == 1) // la lecture est ok
        {
            // carac est-il une minuscule ?
            if (carac >= 'a' && carac <= 'z')
            {
                // augmenter le compteur de minuscules
                compteurMinus++;
            }
            printf("%c", carac);
        }
        else // erreur potentiel
        {
            if (!feof(fic)) // veritablement une erreur
            {
                printf("%s\n", strerror(errno));
                exit(errno);
            }
        }





    }
    //fermer le fichier
    retour = fclose(fic);
    if (retour == EOF)
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    // afficher le nombre de minuscules
    printf("Le fichier contient %d minuscules \n", compteurMinus);
    return (EXIT_SUCCESS);
}
