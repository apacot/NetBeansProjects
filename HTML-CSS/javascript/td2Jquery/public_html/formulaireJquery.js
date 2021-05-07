function verifMDP()
{
    //récuperer mdp 1
    var mdp1 = $("#mdp").val();
    
    //récuperer mdp 2
    var mdp2 = $("#mdp2").val();
    $("#mdp2").next('p').remove();
    
    //comparer mdp1 et mdp2 et voir si identique
    if(mdp1!=mdp2)
    {
        //alert("Mots de passe non identiques");
        $('<p style="display:inline; color:red; position: absolute; left : 460px; top:60px;">Mots de passe non identiques</p>').insertAfter('#mdp2');
    }
}

$(document).ready(function(){
    //associer boutton-click et appel à la fonction
   $("#inscription").click(verifMDP);
    
});