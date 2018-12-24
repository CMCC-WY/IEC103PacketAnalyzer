#ifndef _101Or104DataDefine_H
#define _101Or104DataDefine_H
#pragma once
#include <string>

//ʱ�仺������С,����С��27
const int TIME_BUF_SIZE = 30;

struct Vsq 
{
	unsigned int nContinuous;
	unsigned int nVsq;

	Vsq()
	{
		nContinuous = 0;//0�Ƕ���,1������
		nVsq = 0;
	}
};

//���ݵ�Ԫ��ʶ��
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

//��Ʒ�������ʵĵ�����Ϣ
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

//��Ʒ�������ʵ�˫����Ϣ
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

//Ʒ��������QDS
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

//�̵籣���豸�����¼�
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

//�̵籣���豸�����¼�
struct SPE 
{
	unsigned int nRES;//����
	unsigned int nSRD;//���򱣻�����
	unsigned int nSIE;//�ӵص�����������
	unsigned int nSL3;//C�ౣ������
	unsigned int nSL2;//B�ౣ������
	unsigned int nSL1;//A�ౣ������
	unsigned int nGS;//������

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

//�̵籣���豸�����·��Ϣ
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

//�̵籣���豸�¼���Ʒ��������
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

//��˲��״ָ̬ʾ��ֵ,���ڱ�ѹ���Ĳ�λ�û���������λ����Ϣ
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

//�����Ƽ���������
struct BCR 
{
	//��Ȼ�����
	int nValue;
	//SQ=˳���
	unsigned int SQ;
	//CY=��λ
	unsigned int CY;
	//CA=������������
	unsigned int CA;
	//IV=��Ч
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ʒ�������ʵĵ�������
	SIQ siq;

	Asdu1()
	{
		nInfoAddr = 0;
	}
};

struct Asdu2 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ʒ�������ʵĵ�������
	SIQ siq;
	//3�ֽ�ʱ��
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu2()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu3 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ʒ�������ʵ�˫����Ϣ
	DIQ diq;

	Asdu3()
	{
		nInfoAddr = 0;
	}
};

struct Asdu4 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ʒ�������ʵĵ�������
	DIQ diq;
	//3�ֽ�ʱ��
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu4()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu5 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��˲��״ָ̬ʾ��ֵ
	VTI vti;
	//Ʒ��������
	QDS qds;

	Asdu5()
	{
		nInfoAddr = 0;
	}
};

struct Asdu6 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��˲��״ָ̬ʾ��ֵ
	VTI vti;
	//Ʒ��������
	QDS qds;
	//3�ֽ�ʱ��
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu6()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu7
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//32λ ������״̬��Ϣ
	BSI bsi;
	//Ʒ������
	QDS qds;

	Asdu7()
	{
		nInfoAddr = 0;
	}
};

struct Asdu8
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//32λ ������״̬��Ϣ
	BSI bsi;
	//Ʒ������
	QDS qds;
	//3�ֽ�ʱ��
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu8()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu9 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��һ������
	float fValue;
	//Ʒ������
	QDS qds;

	Asdu9()
	{
		nInfoAddr = 0;
		fValue = 0.0;
	}
};

struct Asdu10 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��һ������
	float fValue;
	//Ʒ������
	QDS qds;
	//3�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ȼ�����
	int nValue;
	//Ʒ������
	QDS qds;

	Asdu11()
	{
		nInfoAddr = 0;
		nValue = 0;
	}
};

struct Asdu12 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ȼ�����
	int nValue;
	//Ʒ������
	QDS qds;
	//3�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ȼ�����
	float fValue;
	//Ʒ������
	QDS qds;

	Asdu13()
	{
		nInfoAddr = 0;
		fValue = 0.0;
	}
};

struct Asdu14 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ȼ�����
	float fValue;
	//Ʒ������
	QDS qds;
	//3�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�����Ƽ���������
	BCR bcr;

	Asdu15()
	{
		nInfoAddr = 0;
	}
};

struct Asdu16
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�����Ƽ���������
	BCR bcr;
	//3�ֽ�ʱ��
	char ch3ByteTime[TIME_BUF_SIZE];

	Asdu16()
	{
		nInfoAddr = 0;
		memset(ch3ByteTime, '\0', sizeof(ch3ByteTime));
	}
};

struct Asdu17 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�̵籣���豸�ĵ����¼�
	SEP sep;
	//2�ֽ�ʱ��
	char ch2ByteTime[TIME_BUF_SIZE];
	//3�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�̵籣���豸�������¼�
	SPE spe;
	//�̵籣���豸�¼���Ʒ��������
	QDP qdp;
	//2�ֽ�ʱ��
	char ch2ByteTime[TIME_BUF_SIZE];
	//3�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�̵籣���豸�������·��Ϣ
	OCI oci;
	//�̵籣���豸�¼���Ʒ��������
	QDP qdp;
	//2�ֽ�ʱ��
	char ch2ByteTime[TIME_BUF_SIZE];
	//3�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//״̬��״̬��λ���
	SCD scd;
	//Ʒ������
	QDS qds;

	Asdu20()
	{
		nInfoAddr = 0;
	}
};

struct Asdu21 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��һ������
	float fValue;

	Asdu21()
	{
		nInfoAddr = 0;
		fValue = 0.0;
	}
};

struct Asdu30 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ʒ�������ʵĵ�������
	SIQ siq;
	//7�ֽ�ʱ��
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu30()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu31 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ʒ�������ʵ�˫����Ϣ
	DIQ diq;
	//7�ֽ�ʱ��
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu31()
	{
		nInfoAddr =0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu32
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��˲��״ָ̬ʾ��ֵ
	VTI vti;
	//Ʒ��������
	QDS qds;
	//7�ֽ�ʱ��
	char ch7ByteTime[TIME_BUF_SIZE];
	
	Asdu32()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu33
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//32λ������״̬��Ϣ
	BSI bsi;
	//Ʒ��������
	QDS qds;
	//7�ֽ�ʱ��
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu33()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};

struct Asdu34 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��һ������
	float fValue;
	//Ʒ��������
	QDS qds;
	//7�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//��Ȼ�ֵ
	int nValue;
	//Ʒ��������
	QDS qds;
	//7�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//IEEE STD 754�̸�����
	float fValue;
	//Ʒ��������
	QDS qds;
	//7�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�����Ƽ���������
	BCR bcr;
	//7�ֽ�ʱ��
	char ch7ByteTime[TIME_BUF_SIZE];

	Asdu37()
	{
		nInfoAddr = 0;
		memset(ch7ByteTime, '\0', sizeof(ch7ByteTime));
	}
};


struct Asdu38 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�̵籣���豸�����¼�
	SEP sep;
	//2�ֽ�ʱ��
	char ch2ByteTime[TIME_BUF_SIZE];
	//7�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�̵籣���豸�������¼�
	SPE spe;
	//�̵籣���豸��Ʒ��������
	QDP qdp;
	//2�ֽ�ʱ��
	char ch2ByteTime[TIME_BUF_SIZE];
	//7�ֽ�ʱ��
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
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	//�̵籣���豸�������·����
	OCI oci;
	//�̵籣���豸��Ʒ��������
	QDP qdp;
	//2�ֽ�ʱ��
	char ch2ByteTime[TIME_BUF_SIZE];
	//7�ֽ�ʱ��
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
	//��ʼ��ԭ���7λ
	unsigned int nCoiReason;
	//��ʼ��ԭ�����λ
	unsigned int nLocalParam;
	
	COI()
	{
		nCoiReason = 0;
		nLocalParam = 0;
	}
};
struct Asdu70 
{
	//���ݵ�Ԫ��ʶ��
	DataUnitIdentifier dui;
	//��Ϣ�����ַ
	unsigned int nInfoAddr;
	COI coi;

	Asdu70()
	{
		nInfoAddr = 0;
	}
};

#endif
