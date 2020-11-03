pragma Singleton
import QtQuick 2.12

Item {
    property alias fontAwesome: fontAwesomeLoader
    readonly property color colourBackground: "#efefef"
    readonly property color colourNavigationBarBackground: "#000000"
    readonly property color colourNavigationBarFont: "#ffffff"
    readonly property int pixelSizeNavigationBarIcon: 42

    FontLoader {
        id: fontAwesomeLoader
        source: "qrc:/assets/fontawesome.ttf"
    }
}
