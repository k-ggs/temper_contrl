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
    implicitWidth: 1600
    implicitHeight: 980


    ValueSource {
       // id: valueSource
    }

    property bool isMaximized : false

       ColumnLayout{
       id:root1
       anchors.fill: parent
       spacing: 0
       Rectangle{
           id:title

       Layout.fillWidth: true
       Layout.preferredHeight: 60


       Taotitle_ui{
        anchors.fill: parent

    }

       }


       ListModel{
           id:gauge_p
           ListElement{
             name:"guage"
             source:"qrc:/Gauge_view_ui.qml"
               }
          // ListElement{
           //    name:"plot"
             //  source:"qrc:/Plot_view_ui.qml"

         // }

       }
       Rectangle{
       id:content

       Layout.fillWidth: true
       Layout.fillHeight: true
      // border.width: 1
       ColumnLayout{
       spacing:0
       anchors.fill: parent
       Item {

       Layout.preferredHeight:content.height*0.7
       Layout.fillWidth: true
          Layout.margins: 1

       ListView{
           id:lis
snapMode: ListView.NoSnap
spacing: 0
anchors.fill: parent
model:gauge_p
currentIndex: 1
orientation :ListView.Horizontal
delegate:
Loader{width: lis.width
    height: lis.height
    anchors.fill: lis
    source: model.source}


}



       }
       ColumnLayout{
       Layout.fillWidth: true
       Layout.fillHeight: true
       spacing: 0
       Layout.leftMargin: 1
       Layout.rightMargin: 1
       Layout.bottomMargin: 1
       Layout.alignment: Qt.AlignTop
       Rectangle{
           Layout.fillWidth: true
           Layout.preferredHeight: 200
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

                   Timer {
                             interval: 150; running: true; repeat: true

                             property double xCurr: 0.0

                             onTriggered: {

                                 var newX = 0.0;
                                 var newY =0.0;
                                 var newY2=0.0 ;
                                   var newY3=0.0 ;
                             //    for (var i = 0; i < 5; i++)
                              //   {
                                     newX = xCurr;
                                  //   newY = Math.sin(xCurr*Math.PI/100.0);
                                     // newY2 = Math.cos(xCurr*Math.PI/100.0);
                                //  newY3 = Math.tan(xCurr*Math.PI/100.0);
                                     xCurr += 1;
                                  // customPlot.addData(0,  xCurr,   valueSource.kph);
                                  // customPlot.addData(1,  xCurr,   valueSource.temperature);
                                 //  customPlot.addData(2,  xCurr,  valueSource.kph+ valueSource.rpm);
                                 //  customPlot.addData(3,  xCurr,  2* valueSource.rpm);
                                 //  customPlot.addData(4,  xCurr,  valueSource.kph+  valueSource.rpm);
                                //   customPlot.addData(5,  xCurr,   valueSource.kph/2+  valueSource.rpm);
                             //    console.log(xCurr)
                              //   }



                             }
                         }


                    }

       }
       Rectangle{
           visible: false
           id:rec_con
           Layout.fillWidth: true
           Layout.fillHeight: true
           color:CusConfig.backgroundColor
           Loader{

               width: rec_con.width
               height: rec_con.height
               source: "qrc:/Contral_ui.qml"}

           }

       }
       }

       }


       }
       Component.onCompleted: {


     customPlot.setRange_tpe( {"lo":-10},2);
     tcpc.toggleConnect(true,iniwr.ip,iniwr.port)
       }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.25}
}
##^##*/
