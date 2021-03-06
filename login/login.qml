import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import "qml/controls"

Item {
    id: mainWindow
    width: 1110
    height: 610
    visible: true
   // color: "#00000000"
   // title: qsTr("flame arrester logion")

    // Make the window Frameless
   // flags: Qt.Window | Qt.FramelessWindowHint
    signal login
    signal forgetpsw
    signal register
    Rectangle {
        id: mainContainer
        color: "#ffffff"
        anchors.fill: parent
        clip: true
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        radius: 10

        // Create a transparent title bar
        Rectangle {
            id: titleBar
            width: parent.width
            height: 40
            color: "transparent"
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            z: 10

            DragHandler {
                onActiveChanged: if (active) {
                                     mainWindow.startSystemMove()
                                 }
            }
        }

        CloseButton {
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 15
            anchors.rightMargin: 15
            z: 10
        }

        Rectangle {
            id: heroSection
            width: 653
            color: "#00000000"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 0
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            Image {
                id: heroLogo
                x: 277
                y: 245
                width: 151
                height: 50
                anchors.left: parent.left
                source: "qrc:/font/icon.png"
                anchors.top: parent.top
                fillMode: Image.PreserveAspectFit
            }
            Image {
                id: heroImage
                anchors.fill: parent
                source:"file:///"+applicationDirPath+ "/images/背景.png"
                fillMode: Image.PreserveAspectFit
/*
                Image {
                    id: heroLogo
                    x: 277
                    y: 245
                    width: 151
                    height: 139
                    anchors.verticalCenter: parent.verticalCenter
                    source: "qrc:/font/icon.png"
                    anchors.horizontalCenter: parent.horizontalCenter
                    fillMode: Image.PreserveAspectFit
                }
                */
            }
        }

        Rectangle {
            id: formSection
            color: "#00000000"
            anchors.left: heroSection.right
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.leftMargin: 0

            StandardButton {
                id: loginButton
                anchors.left: parent.left
                anchors.top: parent.top
                anchors.leftMargin: 79
                anchors.topMargin: 58
                text:  qsTr("Login")
            }

            StandardButton {
                id: registerButton
                anchors.top: parent.top
                anchors.leftMargin: 0
                anchors.topMargin: 58
              //  text:  qsTr("Register")
                anchors.left: loginButton.right

                textColor: "#545454"
                buttonColor: "#ffffff"
                onClicked: {
                  register()
                }
            }

            Label {
                id: welcomeLabel
                text: qsTr("Welcome")
                anchors.left: parent.left
                anchors.top: loginButton.bottom
                font.pixelSize: 36
                anchors.leftMargin: 79
                anchors.topMargin: 30
                font.bold: true
            }

            Label {
                id: welcomeDescription
                color: "#545454"
                text: qsTr("Pleace login to your account")
                anchors.left: parent.left
                anchors.top: welcomeLabel.bottom
                font.pixelSize: 12
                anchors.leftMargin: 79
                anchors.topMargin: 0
            }

            FormInput {
                id: usernameInput
                anchors.left: parent.left
                anchors.top: welcomeDescription.bottom
                anchors.topMargin: 50
                anchors.leftMargin: 79
                z: 20

               // inva
            }

            FormInput {
                id: passwordInput
                anchors.left: parent.left
                anchors.top: usernameInput.bottom
                anchors.topMargin: 30
                anchors.leftMargin: 79
                z: 20
                inputLabel: qsTr("Password")
                fieldType: "Password"
            }

            StandardButton {
                id: okButton
                text: qsTr("OK")
                anchors.right: parent.right
                anchors.top: passwordInput.bottom
                anchors.topMargin: 30
                anchors.rightMargin: 79
                onClicked: {
            //        console.log("ok")
if(iniwr.checkuser(usernameInput.txt)&&iniwr.checkpwd(passwordInput.txt) ){
    login()
}else{
termLabel.text=qsTr("账户或者密码错误!")
}

                }
            }

            StandardButton {
                id: forgotPasswordButton
                anchors.top: passwordInput.bottom
                anchors.leftMargin: 79
                anchors.topMargin: 30
              //  text: "Forgot Password"
                anchors.left: parent.left

                textColor: "#545454"
                buttonColor: "#ffffff"
                textUnderline: true
                onClicked: {
                forgetpsw()
                }
            }

            IconButton {
                id: facebookLogin
                anchors.top: forgotPasswordButton.bottom
                anchors.topMargin: 30
                anchors.left: parent.left
                anchors.leftMargin: 79
                visible: false
            }

            Label {
                id: termLabel
                color: "#8E8E8E"
               // text: qsTr("Terms and Conditions & Privacy Policy")

                anchors.top: facebookLogin.bottom
                font.pixelSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 20

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHandCursor
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:2}
}
##^##*/

