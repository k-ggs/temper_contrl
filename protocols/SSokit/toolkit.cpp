#include <QNetworkInterface>
#include <QAbstractSocket>
#include <QCoreApplication>
#include <QAction>

#include "toolkit.h"
 typedef enum { OUT=0, OUT2IN, IN, ERR } PARSE_STA;
const char* TK::socketTypeName(bool tcp)
{
	return tcp ? "TCP" : "UDP";
}

const char* TK::socketTypeName(QAbstractSocket* skt)
{
	return (skt->socketType()==QAbstractSocket::TcpSocket) ? "TCP" : "UDP";
}


QString TK::ipstr(const QHostAddress& addr, quint16 port)
{
    return addr.toString() + ':' + QString::number(port);
}

QString TK::ipstr(const QHostAddress& addr, quint16 port, bool tcp)
{
    return QString("%1 %2").arg((tcp?"[TCP]":"[UDP]"),ipstr(addr,port));
}


const char* TK::hextab = "0123456789ABCDEF";
const char* TK::hextab2 = "FEDCBA9876543210";
#define TOHEXSTR(v, c, tab) \
		if (v) { \
			*c++ = tab[(v>>4)&0xF]; \
			*c++ = tab[v & 0xF]; \
		}

QString TK::ascii2hex(const QString& src, QVector<uint>& posmap, uint& count)
{
	posmap = src.toUcs4();
	count = 0;

	uint val;
	char ch[16];

	QString res;

	PARSE_STA status = OUT;

	int bound  = 0;
	int hexpos = 0;

	int len = posmap.count();
	for (int i=0; i<len; ++i)
	{
		char* c = ch;
		unsigned char t;

		uint& ov = posmap[i];

		val = ov;
		ov  = hexpos;

		if ('[' == val)
		{
			switch (status)
			{
			case OUT:    status = OUT2IN; break;
			case OUT2IN: status = OUT; break;
			case IN:     status = ERR; break;
            case ERR:    break;
			}

			if (OUT2IN == status)
				continue;
		}
		else
		if (']' == val)
		{
			if (OUT != status)
			{
				if (bound & 1) {
					status = ERR;
				} else {
					status = OUT;
					continue;
				}
			}
		}
		else
		if (OUT != status)
		{
			if ((val >= '0' && val <='9')||
				(val >= 'A' && val <='F'))
			{
				status = IN;
			}
			else
			if (val >= 'a' && val <='f')
			{
				val = 'A' + (val - 'a');
				status = IN;
			}
			else
			if (val == ' ')
			{
				status = IN;
				continue;
			}
			else
			{
				status = ERR;
			}
		}

		if (OUT == status)
		{
			if (bound & 1)
			{
				status = ERR;
			}
			else
			{
				t = val >> 24 & 0xFF;
				TOHEXSTR(t,c,hextab)

				t = val >> 16 & 0xFF;
				TOHEXSTR(t,c,hextab)

				t = val >> 8 & 0xFF;
				TOHEXSTR(t,c,hextab)

				t = val & 0xFF;
				TOHEXSTR(t,c,hextab)
			}
			bound  = 0;
		}
		else
		if (IN == status)
		{
			bound += 1;
			*c++ = (char)val;
		}

		if (ERR == status)
		{
			res += QString("ERROR[%1]").arg(i);

			hexpos = 0;
			while (i < len)
				posmap[i++] = 0;

			break;
		}

		count += (c-ch);

		if (0 == (bound&1))
			*c++ = ' ';

		*c = 0;

		res += ch;
		hexpos = res.length();
	}

	posmap.append(hexpos);
	count /= 2;
	return res;
}

#undef TOHEXSTR

QString TK::bin2hex(const char* buf, uint len)
{
	char* tmp = new char[len * 3 + 3];

	const char* s = buf;
	const char* e = buf + len;
	char* d = tmp;

	if (s && d)
	{
		*d++ = '[';

		while (s < e)
		{
			char c = *s++;
			*d++ = hextab[(c>>4)&0xF];
			*d++ = hextab[c & 0xF];
			*d++ = ' ';
		}

		*d++ = ']';
		*d = 0;
	}

	QString res(tmp);

	delete[] tmp;

	return res;
}



QString TK::bin2hex2(const char* buf, uint len)
{
    char* tmp = new char[len * 3 + 3];

    const char* s = buf;
    const char* e = buf + len;
    char* d = tmp;

    if (s && d)
    {


        while (s < e)
        {
            char c = *s++;
            *d++ = hextab[(c>>4)&0xF];
            *d++ = hextab[c & 0xF];
         //   *d++ = ' ';
        }


        *d = 0;
    }

    QString res(tmp);

    delete[] tmp;

    return res;
}

QString TK::bin2ascii(const char* buf, uint len)
{
	char* tmp = new char[len + 1];

	const char* s = buf;
	const char* e = buf + len;
	char* d = tmp;

	if (s && d)
	{
		while (s < e)
		{
			char c = *s++;
			*d++ = isprint((uchar)c) ? c : '.';
		}

		*d = 0;
	}

	QString res(tmp);

	delete[] tmp;

	return res;
}

bool TK::ascii2bin(const QString& src, QByteArray& dst, QString& err)
{
	dst.clear();
	err.clear();

	QDataStream os(&dst, QIODevice::WriteOnly);

	QVector<uint> lst = src.toUcs4();

	PARSE_STA status = OUT;

	int bound  = 0;
	quint8 hexval = 0;

	int len = lst.count();
	for (int i=0; i<len; ++i)
	{
		uint val = lst.at(i);
		if ('[' == val)
		{
			switch (status)
			{
			case OUT:    status = OUT2IN; break;
			case OUT2IN: status = OUT; break;
			case IN:     status = ERR; break;
            case ERR:    break;
			}

			if (OUT2IN == status)
				continue;
		}
		else
		if (']' == val)
		{
			if (OUT !=status)
			{
				if (bound & 1) {
					status = ERR;
				} else {
					status = OUT;
					continue;
				}
			}
		}
		else
		if (OUT != status)
		{
			if (val >= '0' && val <='9')
			{
				val -= '0';
				status = IN;
			}
			else
			if (val >= 'A' && val <='F')
			{
				val -= 'A';
				val += 10;
				status = IN;
			}
			else
			if (val >= 'a' && val <='f')
			{
				val -= 'a';
				val += 10;
				status = IN;
			}
			else
			if (val == ' ')
			{
				status = IN;
				continue;
			}
			else
			{
				status = ERR;
			}
		}

		if (OUT == status)
		{
			if (bound & 1)
			{
				status = ERR;
			}
			else
			{
				if (val >> 16)
					os << (quint32)val;
				else
				if (val >> 8)
					os << (quint16)val;
				else
					os << (quint8)val;
			}

			bound  = 0;
			hexval = 0;
		}
		else
		if (IN == status)
		{
			if (bound & 1)
				os << (quint8)(((quint8)(val&0xF)) | (hexval<<4));
			else
				hexval = (quint8)(val & 0xF);

			++bound;
		}

		if (ERR == status)
		{
			dst.clear();
			err.append(QString("ERROR[%1]").arg(i));
			break;
		}
	}

	return (ERR != status);
}

char* TK::createBuffer(qint64& cap, qint64 limit)
{
	if (cap < 0 || cap > limit)
        return nullptr;

	if (0 == cap)
		cap = 1;

	return new char[cap];
}

void  TK::releaseBuffer(char*& buf)
{
	delete buf;
    buf = nullptr;
}

/*将浮点数f转化为4个字节数据存放在byte[4]中*/

 char* TK::Float_to_Byte(float f)
{
   // float float_data = 0;
     long longdata = 0;
    longdata = *( long*)&f;           //注意，会丢失精度
     char *byte=new  char[4];
    byte[0] = (longdata & 0xFF000000) >> 24;
    byte[1] = (longdata & 0x00FF0000) >> 16;
    byte[2] = (longdata & 0x0000FF00) >> 8;
    byte[3] = (longdata & 0x000000FF);
    return byte;
}

/*将4个字节数据byte[4]转化为浮点数存放在*f中*/

float TK::Byte_to_Float( char *p)
{
    float float_data=0;
     long longdata = 0;
    longdata = (*p<< 24) + (*(p+1) << 16) + (*(p + 2) << 8) + (*(p + 3) << 0);
   //  longdata =(*(p + 3)<< 0)+(*(p + 2) << 8) +(*(p+1) << 16) + (*p<< 24);
    float_data = *(float*)&longdata;
    return float_data;
}


/*将浮点数f转化为4个字节数据存放在byte[4]中*/
 char *TK::float_to_char(float f,  char *s)      //输入的float型数据，输出char存放地址
{
     union change
    {
        float d;
         char dat[4];
    }r1;

        r1.d = f;
        *s = r1.dat[0];
        *(s + 1) = r1.dat[1];
        *(s + 2) = r1.dat[2];
        *(s + 3) = r1.dat[3];
        return s;
}


float TK::char_to_float( char *s)   //输入char存放地址
{
    float f;
    union change
      {
          float d;
          char dat[4];
      }r1;

     r1.dat[0] = *s;
     r1.dat[1]= *(s+1);
     r1.dat[2] = *(s +2);
     r1.dat[3] = *(s + 3);
     f = r1.d;
     return f;
}
float TK::char_to_float_c( char *s)   //输入char存放地址
{
    float f;
    union change
      {
          float d;
          char dat[4];
      }r1;

     r1.dat[3] = *s;
     r1.dat[2]= *(s+1);
     r1.dat[1] = *(s +2);
     r1.dat[0] = *(s + 3);
     f = r1.d;
     return f;
}

float TK::CharToFloat( char * str)
{
    float float_v = 1.0; //最终值
    //得到int值
    int int_v = 0;
    int_v |= (str[0] << 0);
    int_v |= (str[1] << 8);
    int_v |= (str[2] << 16);
    int_v |= (str[3] << 24);
    //获取二进制表示
    char *binary_v = new char[32];
    for( int i = 31; i>=0; i--)
    {
        if(int_v % 2 == 1)
        {
            binary_v[i] = '1';
        }
        else
        {
            binary_v[i] = '0';
        }
        int_v /= 2;
    }
    //获取尾数
    double m = 1.0; //尾数值
    double bitn = 1.0;  //尾数部分每一位的值
    for(int i = 9; i <= 31; ++i)
    {
        bitn /= 2.0;
        if(binary_v[i] == '1')
        {
            m += bitn;
        }
    }
    //获取指数
    int e = -127;
    int bite = 1;
    for(int i = 8; i >= 1; --i)
    {
        if(binary_v[i] == '1')
        {
            e += bite;
        }
        bite *= 2;
    }
    int value_e = 1;
    while(e--)
    {
        value_e *= 2;
    }
    //得到无符号的float_v，尾数部分*指数部分
    float_v = value_e * m;
    //获取符号位
    if(binary_v[0] == '1')
        float_v *= -1;

    delete [] binary_v;
    return float_v;
}
