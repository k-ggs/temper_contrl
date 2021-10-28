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
   //Q_ENUM(SAKEnumTextFormatInput);
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
  //  Q_ENUM(SAKEnumTextFormatOutput);


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
    static unsigned char* Float_to_Byte(float f);
    static float Byte_to_Float(unsigned char *p);

    static unsigned char *float_to_char(float f,unsigned  char *s);
    static float char_to_float(unsigned char *s);
    static float char_to_float_c( unsigned char *s);
    static void   char2float(unsigned char *chrNum, float &fNum);
    static float CharToFloat(unsigned char * str);
    static bool isLittleEndian()  ;
    static QByteArray stringToByteArray(QString &origingString, SAKEnumTextFormatInput format);
   static void Float2QBytearry(QByteArray &b,float d,bool bigEndian =true );
  static QString byteArrayToString(QByteArray &origingData,
                                                     SAKEnumTextFormatOutput format);
   static  char convertCharToHex(char ch);
  static void  convertStringToHex(const QString &str, QByteArray &byteData);

   static   int  bytesToInt(const QByteArray &bytes,int size = 4 );
};

#endif // __TOOLKIT_H__

