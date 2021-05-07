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
public class TestBarre {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        Barre b;
        b = new Barre(8.9, 0.75, "barre");
        
        BarreCarree bc;
        bc = new BarreCarree(5, 7.8,1, "barreCaree");
        
        BarreRonde bRd;
        bRd = new BarreRonde(2, 2.7, 50, "BarreRonde");
        
        BarreRectangle bRc;
        bRc = new BarreRectangle(25, 5, 7.8, "barreRectangle");
        
        bc.afficherReference();
        System.out.println("masse de barre caree : " + bc.CalculerMasse());
        bRd.afficherReference();
        System.out.println("masse de barre ronde : " + bRd.calculerMasse());
        bRc.afficherReference();
        System.out.println("masse de barre rectangle : " + bRc.CalculerMasse());
    }
    
}
