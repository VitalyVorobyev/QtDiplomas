import QtQuick 2.15
import assets 1.0

Item {
    id: columnWithRectangle
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackground
        Text {
            anchors.centerIn: parent
            text: "Splash View"
        }
    }
}
