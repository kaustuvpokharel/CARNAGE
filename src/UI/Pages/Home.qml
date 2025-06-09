import QtQuick
import QtQuick.Controls
import CARNAGE 1.0

Page
{
    ComboBox
    {
        id: ifaceCombo
        width: parent.width
        model: AppController.interfaces

        onCurrentIndexChanged:
        {
            console.log("Selected interface:", ifaceCombo.currentText)
            //AppController.startCapture(ifaceCombo.currentText)
        }

        Component.onCompleted:
        {
            console.log("Available interfaces:", AppController.interfaces)
        }
    }
}
