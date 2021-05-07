/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 9 janvier 2020, 10:40
 */

#include "accesfichiers.h"

/*
 * 
 */
int main(int argc, char** argv) {

    /* Exercice 1
     * 
        int retour;
        FILE *fic;
        //ouvrir fichier en mode creation/ecriture

        fic = fopen("/home/USERS/ELEVES/SNIR2019/apacot/Documents/INFO/Algo C/accès fichiers/essai.txt", "w+");

        if (fic == NULL) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }

        //ecrire "bonjour" dans le fichier
        retour = fputs("bonjour", fic);
        if (retour == EOF) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }

        //fermer le fichier
        retour = fclose(fic);
        if (retour == EOF) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
     */

    /*
        //Exercice 2 et 3
        int retour;    
        FILE *fic;
        int nbcar=0;  
        char car;
    
        //ouverture du fichier en lecture
        fic = fopen("/home/USERS/ELEVES/SNIR2019/fichierTexte.txt","r");
        if (fic == NULL) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
    
        //lire le fichier du début jusqu'à la fin caractère par caractère
        //lire 1er caractère    
        retour = fgetc(fic);
        if (retour == EOF) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
        car=(unsigned char)retour;
        printf("%c",car);
    
        //boucle de lecture
        while(!feof(fic))
        {
            car = fgetc(fic);
            if (car != EOF) 
            {
                printf("%c",car);
            }
            else
            {
                if(!feof(fic))
                {
                    printf("%s\n", strerror(errno));
                    exit(errno);
                }
            }
            if(car<='z' && car>='a')
            {
                nbcar++;
            }        
        }
        printf("%d", nbcar);
    
        //fermer le fichier
        retour=fclose(fic);
        if (retour == EOF) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
     */

    /*
        // Exercice 4 - 5 - 6 - 7 - 8
    
        int retour;    
        FILE *fic;
        FILE *fic2;
        int i;
        typePersonne tab[5];
    
        //ouverture du fichier en lecture
        fic = fopen("/home/USERS/ELEVES/SNIR2019/apacot/Documents/INFO/Algo C/accès fichiers/mesPersonnes.txt","w+");
        if (fic == NULL) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
        fic2 = fopen("/home/USERS/ELEVES/SNIR2019/apacot/Documents/INFO/Algo C/accès fichiers/mesPersonnesv2.txt","w+");
        if (fic2 == NULL) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
        
        // initialisation pour les 5 personnes
        for(i=0;i<NBPERSONNE;i++)
        {
            tab[i].age = 5*(i +1);
            tab[i].poids = 15 *(i +1);
            tab[i].sexe = 'm';
            strcpy(tab[i].nom, "bidochon");
            strcpy(tab[i].prenom, "robert");
        }
    
        // ecriture dans un fichier des 5 personnes
        for (i=0;i<NBPERSONNE;i++)
        {
            retour = fprintf(fic, "%s%s%d%.2f%c", tab[i].nom, tab[i].prenom,tab[i].age,tab[i].poids,tab[i].sexe);
        }
        if (retour < 0) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
    
        // ecriture des 5 personnes dans un fichier avec fwrite
        retour = fwrite(tab,sizeof(typePersonne),NBPERSONNE, fic2);
        if (retour != NBPERSONNE) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
    
        //fermer le fichier
        retour=fclose(fic);
        if (retour == EOF) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
        //fermer le fichier
        retour=fclose(fic2);
        if (retour == EOF) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
     */
    // Exercice 9

    int retour;
    FILE *fic;
    FILE *fic2;
    typePersonne tab[5];
    int i;

    //ouverture du fichier en lecture
    fic = fopen("/home/USERS/ELEVES/SNIR2019/mgirard/mespersonnes.txt", "r");
    if (fic == NULL) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    //ouverture du fichier en lecture
    fic2 = fopen("/home/USERS/ELEVES/SNIR2019/mgirard/mespersonnes2.txt", "r");
    if (fic2 == NULL) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    // lecture dans un fichier des 5 personnes
    for (i = 0; i < NBPERSONNE; i++) 
    {
        retour = fscanf(fic, "%s%s%d%f%c", tab[i].nom, tab[i].prenom, &tab[i].age, &tab[i].poids, &tab[i].sexe);
        if (retour == EOF) 
        {
            if (!feof(fic)) // veritablement une erreur
            {
                printf("%s\n", strerror(errno));
                exit(errno);
            }
            
        }
        printf("nom : %s\n prenom : %s \n age : %d\n poids : %.2f\n sexe : %c\n", tab[i].nom, tab[i].prenom, tab[i].age, tab[i].poids, tab[i].sexe);
        
    }
    // lecture des 5 personnes dans un fichier avec fread
        retour = fread(tab,sizeof(typePersonne),NBPERSONNE, fic2);
        if (retour != NBPERSONNE) 
        {
            printf("%s\n", strerror(errno));
            exit(errno);
        }
        for (i=0;i<NBPERSONNE;i++)
        {
            printf("nom : %s\n prenom : %s \n age : %d\n poids : %.2f\n sexe : %c\n", tab[i].nom, tab[i].prenom, tab[i].age, tab[i].poids, tab[i].sexe);
        }
    //fermer le fichier
    retour = fclose(fic);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    //fermer le fichier
    retour = fclose(fic2);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }

    return (EXIT_SUCCESS);
}

