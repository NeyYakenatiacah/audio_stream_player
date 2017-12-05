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

//    MediaController {
//        id: controller
//    }
}
