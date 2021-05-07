/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.class_carre_cours;

/**
 *
 * @author apacot
 */
public class Carre 
{
    int Cote;
    public Carre (int cote)
        {
            this.Cote = cote;
        }
    public float calculerPerimetre()
    {
        int perimetre;
        perimetre = Cote*4;
        return perimetre;
    }
    public int calculerAire()
    {
        int Aire;
        Aire = Cote*Cote;
        return Aire;
    }
    public void afficherAire()
    {
        System.out.println("aire du carre : "+calculerAire());
    }
    public void afficherPerimetre()
    {
        System.out.println("perimetre du carre : "+calculerPerimetre());
    }
}
