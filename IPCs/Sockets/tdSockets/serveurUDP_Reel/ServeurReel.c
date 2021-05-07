/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 14 septembre 2020, 10:25
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
//#include <unistd.h>

/*
 * 
 */
int main(int argc, char *argv[]) {
    int fdSocket;

    struct sockaddr_in adresseServeur;

    struct sockaddr_in adresseClient;
    int retour;
    int tailleClient;
    char buffer[255];
    float valRec;

    memset(buffer, '\0', 255);
    printf("serveur UDP sur port 3333 attend un REEL\n");
    fdSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (fdSocket == -1) {
        printf("pb socket : %s\n", strerror(errno));
        exit(0);
    }

    adresseServeur.sin_family = AF_INET;

    adresseServeur.sin_port = htons(3333); //numero de port du serveur dans l'ordre des octets du r�seau
    adresseServeur.sin_addr.s_addr = htonl(INADDR_ANY); // adresse IP du serveur dans l'ordre des octets du reseau

    retour = bind(fdSocket, (struct sockaddr*) &adresseServeur, sizeof (adresseServeur)); //attachement ip-port

    if (retour == -1) {
        printf("pb sendto : %s\n", strerror(errno));
        exit(0);
    }

    tailleClient = sizeof (adresseClient);
    while (1 == 1) {
        memset(buffer, '\0', 255);
        retour = recvfrom(fdSocket, &valRec, sizeof (valRec), 0, (struct sockaddr *) &adresseClient, &tailleClient);

        if (retour == -1) {
            printf("pb recvfrom : %s\n", strerror(errno));
            exit(0);
        }

        printf("message du client %s: %f\n", inet_ntoa(adresseClient.sin_addr), valRec);

        valRec = -valRec;
        retour = sendto(fdSocket, &valRec, sizeof (valRec), 0, (struct sockaddr *) &adresseClient, sizeof (adresseClient));

        if (retour == -1) {
            printf("pb sendto : %s\n", strerror(errno));
            exit(0);
        }
    }

    return EXIT_SUCCESS;
}

/*
int main(int argc, char** argv) 
{
    
    int soc;    // ma socket
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosClient;
    float donneeInverse;
    float donneeRecue;
    int retour;
    socklen_t taille;
    
    
    //creation de la socket serveur en mode datagram
    soc=socket(PF_INET, SOCK_DGRAM,0); //soit 0 soit IPPROTO_UDP
    if (soc==-1)
    {
        printf("pb creation socket : %s \n",strerror(errno));
        exit(errno);
    }
    
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(3333);
    infosServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //liaison socket avec la structure sockaddr
    retour = bind(soc,(struct sockaddr *) &infosServeur, sizeof(infosServeur));
    if(retour==-1)
    {
        printf("pb bind : %s \n", strerror(errno));
        exit(errno);

    }
    
    infosClient.sin_family = AF_INET;
    infosClient.sin_port = htons(0000);
    infosClient.sin_addr.s_addr = htonl(0);
    //recevoir la donnee en provenance du client
    retour=recvfrom(soc, &donneeRecue, sizeof(donneeRecue), 0, (struct sockaddr *)&infosClient, &taille);
    if(retour==-1)
    {
        printf("pb recvfrom : %s \n", strerror(errno));
        exit(errno);

    }
    
    //afficher la donnee
    printf("message du client %s : %f\n", inet_ntoa(infosClient.sin_addr), donneeRecue);
    
    //renvoi de la donnée inverse au client
    donneeInverse = donneeRecue * -1;
    retour = sendto(soc, &donneeInverse, sizeof(donneeInverse), 0, (struct sockaddr *)&infosClient, sizeof(infosClient));
    if(retour==-1)
    {
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);
    }
    
    //fermer la socket
    close(soc);
    
}
*/


