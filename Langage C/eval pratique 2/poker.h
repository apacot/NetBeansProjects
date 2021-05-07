/* 
 * File:   poker.h
 * Author: 
 *
 * Created on 28 novembre 2019, 08:53
 * Modified on 
 * Description : déclaration des fonctions pour le poker aux dés
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/timeb.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/random.h>

#ifndef POKER_H
#define POKER_H

#define NBMAXCAR 50
#define NBDES 5
#define NBJOUEUR 2
#define NBFACES 6
#define AGELIMITE 18
#define SOLDEDEPART 10000

#define BLACK    "\033[1;30m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define PURPLE   "\033[1;35m"
#define CYAN     "\033[1;36m"
#define GREY     "\033[1;37m"
/**
 * @brief retourne une valeur aleatoire entre 0 et maxAlea[
 * @param maxAlea limite haute (non comprise) de la valeur aleatoire
 * @return une valeur E[0..maxAlea[
 */
unsigned int aleatoire(unsigned int maxAlea);
/**
 * @brief attendre maxTime millisecondes
 * @param maxTime
 */
void msleep(unsigned int maxTime);

/**
 * @brief tester si l'age est supérieur à l'age limite
 * @param age age a tester
 * @param ageLimite limite d'age
 * @return -1 si age<ageLimite, 0 sinon
 */
int testerAge(int age, int ageLimite);
/**
 * @brief demander la mise du joueur lui redemandant tant que celle-ci est plus grande que son solde
 * @param solde solde du joueur
 * @return le valeur de la mise
 */
int demanderMise(int solde);
/**
 * @brief tire une valeur aleatoire entre 0 et nbFace
 * @param nbFace
 * @return une valeur E[0..nbFace[
 */
int lancerUnDes(int nbFace);
/**
 * @brief afficher la position et la valeur de chacun des dés
 * @param des le tableau correspondant aux valeurs des dés
 * @param nbDes nombre de dés
 */
void afficherCombinaison(int des[], int nbDes);
/**
 * @brief demander la position du dés à relancer tant que la position n'est pas comprise entre [-1..4]
 * @return la position du dés
 */
int demanderNumeroDeDes();
/**
 * @brief calculer le score correspondant à la combinaison de dés
 * @param des le tableau contenant les valeurs des dés
 * @param nbDes nombre de dés
 * @return score correspondant à la combinaison de dés
 */
int calculerScore(int des[], int nbDes);


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* POKER_H */

