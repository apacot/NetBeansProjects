<!DOCTYPE html>
<html>
    <head>        
        <title>gestion des villes</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <?php
        require_once './fonction_france.inc.php';
        $numeroDepartement=$_GET['numeroDept'];
        // avec filter_input :
        // $nomVille = filter_input(INPUT_POST, 'ville');
        $nomDepartement = afficheNomDepartementFromNumero($numeroDepartement);
        echo "<div>";
        echo "le département ayant pour numéro <b>$numeroDepartement</b> possède le nom : <b>$nomDepartement</b>";
        echo "</div>";
        ?>
    </body>
</html>
