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


if(buf){
QByteArray b(buf,length);//size!
//b.resize(length);

//qDebug()<<"buf size"<<b.length();
//qDebug()<<"buf size"<<b;

int R_datalen=6;
int R_boolLen=1;
int byte_len=4;
int R_tlen=R_datalen*byte_len;
QByteArray Qtemp=b.left(R_tlen);
 float ft[6];
for(int i=0;i<R_datalen;i++){

    QByteArray temp;

    if(TK::isLittleEndian()){

        temp.append(Qtemp[i*4+3]);
         temp.append(Qtemp[i*4+2]);
          temp.append(Qtemp[i*4+1]);
           temp.append(Qtemp[i*4+0]);

           float f=0.0;
           memcpy(&f,temp,sizeof (f));
           if(abs(f)<1||abs(f)>1000){
               f=0.0;
           }
           ft[i]=f;
    }else{

        temp.append(Qtemp[i*4+0]);
         temp.append(Qtemp[i*4+1]);
          temp.append(Qtemp[i*4+2]);
           temp.append(Qtemp[i*4+3]);

           float f=0.0;
           memcpy(&f,temp,sizeof (f));
          if(abs(f)<1||abs(f)>1000){
               f=0.0;
           }
           ft[i]=f;

    }

}
//qDebug()<<b.length();
//qDebug()<<b.toHex();
char boolt=b[R_datalen*4];

bool bl[8];

memcpy(&bl,&boolt,sizeof (bl));
QString dc= QString("%1").arg(QString::number(boolt,2),sizeof (boolt)*8,'0');

setTem1(ft[0]);
setTem2(ft[1]);
setTem3(ft[2]);
setTem4(ft[3]);
setTem5(ft[4]);
setTem6(ft[5]);
//qDebug()<<"dc"<<dc;
//qDebug()<<"Tem"<<_tem1<<_tem2<<_tem3<<_tem4<<_tem5<<_tem6;
setB1(dc.at(0)==1?true:false);
setB2(dc.at(1)==1?true:false);
setB3(dc.at(2)==1?true:false);
setB4(dc.at(3)==1?true:false);
setB5(dc.at(4)==1?true:false);
setB6(dc.at(5)==1?true:false);
QString ds=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz")+","+QString::number( _tem1,'f')+","+QString::number( _tem2,'f')+","+QString::number( _tem3,'f')+","+QString::number( _tem4,'f')+","+QString::number( _tem5,'f')+","+QString::number( _tem6,'f')+"\n";


    record.append(ds);
  

}

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

QByteArray g_tcp_model::str2hex(QString value){


QStringList das=value.split('#');
if(value.length()<19){

    qDebug()<<"长度不足";
}
QString hex_all0= das[0];

QString hex_b1= das[1];
QString hex_b2= das[2];
QString hex_b3= das[3];
QString hex_b4= das[4];
QString hex_b5= das[5];
QString hex_b6= das[6];

QByteArray hex_b7;

qint8 v1 = QString(hex_all0).toInt(Q_NULLPTR, 16);
qint8 v2 = QString(hex_b1).toInt(Q_NULLPTR, 16);
qint8 v3 = QString(hex_b2).toInt(Q_NULLPTR, 16);
qint8 v4 = QString(hex_b3).toInt(Q_NULLPTR, 16);
qint8 v5 = QString(hex_b4).toInt(Q_NULLPTR, 16);
qint8 v6 = QString(hex_b5).toInt(Q_NULLPTR, 16);
qint8 v7 = QString(hex_b6).toInt(Q_NULLPTR, 16);

hex_b7.append(reinterpret_cast<char*>(&v1),1);
hex_b7.append(reinterpret_cast<char*>(&v2),1);
hex_b7.append(reinterpret_cast<char*>(&v3),1);
hex_b7.append(reinterpret_cast<char*>(&v4),1);
hex_b7.append(reinterpret_cast<char*>(&v5),1);
hex_b7.append(reinterpret_cast<char*>(&v6),1);
hex_b7.append(reinterpret_cast<char*>(&v7),1);

QByteArray b1;
QByteArray b2;
QByteArray b3;
QByteArray b4;
QByteArray b5;
QByteArray b6;
 TK::Float2QBytearry(b1,das[7].toFloat(),false);
 TK::Float2QBytearry(b2,das[8].toFloat(),false);
 TK::Float2QBytearry(b3,das[9].toFloat(),false);
 TK::Float2QBytearry(b4,das[10].toFloat(),false);
 TK::Float2QBytearry(b5,das[11].toFloat(),false);
 TK::Float2QBytearry(b6,das[12].toFloat(),false);

QByteArray d1;
QByteArray d2;
QByteArray d3;
QByteArray d4;
QByteArray d5;
QByteArray d6;
TK::Float2QBytearry(d1,das[13].toFloat(),false);
TK::Float2QBytearry(d2,das[14].toFloat(),false);
TK::Float2QBytearry(d3,das[15].toFloat(),false);
TK::Float2QBytearry(d4,das[16].toFloat(),false);
TK::Float2QBytearry(d5,das[17].toFloat(),false);
TK::Float2QBytearry(d6,das[18].toFloat(),false);

QByteArray rt;
rt.append(hex_b7);



rt.append(b1);
rt.append(b2);
rt.append(b3);
rt.append(b4);
rt.append(b5);
rt.append(b6);


rt.append(d1);
rt.append(d2);
rt.append(d3);
rt.append(d4);
rt.append(d5);
rt.append(d6);
return rt;

}
QByteArray g_tcp_model::str2tobyte(QString value){


QStringList das=value.split('#');
if(value.length()<19){

    qDebug()<<"长度不足";
}
QString hex_all0= das[0];

QString hex_b1= das[1];
QString hex_b2= das[2];
QString hex_b3= das[3];
QString hex_b4= das[4];
QString hex_b5= das[5];
QString hex_b6= das[6];
//QByteArray hexb1=hex_b1.toLatin1();
//QByteArray hexb2=hex_b2.toLatin1();
//QByteArray hexb3=hex_b3.toLatin1();
//QByteArray hexb4=hex_b4.toLatin1();
//QByteArray hexb5=hex_b5.toLatin1();
//QByteArray hexb6=hex_b6.toLatin1();



QByteArray b1;
QByteArray b2;
QByteArray b3;
QByteArray b4;
QByteArray b5;
QByteArray b6;
 TK::Float2QBytearry(b1,das[7].toFloat(),false);
 TK::Float2QBytearry(b2,das[8].toFloat(),false);
 TK::Float2QBytearry(b3,das[9].toFloat(),false);
 TK::Float2QBytearry(b4,das[10].toFloat(),false);
 TK::Float2QBytearry(b5,das[11].toFloat(),false);
 TK::Float2QBytearry(b6,das[12].toFloat(),false);

QByteArray d1;
QByteArray d2;
QByteArray d3;
QByteArray d4;
QByteArray d5;
QByteArray d6;
TK::Float2QBytearry(d1,das[13].toFloat(),false);
TK::Float2QBytearry(d2,das[14].toFloat(),false);
TK::Float2QBytearry(d3,das[15].toFloat(),false);
TK::Float2QBytearry(d4,das[16].toFloat(),false);
TK::Float2QBytearry(d5,das[17].toFloat(),false);
TK::Float2QBytearry(d6,das[18].toFloat(),false);

QString hex_f1=  b1.toHex(' ');
QString hex_f2=  b2.toHex(' ');
QString hex_f3=  b3.toHex(' ');
QString hex_f4=  b4.toHex(' ');
QString hex_f5=  b5.toHex(' ');
QString hex_f6=  b6.toHex(' ');

QString hex_df1= d1.toHex(' ');
QString hex_df2= d2.toHex(' ');
QString hex_df3= d3.toHex(' ');
QString hex_df4= d4.toHex(' ');
QString hex_df5= d5.toHex(' ');
QString hex_df6= d6.toHex(' ');
QString s=hex_all0+' '+
        hex_b1+' '+hex_b2+' '+hex_b3+' '+hex_b4+' '+hex_b5+' '+hex_b6+' '+
        hex_f1+' '+hex_f2+' '+hex_f3+' '+hex_f4+' '+hex_f5+' '+hex_f6+' '+
        hex_df1+' '+hex_df2+' '+hex_df3+' '+hex_df4+' '+hex_df5+' '+hex_df6;
//qDebug()<<b1;
//qDebug()<<s.toLocal8Bit();
QByteArray ar=TK::stringToByteArray(s,TK::InputFormatHex);
//qDebug()<<ar;
return ar;

}
