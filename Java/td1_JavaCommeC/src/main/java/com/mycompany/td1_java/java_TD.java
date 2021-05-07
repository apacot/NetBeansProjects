/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.td1_java;

import java.util.Scanner;

/**
 *
 * @author apacot
 */
public class java_TD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
//     Exercice 1 et 2
        
/*      int i;
        int facto;
        int resultFacto=1;
        float resultat;        
        float nb1,nb2,nb3,nb4;
        Scanner sc = new Scanner(System.in);
        System.out.println("Donnez vos 4 nombres dans l'ordre de l'opération et le nombre factoriel");
        nb1=sc.nextFloat();
        nb2=sc.nextFloat();
        nb3=sc.nextFloat();
        nb4=sc.nextFloat();
        facto=sc.nextInt();
        sc.close();
        
        
        System.out.println("Voici la somme de vos 4 nombres : ");
        resultat=nb1+nb2+nb3+nb4;
        System.out.println(nb1 + " + " + nb2 + " + " + nb3 + " + " + nb4 +" = "+resultat);
        System.out.println("Voici la produit de vos 4 nombres : ");
        resultat=nb1*nb2*nb3*nb4;
        System.out.println(nb1 + " x " + nb2 + " x " + nb3 + " x " + nb4 +" = " +resultat);
        
        for (i=1;i<=facto;i++)
        {
            resultFacto = resultFacto * i  ;
        }
        System.out.println("factorielle de : "+ facto + " : " + resultFacto);
        System.out.format("factorielle de : %d : %d\n", facto, resultFacto);
*/    
     // Exercice 3
        
/*      float tempF;
        float tempC;
        
        System.out.println("donnez la température en fahrenheit");
        Scanner sc = new Scanner(System.in);
        tempF=sc.nextFloat();
        sc.close();
        tempC = ((float)5/9)*(tempF-32);  
        
        System.out.println("temperature convertie en degrés : " + tempC);
*/    
/*      //Exercice 4
        
        int nb=0;
        String codeSecret="2304";
        String codeASaisir;
    do
    {
        System.out.println("Saisir votre code");
        Scanner sc = new Scanner(System.in);
        codeASaisir =sc.nextLine();
        while (codeASaisir.length()!=4)
        {
            System.out.println("nombre de caractère incorrecte");
            System.out.println("Veuillez ressaisir le code");
            codeASaisir = sc.nextLine();
        }
        if (codeASaisir.equals(codeSecret))
        {
            System.out.println("Le code est correcte");
        }
        else
        {
            System.out.println("Le code est incorrecte");
            nb++;
            
        }
        
    }while ((codeASaisir.equals(codeSecret)== false) && (nb!=3));   
*/
/*    // Exercice 6
        
        int nbSecondeTotal;
        int nbJour;
        int nbHeure;
        int nbMinute;
        int nbSeconde;
        
        System.out.println("Entrez le nombre de seconde :");
        Scanner sc = new Scanner(System.in);
        nbSecondeTotal = sc.nextInt();
        
        nbJour = nbSecondeTotal / (3600 * 24);
        nbHeure = (nbSecondeTotal - (nbJour * 24 * 3600))/3600;
        nbMinute = (nbSecondeTotal - (nbJour * 24 * 3600) - (nbHeure * 3600))/60;
        nbSeconde = (nbSecondeTotal - (nbJour *24 * 3600) - (nbHeure * 3600) - (nbMinute * 60));
        
        System.out.println("Votre nombre de seconde en jours, heure, minutes, et secondes");
        System.out.println("Jours : "+nbJour);
        System.out.println("Heures : "+nbHeure);
        System.out.println("Minutes : "+nbMinute);
        System.out.println("Secondes : "+nbSeconde);
*/        
/*        //Exercice 7
        
        int nbligne=1;
        int nbEtoile=1;
        int i;
        
        System.out.println("Donnez le nombre de ligne : ");
        Scanner sc = new Scanner(System.in);
        i = sc.nextInt();
        
        while (nbligne<=i+1)
        {
            while (nbEtoile<nbligne)
            {
                System.out.print("*");
                nbEtoile++;
            }
            System.out.println("");
            nbligne++;
            nbEtoile=1;
        }
*/
/*    //Exercice 8
        
        int nbLigne;
        int i;
        int nbEtoile;
        
        System.out.println("Donnez le nombre de ligne : ");
        Scanner sc = new Scanner(System.in);
        nbLigne = sc.nextInt();
        
        for(i=0;i<nbLigne;i++)
        {
            for(nbEtoile=1;nbEtoile<=i;nbEtoile++)
            {
                System.out.print("*");
            }
            System.out.println("");
        }
*/
    //Exercice 9
        
        int nbLigne;
        int i;
        int nbEtoile;
        
        System.out.println("Donnez le nombre de ligne : ");
        Scanner sc = new Scanner(System.in);
        nbLigne = sc.nextInt();
        
        for(i=0;i<nbLigne;i++)
        {
            for(nbEtoile=1;nbEtoile<=i;nbEtoile++)
            {
                System.out.print("*");
            }
            System.out.println("");
        }
      
        
        
        
        
        
        
    }
    
}
