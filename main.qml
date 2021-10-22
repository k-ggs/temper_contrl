import QtQuick 2.12
import QtQuick.Window 2.12


import FramelessWindow 1.0

/*
Window {
    id:root
    width: 1640
    height: 780
    visible: true
   // title: qsTr("Hello World")
     property bool isMoveWindow: false
    property point winpos: Qt.point(x,y)

    //flags:  Qt.WindowSystemMenuHint| Qt.Window
    flags:  Qt.WindowTitleHint|Qt.Window|Qt.FramelessWindowHint
    ColumnLayout{
    id:root1
    anchors.fill: parent
    Rectangle{
        id:title
    Layout.fillWidth: true
    Layout.preferredHeight: 60
    border.width: 2

    RowLayout{

    id:mme
   width: 150
height:parent.height
anchors.right: parent.right


Label{
    color: "#ddcfcdcd"
     font.pointSize: 24
    font.family: "iconfont"
Layout.fillHeight: true
Layout.fillWidth: true
 text: "\uE6C6"
}
Label{
     color: "#ddcfcdcd"
     font.pointSize: 24
    font.family: "iconfont"
Layout.fillHeight: true
Layout.fillWidth: true
  text: "\uE6BB"
}
Label{
     color: "#ddcfcdcd"
     font.pointSize: 24
font.family: "iconfont"
Layout.fillHeight: true
Layout.fillWidth: true
 text: "\uE633"

}

    }
MouseArea{
anchors.fill: title
//只接收鼠标左键
acceptedButtons: Qt.LeftButton
// 接收鼠标按下事件
onPressed: {
root.winpos=Qt.point(mouseX,mouseY)

}
onMouseXChanged: {




        root.x += mouseX - root.winpos.x;

}
onMouseYChanged: {

    root.y += mouseY - root.winpos.y;
}

}
    }
    Rectangle{
         id:content
    Layout.fillWidth: true
    Layout.fillHeight: true
    }


    }


}
*/

TaoFramelessWindow{
    id: root
    visible: true
    width: 1640
    height: 980
    minimumWidth: 480
    minimumHeight: 320

    property int winwidth: Screen.desktopAvailableWidth
     property int winheight: Screen.desktopAvailableHeight
    x:(winwidth-width)/2
    y:(winheight-height)/2
Content_ui{
 anchors.fill: parent
}

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.25}
}
##^##*/
