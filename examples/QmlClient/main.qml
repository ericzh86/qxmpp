import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

import QtShark.Xmpp 1.0

Window {
    id: signWindow

    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        anchors.fill: parent

        TextInput {
            id: username

            Layout.fillWidth: true
            Layout.fillHeight: true

            text: "ericzh_1"
        }

        TextInput {
            id: password

            Layout.fillWidth: true
            Layout.fillHeight: true

            text: "215688650"
        }

        Button {
            Layout.fillWidth: true
            Layout.fillHeight: true

            onClicked: {
                Xmpp.connectToServer(username.text, password.text);
            }
        }
    }

    Connections {
        target: Xmpp
        onStateChanged: {
            if (Xmpp.state === Xmpp.ConnectedState) {
                mainWindowLoader.active = true;
                signWindow.visible = false;
            } else {
                mainWindowLoader.active = false;
                signWindow.visible = true;
            }
        }
    }

    Loader {
        id: mainWindowLoader
        active: false
        sourceComponent: MainWindow { }
    }
}
