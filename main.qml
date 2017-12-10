import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Window 2.3

//import asp.MediaController 1.0
//import "content"

ApplicationWindow {
    id: mainwindow

    visible: true

    Material.theme:  Material.Dark
    Material.accent: Material.Purple

    minimumWidth: 240
    minimumHeight: 320

    title: qsTr("ASP 0.1.3 beta")

    header: {

    }

    footer: {

    }
/*
    PlayerView {
        id: pl_view

    }

    MediaController {
        id: controller

        playbackRate: 1.0
        position: 0

        onPlaybackRateChanged: {

        }

        onStateChanged: {

        }


    }

    function keyPressed(key_id) {
        if (key_id === "play") {
            controller.play()
        }
        else if (key_id === "stop") {
            controller.stop()
        }
        else if (key_id === "forward") {
            //controller.forward()
        }
        else if (key_id === "backward") {
            //controller.backward()
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
*/
}
