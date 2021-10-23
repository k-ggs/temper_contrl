import QtQuick 2.0

import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import custom_plot 1.0
import CustomPlot 1.0
import QtQuick.Extras 1.4
import QtQml.Models 2.3
import"./Tao_custom_Qml/instrument"
import"./TaoQuick"
Rectangle {
    CircularGauge{
   // Layout.fillHeight: true
   // Layout.fillWidth: true
    implicitWidth: 400
    implicitHeight: 400
    value: valueSource.kph
    style: DashboardGaugeStyle{
    txt_Unit: qsTr("℃")
    }

    Rectangle{
        anchors.top: parent.bottom
        anchors.topMargin: 5
        height: CusConfig.fixedHeight
      //  width:parent.width
        color:CusConfig.controlBorderColor
        //border.color: CusConfig.controlBorderColor
        anchors.horizontalCenter: parent.horizontalCenter

        RowLayout{
     spacing: 5
     anchors.fill: parent
     anchors.horizontalCenter: parent.horizontalCenter

    CusLabel {


        text: Temper_Config.temp1
    }
    StatusIndicator{

    active: true

    color: valueSource.kph>80?"red":"blue"


    }
        }

    }
    Rectangle{
        anchors.left: parent.right
height: parent.height
        width: 300
        //width:parent.width
        color:CusConfig.themeColor
        //border.color: CusConfig.controlBorderColor
       // anchors.horizontalCenter: parent.horizontalCenter

    CusSlider_Spin_Cls
    {
    anchors.fill: parent

    }


    }
    }
}
