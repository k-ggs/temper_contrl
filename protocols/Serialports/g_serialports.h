#ifndef G_SERIALPORTS_H
#define G_SERIALPORTS_H

#include <QMenu>
#include <QMutex>
#include <QThread>
#include <QSettings>
#include <QWaitCondition>
#include<QDebug>
#include <QSerialPort>
class g_serialports:public QThread
{
    Q_OBJECT
public:
    g_serialports(QObject *parent = Q_NULLPTR);
protected:
    bool initialize() ;
    QByteArray read() ;
    QByteArray write(const QByteArray &bytes) ;
    void uninitialize() ;
private:
    QSerialPort *mSerialPort;

    struct SAKDeviceProtectedSignal {};
    struct SAKStructSettingsKeyContext {
        QString portName;
        QString frameInterval;
        QString usingCustomBaudRate;
        QString baudRate;
    }mSettingsKeyContext;

    struct SAKStructSerialPortParametersContext {
        QString portName;
        qint32 baudRate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
        QSerialPort::FlowControl flowControl;

        int frameIntervel;
    }SAKSerialPortParametersContext;
signals:
    void bytesWritten(QByteArray bytes);
    void bytesRead(QByteArray bytes);
    void errorOccurred(QString error);

     void readyRead(g_serialports::SAKDeviceProtectedSignal);
};

#endif // G_SERIALPORTS_H
