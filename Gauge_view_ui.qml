import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import custom_plot 1.0
import CustomPlot 1.0
import QtQuick.Extras 1.4
import QtQml.Models 2.3
import"./Tao_custom_Qml/instrument"
import"./TaoQuick"
import src.tcpclientmodel 1.0

    Rectangle{
        id:contenplot
        anchors.fill: parent

           color:  CusConfig.backgroundColor
  // Layout.preferredHeight:content.height*0.3
 //  Layout.preferredWidth : content.width*0.5

           TcpClientModel{
           id:tcpc


           }
  GridLayout{
      anchors.fill: parent
      anchors.margins:90
       anchors.topMargin:10
      columns:3
      columnSpacing: 10
      rowSpacing:100


      CircularGauge{
          Layout.fillHeight: true
          Layout.fillWidth: true
      value: valueSource.kph
      style: DashboardGaugeStyle{
      txt_Unit: qsTr("℃")
      }
ColumnLayout{
anchors.bottom: parent.bottom

    anchors.top: parent.bottom
    anchors.topMargin:0
      Rectangle{


          height: CusConfig.fixedHeight
        //  width:parent.width
          color:CusConfig.controlBorderColor
          //border.color: CusConfig.controlBorderColor
          anchors.horizontalCenter: parent.horizontalCenter

          RowLayout{
       spacing: 5
     //  anchors.fill: parent
       anchors.horizontalCenter: parent.horizontalCenter
       CusButton{

           onClicked: {

               if(gtcpmodel.b1){
                 tcpc.send(iniwr.Writestates[0]+"0")
               }else{
                 tcpc.send(iniwr.Writestates[0]+"1")
               }
                 }
       }
      CusLabel {


          text: Temper_Config.temp1
      }
      StatusIndicator{

      active: true

      color: gtcpmodel.b1==false?"red":"blue"


      }
          }

      }
      Rectangle{
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent
      onValueChanged: {
tcpc.send(iniwr.Writetemps[0]+ value.toString())

      }

      }


      }
}
}

      CircularGauge{
          Layout.fillHeight: true
          Layout.fillWidth: true
      value: valueSource.kph
      style: DashboardGaugeStyle{
      txt_Unit: qsTr("℃")
      }
ColumnLayout{
anchors.bottom: parent.bottom

    anchors.top: parent.bottom
    anchors.topMargin:0
      Rectangle{


          height: CusConfig.fixedHeight
        //  width:parent.width
          color:CusConfig.controlBorderColor
          //border.color: CusConfig.controlBorderColor
          anchors.horizontalCenter: parent.horizontalCenter

          RowLayout{
       spacing: 5
     //  anchors.fill: parent
       anchors.horizontalCenter: parent.horizontalCenter
CusButton{

    onClicked: {

        if(gtcpmodel.b2){
          tcpc.send(iniwr.Writestates[1]+"0")
        }else{
        tcpc.send(iniwr.Writestates[1]+"1")
        }
          }
}
      CusLabel {


          text: Temper_Config.temp1
      }
      StatusIndicator{

      active: true

      color:  gtcpmodel.b2==false?"red":"blue"


      }
          }

      }
      Rectangle{
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent
      onValueChanged: {
tcpc.send(iniwr.Writetemps[1]+ value.toString())
}
      }


      }
}
}

      CircularGauge{
          Layout.fillHeight: true
          Layout.fillWidth: true
      value: valueSource.kph
      style: DashboardGaugeStyle{
      txt_Unit: qsTr("℃")
      }
ColumnLayout{
anchors.bottom: parent.bottom

    anchors.top: parent.bottom
    anchors.topMargin:0
      Rectangle{


          height: CusConfig.fixedHeight
        //  width:parent.width
          color:CusConfig.controlBorderColor
          //border.color: CusConfig.controlBorderColor
          anchors.horizontalCenter: parent.horizontalCenter

          RowLayout{
       spacing: 5
     //  anchors.fill: parent
       anchors.horizontalCenter: parent.horizontalCenter
       CusButton{

           onClicked: {

               if(gtcpmodel.b3){
                 tcpc.send(iniwr.Writestates[2]+"0")
               }else{
               tcpc.send(iniwr.Writestates[2]+"1")
               }
                 }
       }
      CusLabel {


          text: Temper_Config.temp1
      }
      StatusIndicator{

      active: true

      color:  gtcpmodel.b3==false?"red":"blue"


      }
          }

      }
      Rectangle{
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent
      onValueChanged: {
tcpc.send(iniwr.Writetemps[2]+ value.toString())
}
      }


      }
}
}

      CircularGauge{
          Layout.fillHeight: true
          Layout.fillWidth: true
      value: valueSource.kph
      style: DashboardGaugeStyle{
      txt_Unit: qsTr("℃")
      }
ColumnLayout{
anchors.bottom: parent.bottom

    anchors.top: parent.bottom
    anchors.topMargin:0
      Rectangle{


          height: CusConfig.fixedHeight
        //  width:parent.width
          color:CusConfig.controlBorderColor
          //border.color: CusConfig.controlBorderColor
          anchors.horizontalCenter: parent.horizontalCenter

          RowLayout{
       spacing: 5
     //  anchors.fill: parent
       anchors.horizontalCenter: parent.horizontalCenter
       CusButton{

           onClicked: {

               if(gtcpmodel.b4){
                 tcpc.send(iniwr.Writestates[3]+"0")
               }else{
               tcpc.send(iniwr.Writestates[3]+"1")
               }
                 }
       }
      CusLabel {


          text: Temper_Config.temp1
      }
      StatusIndicator{

      active: true

      color:  gtcpmodel.b4==false?"red":"blue"


      }
          }

      }
      Rectangle{
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent
      onValueChanged: {
tcpc.send(iniwr.Writetemps[3]+ value.toString())
}
      }


      }
}
}

      CircularGauge{
          Layout.fillHeight: true
          Layout.fillWidth: true
      value: valueSource.kph
      style: DashboardGaugeStyle{
      txt_Unit: qsTr("℃")
      }
ColumnLayout{
anchors.bottom: parent.bottom

    anchors.top: parent.bottom
    anchors.topMargin:0
      Rectangle{


          height: CusConfig.fixedHeight
        //  width:parent.width
          color:CusConfig.controlBorderColor
          //border.color: CusConfig.controlBorderColor
          anchors.horizontalCenter: parent.horizontalCenter

          RowLayout{
       spacing: 5
     //  anchors.fill: parent
       anchors.horizontalCenter: parent.horizontalCenter
       CusButton{

           onClicked: {

               if(gtcpmodel.b5){
                 tcpc.send(iniwr.Writestates[4]+"0")
               }else{
               tcpc.send(iniwr.Writestates[4]+"1")
               }
                 }
       }
      CusLabel {


          text: Temper_Config.temp1
      }
      StatusIndicator{

      active: true

      color:  gtcpmodel.b5==false?"red":"blue"


      }
          }

      }
      Rectangle{
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent
      onValueChanged: {
tcpc.send(iniwr.Writetemps[4]+ value.toString())

      }
      }


      }
}
}

      CircularGauge{
      Layout.fillHeight: true
      Layout.fillWidth: true
    //  implicitWidth: 300
    //  implicitHeight: 300
      value: valueSource.kph
      style: DashboardGaugeStyle{
      txt_Unit: qsTr("℃")
      }
ColumnLayout{
anchors.bottom: parent.bottom

    anchors.top: parent.bottom
    anchors.topMargin:0
      Rectangle{


          height: CusConfig.fixedHeight
        //  width:parent.width
          color:CusConfig.controlBorderColor
          //border.color: CusConfig.controlBorderColor
          anchors.horizontalCenter: parent.horizontalCenter

          RowLayout{
       spacing: 5
     //  anchors.fill: parent
       anchors.horizontalCenter: parent.horizontalCenter
       CusButton{

           onClicked: {

               if(gtcpmodel.b6){
                 tcpc.send(iniwr.Writestates[5]+"0")
               }else{
               tcpc.send(iniwr.Writestates[5]+"1")
               }
                 }
       }
      CusLabel {


          text: Temper_Config.temp1
      }
      StatusIndicator{

      active: true

      color:  gtcpmodel.b6==false?"red":"blue"


      }
          }

      }
      Rectangle{
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent
      onValueChanged: {
tcpc.send(iniwr.Writetemps[5]+ value.toString())

      }
      }


      }
}
}









  }
  Component.onCompleted: {



tcpc.toggleConnect(true,iniwr.ip,iniwr.port)
  }

    }


