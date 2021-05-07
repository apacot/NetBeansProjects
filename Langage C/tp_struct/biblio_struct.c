#include "biblio_struct.h"

void afficherMenu(int nbAdherent)
{      
        printf("A : Ajouter une fiche adhérent\n");
    
        if (nbAdherent != 0)
        {
            printf("S : Supprimer une fiche\n");
            printf("M : Modifier une fiche\n");
            printf("V : Voir le contenu d'une fiche\n");
            printf("L : Voir le contenu de l'ensemble des fiches\n");
            printf("E : Supprimer toutes les fiches\n");
        }
        printf("Q : Quitter\n");
}
void afficherDate(typeDate date)
{
    printf("%d/%d/%d",date.jour,date.mois,date.annee);
}
void afficherActivite(sports activite)
{
    char *tabSports[NBACTIVITESMAX] = {"natation", "basketball","handball","squash","tennis"};
    sports  choix=activite;
    printf("%s\n ", tabSports[choix]);
}
void afficherUnAdherent(typeAdherent *ad)
{
    int i;
    
    printf("nom : %s\n", ad->nom);
    printf("prénom : %s\n", ad->prenom);
    printf("date de naissance : ");
    afficherDate(ad->dateNaissance);
    printf("\nnombre d'activités : %u\n", ad->nbActivites);
    
    for(i=0 ; i<ad->nbActivites ; i++)
    {
        afficherActivite(ad->nbActivites-i);
    }
    
    printf("\nnuméro de carte : %u\n", ad->numCarte);
}
typeAdherent *creerUnAdherent()
{
    typeAdherent *ptr;
    int i;
    
    ptr=(typeAdherent*)malloc(sizeof(typeAdherent));
    printf("nom : ");
    scanf("%s",&ptr->nom);
    printf("prénom : ");
    scanf("%s",&ptr->prenom);
    printf("date de naissance (jj/mm/aaaa): ");
    scanf("%d/%d/%d",&ptr->dateNaissance.jour,&ptr->dateNaissance.mois,&ptr->dateNaissance.annee);
    
    printf("nombre d'activité : ");
    scanf("%d",&ptr->nbActivites);
    
    for(i=0 ; i<ptr->nbActivites ; i++)
    {
        printf("activités possibles : ");
        scanf("%u",&ptr->activites[i]);
    }
    
    printf("numéro de carte : ");
    scanf("%d",&ptr->numCarte);
    return ptr;
}
void afficherLesAdherents(typeAdherent *ad[],int nb)
{
    int i;
    for(i=0 ; i<nb ; i++)
    {
        afficherUnAdherent(ad[i]);
    }
}
int ajouterUnAdherent(typeAdherent *tab[], int nb)
{
    tab[nb]=creerUnAdherent();
    return nb+1;
}
int supprimerUnAdherent(typeAdherent *tab[],int nro,int nb)
{
    if(nro>=0 && nro<nb)
    {
        free(tab[nro]);
        tab[nro]=tab[nb-1];
        nb=nb-1;
    }    
    return nb;
}
int supprimerTousLesAdherents(typeAdherent *tab[],int nb){
    int i;
    for(i=0 ; i<nb ; i++)
    {
        free(tab[1]);
    }
    nb=0;
    return nb;
}