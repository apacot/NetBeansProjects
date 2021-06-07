/**
 * @file taches.h
 * @brief Déclaration de la classe Taches
 * @version 1.0
 * @author Sofiane SABRI
 * @date 20/05/2021
 */
#ifndef TACHES_H
#define TACHES_H
#define SERIAL_BAUD 115200
#define LED 22
#define SERIALGPS 1

#include "structures.h"

class Taches {
public:
    Taches();
    //void ObtenirTaches(void * parameter);
   static void tacheBME280(void * parameter);
   static void tacheRadiations(void* parameter);
   static void tacheGPS(void* parameter);
   static void tacheAffichage(void* parameter);
   static void tacheSigfox(void* parameter);
   static void tacheCarteSD(void* parameter);
   void tachePageWeb(void* parameter);
   
private:
    
};


#endif /* TACHES_H */

