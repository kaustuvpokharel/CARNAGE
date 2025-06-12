import QtQuick
import QtQuick.Controls
import "../Pages"

Window {
    width: 1920
    height: 1080
    visible: true
    title: qsTr("CARNAGE")

    StackView
    {
        id: mainStack
        anchors.fill: parent
        initialItem: loginScreen

        replaceEnter: Transition
        {
            PropertyAnimation
            {
                property: "opacity"
                from:0
                to: 1
                duration: 300 //this is in ms which is millisecond
            }
        }
        replaceExit: Transition
        {
            PropertyAnimation
            {
                property: "opacity"
                from:1
                to: 0
                duration: 300 //this is in ms which is millisecond
            }
        }
    }

    Component
    {
        id: loginScreen
        Login
        {
            onLoginSuccessful:
            {
                console.log("Login Successful: Need to give access to the application");
                mainStack.replace(home);
            }
        }
    }

    Component
    {
        id: home
        Home
        {

            //For inplementation placeholder for my pages later on
        }
    }
}
