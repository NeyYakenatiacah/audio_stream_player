import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

ListView {
    id: media_list

    model: media_manager.currentList.sources

    anchors.topMargin: 3
    anchors.bottomMargin: 3
    anchors.rightMargin: 3
    anchors.leftMargin: 3

    orientation: Qt.Vertical
    verticalLayoutDirection: ListView.TopToBottom

}
