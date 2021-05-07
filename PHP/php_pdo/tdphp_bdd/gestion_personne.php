<!DOCTYPE html>
<html>
    <head>        
        <title>gestion des personnes</title>
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
        require_once './function_td.inc.php';
        afficherPersonne();
        ?>
    </body>
</html>
