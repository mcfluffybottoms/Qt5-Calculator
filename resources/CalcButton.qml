import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

RoundButton {
    id: button
    width: 60
    height: 60
    
    property color normalColor: "#B0D1D8"
    property color hoverColor: "#B0D1D8"
    property color pressedColor: "#3d8b40"
    property color textColor: "#024873"
    property color bgColor: "#FFFFFF"
    property double colorOpacity: 1.0

    property string imageSource: ""
    property int imageWidth: 30
    property int imageHeight: 30
    
    background: Item {
        Rectangle {
            anchors.fill: parent
            z: -1
            radius: width / 2
            color: bgColor
        }
        Rectangle {
            anchors.fill: parent
            z: 10
            opacity: colorOpacity
            radius: width / 2
            color: button.pressed ? pressedColor : 
               button.hovered ? hoverColor : normalColor
        }
    }
    contentItem: Item {
        Text {
            anchors {
                centerIn: parent
            }
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            text: button.text
            font.family: "Open Sans"
            color: button.textColor
            font.pixelSize: 24
            lineHeight: 30
            font.weight: Font.DemiBold
            visible: button.imageSource == ""
        }

        Image {
            anchors.centerIn: parent
            
            source: button.imageSource
            width: button.imageWidth
            height: button.imageHeight
            fillMode: Image.PreserveAspectFit
            visible: button.imageSource != ""
        }
    } 
    
}