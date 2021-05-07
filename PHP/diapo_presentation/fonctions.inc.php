<?php

function afficheBonjour()
{
    echo "Hello World";
}
function verifLogin($login,$mdp)
{
    $retour=false;
    if($login=="toto" && $mdp=="toto")
    {
        $retour=true;
    }
    return $retour;
}
    

