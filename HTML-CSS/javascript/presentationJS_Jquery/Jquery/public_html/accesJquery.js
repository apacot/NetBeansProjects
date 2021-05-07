function changeCouleur()
{
    $(this).css("background-color","red");
    
    $("form").append('<input type="button" value="3" />');
}
function afficheValeur()
{
    var valBouton=$(this).val();
    $("#duTexte").css("background-color","white");
    $("#duTexte").css("color","red");
    $("#duTexte").text(valBouton);

}

$(document).ready(function()
{
    $("#duTexte").click(changeCouleur);
   //allocation statique
   //  $(":button").mouseover(afficheValeur);

    //allocation dynamique
    $(document).on("mouseover",":button",afficheValeur);
   
})