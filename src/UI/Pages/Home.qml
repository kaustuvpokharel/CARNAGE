import QtQuick
import QtQuick.Controls
import "../Components"
import CARNAGE 1.0

Item
{
    id: home

    Rectangle
    {

        id:background
        anchors.fill: parent
        color: "#121212"
        // Image
        // {
        //     source: "qrc:/images/Assets/images/loginBg.jpg"
        //     anchors.fill: parent
        //     fillMode: Image.PreserveAspectCrop
        //     opacity: 0.2
        // }
    }

    Header
    {
        id: headerComp
        anchors.fill: parent
    }
}
