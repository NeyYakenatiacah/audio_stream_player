import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import QtQuick.Window 2.3

//import asp.MediaController 1.0
import "content"

ApplicationWindow {
    id: mainwindow
    visible: true
    //flags: Qt.FramelessWindowHint

    readonly property int dpi: Screen.pixelDensity * 25.4
    function dp(x) {
        return (dpi < 120) ? x : x*(dpi/160);
    }

    Material.theme:  Material.Dark
    Material.accent: Material.Purple

    minimumWidth: 180
    minimumHeight: 320

    title: qsTr("ASP 0.0.1 beta")

    header: Text {

        height: dp(48)
        text: qsTr("Header")


    }

    footer: Item {
        id: iFooter

        width: parent.width
        height: dp(32)

        Rectangle {
            id: playlist_footer
            color: "#e42424"
            visible: true


            anchors.fill: iFooter
        }

        function setPlaylistMode () {
            playlist_footer.visible = true
        }

        function setDefaultMode () {

        }
    }

    Drawer {
        id: drawer
        width: 0.5 * mainwindow.width
        height: mainwindow.height
    }


    PlayerView {
        id: pl_view

    }
/*
    MediaController {
        id: controller

        playbackRate: 1.0
        position: 0

        onPlaybackRateChanged: {

        }

        onStateChanged: {

        }


    }
*/
    function keyPressed(key_id) {
        if (key_id === "play") {
            controller.play()
        }
        else if (key_id === "stop") {
            controller.stop()
        }
        else if (key_id === "forward") {
            controller.toForward()
        }
        else if (key_id === "backward") {
            controller.toBackward()
        }
    }

    function playbackRate() {
        return controller.playbackRate()
    }

    function position() {
        return controller.position()
    }

    function setPosition(pos) {
        controller.position = pos
    }

    function setPlaybackRate(rate) {
        controller.playbackRate = rate
    }

}
