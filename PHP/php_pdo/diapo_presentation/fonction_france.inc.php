<?php
define("SERVEURBD", "195.221.61.190");
define("LOGIN", "snir");
define("MOTDEPASSE", "snir");
define("NOMDELABASE", "france");

function connexionBdd(){
    
    try{
        $pdoOptions = array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION);
        $bdd = new PDO('mysql:host=' . SERVEURBD . ';dbname=' . NOMDELABASE, LOGIN, MOTDEPASSE, $pdoOptions);
        $bdd->exec("set names utf8");
        return $bdd;
    } catch (PDOException $e) {
        print "Erreur !:" . $e->getMessage() . "<br/>";
        die();
    }
}

function getNomDepartementFromVille($ville){
    try{
        //connexion à la base et selection de la BDD
        $bdd = connexionBdd();
        
        //préparation de la requete sql
        $requete = $bdd->prepare("select nomDept from ville, departement"
                . "where departement.idDepartement=ville.idDepartement"
                . "and nomVille like : laville ; ");
        // remplacement des variables de la requete par les valeurs effectives
        $requete->bindParam(":laville", $ville);
        
        // execution de la requete
        $requette->execute() or die(print_r($requete->errorInfo()));
        
        //recuperation du nombre de ligne retourné par la requete
        $nbLigne = $requete->rowCount();
                
        //si pas de correspondance
        if($nbLigne == 0){
            $nomDep = "pas de département correspondant";
        }        
        // si une seule correspondance
        if($nbLigne == 1){
            $nomDep = $requete->fetchColumn(0);
        }
        //si plus d'une correspondance
        if($nbLigne > 1 ){
            $nomDep = "";
            while ($ligne=$requete->fetch()){
                $nomDep=$nomDep. "<br/>". $ligne['nomDept'];
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

