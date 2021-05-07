#include "treasurequest.h"

// attendre un maxTime millisecondes

void msleep(unsigned int maxTime) {
    /*
    struct timespec {
    time_t tv_sec;        // secondes
    long   tv_nsec;       // nanosecondes
    };
     */
    struct timespec req;
    struct timespec rem;
    time_t secondes = 0;
    long nanoSecondes = 0;
    if (maxTime >= 1000) {
        do {
            secondes++;
            maxTime -= 1000;
        }        while (maxTime >= 1000);
    }
    nanoSecondes = maxTime * 1000000;
    req.tv_sec = secondes;
    req.tv_nsec = nanoSecondes;
    nanosleep(&req, &rem);

}

void initPiege(char tab[LARGEUR][HAUTEUR], int nbPiege) {

    int x, y, i;

    for (i = 0; i < nbPiege; i++) {
        do {
            x = aleatoire(LARGEUR);
            y = aleatoire(HAUTEUR);
        }        while (tab[x][y] != 0);

        tab[x][y] = PIEGE;
    }
}

void initMonstre(char tab[LARGEUR][HAUTEUR], int nbMonstre) {
    int x, y, i;

    for (i = 0; i < nbMonstre; i++) {
        do {
            x = aleatoire(LARGEUR);
            y = aleatoire(HAUTEUR);
        }        while (tab[x][y] != 0);

        tab[x][y] = MONSTRE;
    }
}

void initPotion(char tab[LARGEUR][HAUTEUR], int nbPotion) {
    int x, y, i;

    for (i = 0; i < nbPotion; i++) {
        do {
            x = aleatoire(LARGEUR);
            y = aleatoire(HAUTEUR);
        }        while (tab[x][y] != 0);

        tab[x][y] = POTION;
    }
}

void initSortie(char tab[LARGEUR][HAUTEUR]) {
    int x, y;
    //placer sortie
    do {
        x = aleatoire(LARGEUR);
        y = aleatoire(HAUTEUR);
    }    while (tab[x][y] != 0);

    tab[x][y] = SORTIE;
}

void initMonde(char tab[LARGEUR][HAUTEUR], int nbMonstre, int nbPotion, int nbPiege) {
    int x, y;
    printf("veuillez patientez, creation du monde...\n");

    for (x = 0; x < LARGEUR; x++) {
        for (y = 0; y < HAUTEUR; y++) {
            tab[x][y] = VIDE;
        }
    }

    // placer tresor
    x = aleatoire(LARGEUR);

    y = aleatoire(HAUTEUR);

    tab[x][y] = TRESOR;



    initPotion(tab, nbPotion);

    initMonstre(tab, nbMonstre);

    initPiege(tab, nbPiege);

    initSortie(tab);

}

void afficheMonde(char tab[LARGEUR][HAUTEUR], int posX, int posY) {
    int x, y, cadre;
    // afficher haut du cadre
    for (x = 0; x < LARGEUR + 2; x++) {
        printf("_");

    }
    printf("\n");

    //afficher les bords du cadre et l'aire de jeu
    for (y = HAUTEUR - 1; y >= 0; y--) {
        // bord gauche
        printf("|");
        // aire de jeu
        for (x = 0; x < LARGEUR; x++) {
            // afficher un . pour representer l'aire  de jeu
            if ((x != posX) || (y != posY)) {
                /*
                a completer
                 */
                if (tab[x][y] != DEJAVISITE) {
                    printf(".");
                }

            }
            // afficher une X si x,y sont la position du joueur
            if ((x == posX) && (y == posY)) {
                printf("X");
            }
        }
        // bord droit
        printf("|");

        printf("\n");
    }
    // afficher bas du cadre
    for (x = 0; x < LARGEUR + 2; x++) {
        printf("-");

    }
    printf("\n");

    // afficher les coordonnees du joueur
    printf("pos(%d,%d) ", posX, posY);

}


//retourne une valeur entiere E[0..maxAlea[

unsigned int aleatoire(unsigned int maxAlea) {
    /*	struct timeb {
        time_t         time;
        unsigned short millitm;
        short          timezone;
        short          dstflag;
    };*/

    struct timeb t;
    //long t;
    float a, b;
    unsigned int nbmilli;
    ftime(&t);
    nbmilli = t.time * 1000 + t.millitm;
    srand(nbmilli);
    a = rand();
    b = (maxAlea * a) / RAND_MAX;
    //printf( "in alea %i\n", nbmilli );
    msleep(100);
    return ( (unsigned int) b);


}

unsigned int getXTresor(char tab[LARGEUR][HAUTEUR]) {
    int x = 0, y;
    int retour = -1;

    do {
        y = 0;

        do {
            if ((tab[x][y]) == TRESOR)
                retour = x;

            y++;
        }        while (y < HAUTEUR && retour == -1);

        x++;
    }    while (x < LARGEUR && retour == -1);

    return retour;

}

unsigned int getYTresor(char tab[LARGEUR][HAUTEUR]) {
    int x, y = 0;
    int retour = -1;

    do {
        x = 0;

        do {
            if ((tab[x][y]) == TRESOR)
                retour = y;

            x++;
        }        while (x < LARGEUR && retour == -1);

        y++;
    }    while (y < HAUTEUR && retour == -1);

    return retour;
}

unsigned int getXSortie(char tab[LARGEUR][HAUTEUR]) {
    int x = 0, y;
    int retour = -1;

    do {
        y = 0;

        do {
            if ((tab[x][y]) == SORTIE)
                retour = x;

            y++;
        }        while (y < HAUTEUR && retour == -1);

        x++;
    }    while (x < LARGEUR && retour == -1);

    return retour;

}

unsigned int getYSortie(char tab[LARGEUR][HAUTEUR]) {
    int x, y = 0;
    int retour = -1;

    do {
        x = 0;

        do {
            if ((tab[x][y]) == SORTIE)
                retour = y;

            x++;
        }        while (x < LARGEUR && retour == -1);

        y++;
    }    while (y < HAUTEUR && retour == -1);

    return retour;
}

float getDistance(unsigned int xt, unsigned int yt, unsigned int xp, unsigned int yp) {
    int xVecteur = xt - xp;
    int yVecteur = yt - yp;
    double module;
    module = sqrt((xVecteur * xVecteur + yVecteur * yVecteur));
    return (float) module;
}

void afficheTresor() {

    printf(" _______ _____  ______  _____  ____  _____  \n|__   __|  __ \\|  ____|/ ____|/ __ \\|  __ \\ \n   | |  | |__) | |__  | (___ | |  | | |__) |\n   | |  |  _  /|  __|  \\___ \\| |  | |  _  / \n   | |  | | \\ \\| |____ ____) | |__| | | \\ \\ \n   |_|  |_|  \\_\\______|_____/ \\____/|_|  \\_\\\n");

}

void afficheMonstre() {
    printf(" _    _         __  __                 _            _ _ _ \n| |  | |       |  \\/  |               | |          | | | |\n| |  | |_ __   | \\  / | ___  _ __  ___| |_ _ __ ___| | | |\n| |  | | '_ \\  | |\\/| |/ _ \\| '_ \\/ __| __| '__/ _ \\ | | |\n| |__| | | | | | |  | | (_) | | | \\__ \\ |_| | |  __/_|_|_|\n \\____/|_| |_| |_|  |_|\\___/|_| |_|___/\\__|_|  \\___(_|_|_)\n");
}

void affichePotion() {
    printf(" _____      _   _                   _                  _       \n|  __ \\    | | (_)                 | |                (_)      \n| |__) |__ | |_ _  ___  _ __     __| | ___   ___  ___  _ _ __  \n|  ___/ _ \\| __| |/ _ \\| '_ \\   / _` |/ _ \\ / __|/ _ \\| | '_ \\ \n| |  | (_) | |_| | (_) | | | | | (_| |  __/ \\__ \\ (_) | | | | |\n|_|   \\___/ \\__|_|\\___/|_| |_|  \\__,_|\\___| |___/\\___/|_|_| |_|\n    ");
}

void affichePiege() {
    printf("                                               _                 \n                                              (_)                \n  ___  _   _ _ __  ___     _   _ _ __    _ __  _  ___  __ _  ___ \n / _ \\| | | | '_ \\/ __|   | | | | '_ \\  | '_ \\| |/ _ \\/ _` |/ _ \\\n| (_) | |_| | |_) \\__ \\_  | |_| | | | | | |_) | |  __/ (_| |  __/\n \\___/ \\__,_| .__/|___( )  \\__,_|_| |_| | .__/|_|\\___|\\__, |\\___|\n            | |       |/                | |            __/ |     \n            |_|                         |_|           |___/      \n");
}

void afficheSortie() {
    printf(" ________   _______ _______ \n|  ____\\ \\ / /_   _|__   __|\n| |__   \\ V /  | |    | |   \n|  __|   > <   | |    | |   \n| |____ / . \\ _| |_   | |   \n|______/_/ \\_\\_____|  |_|   \n    ");
}

void affichePerdu() {
    printf("                (\\  _  /)\n                ( \\ O / )\n                 (// \\\\)\n                    X\n                   / \\\n                  /___\\\n           _____/      \\\\_____\n          |                  ||\n          |                  ||\n          |                  ||\n          |  _     ___   _   ||\n          | | \\     |   | \\  ||\n          | |  |    |   |  | ||\n          | |_/     |   |_/  ||\n          | | \\     |   |    ||\n          | |  \\    |   |    ||\n          | |   \\. _|_. | .  ||\n          |                  ||\n  *     * | *   **    * **   |**      **\n    ");

}

int calculAttaque(typePersonnage *att) {
    double bonus;
    double attaque;
    switch (att->competence) {
        case PALADIN:
            bonus = BONUSATTPALA;
            break;
        case SAMOURAI:
            bonus = BONUSATTSAM;
            break;
        case BERSERK:
            bonus = BONUSATTBER;
            break;
        case BRETTEUR:
            bonus = BONUSATTBRE;
            break;
        case GUERRIER:
            bonus = BONUSATTGUE;
            break;
        case ASSASSIN:
            bonus = BONUSATTASS;
            break;
    }

    attaque = att->niveau * ((att->poids * att->taille) / (double) att->age) * bonus;
    // je personnage possede une arme a 2 mains
    if (att->armes.deuxMains != NIL) {
        attaque = attaque + att->armes.deuxMains;
    } else // le personnage ne possede pas d'arme a 2 mains
    {
        // le perso n'a pas de bouclier
        if (att->armes.mainDroite != BOUCLIER && att->armes.mainGauche != BOUCLIER) {
            attaque = attaque + att->armes.mainDroite + att->armes.mainGauche;
        } else // un bouclier dans l'une des mains
        {
            attaque = attaque + att->armes.mainDroite + att->armes.mainGauche - BOUCLIER + 2;
        }
    }
    attaque = attaque * (0.5 + aleatoire(10) / 10.0);
    return (int) attaque;
}

int calculDefense(typePersonnage *def) {
    double bonus;
    double defense;
    switch (def->competence) {
        case PALADIN:
            bonus = BONUSDEFPALA;
            break;
        case SAMOURAI:
            bonus = BONUSDEFSAM;
            break;
        case BERSERK:
            bonus = BONUSDEFBER;
            break;
        case BRETTEUR:
            bonus = BONUSDEFBRE;
            break;
        case GUERRIER:
            bonus = BONUSDEFGUE;
            break;
        case ASSASSIN:
            bonus = BONUSDEFASS;
            break;
    }

    defense = def->niveau * ((def->poids * def->taille) / (double) def->age) * bonus;
    // je personnage possede une arme a 2 mains
    if (def->armes.deuxMains != NIL) {
        defense = defense - (def->armes.deuxMains) / 2;
    } else // le personnage ne possede pas d'arme a 2 mains
    {
        // le perso n'a pas de bouclier
        if (def->armes.mainDroite != BOUCLIER && def->armes.mainGauche != BOUCLIER) {
            defense = defense - (def->armes.mainDroite + def->armes.mainGauche) / 3;
        } else // un bouclier dans l'une des mains
        {
            defense = defense - BOUCLIER;
        }
    }
    defense = defense * (0.5 + aleatoire(10) / 10.0);
    return (int) defense;

}



void mettreAJourNiveau(typePersonnage *perso, unsigned int exp) {
    perso->experience += exp;
    if (perso->experience >= EXPERIENCEPASSAGE) {
        perso->niveau++;
        perso->experience -= EXPERIENCEPASSAGE;
        perso->pvMax += PVMAXINIT / perso->niveau;
        perso->pv = perso->pvMax;
        switch (perso->competence) {
            case PALADIN:
                perso->resistancePhysique += RESPALADIN;
                break;
            case SAMOURAI:
                perso->resistancePhysique += RESSAMOURAI;
                break;
            case BERSERK:
                perso->resistancePhysique += RESBERSERK;
                break;
            case BRETTEUR:
                perso->resistancePhysique += RESBRETTEUR;
                break;
            case GUERRIER:
                perso->resistancePhysique += RESGUERRIER;
                break;
            case ASSASSIN:
                perso->resistancePhysique += RESASSASSIN;
                break;
        }
    }

}

unsigned int calculerGainExperience(typePersonnage *p1, typePersonnage *p2, booleen victoire, unsigned int tours) {
    unsigned int exp = 0;
    if (victoire) {
        exp = 2 * (p2->niveau - p1->niveau + 1) * tours;

    } else {
        exp = (p2->niveau - p1->niveau + 1) * tours;

    }
    return exp;

}

void afficherClasse(competenceDeClasse c) {
    switch (c) {
        case PALADIN:
            printf("Paladin \n");
            break;
        case SAMOURAI:
            printf("Samourai\n");
            break;
        case BERSERK:
            printf("Berserk\n");
            break;
        case BRETTEUR:
            printf("Bretteur\n");
            break;
        case GUERRIER:
            printf("Guerrier\n");
            break;
        case ASSASSIN:
            printf("Assassin\n");
            break;
    }
}

void afficherArmeUneMain(armesUneMain aum) {
    switch (aum) {
        case DAGUE:
            printf("Dague - degats : %d\n", DAGUE);
            break;
        case WAKIZASHI:
            printf("Wakizashi - degats : %d\n", WAKIZASHI);
            break;
        case GLAIVE:
            printf("Glaive - degats : %d\n", GLAIVE);
            break;
        case XIPHOS:
            printf("Xiphos - degats : %d\n", XIPHOS);
            break;
        case CLADIO:
            printf("Cladio - degats : %d\n", CLADIO);
            break;
        case RAPIERE:
            printf("Rapiere - degats : %d\n", RAPIERE);
            break;
        case BOUCLIER:
            printf("Bouclier - protection : %d\n", -BOUCLIER);
            break;
        case RIEN:
            printf("Vide - degats : 1\n");
            break;
    }
}



void afficherArmement(typeArmement arm) {
    // il possede une arme a 2 mains
    if (arm.deuxMains != NIL) {
        printf("2 mains : ");
        afficherArmeDeuxMains(arm.deuxMains);
    } else {
        printf("Main gauche : ");
        afficherArmeUneMain(arm.mainGauche);
        printf("Main droite : ");
        afficherArmeUneMain(arm.mainDroite);
    }
}



armesUneMain choisirArmeUneMain() {
    armesUneMain arme;
    int choix;
    do {
        printf("Choix de l'arme :\n");
        printf(" 1 :");
        afficherArmeUneMain(DAGUE);
        printf(" 2 :");
        afficherArmeUneMain(WAKIZASHI);
        printf(" 3 :");
        afficherArmeUneMain(GLAIVE);
        printf(" 4 :");
        afficherArmeUneMain(XIPHOS);
        printf(" 5 :");
        afficherArmeUneMain(CLADIO);
        printf(" 6 :");
        afficherArmeUneMain(RAPIERE);
        printf("\n votre choix : ");
        scanf("%d", &choix);
    }    while (choix < 1 || choix > 6);
    switch (choix) {
        case 1:
            arme = DAGUE;
            break;
        case 2:
            arme = WAKIZASHI;
            break;
        case 3:
            arme = GLAIVE;
            break;
        case 4:
            arme = XIPHOS;
            break;
        case 5:
            arme = CLADIO;
            break;
        case 6:
            arme = RAPIERE;
            break;
    }
    return arme;

}

armesDeuxMains choisirArmeDeuxMains() {
    armesDeuxMains arme;
    int choix;
    do {
        printf("Choix de l'arme : \n");
        printf(" 1 :");
        afficherArmeDeuxMains(BATARDE);
        printf(" 2 :");
        afficherArmeDeuxMains(KATANA);
        printf(" 3 :");
        afficherArmeDeuxMains(CLAYMORE);
        printf(" 4 :");
        afficherArmeDeuxMains(FLAMBERGE);
        printf("\n votre choix : ");
        scanf("%d", &choix);
    }    while (choix < 1 || choix > 4);
    switch (choix) {
        case 1:
            arme = BATARDE;
            break;
        case 2:
            arme = KATANA;
            break;
        case 3:
            arme = CLAYMORE;
            break;
        case 4:
            arme = FLAMBERGE;
            break;
    }
    return arme;

}

unsigned int determinerResistance(competenceDeClasse c) {
    unsigned int res;

    switch (c) {
        case PALADIN:
            res = RESPALADIN;
            break;
        case SAMOURAI:
            res = RESSAMOURAI;
            break;
        case BERSERK:
            res = RESBERSERK;
            break;
        case BRETTEUR:
            res = RESBRETTEUR;
            break;
        case GUERRIER:
            res = RESGUERRIER;
            break;
        case ASSASSIN:
            res = RESASSASSIN;
            break;
    }
    return res;
}

typePersonnage* creerPersonnage() {
    typePersonnage* p = malloc(sizeof (typePersonnage));
    int choix;
    char unOuDeux;
    do {
        printf("choix de la classe :\n");
        printf(" 1 - Bretteur\n");
        printf(" 2 - Paladin\n");
        printf(" 3 - Berserk\n");
        printf(" 4 - Assassin\n");
        printf(" 5 - Guerrier\n");
        printf(" 6 - Samourai\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
    }    while (choix < 1 || choix > 6);

    switch (choix) {
        case 1:
            p->competence = BRETTEUR;
            break;
        case 2:
            p->competence = PALADIN;
            break;
        case 3:
            p->competence = BERSERK;
            break;
        case 4:
            p->competence = ASSASSIN;
            break;
        case 5:
            p->competence = GUERRIER;
            break;
        case 6:
            p->competence = SAMOURAI;
            break;
    }
    printf("Nom :");
    scanf(" %s", p->nom);
    printf("Prenom :");
    scanf(" %s", p->prenom);
    printf("Age :");
    scanf("%d", &p->age);
    printf("Taille :");
    scanf("%f", &p->taille);
    printf("Poids :");
    scanf("%f", &p->poids);


    p->pv = PVMAXINIT;
    p->pvMax = PVMAXINIT;
    p->experience = 0;
    p->niveau = 2;

    p->resistancePhysique = determinerResistance(p->competence);
    // si berserk ne peut avoir qu'une arme a 2 mains
    if (p->competence == BERSERK) {

        p->armes.deuxMains = choisirArmeDeuxMains();
    } else // pas berserk
    {
        p->armes.deuxMains = NIL;
        if (p->competence == PALADIN || p->competence == SAMOURAI) {
            do {
                printf("Voulez vous utiliser une arme à deux mains(o/n)?");
                scanf(" %c", &unOuDeux);

            }            while (unOuDeux != 'o' && unOuDeux != 'n');
            if (unOuDeux == 'o') {
                p->armes.deuxMains = choisirArmeDeuxMains();

            } else {
                p->armes.mainDroite = choisirArmeUneMain();

                if (p->competence == PALADIN) // epee et bouclier
                {

                    p->armes.mainGauche = BOUCLIER;

                }
                if (p->competence == SAMOURAI) // epee et main libre
                {

                    p->armes.mainGauche = RIEN;

                }

            }
        }
        if (p->competence == ASSASSIN) {
            p->armes.mainDroite = choisirArmeUneMain();
            p->armes.mainGauche = RIEN;

        }
        if (p->competence == BRETTEUR) {
            do {
                printf("Voulez vous utiliser deux armes (o/n)?");
                scanf(" %c", &unOuDeux);

            }            while (unOuDeux != 'o' && unOuDeux != 'n');
            if (unOuDeux == 'o') {
                printf("Main droite : ");
                p->armes.mainDroite = choisirArmeUneMain();
                printf("Main gauche : ");
                p->armes.mainGauche = choisirArmeUneMain();
            } else {
                p->armes.mainDroite = choisirArmeUneMain();

                p->armes.mainGauche = RIEN;

            }

        }
        if (p->competence == GUERRIER) {
            do {
                printf("Voulez vous utiliser un bouclier(o/n)?");
                scanf(" %c", &unOuDeux);

            }            while (unOuDeux != 'o' && unOuDeux != 'n');
            if (unOuDeux == 'o') {
                printf("Main droite : ");
                p->armes.mainDroite = choisirArmeUneMain();

                p->armes.mainGauche = BOUCLIER;
            } else {
                p->armes.mainDroite = choisirArmeUneMain();

                p->armes.mainGauche = RIEN;

            }

        }

    }



    return p;
}

typePersonnage* creerAdversaire(unsigned int niveau) {
    typePersonnage* p = malloc(sizeof (typePersonnage));
    int choix;

    choix = 1 + aleatoire(5);

    switch (choix) {
        case 1:
            p->competence = BRETTEUR;
            break;
        case 2:
            p->competence = PALADIN;
            break;
        case 3:
            p->competence = BERSERK;
            break;
        case 4:
            p->competence = ASSASSIN;
            break;
        case 5:
            p->competence = GUERRIER;
            break;
        case 6:
            p->competence = SAMOURAI;
            break;
    }
    strcpy(p->nom, "do");

    strcpy(p->prenom, "john");

    p->age = 10 + aleatoire(60);
    p->taille = 1.0 + (aleatoire(200)) / 100.0;

    p->poids = aleatoire(200);


    p->pv = PVMAXINIT;
    p->pvMax = PVMAXINIT;
    p->experience = 0;
    p->niveau = niveau;

    p->resistancePhysique = determinerResistance(p->competence);
    // si berserk ne peut avoir qu'une arme a 2 mains
    if (p->competence == BERSERK) {

        p->armes.deuxMains = CLAYMORE;
    } else // pas berserk
    {
        p->armes.deuxMains = NIL;
        if (p->competence == PALADIN || p->competence == SAMOURAI) {

            p->armes.mainDroite = choisirArmeUneMain();

            if (p->competence == PALADIN) // epee et bouclier
            {

                p->armes.mainGauche = BOUCLIER;

            }
            if (p->competence == SAMOURAI) // epee et main libre
            {

                p->armes.mainGauche = RIEN;

            }
        }
        if (p->competence == ASSASSIN) {
            p->armes.mainDroite = DAGUE;
            p->armes.mainGauche = RIEN;

        }
        if (p->competence == BRETTEUR) {

            p->armes.mainDroite = RAPIERE;

            p->armes.mainGauche = GLAIVE;


        }
        if (p->competence == GUERRIER) {

            p->armes.mainDroite = GLAIVE;

            p->armes.mainGauche = BOUCLIER;
        }
    }

    return p;
}



void faireUnDuel(typePersonnage *j1, typePersonnage *j2) {
    booleen j1gagne = FALSE;
    booleen j2gagne = FALSE;
    int tour = 0;
    int exp = 0;
    int degat;

    do {
        degat = calculDegats(j1, j2);
        j2->pv -= degat;
        printf("%s attaque %s : %d pts de degats \n", j1->nom, j2->nom, degat);
        degat = calculDegats(j2, j1);
        j1->pv -= degat;
        printf("%s attaque %s : %d pts de degats \n", j2->nom, j1->nom, degat);
        printf("\n%s : [%d/%u]pv \n%s : [%d/%u]pv\n\n", j1->nom, j1->pv, j1->pvMax, j2->nom, j2->pv, j2->pvMax);
        tour++;
    }    while (j1->pv > 0 && j2->pv > 0);

                /*
                a completer
                 */
    

    exp = calculerGainExperience(j1, j2, j1gagne, tour);
                /*
                a completer
                 */
 
    printf(BLANC);
    printf("+++++++++++++++++++++++++++++++++++\n");
    afficherPersonnage(j1);
    printf("===================================\n");
    
}
