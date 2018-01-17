import QtQuick 2.10

Rectangle {
    id: source_view

    property int idx: index

    anchors.margins: 3

    width: parent.width
    height: 50

    border.color: settings.foreground
    border.width: 1

    Text {
        id: mTitle

        anchors.top: source_view.top
        anchors.left: source_view.left

        anchors.margins: 2

        color: settings.foreground
        text: media_manager.currentList.sources[idx].title
    }

    Text {
        id: mArtist

        anchors.top: mTitle.top
        anchors.left: source_view.left

        anchors.margins: 2

        color: settings.foreground
        text: media_manager.currentList.sources[idx].artist
    }

    Text {
        id: mDuration

        anchors.top: source_view.top
        anchors.bottom: source_view.bottom
        anchors.right: source_view.left

        anchors.margins: 2

        color: settings.foreground
        text: media_manager.currentList.sources[idx].duration
    }

    Text {
        id: mAlbum

        color: settings.foreground
        text: media_manager.currentList.sources[idx].album
    }

    MouseArea {
        id: sv_area
        anchors.fill: parent

        anchors.margins: -3

        onClicked: {
            media_manager.currentList.sources[idx].select
        }
    }
}
