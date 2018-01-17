import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Rectangle {
    id: playerView

    width: 360
    height: 150
    anchors.margins: 3

    color: "#b2ea81"


    DisplayView {
        id: dView
        height: 80

        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left
    }


    Row {
        id: row
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        spacing: 5

        anchors.top: dView.bottom
        anchors.topMargin: 0

        anchors.right: parent.right
        anchors.left: parent.left

        onWidthChanged: {
            if(row.width < (row.height - 6) * 6) {

                var bSize = row.width / 6 - 6

                volume_dial.width  = bSize
                volume_dial.height = bSize

                pb_rate_dial.width  = bSize
                pb_rate_dial.height = bSize

                play_btn.width  = bSize
                play_btn.height = bSize
                stop_btn.width  = bSize
                stop_btn.height = bSize

                forward_btn.width  = bSize
                forward_btn.height = bSize
                backward_btn.width  = bSize
                backward_btn.height = bSize

            } else {

                volume_dial.width  = row.height - 6
                volume_dial.height = row.height - 6

                pb_rate_dial.width  = row.height - 6
                pb_rate_dial.height = row.height - 6

                play_btn.width  = row.height - 6
                play_btn.height = row.height - 6
                stop_btn.width  = row.height - 6
                stop_btn.height = row.height - 6

                forward_btn.width  = row.height - 6
                forward_btn.height = row.height - 6
                backward_btn.width  = row.height - 6
                backward_btn.height = row.height - 6
            }
        }

        Dial {
            id: volume_dial

            width: parent.height - 6
            height: width

            anchors.leftMargin: 3
            anchors.rightMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3

            value: 40
            to: 100

            onMoved: controller.volume = volume_dial.value
        }

        RoundButton {
            id: backward_btn

            anchors.leftMargin: 3
            anchors.rightMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3

            width: parent.height - 6
            height: width

            onClicked: controller.toBackward()
        }

        RoundButton {
            id: play_btn

            anchors.leftMargin: 3
            anchors.rightMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3

            width: parent.height - 6
            height: width

            onClicked: controller.play()
        }

        RoundButton {
            id: stop_btn

            anchors.leftMargin: 3
            anchors.rightMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3

            width: parent.height - 6
            height: width

            onClicked: controller.stop()
        }

        RoundButton {
            id: forward_btn

            anchors.leftMargin: 3
            anchors.rightMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3

            width: parent.height - 6
            height: width

            onClicked: controller.toForward()
        }

        Dial {
            id: pb_rate_dial

            anchors.leftMargin: 3
            anchors.rightMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3

            width: parent.height - 6
            height: width

            value: 1.0
            from: 0.0
            to: 2.0

            onMoved: controller.playbackRate = pb_rate_dial.value
        }
    }





}
