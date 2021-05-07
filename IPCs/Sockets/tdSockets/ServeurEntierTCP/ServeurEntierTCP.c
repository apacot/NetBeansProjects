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
    
    int SocFileAttente;
    int SocCommClient;
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosClient;
    int retour;
    int tailleClient;
    int donneeRecue;
    int donneeInverse;
    
    //creation de la socket serveur en mode datagram
    SocFileAttente = socket(PF_INET, SOCK_STREAM , IPPROTO_TCP);
    if (SocFileAttente==-1)
    {
        printf("pb creation socket : %s \n",strerror(errno));
        exit(errno);
    }
    
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(5555);
    infosServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //liaison socket avec la structure sockaddr
    retour = bind(SocFileAttente,(struct sockaddr *) &infosServeur, sizeof(infosServeur));
    if(retour==-1)
    {
        printf("pb bind : %s \n", strerror(errno));
        exit(errno);
    }
    tailleClient = sizeof(infosClient);
    
    //mise en place d'une file d'attente de 10
    retour = listen(SocFileAttente,10);
    if(retour==-1)
    {
        printf("pb listen : %s \n", strerror(errno));
        exit(errno);
    }
    //attente de connexion
    SocCommClient = accept(SocFileAttente, (struct sockaddr *)&infosClient,&tailleClient);
    if(SocCommClient==-1)
    {
        printf("pb accept : %s \n", strerror(errno));
        exit(errno);
    }
   
    //recevoir la donnee en provenance du client
    retour=read(SocCommClient, &donneeRecue, sizeof(donneeRecue));
    if(retour==-1)
    {
        printf("pb read : %s \n", strerror(errno));
        exit(errno);

    }
    
    //afficher la donnee
    printf("message du client %s : %d \n", inet_ntoa(infosClient.sin_addr), donneeRecue);
    
    //renvoi de la donnée inverse au client
    donneeInverse = donneeRecue * -1;
    retour = write(SocCommClient, &donneeInverse, sizeof(donneeInverse));
    if(retour==-1)
    {
        printf("pb write : %s \n", strerror(errno));
        exit(errno);
    }
    
    
    //fermer la socket
    close(SocCommClient);
    close(SocFileAttente);
    
}
