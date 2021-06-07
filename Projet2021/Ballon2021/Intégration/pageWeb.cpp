
/* 
 * File:   pageWeb.cpp
 * Author: antoine
 * 
 * Created on 7 juin 2021, 09:38
 */

#include "pageWeb.h"
#include "sigfox.h"

pageWeb::pageWeb() 
{
    
}

pageWeb::~pageWeb() 
{
    
}

void pageWeb::handleRoot(typeDonnees *lesDonnees) 
{

    pageHtml = "<!DOCTYPE html>";
    pageHtml += "<head>";
    pageHtml += "<title>Ballon2021</title>";
    pageHtml += "<meta charset='UTF-8'>";
    pageHtml += "<meta name='viewport' content= width=device-width, initial-scale=1.0>";
    pageHtml += "<script>";
    pageHtml += "function afficherData() {";
    pageHtml += "document.getElementById('Date').innerHTML = '" + String(lesDonnees->date.jour) + "/" + String(lesDonnees->date.mois) + "/" + String(lesDonnees->date.annee) + "';";
    pageHtml += "document.getElementById('Heure').innerHTML = '" + String(lesDonnees->heures.heure) + ":" + String(lesDonnees->heures.minute) + ":" + String(lesDonnees->heures.seconde) + "';";
    pageHtml += "document.getElementById('Longitude').innerHTML = '" + String(lesDonnees->position.latitude,{6}) + "';";
    pageHtml += "document.getElementById('Latitude').innerHTML = '" + String(lesDonnees->position.longitude,{6}) + "';";
    pageHtml += "document.getElementById('Altitude').innerHTML = '" + String(lesDonnees->position.altitude) + "';";
    pageHtml += "document.getElementById('Temperature').innerHTML = '" + String(lesDonnees->DonneesCapteurs.temperature) +"';";
    pageHtml += "document.getElementById('Pression').innerHTML = '" + String(lesDonnees->DonneesCapteurs.pression) + "';";
    pageHtml += "document.getElementById('Radiation').innerHTML = '" + String(lesDonnees->DonneesCapteurs.cpm) + "';";
    pageHtml += "document.getElementById('Humidite').innerHTML = '" + String(lesDonnees->DonneesCapteurs.humidite) + "';";
    pageHtml += "}";
    pageHtml += "setInterval('afficherData()', 10000);";
    pageHtml += "</script>";
    pageHtml += "</head>";
    pageHtml += "<body>";
    pageHtml += "<div><h1> BALLON SONDE 2021 </h1></div>";
    pageHtml += "<div><h2> Date : <span id = 'Date'></span></h2>";
    pageHtml += "<h2> Heure : <span id = 'Heure'></span></h2>";
    pageHtml += "<h2> Latitude : <span id = 'Latitude'></span></h2>";
    pageHtml += "<h2> Longitude : <span id = 'Longitude'></span></h2>";
    pageHtml += "<h2> Altitude (m): <span id = 'Altitude'></span></h2>";
    pageHtml += "<h2> Température (°C) : <span id = 'Temperature'></span></h2>";
    pageHtml += "<h2> Pression (hpa) : <span id = 'Pression'></span></h2>";
    pageHtml += "<h2> Radiation (cpm) : <span id = 'Radiation'></span></h2>";
    pageHtml += "<h2> Humidité (%HR) : <span id = 'Humidite'></span></h2></div>";
    pageHtml += "<form action = '/form' method = 'get'>";
    pageHtml += "<input type = 'submit' ID = 'boutonEnvoyer' value = 'EnvoyerTrame'>";
    pageHtml += "</form>";
    pageHtml += "</body";
    pageHtml += "</html>";

    serveur.send(200, "text/html", pageHtml);
}

void pageWeb::handleForm(typeDonnees *lesDonnees, Sigfox BallonSig) {
    
    BallonSig.coderTrame(lesDonnees);
    bool ret = BallonSig.envoyer(BallonSig.trame, sizeof (BallonSig.trame));

    String pageOK;
    //bool ret = true;
    
    if (ret) {
        pageOK += "Trame envoyee avec succes";
    } else {
        pageOK += "Trame non envoyee, revenez sur la page precedente";
    }
    serveur.send(200, "text/plain", pageOK);
}

void pageWeb::handle_NotFound() { // Page Not found
    serveur.send(404, "text/plain", "404: Not found");
}
