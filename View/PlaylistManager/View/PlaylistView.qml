import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2
import "../components"
Item {
    id: plView

    Rectangle {
        id: frame
        anchors.fill: parent
        radius: 3
        border.color: settings.palette.button
        color: "transparent"
    }

    ListView {
        id: media_list

        spacing: 2

        anchors.fill: parent

        focus: true

        snapMode: ListView.SnapToItem
        boundsBehavior: Flickable.StopAtBounds
        orientation: ListView.Vertical
        //verticalLayoutDirection: ListView.TopToBottom
        highlightFollowsCurrentItem: true

        model: media_manager.currentList.sources

        delegate: MediaSourceView {
            id: delegate

            width: media_list.width
            height: 50

            text_color: ListView.isCurrentItem ? settings.palette.highlightedText : settings.palette.text

            onClicked: {
                media_list.currentIndex = index
            }

            onDoubleClicked: {
                console.log("dc")
                controller.setMedia(media_manager.currentList.source(index))
                //controller.play()
            }
        }

    }

    function rebuilt() {
        plView.update()
    }
}
