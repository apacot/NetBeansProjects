#include "gestionPendu.h"

int afficherMenu() 
{
    int choix;

    do 
    {
        printf("1) Rejouer \n");
        printf("2) Quitter \n");
        scanf("%d", &choix);
    } while (choix != 1 && choix != 2);
    if (choix != 1)
    {
        choix = -1;
    }
    return choix;
}

void afficherPendu(int nroErreur) 
{
    /* A completer */
    

}

void afficherLettre(char *histo, int nbLettre) {
    int i;
    printf("\nLettres deja proposees : ");
    /* A completer */
    printf("\n");
}

int motEstTrouve(char *motATtrouver, char *motPropose) {
    return (strcmp(motATtrouver, motPropose));
}

int placerLettre(char *motATrouver, char *motCourant, char lettrePropose) {
    int flag = 1;
    int i;
    for (i = 0; i < strlen(motATrouver); i++) {
        /* A completer */
    }
    return flag;
}

int verifierLettrePropose(char *lettresProposees, int nbLettreProposee, char lettre) {
    int flag = 1;
    int i;
    for (i = 0; i < nbLettreProposee; i++) {
        if ((lettre == lettresProposees[i]) || (lettre < 'a' || lettre > 'z')) {
            flag = 0;
        }
    }
    return flag;

}

void msleep(unsigned int maxTime) {

    struct timespec req;
    struct timespec rem;
    time_t secondes = 0;
    long nanoSecondes = 0;
    if (maxTime >= 1000) {
        do {
            secondes++;
            maxTime -= 1000;
        }        while (maxTime >= 1000);
    }
    nanoSecondes = maxTime * 1000000;
    req.tv_sec = secondes;
    req.tv_nsec = nanoSecondes;
    nanosleep(&req, &rem);

}

unsigned int aleatoire(unsigned int maxAlea) {
    struct timeb t;
    float a, b;
    unsigned int nbmilli;
    ftime(&t);
    nbmilli = t.time * 1000 + t.millitm;
    srand(nbmilli);
    a = rand();
    b = (maxAlea * a) / RAND_MAX;
    msleep(250);
    return ( (unsigned int) b);


}

void initialiserMot(char *motCourant, int longueurMot) {
    int i;
    /* A completer */
    // ajout du \0 apres les - pour que le tableau soit une chaine de caractere
    motCourant[longueurMot] = '\0';
}
