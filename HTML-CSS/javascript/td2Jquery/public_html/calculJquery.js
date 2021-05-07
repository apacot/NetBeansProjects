function multiplication()
{
    // recupérer les valeurs de val1 et val2
    var val1=$("#val1").val();
    var val2=$("#val2").val();
    console.log("val1 = " +val1+ " val2 = " + val2);
    $("#result").val(val1*val2);
}
function addition()
{
    // recupérer les valeurs de val1 et val2
    var val1=$("#val1a").val();
    var val2=$("#val2a").val();
    console.log("val1 = " +val1a+ " val2 = " + val2a);
    $("#resulta").val(parseFloat(val1)+parseFloat(val2));
}
$(document).ready(function(){
  //association bouton égal (click) et appel de fonction
  $("#egal").click(multiplication);
  $("#egala").click(addition); 
    
});