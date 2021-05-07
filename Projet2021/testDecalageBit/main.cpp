/* 
 * File:   main.cpp
 * Author: apacot
 *
 * Created on 26 mars 2021, 15:05
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;
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

typePosition position;
typeDate date;
typeHeure heure;
typeDonneesCapteurs donneesCapteurs;

int main(int argc, char** argv) {
    //simulation de données

    position.altitude = 17051;
    position.latitude = 48.508944;
    position.longitude = -2.762288;

    date.annee = 2021;
    date.mois = 04;
    date.jour = 02;

    heure.heure = 14;
    heure.minute = 20;
    heure.seconde = 40;

    donneesCapteurs.cpm = 856;
    donneesCapteurs.pression = 62;
    donneesCapteurs.temperature = -12;

    //conversion des donnees    
    unsigned short int altitude = position.altitude;
    unsigned int latitude = position.latitude * 1000000.0;
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
    if (donneesCapteurs.temperature < 0) {
        temperature = donneesCapteurs.temperature * (-1.0);
    }
    
    //traitement longitude
    if (position.longitude < 0) {
        longitude = position.longitude * (-1000000.0);
    }
    else
    {
        longitude = position.longitude * (1000000.0);
    }
    
    //Affichage des données

    cout << "altitude : " << altitude << " metres" << endl;
    cout << "latitude : " << latitude << " °" << endl;
    cout << "longitude : " << longitude << " °" << endl;
    cout << "radiation : " << radiationCpm << " cpm" << endl;
    cout << "Pression : " << pression << " hPa" << endl;
    cout << "Temperature : " << temperature << " °C" << endl;

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

    if (position.longitude < 0) {
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
    
    

    return 0;
}

