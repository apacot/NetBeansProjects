/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 28 septembre 2020, 09:19
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
#include <time.h>

#define TAILLEMAX 255
/*
 * 
 */
int main(int argc, char** argv)
{
    int socCommServ; //socket de communication au serveur
    struct sockaddr_in infosServeur; //variable de type struct sockaddr_in contenant les infos du serveur
    struct tm heureServeur; // structure de type tm pour recevoir l'heure systeme du serveur
    char donneeAEnvoyer; //variable pour envoyer les données au serveur
    char donneeRecue[TAILLEMAX]; //variable pour recevoir les données du serveur
    int retour;     //variable de retour pour tester les différentes fonctions
    char adresseServeur[20]; //variable pour recevoir l'adresse que l'utilisateur va rentrer lors de l'utilisation du client
    int choix; //variable pour le choix de l'option au menu de l'utilisateur
    socklen_t taille;
    
    //création de la socket en mode non-connecté (PF_INET pour la familleIPPROTO_UDP ou 0, cela revient au même)
    socCommServ = socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP); 
    if(socCommServ == -1) // test de la fonction socket
    {
        printf("pb creation socket : %s \n",strerror(errno));
        exit(errno);
    }
    
    //Initialiser les infos du serveur sauf l'adresse qui est initialisé après l'avoir demandé à l'utilisateur
    infosServeur.sin_family = AF_INET; //famille d'adresse
    infosServeur.sin_port = htons(4444); // port dans l'order "network"
    
    //demande l'adresse du serveur à l'utilisateur et l'initialise dans les infos du serveur
    printf("Quelle est l'adresse du serveur ? ");
    gets(adresseServeur);
    infosServeur.sin_addr.s_addr = inet_addr(adresseServeur); //adresse dans l'order "network"
    do
    {
        //affichage du menu
        printf("1 - Date et heure du serveur\n"); //1er option
        printf("2 - Utilisateur ayant lancé le serveur\n"); //2e option
        printf("3 - Chemin de l'environnement JAVA sur le serveur\n"); //3e option
        printf("4 - Encodage des caractères sur le serveur\n");//4e option
        printf("5 - Quitter le programme\n");//5e option
        printf("votre choix : ");
        scanf("%d",&choix);
        //fonctionnement du menu
        switch(choix)
        {
            case 1: //si l'utilisateur choisi l'option 1
                donneeAEnvoyer = 'd'; //affectation de la donnée à envoyer au serveur
                //envoi de la donnée au serveur
                retour = sendto(socCommServ,&donneeAEnvoyer,sizeof(donneeAEnvoyer),0,(struct sockaddr *)&infosServeur,sizeof(infosServeur));
                if(retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n",strerror(errno));
                    exit(errno);
                }
                //réception de la donnée du serveur
                retour = recvfrom(socCommServ, &heureServeur, sizeof(heureServeur), 0, (struct sockaddr *)&infosServeur, &taille);
                if(retour == -1) //test de la fonction recvfrom
                {
                    printf("pb recvfrom : %s\n",strerror(errno));
                    exit(errno);
                }
                //affichage de la donnée (date et heure) (accès à chaque champs de struct tm heureServeur)
                printf("%d/%d/%d %d:%d:%d\n",heureServeur.tm_mday,heureServeur.tm_mon+1,heureServeur.tm_year+1900,heureServeur.tm_hour,heureServeur.tm_min,heureServeur.tm_sec);
            break;
            case 2: //si l'utilisateur choisi l'option 2
                donneeAEnvoyer = 'u'; //affectation de la donnée à envoyer au serveur
                //envoi de la donnée au serveur
                retour = sendto(socCommServ,&donneeAEnvoyer,sizeof(donneeAEnvoyer),0,(struct sockaddr *)&infosServeur,sizeof(infosServeur));
                if(retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n",strerror(errno));
                    exit(errno);
                }
                //réception de la donnée du serveur
                retour = recvfrom(socCommServ, donneeRecue, TAILLEMAX, 0, (struct sockaddr *)&infosServeur, &taille);
                if(retour == -1) //test de la fonction recvfrom
                {
                    printf("pb recvfrom : %s\n",strerror(errno));
                    exit(errno);
                }
                //affichage de la donnée (nom de l'utilisateur du serveur
                printf("Utilisateur : %s\n",donneeRecue);
                
            break;
            case 3: //si l'utilisateur choisi l'option 3
                donneeAEnvoyer = 'j'; //affectation de la donnée à envoyer au serveur
                //envoi de la donnée au serveur
                retour = sendto(socCommServ,&donneeAEnvoyer,sizeof(donneeAEnvoyer),0,(struct sockaddr *)&infosServeur,sizeof(infosServeur));
                if(retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n",strerror(errno));
                    exit(errno);
                }
                //réception de la donnée du serveur
                retour = recvfrom(socCommServ, donneeRecue, TAILLEMAX, 0, (struct sockaddr *)&infosServeur, &taille);
                if(retour == -1) //test de la fonction recvfrom
                {
                    printf("pb recvfrom : %s\n",strerror(errno));
                    exit(errno);
                }
                //affichage de la donnée (version du gestionnaire graphique)
                printf("Version du gestionnaire graphique : %s\n", donneeRecue);
            break;
            case 4: //si l'utilisateur choisi l'option 4
             donneeAEnvoyer = 'l'; //affectation de la donnée à envoyer au serveur
                //envoi de la donnée au serveur
                retour = sendto(socCommServ,&donneeAEnvoyer,sizeof(donneeAEnvoyer),0,(struct sockaddr *)&infosServeur,sizeof(infosServeur));
                if(retour == -1)//test de la fonction sendto
                {
                    printf("pb sendto : %s\n",strerror(errno));
                    exit(errno);
                }
                //réception de la donnée du serveur
                retour = recvfrom(socCommServ, donneeRecue, TAILLEMAX, 0, (struct sockaddr *)&infosServeur, &taille);
                if(retour == -1) //test de la fonction recvfrom
                {
                    printf("pb recvfrom : %s\n",strerror(errno));
                    exit(errno);
                }
                //affichage de la donnée (encodage de caractère)
                printf("Encodage des caractères : %s\n",donneeRecue);
            break;
        }
    }while(choix!=5);
    
    //fermer la socket
    close(socCommServ);
    return (EXIT_SUCCESS);
}

