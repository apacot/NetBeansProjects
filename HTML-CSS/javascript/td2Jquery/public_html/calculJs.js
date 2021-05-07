function multiplication()
{
    // recupérer les valeurs de val1 et val2
    var val1=document.getElementById("val1").value;
    var val2=document.getElementById("val2").value;
    console.log("val1 = " +val1+ " val2 = " + val2);
    document.getElementById("result").value=val1*val2;
}
function addition()
{
    // recupérer les valeurs de val1 et val2
    var val1=document.getElementById("val1a").value;
    var val2=document.getElementById("val2a").value;
    console.log("val1 = " +val1+ " val2 = " + val2);
    document.getElementById("resulta").value=parseFloat(val1)+parseFloat(val2);
}