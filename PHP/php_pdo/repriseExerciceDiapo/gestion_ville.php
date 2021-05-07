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
        $nomVille=$_POST['ville'];
        // avec filter_input :
        // $nomVille = filter_input(INPUT_POST, 'ville');
        $nomDepartement = getNomDepartementFromVille($nomVille);
        echo "<div>";
        echo "ville de <b>$nomVille</b> se trouve dans le departement : <br/>";
        echo "<b>$nomDepartement</b>";
        echo "</div>";
        ?>
    </body>
</html>
