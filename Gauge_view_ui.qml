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
        id:contenplot
        anchors.fill: parent
           color:  CusConfig.controlBorderColor
  // Layout.preferredHeight:content.height*0.3
 //  Layout.preferredWidth : content.width*0.5
  GridLayout{
      anchors.fill: parent
      anchors.margins: 20
      columns:6
      rowSpacing: 55


CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("℃")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fixedHeight
    width:120
    color:CusConfig.controlBorderColor
  //  border.color: CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("油箱温度")
}
StatusIndicator{
//     id:light
active: true
height: parent.height-2
width: height

//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3

}
}
}

CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("℃")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
    color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("试验箱温度1")
}
StatusIndicator{
//    id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right

anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3
}
}
}

CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("℃")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
  color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("试验箱温度2")
}
StatusIndicator{
  //  id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3

}
}
}


CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("℃")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
   color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("进管道温度")
}
StatusIndicator{
 //   id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3

}
}
}

CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("℃")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
     color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("出管道温度")
}
StatusIndicator{
//    id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right

anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3
}
}
}


CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("Mpa")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
    color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("进管道压力")
}
StatusIndicator{
 //   id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3

}
}
}

/*
CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("Mpa")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
    color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("出管道压力")
}
StatusIndicator{
 //   id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3

}
}
}



CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("m³/h")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
    color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("流量")
}
StatusIndicator{
 //   id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
anchors.rightMargin: 3

}
}
}


CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("N")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
    color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("侧向加载力")
}
StatusIndicator{
 //   id:light
height: parent.height-2
width: height
//radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3

}
}
}


CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("N")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
    color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("轴向加载力")
}
Rectangle{
 //   id:light
height: parent.height-2
width: height
radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
 anchors.rightMargin: 3

}
}
}

CircularGauge{   Layout.fillHeight: true
Layout.fillWidth: true
   value: valueSource.kph
style: DashboardGaugeStyle{
txt_Unit: qsTr("N")
}
Rectangle{
    anchors.top: parent.bottom
    anchors.topMargin: 5
    height: CusConfig.fontPixel
    width:100
    color:CusConfig.controlBorderColor
    anchors.horizontalCenter: parent.horizontalCenter
CusLabel {
horizontalAlignment: Qt.AlignHCenter
anchors.fill: parent

    text: qsTr("力矩加载力")
}
Rectangle{
 //   id:light
height: parent.height-2
width: height
radius: width/2
color: valueSource.kph>80?"red":"blue"
anchors.right:parent.right
anchors.verticalCenter: parent.verticalCenter
anchors.rightMargin: 3

}
}
}
*/





  }


    }


