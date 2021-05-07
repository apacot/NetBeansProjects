<?php

define("SERVEURBD", "195.221.61.190");
define("LOGIN", "snir");
define("MOTDEPASSE", "snir");
define("NOMDELABASE", "france2015");

function connexionBdd() {

    try {
        $pdoOptions = array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION);
        $bdd = new PDO('mysql:host=' . SERVEURBD . ';dbname=' . NOMDELABASE, LOGIN, MOTDEPASSE, $pdoOptions);
        $bdd->exec("set names utf8");
        return $bdd;
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}

function afficherPersonne() {
    try {
        //connexion à la base et selection de la BDD
        $bdd = connexionBdd();

        //préparation de la requete sql
        $requete = $bdd->prepare("select nom, prenom, dateNaissance, ville_nom, ville_code_postal, departement_nom, region_nom from utilisateurs, villes, departements, regions where villes.ville_id=utilisateurs.ville_id, departements.ville_departement_id=villes.departement_id, regions.departement_region_id=departements.regions_id;") or die(print_r($requete->errorInfo()));

        // execution de la requete
        $requete->execute() or die(print_r($requete->errorInfo()));

        echo "<table>";
        echo "<tr><th>Nom</th><th>Prénom</th><th>Date de naissance</th><th>Nom de la ville</th><th>Code postal</th><th>Département</th><th>Région</th></tr>";
        while ($ligne = $requete->fetch()) {
            echo "<tr>";
            echo "<td>" . $ligne['nom'] . "</td>";
            echo "<td>" . $ligne['prenom'] . "</td>";
            echo "<td>" . $ligne['dateNaissance'] . "</td>";
            echo "<td>" . $ligne['ville_nom'] . "</td>";
            echo "<td>" . $ligne['ville_code_postal'] . "</td>";
            echo "<td>" . $ligne['departement_nom'] . "</td>";
            echo "<td>" . $ligne['region_nom'] . "</td>";
            echo "</tr>";
        }
        echo"</table>";
        //liberation des ressources de la requete
        $requete->closeCursor();
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}

function afficherVillesFromCp($codePostal) {
    try {
        //connexion à la bdd
        $bdd = connexionBdd();

        //préparation de la requete sql

        $requete = $bdd->prepare("select ville_nom from villes where ville_code_postal like :cp;");

        // remplacement des variables de la requete par les valeurs effectives
        $requete->bindParam(":cp", $codePostal);

        // execution de la requete
        $requete->execute() or die(print_r($requete->errorInfo()));

        //recuperation du nombre de ligne retourné par la requete
        $nbLigne = $requete->rowCount();

        //si pas de correspondance
        if ($nbLigne == 0) {
            $nomVille = "pas de ville correspondant a votre code postal";
        }
        // si une seule correspondance
        if ($nbLigne == 1) {
            $nomVille = $requete->fetchColumn(0);
        }
        //si plus d'une correspondance
        if ($nbLigne > 1) {
            $nomVille = "";
            while ($ligne = $requete->fetch()) {
                $nomVille = $nomVille . "<br/>" . $ligne['ville_nom'];
            }
        }
        //liberation des ressources de la requete
        $requete->closeCursor();

        //affichage 
        echo "<div>";
        echo " la ou les ville ayant pour code postal <b>$codePostal</b> sont <b>$nomVille</b>";
        echo "</div>";
        
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}
function afficherCompteVillesFromCp($codePostal) {
    try {
        //connexion à la bdd
        $bdd = connexionBdd();

        //préparation de la requete sql

        $requete = $bdd->prepare("select ville_nom from villes where ville_code_postal like :cp;");

        // remplacement des variables de la requete par les valeurs effectives
        $requete->bindParam(":cp", $codePostal);

        // execution de la requete
        $requete->execute() or die(print_r($requete->errorInfo()));

        //recuperation du nombre de ligne retourné par la requete
        $nbLigne = $requete->rowCount();

        //liberation des ressources de la requete
        $requete->closeCursor();

        //affichage 
        echo "<div>";
        echo "il existe <b>$nbLigne</b> ville(s) qui ont comme code postal : <b>$codePostal</b>";
        echo "</div>";
        
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}
function afficherPopulationParDepartement()
{
    try{
        //connexion bdd
        $bdd= connexionBdd();
        
        //préparation de la requete
        $requete = $bdd->prepare("select ville_departement, count(*) from villes group by ville_departement;");
        
        //execution requete
        $requete->execute() or die(print_r($requete->errorInfo()));
        
        //recuperation du nombre de ligne retourné par la requete
        $nbVille = $requete->rowCount();
        
        echo "il y a $nbVille villes dans le departement :";
        
    } catch (Exception $ex) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}

