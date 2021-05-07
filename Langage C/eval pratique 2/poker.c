/* 
 * File:   poker.c
 * Author: 
 *
 * Created on 28 novembre 2019, 08:53
 * Modified on 
 * Description : définition des fonctions pour le poker aux dés
 */
#include "poker.h"

void msleep(unsigned int maxTime)
{

    struct timespec req;
    struct timespec rem;
    time_t secondes = 0;
    long nanoSecondes = 0;
    if (maxTime >= 1000)
    {
        do
        {
            secondes++;
            maxTime -= 1000;
        }
        while (maxTime >= 1000);
    }
    nanoSecondes = maxTime * 1000000;
    req.tv_sec = secondes;
    req.tv_nsec = nanoSecondes;
    nanosleep(&req, &rem);

}

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



int calculerScore(int des[], int nbDes)
{
    unsigned int idem[NBFACES] = {0, 0, 0, 0, 0, 0};
    // compteurs de combinaison
    int paire = 0, brelan = 0, carre = 0, poker = 0;
    int score = 0;
    // faire le compte des faces identiques pour chaque valeur de face
    for (int i = 0; i < nbDes; i++)
    {
        idem[des[i]]++;
    }
    // pour chaque face de des, compter le nombre d'occurence
    for (int i = 0; i < NBFACES; i++)
    {
        if (idem[i] == 2)
        {
            paire++;

        }
        if (idem[i] == 3)
        {
            brelan++;

        }
        if (idem[i] == 4)
        {
            carre++;

        }
        if (idem[i] == 5)
        {
            poker++;

        }
    }
    // application de la pondération pour chaque combinaison pour avoir le score
    score = paire * 10 + brelan * 30 + carre * 60 + poker * 70;

    return score;

}
int testerAge(int age, int ageLimite)
{
    if (age<ageLimite)
    {
        age=-1;
    }
    else
    {
        age=0;
    }
    return age;
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
int lancerUnDes(int nbFace)
{
    nbFace=aleatoire(nbFace);
    return nbFace;
}
void afficherCombinaison(int des[], int nbDes)
{
    int i;
    for (i=0;i<NBDES;i++)
    {    
        printf("%d ",des[i]);                
    }
}
int demanderNumeroDeDes()
{
    int posDes=0;
    
    do
    {
        printf(" voulez vous changer un dé ? "
                "\nSi oui, lequel ? "
                "\nTaper 1 pour le 1er"
                "\nTaper 2 pour le 2e"
                "\nTaper 3 pour le 3e"
                "\nTaper 4 pour le 4e"
                "\nTaper 5 pour le 5e"
                "\nTaper -1 pour ne pas changer \n");
        scanf("%d",&posDes);
        
        switch(posDes)
        {
            case '1':                
                posDes=0;
                break;
            case '2':                
                posDes=1;
                break;
            case '3':                
                posDes=2; 
                break;
            case '4':                
                posDes=3;
                break;
            case '5':
                posDes=4;
                break;
        }
                
    }while (posDes < -1 && posDes > 4);    
       
    return (posDes);
}