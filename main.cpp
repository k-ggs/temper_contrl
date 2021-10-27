#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQuickView>
#include<QQmlContext>
#include<QtQuickControls2/QtQuickControls2>
#include"framelesswindow.h"

#include "Frameless/TaoFrameLessView.h"
#include "Logger/Logger.h"
#include "QuickTool/QuickTool.h"
#include "Trans/Trans.h"
#include"qcustom_api.h"
#include"RegisterAll.h"

#include"UdpClientModel.h"
#include "TcpServerModel.h"
#include "UdpServerModel.h"
#include "notepadmodel.h"
#include "TcpClientModel.h"

#include"ini_wr.h"
#include"g_tcp_model.h"
#include<QtEndian>
#ifdef QMAKE_GEN_TAOMACRO
    #include "taoMacro.h"
#endif
int main(int argc, char *argv[])
{
//X
   #ifndef QT_NO_DEBUG
    QString bb="428D0000";

    QByteArray b=bb.toLocal8Bit();
  QByteArray hx1=   QByteArray::fromHex(b);
    QByteArray b2;
      b2.append(hx1[3]);
      b2.append(hx1[2]);
      b2.append(hx1[1]);
      b2.append(hx1[0]);


qDebug()<<hx1.length();
 qDebug()<<b2[0]<<b2[1]<<b2[2]<<b2[3];
 qDebug()<<hx1[0]<<hx1[1]<<hx1[2]<<hx1[3];



 qDebug()<<b.length();
 qDebug()<<b;
 float f1=0.0;
 memcpy(&f1,b2,sizeof (f1));

 qDebug()<<f1;
#endif

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

Logger::initLog();
    QQmlApplicationEngine engine;
    QmlModulesInstaller::Install();
    QFontDatabase::addApplicationFont(":/Font/Resur/iconfont.ttf");
   Trans trans;
   QString transDir= ":/Resur/Trans/";
    QString imgPath="qrc:/Resur/Image/";
    trans.beforeUiReady(engine.rootContext(), transDir);
    qmlRegisterType<FramelessWindow>("FramelessWindow", 1, 0, "FramelessWindow");
      qmlRegisterType<TaoFrameLessView>("FramelessWindow", 1, 0, "TaoFramelessWindow");
    qmlRegisterType<qcustom_api>("custom_plot", 1, 0, "Qcustom");

    qmlRegisterType<TcpServerModel>("src.tcpservermodel", 1, 0, "TcpServerModel");
    qmlRegisterType<UdpClientModel>("src.UdpclientModel", 1, 0, "UdpClientModel");
    qmlRegisterType<TcpClientModel>("src.tcpclientmodel", 1, 0, "TcpClientModel");
  //qmlRegisterType<JsonFormat>("src.jsonformat",1,0,"JsonFormat");
  qmlRegisterUncreatableType<TreeItem>("src.treeitem",1,0,"TreeItem","Reference only");
   qmlRegisterUncreatableType<LogMessageModel>("src.logmessagedata",1,0,"LogMessageData","Reference only");





 iniwr->readdefault();
 //iniwr->readdefault_json();

    engine.rootContext()->setContextProperty("iniwr", iniwr);
    engine.rootContext()->setContextProperty("gtcpmodel", gtcpmodel);

    engine.rootContext()->setContextProperty("imgPath", imgPath);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

//engine.addImportPath(qmlPath);
//engine.addImportPath(qmlPath);

    engine.addImportPath(TaoQuickImportPath);
    engine.rootContext()->setContextProperty("taoQuickImagePath", TaoQuickImagePath);
    engine.load(url);

    return app.exec();
}
