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

       Layout.preferredHeight:content.height*0.9
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
     //  Layout.fillWidth: true
     //  Layout.fillHeight: true
       spacing: 0
       Layout.leftMargin: 1
       Layout.rightMargin: 1
       Layout.bottomMargin: 1
       Layout.alignment: Qt.AlignTop

       Rectangle{

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


     //customPlot.setRange_tpe( {"lo":-10},2);
     //tcpc.toggleConnect(true,iniwr.ip,iniwr.port)
       }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.25}
}
##^##*/
