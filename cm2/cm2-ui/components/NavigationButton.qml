import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import assets 1.0

Item {
    property alias iconCharacter: textIcon.text
    property alias description: textDescription.text
    property color hoverColour: Style.colourNavigationBarBackground

    signal navigationButtonClicked()

    width: parent.width
    height: Style.heightNavigationButton

    Rectangle {
        id: background
        anchors.fill: parent
        color: Style.colourNavigationBarBackground

        states: [
            State {
                name: "hover"
                PropertyChanges {
                    target: background
                    color: hoverColour
                }
            }
        ]

        Row {
            Text{
                id: textIcon
                width: Style.widthNavigationButtonIcon
                height: Style.heightNavigationButtonIcon
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font {
                    family: Style.fontAwesome
                    pixelSize: 42
                }
                color: Style.colourNavigationBarFont
                text: "\uf11a"
            }
            Text{
                id: textDescription
                width: Style.widthNavigationButtonDescription
                height: Style.heightNavigationButtonDescription
                verticalAlignment: Text.AlignVCenter
                color: Style.colourNavigationBarFont
                font.pixelSize: Style.pixelSizeNavigationBarText
                text: "set me!"
            }
        }

        MouseArea {
            anchors.fill: parent
            cursorShape: Qt.PointingHandCursor
            hoverEnabled: true
            onEntered: background.state = "hover"
            onExited: background.state = ""
            onClicked: navigationButtonClicked()
        }
    }
}
