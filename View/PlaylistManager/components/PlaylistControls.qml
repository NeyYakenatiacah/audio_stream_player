import QtQuick 2.9
import QtQuick.Layouts 1.3

import "../../Components/buttons"

Rectangle {
    id: controls_rect

    RowLayout {
        id: row
        y: 176

        Layout.fillWidth: true

        anchors.fill: parent

//        anchors.bottom: parent.bottom

        PlButton {
            id: add_btn
            image: "images/ic_add_white_48pt.png"

            onButtonClicked: {
                media_manager.createList()
            }
        }

        PlButton {
            id: rem_btn
            image: "images/ic_remove_white_48pt.png"
        }
    }
}
