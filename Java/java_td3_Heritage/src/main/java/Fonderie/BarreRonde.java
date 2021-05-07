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
public class BarreRonde extends Barre
{
    protected double diametre;
    
    public BarreRonde()
    {
        System.out.println("constructeur par défaut");
    }
    public BarreRonde(double diametre, double densite, double longueur, String reference)
    {
        super(densite, longueur, reference);
        this.diametre = diametre;
        System.out.println("constructeur avec parametres");
    }
    public BarreRonde(BarreRonde br)
    {
        super(br.densite,br.longueur,br.reference);
        this.diametre = br.diametre;
        System.out.println("constructeur de copie");
    }
    public double calculerMasse()
    {
        double section;
        double masse;
        section = Math.PI*(diametre/2)*(diametre/2);
        masse = longueur*densite*section;
        return masse;
    }
    
}
