/*
 *
 */

#include "biblio_struct.h"

typePersonne creePersonne()
{
    
    typePersonne unePersonne;
    
    printf("nom : ");
    scanf("%s", unePersonne.nom);
    printf("prenom : ");
    scanf("%s", unePersonne.prenom);
    printf("année : ");
    scanf("%u", &unePersonne.annee);
    printf("Taille : ");
    scanf("%f", &unePersonne.taille);
    printf("poids : ");
    scanf("%f", &unePersonne.poids);
    
    return unePersonne;
}
void affichePersonne(typePersonne personne)
{
    printf("Nom : %s\n", personne.nom);
    printf("Prenom : %s\n", personne.prenom);
    printf("Année : %u\n", personne.annee);
    printf("Taille : %.2fm\n", personne.taille);
    printf("Poids : %.2fkg\n", personne.poids);
}
typePersonne *creePersonnePtr()
{
    typePersonne *ptrPersonne;
    
    ptrPersonne=(typePersonne *)malloc(sizeof(typePersonne));
    
    printf("nom : ");
    scanf("%s", ptrPersonne->nom);
    printf("prenom : ");
    scanf("%s", ptrPersonne->prenom);
    printf("année : ");
    scanf("%u", &ptrPersonne->annee);
    printf("Taille : ");
    scanf("%f", &ptrPersonne->taille);
    printf("poids : ");
    scanf("%f", &ptrPersonne->poids);
    
    return ptrPersonne;
}
 void affichePersonnePtr(typePersonne *personne)
{
    printf("Nom : %s\n", personne->nom);
    printf("Prenom : %s\n", personne->prenom);
    printf("Année : %u\n", personne->annee);
    printf("Taille : %.2fm\n", personne->taille);
    printf("Poids : %.2fkg\n", personne->poids);
}
typeAdherent *nouvelAdherent(typeAdherent personne)
{
    typePersonne *personnePtr;
    
    printf("nom : ");
    scanf("%s", personnePtr->nom);
    printf("prenom : ");
    scanf("%s", personnePtr->prenom);
    printf("année : ");
    scanf("%u", &personnePtr->annee);
    printf("Taille : ");
    scanf("%f", &personnePtr->taille);    
}