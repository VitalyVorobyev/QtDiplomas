import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import components 1.0
import assets 1.0

Window {
    width: 1024
    height: 768
    visible: true
    title: qsTr("Client Manager")

    Connections {
        target: masterController.ui_navigationController
        function onGoAddDiplomaView() { contentFrame.replace("qrc:/views/AddDiplomaView.qml")}
        function onGoDashboardView() { contentFrame.replace("qrc:/views/DashboardView.qml")}
        function onGoEditDiplomaView() { contentFrame.replace("qrc:/views/EditDiplomaView.qml")}
        function onGoFindDiplomaView() { contentFrame.replace("qrc:/views/FindDiplomaView.qml")}
    }

    Component.onCompleted:
        contentFrame.replace("qrc:/views/DashboardView.qml")

    StackView {
        id: contentFrame
        anchors {
            top:parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        clip: true

        initialItem: Qt.resolvedUrl("qrc:/views/SplashView.qml")
    }

    NavigationBar {
        id: navigationBar
    }

}
