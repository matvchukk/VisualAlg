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

    property var secondWindow: null
    function createSecondWindow(file, type){
        if( secondWindow == null){
            var component =Qt.createComponent(file)
            secondWindow =component.createObject(root, {type: type,"x":0, "y":0})
            if (secondWindow !== null)
                secondWindow.anchors.centerIn= mainwindow
                secondWindow.hideMeCliked.connect( destroySecondWindow)
        }
    }

    function destroySecondWindow(){
         if( secondWindow !== null){
         secondWindow.destroy()
         secondWindow=null}
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
        Column{
            id: loColumn
            anchors.centerIn: parent
            spacing: parent.width/10

                Row{

                    Rectangle {
                         width: 10
                         height: button1.height
                         color:  "#721F1F"
                         }

                     Button {
                        id: button1
                        text: "Bubble Sort"
                        background: Rectangle {
                                     color: "white"
                                     }
                       contentItem: Text {
                       text: button1.text
                       color: "#721F1F"
                       font.pixelSize: 32
                       font.bold: true
                       anchors.horizontalCenter: parent.horizontalCenter
                       anchors.verticalCenter: parent.verticalCenter
                   }
                        onClicked: {
                            createSecondWindow("SecondWindowSort.qml", 1)
                         }
                      }
                 }
                Row{
                      Rectangle {
                         width: 10
                         height: button2.height
                         color:  "#721F1F"
                     }
                     Button {
                        id: button2
                        background: Rectangle {
                              color: "white"
                         }
                        contentItem: Text {
                       text: "Selection Sort"
                       color: "#721F1F"
                       font.pixelSize: 32
                       font.bold: true
                       anchors.horizontalCenter: button2.horizontalCenter
                       anchors.verticalCenter: parent.verticalCenter
                       wrapMode: Text.WordWrap
                   }
                        onClicked: {
                           createSecondWindow("SecondWindowSort.qml", 2)
                         }
                      }
             }
             Row{
                     Rectangle {
                         width: 10
                        height: button3.height
                        color:  "#721F1F"
                     }

                     Button {
                        id: button3
                        background: Rectangle {
                        color: "white"
                            }
                       text: "Quick Sort"
                       contentItem: Text {
                       text: button3.text
                       color: "#721F1F"
                       font.pixelSize: 32
                       font.bold: true
                       anchors.horizontalCenter: button3.horizontalCenter
                       anchors.verticalCenter: button3.verticalCenter
                        }
                       onClicked: {
                      createSecondWindow("SecondWindowSort.qml", 3)
                   }
               }
    }
    }
}

        Button {
            id: back
            anchors.bottom: parent.bottom
            background: Rectangle {
                color: "white"
                 }
            contentItem: Text {
            text: "Menu"
            font.pixelSize:26
            color: "#721F1F"}
            onClicked: secondDialog.hideMeCliked()
        }
   }









