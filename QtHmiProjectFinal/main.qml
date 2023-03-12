import QtQuick 2.12
import QtQuick.Window 2.12

Window {

    id: mainWindow
//    width: 800
//    height: 480
    visible: true
    title: qsTr("QtHmiProjectFinal")

    ScreenMoving {
        id: screenMoving
    }
    width: Screen.width
    height: Screen.height
    visibility:Window.FullScreen

//    flags: Qt.FramelessWindowHint | Qt.Window
//    color: "black"
//    visibility: Qt.WindowFullScreen // << the solution
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}
}
##^##*/
