import QtQuick 2.9

Rectangle {
    id: selector
    //color: settings.palette.button

    signal playlistSelected()

    property string selectedPlaylistName

    ListView {
        id: selector_list_view

        anchors.fill: parent

        snapMode: ListView.SnapToItem
        boundsBehavior: Flickable.StopAtBounds
        orientation: ListView.Horizontal

        model: media_manager.names

        delegate: Rectangle {


            //height: parent.height
            color: settings.palette.highlight
            border.color: settings.palette.highlight
            border.width: 1

            Text {
                id: item_text
                color: settings.palette.button
                text: modelData
            }
        }

        onCurrentIndexChanged: {
            selector.selectedPlaylistName = media_manager.names[selector_list_view.currentIndex]
        }
    }

}
