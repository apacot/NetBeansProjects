function genererListeRegions() {
    $("#regions").empty();
    $.getJSON('php/controleur.php',
            {
                'commande': 'getRegions',
            }
    )
            .done(function (donnees, stat, xhr) {
                // génération de la liste déroulante des utilisateurs
                $("#regions").append($('<option>', {value: -1}).text("Sélectionnez une région"));
                $.each(donnees, function (index, ligne) {
                    // ligne contient un objet json de la forme
                    // {"idRegion" : "id de la region"},
                    // {"nomRegion" : "nom de la region"}                 
                    $("#regions").append($('<option>', {value: ligne.idRegion}).text(ligne.nomRegion));
                });
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
                console.log("status : " + text);
                console.log("error : " + error);
            });
}

function genereListeDepartements()
{
    var idRegion = $(this).val(); // on récupère la valeur de la clef primaire correspondant à la région


    $("#departements").empty();
    $("#villes").empty();   // on vide également la liste des villes car elle peut contenir les villes d'un département sélectionner auparavant.
    // si la region selectionné existe (pas le "choisissez une region")
    if (idRegion != -1) {
        $.getJSON('php/controleur.php',
                {
                    'commande': 'getDepartements',
                    'idRegion' : idRegion
                }
        )
                .done(function (donnees, stat, xhr) {
                    // génération de la liste déroulante des utilisateurs
                    $("#departements").append($('<option>', {value: -1}).text("Sélectionnez un département"));
                    $.each(donnees, function (index, ligne) {
                        // ligne contient un objet json de la forme
                        // {"idDepartement" : "id du departement"},
                        // {"nomDepartement" : "nom du departement"}           
                        $("#departements").append($('<option>', {value: ligne.idDepartement}).text(ligne.nomDepartement));
                    });
                })
                .fail(function (xhr, text, error) {
                    console.log("param : " + JSON.stringify(xhr));
                    console.log("status : " + text);
                    console.log("error : " + error);
                });
    }

}

$(document).ready(function ()
{
    // generation de la liste deroulante des regions
    genererListeRegions();

    // gestion du changement de region
    $("#regions").change(genereListeDepartements);

    // gestion du changement de departement

});
