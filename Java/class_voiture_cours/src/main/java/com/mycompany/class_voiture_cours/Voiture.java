package com.mycompany.class_voiture_cours;

/**
 *
 * @author apacot
 */
public class Voiture 
{
    private String couleur;

    public String getCouleur() {
        return couleur;
    }

    public void setCouleur(String couleur) {
        this.couleur = couleur;
    }

    public int getNbKilometres() {
        return nbKilometres;
    }

    public void setNbKilometres(int nbKilometres) {
        this.nbKilometres = nbKilometres;
    }
    private int nbKilometres;
    
    public Voiture(String c, int nb)
    {
        this.couleur = c;
        this.nbKilometres = nb;
    }
    public void rouler(int distance)
    {
        nbKilometres+=distance;
    }
    public void afficher()
    {
        System.out.println("couleur : "+couleur);
        System.out.println("kilometrage : "+nbKilometres);
    }
}
