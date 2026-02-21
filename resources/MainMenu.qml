import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

ApplicationWindow {
    id: window
    title: "Calculator"
    visible: true

    width: 360
    height: 630
    minimumWidth: 360
    minimumHeight:  630
    maximumWidth: 360
    maximumHeight: 630
    flags: Qt.Window | Qt.WindowTitleHint | 
           Qt.WindowCloseButtonHint

    property var mainComponent: null
    property var secretComponent: null

    Component.onCompleted: {
        // mainComponent
        mainComponent = Qt.createComponent("Calculator.qml")
        if (mainComponent.status === Component.Ready) {
            stackView.push(mainComponent.createObject(stackView))
        } else {
            console.log("Error loading component:", mainComponent.errorString())
        }

       // secretComponent
        secretComponent = Qt.createComponent("SecretMenu.qml")
    }

    StackView {
        id: stackView
        anchors.fill: parent
    }
}