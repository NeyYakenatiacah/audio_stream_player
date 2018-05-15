import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ItemDelegate {
    id: delegate

    property string color

    checkable: true

    Rectangle {
        id: delegate_frame

        Rectangle {
            anchors.bottom: delegate_frame.bottom
            anchors.top: delegate_frame.top
            anchors.left: delegate_frame.left
            width: 1
            color: delegate.color
        }

        Rectangle {
            anchors.bottom: delegate_frame.bottom
            anchors.right: delegate_frame.right
            anchors.left: delegate_frame.left
            height: 2
            color: delegate.color
        }

        Rectangle {
            anchors.bottom: delegate_frame.bottom
            anchors.top: delegate_frame.top
            anchors.right: delegate_frame.right
            width: 1
            color: delegate.color
        }

        anchors.fill: parent

        color: "transparent"

        //radius: 3

        //border.width: 1
        //border.color: delegate.color

        //visible: false

        Text {
            id: delegate_text

            anchors.fill: parent
            anchors.margins: 2

            elide: Text.ElideMiddle

            text: modelData

            font.italic: true
            font.pixelSize: 12
            color: delegate.color

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment:   Text.AlignVCenter
        }

        MouseArea {
            id: area
            anchors.fill: parent
            acceptedButtons: Qt.RightButton

            onClicked: {
                media_manager.rename(modelData, "privet")
                console.log("right on selectord")
            }
        }
    }
}
