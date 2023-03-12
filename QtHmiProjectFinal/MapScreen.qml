import QtQuick 2.0

Item {
    width: 800
    height: 480

    Image {
        id: mapBackground
        x: 0
        y: 0
        source: "qrc:/images/google_map.png"
    }

    Item {
        id: root
        width: 800
        height: 480
        x: 0
        y: 0


        Item {
            id: pointer
            x: 345
            y: 338

            Image {
                id: circle
                visible: true
                source: "qrc:/images/blue_circle_gps_area.png"

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                Image {
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/images/map_location_arrow.png"
                }
            }
        }

    }

}

