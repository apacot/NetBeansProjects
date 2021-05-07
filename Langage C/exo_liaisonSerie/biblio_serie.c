#include "biblio_serie.h"

int OuvrirPort(const char* device)
{
    int retour=-1;
    
    // ouverture du fichier
    retour = open(device, O_RDWR | O_NOCTTY);
    if (retour == -1)
    {
        printf("pb ouverture : %s\n", strerror(errno));
        exit(errno);
    }
}
void configurerPort(int fd, int baud)
{
    struct termios term;
    speed_t vitesse;
    
    tcgetattr(fd, &term);
    switch (baud)
    {
        case 2400: vitesse = B2400; break;
        case 4800: vitesse = B4800; break;
        case 9600: vitesse = B9600; break;
        case 19200: vitesse = B19200; break;
        case 38400: vitesse = B38400; break;
        default:
            vitesse = B9600;    
    } 
    // écriture de la vitesse dans la structure
    cfsetispeed(&term, vitesse);
    // enregisrer la structure
    tcsetattr (fd,TCSANOW, &term);
}
int envoyerMessage(int fd, char* message)
{
    int longueur;
    int nb;
    
    longueur = strlen(message);    
    nb = write(fd,message,longueur);
    
    return nb;
}
int recevoirMessage(int fd, char* message, char fin)
{
    char carRecu;
    int nb=0;
    
    
    do 
    {
        read(fd, message,1);
        carRecu = *message;
        message++;
        nb++;
        
    }while (carRecu != fin);
    
    *message='\0';
    
    return nb;
}
void fermerPort(int fd)
{
    close(fd);
}