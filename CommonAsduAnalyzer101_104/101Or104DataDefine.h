#ifndef _101Or104DataDefine_H
#define _101Or104DataDefine_H
#pragma once
#include <string>

//时间缓冲区大小,不得小于27
const int TIME_BUF_SIZE = 30;

struct Vsq 
{
	unsigned int nContinuous;
	unsigned int nVsq;

	Vsq()
	{
		nContinuous = 0;//0是断续,1是连续
		nVsq = 0;
	}
};

//数据单元标识符
struct DataUnitIdentifier 
{
	unsigned int nType;
	Vsq vsq;
	unsigned int nCot;
	unsigned int nCommonAddr;

	DataUnitIdentifier()
	{
		nType = 0;
		nCot = 0;
		nCommonAddr = 0;
	}
};

//带品质描述词的单点信息
struct SIQ 
{
	//IV
	unsigned int nIV;
	//NT
	unsigned int nNT;
	//SB
	unsigned int nSB;
	//BL
	unsigned int nBL;
	//RES
	unsigned int nRES;
	//SPI
	unsigned int nSPI;

	SIQ()
	{
		nIV = 1;
		nNT = 1;
		nSB = 1;
		nBL = 1;
		nRES = 0;
		nSPI = 1;
	}
};

//带品质描述词的双点信息
struct DIQ 
{
	//IV
	unsigned int nIV;
	//NT
	unsigned int nNT;
	//SB
	unsigned int nSB;
	//BL
	unsigned int nBL;
	//RES
	unsigned int nRES;
	//DPI
	unsigned int nDPI;

	DIQ()
	{
		nIV = 1;
		nNT = 1;
		nSB = 1;
		nBL = 1;
		nRES = 0;
		nDPI = 3;
	}
};

//品质描述词QDS
struct QDS 
{
	//IV
	unsigned int nIV;
	//NT
	unsigned int nNT;
	//SB
	unsigned int nSB;
	//BL
	unsigned int nBL;
	//RES
	unsigned int nRES;
	//OV
	unsigned int nOV;

	QDS()
	{
		nIV = 1;
		nNT = 1;
		nSB = 1;
		nBL = 1;
		nRES = 0;
		nOV = 1;
	}
};

//继电保护设备单个事件
struct  SEP
{
	//IV
	unsigned int nIV;
	//NT
	unsigned int nNT;
	//SB
	unsigned int nSB;
	//BL
	unsigned int nBL;
	//EI
	unsigned int nEI;
	//RES
	unsigned int nRES;
	//ES
	unsigned int nES;

	SEP()
	{
		nIV = 1;
		nNT = 1;
		nSB = 1;
		nBL = 1;
		nEI = 1;
		nRES = 0;
		nES = 3;
	}
};

//继电保护设备启动事件
struct SPE 
{
	unsigned int nRES;//保留
	unsigned int nSRD;//反向保护启动
	unsigned int nSIE;//接地电流保护启动
	unsigned int nSL3;//C相保护启动
	unsigned int nSL2;//B相保护启动
	unsigned int nSL1;//A相保护启动
	unsigned int nGS;//总启动

	SPE()
	{
		nRES = 0;
		nSRD = 0;
		nSIE = 0;
		nSL3 = 0;
		nSL2 = 0;
		nSL1 = 0;
		nGS = 0;
	}
};

//继电保护设备输出电路信息
struct OCI 
{
	unsigned int nRES;
	unsigned int nCL3;
	unsigned int nCL2;
	unsigned int nCL1;
	unsigned int nGC;
	
	OCI()
	{
		nRES = 0;
		nCL1 = 0;
		nCL2 = 0;
		nCL3 = 0;
		nGC = 0;
	}
};

//继电保护设备事件的品质描述词
struct QDP 
{
	//IV
	unsigned int nIV;
	//NT
	unsigned int nNT;
	//SB
	unsigned int nSB;
	//BL
	unsigned int nBL;
	//EI
	unsigned int nEI;
	//RES
	unsigned int nRES;

	QDP()
	{
		nIV = 1;
		nNT = 1;
		nSB = 1;
		nBL = 1;
		nEI = 1;
		nRES = 0;
	}
};

//带瞬变状态指示的值,用于变压器的步位置或者其他步位置信息
struct VTI 
{
	unsigned int nT;
	unsigned int nValue;

	VTI()
	{
		nT = 0;
		nValue = 0;
	}
};

//二进制计数器读数
struct BCR 
{
	//标度化数据
	int nValue;
	//SQ=顺序号
	unsigned int SQ;
	//CY=进位
	unsigned int CY;
	//CA=计数量被调整
	unsigned int CA;
	//IV=无效
	unsigned int IV;

	BCR()
	{
		nValue = 0;
		SQ = 0;
		CY = 1;
		CA = 1;
		IV = 1;
	}
};

struct BSI
{
	unsigned char chBsi[4];

	BSI()
	{
		chBsi[0] = 0x00;
		chBsi[1] = 0x00;
		chBsi[2] = 0x00;
		chBsi[3] = 0x00;
	}
};

struct SCD
{

	unsigned char chScd[4];

	SCD()
	{
		chScd[0] = 0x00;
		chScd[1] = 0x00;
		chScd[2] = 0x00;
		chScd[3] = 0x00;
	}
};

struct Asdu1 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带品质描述词的单点数据
	SIQ siq;

	Asdu1()
	{
		nInfoAddr = 0;
	}
};

struct Asdu2 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带品质描述词的单点数据
	SIQ siq;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu2()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu3 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带品质描述词的双点信息
	DIQ diq;

	Asdu3()
	{
		nInfoAddr = 0;
	}
};

struct Asdu4 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带品质描述词的单点数据
	DIQ diq;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu4()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu5 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带瞬变状态指示的值
	VTI vti;
	//品质描述词
	QDS qds;

	Asdu5()
	{
		nInfoAddr = 0;
	}
};

struct Asdu6 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带瞬变状态指示的值
	VTI vti;
	//品质描述词
	QDS qds;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu6()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu7
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//32位 二进制状态信息
	BSI bsi;
	//品质因数
	QDS qds;

	Asdu7()
	{
		nInfoAddr = 0;
	}
};

struct Asdu8
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//32位 二进制状态信息
	BSI bsi;
	//品质因数
	QDS qds;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu8()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu9 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//归一化数据
	float fValue;
	//品质因数
	QDS qds;

	Asdu9()
	{
		nInfoAddr = 0;
		fValue = 0.0;
	}
};

struct Asdu10 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//归一化数据
	float fValue;
	//品质因数
	QDS qds;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu10()
	{
		nInfoAddr = 0;
		fValue = 0.0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu11 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//标度化数据
	int nValue;
	//品质因数
	QDS qds;

	Asdu11()
	{
		nInfoAddr = 0;
		nValue = 0;
	}
};

struct Asdu12 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//标度化数据
	int nValue;
	//品质因数
	QDS qds;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu12()
	{
		nInfoAddr = 0;
		nValue = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu13 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//标度化数据
	float fValue;
	//品质因数
	QDS qds;

	Asdu13()
	{
		nInfoAddr = 0;
		fValue = 0.0;
	}
};

struct Asdu14 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//标度化数据
	float fValue;
	//品质因数
	QDS qds;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu14()
	{
		nInfoAddr = 0;
		fValue = 0.0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu15
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//二进制计数器读数
	BCR bcr;

	Asdu15()
	{
		nInfoAddr = 0;
	}
};

struct Asdu16
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//二进制计数器读数
	BCR bcr;
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu16()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu17 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//继电保护设备的单个事件
	SEP sep;
	//2字节时间
	char ch2ByteTime[TIME_BUF_SIZE];
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu17()
	{
		nInfoAddr = 0;
		memset(ch2ByteTime, '\0', sizeof(ch2ByteTime));
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu18 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//继电保护设备的启动事件
	SPE spe;
	//继电保护设备事件的品质描述词
	QDP qdp;
	//2字节时间
	char ch2ByteTime[TIME_BUF_SIZE];
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu18()
	{
		nInfoAddr = 0;
		memset(ch2ByteTime, '\0', sizeof(ch2ByteTime));
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu19 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//继电保护设备的输出电路信息
	OCI oci;
	//继电保护设备事件的品质描述词
	QDP qdp;
	//2字节时间
	char ch2ByteTime[TIME_BUF_SIZE];
	//3字节时间
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu19()
	{
		nInfoAddr = 0;
		memset(ch2ByteTime, '\0', sizeof(ch2ByteTime));
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu20
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//状态和状态变位检出
	SCD scd;
	//品质因数
	QDS qds;

	Asdu20()
	{
		nInfoAddr = 0;
	}
};

struct Asdu21 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//归一化数据
	float fValue;

	Asdu21()
	{
		nInfoAddr = 0;
		fValue = 0.0;
	}
};

struct Asdu30 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带品质描述词的单点数据
	SIQ siq;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu30()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu31 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带品质描述词的双点信息
	DIQ diq;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu31()
	{
		nInfoAddr =0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu32
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//带瞬变状态指示的值
	VTI vti;
	//品质描述词
	QDS qds;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];
	
	Asdu32()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu33
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//32位二进制状态信息
	BSI bsi;
	//品质描述词
	QDS qds;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu33()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu34 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//归一化数据
	float fValue;
	//品质描述词
	QDS qds;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu34()
	{
		nInfoAddr = 0;
		fValue = 0.0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu35 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//标度化值
	int nValue;
	//品质描述词
	QDS qds;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu35()
	{
		nInfoAddr = 0;
		nValue = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu36 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//IEEE STD 754短浮点数
	float fValue;
	//品质描述词
	QDS qds;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu36()
	{
		nInfoAddr = 0;
		fValue = 0.0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu37
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//二进制计数器读数
	BCR bcr;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu37()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};


struct Asdu38 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//继电保护设备单个事件
	SEP sep;
	//2字节时间
	char ch2ByteTime[TIME_BUF_SIZE];
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu38()
	{
		nInfoAddr = 0;
		memset(ch2ByteTime, '\0', sizeof(ch2ByteTime));
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu39 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//继电保护设备的启动事件
	SPE spe;
	//继电保护设备的品质描述词
	QDP qdp;
	//2字节时间
	char ch2ByteTime[TIME_BUF_SIZE];
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu39()
	{
		nInfoAddr = 0;
		memset(ch2ByteTime, '\0', sizeof(ch2ByteTime));
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu40 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	//继电保护设备的输出电路命令
	OCI oci;
	//继电保护设备的品质描述词
	QDP qdp;
	//2字节时间
	char ch2ByteTime[TIME_BUF_SIZE];
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu40()
	{
		nInfoAddr = 0;
		memset(ch2ByteTime, '\0', sizeof(ch2ByteTime));
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};
struct COI 
{
	//初始化原因低7位
	unsigned int nCoiReason;
	//初始化原因最高位
	unsigned int nLocalParam;
	
	COI()
	{
		nCoiReason = 0;
		nLocalParam = 0;
	}
};
struct Asdu70 
{
	//数据单元标识符
	DataUnitIdentifier dui;
	//信息对象地址
	unsigned int nInfoAddr;
	COI coi;

	Asdu70()
	{
		nInfoAddr = 0;
	}
};

#endif
