import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12




Rectangle {
    signal hideMeCliked()
    id: secondDialog
    visible: true
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    ListModel {
        id: numberModel
    }

    Item {
        anchors.fill: parent

        Rectangle {
            id: topRect
            height: 100
            width: parent.width
            color: "#721F1F"
            anchors.top: parent.top

            Text {
                text: "Sorting algorithms"
                font.bold: true
                font.pixelSize: 32
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 35
                color: "white"
            }
        }

        Item {
            width: parent.width
            anchors.bottom: parent.bottom
            anchors.top: topRect.bottom

            Rectangle {
                id: leftRect
                width: 0.8 * parent.width
                height: parent.height
                anchors.left: parent.left

                ListView {
                    id: numberList
                    model: array

                    spacing: 5
                    orientation: ListView.Horizontal
                    anchors.centerIn: parent
                    width: parent.width * 0.7
                    height: parent.height * 0.2
                    delegate: Rectangle {
                        width: textItem.implicitWidth + 10
                        height: textItem.implicitHeight + 10

                        RowLayout {
                            anchors.centerIn: parent

                            Text {
                                id: textItem
                                color: "black"
                                font.bold: true
                                font.pixelSize: 24
                            text: modelData.items.toString()
                            }
                        }
                    }
                }
            }



            Item {
                id: rightItem
                width: 0.2 * parent.width
                height: parent.height
                anchors.right: parent.right

                Column {
                    anchors.top: parent.top
                    anchors.topMargin: 50
                    anchors.horizontalCenter: parent.horizontalCenter

                    TextField {
                        id: inputtext
                        placeholderText: "Enter the number"
                        height: 50
                        width: rightItem.width * 0.7
                        color: "black"
                    }

                    Button {
                        text: "ADD"
                        height: 50
                        width: rightItem.width * 0.7

                        onClicked: {
                            var number = parseInt(inputtext.text)
                            if (!isNaN(number)) {
                                array.addItem(number)
                                inputtext.text = ""
                            }
                        }
                    }


                    Connections {
                        target: bubbleSort
                       onCallQml: {
                          array=steplist
                             console.log("Connection works")
                            console.log(steplist);

                        }
                    }
                    Button {
                            text: "Sort"
                            height: 50
                            width: rightItem.width * 0.7

                            onClicked: {

                                bubbleSort.sort()
                            }
                        }



                    }
                }
            }
        }


    Button {
        id: back
        anchors.bottom: parent.bottom
        text: "Back"
        onClicked: secondDialog.hideMeCliked()
    }
}

