import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ItemDelegate {
    id: delegate

    property int idx: index
    property string text_color

    anchors.margins: 3

    Rectangle {
        id: source_view

        color: "transparent"
        border.color: "white"
        border.width: 1

        anchors.fill: delegate
        anchors.margins: 3

        Text {
            id: mIdx

            anchors.bottom: source_view.bottom
            anchors.left: source_view.left
            anchors.top: source_view.top

            width: delegate.width / 10

            elide: Text.ElideMiddle
            color: delegate.text_color
            text: idx

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment:   Text.AlignVCenter
        }

        Text {
            id: mArtist

            anchors.left: mIdx.right
            anchors.top: source_view.top

            width: delegate.width * 0.35
            height: delegate.height * 0.5

            elide: Text.ElideLeft
            color: delegate.text_color
            text: artist

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment:   Text.AlignVCenter
        }

        Text {
            id: mAlbum

            anchors.left: mArtist.right
            anchors.top: source_view.top

            width: delegate.width * 0.35
            height: delegate.height * 0.5

            elide: Text.ElideRight
            color: delegate.text_color
            text: album

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment:   Text.AlignVCenter
        }

        Text {
            id: mDuration

            anchors.left: mAlbum.right
            anchors.right: source_view.right
            anchors.top: source_view.top

            height: delegate.height * 0.5

            elide: Text.ElideMiddle
            color: delegate.text_color
            text: time

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment:   Text.AlignVCenter
        }

        Text {
            id: mTitle

            anchors.left: mIdx.right
            anchors.bottom: source_view.bottom

            height: delegate.height * 0.5

            elide: Text.ElideLeft
            color: delegate.text_color
            text: title

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment:   Text.AlignVCenter
        }
    }
}
