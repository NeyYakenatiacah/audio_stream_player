import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ItemDelegate {
    id: delegate

    property string color

    checkable: true

    Rectangle {
        id: delegate_frame

        anchors.fill: parent

        color: "transparent"

        radius: 3

        border.width: 1
        border.color: delegate.color

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
    }
}
