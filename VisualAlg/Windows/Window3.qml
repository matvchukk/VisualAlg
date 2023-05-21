import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle{
    signal hideMeCliked()
    id: secondDialog
    visible: true
    width: parent.width
    height: parent.height
    anchors.centerIn: parent
    color: "green"

    Button{
        id: back
        anchors.bottom: parent.bottom
        text: "Back"
        onClicked: secondDialog.hideMeCliked()
    }
}
