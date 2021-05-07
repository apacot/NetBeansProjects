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
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
 * 
 */
int main(int argc, char** argv) 
{
    
    int fdSocket;    // ma socket
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosClient;
    int donneeInverse;
    int donneeRecue;
    int retour;
    socklen_t tailleClient;
    
    
    //creation de la socket serveur en mode datagram
    fdSocket=socket(PF_INET, SOCK_DGRAM,0/*soit 0 soit IPPROTO_UDP*/);
    if (fdSocket==-1)
    {
        printf("pb creation socket : %s \n",strerror(errno));
        exit(errno);
    }
    
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(2222);
    infosServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //liaison socket avec la structure sockaddr
    retour = bind(fdSocket,(struct sockaddr *) &infosServeur, sizeof(infosServeur));
    if(retour==-1)
    {
        printf("pb bind : %s \n", strerror(errno));
        exit(errno);

    }
   
    //recevoir la donnee en provenance du client
    retour=recvfrom(fdSocket, &donneeRecue, sizeof(donneeRecue), 0, (struct sockaddr *)&infosClient, &tailleClient);
    if(retour==-1)
    {
        printf("pb recvfrom : %s \n", strerror(errno));
        exit(errno);

    }
    
    //afficher la donnee
    printf("message du client %s : %d \n", inet_ntoa(infosClient.sin_addr), donneeRecue);
    
    //renvoi de la donnée inverse au client
    donneeInverse = donneeRecue * -1;
    retour = sendto(fdSocket, &donneeInverse, sizeof(donneeInverse), 0, (struct sockaddr *)&infosClient, sizeof(infosClient));
    if(retour==-1)
    {
        printf("pb sendto : %s \n", strerror(errno));
        exit(errno);
    }
    
    
    //fermer la socket
    close(fdSocket);
    
}

