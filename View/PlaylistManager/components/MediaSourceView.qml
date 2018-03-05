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

        GridLayout {
            id: grid

            columnSpacing: 2
            rowSpacing: 2

            Layout.fillWidth: true

            Text {
                id: mIdx

                Layout.row: 0
                Layout.column: 0

                Layout.rowSpan: 2
                Layout.columnSpan: 1

                Layout.fillWidth: true

                elide: Text.ElideMiddle
                color: delegate.text_color
                text: idx

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment:   Text.AlignVCenter
            }

            Text {
                id: mArtist

                Layout.row: 0
                Layout.column: 1

                Layout.rowSpan: 1
                Layout.columnSpan: 2

                Layout.fillWidth: true

                elide: Text.ElideMiddle
                color: delegate.text_color
                text: artist

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment:   Text.AlignVCenter
            }

            Text {
                id: mTitle

                Layout.row: 0
                Layout.column: 3

                Layout.rowSpan: 1
                Layout.columnSpan: 2

                Layout.fillWidth: true

                elide: Text.ElideMiddle
                color: delegate.text_color
                text: title

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment:   Text.AlignVCenter
            }

            Text {
                id: mDuration

                Layout.row: 0
                Layout.column: 5

                Layout.rowSpan: 1
                Layout.columnSpan: 1

                Layout.fillWidth: true

                elide: Text.ElideMiddle
                color: delegate.text_color
                text: time

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment:   Text.AlignVCenter
            }

            Text {
                id: mAlbum

                Layout.row: 1
                Layout.column: 1

                Layout.rowSpan: 1
                Layout.columnSpan: 2

                Layout.fillWidth: true

                elide: Text.ElideMiddle
                color: delegate.text_color
                text: album

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment:   Text.AlignVCenter
            }
        }
    }
}
