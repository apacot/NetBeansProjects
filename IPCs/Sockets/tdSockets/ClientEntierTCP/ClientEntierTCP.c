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

/*
 * 
 */
int main(int argc, char** argv) 
{

    int socCommServ;    // socket communication serveur
    struct sockaddr_in infosServeur;
    int donneeAEnvoyer;
    int donneeRecue;
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
    infosServeur.sin_port = htons(5555); // port dans l'order "network"
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.73"); //adresse dans l'order "network"
    //connexion au serveur    
    retour = connect(socCommServ, (struct sockaddr *)&infosServeur, sizeof(infosServeur));
    if (retour==-1)
    {
        printf("pb connect : %s \n",strerror(errno));
        exit(errno);
    }
    //envoyer la donnee au serveur
    donneeAEnvoyer = 715705;
    retour = write(socCommServ, &donneeAEnvoyer, sizeof(donneeAEnvoyer));
    if (retour==-1)
    {
        printf("pb write : %s \n",strerror(errno));
        exit(errno);
    }
    //reception de la donnée du serveur
    retour = read(socCommServ, &donneeRecue, sizeof(donneeRecue));
    if (retour==-1)
    {
        printf("pb read : %s \n",strerror(errno));
        exit(errno);
    }
    printf("valeur provenant du serveur : %d\n",donneeRecue);
    
    close(socCommServ);
    
    return (EXIT_SUCCESS);
    
    
}

