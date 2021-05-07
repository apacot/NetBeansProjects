/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.javaobjetheritage;

/**
 *
 * @author apacot
 */
public class TestCompteEpargne {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        //...
        CompteEpargne ce;
        double interet;        
        ce = new CompteEpargne();
        ce.deposer(100.0);
        ce.changerTaux(0.5);// taux livret A
        interet = ce.calculerInteret();
        
    }
    
}
