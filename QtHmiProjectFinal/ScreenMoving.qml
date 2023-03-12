import QtQuick 2.0


Item {
    id: principal
    width: 800
    height: 480
    x: 0
    y: 0



    Item{
        id: mainScreenMoving
        width: 800 * 2
        height: 480
        x: 0
        y: 0

        MainBackground {
            id: mainBackground
            visible: true
            x: 0
            y: 0
        }

        MapScreen{
            id: mapScreen
            x:800
            y:0
        }

        PropertyAnimation{
            id: animationRight
            target: mainScreenMoving
            property: "x"
            to: -800
            duration: 500
        }
        PropertyAnimation{
            id: animationLeft
            target: mainScreenMoving
            property: "x"
            to: 0
            duration: 500
        }


    }

    BottonBackground {
        id: bottonBackground
    }

    Image {
        id: imgBottonnavigation
        x: 682
        y: 365

        visible: true
        property bool isNavActive: false
        source: isNavActive ? "../images/no-nav-nodir.png" : "../images/nav_nodir.png"
        fillMode: Image.PreserveAspectFit

        MouseArea {
            id: mouseNavArea
            anchors.fill: parent
            onClicked: {
                parent.isNavActive = !parent.isNavActive
                if(mainScreenMoving.x === 0)
                {
                    animationRight.start()
                    bikeImage.visible = true
                }
                else
                {
                    animationLeft.start()
                    bikeImage.visible = false
                }
            }
        }

        BikeImage {
            id: bikeImage
            x:  0
            y:  0

            width: 100
            visible: false
        }
    }

}
