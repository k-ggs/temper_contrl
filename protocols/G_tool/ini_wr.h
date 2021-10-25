#ifndef INI_WR_H
#define INI_WR_H
#include<QtDebug>
#include <QObject>
#include<QSettings>
#include<QCoreApplication>
#include<QTextCodec>
#include<QFile>
#include<QCryptographicHash>
class ini_wr;
extern ini_wr *iniwr;
class ini_wr:public QObject
{
     Q_OBJECT




     Q_PROPERTY(QString ip READ ip )
     Q_PROPERTY(int port READ port )
     Q_PROPERTY(QStringList Readtemps   READ Readtemps )
     Q_PROPERTY(QStringList Readstates  READ Readstates )
     Q_PROPERTY(QStringList Writestates READ Writestates )
     Q_PROPERTY(QStringList Writetemps  READ Writetemps )
     Q_PROPERTY(QStringList Writedeviation READ Writedeviation )
    //Q_PROPERTY(QStringList port READ port )

public:
explicit    ini_wr(QObject * parent=nullptr);

    QString ip()const{return _ip;};
    int port()const{return _port;};
     void readdefault();
  int tempmax=80;
  QStringList Readtemps()const{return _Readtemps;}
  QStringList Readstates()const{return _Readstates;}
  QStringList Writestates()const{return _Writestates;}
  QStringList Writetemps()const{return _Writetemps;}
  QStringList Writedeviation()const{return _Writedeviation;}

private:

  QString _ip;
  int _port=2000;

  QStringList _Readtemps;
  QStringList _Readstates;
  QStringList _Writestates;
  QStringList _Writetemps;
  QStringList  _Writedeviation;




};

#endif // INI_WR_H
