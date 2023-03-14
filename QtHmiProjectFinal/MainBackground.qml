import QtQuick 2.0
import AnimationToNumbersClass 1.0

Item {
    width: 800
    height: 480

    AnimationToNumbers{
        id: animationToNumbers
    }

    Image {
        id: imgMainScreenBackground
        x: 0
        y: 0
        width: 800
        height: 480

        source: "qrc:/images/background.png"
        fillMode: Image.PreserveAspectFit
    }

    Item {
        id: imgMainScreenSpeedBatteryBackground
        x: 80
        y: 20
        width: 640
        height: 390
        visible: true

        Image {
            id: leftBackground
            x: 32
            y: 24

            source: "qrc:/images/left-arc-main.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: arrowLeft
            x: 81
            y: 74

            source: "qrc:/images/arrow-left-main.png"
            rotation: animationToNumbers.OdoAnalogIncreaseVar
            fillMode: Image.PreserveAspectFit

        }

        Image {
            id: rightBackgroundRed
            x: 255
            y: 25

            source: animationToNumbers.AlertLowBatteryVar
            fillMode: Image.PreserveAspectFit
        }


        Image {
            id: arrowRight
            x: 292
            y: 56
            // -5 to 265
            source: "qrc:/images/arrow-right-main.png"
            rotation: animationToNumbers.OdoAnalogIncreaseVar - 90
            fillMode: Image.PreserveAspectFit

        }
    }

    BikeImage {
        id: bikeImage
    }

    Item {
        id: batteryPercetagem
        width: 149
        height: 74
        x: 444
        y: 298

        Text {
            id: batteryPercetagemNumber
            anchors.left: batteryPercetagem.left
            width: 115
            height: 82
            color: "#FFFFFF"
            text: animationToNumbers.BatteryIncreaseVar
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 62
            font.family: "Cherry"

        }

        Text {
            id: simbolpercetagem

            anchors.right: batteryPercetagem.right
            anchors.bottom: batteryPercetagem.bottom
            width: 44
            height: 40
            color: "#FFFFFF"
            text: "%"
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 32
            font.family: "Cherry"
        }
    }

    Item {
        id: speedValue
        width: 149
        height: 74
        x: 208
        y: 298

        Text {
            id: simbolSpeed

            anchors.right: speedValue.right
            anchors.bottom: speedValue.bottom
            width: 44
            height: 40
            color: "#FFFFFF"
            text: "mi"
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 32
            font.family: "Cherry"
        }

        Text {
            id: speedNumber
            anchors.left: speedValue.left
            width: 115
            height: 82
            color: "#FFFFFF"
            text: animationToNumbers.SpeedIncreaseVar
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 62
            font.family: "Cherry"

        }
    }

}

