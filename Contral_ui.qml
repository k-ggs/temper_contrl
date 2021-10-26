import QtQuick 2.0
import QtQuick.Layouts 1.3
import "./TaoQuick"
import"./Tao_custom_Qml/Biz"
import"./Tao_custom_Qml/content"


Rectangle{
anchors.fill: parent
ColumnLayout{
anchors.fill: parent
GridLayout{
Layout.fillHeight: true
Layout.fillWidth: true
columns: 3
rows: 2
id:root
columnSpacing: 5
rowSpacing: 5
property int cslwdt : 300

CusButton{
text: "保存记录"
onClicked: {
gtcpmodel.stop_record()
}
}
/*
CusSlider_Spin{
    txt:Temper_Config.temp1
    Layout.preferredWidth: root.cslwdt
    from:1
    to:100
}
CusSlider_Spin{
     txt:Temper_Config.temp2
    Layout.preferredWidth: root.cslwdt
    from:1
    to:100
}
CusSlider_Spin{
      txt:Temper_Config.temp3
    Layout.preferredWidth: root.cslwdt
    from:1
    to:100
}
CusSlider_Spin{
      txt:Temper_Config.temp4
    Layout.preferredWidth: root.cslwdt
    from:1
    to:100
}
CusSlider_Spin{
      txt:Temper_Config.temp5
    Layout.preferredWidth: root.cslwdt
    from:1
    to:100
}
CusSlider_Spin{
      txt:Temper_Config.temp5
    Layout.preferredWidth: root.cslwdt
    from:1
    to:100


}
*/

}

}

}

