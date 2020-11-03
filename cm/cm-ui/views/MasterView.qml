import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import assets 1.0
import components 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Client Management")

    Connections {
        target: masterController.ui_navigationController
        onGoCreateClientView:
            contentFrame.replace("qrc:/views/CreateClientView.qml")
        onGoDashboardView:
            contentFrame.replace("qrc:/views/DashboardView.qml")
        onGoEditClientView:
            contentFrame.replace("qrc:/views/EditClientView.qml", {selectedClient: client})
        onGoFindClientView:
            contentFrame.replace("qrc:/views/FindClientView.qml")
    }

    StackView {
        id: contentFrame
        clip: true
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        initialItem: Qt.resolvedUrl("qrc:/views/SplashView.qml")
    }

    Rectangle {
        id: navigationBar
        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        width: 100
        color: "#000000"

        Column {
            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Dashboard"
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Client"
            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find Client"
            }
        }
    }

    Component.onCompleted: contentFrame.replace("qrc:/views/DashboardView.qml")
}
