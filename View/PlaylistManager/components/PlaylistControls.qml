import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import "../../Components/buttons"

Rectangle {
    id: controls_rect

    RowLayout {
        id: row
        y: 176

        Layout.fillWidth: true

        anchors.fill: parent

//        anchors.bottom: parent.bottom

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

        PlButton {
            id: add_btn
            image: "images/ic_add_white_48pt.png"

            onButtonClicked: {
                //media_manager.createList()
                file_dialog.title = qsTr("Open single media file")
                file_dialog.selectMultiple = true
                file_dialog.selectFolder = false
                file_dialog.open()
            }
        }

        PlButton {
            id: rem_btn
            image: "images/ic_remove_white_48pt.png"
        }
    }
}
