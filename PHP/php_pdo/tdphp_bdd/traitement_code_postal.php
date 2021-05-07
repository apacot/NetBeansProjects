<!DOCTYPE html>
<html>
    <head>        
        <title>affichage des régions</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
        <?php
        require_once './function_td.inc.php';
        $codePostal=$_GET['cp'];
        afficherVillesFromCp($codePostal);
        afficherCompteVillesFromCp($codePostal);
        ?>
    </body>
</html>

