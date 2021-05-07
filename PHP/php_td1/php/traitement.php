<!DOCTYPE html>

<html>
    <head>
        <title>TODO supply a title</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
    <?php
    //afficher les valeurs des champs du formulaire
    /*  
        echo "nom : ".$_POST['nom'];
        echo "<br/>";
        echo "prenom : ".$_POST['prenom'];
        echo "<br/>";
        echo "date de naissance : ".$_POST['ddn'];
        echo "<br/>";
        echo "<pre>";
        print_r($_POST);
        echo "</pre>";
     */
    require_once './functions.inc.php';
    if (filter_input(INPUT_SERVER, 'REQUEST_METHOD')==='POST')
    {
        afficherChamps($_POST);    
    }
    else
    {
        afficherChamps($_GET);
    }
    
    ?>
    </body>
</html>

    

