import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.12
Rectangle {
    signal hideMeCliked()
    id: secondTreeWindow
    visible: true
    width: parent.width
    height: parent.height
    anchors.centerIn: parent

     property var values: [16,42,18,5,12,27,19,8]

    ListModel {
        id: treeModel
    }

    function updateTreeModel(tree) {
        treeModel.clear()
        var values = tree.getSortedValues()
        for (var i = 0; i < values.length; ++i) {
            treeModel.append({ "value": values[i] })
        }
    }

    Item {
        anchors.fill: parent

        Row {
            spacing: 10
            TextField {
                id: valueInput
                placeholderText: "Enter value"
                width: 100
            }

            Button {
                text: "Add"
                onClicked: {
                    var value = parseInt(valueInput.text)
                    avlTree.insert(value)
                    valueInput.text = ""
                }
            }

            Button {
                text: "Remove"
                onClicked: {
                    var value = parseInt(valueInput.text)
                    avlTree.remove(value)
                    valueInput.text = ""
                }
            }
        }
    }

    ListView {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom

        model: treeModel

        delegate: Item {
            width: parent.width

            Text {
                text: "Value: " + modelData.value
            }
        }
    }        Text {
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
                secondTreeWindow.hideMeCliked()}
        }

    function getTreeType(type){
        if (type===1) return timingBubbleSort
        else if (type===2) return timingSelectionSort
        }

    function getTree(type){
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
