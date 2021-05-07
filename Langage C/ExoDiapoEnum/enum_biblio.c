/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "enum_biblio.h"

boolean estUnPalindrome(char *chaine)
{
    int i;
    int longueur;
    
    boolean idem=TRUE;
    longueur=strlen(chaine);
    
    for (i=0;i<longueur/2;i++)
    {
        if (chaine[i]!=chaine[(longueur-1)-i])
        {
            idem=FALSE;
        }
    }
    return idem;
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

