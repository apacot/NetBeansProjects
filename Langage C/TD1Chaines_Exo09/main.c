/*
 * J'ai mal
 */

/*  char morseA[TAILLEMAX]={46 ,95};
    char morseB[TAILLEMAX]={95 ,46,46,46};
    char morseC[TAILLEMAX]={95 ,46,95,46};
    char morseD[TAILLEMAX]={95 ,46,46};
    char morseE[TAILLEMAX]={46};
    char morseF[TAILLEMAX]={46,46,95,46};
    char morseG[TAILLEMAX]={95,95,46};
    char morseH[TAILLEMAX]={46 ,46,46,46};
    char morseI[TAILLEMAX]={46 ,46};
    char morseJ[TAILLEMAX]={46 ,95,95,95};
    char morseK[TAILLEMAX]={95,46 ,95};
    char morseL[TAILLEMAX]={46 ,95,46,46};
    char morseM[TAILLEMAX]={95,95};
    char morseN[TAILLEMAX]={95,46};
    char morseO[TAILLEMAX]={95,95 ,95};
    char morseP[TAILLEMAX]={46 ,95,95,46};
    char morseQ[TAILLEMAX]={95,95,46 ,95};
    char morseR[TAILLEMAX]={46 ,95,46};
    char morseS[TAILLEMAX]={46,46,46};
    char morseT[TAILLEMAX]={95};
    char morseU[TAILLEMAX]={46,46,95};
    char morseV[TAILLEMAX]={46,46,46,95};
    char morseW[TAILLEMAX]={46,95,95};
    char morseX[TAILLEMAX]={46 ,95,95,46};
    char morseY[TAILLEMAX]={95,46 ,95,95};
    char morseZ[TAILLEMAX]={95,95,46,46};
    char morse1[TAILLEMAX]={46,95,95,95,95};
    char morse2[TAILLEMAX]={46 ,46,95,95,95};
    char morse3[TAILLEMAX]={46,46,46,95,95};
    char morse4[TAILLEMAX]={46 ,46,46,46,95};
    char morse5[TAILLEMAX]={46,46,46,46,46};
    char morse6[TAILLEMAX]={95,46,46,46,46};
    char morse7[TAILLEMAX]={95,95,46,46,46};
    char morse8[TAILLEMAX]={95,95,95,46,46};
    char morse9[TAILLEMAX]={95,95,95,95,95};
    char morse0[TAILLEMAX]={95,95,95,95,95};
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLEMAX 255

/*
 * 
 */
int main(int argc, char** argv) {
    char morse[36][7] = {".-", "-..", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".----", "-.-", ".-..", "--",
        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
        "....-", ".....", "-....", "--...", "---..", "----.", "------"};
    int i;
    char buffer[TAILLEMAX];

    printf("Saisir une phrase \n");
    fgets(buffer,sizeof(buffer), stdin);
    printf("La phrase en morse est : \n");

    for (i=0; i <strlen(buffer);i++){
        if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            printf("%s ",morse[buffer[i] - 'A']);
        else if(buffer[i]>= 'a' && buffer[i] <= 'z')
            printf("%s ",morse[buffer[i] - 'a']);
        else if (buffer[i]>= '0' && buffer[i] <= '9')
            printf("%s ",morse[buffer[i] - '0' +26]);
        else printf(" ");
    }
    printf("\n");

    return (EXIT_SUCCESS);
}

