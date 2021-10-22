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
#ifdef QMAKE_GEN_TAOMACRO
    #include "taoMacro.h"
#endif
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);


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




    engine.rootContext()->setContextProperty("imgPath", imgPath);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
//engine.addImportPath(qmlPath);
 //   engine.addImportPath(qmlPath);
    engine.addImportPath(TaoQuickImportPath);
    engine.rootContext()->setContextProperty("taoQuickImagePath", TaoQuickImagePath);
    engine.load(url);

    return app.exec();
}
