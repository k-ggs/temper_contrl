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

   _tempmax=setFile.value("Range/tempmax").toInt();
   qDebug()<<setFile.value("Read/statetemp").toString();
   _Readtemps=setFile.value("Read/temp").toString().split('#');
   _Readstates=setFile.value("Read/statetemp").toString().split('#');
   qDebug()<<_Readstates[0];
   _Writestates=setFile.value("Write/state").toString().split('#');
   _Writetemps=setFile.value("Write/temp").toString().split('#');
   _Writedeviation=setFile.value("Write/deviation").toString().split('#');


   _defaulttemp=setFile.value("default/temp").toInt();
   _defaultdeva=setFile.value("default/deva").toInt();

   _analysetxt=setFile.value("analysetxt/value").toString();
   qDebug()<<_analysetxt;
}


void ini_wr::readdefault_json()
{  QFile file(QCoreApplication::applicationDirPath()+ "/ini.json");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))

    {

        qDebug()<<"Can't open the file!"<<endl;

    }
    QString displayString;
    while(!file.atEnd())

    {

        QByteArray line = file.readLine();

        QString str(line);

        qDebug()<< str;

        displayString.append(str);

    }
    JsonFormat Json;
    Json.checkJonsStr(displayString);
    Json.convertJsonToTreeModel(displayString);
#ifndef QT_NO_DEBUG
   qDebug()<<" Json.jsonModel()"<< Json.jsonModel()->rootItem->m_childItems[0]->itemData();
   qDebug()<<Json.jsonModel()->rootItem->child(0)->m_childItems[0]->itemData();
   qDebug()<<Json.jsonModel()->rootItem->child(0)->m_childItems[0]->childCount();
   qDebug()<<Json.jsonModel()->rootItem->child(0)->m_childItems[0]->child(1)->itemData();
   qDebug()<<Json.jsonModel()->rootItem->child(0)->m_childItems[0]->child(1)->property()->value();
   qDebug()<<Json.jsonModel()->rootItem->child(0)->m_childItems[0]->child(1)->property()->type();
#endif

QVector< TreeItem *>t= Json.jsonModel()->rootItem->child(0)->m_childItems;

   _ip=  t[0]->child(0)->property()->value();
 qDebug()<<_ip;
   _port=t[0]->child(1)->property()->value().toInt();

 qDebug()<<_port;


      _defaulttemp=t[1]->child(0)->property()->value().toInt();
 qDebug()<<_defaulttemp;

   _defaultdeva=t[1]->child(1)->property()->value().toInt();
  qDebug()<<_defaultdeva;
 _tempmax=t[2]->child(0)->property()->value().toInt();
 qDebug()<<_tempmax;
   _Readstates=t[3]->child(0)->property()->value().split('#');
  qDebug()<<_Readstates;
 _Readtemps=t[3]->child(1)->property()->value().split('#');
 qDebug()<<_Readtemps;
   _Writestates=t[4]->child(0)->property()->value().split('#');
   qDebug()<<_Writestates;
 _Writetemps=t[4]->child(1)->property()->value().split('#');
  qDebug()<<"_Writetemps"<<_Writetemps;
   _Writedeviation=t[4]->child(2)->property()->value().split('#');

 qDebug()<<"_Writedeviation"<<_Writedeviation;









   qDebug()<< _Readtemps;
  qDebug()<<  _Readstates;

   qDebug()<< _Writestates;
   qDebug()<< _Writetemps;
  qDebug()<<  _Writedeviation;
}
