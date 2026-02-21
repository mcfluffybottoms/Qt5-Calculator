import QtQuick 2.3
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

CalcButton {
    id: secretButton
    
    property int pressSeconds;
    property int waitSeconds;

    Timer {
        id: pressTimer;

        interval: pressSeconds * 1000;
        repeat: false;
        running: false;

        onTriggered: {
            console.log("ON")
            calculator.enableWaitingForPassword()
            waitTimer.running = true;
        }
    }

    Timer {
        id: waitTimer;

        interval: waitSeconds * 1000;
        repeat: false;
        running: false;

        onTriggered: {
            console.log("Off")
            calculator.disableWaitingForPassword()
        }
    }

    onPressedChanged: {
        if(pressed) {
            pressTimer.running = true;

        } else {
            pressTimer.running = false;
        }
    }
    
}