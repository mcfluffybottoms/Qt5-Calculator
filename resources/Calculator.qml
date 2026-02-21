import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

Component {
    Item {
        id: calculatorWindow
        visible: true
        width: window.width
        height: window.height

        Rectangle {
            anchors.fill: parent
            color: "#024873"
            z: -100
        }

        Connections {
            target: calculator
            function onPasswordEntered() {
                if (window.secretComponent.status === Component.Ready) {
                    stackView.push(window.secretComponent.createObject(stackView))
                } else {
                    console.log("Error loading component:", window.secretComponent.errorString())
                }
            }
        }

        // status bar
        Item {
            id: statusBar
            width: calculatorWindow.width
            height: 24
            z: 10
            Image {
                id: statusBarImage
                width: calculatorWindow.width
                height: 24
                visible: true
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                    fill: parent
                }
                source: "qrc:/status_bar.png"
                fillMode: Image.PreserveAspectFit
            }
        }
        // DISPLAY
        Item {
            id: display
            width: parent.width
            height: 180
            z: 1
            Rectangle {
                id: displayFront
                width: display.width
                height: 180
                color: "#04BFAD"
                radius: 24
                z: 1

                anchors {
                    top: display.top
                    topMargin: 0
                    horizontalCenter: parent.horizontalCenter
                }
                
            }
            Rectangle {
                id: displayBack
                width: display.width
                height: 25
                color: "#04BFAD"
                z: 0
                anchors {
                    top: display.top
                    topMargin: 0
                    horizontalCenter: parent.horizontalCenter
                }
            }
            Item {
                id: displayText
                width: display.width
                height: display.height
                z: 10
                Text {
                    id: displayExpr
                    visible: true
                    text: calculator ? calculator.displayText : ""
                    anchors {
                        top: displayText.top
                        left: displayText.left
                        right: displayText.right
                        bottom: displayText.bottom
                        topMargin: 68
                        leftMargin: 39
                        rightMargin: 39
                    }
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignTop

                    maximumLineCount: 1
                    elide: Text.ElideLeft

                    font.family: "Open Sans"
                    color: "#FFFFFF"
                    font.pixelSize: 24
                    lineHeight: 30
                    font.weight: Font.DemiBold
                }
                Text {
                    id: displayAns
                    visible: true
                    text: calculator ? calculator.answerText : ""
                    anchors {
                        top: displayText.top
                        left: displayText.left
                        right: displayText.right
                        bottom: displayText.bottom
                        topMargin: 106
                        leftMargin: 39
                        rightMargin: 39
                    }
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignTop

                    maximumLineCount: 1
                    elide: Text.ElideRight

                    font.family: "Open Sans"
                    color: "#FFFFFF"
                    font.pixelSize: 50
                    lineHeight: 60
                    font.weight: Font.DemiBold
                }
            }
        }

        // PANEL
        Item {
            id: buttons
            width: 312
            height: 396
            anchors {
                top: parent.top
                bottom: parent.bottom
                left: parent.left
                right: parent.right
                topMargin: 204
                bottomMargin: 40
                leftMargin: 24
                rightMargin: 24
            }
            Column {
                spacing: 24
                Row {
                    spacing: 24
                    CalcButton { 
                        text: "()"; 
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425";
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/bkt.png"
                        onClicked: calculator.handleBracketChange(); 
                    }
                    CalcButton {
                        text: "+/-"; 
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425";
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/plus_minus.png"
                        onClicked: calculator.handleSignChange()
                    }
                    CalcButton { 
                        text: "%"; 
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425";
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/percent.png"
                        onClicked: calculator.handleOperator("%")
                    }
                    CalcButton { 
                        text: "÷"; 
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425";
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/division.png"
                        onClicked: calculator.handleOperator("/")
                    }
                }
                Row {
                    spacing: 24
                    CalcButton { text: "7"; onClicked: calculator.handleNumberClick(7) }
                    CalcButton { text: "8"; onClicked: calculator.handleNumberClick(8) }
                    CalcButton { text: "9"; onClicked: calculator.handleNumberClick(9) }
                    CalcButton { 
                        text: "×"; 
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425";
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/multiplication.png"; 
                        onClicked: calculator.handleOperator("*")
                    }
                }
                Row {
                    spacing: 24
                    CalcButton { text: "4"; onClicked: calculator.handleNumberClick(4) }
                    CalcButton { text: "5"; onClicked: calculator.handleNumberClick(5) }
                    CalcButton { text: "6"; onClicked: calculator.handleNumberClick(6) }
                    CalcButton { 
                        text: "-"; 
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425";
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/minus.png"; 
                        onClicked: calculator.handleOperator("-") 
                    }
                }
                Row {
                    spacing: 24
                    CalcButton { text: "1"; onClicked: calculator.handleNumberClick(1) }
                    CalcButton { text: "2"; onClicked: calculator.handleNumberClick(2) }
                    CalcButton { text: "3"; onClicked: calculator.handleNumberClick(3) }
                    CalcButton { 
                        text: "+"; 
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425";
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/plus.png"; 
                        onClicked: calculator.handleOperator("+") 
                    }
                }
                Row {
                    spacing: 24
                    CalcButton { 
                        text: "C"; 
                        normalColor: "#F25E5E"; 
                        pressedColor: "#F25E5E"; 
                        hoverColor: "#F25E5E"; 
                        textColor: "#FFFFFF";
                        colorOpacity: !this.hovered && !this.pressed ? 0.5 : 1.0; 
                        onClicked: calculator.handleClear() 
                    }
                    CalcButton { text: "0"; onClicked: calculator.handleNumberClick(0) }
                    CalcButton { text: "."; onClicked: calculator.handleNumberClick(".") }
                    SecretButton { 
                        text: "=";
                        pressSeconds: 4;
                        waitSeconds: 5;
                        normalColor: "#0889A6";
                        hoverColor: "#0889A6";
                        pressedColor: "#F7E425"; 
                        textColor: "#FFFFFF";
                        imageSource: "qrc:/icon/equal.png"; 
                        onClicked: calculator.handleSolver() 
                    }
                }
            }
        }
        

    }
}