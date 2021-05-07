#include "fic_biblio.h"

void afficheEnTeteFichierBmp(typeEnTeteFichierBmp enTete)
{
    printf("signature : %c%c\n",enTete.signature[0],enTete.signature[1]);
    printf("taille fichier : %u\n",enTete.tailleFichier);
    printf("octets réservés : %u\n",enTete.reserve);
    printf("adresse infos image : %u\n",enTete.adresse);
            
}
void afficheEnTeteImageBmp(typeEnTeteImage enTete)
{
    printf("taille en-tete : %u\n",enTete.tailleEnTete);
    printf("largeur : %u\n",enTete.largeur);
    printf("hauteur : %u\n",enTete.hauteur);
    printf("nombre de plan: %u\n",enTete.nbPlan);
    printf("bit par pixel : %u\n",enTete.bitParPixel);
    printf("type compression : %u\n",enTete.typeCompression);
    printf("taille image : %u\n",enTete.tailleImage);
    printf("resolution horizontale : %u\n",enTete.resolutionHorizontale);
    printf("resolution verticale : %u\n",enTete.resolutionVerticale);
    printf("nombre couleurs utilisées : %u\n",enTete.nbCouleursUtilisees);
    printf("nombre couleurs importante : %u\n",enTete.nbCouleursImportantes);
    
    
}
void rougirPalette(typeCouleur pal[])
{
    int i;
    for(i=0;i<NBCOULEURS;i++)
    {
        pal[i].g = 0;
        pal[i].b = 0;
        pal[i].a = 0;
    }
}
void verdirPalette(typeCouleur pal[])
{
    int i;
    for(i=0;i<NBCOULEURS;i++)
    {
        pal[i].r = 0;
        pal[i].b = 0;
        pal[i].a = 0;
    }
}
void bleuirPalette(typeCouleur pal[])
{
    int i;
    for(i=0;i<NBCOULEURS;i++)
    {
        pal[i].g = 0;
        pal[i].r = 0;
        pal[i].a = 0;
    }
}