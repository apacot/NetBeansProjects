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
public class CompteCheque 
{
    private double decouvertAutorise;
    
    /**
     *
     */
    public CompteCheque()
    {
        System.out.println("constructeur defaut CompteCheque");
    }

    /**
     *
     * @param decouvertAutorise
     */
    public CompteCheque(double decouvertAutorise)
    {
        this.decouvertAutorise = decouvertAutorise;
        System.out.println("constructeur CompteCheque avec parametre");
    }

    /**
     *
     * @param cc
     */
    public CompteCheque(CompteCheque cc)
    {
        this.decouvertAutorise = cc.decouvertAutorise;
        System.out.println("constructeur copie compteCheque");
    }

    /**
     *
     * @param nouveauDecouvert
     */
    public void changerDecouvert(double nouveauDecouvert)
    {
        this.decouvertAutorise = nouveauDecouvert;
    }
}
