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
public class Barre 
{
    protected double densite;
    protected double longueur;
    protected String reference;
    
    public Barre()
    {
        System.out.println("constructeur par défaut");
    }

    public Barre(double densite, double longueur, String reference) 
    {
        this.densite = densite;
        this.longueur = longueur;
        this.reference = reference;
        System.out.println("constructeur avec paramètres");
    }
    public Barre(Barre b)
    {
        this.densite = b.densite;
        this.longueur = b.longueur;
        this.reference = b.reference;
        System.out.println("constructeur de copie");
    }
    public void afficherReference()
    {
        System.out.println("La reference de la barre est : " + reference);
    }
}
