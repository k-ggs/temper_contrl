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

      ColumnLayout{
              anchors.fill: parent
           GridLayout{
   Layout.preferredHeight: parent.height*0.7
   Layout.fillWidth: true
     // anchors.margins:90
      // anchors.topMargin:10
     Layout.margins: 90
   Layout.topMargin: 10

      columns:3
      columnSpacing: 10
      rowSpacing:100


      CircularGauge{
          Layout.fillHeight: true
          Layout.fillWidth: true
      value:gtcpmodel.tem1
         property int  xx: 0
      onValueChanged: {
          xx++
          customPlot.addData(0,xx,gtcpmodel.tem1)
          customPlot.addData(1,xx,gtcpmodel.tem2)
          customPlot.addData(2,xx,gtcpmodel.tem3)
          customPlot.addData(3,xx,gtcpmodel.tem4)
          customPlot.addData(4,xx,gtcpmodel.tem5)

          customPlot.addData(5,xx,gtcpmodel.tem6)

      }

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
       Switch{
//checked: gtcpmodel.b1
           onCheckedChanged: {

           if(gtcpmodel.b1){
                 tcpc.send(iniwr.Writestates[0]+"0")
           checked=true
           }else{
           checked=false
                 tcpc.send(iniwr.Writestates[0]+"1")

           }
           }
           /*
           onClicked: {
  //console.log(iniwr.Writestates[0])
               if(gtcpmodel.b1){

                 tcpc.send(iniwr.Writestates[0]+"0")
               }else{
                 tcpc.send(iniwr.Writestates[0]+"1")
               }
                 }
           */
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


      G_Slider_Spin
      {width: 300
      anchors.fill: parent
      from:0
      to:iniwr.tempmax
      value: iniwr.defaulttemp
    divv:iniwr.defaultdeva
onSend: {
tcpc.send(iniwr.Writetemps[0]+ value.toString())
tcpc.send(iniwr.Writedeviation[0]+ divv.toString())
}
      }


      }
}
}

      CircularGauge{
          Layout.fillHeight: true
          Layout.fillWidth: true
      value: gtcpmodel.tem2
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


      G_Slider_Spin
      {width: 300
      anchors.fill: parent
      from:0
      to:iniwr.tempmax
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
      value: gtcpmodel.tem3
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


      G_Slider_Spin
      {width: 300
      anchors.fill: parent
      from:0
      to:iniwr.tempmax
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
      value: gtcpmodel.tem4
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


      G_Slider_Spin
      {width: 300
      anchors.fill: parent
      from:0
      to:iniwr.tempmax
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
      value: gtcpmodel.tem5
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


      G_Slider_Spin
      {width: 300
      anchors.fill: parent
      from:0
      to:iniwr.tempmax
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
      value: gtcpmodel.tem6
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


      G_Slider_Spin
      {width: 300
      anchors.fill: parent
      from:0
      to:iniwr.tempmax
      onValueChanged: {
tcpc.send(iniwr.Writetemps[5]+ value.toString())

      }
      }


      }
}
}









  }

           Rectangle{
                    Layout.fillWidth: true
                    Layout.preferredHeight:parent.height*0.3
                    color:CusConfig.CusConfig.backgroundColor

                    CustomPlotItem{

                      //  Layout.fillHeight: true
                     //   Layout.fillWidth: true
                        anchors.fill: parent
                        id: customPlot

                        background :CusConfig.CusConfig.backgroundColor
                        legend: Legend{ font: "helvetica,-1,8,5,0,0,0,0,0,0"}

                        graphs : [
                           Graph {
                                         name : "温度1"
                                         pen : Pen { color : "blue"; width : 1.0 }
                                         scatter : ScatterStyle {
                                             brush : "white"
                                            // type : Scatter.ssCircle
                                             size : 1
                                             pen : Pen {	color : "green"; width: 1.0	}
                                         }
                                         xAxis : Axis {
                                             useDefault : true
                                             visible : false
                                             label : Label {
                                                 text : "domain"
                                                 font : "helvetica,-1,8,5,0,0,0,0,0,0"
                                                 color: "blue"
                                             }
                                         }
                                         yAxis : Axis
                                         { visible : false
                                             label : Label {
                                                 text : "sin"
                                                 font : "helvetica,-1,8,5,0,0,0,0,0,0"
                                                 color : "red"
                                             }
                                         }
                                  },
                           Graph {
                                         name : "温度2"
                                         pen : Pen { color : "red"; width : 1.0 }
                                         xAxis : Axis {
                                         useDefault : true

                                         }

                                     }

                                     ,
                           Graph {
                                             name : "温度3"
                                             pen : Pen { color : "green"; width : 1.0 }
                                             xAxis : Axis {
                                              useDefault : true

                                               }

                                                }
                            ,
                           Graph {
                                  name :"温度4"
                                 pen : Pen { color : "green"; width : 1.0 }
                                  xAxis : Axis {
                                  useDefault : true

                           }

                           }
                            ,
                           Graph {
                             name : "温度5"
                             pen : Pen { color : "green"; width : 1.0 }
                             xAxis : Axis {
                             useDefault : true

                          }

                            }
                           ,
                           Graph {
                             name : "温度6"
                            pen : Pen { color : "green"; width : 1.0 }
                             xAxis : Axis {
                              useDefault : true

                             }

                            }

                            ]



                             }

                }

      }
           Component.onCompleted: {


customPlot.setRange_tpe( {"lo":0,"up":100},2);
tcpc.toggleConnect(true,iniwr.ip,iniwr.port)
  }

    }


