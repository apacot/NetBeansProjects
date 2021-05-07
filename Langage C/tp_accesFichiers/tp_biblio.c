#include "tp_biblio.h"

void afficherMenu(int nbAdherent)
{      
        printf("A : Ajouter une fiche adhérent\n");
    
        if (nbAdherent > 0)
        {
            printf("S : Supprimer une fiche\n");
            printf("M : Modifier une fiche\n");
            printf("V : Voir le contenu d'une fiche\n");
            printf("L : Voir le contenu de l'ensemble des fiches\n");
            printf("E : Supprimer toutes les fiches\n");
            printf("F : Sauvegarder toutes les fiches\n");
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
    
    printf("\nnom : %s\n", ad->nom);
    printf("prénom : %s\n", ad->prenom);
    printf("date de naissance : ");
    afficherDate(ad->dateNaissance);
    printf("\nnombre d'activités : %u\n", ad->nbActivites);
    
    for(i=0 ; i<ad->nbActivites ; i++)
    {
        afficherActivite(ad->activites[i]);
    }
    
    printf("numéro de carte : %u\n", ad->numCarte);
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
    
    printf(" 0) Natation\n 1) Basketball\n 2) Handball\n 3) Squash\n 4) Tennis\n");
    for(i=0 ; i<ptr->nbActivites ; i++)
    {
        
        printf("Votre Activité :");
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
        sleep(1);
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
void sauvegarderAdherents (typeAdherent *tab[], int nbAdherent)
{
    FILE *ficSave;
    int retour;
    int i;
    
    //ouverture du fichier de sauvegarde
    ficSave = fopen("/home/USERS/ELEVES/SNIR2019/apacot/Documents/INFO/Algo C/accès fichiers/SaveAdherent.bin","w+");
    if (ficSave == NULL) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
    
    //sauvegarde de chacun des adherents
    for (i=0; i<nbAdherent; i++)
    {
        retour = fwrite(tab[i],sizeof (typeAdherent),1,ficSave);
        if (retour != 1)
        {
        printf("%s\n", strerror(errno));
        exit(errno);
        }
    }
    
    //fermer le fichier
    retour=fclose(ficSave);
    if (retour == EOF) 
    {
        printf("%s\n", strerror(errno));
        exit(errno);
    }
}
/* fonction charger un adhérent 
 * 
 * ouverture en lecture
 * 
 * tant que pas fin de fichier
 * 
 *   reserver l'espace memoire
 * 
 *  lire un adhérent
 * 
 *  ajouter l'adherént au tableau
 * 
 *  augmenter compteur adhérent
 
 * fin tant que
 * 
 * fermeture
 * 
 * retour nb adhérent
 
 */