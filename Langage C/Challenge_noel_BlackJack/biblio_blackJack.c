

#include "biblio_blackJack.h"

int calculerScore(carte mainJ[], int nbCarte)
{
    int score=0;
    int i;
    
    for(i=0;i<nbCarte;i++)
    {
        score = score + mainJ[i].valeur; 
    }
    return score;
}
carte tirerCarte(carte Pioche[],int nbCartePioche)
{
    carte carteTiree;
    int carteAlea;
    int i;
    
    carteAlea=aleatoire(nbCartePioche);
    carteTiree = Pioche[carteAlea];
    
    for (i=carteAlea;i<NBCARTE-1;i++)
    {
        Pioche[i] = Pioche[i+1];
    }
    
    return carteTiree;
}
int demanderMise(int solde)
{
    int mise;
    
    do
    {
        printf("\nVotre mise : ");
        scanf("%d",&mise);
        if (mise>solde)
        {
            printf("Mise supérieure à votre solde restant");
        }
                
    }while (mise>solde);
}
// attendre un maxTime millisecondes
void msleep(unsigned int maxTime) 
{
    /*
    struct timespec {
    time_t tv_sec;        // secondes
    long   tv_nsec;       // nanosecondes
};
     */
    struct timespec req;
    struct timespec rem;
    time_t secondes = 0;
    long nanoSecondes = 0;
    if (maxTime >= 1000) {
        do {
            secondes++;
            maxTime -= 1000;
        } while (maxTime >= 1000);
    }
    nanoSecondes = maxTime * 1000000;
    req.tv_sec = secondes;
    req.tv_nsec = nanoSecondes;
    nanosleep(&req, &rem);

}

/**
 * 
 * @param maxAlea valeur max de l'aleatoire
 * @return retourne une valeur entiere E[0..maxAlea[
 */
unsigned int aleatoire(unsigned int maxAlea) 
{
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