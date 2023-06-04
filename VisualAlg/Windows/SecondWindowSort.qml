import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
Rectangle {
    signal hideMeCliked()
    id: secondSortWindow
    visible: true
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

     property var values: [16,42,18,5,12,27,19,8]
     property int currentStepIndex: -2
     property int first: -1
     property int second: -1
     property int sorted: 0
     property int type
     property int complexity: 0
     property int time: 0

    Item {
        anchors.fill: parent

        Rectangle {
            id: topRect
            height: 100
            width: parent.width
            color: "#3B5249"
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
            id: lefterItem
            width: 0.2 * parent.width
            height: parent.height
            anchors.left: parent.left

            Column {
                anchors.top: parent.top
                anchors.topMargin: 150
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 20

                  TextField {
                     id: inputValue

                    height: 70
                     width: rightItem.width * 0.7



                    placeholderText: "Enter a number"
                    font.pixelSize: 18
                    color: "#3B5249"

                            background: Rectangle {
                                color: "transparent"
                                border.color: "#3B5249"  // Колір контуру
                                border.width: 2  // Товщина контуру
                                radius: 5  // Радіус кутиків
                            }

                     }

          Button {
            id: addButton
            height: 50
            width: rightItem.width * 0.7
            background: Rectangle {
                  color: "white"
             }
            contentItem: Text {
            text: "Add"
            color: "#3B5249"
             font.bold: true
            font.pixelSize: 22}

            onClicked: {
                var inputNumber = parseInt(inputValue.text)
                if (inputNumber>0) {
                     empty.visible=false
                    positive.visible=false
                    addValue(inputNumber)
                    inputValue.text = ""
                    sorted=0
                    currentStepIndex=0
                    getListOfSteps(type).clearSteps()
                }
                else positive.visible=true

            }
        }


          Button {
            id: deleteButton
            height: 50
            width: rightItem.width * 0.7
            background: Rectangle {
                  color: "white"
             }
            contentItem: Text {
            text: "Delete"
            color: "#3B5249"
             font.bold: true
            font.pixelSize: 22}
            onClicked: {
                    removeLastValue()
                    sorted=0
                    currentStepIndex=0
                    getListOfSteps(type).clearSteps()
            }
              enabled: listModel.count>0
        }


   }
}
        Item {
            width: 0.6*parent.width
            anchors.bottom: parent.bottom
            anchors.top: topRect.bottom
            anchors.left: lefterItem.right

            Rectangle {
                id: leftRect
                width:  parent.width
                height: parent.height
               // anchors.left: lefterItem.right

                GridView {
                           width: parent.width
                           height: parent.height - 80
                           cellWidth: parent.width/ listModel.count
                           cellHeight: parent.height - 80
                           model: ListModel {
                               id: listModel
                               ListElement { value:16}
                               ListElement { value: 42 }
                               ListElement { value: 18 }
                               ListElement { value:5 }
                               ListElement { value:12 }
                               ListElement { value:27 }
                               ListElement { value:19 }
                               ListElement { value:8 }
                           }

                           delegate: Rectangle {
                               width: parent.width/ listModel.count
                               height: value * 10
                             color: (index === first || index === second) ? "#20342C" :  "#A4B494"
                               border.color: "#3B5249"
                               Text {
                                   font.pixelSize: 24
                                   color: "white"
                                   text: value
                                   anchors.centerIn: parent
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
                anchors.topMargin: 150
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 20

          Connections {
                         target: getSort(type)
                         onCallQml: {
                                sorted=1
                                getListOfSteps(type).backup();
                                currentStepIndex++
                                    }
                                }
          Connections {
                         target: getSortType(type)
                         onElapsedTimeChanged: {
                            // complexity=  getSortType(type).elapsedTime()
                              console.log("EEEEEEEEEEEEEEEE")
                           time=elapsedTime
                             eltime.visible=true
                                    }
                                }


        Button {
            height: 50
            width: rightItem.width * 0.7
            background: Rectangle {
                  color: "white"
             }
            contentItem: Text {
            text: "Sort"
            horizontalAlignment: Text.AlignRight
            font.bold: true
            color:  parent.enabled ? "#3B5249" : "#748B82"
            font.pixelSize: 32}
            onClicked: {
                if (listModel.count>0){
                    currentStepIndex = 0
                    arrayIntoQlist(values.slice())
                    getListOfSteps(type).backup()
                    getSortType(type).sort()
                    //console.log(getSortType(type).time)
                   //complexity=getSortType(type).getComplexity()

                    currentStepIndex++
                    updateGridView()
                    first=-1
                    second=-1
                }
                else empty.visible=true
            }
            enabled: sorted===0
        }
        Rectangle {
            width: rightItem.width
           height:6
           color:  "#3B5249"
        }
        Button {
            height: 50
            width: rightItem.width * 0.7
            background: Rectangle {
                  color: "white"
             }
            contentItem: Text {
            text: "Back"
             color:  parent.enabled ? "#3B5249" : "#748B82"
            horizontalAlignment: Text.AlignRight
             font.bold: true
            font.pixelSize: 26}
            onClicked: {
                currentStepIndex--
                updateGridView()
            }
            enabled: currentStepIndex > 1
        }

        Button {
            height: 50
            width: rightItem.width * 0.7
            background: Rectangle {
                  color: "white"
             }
            contentItem: Text {
            text: "Forward"
            color:  parent.enabled ? "#3B5249" : "#748B82"
            horizontalAlignment: Text.AlignRight
             font.bold: true
            font.pixelSize: 26}
            onClicked: {
                if (listModel.count>0){
                if (sorted===0){
                    currentStepIndex = 0
                    arrayIntoQlist(values.slice())
                    getListOfSteps(type).backup()
                    getSortType(type).sort()
                    currentStepIndex = 1}
                    currentStepIndex++
                    updateGridView()
            }
                else empty.visible=true
            }
         enabled: currentStepIndex!==getListOfSteps(type).getSize()
        }

        Button {
            height: 50
            width: rightItem.width * 0.7
            background: Rectangle {
                  color: "white"
             }
            contentItem: Text {

            text: "Reset"
            color:  parent.enabled ? "#3B5249" : "#748B82"
            horizontalAlignment: Text.AlignRight
             font.bold: true
            font.pixelSize: 26}
            onClicked: {
                currentStepIndex=1
                first=-1
                second=-1
                updateGridView()
                sorted=0
                getListOfSteps(type).clearSteps()
            }
              enabled: sorted===1

        }
        Text {
            id: eltime
            text:"Elapsed time: " +time+ " ms"
            font.bold: true
            font.pixelSize: 18
           anchors.bottom: rightItem.bottom
            anchors.left: parent.left
            anchors.leftMargin: 35
            anchors.topMargin: 100
            color:  "#3B5249"
            visible: false
        }

        }

         }
        Text {
            id: positive
            text: "Please, enter a positive number"
            font.bold: true
            font.pixelSize: 18
           anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.leftMargin: 35
            anchors.bottomMargin: parent.height/10
            color:  "#3B5249"
            visible: false
        }
        Text {
            id: empty
            text: "Your list is empty!"
            font.bold: true
            font.pixelSize: 18
           anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.leftMargin: 35
            anchors.bottomMargin: parent.height/10
            color:  "#3B5249"
            visible: false
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
            color: "#3B5249"}
            onClicked: {
                values=[]
                secondSortWindow.hideMeCliked()}
        }
   }

    function getListOfSteps(type){
        if (type===1) return listofstepsB
        else if (type===2) return listofstepsS
        else if (type===3) return listofstepsQ
        }

    function getSortType(type){
        if (type===1) return timingBubbleSort
        else if (type===2) return timingSelectionSort
        else if (type===3) return timingQuickSort
        }
    function getSort(type){
        if (type===1) return bubbleSort
        else if (type===2) return selectionSort
        else if (type===3) return quickSort
        }

     function arrayIntoQlist(list){
        array.clearItems()
        for (var i=0;i<list.length;i++){
              array.addItem(list[i] )
             }
     }

    function addValue(number) {
        values.push(number)
        listModel.append({ value: number })
    }

    function removeLastValue() {
        if (values.length > 0) {
            values.pop();
            listModel.remove(listModel.count - 1);
        }
    }

    function updateGridView() {
        listModel.clear()
        values=[]
        first= getListOfSteps(type).getIndexLeft(currentStepIndex-1)
        second= getListOfSteps(type).getIndexRight(currentStepIndex-1)
        for (var i = 0; i <  getListOfSteps(type).getList(currentStepIndex-1).length; i++) {
            values.push( getListOfSteps(type).getList(currentStepIndex-1)[i]);}
        for (var i = 0; i <values.length; i++) {
            listModel.append({ value: values[i] })}
}

}
