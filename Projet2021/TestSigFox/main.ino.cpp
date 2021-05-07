#include <sigfox.h>

Sigfox BallonSig(27, 26, true);

typedef unsigned char byte;

typedef struct {
    byte seconde;
    byte minute;
    byte heure;
} typeHeure;

typedef struct {
    byte jour;
    byte mois;
    unsigned int annee;
} typeDate;

typedef struct {
    float temperature;
    float humidite;
    float pression;
    float cpm;
} typeDonneesCapteurs;

typedef struct {
    float altitude;
    float latitude;
    float longitude;
} typePosition;

typedef struct {
    typePosition position;
    typeHeure heures;
    typeDate date;
    typeDonneesCapteurs DonneesCapteurs;
} typeDonnees;

typePosition donneesGPS;
typeDate laDate;
typeHeure lHeure;
typeDonneesCapteurs donneesCapteurs;

void setup() 
{
    Serial.begin(115200);
    BallonSig.begin();
    BallonSig.tester();
    
    //simulation de données
    //trame 1
    
    donneesGPS.altitude = 19900;
    donneesGPS.latitude = 47.995861;
    donneesGPS.longitude = 0.205248;
    
    laDate.annee = 2021;
    laDate.mois = 03;
    laDate.jour = 19;
    
    lHeure.heure = 14;
    lHeure.minute = 20;
    lHeure.seconde = 40;
    
    donneesCapteurs.cpm = 3950;
    donneesCapteurs.pression = 58;
    donneesCapteurs.temperature = 2;
    
    
    //trame 2
    /*
    donneesGPS.altitude = 17051;
    donneesGPS.latitude = 48.508944;
    donneesGPS.longitude = -2.762288;

    laDate.annee = 2021;
    laDate.mois = 04;
    laDate.jour = 02;

    lHeure.heure = 14;
    lHeure.minute = 20;
    lHeure.seconde = 40;

    donneesCapteurs.cpm = 856;
    donneesCapteurs.pression = 62;
    donneesCapteurs.temperature = -12;
    */
    
    //conversion des donnees    
    unsigned short int altitude = donneesGPS.altitude;
    unsigned int latitude = donneesGPS.latitude * 1000000.0;
    unsigned int longitude;
    unsigned short int radiationCpm = donneesCapteurs.cpm;
    unsigned short int pression = donneesCapteurs.pression;
    byte temperature = donneesCapteurs.temperature;
    byte octetCourant; //variable sur un octet (= 8bits)
    byte quartetGauche;
    byte quartetDroit;
    byte trame[12]; //tableau de 12 octets (de 0 à 11)
    int i = 11; //indice du tableau (on commence à la fin du tableau)
    
    //traitement temperature
    if (donneesCapteurs.temperature < 0) //si température négative
    {
        temperature = donneesCapteurs.temperature * (-1.0);
    }
    
    //traitement longitude
    if (donneesGPS.longitude < 0) //si longitude négative
    {
        longitude = donneesGPS.longitude * (-1000000.0);
    }
    else
    {
        longitude = donneesGPS.longitude * (1000000.0);
    } 

    
        
    //------------------------------------------------codage trame (en partant de la fin) ----------------------------------------------------

    //codage du 12e octet de la trame
    octetCourant = radiationCpm;
    trame[i] = octetCourant; //stockage du 12 octet dans le tableau d'octet
    i--; //i = i-1 (pour accéder à la case suivant (en partant de la fin))

    //codage du 11e octet
    quartetGauche = radiationCpm >> 8; //décalage de 8 vers la droite
    quartetDroit = pression << 4; // décalage de 4 vers la gauche
    octetCourant = quartetDroit | quartetGauche; //octetCourant = quartetDroit OU quartetGauche;
    trame[i] = octetCourant; // stockage du 11e octet (à la case i (=10))
    i--;

    //codage du 10e octet
    quartetDroit = pression >> 4;
    quartetGauche = temperature << 7;
    octetCourant = quartetDroit | quartetGauche;
    trame[i] = octetCourant;
    i--;

    //codage du 9e octet
    quartetDroit = temperature >> 1;
    quartetGauche = altitude << 6;
    octetCourant = quartetDroit | quartetGauche;

    if (donneesCapteurs.temperature < 0) // Si température négatif
    {
        octetCourant = octetCourant | 0x20; //bit de signe à 1
    } else {
        octetCourant = octetCourant & 0xDF; //bit de signe à 0
    }
    trame[i] = octetCourant;
    i--;

    //codage du 8e octet
    octetCourant = altitude >> 2;
    trame[i] = octetCourant;
    i--;

    //codage du 7e octet
    quartetDroit = altitude >> 10;
    quartetGauche = longitude << 5;
    octetCourant = quartetDroit | quartetGauche;
    trame[i] = octetCourant;
    i--;

    //codage du 6e octet
    octetCourant = longitude >> 3;
    trame[i] = octetCourant;
    i--;

    //codage du 5e octet
    octetCourant = longitude >> 11;
    trame[i] = octetCourant;
    i--;

    //codage du 4e octet
    
    quartetDroit = longitude >> 19;
    quartetGauche = latitude << 5;
    octetCourant = quartetDroit | quartetGauche;

    if (donneesGPS.longitude < 0) {
        octetCourant = octetCourant | 0x10; //bit de signe à 1
    } else {
        octetCourant = octetCourant & 0xEF; //bit de signe à 0
    }
    trame[i] = octetCourant;
    i--;

    //codage du 3e octet
    octetCourant = latitude >> 3;
    trame[i] = octetCourant;
    i--;

    //codage du 2e octet
    octetCourant = latitude >> 11;
    trame[i] = octetCourant;
    i--;

    //codage du 1e octet
    octetCourant = latitude >> 19;
    trame[i] = octetCourant;    
    
    //envoie de la trame
    BallonSig.envoyer(trame,sizeof(trame));
}

void loop() {

}