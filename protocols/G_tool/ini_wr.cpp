#include "ini_wr.h"
ini_wr *iniwr =new ini_wr();
ini_wr::ini_wr(QObject * parent):QObject(parent)
{

}







void ini_wr::readdefault()
{
 QSettings setFile( QCoreApplication::applicationDirPath()+"/config.ini",QSettings::IniFormat);
setFile.setIniCodec(QTextCodec::codecForName("UTF-8"));
_ip=setFile.value("Addres/ip").toString();
_port=setFile.value("Addres/port").toInt();
qDebug()<<_ip;
qDebug()<<_port;
tempmax=setFile.value("Range/tempmax").toInt();
 _Readtemps=setFile.value("Read/temp").toString().split(',');
  _Readstates=setFile.value("Read/statetemp").toString().split(',');

   _Writestates=setFile.value("Write/state").toString().split(',');
   _Writetemps=setFile.value("Write/temp").toString().split(',');
   _Writedeviation=setFile.value("Write/deviation").toString().split(',');
}


