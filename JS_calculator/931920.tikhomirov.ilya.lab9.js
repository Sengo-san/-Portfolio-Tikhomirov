function digitInsert() {
    var numberInsert = document.getElementById("numberInsert");
    if (numberInsert.innerHTML == "0") numberInsert.innerHTML = "";
    numberInsert.innerHTML += document.activeElement.innerHTML;

}

function clearMonitor() {
    var numberInsert = document.getElementById("numberInsert");
    var numberSaved = document.getElementById("numberSaved");
    var operator = document.getElementById("operator");
    numberInsert.innerHTML = "0";
    numberSaved.innerHTML = "";
    operator.innerHTML = "";
}

function operatorInsert() {
    var operator = document.getElementById("operator");
    var numberSaved = document.getElementById("numberSaved");
    var numberInsert = document.getElementById("numberInsert");

    if (operator.innerHTML) {
        if (numberInsert.innerHTML.length) {
            solve();
            numberSaved.innerHTML = numberInsert.innerHTML;
            numberInsert.innerHTML = "";
        }
        operator.innerHTML = document.activeElement.innerHTML;
    }

    else {
        var numberInsert = document.getElementById("numberInsert");
        var numberSaved = document.getElementById("numberSaved");
        numberSaved.innerHTML = numberInsert.innerHTML;
        operator.innerHTML = document.activeElement.innerHTML;
        numberInsert.innerHTML = "";
    }

}

function dotInsert() {
    var numberInsert = document.getElementById("numberInsert");
    if (numberInsert.innerHTML.indexOf('.') == -1) {
        if (numberInsert.innerHTML == "")
            numberInsert.innerHTML += "0.";
        else
            numberInsert.innerHTML += '.';
    }


}


function solve() {
    var numberInsert = document.getElementById("numberInsert");
    var numberSaved = document.getElementById("numberSaved");
    var operator = document.getElementById("operator");

    var res;
    switch (operator.innerHTML) {
        case "*":
            res = Number(numberSaved.innerHTML) * Number(numberInsert.innerHTML);
            break;
        case "/":
            res = Number(numberSaved.innerHTML) / Number(numberInsert.innerHTML);
            break;
        case "-":
            res = Number(numberSaved.innerHTML) - Number(numberInsert.innerHTML);
            break;
        case "+":
            res = Number(numberSaved.innerHTML) + Number(numberInsert.innerHTML);
            break;
        default:
            res = numberInsert.innerHTML;
            break;
    }

    numberInsert.innerHTML = res;
    numberSaved.innerHTML = "";
    operator.innerHTML = "";

}

function del() {
    var numberInsert = document.getElementById("numberInsert");
    var numberSaved = document.getElementById("numberSaved");
    var operator = document.getElementById("operator");

    if (numberInsert.innerHTML.length > 1 && numberSaved.innerHTML.length == 0)
        numberInsert.innerHTML = numberInsert.innerHTML.slice(0, -1);

    else if (numberInsert.innerHTML.length == 1 && numberSaved.innerHTML.length == 0)
        numberInsert.innerHTML = "0";

    else if (numberInsert.innerHTML.length > 0 && numberSaved.innerHTML.length > 0)
        numberInsert.innerHTML = numberInsert.innerHTML.slice(0, -1);

    else {
        operator.innerHTML = "";
        numberInsert.innerHTML = numberSaved.innerHTML;
        numberSaved.innerHTML = "";
    }

}