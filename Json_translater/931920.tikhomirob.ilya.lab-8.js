function createJsonLine() {

    var linesContainer = document.getElementById('linescontainer');
    var line = linesContainer.children[0];
    var newLine = line.cloneNode(true);

    newLine.children[0].value = '';
    newLine.children[1].value = '';
    linesContainer.lastChild.after(newLine);
}

function moveUp() {
    var line = document.activeElement.parentElement;
    var prevLine = line.previousElementSibling;
    if (prevLine) {
        prevLine.before(line);
    }
}

function moveDown() {
    var line = document.activeElement.parentElement;
    var nextLine = line.nextElementSibling;
    if (nextLine) {
        nextLine.after(line);
    }
}

function deleteJsonLine() {
    var linesContainer = document.getElementById('linescontainer');
    if (linesContainer.children.length > 1) {
        var line = document.activeElement.parentElement;
        var linesContainer = document.getElementById('linescontainer');
        linesContainer.removeChild(line);
    }
}

function saveAsJson() {
    var jsText = '{'
    var linesList = document.getElementById('linescontainer').children;
    for (var i = 0; i < linesList.length; i++) {
        var jsElement = "\"";
        jsElement += linesList[i].children[0].value;
        jsElement += "\":\"";
        jsElement += linesList[i].children[1].value;
        jsElement += "\""
        if (linesList[i + 1]) {
            jsElement += ",";
        }
        jsText += jsElement;
    }
    jsText += "}";
    document.getElementById("jsText").innerHTML = jsText;
}
