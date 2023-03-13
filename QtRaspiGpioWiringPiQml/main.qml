import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 800
    height: 480
    visible: true
    title: qsTr("Hello World")

//    Button {
//        id: button
//        x: 224
//        y: 95
//        width: 367
//        height: 293

//        property bool isActive: false

//        Image {
//            id: image
//            anchors.fill: parent
//            source: isActive ? "qrc:/images/led-on.png" : "qrc:/images/led-off.png"
//            fillMode: Image.PreserveAspectFit
//        }

//        onClicked: {
//            isActive = !isActive
//        }

//    }

    Rectangle {
        width: 300
        height: 300

        border.color: "#000000"
        border.width: 5
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter



    Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit

            visible: true
            property bool isActive: false
            source: isActive ? "qrc:/images/led-off.png" : "qrc:/images/led-on.png"

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked:{
                    parent.isActive = !parent.isActive

                    if(parent.isActive)
                        output.pinHigh();
                    else
                        output.pinLow();
                        }
                    }
        }
    }

}
