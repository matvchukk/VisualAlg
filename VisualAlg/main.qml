import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property var secondWindow: null

    function createSecondWindow(file){
        if( secondWindow == null){
            var component =Qt.createComponent(file)
            secondWindow =component.createObject(root, {"x":0, "y":0})
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

    Rectangle{
        id:mainwindow
        color: "#8EA4D2"
        anchors.fill: parent
    }

    Text{
        text:"Choose the algorithm"

        anchors.verticalCenter: parent.top
        anchors.horizontalCenter: parent.right
        anchors.verticalCenterOffset: parent.height/10
        anchors.horizontalCenterOffset: -parent.width/2
    }
    ColumnLayout{
        id: loColumn
        anchors.centerIn: parent
        spacing: parent.width/10


        //the first algorithm
        Button{
            id: button1
            text: "Sort"
            onClicked: {
                createSecondWindow("../Windows/WindowSort.qml")
            }
        }

        //the second algorithm
        Button{
            id: button2
            text: "Alg2"
            onClicked: {
                createSecondWindow("../Windows/Window2.qml")
            }
        }

         //the third algorithm
        Button{
            id: button3
            text: "Alg3"
            onClicked: {
                createSecondWindow("../Windows/Window3.qml")
            }
        }


    }


}
