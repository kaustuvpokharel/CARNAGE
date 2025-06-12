// @ author Kaustuv Pokharel
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Qt5Compat.GraphicalEffects
import CARNAGE 1.0

Item {
    id: root
    // width: parent.width
    // height: parent.height

    signal loginSuccessful()

    property bool loading: false
    property string emailText: ""
    property string passwordText: ""

    BusyIndicator {
        id: loader
        anchors.centerIn: parent
        running: root.loading
        visible: root.loading
        z: 1000
        width: 64
        height: 64
    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: AppController.palette["colors.primary.background"]
    }

    Rectangle {
        anchors.fill: parent
        color: "transparent"

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 50

            ColumnLayout {
                spacing: 5
                Layout.alignment: Qt.AlignHCenter

                Image {
                    id: logo
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredHeight: 120
                    Layout.preferredWidth: 200
                    source: "qrc:/logo/logo"
                    fillMode: Image.PreserveAspectFit
                }

                Text {
                    text: "Sniff. Inject. Obliterate."
                    Layout.alignment: Qt.AlignHCenter
                    color: "#f2f2f2"
                    font.pixelSize: 30
                    font.family: "pBold"
                    font.weight: 700
                }

                Text {
                    text: "Sign in to continue"
                    Layout.alignment: Qt.AlignHCenter
                    color: "#b62619"
                    font.pixelSize: 16
                    font.family: "pMedium"
                    font.weight: 500
                }
            }

            Rectangle {
                id: loginArea
                Layout.alignment: Qt.AlignCenter
                color: AppController.palette["colors.primary.surface"]
                width: 450
                height: 400
                radius: 5
                border.color: AppController.palette["colors.primary.border"]
                border.width: 1

                ColumnLayout
                {
                    spacing: 20
                    anchors.fill: parent
                    anchors.margins: 45

                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 4

                        Text {
                            text: "Email"
                            color: AppController.palette["colors.text.secondary"]
                            font.pixelSize: parseInt(AppController.palette["typography.fontSize.sm"])
                            font.weight: parseInt(AppController.palette["typography.fontWeight.medium"])
                        }

                        Rectangle {
                            height: 50
                            Layout.fillWidth: true
                            color: AppController.palette["colors.primary.elevated"]
                            radius: 5
                            border.color: AppController.palette["colors.primary.border"]
                            border.width: 1

                            TextField {
                                id: emailField
                                anchors.fill: parent
                                anchors.margins: 12
                                placeholderText: "Enter your email"
                                color: AppController.palette["colors.text.primary"]
                                placeholderTextColor: AppController.palette["colors.text.secondary"]
                                font.pixelSize: parseInt(AppController.palette["typography.fontSize.base"])
                                font.weight: parseInt(AppController.palette["typography.fontWeight.normal"])
                                font.family: "pRegular"
                                background: null
                                onTextChanged: emailText = text
                            }
                        }
                    }

                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 4

                        Text {
                            text: "Password"
                            color: AppController.palette["colors.text.secondary"]
                            font.pixelSize: parseInt(AppController.palette["typography.fontSize.sm"])
                            font.weight: parseInt(AppController.palette["typography.fontWeight.medium"])
                        }

                        Rectangle {
                            height: 50
                            Layout.fillWidth: true
                            color: AppController.palette["colors.primary.elevated"]
                            radius: 5
                            border.color: AppController.palette["colors.primary.border"]
                            border.width: 1

                            TextField {
                                id: passwordField
                                anchors.fill: parent
                                anchors.margins: 12
                                placeholderText: "Enter your password"
                                color: AppController.palette["colors.text.primary"]
                                placeholderTextColor: AppController.palette["colors.text.secondary"]
                                font.pixelSize: parseInt(AppController.palette["typography.fontSize.base"])
                                font.weight: parseInt(AppController.palette["typography.fontWeight.normal"])
                                font.family: "pRegular"
                                background: null
                                onTextChanged: passwordText = text
                            }
                        }
                    }

                    Text {
                        text: "Forgot Password?"
                        color: AppController.palette["colors.accent.primary"]
                        font.pixelSize: AppController.palette["typography.fontSize.sm"]
                        font.weight: AppController.palette["typography.fontWeight.medium"]
                        Layout.alignment: Qt.AlignRight

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            onClicked: console.log("Forgot password clicked")
                        }
                    }

                    Text {
                        id: errorMessage
                        text: ""
                        color: "#b62619"
                        font.pixelSize: 14
                        visible: text.length > 0
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 50
                        color: emailText.length > 1 && passwordText.length > 1 ? "#b62619" : "#3a3a3a"
                        radius: 5

                        MouseArea {
                            anchors.fill: parent
                            cursorShape: Qt.PointingHandCursor
                            enabled: emailText.length > 1 && passwordText.length > 1

                            onClicked: {
                                root.loginSuccessful();
                            }
                        }

                        Row {
                            anchors.centerIn: parent
                            spacing: 8

                            Text {
                                text: "Sign In"
                                color: "#ffffff"
                                font.pixelSize: 16
                                font.family: "pBold"
                                font.weight: 700
                            }
                        }
                    }

                    Row {
                        Layout.alignment: Qt.AlignHCenter
                        Layout.topMargin: 16
                        spacing: 4

                        Text {
                            text: "Don't have an account?"
                            color: AppController.palette["colors.accent.primary"]
                            font.pixelSize: 14
                            font.family: "pMedium"
                            font.weight: 500
                        }

                        Text {
                            text: "Sign Up"
                            color: AppController.palette["colors.text.primary"]
                            font.pixelSize: 14
                            font.family: "pBold"
                            font.weight: 700

                            MouseArea {
                                anchors.fill: parent
                                cursorShape: Qt.PointingHandCursor
                                onClicked: console.log("Sign up clicked")
                            }
                        }
                    }
                }

            }
        }
    }
}
