#ifndef _103DataDefine_H
#define _103DataDefine_H
#pragma once

#pragma warning (disable : 4786)
#pragma warning (disable : 4275)
#include <string>
#include <vector>
//时间缓冲区大小,不得小于27
const int TIME_BUF_SIZE_103 = 30;

//扰动值数目,最大25个
const int MAX_SDV_NUM = 25;

struct Vsq_103 
{
	unsigned int nContinuous;
	unsigned int nVsq;

	Vsq_103()
	{
		nContinuous = 0;//0是断续,1是连续
		nVsq = 0;
	}
};

//数据单元标识符
struct DataUnitIdentifier_103 
{
	unsigned int nType;
    Vsq_103 vsq;
	unsigned int nCot;
	unsigned int nCommonAddr;

	DataUnitIdentifier_103()
	{
		nType = 0;
		nCot = 0;
		nCommonAddr = 0;
	}
};

//实际通道
struct ACC 
{
	unsigned int nACC;

	ACC()
	{
		nACC = 0;
	}
};

//兼容级别
struct COL 
{
	unsigned int nCOL;

	COL()
	{
		nCOL = 0;
	}
};

//双点信息
struct DPI 
{
	unsigned int nDpi;

	DPI()
	{
		nDpi = 0;
	}
};

//单点信息
struct SPI
{
	unsigned int nSpi;

	SPI()
	{
		nSpi = 0;
	}
};

//故障序号
struct FAN
{
	unsigned int nFAN;

	FAN()
	{
		//从0~65535
		nFAN = 0;
	}
};

//信息元素的间隔
struct INT 
{
	unsigned int nINT;

	INT()
	{
		nINT = 0;
	}
};

//带品质描述词的被测值
struct MEA 
{
	unsigned int nOV;
	unsigned int nER;
	unsigned int nRES;
	float fMVAL;

	MEA()
	{
		nOV = 1;
		nER = 1;
		nRES = 0;
		fMVAL = 0.0;
	}
};

//通道数目
struct NOC 
{
	unsigned int nNOC;

	NOC()
	{
		nNOC = 0;
	}
};

//一个通道信息元素数目
struct NOE 
{
	unsigned int nNOE;

	NOE()
	{
		nNOE = 0;
	}
};

//电网故障序号
struct NOF 
{
	unsigned int nNOF;

	NOF()
	{
		nNOF = 0;
	}
};

//带标志的状态变位的数目
struct NOT 
{
	unsigned int nNot;

	NOT()
	{
		nNot = 0;
	}
};

//每个应用服务数据单元有关扰动值的数目
struct NDV
{
	unsigned int nNDV;

	NDV()
	{
		nNDV = 0;
	}
};

//相对时间
struct RET
{
	unsigned int nRET;

	RET()
	{
		//从0~65535
		nRET = 0;
	}
};

//附加信息
struct SIN 
{
	unsigned int nSIN;

	SIN()
	{
		nSIN = 0;
	}
};

//短路位置
struct SCL 
{
	float fSCL;

	SCL()
	{
		fSCL = 0.0;
	}
};

//扫描序号
struct SCN 
{
	unsigned int nSCN;
	
	SCN()
	{
		nSCN = 0;
	}
};

//故障的状态
struct SOF 
{
	//被记录的故障跳闸1,未跳闸0
	unsigned int nTP;
	//扰动数据正在传输1,等待传输0
	unsigned int nTM;
	//正常操作时被记录的数据0,测试模式记录的数据1
	unsigned int nTEST;
	//由启动、检出故障触发被记录的扰动数据0,其他事件触发的扰动数据1
	unsigned int nOTEV;
	//保留位
	unsigned int nRES;

	SOF()
	{
		nTP = 1;
		nTM = 1;
		nTEST = 1;
		nOTEV = 1;
		nRES = 0;
	}
};

//扰动值的类型
struct TOV 
{
	unsigned int nTOV;

	TOV()
	{
		nTOV = 0;
	}
};

//标志的位置
struct TAP 
{
	unsigned int nTap;
	
	TAP()
	{
		nTap = 0;
	}
};

//应用服务数据单元的第一个信息元素的序号
struct NFE 
{
	unsigned int nNFE;

	NFE()
	{
		nNFE = 0;
	}
};

//单个扰动值
struct SDV
{
	//按照规约要求,最多25个
	int nSDV;

	SDV()
	{
		nSDV = 0;
	}
};

//命令类型
struct TOO 
{
	unsigned int nToo;

	TOO()
	{
		nToo = 0;
	}
};

//通用分类数据集数目
struct  NGD
{
	unsigned int nNo;
	unsigned int nCont;

	NGD()
	{
		nNo = 0;
		nCont = 0;
	}
};

//通用分类标识序号
struct GIN 
{
	unsigned int nGroup;
	unsigned int nEntry;

	GIN()
	{
		nGroup = 0;
		nEntry = 0;
	}
};

//通用分类数据描述
struct GDD 
{
	unsigned int nType;
	unsigned int nSize;
	unsigned int nNum;
	unsigned int n_Cont;

	GDD()
	{
		nType = 0;
		nSize = 0;
		nNum = 0;
		n_Cont = 0;
	}
};

//成组8位串
struct BSI_103
{
	unsigned char chBsi[4];

    BSI_103()
	{
		chBsi[0] = 0x00;
		chBsi[1] = 0x00;
		chBsi[2] = 0x00;
		chBsi[3] = 0x00;
	}
};

//带时标的报文
struct  DPIwiTime
{
	DPI dpi;
	char ch4ByteTime[TIME_BUF_SIZE_103];
	SIN sin;

	DPIwiTime()
	{
		memset(ch4ByteTime, '\0', sizeof(ch4ByteTime));
	}
};

//带相对时间的时标报文
struct DPIwiRET 
{
	DPI dpi;
	RET ret;
	FAN fan;
	char ch4ByteTime[TIME_BUF_SIZE_103];
	SIN sin;

	DPIwiRET()
	{
		memset(ch4ByteTime, '\0', sizeof(ch4ByteTime));
	}
};

//带相对时间的时标的被测值
struct VALwiRET 
{
	float R32;
	RET ret;
	FAN fan;
	char ch4ByteTime[TIME_BUF_SIZE_103];

	VALwiRET()
	{
		R32 = 0.0;
		memset(ch4ByteTime, '\0', sizeof(ch4ByteTime));
	}
};

//通用分类回答码
struct GRC 
{
	unsigned int nGrc;

	GRC()
	{
		nGrc = 0;
	}
};

//数据结构
struct GDDaGID 
{
	GDD gdd;
	//GID gid;
};

//描述元素的数目
struct NDE 
{
	//数目
	unsigned int nNO;
	//后续状态位
	unsigned int nCONT;
};

struct Asdu103_1 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;

	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//DPI
	DPI dpi;
	//4字节时间
	char ch4ByteTime[TIME_BUF_SIZE_103];
	//附加信息
	SIN stru_sin;

	Asdu103_1()
	{
		nFUN = 0;
		nINF = 0;
		memset(ch4ByteTime, '\0', sizeof(ch4ByteTime));
	}
};

struct Asdu103_2 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;

	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//DPI
	DPI dpi;
	//RET
	RET ret;
	//FAN
	FAN fan;


	//4字节时间
	char ch4ByteTime[TIME_BUF_SIZE_103];
	//附加信息
	SIN stru_sin;

	Asdu103_2()
	{
		nFUN = 0;
		nINF = 0;
		memset(ch4ByteTime, '\0', sizeof(ch4ByteTime));
	}
};

struct Asdu103_3 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;

	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;

	//从0开始依次为b相电流,AB线电压,有功功率,无功功率
	std::vector<MEA> vec_meaValue;

	Asdu103_3()
	{
		nFUN = 0;
		nINF = 0;
		vec_meaValue.clear();
	}
};

struct Asdu103_4 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;

	//SCL
	SCL scl;
	//RET
	RET ret;
	//FAN
	FAN fan;
	//4字节时间
	char ch4ByteTime[TIME_BUF_SIZE_103];

	Asdu103_4()
	{
		nFUN = 0;
		nINF = 0;
		memset(ch4ByteTime, '\0', sizeof(ch4ByteTime));
	}
};

struct Asdu103_5 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//COL
	COL col;
	//ASCII1
	unsigned int ASCII1;
	//ASCII2
	unsigned int ASCII2;
	//ASCII3
	unsigned int ASCII3;
	//ASCII4
	unsigned int ASCII4;
	//ASCII5
	unsigned int ASCII5;
	//ASCII6
	unsigned int ASCII6;
	//ASCII7
	unsigned int ASCII7;
	//ASCII8
	unsigned int ASCII8;
	//自由赋值1
	unsigned int FreeValue1;
	//自由赋值2
	unsigned int FreeValue2;
	//自由赋值3
	unsigned int FreeValue3;
	//自由赋值4
	unsigned int FreeValue4;

	Asdu103_5()
	{
		nFUN = 0;
		nINF = 0;

		ASCII1 = 0x30;
		ASCII2 = 0x30;
		ASCII3 = 0x30;
		ASCII4 = 0x30;
		ASCII5 = 0x30;
		ASCII6 = 0x30;
		ASCII7 = 0x30;
		ASCII8 = 0x30;

		FreeValue1 = 0x00;
		FreeValue2 = 0x00;
		FreeValue3 = 0x00;
		FreeValue4 = 0x00;
	}
};

struct Asdu103_6 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE_103];

	Asdu103_6()
	{
		nFUN = 0;
		nINF = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu103_8
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//SCN
	SCN scn;

	Asdu103_8()
	{
		nFUN = 0;
		nINF = 0;
	}
};

struct Asdu103_9 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;

	//从0开始依次是a相电流,b相电流,c相电流,a相电压,b相电压,c相电压,三相有功功率,三相无功功率,(频率,偏移50Hz的差值范围-2.000~2.000Hz)
	std::vector<MEA> vec_meaValue;
		
	Asdu103_9()
	{
		nFUN = 0;
		nINF = 0;
		vec_meaValue.clear();
	}
};

//Asdu103_10通用分类标识数据
struct GID 
{
	//1 ASCII8位码
	unsigned int ASCII;

	//2 成组8位串
    BSI_103 bsi;

	//3 无符号整数
	unsigned int UnnValue;

	//4 整数
	int nValue;

	//5 无符号浮点数
	double UnfValue;

	//6 浮点数
	float fValue;

	//7 IEEE标准754短实数
	float R32;

	//8 IEEE标准754实数
	double R64;

	//9 双点信息
	DPI dpi;

	//10 单点信息
	SPI spi;

	//11 带瞬变和差错的双点信息
	unsigned int nTEDPI;

	//12 带品质描述词的被测值
	MEA mea;

	//13 备用

	//14 7个8位二进制时间
	char ch7ByteTime[TIME_BUF_SIZE_103];

	//15 通用分类标识序号
	GIN gin;

	//16 相对时间
	RET ret;

	//17 功能类型和信息序号
	unsigned int nFUN;
	unsigned int nINF;

	//18 带时标的报文
	DPIwiTime dpiwitime;

	//19 带相对时间的时标报文
	DPIwiRET dpiwiret;

	//20 带相对时间的时标的被测值
	VALwiRET valwiret;

	//21 外部文本序号
	

	//22 通用分类回答码
	GRC grc;

	//23 数据结构
	GDDaGID gddagid;

	//24 索引


	//25~255备用

	GID()
	{
		UnnValue = 0;
		nValue = 0;
		UnfValue = 0.0;
		fValue = 0.0;
		R32 = 0.0;
		R64 = 0.0;
		nTEDPI = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
		nFUN = 0;
		nINF = 0;

	}

};

//Asdu103_10数据集结构
struct Asdu103_10DataSet 
{
	//GIN
	GIN gin;
	//KOD(描述类别)
	unsigned int nKod;
	//GDD
	GDD gdd;
	//GID
	std::vector<GID> vec_GID;

	Asdu103_10DataSet()
	{
		nKod = 0;
	}
};

struct Asdu103_10 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//功能类型
	unsigned int nGENTYP;
	//INF
	unsigned int nINF;
	//RII
	unsigned int nRII;
	//NGD
	NGD ngd;

	std::vector<Asdu103_10DataSet> vec_Asdu103_10DataSet;

	Asdu103_10()
	{
		nINF = 0;
		nRII = 0;
	}

};

//Asdu103_11描述元素结构
struct Asdu103_11DataSet 
{
	//KOD
	unsigned int nKod;
	//GDD
	GDD gdd;
	//GID
	std::vector<GID> vec_GID;

	Asdu103_11DataSet()
	{
		nKod = 0;
	}
};

struct Asdu103_11 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//功能类型
	unsigned int nGENFUN;
	//INF
	unsigned int nINF;
	//RII
	unsigned int nRII;
	//GIN
	GIN gin;
	//NDE
	NDE nde;

	std::vector<Asdu103_11DataSet> vec_Asdu103_11DataSet;

	Asdu103_11()
	{
		nGENFUN = 0;
		nINF = 0;
		nRII = 0;
	}
};

//Asdu103_23数据集结构
struct Asdu103_23DataSet 
{
	//故障序号
	FAN fan;
	//S故障状态
	SOF sof;
	//7字节时间
	char ch7ByteTime[TIME_BUF_SIZE_103];

	Asdu103_23DataSet()
	{
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu103_23
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF,固定为0
	unsigned int nINF;
	
	std::vector<Asdu103_23DataSet> vec_Asdu103_23DataSet;

	Asdu103_23()
	{
		nFUN = 0;
		nINF = 0;
		vec_Asdu103_23DataSet.clear();	
	}
};

struct Asdu103_26
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//TOV
	TOV tov;
	//FAN
	FAN fan;
	//NOF
	NOF nof;
	//NOC
	NOC noc;
	//NOE
	NOE noe;
	//INT
	INT stru_INT;
	//4字节时间
	char ch4ByteTime[TIME_BUF_SIZE_103];

	Asdu103_26()
	{
		nFUN = 0;
		nINF = 0;
		memset(ch4ByteTime, '\0', sizeof(ch4ByteTime));
	}
};

struct Asdu103_27
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//TOV
	TOV tov;
	//FAN
	FAN fan;
	//ACC
	ACC acc;
	//一次额定值
	float fPrimValue;
	//二次额定值
	float fSecValue;
	//参比因子
	float fRatio;

	Asdu103_27()
	{
		nFUN = 0;
		nINF = 0;
		fPrimValue = 0.0;
		fSecValue = 0.0;
		fRatio = 0.0;
	}
};

struct Asdu103_28
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//FAN
	FAN fan;

	Asdu103_28()
	{
		nFUN = 0;
		nINF = 0;
	}
};

//Asdu103_29数据集
struct Asdu103_29DataSet 
{
	//状态变位的fun
	unsigned int nStateFUN;
	//状态变位的inf
	unsigned int nStateINF;
	//DPI
	DPI dpi;

	Asdu103_29DataSet()
	{
		nStateFUN = 0;
		nStateINF = 0;
	}
};

struct Asdu103_29 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//FAN
	FAN fan;
	//NOT
	NOT stru_NOT;
	//TAP
	TAP stru_TAP;

	std::vector<Asdu103_29DataSet> vec_Asdu103_29DataSet;
	Asdu103_29()
	{
		nFUN = 0;
		nINF = 0;
		vec_Asdu103_29DataSet.clear();
	}
};

struct Asdu103_30 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;
	//TOV
	TOV tov;
	//FAN
	FAN fan;
	//ACC
	ACC acc;

	//NDV
	NDV ndv;
	//NFE
	NFE nfe;
	//SDV
	float sdv[MAX_SDV_NUM];
	
	Asdu103_30()
	{
		nFUN = 0;
		nINF = 0;
	}
};

struct Asdu103_31 
{
	//数据单元标识符
	DataUnitIdentifier_103 dui;
	//FUN
	unsigned int nFUN;
	//INF
	unsigned int nINF;

	//TOO
	TOO too;
	//TOV
	TOV tov;
	//FAN
	FAN fan;
	//ACC
	ACC acc;

	Asdu103_31()
	{
		nFUN = 0;
		nINF = 0;
	}
};

#endif
