import QtQuick 2.9

Item {
    id: source_view

    property int idx: -1

    width: parent.width
    height: 50

    Text {
        id: textItem
    }

    MouseArea {
        id: sv_area
        anchors.fill: parent
        anchors.margins: -3

        onClicked: {

        }
    }
}
