import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
import QtQuick.Shapes 1.15

Rectangle {
    signal hideMeClicked
    id: secondDialog
    visible: true
    width: parent.width
    height: parent.height
    anchors.centerIn: parent
    color: "#eeeee4"

    property string textToSearch: ""
    property string patternToSearch: ""
    property bool isSearching: false

    Button {
        id: back
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "Back"
        onClicked: secondDialog.hideMeClicked()
    }

    Column {
        Rectangle {
            id: title
            height: 100
            width: screen.width
            color: "#154c79"
            anchors.topMargin: 10

            Text {
                text: "Algorithms for Pattern Searching"
                font.bold: true
                font.pixelSize: 32
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 35
                color: "white"
            }
        }

        ColumnLayout {
            anchors.topMargin: 40

            TextField {
                placeholderText: "Text to search"
                onTextChanged: {
                    textToSearch = text;
                    resetSearchResult();
                }
                implicitWidth: 450
                implicitHeight: 60
            }

            TextField {
                placeholderText: "Pattern to search"
                onTextChanged: {
                    patternToSearch = text;
                    resetSearchResult();
                }
                implicitWidth: 450
                implicitHeight: 60
            }

            Text {
                id: resultText
                text: getResultText()
                visible: isSearching && getResultText() !== ""
                font.bold: true
                font.pixelSize: 20
                color: "#154c79"
            }

            Text {
                text: "Your pattern:"
                font.bold: true
                font.pixelSize: 20
                color: "#154c79"
            }

            Row {
                id: patternVisualization
                spacing: 1

                Repeater {
                    model: patternToSearch.length

                    Rectangle {
                        width: Math.min((secondDialog.width - 25) / patternToSearch.length, 80)
                        height: 80
                        color: "#FFD6C4"
                        border.color: "#f59971"

                        Text {
                            text: patternToSearch[index]
                            font.family: "Courier New"
                            font.bold: true
                            anchors.centerIn: parent
                        }
                    }
                }
            }

            Text {
                text: "Your text:"
                font.bold: true
                font.pixelSize: 20
                color: "#154c79"
            }

            Row {
                id: textVisualization
                spacing: 1

                Repeater {
                    model: textToSearch.length

                    Rectangle {
                        id: cell
                        property int textIndex: index
                        width: Math.min((secondDialog.width - 25) / textToSearch.length, 80)
                        height: 80
                        color: "#D2D0FF"
                        border.width: isPatternFound(textIndex) ? 3 : 1
                        border.color: isPatternFound(textIndex) ? "red" : "#8c87fa"

                        Text {
                            text: textToSearch[textIndex]
                            font.family: "Courier New"
                            font.bold: true
                            anchors.centerIn: parent
                        }

                        Repeater {
                            model: searchResult.length

                            Shape {
                                property int patternFirstIndex: searchResult[index]
                                visible: textIndex === patternFirstIndex && patternToSearch !== ""
                                ShapePath {
                                    strokeWidth: 2
                                    strokeColor: "red"
                                    startX: 0
                                    startY: cell.height
                                    PathLine {
                                        x: patternToSearch.length * cell.width / 2
                                        y: cell.height + 120
                                    }
                                }
                                ShapePath {
                                    strokeWidth: 2
                                    strokeColor: "red"
                                    startX: cell.width*patternToSearch.length
                                    startY: cell.height
                                    PathLine {
                                        x: patternToSearch.length * cell.width / 2
                                        y: cell.height + 120
                                    }
                                }
                            }
                        }
                    }
                }
            }
            Row {
                anchors.top: textVisualization.bottom
                anchors.topMargin: 200
                 spacing: 20

                ColumnLayout {
                     spacing: 20
                    Button {
                        text: "Rabin-Karp Algorithm"
                        onClicked: {
                            context.setStrategy(rabinKarp);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }

                    Button {
                        text: "Boyer Moore Algorithm"
                        onClicked: {
                            context.setStrategy(boyerMoore);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }
                    Button {
                        text: "Finite Automata Algorithm"
                        onClicked: {
                            context.setStrategy(finiteAutomata);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }
                    Button {
                        text: "KMP Algorithm"
                        onClicked: {
                            context.setStrategy(knuthMorrisPratt);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }
                    Text {
                            id: elapsedTimeText
                            visible: isSearching
                            text: "Elapsed Time: " + context.elapsedTime
                            font.bold: true
                            font.pixelSize: 20
                            color: "#154c79"
                        }
                }

                ColumnLayout {
                     spacing: 20
                    Button {
                        text: "Boyer-Moore-Horspool Algorithm"
                        onClicked: {
                            context.setStrategy(boyerMooreHorspool);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }

                    Button {
                        text: "Smith Algorithm"
                        onClicked: {
                            context.setStrategy(smith);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }

                    Button {
                        text: "Gallagher-Syed-Gallagher Algorithm"
                        onClicked: {
                            context.setStrategy(gallagherSyedGallagher);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }

                    Button {
                        text: "Collins Algorithm"
                        onClicked: {
                            context.setStrategy(collinsAlgorithm);
                            context.executeStrategy(textToSearch, patternToSearch);
                            resultText.visible = true;
                        }
                        implicitWidth: 200
                        implicitHeight: 40
                    }

                }
            }
        }


    }

    Connections {
        target: context
        onSearchStarted: {
            isSearching = true;
            resetSearchResult();
        }
        onSearchCompleted: {
            isSearching = false;
            resultText.visible = true;
            searchResult = positions;
            elapsedTimeText.visible = true;
        }
        onGetElapsedTime: {
            //elapsedTime = timedContext.elapsedTime
            elapsedTimeText.text = "Elapsed Time: " + elapsedTime;
                }
    }

    function resetSearchResult() {
        resultText.visible = false;
        searchResult = [];
    }

    property var searchResult: []

    function getResultText() {
        if (searchResult.length > 0 && patternToSearch !== "") {
            return "Search result: " + searchResult.join(", ");
        } else if (!isSearching && patternToSearch !== "") {
            return "Pattern not found";
        } else {
            return "";
        }
    }


    function isPatternFound(index) {
        for (var i = 0; i < searchResult.length; i++) {
            if (index >= searchResult[i] && index < searchResult[i] + patternToSearch.length)
                return true;
        }
        return false;
    }

    function getFormattedElapsedTime() {
            var seconds = Math.floor(context.elapsedTime / 1000);
            var milliseconds = context.elapsedTime % 1000;
            //return seconds + "." + milliseconds + "s";
        return milliseconds;
        }
}
