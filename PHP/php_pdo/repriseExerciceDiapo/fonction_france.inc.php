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
function afficheDepartementsRegions() {
    try {
        //connexion à la base et selection de la BDD
        $bdd = connexionBdd();

        //préparation de la requete sql
        $requete = $bdd->query("select departement_nom, region_nom from departements, regions where departements.departement_region_id=regions.regions_id order by region_nom;") or die(print_r($requete->errorInfo()));

        echo "<table>";
        echo "<tr><th>Régions</th><th>Département</th></tr>";
        while ($ligne = $requete->fetch()) {
            echo "<tr>";
            echo "<td>".$ligne['region_nom']."</td>";
            echo "<td>".$ligne['departement_nom']."</td>";
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

function afficheRegions() {
    try {
        //connexion à la base et selection de la BDD
        $bdd = connexionBdd();

        //préparation de la requete sql
        $requete = $bdd->query("select region_nom from regions order by region_nom;") or die(print_r($requete->errorInfo()));

        //recuperation du nombre de ligne retourné par la requete
        //$nbLigne = $requete->count(*);

        //si plus d'une correspondance
//        if ($nbLigne > 1) {
//            while ($ligne = $requete->fetch()) {
//                echo $ligne['region_nom'];
//                echo"<br/>";
//            }
//        } else {
//            echo "pas de région";
//        }
        //liberation des ressources de la requete
        $requete->closeCursor();
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}
function afficheNomDepartementFromNumero($numeroDepartement)
{
    try {
        //connexion à la base et selection de la BDD
        $bdd = connexionBdd();

        //préparation de la requete sql
        $requete = $bdd->prepare("select departement_nom from departements where departement_code like :nro ; ");
        // remplacement des variables de la requete par les valeurs effectives
        $requete->bindParam(":nro", $numeroDepartement);

        // execution de la requete
        $requete->execute() or die(print_r($requete->errorInfo()));

        //recuperation du nombre de ligne retourné par la requete
        $nbLigne = $requete->rowCount();

        //si pas de correspondance
        if ($nbLigne == 0) {
            $nomDep = "pas de département correspondant";
        }
        // si une seule correspondance
        if ($nbLigne == 1) {
            $nomDep = $requete->fetchColumn(0);
        }
        //si plus d'une correspondance
        if ($nbLigne > 1) {
            $nomDep = "";
            while ($ligne = $requete->fetch()) {
                $nomDep = $nomDep . "<br/>" . $ligne['departement_nom'];
            }
        }
        //liberation des ressources de la requete
        $requete->closeCursor();

        // retourne la chaine correspondant au departement
        return $nomDep;
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}
function getNomDepartementFromVille($ville) {
    try {
        //connexion à la base et selection de la BDD
        $bdd = connexionBdd();

        //préparation de la requete sql
        $requete = $bdd->prepare("select departement_nom from villes, departements "
                . "where departements.departement_id = villes.ville_departement_id and ville_nom like :laville ;");
        // remplacement des variables de la requete par les valeurs effectives
        $requete->bindParam(":laville", $ville);

        // execution de la requete
        $requete->execute() or die(print_r($requete->errorInfo()));

        //recuperation du nombre de ligne retourné par la requete
        $nbLigne = $requete->rowCount();

        //si pas de correspondance
        if ($nbLigne == 0) {
            $nomDep = "pas de département correspondant";
        }
        // si une seule correspondance
        if ($nbLigne == 1) {
            $nomDep = $requete->fetchColumn(0);
        }
        //si plus d'une correspondance
        if ($nbLigne > 1) {
            $nomDep = "";
            while ($ligne = $requete->fetch()) {
                $nomDep = $nomDep . "<br/>" . $ligne['departement_nom'];
            }
        }
        //liberation des ressources de la requete
        $requete->closeCursor();

        // retourne la chaine correspondant au departement
        return $nomDep;
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}
