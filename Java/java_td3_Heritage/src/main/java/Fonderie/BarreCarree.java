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
public class BarreCarree extends Barre
{
    protected double cote;
    
    public BarreCarree()
    {
        System.out.println("constructeur par défaut");
    }
    public BarreCarree(double cote, double densite, double longueur, String reference)
    {
        super(densite, longueur, reference);
        this.cote = cote;
        System.out.println("constructeur avec paramètre");
    }
    public BarreCarree(BarreCarree bc)
    {
        super(bc.densite, bc.longueur, bc.reference);
        this.cote = bc.cote;
        System.out.println("constructeur de copie");
    }
    public double CalculerMasse()
    {
        double masse;
        double section;
        section = cote*cote;
        masse = longueur*densite*section;
        return masse;
    }
}
