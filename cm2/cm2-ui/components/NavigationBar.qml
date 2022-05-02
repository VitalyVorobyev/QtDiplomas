import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import components 1.0
import assets 1.0

Item {
    property bool isCollapsed: true

    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.widthNavigationBarExpanded

    Rectangle {
        anchors.fill: parent
        color: Style.colourNavigationBarBackground
        clip: true

        Column {
            width: parent.width

            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColour: "#993333"
                onNavigationButtonClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "Home"
                hoverColour: "#dc8a00"
                onNavigationButtonClicked:
                    masterController.ui_navigationController.goDashboardView()
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "Add"
                hoverColour: "#dccd00"
                onNavigationButtonClicked:
                    masterController.ui_navigationController.goAddDiplomaView()
            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find"
                hoverColour: "#8aef63"
                onNavigationButtonClicked:
                    masterController.ui_navigationController.goFindDiplomaView()
            }
        }
    }
}
