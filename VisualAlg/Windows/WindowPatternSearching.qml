import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle{
    signal hideMeCliked()
    id: secondDialog
    visible: true
    width: parent.width
    height: parent.height
    anchors.centerIn: parent
    color: "pink"

    property string textToSearch: ""
    property string patternToSearch: ""

    Button{
        id: back
        anchors.bottom: parent.bottom
        text: "Back"
        onClicked: secondDialog.hideMeCliked()
    }

    Column {
        TextField {
            placeholderText: "Text to search"
            onTextChanged: {
                textToSearch = text;
                rabinKarp.search(textToSearch, patternToSearch); // Виклик алгоритму Рабіна-Карпа при зміні тексту
            }
        }
        TextField {
            placeholderText: "Pattern to search"
            onTextChanged: {
                patternToSearch = text;
                rabinKarp.search(textToSearch, patternToSearch); // Виклик алгоритму Рабіна-Карпа при зміні шаблону
            }
        }
        Text {
            id: resultText
            text: getResultText()
            visible: getResultText() !== ""
        }
    }
    Connections {
        target: rabinKarp
        onSearchCompleted: {
            resultText.visible = true;
            searchResult = positions;
        }
    }
    function resetSearchResult() {
        resultText.visible = false;
        searchResult = [];
    }

    property var searchResult: []

    function getResultText() {
        if (searchResult.length > 0) {
            return "Search result: " + searchResult.join(", ");
        } else {
            return "Pattern not found";
        }
    }
}
