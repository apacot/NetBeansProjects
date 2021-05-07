#include <stdio.h>
#include <stdlib.h>
#include "biblioComprehension.h"

int main(int argc, char** argv) 
{

    int uneVal=33;
    int laValDeRetour;
    float abscisse;
    
    laValDeRetour=fonctionA();
    printf("uneVal : %d ret 1 : %d\n", uneVal,laValDeRetour);
    laValDeRetour=fonctionB();
    printf("uneVal : %d ret 2 : %d\n",uneVal,laValDeRetour);
    
    printf("donnez moi l'abscisse : ");
    scanf("%f",&abscisse);
    fonctionC(abscisse);
    
    laValDeRetour=fonctionD(0,0,13.5,-2.3);
    printf("norme du vecteur : %d\n",laValDeRetour);
    return 0;
    
    return (EXIT_SUCCESS);
}

