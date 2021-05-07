/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.class_voiture_cours;

/**
 *
 * @author apacot
 */
public class TestVoiture 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Voiture maVoiture;
        maVoiture = new Voiture("rouge", 3000);
        /*System.out.println("couleur : "+maVoiture.couleur);
        System.out.println("kilometrage : "+maVoiture.nbKilometres);    */    
        maVoiture.afficher();
        
        maVoiture.rouler(15);
        maVoiture.setCouleur("noir");        
        maVoiture.afficher();
    }
    
}
