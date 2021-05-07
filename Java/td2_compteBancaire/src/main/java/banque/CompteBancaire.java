/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package banque;

/**
 *
 * @author apacot
 */
public class CompteBancaire 
{
    private double soldeCompte;
    private double decouvertAutorise;
    
    public CompteBancaire()
    {
        System.out.println("constructeur par défaut");
    }
    public CompteBancaire(CompteBancaire cb)
    {
        this.soldeCompte=cb.soldeCompte;
        this.decouvertAutorise=cb.decouvertAutorise;
        System.out.println("constructeur de copie");
    }
    public CompteBancaire(double solde,double decouvert)
    {
        this.soldeCompte=solde;
        this.decouvertAutorise=decouvert;
    }
    public void retirerSomme(double sommeRetrait)
    {
        if (sommeRetrait>0)
        {
          soldeCompte-=sommeRetrait;  
        }             
    }
    public void deposerSomme (double sommeDepot)
    {
        if (sommeDepot>=0)
        {
            soldeCompte+=sommeDepot;
        }
    }
    public void changerDecouvert(double nouveauDecouvert)
    {
        this.decouvertAutorise = nouveauDecouvert;
    }
    public void afficherSolde()
    {
        System.out.println("Solde du compte : "+this.soldeCompte + "€");
    }
    public void afficherDecouvert()
    {
        System.out.println("Decouvert autorisé sur le compte : "+this.decouvertAutorise + "€");
    }
    
    
}
