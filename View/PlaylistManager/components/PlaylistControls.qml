import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import "../../Components/buttons"

Rectangle {
    id: frame
    z: 1000
    PlButton {
        id: add_btn

        width: 30
        height: 30

        anchors.left: frame.left
        anchors.bottom: frame.bottom
        anchors.top: frame.top

        Menu {
            id: add_menu

            x: add_btn.mapToItem(null, 0, 0).x
            y: -160

            MenuItem {
                text: "Add playlist"
                onClicked: impl.createPlaylist()
            }

            MenuItem {
                text: "Add single file"
                onClicked: impl.openSingleFile()
            }

            MenuItem {
                text: "Add multiple files"
                onClicked: impl.openMultipleFiles()
            }

            MenuItem {
                text: "Add folder"
                onClicked: impl.openFolder()
            }

            onOpened: {
                add_btn.press()
            }

            onClosed: {
                add_btn.release()
            }
        }

        image: "images/ic_add_white_48pt.png"

        onButtonClicked: {
            add_menu.open()
        }
    }
    PlButton {
        id: rem_btn

        width: 30
        height: 30

        anchors.left: add_btn.right
        anchors.bottom: frame.bottom
        anchors.top: frame.top

        image: "images/ic_remove_white_48pt.png"

        onButtonClicked: {
            var crd = add_btn.mapToItem(frame, 30, 30)
            console.log(crd.x)
            console.log(crd.y)

        }
    }






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

    QtObject {
        id: impl



        function openSingleFile() {
            file_dialog.title = qsTr("Open single media file")
            file_dialog.selectMultiple = false
            file_dialog.selectFolder = false
            file_dialog.open()
        }

        function openMultipleFiles() {
            file_dialog.title = qsTr("Open multiple media files")
            file_dialog.selectMultiple = true
            file_dialog.selectFolder = false
            file_dialog.open()
        }

        function openFolder() {
            file_dialog.title = qsTr("Open folder with media")
            file_dialog.selectMultiple = false
            file_dialog.selectFolder = true
            file_dialog.open()
        }

        function createPlaylist() {
            media_manager.createList()
        }
    }
}
