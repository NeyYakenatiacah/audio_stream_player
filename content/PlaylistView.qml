import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

Item {
    id: playlist

    ListView {
        id: media_list

        anchors.top: parent.top
        anchors.bottom: pl_numPad.top
        anchors.right: parent.right
        anchors.left: parent.left

        anchors.topMargin: 3
        anchors.bottomMargin: 3
        anchors.rightMargin: 3
        anchors.leftMargin: 3

        orientation: Qt.Vertical
        verticalLayoutDirection: ListView.TopToBottom

        Component {
            id: media_delegate

        }
    }

    Rectangle {
        id: pl_numPad

        height: 64

        anchors.right: parent.right
        anchors.rightMargin: 3

        anchors.left: parent.left
        anchors.leftMargin: 3

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 3

        Row {
            anchors.fill: parent

            Button {
                id: add_btn
                text: "+"
                height: parent.height
                width: parent.height
            }

            Button {
                id: rem_btn
                text: "-"
                height: parent.height
                width: parent.height
            }
        }
    }
}


