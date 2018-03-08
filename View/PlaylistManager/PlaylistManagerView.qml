import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3

import "components"
import "Selector"
import "View"

Rectangle {
    id: media_list_manager

    FileDialog {
        id: file_dialog
        modality: Qt.WindowModal
        nameFilters: [ "Audio files (*.mp3 *.flac)", "All files (*)" ]
        selectedNameFilter: "All files (*)"
        sidebarVisible: false
        selectExisting: true

        onAccepted: {
            for(var i = 0; i < fileUrls.length; ++i) {
                media_manager.currentList.openLocalFile(fileUrls[i])
            }
        }
        onRejected: {
            console.log("Rejected...")
        }
    }

    PlaylistSelector {
        id: selector

        anchors.top: parent.top
        anchors.right: parent.right
        anchors.left: parent.left

        anchors.margins: 1

        color: settings.palette.window

        height: 30
    }

    PlaylistView {
        id: view

        anchors.top: selector.bottom
        anchors.bottom: controls.top
        anchors.left: parent.left
        anchors.right: parent.right

        anchors.margins: 1
    }

    PlaylistControls {
        id: controls

        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left

        color: "transparent"

        height: 30
    }



    QtObject {
        id: impl

        function openSingleFile() {
            file_dialog.title = qsTr("Open single media file")
            file_dialog.selectMultiple = false
            file_dialog.selectFolder = false
            file_dialog.open()
        }

        function createPlaylist() {
            media_manager.createList()
        }
    }



}
