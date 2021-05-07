#ifndef TREASUREQUEST_H_INCLUDED
#define TREASUREQUEST_H_INCLUDED
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define BLANC "\033[37m"
#define VERT "\033[32m"
#define JAUNE "\033[33m"
#define MAGENTA "\033[35m"
#define ROUGE "\033[31m"

#define FONDBLANC "\033[47m"
#define FONDNOIR "\033[40m"
#define FONDJAUNE "\033[43m"
#define FONDMAGENTA "\033[45m"
#define FONDROUGE "\033[41m"

#define LARGEUR 20
#define HAUTEUR 10

#define VIDE 0
#define MONSTRE 1
#define TRESOR 4
#define SORTIE 5
#define DEJAVISITE 6
#define PIEGE 20

#define POTION 120

#define NBMAXCARNOM 50
#define NBMAXCARPRENOM 50
#define EXPERIENCEPASSAGE 200
#define PVMAXINIT 500

#define RESBRETTEUR 20
#define RESPALADIN 15
#define RESBERSERK 5
#define RESASSASSIN 25
#define RESGUERRIER 10
#define RESSAMOURAI 15

#define BONUSDEFPALA 1.5
#define BONUSDEFSAM 1.5
#define BONUSDEFBER 0.5
#define BONUSDEFBRE 1.5
#define BONUSDEFGUE 1
#define BONUSDEFASS 3

#define BONUSATTPALA 1.5
#define BONUSATTSAM 1.5
#define BONUSATTBER 3
#define BONUSATTBRE 1.75
#define BONUSATTGUE 1
#define BONUSATTASS 0.5




typedef enum
{
    FALSE=0, TRUE
}booleen;



typedef enum
{
    BOUCLIER=-10, RIEN=0, DAGUE=5,WAKIZASHI=8,GLAIVE=10, XIPHOS=11, CLADIO=12, RAPIERE=13

} armesUneMain;

typedef enum
{
    NIL=0, BATARDE=25, KATANA=30, CLAYMORE=32,  FLAMBERGE=35
} armesDeuxMains;


typedef struct
{
    armesUneMain mainGauche;
    armesUneMain mainDroite;
    armesDeuxMains deuxMains;
} typeArmement;



void msleep(unsigned int maxTime);
void initMonde( char tab[LARGEUR][HAUTEUR], int nbMonstre, int nbPotion, int nbPiege );
unsigned int aleatoire(unsigned int maxAlea);
void initPiege( char tab[LARGEUR][HAUTEUR], int nbPiege );
void initMonstre( char tab[LARGEUR][HAUTEUR], int nbMonstre );
void initPotion( char tab[LARGEUR][HAUTEUR], int nbPotion );
void afficheMonde( char tab[LARGEUR][HAUTEUR] , int posX, int posY );
unsigned int getXTresor(char tab[LARGEUR][HAUTEUR]);
unsigned int getYTresor(char tab[LARGEUR][HAUTEUR]);
unsigned int getXSortie(char tab[LARGEUR][HAUTEUR]);
unsigned int getYSortie(char tab[LARGEUR][HAUTEUR]);
void afficheTresor();
void afficheMonstre();
void affichePotion();
void affichePiege();
void afficheSortie();
void affichePerdu();
float getDistance(unsigned int xt,unsigned int yt,unsigned int xp,unsigned int yp);

typedef enum {BRETTEUR=1,PALADIN,BERSERK,ASSASSIN,GUERRIER,SAMOURAI}competenceDeClasse;

typedef struct
{
    char nom[NBMAXCARNOM];
    char prenom[NBMAXCARPRENOM];
    unsigned int age;
    float taille;
    float poids;
    int resistancePhysique;
    int pv;
    unsigned int pvMax;
    unsigned int niveau;
    unsigned int experience;
    competenceDeClasse competence;
    typeArmement armes;
    
}typePersonnage;


int calculAttaque(typePersonnage *att);
int calculDefense(typePersonnage *def);
void mettreAJourNiveau(typePersonnage *perso, unsigned int exp);
unsigned int calculerGainExperience(typePersonnage *p1,typePersonnage *p2,booleen victoire,unsigned int tours);

void afficherClasse(competenceDeClasse c);
void afficherArmeUneMain(armesUneMain aum);

void afficherArmement(typeArmement arm);
armesUneMain choisirArmeUneMain();
armesDeuxMains choisirArmeDeuxMains();
unsigned int determinerResistance(competenceDeClasse classe);
typePersonnage* creerPersonnage();
typePersonnage* creerAdversaire(unsigned int niveau);

void faireUnDuel(typePersonnage *j1,typePersonnage *j2);

#endif // TREASUREQUEST_H_INCLUDED
