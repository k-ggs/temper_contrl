#ifndef __TOOLKIT_H__
#define __TOOLKIT_H__

#include <QGlobalStatic>
#include <QVector>
#include <QHostAddress>

class QAbstractSocket;

typedef struct _IPAddr
{
    QHostAddress ip;
    quint16 port;
} IPAddr;

class TK
{
public:
    // Input text format
    enum SAKEnumTextFormatInput {
        InputFormatBin,
        InputFormatOct,
        InputFormatDec,
        InputFormatHex,
        InputFormatAscii,
        InputFormatLocal
    };
   Q_ENUM(SAKEnumTextFormatInput);
    // Output text format
    enum SAKEnumTextFormatOutput {
        OutputFormatBin,
        OutputFormatOct,
        OutputFormatDec,
        OutputFormatHex,
        OutputFormatUcs4,
        OutputFormatUtf8,
        OutputFormatUtf16,
        OutputFormatAscii,
        OutputFormatLocal,
    };
    Q_ENUM(SAKEnumTextFormatOutput);


    //static unsigned char byte[4];
    static const char* hextab;
    static const char* hextab2;
    static QString ascii2hex(const QString& src, QVector<uint>& posmap, uint& count);
    static QString bin2hex(const char* buf, uint len);
    static QString bin2hex2(const char* buf, uint len);

    static QString bin2ascii(const char* buf, uint len);
    static bool ascii2bin(const QString& src, QByteArray& dst, QString& err);

    static char* createBuffer(qint64& cap, qint64 limit);
    static void  releaseBuffer(char*& buf);

    static const char* socketTypeName(bool tcp);
    static const char* socketTypeName(QAbstractSocket* skt);

    static QString ipstr(const QHostAddress& addr, quint16 port);
    static QString ipstr(const QHostAddress& addr, quint16 port, bool tcp);
    static  char* Float_to_Byte(float f);
    static float Byte_to_Float( char *p);

    static  char *float_to_char(float f,  char *s);
    static float char_to_float( char *s);
    static float char_to_float_c( char *s);
    static void   char2float(char *chrNum, float &fNum);
    static float CharToFloat( char * str);
    static bool isLittleEndian()  ;
    static QByteArray stringToByteArray(QString &origingString, SAKEnumTextFormatInput format);
   static void Float2QBytearry(QByteArray &b,float d,bool bigEndian =true );
   QString byteArrayToString(QByteArray &origingData,
                                                     SAKEnumTextFormatOutput format);
};

#endif // __TOOLKIT_H__

