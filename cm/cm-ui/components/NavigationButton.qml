import QtQuick 2.12
import assets 1.0

Item {
    property alias iconCharacter: textIcon.text
    property alias description: textDescription.text

    Row {
        Text {
            id: textIcon
            font {
                family: Style.fontAwesome
                pixelSize: 42
            }
            color: "#ffffff"
            text: "\uf234"
        }
        Text {
            id: textDescription
            color: "#ffffff"
            text: "New Client"
        }
    }
}
