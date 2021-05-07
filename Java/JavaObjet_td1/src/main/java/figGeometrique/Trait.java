/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package figGeometrique;
/**
 *
 * @author apacot
 */
public class Trait 
{
    private Point pointDeb;
    private Point pointFin;
    private int epaisseur;
    private String typeLigne;
    
    public Trait()
    {
        
    }

    public Trait(Point pointDeb, Point pointFin, int epaisseur, String typeLigne) 
    {
        this.pointDeb = pointDeb;
        this.pointFin = pointFin;
        this.epaisseur = epaisseur;
        this.typeLigne = typeLigne;
    }
    
    public Trait(Trait t)
    {
        this.pointDeb = t.pointDeb;
        this.pointFin = t.pointFin;
        this.epaisseur = t.epaisseur;
        this.typeLigne =t.typeLigne;
        
    }
    public double calculerLongueur()
    {
        double longueur;
        longueur=pointDeb.calculerDistancePoint(pointFin);
        return longueur;
    }
    public void afficheTrait()
    {
        System.out.println("Point de début : " );
        pointDeb.afficherPoint();
        System.out.println("Point de fin : ");
        pointFin.afficherPoint();
    }
            
    
}
