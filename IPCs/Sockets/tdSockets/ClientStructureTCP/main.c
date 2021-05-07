/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 8 septembre 2020, 10:53
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

typedef struct{
	unsigned char jour;
	unsigned char mois;
	unsigned short int annee;
	char jourDeLaSemaine[10];	// le jour en toute lettre
}datePerso;

/*
 * 
 */ 

int main(int argc, char** argv) 
{

    int socCommServ;    // socket communication serveur
    struct sockaddr_in infosServeur;
    datePerso donneeAEnvoyer;
    datePerso donneeRecue;
    int retour;
    socklen_t taille;
    
    //creation de la socket en mode connecté
    socCommServ=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socCommServ==-1)
    {
        printf("pb creation socket : %s \n",strerror(errno));
        exit(errno);
    }
    
    //initialisation de la structure contenant les infos du serveur
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(7777); // port dans l'order "network"
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.73"); //adresse dans l'order "network"
    //connexion au serveur    
    retour = connect(socCommServ, (struct sockaddr *)&infosServeur, sizeof(infosServeur));
    if (retour==-1)
    {
        printf("pb connect : %s \n",strerror(errno));
        exit(errno);
    }
    //envoyer la donnee au serveur
    //envoyer la donnee au serveur
    donneeAEnvoyer.annee = 2001;
    donneeAEnvoyer.jour = 18;
    strcpy(donneeAEnvoyer.jourDeLaSemaine,"lundi");
    donneeAEnvoyer.mois = 6;
    retour = write(socCommServ, &donneeAEnvoyer, sizeof(donneeAEnvoyer));
    if (retour==-1)
    {
        printf("pb write : %s \n",strerror(errno));
        exit(errno);
    }
    
/*  !PAS DE RETOUR DU SERVEUR!
 * 
 * 
    //reception de la donnée du serveur
    retour = read(socCommServ, &donneeRecue, sizeof(donneeRecue));
    if (retour==-1)
    {
        printf("pb read : %s \n",strerror(errno));
        exit(errno);
    }
    printf("valeur provenant du serveur : %d\n",donneeRecue);
    
*/
    return (EXIT_SUCCESS);
}

