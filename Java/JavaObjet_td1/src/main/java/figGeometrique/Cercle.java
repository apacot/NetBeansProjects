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
public class Cercle 
{
    private double rayon;
    
    public Cercle()
    {
        
    }
    public Cercle(double rayon)
    {
        this.rayon = rayon;
    }
    public Cercle(Cercle c)
    {
        this.rayon=c.rayon;
    }
    public double calculerAire()
    {
        double aire;
        aire = Math.PI * rayon * rayon;
        return aire;
    }
    public void afficherAire()
    {
        System.out.println("Rayon du cercle : "+this.rayon);
    }
}
