/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 28 septembre 2020, 11:08
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int socCommClient; //socket de communication client
    struct sockaddr_in infosServeur; //variable de type struct sockaddr_in contenant les infos du serveur
    struct sockaddr_in infosClient; //variable de type struct sockaddr_in contenant les infos du client
    char *donneeServeur; //variable pour les données que le serveur envoi au client
    char donneeClient; //variable pour les données que le client envoi au serveur
    int retour; //variable de retour pour tester les différentes fonctions
    socklen_t tailleClient=sizeof(infosClient);
    //récupérer la date et l'heure du systeme
    time_t t;
    struct tm *laDate;

    //création de la socket en mode non-connecté(datagram) (PF_INET pour la familleIPPROTO_UDP ou 0, cela revient au même)
    socCommClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socCommClient == -1) // test de la fonction socket
    {
        printf("pb creation socket : %s \n", strerror(errno));
        exit(errno);
    }
    //Initialiser les infos du serveur
    infosServeur.sin_family = AF_INET; //famille d'adresses
    infosServeur.sin_port = htons(4444); //port dans l'order "network"
    infosServeur.sin_addr.s_addr = htonl(INADDR_ANY); //INADDR_ANY, pour écouter sur toutes les interfaces présentes

    //liaison socket avec la structure sockaddr
    retour = bind(socCommClient, (struct sockaddr *) &infosServeur, sizeof (infosServeur));
    if (retour == -1) //test de la fonction bind
    {
        printf("pb bind : %s \n", strerror(errno));
        exit(errno);

    }
    printf("Le serveur attend un caractère de la part du client sur le port 4444\n");
    //recevoir la donnee en provenance du client
    do {
        retour = recvfrom(socCommClient, &donneeClient, sizeof (donneeClient), 0, (struct sockaddr *) &infosClient, &tailleClient);
        if (retour == -1) //test de la fonction recvfrom
        {
            printf("pb recvfrom : %s \n", strerror(errno));
            exit(errno);
        }

        //affichage de la donnée reçue
        printf("message du client %s/%hu: %c\n", inet_ntoa(infosClient.sin_addr), infosClient.sin_port, donneeClient);
        switch (donneeClient) {
            case 'd': //si le client envoi le caractère 'd'
                t = time(NULL);
                laDate = localtime(&t);
                retour = sendto(socCommClient, laDate, sizeof (struct tm), 0, (struct sockaddr *) &infosClient, sizeof (infosClient));
                if (retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n", strerror(errno));
                    exit(errno);
                }
                break;
            case 'u': //si le client envoi le caractère 'u'
                donneeServeur = getenv("USER");
                retour = sendto(socCommClient, donneeServeur, strlen(donneeServeur), 0, (struct sockaddr *) &infosClient, sizeof (infosClient));
                if (retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n", strerror(errno));
                    exit(errno);
                }
                break;
            case 'j': //si le client envoi le caractère 'j'
                donneeServeur = getenv("CINNAMON_VERSION");
                retour = sendto(socCommClient, donneeServeur, sizeof (donneeServeur), 0, (struct sockaddr *) &infosClient, sizeof (infosClient));
                if (retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n", strerror(errno));
                    exit(errno);
                }
                break;
            case 'l': // si le client envoi le caractère 'l'
                donneeServeur = getenv("LANG");
                retour = sendto(socCommClient, donneeServeur, sizeof (donneeServeur), 0, (struct sockaddr *) &infosClient, sizeof (infosClient));
                if (retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n", strerror(errno));
                    exit(errno);
                }

                break;
        }
    } while (1 == 1);
    //fermer la socket
    close(socCommClient);
    return (EXIT_SUCCESS);
}

