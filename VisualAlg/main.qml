import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12


Window {
    id: root
    width: Screen.desktopAvailableWidth
  height: Screen.desktopAvailableHeight
    visible: true

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

        anchors.fill: parent
    }

    Rectangle {
        id: topRect
        height: 100
        width: parent.width
        color: "#721F1F"
        anchors.top: parent.top

        Text {
            text: "Choose the algorithm"
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
                    text: "Sorting"
                    background: Rectangle {
                                 color: "white"
                                 }
                   contentItem: Text {
                   text: button1.text
                   color: "#721F1F"
                   font.pixelSize: 40
                   font.bold: true
                   anchors.horizontalCenter: parent.horizontalCenter
                   anchors.verticalCenter: parent.verticalCenter
               }
                    onClicked: {
                        createSecondWindow("../Windows/WindowSort.qml")
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
                   text: "Pattern Searching"
                   color: "#721F1F"
                   font.pixelSize: 40
                   font.bold: true
                   anchors.horizontalCenter: button2.horizontalCenter
                   anchors.verticalCenter: parent.verticalCenter
                   wrapMode: Text.WordWrap
               }
                    onClicked: {
                        createSecondWindow("../Windows/WindowPatternSearching.qml")
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
                   text: "Trees"
                   contentItem: Text {
                   text: button3.text
                   color: "#721F1F"
                   font.pixelSize: 40
                   font.bold: true
                   anchors.horizontalCenter: button3.horizontalCenter
                   anchors.verticalCenter: button3.verticalCenter
                    }
                   onClicked: {
                   createSecondWindow("../Windows/WindowTree.qml")
               }
           }
}
}
}
