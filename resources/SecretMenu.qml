import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

Component {
    Item {
        id: secretWindow
        visible: true
        width: window.width
        height: window.height

        Rectangle {
            anchors.fill: parent
            color: "#024873"
            z: -100
        }

        Text {
            id: secretWindowText
            visible: true
            text: "Секретное меню"
            z: 10

            anchors {
                top: secretWindow.top
                left: secretWindow.left
                right: secretWindow.right
                bottom: secretWindow.bottom
            }

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

            font.family: "Open Sans"
            color: "#FFFFFF"
            font.pixelSize: 24
            lineHeight: 30
            font.weight: Font.DemiBold
        
        }

        CalcButton { 
            text: "<"; 
            textColor: "#FFFFFF";

            width: 60
            height: 60
            
            anchors {
                left: secretWindow.left
                bottom: secretWindow.bottom
                bottomMargin: 24
                leftMargin: 24
            }

            onClicked: stackView.pop()
        }
    }
}