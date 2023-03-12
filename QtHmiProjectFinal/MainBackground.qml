import QtQuick 2.0
//import QtQuick.Timeline 1.0

Item {
    width: 800
    height: 480

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
            rotation: 0
            fillMode: Image.PreserveAspectFit

            SequentialAnimation {
                id: playArrowLeft
                running: true
                loops: Animation.Infinite
                NumberAnimation {
                    target: arrowLeft
                    property: "rotation"
                    from: 0
                    to: 90
                    duration: 3000
                }
                NumberAnimation {
                    target: arrowLeft
                    property: "rotation"
                    from: 90
                    to: 0
                    duration: 3000
                }
            }
        }

        Image {
            id: rightBackground
            x: 255
            y: 25

            source: "qrc:/images/right-arc-main.png"
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: arrowRight
            x: 292
            y: 56
            // -5 to 265
            source: "qrc:/images/arrow-right-main.png"
            rotation: 265
            fillMode: Image.PreserveAspectFit

            SequentialAnimation {
                id: playArrowRight
                running: true
                loops: Animation.Infinite
                NumberAnimation {
                    target: arrowRight
                    property: "rotation"
                    from: 265
                    to: 353
                    duration: 3000
                }
                NumberAnimation {
                    target: arrowRight
                    property: "rotation"
                    from: 353
                    to: 265
                    duration: 3000
                }
            }
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
            text: "100"
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 62
            font.family: "Cherry"

//            Timeline {
//                id: timeline
//                animations: [
//                    TimelineAnimation {
//                        id: route
//                        to: 10000
//                        duration: 6000
//                        running: true
//                        loops: -1
//                        from: 0
//                    }
//                ]
//                startFrame: 0
//                enabled: true
//                endFrame: 10000

//                KeyframeGroup {
//                    target: batteryPercetagemNumber
//                    property: "text"

//                    Keyframe {
//                        value: 100
//                        frame: 0
//                    }

//                    Keyframe {
//                        value: 90
//                        frame: 500
//                    }

//                    Keyframe {
//                        value: 80
//                        frame: 1000
//                    }

//                    Keyframe {
//                        value: 70
//                        frame: 1500
//                    }

//                    Keyframe {
//                        value: 60
//                        frame: 2000
//                    }

//                    Keyframe {
//                        value: 50
//                        frame: 2500
//                    }

//                    Keyframe {
//                        value: 40
//                        frame: 3000
//                    }

//                    Keyframe {
//                        value: 30
//                        frame: 3500
//                    }

//                    Keyframe {
//                        value: 20
//                        frame: 4000
//                    }

//                    Keyframe {
//                        value: 10
//                        frame: 4500
//                    }

//                    Keyframe {
//                        value: 00
//                        frame: 5000
//                    }

//                    Keyframe {
//                        value: 10
//                        frame: 5500
//                    }

//                    Keyframe {
//                        value: 20
//                        frame: 6000
//                    }

//                    Keyframe {
//                        value: 30
//                        frame: 6500
//                    }

//                    Keyframe {
//                        value: 40
//                        frame: 7000
//                    }

//                    Keyframe {
//                        value: 50
//                        frame: 7500
//                    }

//                    Keyframe {
//                        value: 60
//                        frame: 8000
//                    }

//                    Keyframe {
//                        value: 70
//                        frame: 8500
//                    }

//                    Keyframe {
//                        value: 80
//                        frame: 9000
//                    }

//                    Keyframe {
//                        value: 90
//                        frame: 9500
//                    }

//                    Keyframe {
//                        value: 99
//                        frame: 10000
//                    }
//                }
//            }

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
            text: "899"
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 62
            font.family: "Cherry"

//            Timeline {
//                id: timeline2
//                animations: [
//                    TimelineAnimation {
//                        id: route2
//                        to: 10000
//                        duration: 6000
//                        running: true
//                        loops: -1
//                        from: 0
//                    }
//                ]
//                startFrame: 0
//                enabled: true
//                endFrame: 10000

//                KeyframeGroup {
//                    target: speedNumber
//                    property: "text"

//                    Keyframe {
//                        value: 0
//                        frame: 0
//                    }

//                    Keyframe {
//                        value: 10
//                        frame: 769
//                    }

//                    Keyframe {
//                        value: 20
//                        frame: 1538
//                    }

//                    Keyframe {
//                        value: 30
//                        frame: 2307
//                    }

//                    Keyframe {
//                        value: 40
//                        frame: 3076
//                    }

//                    Keyframe {
//                        value: 50
//                        frame: 3845
//                    }

//                    Keyframe {
//                        value: 60
//                        frame: 4614
//                    }

//                    Keyframe {
//                        value: 50
//                        frame: 5383
//                    }

//                    Keyframe {
//                        value: 40
//                        frame: 6152
//                    }

//                    Keyframe {
//                        value: 30
//                        frame: 6921
//                    }

//                    Keyframe {
//                        value: 20
//                        frame: 7690
//                    }

//                    Keyframe {
//                        value: 10
//                        frame: 8459
//                    }

//                    Keyframe {
//                        value: 5
//                        frame: 9228
//                    }

//                    Keyframe {
//                        value: 0
//                        frame: 10000
//                    }
//                }
//            }

        }
    }

}

