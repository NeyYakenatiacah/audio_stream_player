import QtQuick 2.9

Rectangle {
    id: selector

    z: 1000



    ListView {
        id: selector_list_view
        //z: parent.z
        spacing: 3

        anchors.fill: parent

        focus: true

        snapMode: ListView.SnapToItem
        boundsBehavior: Flickable.StopAtBounds
        orientation: ListView.Horizontal

        highlightFollowsCurrentItem: true

        model: media_manager.names

        delegate: SelectorDelegate {
            id: delegate

            width: 100
            height: parent.height

            color: ListView.isCurrentItem ? settings.palette.highlightedText : settings.palette.text

            onClicked: selector_list_view.currentIndex = index
        }

        onCurrentIndexChanged: {
            media_manager.select (media_manager.names[selector_list_view.currentIndex])
        }
    }

    Connections {
        target: media_manager
        onCurrentListChanged: {
            var idx = media_manager.currentIdx()
            if(idx !== -1) selector_list_view.currentIndex = idx
        }
    }
}
