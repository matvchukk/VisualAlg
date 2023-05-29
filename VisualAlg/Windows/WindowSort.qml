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


    property var values: [10, 5, 8, 3, 2]
    property var sortSteps: []
    property int currentStepIndex: 0
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
                           cellWidth: 100
                           cellHeight: parent.height - 80
                           model: ListModel {
                               id: listModel
                               ListElement { value: 10 }
                               ListElement { value: 5 }
                               ListElement { value: 8 }
                               ListElement { value: 3 }
                               ListElement { value: 2 }
                           }

                           delegate: Rectangle {
                               width: 100
                               height: value * 10
                               color: "steelblue"
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
            placeholderText: "Введіть число"
        }

        Button {
            id: addButton
            height: 50
            width: rightItem.width * 0.7

            text: "Додати"
            onClicked: {
                var inputNumber = parseInt(inputValue.text)
                if (!isNaN(inputNumber)) {
                    addValue(inputNumber)
                    inputValue.text = ""
                }
            }
        }

        Button {

            height: 50
            width: rightItem.width * 0.7
            text: "Сортувати"
            onClicked: {
                bubbleSort()
                currentStepIndex = 0
                updateGridView()
            }
        }

        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Назад"
            onClicked: {
                previousStep()
            }
            enabled: currentStepIndex > 0
        }

        Button {
            height: 50
            width: rightItem.width * 0.7
            text: "Вперед"
            onClicked: {
                nextStep()
            }
            enabled: currentStepIndex < sortSteps.length - 1
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
    function addValue(number) {
        values.push(number)
        listModel.append({ value: number })
    }

    function bubbleSort() {
        sortSteps = []
        var length = values.length
        var swapped = true
        while (swapped) {
            swapped = false

            for (var i = 0; i < length - 1; i++) {
                if (values[i] > values[i + 1]) {
                    swapValues(i, i + 1)

                    swapped = true

                }
            }
             sortSteps.push(values.slice())

            length--
        }


    }

    function swapValues(index1, index2) {
        var temp = values[index1]
        values[index1] = values[index2]
        values[index2] = temp


        listModel.setProperty(index1, "value", values[index1])
        listModel.setProperty(index2, "value", values[index2])
    }

    function previousStep() {
        if (currentStepIndex > 0) {
            currentStepIndex--
            updateGridView()
        }
    }

    function nextStep() {
        if (currentStepIndex < sortSteps.length - 1) {
            currentStepIndex++
            updateGridView()
        }
    }

    function updateGridView() {
        var stepValues = sortSteps[currentStepIndex]
        for (var i = 0; i < values.length; i++) {
            listModel.setProperty(i, "value", stepValues[i])
        }
    }


}


