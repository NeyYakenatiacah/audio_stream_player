import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Window 2.3

ListView {
    id: media_list_manager

    PlayerView {
        id: media_view
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

    Button {
        id: open_btn
        text: qsTr("Single")
        onClicked: openSingleFile()
    }

    function openSingleFile() {
        file_dialog.title = qsTr("Open single media file")
        file_dialog.selectMultiple = false
        file_dialog.selectFolder = false
        file_dialog.open()
    }

}
