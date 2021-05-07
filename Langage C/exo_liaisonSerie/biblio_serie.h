/* 
 * File:   biblio_serie.h
 * Author: apacot
 *
 * Created on 16 janvier 2020, 14:49
 */

#ifndef BIBLIO_SERIE_H
#define BIBLIO_SERIE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <string.h>
#include <fcntl.h>
#include <sys/termios.h>
#include <unistd.h>

int OuvrirPort(const char* device);
void configurerPort(int fd, int baud);
int envoyerMessage(int fd, char* message);
int recevoirMessage(int fd, char* message, char fin);
void fermerPort(const int fd);

#endif /* BIBLIO_SERIE_H */

