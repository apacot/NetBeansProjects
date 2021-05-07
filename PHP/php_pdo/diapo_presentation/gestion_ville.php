<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title></title>
    </head>
    <body>
        <?php
        require_once './fonctions_france.inc.php';
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
