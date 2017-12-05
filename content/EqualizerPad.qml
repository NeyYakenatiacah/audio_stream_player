import QtQuick 2.9
import QtQuick.Controls 2.2

Rectangle {
    id: eq_pad

    Rectangle {
        anchors.top: parent.top
        width: parent.width

        Slider {
            id: bar_1
            width: 45
            height: 244

            from: -20
            to: 20

            anchors.left: parent.left
            anchors.leftMargin: 8
            orientation: Qt.Vertical




        }

        Slider {
            id: bar_2

            width: 45
            height: 244

            from: -20
            to: 20

            anchors.left: bar_1.right
            orientation: Qt.Vertical

        }
    }


}
