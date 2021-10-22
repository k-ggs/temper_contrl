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
color:  CusConfig.controlBorderColor
id:contentmsg
//Layout.fillWidth: true
//Layout.fillHeight: true
anchors.fill: parent
ColumnLayout{   anchors.fill: parent
CustomPlotItem{
Layout.fillHeight: true
Layout.fillWidth: true

id: customPlot2

        background : CusConfig.controlBorderColor//"white"
        legend: Legend{ font: "helvetica,-1,8,5,0,0,0,0,0,0"}

        graphs : [
            Graph {
                name : "油箱温度"
                pen : Pen { color : "blue"; width : 1.0 }
                scatter : ScatterStyle {
                    brush : "white"
                   // type : Scatter.ssCircle
                    size : 1
                    pen : Pen {	color : "black"; width: 1.0	}
                }
                xAxis : Axis {
                    useDefault : true
                    visible : false
                    label : Label {
                        text : "domain"
                        font : "helvetica,-1,30,5,0,0,0,0,0,0"
                        color: "blue"
                    }
                }
                yAxis : Axis
                { visible : false
                    label : Label {
                        text : "sin"
                        font : "helvetica,-1,15,5,0,0,0,0,0,0"
                        color : "red"
                    }
                }
            },
            Graph {
                name : "试验箱温度1"
                pen : Pen { color : "red"; width : 1.0 }
                xAxis : Axis {
                useDefault : true

                }
             //   yAxis : Axis
             //   {
               //     useDefault : false
              //  }
            }

            ,
            Graph {
                                        name : "试验箱温度2"
                                        pen : Pen { color : "red"; width : 1.0 }
                                        xAxis : Axis {
                                        useDefault : true

                                        }
                                     //   yAxis : Axis
                                     //   {
                                       //     useDefault : false
                                      //  }
                                    },
            Graph {
                name : "进管道温度"
                pen : Pen { color : "blue"; width : 1.0 }
                scatter : ScatterStyle {
                    brush : "white"
                   // type : Scatter.ssCircle
                    size : 1
                    pen : Pen {	color : "black"; width: 1.0	}
                }
                xAxis : Axis {
                    useDefault : true
                    visible : false
                    label : Label {
                        text : "domain"
                        font : "helvetica,-1,30,5,0,0,0,0,0,0"
                        color: "blue"
                    }
                }
                yAxis : Axis
                { visible : false
                    label : Label {
                        text : "sin"
                        font : "helvetica,-1,15,5,0,0,0,0,0,0"
                        color : "red"
                    }
                }
            },
            Graph {
                name : "出管道温度"
                pen : Pen { color : "red"; width : 1.0 }
                xAxis : Axis {
                useDefault : true

                }
             //   yAxis : Axis
             //   {
               //     useDefault : false
              //  }
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
                 var newY4=0.0 ;
                   var newY5=0.0 ;
             //    for (var i = 0; i < 5; i++)
              //   {
                     newX = xCurr;
                     newY = Math.sin(xCurr*Math.PI/100.0);
                      newY2 = Math.cos(xCurr*Math.PI/100.0);
                  newY3 = Math.sin(xCurr*Math.PI/100.0)+Math.cos(xCurr*Math.PI/100.0);
                 newY4 = 2*Math.sin(xCurr*Math.PI/100.0)+Math.tan(xCurr*Math.PI/100.0);
             newY5 =  2*Math.cos(xCurr*Math.PI/100.0)+Math.tan(xCurr*Math.PI/100.0);
                     xCurr += 1;
                      customPlot2.addData(0,  xCurr,  newY);
                        customPlot2.addData(1,  xCurr,  newY2);
                   customPlot2.addData(2,  xCurr,  newY3);
                   customPlot2.addData(3,  xCurr,  newY3);
                   customPlot2.addData(4,  xCurr,  newY3);
             //    console.log(xCurr)
              //   }



             }
         }


    }
CustomPlotItem{
Layout.fillHeight: true
Layout.fillWidth: true

id: customPlot3

        background : CusConfig.controlBorderColor//"white"
        legend: Legend{ font: "helvetica,-1,8,5,0,0,0,0,0,0"}

        graphs : [
            Graph {
                name : "出管道压力"
                pen : Pen { color : "blue"; width : 1.0 }
                scatter : ScatterStyle {
                    brush : "white"
                   // type : Scatter.ssCircle
                    size : 1
                    pen : Pen {	color : "black"; width: 1.0	}
                }
                xAxis : Axis {
                    useDefault : true
                    visible : false
                    label : Label {
                        text : "domain"
                        font : "helvetica,-1,8,1,0,0,0,0,0,0"
                        color: "blue"
                    }
                }
                yAxis : Axis
                { visible : false
                    label : Label {
                        text : "sin"
                        font : "helvetica,-1,8,1,0,0,0,0,0,0"
                        color : "red"
                    }
                }
            },
            Graph {
                                        name : "进管道压力"
                                        pen : Pen { color : "red"; width : 1.0 }
                                        xAxis : Axis {
                                        useDefault : true

                                        }
                                     //   yAxis : Axis
                                     //   {
                                       //     useDefault : false
                                      //  }
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
                     newY = Math.sin(xCurr*Math.PI/100.0);
                      newY2 = Math.cos(xCurr*Math.PI/100.0);
                  newY3 = Math.tan(xCurr*Math.PI/100.0);
                     xCurr += 1;
                      customPlot3.addData(0,  xCurr,  newY);
                        customPlot3.addData(1,  xCurr,  newY2);
                 //  customPlot3.addData(2,  xCurr,  newY3);
             //    console.log(xCurr)
              //   }



             }
         }


    }
CustomPlotItem{
Layout.fillHeight: true
Layout.fillWidth: true

id: customPlot4

        background : CusConfig.controlBorderColor//"white"
        legend: Legend{ font: "helvetica,-1,2,2,0,0,0,0,0,0"}

        graphs : [

            Graph {
                name : "流量"
                pen : Pen { color : "red"; width : 1.0 }
                xAxis : Axis {
                useDefault : true

                }
             //   yAxis : Axis
             //   {
               //     useDefault : false
              //  }
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
                     newY = Math.sin(xCurr*Math.PI/100.0);
                      newY2 = Math.cos(xCurr*Math.PI/100.0);
                  newY3 = Math.tan(xCurr*Math.PI/100.0);
                     xCurr += 1;
                      customPlot4.addData(0,  xCurr,  newY);
                    //    customPlot4.addData(1,  xCurr,  newY2);
                 //  customPlot4.addData(2,  xCurr,  newY3);
             //    console.log(xCurr)
              //   }



             }
         }


    }



}
Component.onCompleted: {

      //qcplot.initCustomPlot()
}
}



