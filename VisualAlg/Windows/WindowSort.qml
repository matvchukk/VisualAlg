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

     property var values: [6,2,3,5]
     property int currentStepIndex: -2
     property int first: -1
     property int second: -1
     property int sorted: 0

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
                }
            }
        }


          Connections {
                         target: bubbleSort
                         onCallQml: {
                                sorted=1
                                listofsteps.backup();
                                currentStepIndex++
                                    }
                                }

        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "BubbleSort"
            onClicked: {
            currentStepIndex = 0
            arrayIntoQlist(values.slice())
            listofsteps.backup();
            currentStepIndex++
            bubbleSort.sort()
            updateGridView()
            first=-1
            second=-1
            }
            enabled: sorted===0
        }

        Connections {
                              target: quickSort
                              onCallQml: {
                                      values=[]
                                      for (var i = 0; i < steplist.length; i++) {
                                         values.push(steplist[i]);
                                      }
                                      sortSteps.push(values.slice())
                                      updateGridView()
                                      currentStepIndex++
                                }
                            }
        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "QuickSort"
            onClicked: {
                currentStepIndex = 0
               arrayIntoQlist(values.slice())
                 quickSort.sort()
                currentStepIndex = 0
              // console.log( QuickSort.getComplexity())

            }
        }
        Connections {
                              target: mergeSort
                              onCallQml: {
                                      values=[]
                                      for (var i = 0; i < steplist.length; i++) {
                                         values.push(steplist[i]);
                                      }
                                      sortSteps.push(values.slice())
                                      updateGridView()
                                      currentStepIndex++
                                }
                            }
        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "MergeSort"
            onClicked: {

                arrayIntoQlist(values.slice())
                 mergeSort.sort()

                currentStepIndex = 0
              // console.log(   MergeSort.getComplexity())

            }
        }

        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Back"
            onClicked: {
                currentStepIndex--
                updateGridView()
            }
            enabled: currentStepIndex > 0
        }

        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Forward"
            onClicked: {

                if (sorted===0){
                    currentStepIndex = 0
                    arrayIntoQlist(values.slice())
                    bubbleSort.sort()
                    currentStepIndex = 0}

                currentStepIndex++
                updateGridView()
            }

        }
        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Reset"
            onClicked: {
                currentStepIndex=1
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
            onClicked: secondDialog.hideMeCliked()
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
        first=listofsteps.getIndexLeft(currentStepIndex-1)
        second=listofsteps.getIndexRight(currentStepIndex-1)
        for (var i = 0; i < listofsteps.getList(currentStepIndex-1).length; i++) {
           values.push(listofsteps.getList(currentStepIndex-1)[i]);
        }
        for (var i = 0; i <values.length; i++) {
            listModel.append({ value: values[i] })
        }
        }



    }



