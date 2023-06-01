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

        Item {
            id: rightItem
            width:  parent.width
            height: parent.height
            anchors.right: parent.right

           Row {
                anchors.top: parent.top
                anchors.topMargin:parent.height/2-50
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 20


                Button{
                    id: button1
                    text: "Bubble Sort"
                    width: 200
                    height: 60
                    font.pixelSize: 20

                    onClicked: {
                        createSecondWindow("SecondWindowSort.qml", 1)
                    }
                }
                Button{
                    id: button2
                    text: "Selection Sort"
                    width: 200
                    height: 60
                    font.pixelSize: 20

                    onClicked: {
                        createSecondWindow("SecondWindowSort.qml", 2)
                    }
                }
                Button{
                    id: button3
                    text: "Sort"
                    width: 200
                    height: 60
                    font.pixelSize: 20

                    onClicked: {
                       // createSecondWindow("BubbleSortWindow.qml")
                    }
                }

         }
        }
        Button {
            id: back
            anchors.bottom: parent.bottom
            text: "Menu"
            onClicked: secondDialog.hideMeCliked()
        }
   }





    }



