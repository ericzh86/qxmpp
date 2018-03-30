import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import QtShark.Xmpp 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("WeChat")

    ListView {
        anchors.fill: parent
        model: Xmpp.contacts

        delegate: Item {
            width: parent.width
            height: 80

            Rectangle {
                anchors.fill: parent
                color: "red"
            }

            Text {
                anchors.centerIn: parent
                text: contactInfo.id
            }
        }
    }
}
