import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Client Management")

    StackView {
        id: contentFrame
        anchors.fill: parent
        initialItem: Qt.resolvedUrl("qrc:/views/SplashView.qml")
    }
}
