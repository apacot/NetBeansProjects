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

    int soc;    // ma socket
    struct sockaddr_in infosServeur;
    datePerso donneeAEnvoyer;
    datePerso donneeRecue;
    int retour;
    socklen_t taille;
    
    //creation de la socket en mode datagram
    soc=socket(PF_INET, SOCK_DGRAM,0/*soit 0 soit IPPROTO_UDP*/);
    if (soc==-1)
    {
        printf("pb creation socket : %s \n",strerror(errno));
        exit(errno);
    }
    
    //initialisation de la structure contenant les infos du serveur
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(4444); // port dans l'order "network"
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.83"); //adresse dans l'order "network"
    //envoyer la donnee au serveur
    donneeAEnvoyer.annee = 2001;
    donneeAEnvoyer.jour = 18;
    strcpy(donneeAEnvoyer.jourDeLaSemaine,"lundi");
    donneeAEnvoyer.mois = 6;
    //printf("%f\n",donneeAEnvoyer); verifie la donnee a envoyer
    retour = sendto(soc, &donneeAEnvoyer, sizeof(donneeAEnvoyer),0, (struct sockaddr *)&infosServeur, sizeof(infosServeur));
    if(retour==-1)
    {
        //message d'erreur si ça marche pas
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);
    }
    
/*  !*Pas de retour de la part du serveur*!
 * 
 * 
    //recevoir la donnee en provenance du serveur
    retour=recvfrom(soc, &donneeRecue, sizeof(donneeRecue), 0, (struct sockaddr *)&infosServeur, &taille);
    if(retour==-1)
    {
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);

    }
    
    //afficher la donnee
    printf("Donne recue : %f \n", donneeRecue);
*/
    
    //fermer la socket
    close(soc);
    
    
    return (EXIT_SUCCESS);
}

