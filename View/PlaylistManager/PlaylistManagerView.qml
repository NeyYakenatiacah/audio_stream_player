import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3

import "components"

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

        height: 30
    }

    PlaylistControls {
        id: controls

        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left

        height: 50
    }

    /*Rectangle {
        id: button_bar

        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left

        height: 50
        //color: settings.palette.button



//        Grid {
//            id: button_grid

//            Button {
//                id: open_btn
//                text: qsTr("Single")
//                onClicked: impl.openSingleFile()
//            }

//            Button {
//                id: add_pl
//                text: qsTr("Add list")
//                onClicked: impl.createPlaylist()
//            }
//        }
    }*/

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
