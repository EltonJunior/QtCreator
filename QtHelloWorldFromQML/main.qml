import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow
    width: 300
    height: 100
    visible: true
    title: qsTr("Hello World")


    Text {
    id: txtHelloWorld
    text: qsTr("<center>HELLO WORLD from qtQML by ELTON</center>")

    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignHCenter
    anchors {
//        left: parent.left
        verticalCenter: parent.verticalCenter
        horizontalCenter: parent.horizontalCenter
    }
    }

}
