#ifndef G_TCP_MODEL_H
#define G_TCP_MODEL_H

#include <QObject>
#include "toolkit.h"
#include<QDir>
#include<QFile>
#include<QCoreApplication>
#include<QDateTime>
class g_tcp_model;
extern g_tcp_model *gtcpmodel;
class g_tcp_model:public QObject
{
    Q_OBJECT

    Q_PROPERTY(float tem1 READ tem1 WRITE setTem1 NOTIFY tem1Changed)
    Q_PROPERTY(float tem2 READ tem2 WRITE setTem2 NOTIFY tem2Changed)
    Q_PROPERTY(float tem3 READ tem3 WRITE setTem3 NOTIFY tem3Changed)
    Q_PROPERTY(float tem4 READ tem4 WRITE setTem4 NOTIFY tem4Changed)
    Q_PROPERTY(float tem5 READ tem5 WRITE setTem5 NOTIFY tem5Changed)
    Q_PROPERTY(float tem6 READ tem6 WRITE setTem6 NOTIFY tem6Changed)


    Q_PROPERTY(bool b1 READ b1 WRITE setB1 NOTIFY b1Changed)
    Q_PROPERTY(bool b2 READ b2 WRITE setB2 NOTIFY b2Changed)
    Q_PROPERTY(bool b3 READ b3 WRITE setB3 NOTIFY b3Changed)
    Q_PROPERTY(bool b4 READ b4 WRITE setB4 NOTIFY b4Changed)
    Q_PROPERTY(bool b5 READ b5 WRITE setB5 NOTIFY b5Changed)
    Q_PROPERTY(bool b6 READ b6 WRITE setB6 NOTIFY b6Changed)

public:

    g_tcp_model(QObject *parent=nullptr);
    ~g_tcp_model();

    float tem1()const{return _tem1;}
    float tem2()const{return _tem2;}
    float tem3()const{return _tem3;}
    float tem4()const{return _tem4;}
    float tem5()const{return _tem5;}
    float tem6()const{return _tem6;}

     bool b1() const{return _b1;}
     bool b2() const{return _b2;}
     bool b3() const{return _b3;}
     bool b4() const{return _b4;}
     bool b5() const{return _b5;}
     bool b6() const{return _b6;}

 public slots:

     void setTem1(float d);
     void setTem2(float d);
     void setTem3(float d);
     void setTem4(float d);
     void setTem5(float d);
     void setTem6(float d);

     void setB1(bool d);
     void setB2(bool d);
     void setB3(bool d);
     void setB4(bool d);
     void setB5(bool d);
     void setB6(bool d);

     void Convert_date( QString &host,const char* buf, qint64 length);

     void start_record();
     void stop_record();

    signals:

    void tem1Changed(float d);
    void tem2Changed(float d);
    void tem3Changed(float d);
    void tem4Changed(float d);
    void tem5Changed(float d);
    void tem6Changed(float d);

    void b1Changed(bool d);
    void b2Changed(bool d);
    void b3Changed(bool d);
    void b4Changed(bool d);
    void b5Changed(bool d);
    void b6Changed(bool d);
private:
    float _tem1=0;
    float _tem2=0;
    float _tem3=0;
    float _tem4=0;
    float _tem5=0;
    float _tem6=0;


    bool _b1=false;
    bool _b2=false;
    bool _b3=false;
    bool _b4=false;
    bool _b5=false;
    bool _b6=false;

    bool record_flags=false;

    QVector<QString> record;
};

#endif // G_TCP_MODEL_H
