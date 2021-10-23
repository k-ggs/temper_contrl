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

           color:  CusConfig.backgroundColor
  // Layout.preferredHeight:content.height*0.3
 //  Layout.preferredWidth : content.width*0.5
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
Switch{
}
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
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent

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
Switch{
}
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
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent

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
Switch{
}
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
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent

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
Switch{
}
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
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent

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
Switch{
}
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
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent

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
Switch{
}
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
         // anchors.left: parent.right
           height: parent.height
          width: 300

          color:CusConfig.themeColor


      CusSlider_Spin
      {width: 300
      anchors.fill: parent

      }


      }
}
}









  }


    }


