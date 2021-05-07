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
public class TestFigure 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Cercle c1;
        c1 = new Cercle(5.6);
        c1.afficherAire();
        System.out.println("Aire du cercle : "+c1.calculerAire());
        
        carre c2;
        c2 = new carre(5);
        c2.afficherAire();
        System.out.println("Aire du carré : "+c2.calculerAire());
        
        Point p1;
        p1 = new Point(3,5);
        p1.afficherPoint();
        
        Point p2;
        p2 = new Point(5,7);
        p2.afficherPoint();
        
        Trait t;
        t = new Trait(p1,p2,2,"continu");
        t.afficheTrait();
        System.out.println("longueur du trait : "+t.calculerLongueur());
        
    }
    
}
