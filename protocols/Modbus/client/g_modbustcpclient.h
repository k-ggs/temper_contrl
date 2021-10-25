#ifndef G_MODBUSTCPCLIENT_H
#define G_MODBUSTCPCLIENT_H

#include <QWidget>
#include <QJsonArray>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QModbusDevice>
#include <QModbusServer>
#include<QModbusClient>
#include <QModbusTcpServer>
#include <QModbusDataUnit>
#include <QModbusTcpClient>
#include<QFile>
#include<QJsonObject>
#include<QJsonDocument>
class G_modbusTcpclient:public QObject
{
    Q_OBJECT
public:
    G_modbusTcpclient(QObject *parent = Q_NULLPTR);
    ~G_modbusTcpclient();
     void setData(QModbusDataUnit::RegisterType type, quint16 address, quint16 value) ;
     quint16 registerValue(QModbusDataUnit::RegisterType type, quint16 address) ;
     void exportRegisterData() ;
     void importRegisterData() ;

    bool tempData(QModbusDataUnit::RegisterType table, quint16 address, quint16 *data);

    void closeDevice();

    QModbusDevice *device();
     void init();

     struct ParametersContext{
         QString host;
         quint16 port;
         int timeout;
         int numberOfRetries;
     };
   void open(ParametersContext par1);
private:

    QModbusTcpClient *mDevice;
    quint16 mRegisterNumber;
    QMap<QModbusDataUnit::RegisterType, QString> mInfoMap;
    int mAllRegisterCount;
protected:
 QModbusServer *mModbusServer;
    void sendReadRequest(QModbusDataUnit mdu, quint16 slaveAddress);
    void sendWriteRequest(QModbusDataUnit mdu, quint16 slaveAddress);
private:
    void readReply();

protected:

    //You should implement this function and do not calling it in the sub class.
    //You can use device() to get the device instance.
    virtual QModbusTcpClient *initModbusDevice();

    void setModbusServerMap(QModbusServer *server);
    QString getSaveFileName();
    QString getOpenFileName();
    void saveServerRegisterData(QModbusServer *server, QString fileName);
    // The file is the json file.
    void setServerRegisterData(QModbusServer *server, QString fileName);


signals:
    void deviceStateChanged();
    void modbusDataUnitRead(QModbusDataUnit mdu);
    void modbusDataUnitWritten(QModbusDataUnit mdu);
    // The signal is for QModbusServer device only
    void dataWritten(QModbusDataUnit::RegisterType table, int address, int size);
    void invokeOutputMessage(QString msg, bool isErrorMsg = false);
};




#endif // G_MODBUSTCPCLIENT_H
