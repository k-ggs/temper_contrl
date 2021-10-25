#include "g_tcp_model.h"
g_tcp_model *gtcpmodel=new g_tcp_model();
g_tcp_model::g_tcp_model(QObject *parent):QObject(parent)
{

}
g_tcp_model::~g_tcp_model()
{


}
void g_tcp_model::setTem1(float d){
_tem1=d;
emit tem1Changed(d);
}
void g_tcp_model::setTem2(float d){
    _tem2=d;
    emit tem2Changed(d);
}
void g_tcp_model::setTem3(float d){
    _tem3=d;
    emit tem3Changed(d);
}
void g_tcp_model::setTem4(float d){
    _tem4=d;
    emit tem4Changed(d);
}
void g_tcp_model::setTem5(float d){
    _tem5=d;
    emit tem5Changed(d);
}
void g_tcp_model::setTem6(float d){
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
// QString ascData = TK::bin2ascii(buf, static_cast<uint>(length));
// QString hexData = TK::bin2hex(buf,static_cast<uint>(length));
// qDebug()<<"ascData"<<ascData;
 //qDebug()<<"hexData"<<hexData;
 char *data=new char[length];
 strcpy_s(data,length,buf);
if(length>24){
   // char *t1=new char[4];
  //  strcpy_s(t1,4,buf);
  //  memcpy_s(t1,0,buf,4);
    int i=length-4;
  char d= *data>>i;
    setTem1(TK::char_to_float( &d));
    delete[] data;
}
}
