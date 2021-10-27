import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import custom_plot 1.0
import CustomPlot 1.0
import QtQuick.Extras 1.4
import QtQml.Models 2.3
import"./Tao_custom_Qml/instrument"
import"./TaoQuick"

Rectangle{
  //  anchors.fill: parent
    property alias title: ttle.text
    property alias value: gauge.value
    property  string swh :"00"
    property  alias temperature:sld.value
     property alias dev:sld.divv
    property bool opened:false
    signal sendd()
    signal sw_open()
    signal sw_close()
    border.width: 2
    color:CusConfig.controlBorderColor
radius:20
CircularGauge{
    id:gauge
   anchors.fill: parent





style: DashboardGaugeStyle{
txt_Unit: qsTr("℃")
}
   ColumnLayout{
anchors.bottom: parent.bottom

anchors.top: parent.bottom
anchors.topMargin:0
Rectangle{


    height: CusConfig.fixedHeight

    color:CusConfig.controlBorderColor

    anchors.horizontalCenter: parent.horizontalCenter

    RowLayout{
 spacing: 5

 anchors.horizontalCenter: parent.horizontalCenter
 CusButton{

        text: "开"
     onClicked: {

            swh="01"
        sw_open()

     }
     }
 CusButton{
textColor: "red"
text: "关"

     onClicked: {

          swh="00"
         sw_close()


     }
     }




CusLabel {

id:ttle


}
StatusIndicator{

active: true

color: opened==false?"red":"blue"


}
    }

}
Rectangle{
   // anchors.left: parent.right
     height: parent.height
    width: 300

    color:CusConfig.themeColor


G_Slider_Spin
{
id:sld
width: 300
anchors.fill: parent
from:0
to:iniwr.tempmax
value: iniwr.defaulttemp
divv:iniwr.defaultdeva
onSend: {
sendd()
}
}


}
}
}

}
