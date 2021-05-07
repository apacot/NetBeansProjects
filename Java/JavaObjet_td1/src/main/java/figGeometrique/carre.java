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
public class carre 
{
    private double cote;
    
    public carre()
    {
        
    }
    
    public carre(double cote)
    {
        this.cote = cote;
    }
    
    public carre(carre c)
    {
        this.cote = c.cote;
    }
    
    public double calculerAire()
    {
        double aire;
        aire = cote*cote;
        return aire;
    }
    public void afficherAire()
    {
        System.out.println("coté du carré : "+this.cote);
    }
    
}
