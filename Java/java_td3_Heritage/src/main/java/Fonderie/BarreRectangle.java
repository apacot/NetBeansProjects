/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Fonderie;

/**
 *
 * @author apacot
 */
public class BarreRectangle extends Barre
{
    protected double largeur;
    
    public BarreRectangle()
    {
        System.out.println("constructeur par défaut");
    }
    public BarreRectangle(double longueur, double largeur, double densite, String reference) 
    {
        super(densite, longueur, reference);
        this.longueur = longueur;
        this.largeur = largeur;
    }
    public BarreRectangle(BarreRectangle br)
    {
        super(br.densite, br.longueur, br.reference);
        this.longueur = br.longueur;
        this.largeur = br.largeur;
    }
    public double CalculerMasse()
    {
        double masse;
        double section;
        section = longueur*largeur;
        masse = longueur*densite*section;
        return masse;
    }
    
    
}
