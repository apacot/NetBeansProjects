/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 3 novembre 2020, 11:22
 */

#define MAXBUFF 255

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) 
{
    //variables serveurTCP
    int socFileAttente;
    int socCommClient;
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosClient;
    int retour;
    int tailleClient;
    int donneeRecue;
    
    //variables récuperation de date et charge via popen
    FILE *chargeSystem;
    FILE *dateSystem;
    char *retourLecture;
    char buffer[MAXBUFF];
    memset(buffer,'\0',MAXBUFF);
         
    //creation de la socket serveur en mode datagram
    socFileAttente = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socFileAttente==-1)
    {
        printf("pb creation socket : %s \n",strerror(errno));
        exit(errno);
    }    
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(5555);
    infosServeur.sin_addr.s_addr = htonl(INADDR_ANY);
    
    //liaison socket avec la structure sockaddr
    retour = bind(socFileAttente,(struct sockaddr *) &infosServeur, sizeof(infosServeur));
    if(retour==-1)
    {
        printf("pb bind : %s \n", strerror(errno));
        exit(errno);
    }
    tailleClient = sizeof(infosClient);
    
    //mise en place d'une file d'attente de 10
    retour = listen(socFileAttente,10);
    if(retour==-1)
    {
        printf("pb listen : %s \n", strerror(errno));
        exit(errno);
    }
    
    //attente de connexion
    socCommClient = accept(socFileAttente, (struct sockaddr *)&infosClient,&tailleClient);
    if(socCommClient==-1)
    {
        printf("pb accept : %s \n", strerror(errno));
        exit(errno);
    }
    //recevoir la donnee en provenance du client
    retour=read(socCommClient, &donneeRecue, sizeof(donneeRecue));
    if(retour==-1)
    {
        printf("pb read : %s \n", strerror(errno));
        exit(errno);

    }
    
    //traitement de la donnee (si 0 alors recuperation de la date, si 1 alors recuparation de la charge
    if(donneeRecue == 1)
    {
        chargeSystem = popen("usr/bin/uptime","r"); //en mode lecture
        if(chargeSystem == NULL)
        {
            printf(" pb popen : %s\n",strerror(errno));
            exit(errno);
        }
    }
    else
    {
        if(donneeRecue == 0)
        {
            dateSystem = popen("bin/date","r"); //en mode lecture
            if(dateSystem == NULL)
            {
                printf(" pb popen : %s\n",strerror(errno));
                exit(errno);
            }
        }
    }
    
    
    return (EXIT_SUCCESS);
}

