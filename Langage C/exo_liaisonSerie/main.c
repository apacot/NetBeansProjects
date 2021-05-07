/* 
 * File:   main.c
 * Author: apacot
 *
 * Created on 16 janvier 2020, 14:47
 */

#include "biblio_serie.h"

/*
 * 
 */

int main(int argc, char** argv) 
{
    int fd;
    printf("essai liaison série");
    char message[1000];
    int nb;
    
    fd = OuvrirPort("/dev/ttyS0");
    printf("fd = %d", fd);
    configurerPort(fd,9600);
    do
    {
        nb = recevoirMessage(fd,message, '\r');
        printf("%s\n", message);
        envoyerMessage(fd, message);
    }while (strncmp(message, "bye", 3));
    fermerPort(fd);
    
    return (EXIT_SUCCESS);
}

