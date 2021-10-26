﻿import QtQuick 2.9
import QtQuick.Controls 2.2
import"./Tao_custom_Qml/instrument"
import"./TaoQuick"
Row {
    height: CusConfig.fixedHeight
    spacing: 0
    property alias value: slider.value
    property alias divv: label2.value
    property alias from: slider.from
    property alias to: slider.to
    property alias stepSize: slider.stepSize
    property string txt: "确定"
    signal send()

    CusButton_Red{

          width: parent.width * 0.2
            height: CusConfig.fixedHeight
            text: txt
            onClicked: {
            send()
            }

    }
    CusSlider {
        id: slider
        height: CusConfig.fixedHeight
        width: parent.width * 0.6
        onValueChanged: {
            spinBox.value = value
        }
    }
    CusSpinBox {
        id: spinBox

        height: CusConfig.fixedHeight
        width: parent.width * 0.1
        value: slider.value
        from: slider.from
        to: slider.to
        onValueChanged: {
            slider.value = value
        }
      ToolTip.text: qsTr("设定的温度")
      ToolTip.visible: hovered
      ToolTip.delay: 500
      ToolTip.timeout: 1000

    }
    CusSpinBox{
        id:label2
        height: CusConfig.fixedHeight
        width: parent.width * 0.1
    from:0
    ToolTip.text: qsTr("温差范围")
    ToolTip.visible: hovered
    ToolTip.delay: 500
    ToolTip.timeout: 1000
   // to:Slider.to-spinBox.value
    onValueChanged: {
label2.to=slider.to-spinBox.value

    }

    }


}
