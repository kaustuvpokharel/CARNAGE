import QtQuick
import QtQuick.Layouts
import CARNAGE 1.0

Item{

    Rectangle
    {
        id: headerArea
        height: 60
        color: AppController.palette["colors.primary.surface"]
        border.color: AppController.palette["colors.primary.border"]
        border.width: 1
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        RowLayout
        {
            anchors.fill: parent
            RowLayout
            {
                spacing: 50
                RowLayout
                {
                    spacing: 20
                    Image {
                        id: logoHead
                        source: "qrc:/logo/logoHead"
                        Layout.preferredHeight: 40
                        fillMode: Image.PreserveAspectFit
                    }
                    Image {
                        id: logText
                        source: "qrc:/logo/carnageText"
                        Layout.preferredHeight: 40
                        fillMode: Image.PreserveAspectFit
                    }
                }

                Rectangle {
                    id: captureBtn
                    height: 35
                    width: 200
                    color: isActivated ? AppController.palette["colors.semantic.allowed"] : AppController.palette["colors.accent.primary"] //AppController.palette["colors.accent.primary"]
                    radius: 5

                    property bool isActivated: true

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor

                        onClicked: {
                                captureBtn.isActivated = !captureBtn.isActivated
                            }
                    }

                    Row {
                        anchors.centerIn: parent
                        spacing: 8

                        Text {
                            text:  captureBtn.isActivated ? "START CAPTURE" : "STOP CAPTURE"
                            color: AppController.palette["colors.text.primary"]
                            font.pixelSize: AppController.palette["typography.fontSize.sm"]
                            font.family: AppController.palette["typography.fontFamily.inter"]
                            font.weight: AppController.palette["typography.fontWeight.semibold"]
                        }
                    }
                }

            }

            RowLayout
            {

            }

            RowLayout
            {

            }
        }
    }
}
