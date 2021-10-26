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
//QString hexData = TK::bin2hex2(buf,static_cast<uint>(length));
//   char *data= const_cast<char*>(buf);

 //char *data=new char[length+1];
 //strcpy_s(data,length+1,buf);
QString bb="428D0000";

if(length>24){

QByteArray b= bb.toLatin1();
    setTem1(TK::CharToFloat( b.left(4).data()));
  float tt;
 // TK::char2float( d,tt);
//setTem1(tt);
    qDebug()<<tem1();
  //  if(record_flags){
QString ds=QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+","+QString::number( _tem1,'f')+","+QString::number( _tem2,'f')+","+QString::number( _tem3,'f')+","+QString::number( _tem4,'f')+","+QString::number( _tem5,'f')+","+QString::number( _tem6,'f')+"\n";


    record.append(ds);
   // }

}
 // delete[] data;
}
void g_tcp_model::start_record(){

    record_flags=true;

}
void g_tcp_model::stop_record(){
    record_flags=false;
    if(record.isEmpty()){
        return;
    }
QString dr= QCoreApplication::applicationDirPath()+"/record/";
QString fl= QCoreApplication::applicationDirPath()+"/record/"+QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+".csv";
    QDir d1(dr);

    if(!d1.exists())
    {
        d1.mkpath(dr);


    }



     QFile file(fl);
     if(!file.exists())
     {
         if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
              {
                  qDebug()<<"打开失败";
             }


     }
     QTextStream in(&file);
     in<< QString("t")<<","

         <<QString("t1")<<","
         <<QString("t2")<<","
         <<QString("t3")<<","
         <<QString("t4")<<","

         <<QString("t5")<<","

        <<QString("t")<<"\n";

     for(int i=0;i<record.length();i++)
     {
         in<<record[i];







     }
     file.close();


}
