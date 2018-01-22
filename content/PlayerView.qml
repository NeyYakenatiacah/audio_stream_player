import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Layouts 1.3
import "buttons"

Rectangle {
    id: playerView

    width: parent.width
    height: 250
    anchors.margins: 3

    border.color: settings.palette.button
    border.width: 1

    color: "transparent"


//    DisplayView {
//        id: dView
//        height: 80

//        anchors.top: parent.top
//        anchors.right: parent.right
//        anchors.left: parent.left
//    }

    RowLayout {
        id: row_layout
        y: 176

        Layout.fillWidth: true

        anchors.left:  parent.left
        anchors.right: parent.right

        height: 74
        anchors.rightMargin: 3
        anchors.leftMargin: 3
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3

        PlButton {
            id: bw_button
            image: "images/ic_fast_rewind_white_48pt.png"

            onButtonClicked: {
                controller.toBackward()
            }
        }

        PlButton {
            id: play_button
            image: "images/ic_play_arrow_white_48pt.png"

            onButtonClicked: {
                controller.play()
            }
        }

        PlButton {
            id: stop_button
            image: "images/ic_stop_white_48pt.png"

            onButtonClicked: {
                controller.stop()
            }
        }

        PlButton {
            id: fw_button
            image: "images/ic_fast_forward_white_48pt.png"

            onButtonClicked: {
                controller.toForward()
            }
        }
    }

    Connections {
        target: controller
        onPlaying: {
            play_button.image = "images/ic_pause_white_48pt.png"
        }
        onPaused: {
            play_button.image = "images/ic_play_arrow_white_48pt.png"
        }
        onStopped: {
            play_button.image = "images/ic_play_arrow_white_48pt.png"
        }
    }
}
