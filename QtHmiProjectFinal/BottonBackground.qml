import QtQuick 2.0
import QtQuick.Controls 2.12
//import QtQuick.Timeline 1.0


Item{
    id: itemBottonBackground
    width: imgBottonBackground.width
    height: imgBottonBackground.height
    anchors.bottom: parent.bottom

    Image {
        id: imgBottonBackground
        x: 0
        y: 0

        source: "qrc:/images/botton-background.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: imgHighbeam
        anchors.bottom: imgBottonBackground.bottom
        anchors.bottomMargin: 35

        anchors.left: imgBottonBackground.left
        anchors.leftMargin: 35

        visible: true
        property bool isActive: false
        source: isActive ? "qrc:/images/lights_on.png" : "qrc:/images/lights_off.png"
        fillMode: Image.PreserveAspectFit

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


        Item {
            id: odometerValue
            width: 200
            height: 40
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: simbolOdometer

                anchors.right: odometerValue.right
                width: 44
                height: 40
                color: "#FFFFFF"
                text: "mi"
                horizontalAlignment: Text.AlignRight
                verticalAlignment: Text.AlignBottom
                font.pixelSize: 22
                font.family: "Cherry"
            }


            Text {
                id: odometerNumber
                width: 120
                height: 40
                color: "#FFFFFF"
                text: "0"
                horizontalAlignment: Text.AlignRight
                font.pixelSize: 32
                font.family: "Cherry"

//                Timeline {
//                    id: timeline3
//                    animations: [
//                        TimelineAnimation {
//                            id: route3
//                            to: 10000
//                            duration: 10000
//                            running: true
//                            loops: -1
//                            from: 0
//                        }
//                    ]
//                    startFrame: 0
//                    enabled: true
//                    endFrame: 10000

//                    KeyframeGroup {
//                        target: odometerNumber
//                        property: "text"

//                        Keyframe {
//                            value: 0
//                            frame: 0
//                        }

//                        Keyframe {
//                            value: 111111
//                            frame: 1000
//                        }

//                        Keyframe {
//                            value: 222222
//                            frame: 2000
//                        }

//                        Keyframe {
//                            value: 333333
//                            frame: 3000
//                        }

//                        Keyframe {
//                            value: 444444
//                            frame: 4000
//                        }

//                        Keyframe {
//                            value: 555555
//                            frame: 5000
//                        }

//                        Keyframe {
//                            value: 666666
//                            frame: 6000
//                        }

//                        Keyframe {
//                            value: 777777
//                            frame: 7000
//                        }

//                        Keyframe {
//                            value: 888888
//                            frame: 8000
//                        }

//                        Keyframe {
//                            value: 999999
//                            frame: 9000
//                        }

//                        Keyframe {
//                            value: 999999
//                            frame: 10000
//                        }
//                    }
//                }

            }
        }

}

