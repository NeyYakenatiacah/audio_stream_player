import QtQuick 2.10
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

//    PlaylistView {
//        id: pls_view

//        anchors.fill: parent
//    }

}
