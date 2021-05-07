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
public class CompteBancaire 
{

    /**
     *
     */
    protected double solde;
    
    /**
     *
     * @param somme
     */
    public void deposer (double somme)
    {
        if (somme>=0)
        {
            solde+=somme;
        }
    }

    /**
     *
     * @param retrait
     */
    public void retirer(double retrait)
    {
        if (retrait >=0)
        {
        solde-=retrait;
        }
    }
}
