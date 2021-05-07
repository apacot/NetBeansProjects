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
public class Point 
{
    // attributs
    private double x;
    private double y;
    
    // constructeurs
    //constructeurs défaut
    public Point()
    {
        
    }
    
    //constructeur à paramètres
    public Point(double x, double y) 
    {
        this.x = x;
        this.y = y;
    }  
    
    // constructeurs de copie
    public Point(Point p)
    {
        this.x=p.x;
        this.y=p.y;
    }
    
    public void translater(double offsetX, double offsetY)
    {
        this.x+=offsetX;
        this.y+=offsetY;               
    }
    public double calculerDistance()
    {
        double distance;
        distance = Math.sqrt(x*x+y*y);
        return distance;
    }
    public double calculerDistancePoint(Point p2)
    {
        double distance;
        distance = Math.sqrt(p2.x-this.x)*(p2.y-this.y);
        return distance;
    }
    public void afficherPoint()
    {
        System.out.println("Coordonnées du point :\nx = "+this.x+"\ny = "+this.y);
    }
    
    
}
