/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pageWeb.h
 * Author: antoine
 *
 * Created on 7 juin 2021, 09:38
 */

#ifndef PAGEWEB_H
#define PAGEWEB_H

#include <WebServer.h>
#include "structures.h"
#include "sigfox.h"

class pageWeb 
{
public:
    pageWeb();
    ~pageWeb();
    void handleRoot(typeDonnees *lesDonnees);
    void handleForm(typeDonnees *lesDonnees, Sigfox BallonSig);
    void handle_NotFound();
    String pageHtml;
    WebServer serveur;
    
private:

};

#endif /* PAGEWEB_H */

