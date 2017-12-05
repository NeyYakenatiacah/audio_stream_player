import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Rectangle {
    id: rectangle
    width: 400
    height: 200

    Dial {
        id: volume_dial

        width: 64
        height: 64

        anchors.right: parent.right
        anchors.rightMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8

        value: 40
        to: 100
    }

    Dial {
        id: pb_rate_dial

        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8

        width: 64
        height: 64

        value: 1.0
        from: 0.0
        to: 2.0
    }

    Rectangle {
        id: rectangle1

        anchors.right: volume_dial.left
        anchors.rightMargin: 10
        anchors.left: pb_rate_dial.right
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8

        height: 64

        Row {
            id: row

            spacing: 5

            anchors.right: parent.right
            anchors.rightMargin: 3
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.leftMargin: 3
            anchors.bottomMargin: 3
            anchors.topMargin: 3

            RoundButton {
                id: backward_btn

                anchors.leftMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                anchors.topMargin: 3

                width: parent.height - 6
                height: width
            }

            RoundButton {
                id: play_btn

                anchors.leftMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                anchors.topMargin: 3

                width: parent.height - 6
                height: width
            }

            RoundButton {
                id: stop_btn

                anchors.leftMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                anchors.topMargin: 3

                width: parent.height - 6
                height: width
            }

            RoundButton {
                id: forward_btn

                anchors.leftMargin: 3
                anchors.rightMargin: 3
                anchors.bottomMargin: 3
                anchors.topMargin: 3

                width: parent.height - 6
                height: width

                onClicked: {

                }
            }
        }
    }

    Column {
        id: column
        x: 8
        y: 8
        width: 384
        height: 114
    }

}
