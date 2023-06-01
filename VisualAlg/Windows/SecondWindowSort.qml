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

     property var values: [6,2,3,5]
     property int currentStepIndex: -2
     property int first: -1
     property int second: -1
     property int sorted: 0
     property int type
     property int complexity: 0

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

                GridView {
                           width: parent.width
                           height: parent.height - 80
                           cellWidth: parent.width/ listModel.count
                           cellHeight: parent.height - 80
                           model: ListModel {
                               id: listModel
                               ListElement { value:6}
                               ListElement { value: 2 }
                               ListElement { value: 3 }
                               ListElement { value:5 }
                           }

                           delegate: Rectangle {
                               width: parent.width/ listModel.count
                               height: value * 10
                             color: (index === first || index === second) ? "brown" : "steelblue"
                               border.color: "black"
                               Text {
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

                  TextField {
                     id: inputValue
                    height: 50
                     width: rightItem.width * 0.7
                    placeholderText: "Enter a number"
                     }

          Button {
            id: addButton
            height: 50
            width: rightItem.width * 0.7

            text: "Add"
            onClicked: {
                var inputNumber = parseInt(inputValue.text)
                if (!isNaN(inputNumber)) {
                    addValue(inputNumber)
                    inputValue.text = ""
                    sorted=0
                    currentStepIndex=0
                    listofsteps.clearSteps()
                     listofstepsS.clearSteps()

                }
            }
        }

          Connections {
                         target:  bubbleSort
                         onCallQml: {
                                sorted=1
                                listofsteps.backup();
                                currentStepIndex++
                                    }
                                }

          Connections {
                         target:  selectionSort
                         onCallQml: {
                                sorted=1
                                listofstepsS.backup();
                                currentStepIndex++
                                    }
                                }

        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Sort"
            onClicked: {
            currentStepIndex = 0
            arrayIntoQlist(values.slice())

                if (type==1){
                    listofsteps.backup()
                    bubbleSort.sort()
                    complexity=bubbleSort.getComplexity()

                }
                if(type==2){
                    listofstepsS.backup()
                    selectionSort.sort()
                    complexity= selectionSort.getComplexity()
                    console.log(complexity)

                }
            currentStepIndex++
            updateGridView()
            first=-1
            second=-1
            }
            enabled: sorted===0
        }



        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Back"
            onClicked: {
                currentStepIndex--
                updateGridView()
            }
            enabled: currentStepIndex > 1
        }

        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Forward"
            onClicked: {

                if (sorted===0){

                    currentStepIndex = 0
                    arrayIntoQlist(values.slice())
                    if (type==1){
                         listofsteps.backup()
                        bubbleSort.sort()
                    currentStepIndex = 0}

                    if(type==2){
                         listofstepsS.backup()
                        selectionSort.sort()
                       currentStepIndex = 0}}

                currentStepIndex++
                updateGridView()
            }
         enabled: (currentStepIndex-1)/2!=complexity
        }
        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Reset"
            onClicked: {
                currentStepIndex=1
                first=-1
                second=-1
                updateGridView()
                sorted=0
            }

        }
        }

         }
        Button {
            id: back
            anchors.bottom: parent.bottom
            text: "Menu"
            onClicked: {
                values=[]
                secondSortWindow.hideMeCliked()}
        }
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

    function updateGridView() {
        listModel.clear()
        values=[]
        if (type==1){
            first=listofsteps.getIndexLeft(currentStepIndex-1)
            second=listofsteps.getIndexRight(currentStepIndex-1)
            for (var i = 0; i < listofsteps.getList(currentStepIndex-1).length; i++) {
               values.push(listofsteps.getList(currentStepIndex-1)[i]);
            }
        }
        else if (type===2){

            first=listofstepsS.getIndexLeft(currentStepIndex-1)
            second=listofstepsS.getIndexRight(currentStepIndex-1)
            for (var i = 0; i < listofstepsS.getList(currentStepIndex-1).length; i++) {
            values.push(listofstepsS.getList(currentStepIndex-1)[i]);

            }
        }
        console.log(currentStepIndex)
        for (var i = 0; i <values.length; i++) {
            listModel.append({ value: values[i] })
        }
        }



    }


