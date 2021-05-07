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
public class CompteEpargne extends CompteBancaire
{
    private double tauxInteret;
    
    /**
     *
     * @return
     */
    public double calculerInteret()
    {
        double interet;
        interet = solde*tauxInteret/100.0;
        return interet;
    }

    /**
     *
     */
    public void crediterInteret()
    {
        solde+=calculerInteret();
    }

    /**
     *
     * @param nouveauTaux
     */
    public void changerTaux(double nouveauTaux)
    {
        if (nouveauTaux >=0)
        {
            tauxInteret=nouveauTaux;
        }
    }    

    /**
     *
     * @return
     */
    @Override
    public String toString() 
    {
        return "CompteEpargne{" + "tauxInteret=" + tauxInteret + '}';
    }
    
}

