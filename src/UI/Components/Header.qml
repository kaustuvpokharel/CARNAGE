import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import CARNAGE 1.0

Item {
    Rectangle {
        id: headerArea
        height: 60
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        color: AppController.palette["colors.primary.surface"]
        border.color: AppController.palette["colors.primary.border"]
        border.width: 1

        RowLayout {
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.leftMargin: 25
            anchors.rightMargin: 25
            anchors.margins: 10
            spacing: 20

            RowLayout {
                spacing: 50
                Layout.alignment: Qt.AlignVCenter

                RowLayout {
                    spacing: 10
                    Image {
                        id: logoHead
                        source: "qrc:/logo/logoHead"
                        Layout.preferredHeight: 40
                        Layout.preferredWidth: 30
                        fillMode: Image.PreserveAspectFit
                    }

                    Image {
                        id: logText
                        source: "qrc:/logo/carnageText"
                        Layout.preferredHeight: 35
                        Layout.preferredWidth: 100
                        fillMode: Image.PreserveAspectFit
                    }
                }

                Rectangle {
                    id: captureBtn
                    width: 180
                    height: 30
                    radius: 5
                    color: isActivated
                        ? AppController.palette["colors.semantic.allowed"]
                        : AppController.palette["colors.accent.primary"]

                    property bool isActivated: true

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: captureBtn.isActivated = !captureBtn.isActivated
                    }

                    Row {
                        anchors.centerIn: parent
                        spacing: 8

                        Text {
                            text: captureBtn.isActivated ? "STOP CAPTURE" : "START CAPTURE"
                            color: AppController.palette["colors.text.primary"]
                            font.pixelSize: AppController.palette["typography.fontSize.base"]
                            font.family: AppController.palette["typography.fontFamily.inter"]
                            font.weight: AppController.palette["typography.fontWeight.semibold"]
                        }
                    }
                }
            }

            // Spacer to push right side elements
            Item { Layout.fillWidth: true }

            RowLayout {
                spacing: 15
                Layout.alignment: Qt.AlignVCenter

                RowLayout {
                    spacing: 8
                    Layout.alignment: Qt.AlignVCenter

                    Text {
                        text: "Interface:"
                        color: AppController.palette["colors.text.secondary"]
                        font.pixelSize: AppController.palette["typography.fontSize.sm"]
                        font.family: AppController.palette["typography.fontFamily.inter"]
                        font.weight: AppController.palette["typography.fontWeight.semibold"]
                    }

                    ComboBox {
                        editable: false
                        model: ListModel {
                            id: model
                            ListElement { text: "Ethernet (eth0)" }
                            ListElement { text: "Wi-Fi (wlan0)" }
                            ListElement { text: "Loopback (lo)" }
                        }
                        font.pixelSize: AppController.palette["typography.fontSize.sm"]
                        font.family: AppController.palette["typography.fontFamily.inter"]
                        font.weight: AppController.palette["typography.fontWeight.medium"]
                    }
                }

                RowLayout {
                    spacing: 8

                    Repeater {
                        model: [1, 2, 3, 4]
                        delegate: Rectangle {
                            width: 30
                            height: 30
                            radius: 5
                            color: AppController.palette["colors.primary.elevated"]
                        }
                    }
                }
            }
        }
    }
}
