import QtQuick 2.10
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0
import asp.Palette 1.0

Item {
    Layout.minimumWidth:  48
    Layout.minimumHeight: 48

    Layout.preferredWidth:  64
    Layout.preferredHeight: 64

    Layout.maximumWidth: 80
    Layout.maximumHeight: 80

    Layout.fillWidth: true

    property color primaryColor:   settings.palette.button
    property color highlightColor: settings.palette.highlight
    property string image

    signal buttonClicked()

    Image {
        id: btn_img
        anchors.centerIn: parent
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
