<!DOCTYPE html>
<html>
    <head>        
        <title>affichage des régions</title>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <style>
            table,tr,th,td
            {
                border: 1px black ridge;
                text-align: center;
            }
            table
            {
                border-collapse: collapse;
            }
        </style>
    </head>
    <body>
        <?php
        require_once './fonction_france.inc.php';
        afficheDepartementsRegions();
        ?>
    </body>
</html>
