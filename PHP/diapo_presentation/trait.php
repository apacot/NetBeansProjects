<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <title>Traitement formulaire</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <?php
        if (filter_input(INPUT_SERVER, 'REQUEST_METHOD')==='GET') 
        {
            require_once './fonctions.inc.php';
            $login=filter_input(INPUT_GET,'login');
            $mdp=filter_input(INPUT_GET,'pwd');
            if(verifLogin($login, $mdp))
            {
                echo "utilisateur $login identifié";
            }
            else
            {
                echo "login : $login ou mdp incorrect";
            }
        /*  echo "votre login est : ".filter_input(INPUT_GET,'login'); //correspond à : $_GET["login"]
            echo "<br/>";
            echo "votre mot de passe est : ".filter_input(INPUT_GET,'pwd'); //correspond à : $_GET["pwd"]
            echo "<br/>";   
            $email=filter_input(INPUT_GET,'courriel',FILTER_VALIDATE_EMAIL); //correspond à : $_GET["courriel"] + validation formait email
            if($email===false)
            {
                echo "email syntaxiquement incorrecte";
            }
            else
            {
            echo "votre email est : $email ";
            }
        */
        }
        ?>
    </body>
</html>
