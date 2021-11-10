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

          // color:  CusConfig.controlBorderColor
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
      columnSpacing: 0
      rowSpacing:100

G_gauge{
    id:g1
    title: Temper_Config.temp1
    value: gtcpmodel.tem1

    opened:gtcpmodel.b1
    onSw_open: {
 sendmsg()
    }
    onSw_close: {
 sendmsg()
    }
    onSendd: {
sendmsg()
    }

    Layout.fillHeight: true
    Layout.fillWidth: true
}
G_gauge{
      id:g2

    title: Temper_Config.temp2
    value: gtcpmodel.tem2
     opened:gtcpmodel.b2
    Layout.fillHeight: true
    Layout.fillWidth: true
    onSw_open: {
 sendmsg()
    }
    onSw_close: {
 sendmsg()
    }
    onSendd: {
sendmsg()
    }



}
G_gauge{
      id:g3
    title: Temper_Config.temp3
     value: gtcpmodel.tem3
    Layout.fillHeight: true
     opened:gtcpmodel.b3
    Layout.fillWidth: true
    onSw_open: {
 sendmsg()
    }
    onSw_close: {
 sendmsg()
    }
    onSendd: {
sendmsg()
    }

}
G_gauge{
    id:g4
    title: Temper_Config.temp4
     opened:gtcpmodel.b4
     value: gtcpmodel.tem4
    Layout.fillHeight: true

    Layout.fillWidth: true
    onSw_open: {
 sendmsg()
    }
    onSw_close: {
 sendmsg()
    }
    onSendd: {
sendmsg()
    }

}
G_gauge{
    id:g5
     opened:gtcpmodel.b5
    title: Temper_Config.temp5
     value: gtcpmodel.tem5
    Layout.fillHeight: true
    Layout.fillWidth: true
    onSw_open: {
 sendmsg()
    }
    onSw_close: {
 sendmsg()
    }
    onSendd: {
sendmsg()
    }

}
G_gauge{
    id:g6
     opened:gtcpmodel.b6
    title: Temper_Config.temp6
    value: gtcpmodel.tem6
    Layout.fillHeight: true
    Layout.fillWidth: true
    onSw_open: {
 sendmsg()
    }
    onSw_close: {
 sendmsg()
    }
    onSendd: {
sendmsg()
    }

}


Timer{

repeat: true
running: true
interval: 500
  property int  xx: 0
onTriggered: {
    xx++
    customPlot.addData(0,xx,gtcpmodel.tem1)
    customPlot.addData(1,xx,gtcpmodel.tem2)
    customPlot.addData(2,xx,gtcpmodel.tem3)
    customPlot.addData(3,xx,gtcpmodel.tem4)
    customPlot.addData(4,xx,gtcpmodel.tem5)

    customPlot.addData(5,xx,gtcpmodel.tem6)
}
}


  }

           Rectangle{
                    Layout.fillWidth: true
                    Layout.preferredHeight:parent.height*0.2
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
                                         {
                                            // visible:false
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
                                 pen : Pen { color : "yellow"; width : 1.0 }
                                  xAxis : Axis {
                                  useDefault : true

                           }

                           }
                            ,
                           Graph {
                             name : "温度5"
                             pen : Pen { color : Qt.black; width : 1.0 }
                             xAxis : Axis {
                             useDefault : true

                          }

                            }
                           ,
                           Graph {
                             name : "温度6"
                            pen : Pen { color : "#98A9EE"; width : 1.0 }
                             xAxis : Axis {
                              useDefault : true

                             }

                            }

                            ]



                             }

                }
Rectangle{
    Layout.fillWidth: true
    Layout.preferredHeight:parent.height*0.1
    color:CusConfig.CusConfig.backgroundColor
    RowLayout{
    anchors.fill: parent
    CusButton{
        Layout.fillHeight: true
        Layout.preferredWidth: 100
    text: "保存记录"
    onClicked: {
    gtcpmodel.stop_record()
    }
    }
    CusSwitch{
        id:allbt
        property string msg: "00"
     //   textColor: "red"
        Layout.fillHeight: true
        Layout.preferredWidth: 200
    text:checked==true? "温度全开":"全开关闭"
    onClicked: {
        if(checked){
        msg="01"
        sendmsg()
        }
        else{
         msg="00"
             sendmsg()
        }
 //   gtcpmodel.stop_record()
    }
    }
   CusSwitch{
   id:remo_c
   Layout.fillHeight: true
    Layout.preferredWidth: 200
   text:checked==true? "远程控制开":"远程控制关"
   property string rm_c: "01"
   checked: true
   onClicked: {

   if(checked){
       rm_c="01"
   sendmsg()
   }
   if(!checked){
       rm_c="00"
   sendmsg()
   }
   }
   }

    Rectangle{
Layout.fillWidth: true
Layout.fillHeight: true
ColumnLayout{
    anchors.fill: parent
CusLabel{
text: "误差分析"
Layout.fillWidth: true
Layout.preferredHeight: 30

}
CusTextField{
Layout.fillWidth: true

Layout.fillHeight: true
text: iniwr.analysetxt
}
   }
    }

    }
}
      }
      Component.onDestruction: {

      console.log("destroy")

          sendcloseall()
      }
           Component.onCompleted: {


//customPlot.setRange_tpe( {"lo":0,"up":100},2);
tcpc.toggleConnect(true,iniwr.ip,iniwr.port)
  }

Timer{
id:det
interval: 10000
repeat: false

}

    function  appenddata(){


    }
    function sendmsg(){


       var str=allbt.msg+"#"+
       g1.swh+"#"+g2.swh+"#"+g3.swh+"#"+g4.swh+"#"+g5.swh+"#"+g6.swh+"#"+
       remo_c.rm_c+"#"+
       g1.temperature+"#"+g2.temperature+"#"+g3.temperature+"#"+g4.temperature+"#"+g5.temperature+"#"+g6.temperature+"#"+
       g1.dev+"#"+g2.dev+"#"+g3.dev+"#"+g4.dev+"#"+g5.dev+"#"+g6.dev
console.log((str))
        console.log(gtcpmodel.str2hex(str))
      tcpc.write(gtcpmodel.str2tobyte(str))
//tcpc.send(gtcpmodel.str2hex(str))
    }


    function sendcloseall(){
        var str="00"+"#"+
        "00"+"#"+"00"+"#"+"00"+"#"+"00"+"#"+"00"+"#"+"00"+"#"+
        "01"+"#"+
        g1.temperature+"#"+g2.temperature+"#"+g3.temperature+"#"+g4.temperature+"#"+g5.temperature+"#"+g6.temperature+"#"+
        g1.dev+"#"+g2.dev+"#"+g3.dev+"#"+g4.dev+"#"+g5.dev+"#"+g6.dev

       tcpc.write(gtcpmodel.str2tobyte(str))

        det.start()
    }
    }


