#include "g_tcp_model.h"
g_tcp_model *gtcpmodel=new g_tcp_model();
g_tcp_model::g_tcp_model(QObject *parent):QObject(parent)
{

}
g_tcp_model::~g_tcp_model()
{


}
void g_tcp_model::setTem1(double d){
_tem1=d;
emit tem1Changed(d);
}
void g_tcp_model::setTem2(double d){
    _tem2=d;
    emit tem2Changed(d);
}
void g_tcp_model::setTem3(double d){
    _tem3=d;
    emit tem3Changed(d);
}
void g_tcp_model::setTem4(double d){
    _tem4=d;
    emit tem4Changed(d);
}
void g_tcp_model::setTem5(double d){
    _tem5=d;
    emit tem5Changed(d);
}
void g_tcp_model::setTem6(double d){
    _tem6=d;
    emit tem6Changed(d);
}

void g_tcp_model::setB1(bool d){
_b1=d;
emit b1Changed(d);
}
void g_tcp_model::setB2(bool d){
    _b2=d;
    emit b2Changed(d);
}
void g_tcp_model::setB3(bool d){
    _b3=d;
    emit b3Changed(d);
}
void g_tcp_model::setB4(bool d){
    _b4=d;
    emit b4Changed(d);
}
void g_tcp_model::setB5(bool d){
    _b5=d;
    emit b5Changed(d);
}
void g_tcp_model::setB6(bool d){
    _b6=d;
    emit b6Changed(d);
}
void g_tcp_model::Convert_date( QString &host,const char* buf, qint64 length){
 QString ascData = TK::bin2ascii(buf, static_cast<uint>(length));
 QString hexData = TK::bin2hex(buf,static_cast<uint>(length));
 qDebug()<<"ascData"<<ascData;
 qDebug()<<"hexData"<<hexData;

}
