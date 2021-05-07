/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   zone.h
 * Author: apacot
 *
 * Created on 12 octobre 2020, 10:43
 */
#pragma pack(push,1)
#ifndef ZONE_H
#define ZONE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    float temp; //4 octets
    int press;  //4 octets
    char ordre; //4 octets
}zoneMemPartagee;


#ifdef __cplusplus
}
#endif

#endif /* ZONE_H */

