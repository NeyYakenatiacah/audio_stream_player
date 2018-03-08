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

        spacing: 1

        anchors.fill: parent

        focus: true

        //snapMode: ListView.SnapToItem
        //boundsBehavior: Flickable.StopAtBounds
        orientation: ListView.Vertical
        //verticalLayoutDirection: ListView.TopToBottom
        //highlightFollowsCurrentItem: true

        model: media_manager.currentList.sources

        delegate: MediaSourceView {
            id: delegate

            width: media_list.width
            height: 30

            text_color: ListView.isCurrentItem ? settings.palette.highlightedText : settings.palette.text

            onClicked: {
                media_list.currentIndex = index
                controller.setMedia(media_manager.currentList.source(index))
            }
        }

        Connections {
            target: controller

            onForward: {
                media_list.currentIndex = media_list.currentIndex + 1
                controller.setMedia(media_manager.currentList.source(media_list.currentIndex))
                if(!controller.autoPlayMode) controller.play()
            }

            onBackward: {
                media_list.currentIndex = media_list.currentIndex - 1
                controller.setMedia(media_manager.currentList.source(media_list.currentIndex))
                if(!controller.autoPlayMode) controller.play()
            }

            onEnd: {
                console.log("Ended")
                controller.toForward()
            }
        }
    }

    function rebuilt() {
        plView.update()
    }
}
