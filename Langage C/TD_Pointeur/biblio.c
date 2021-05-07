/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "bilbio.h"
char *moisNom(int nbMois)
{
    char *nomDuMois;
    char mois[12][15]={"janvier","fevrier","mars","avril","mai","juin","juillet","aout","septembre","octobre","novembre","decembre"};    
    
    if (nbMois>=1 && nbMois<=12)
    {
        nomDuMois=(char*)malloc((strlen(mois[nbMois-1])+1) * sizeof(char));     
        strcpy(nomDuMois,mois[nbMois-1]);
    }
    else
    {
        nomDuMois=(char*)malloc((strlen("mois inconnu")+1) * sizeof(char));     
        strcpy(nomDuMois,"mois inconnu");
    }
    return nomDuMois;
}
char *supprimerE(char* chaine)
{
    char *chaineSansE;
    char buffer[255];
    int i,j;
    j=0;
    
    for (i=0;i<strlen(chaine);i++)
    {
        if (chaine[i]!='e')
        {
            buffer[j]=chaine[i];
            j++;
        }
    }
    buffer[j]='\0';
    
    chaineSansE=(char *)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(chaineSansE,buffer);
    
    return chaineSansE;
}
char *saisirChaine(char *message)
{
    char *chaine1;
    char buffer[50];
    
    printf("%s",message);
    scanf("%s",buffer);
    
    chaine1=(char*)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(chaine1,buffer);       
    
    return chaine1;
}