import QtQuick 2.10
import QtGraphicalEffects 1.0

Item {
    width:  100
    height: 100

    property color primaryColor
    property color highlightColor
    property string image

    signal buttonClicked()

    Image {
        id: btn_img
        source: image
        sourceSize: Qt.size(parent.width, parent.height)
        smooth: true
        visible: false
    }

    ColorOverlay {
        id: overlay
        anchors.fill: btn_img
        source: btn_img
        color: primaryColor
    }

    MouseArea {
        id: mouse_area
        anchors.fill: parent

        onPressed: {
            overlay.color = highlightColor
            overlay.update()
            buttonClicked()
        }

        onReleased: {
            overlay.color = primaryColor
        }
    }

    function setColor (color) {
        primaryColor = color
        highlightColor = Qt.lighter(color)
    }

    function setSource (path) {
        play_im.source = path
    }
}
