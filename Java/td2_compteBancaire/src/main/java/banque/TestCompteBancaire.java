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
public class TestCompteBancaire 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        CompteBancaire cb;
        cb = new CompteBancaire(1000, 0);
        cb.afficherDecouvert();
        cb.afficherSolde();
        cb.deposerSomme(100);
        cb.retirerSomme(150);
        cb.changerDecouvert(500);
        cb.afficherDecouvert();
        cb.afficherSolde();
        
    }
    
}
