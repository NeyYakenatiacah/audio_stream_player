import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import "buttons"

Rectangle {
    id: playerView

    width: 360
    height: 150
    anchors.margins: 3

    color: "#b2ea81"


//    DisplayView {
//        id: dView
//        height: 80

//        anchors.top: parent.top
//        anchors.right: parent.right
//        anchors.left: parent.left
//    }


   Row {
        id: row
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        spacing: 5

        //anchors.top: dView.bottom
        anchors.top: parent.top
        anchors.topMargin: 0

        anchors.right: parent.right
        anchors.left: parent.left


        PlButton {
            id: play_button
            image: "images/play.png"

            onButtonClicked: {
                controller.play()
            }
        }

        PlButton {
            id: stop_button
            image: "images/stop.png"

            onButtonClicked: {
                controller.stop()
            }
        }
    }




}
