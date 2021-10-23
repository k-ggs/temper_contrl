import QtQuick 2.9
import QtQuick.Controls 2.2

import ".."
import "../.."
Column {
    height: parent.height

    spacing: 0
    property alias value: slider.value
    property alias from: slider.from
    property alias to: slider.to
    property alias stepSize: slider.stepSize
    property string txt: "demo"
    CusLabel_Center{
  height: parent.width * 0.2
          //hie: parent.width * 0.3
         //   height: CusConfig.fixedHeight
            text: txt+":"
    }
   Slider{from:0
       to:100
        orientation: Qt.vertical
        id: slider
     //   height: CusConfig.fixedHeight
     //   height: parent.width * 0.6
        onValueChanged: {
            spinBox.value = value
        }
    }
    CusSpinBox {
        id: spinBox

    //    height: CusConfig.fixedHeight
        height: parent.width * 0.2
        value: slider.value
        from: slider.from
        to: slider.to
        onValueChanged: {
            slider.value = value
        }
    }
}
