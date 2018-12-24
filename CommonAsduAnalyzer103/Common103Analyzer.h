#ifndef _Common103Analyzer_H
#define _Common103Analyzer_H
#pragma once

//����sprintf_s����
#pragma warning (disable : 4996)

#include <map>
#include <vector>
#include "C103Data.h"

//ASDU����λ��
const int ASDU_TYPE_POISION_103 = 0;

const int ASDU_TYPE_NUM_103 = 1;

const int VSQ_NUM_103 = 1;

const int LOG_BUF_SIZE_103 = 1024;

class CCommon103Analyzer
{
public:
	CCommon103Analyzer(void);

public:
	virtual ~CCommon103Analyzer(void);

public:

	/// 
	/// �������ݵ�Ԫ��ʶ��
	///    @param int nCotNum ����ԭ��ռ�õ��ֽ���
	///    @param int nCommonAddrNum ������ַռ�õ��ֽ���
	int SetDuiValue(int nCotNum, int nCommonAddrNum);

	/// 
	/// ����Asdu����
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ�����Ӧ�Ľṹ��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
    int AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data);

	/// 
	/// ��ȡasdu���ĺ�
	///    @param void �޲���
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int GetAsduType(void);

	/// 
	/// ��ȡ���һ�εĴ�����Ϣ
	///    @param void �޲���
	///    @return char* ����Ĵ�����Ϣ
	char* GetLastLogMsg(void);

private:
	//��ʼ��asdu���ͺźͶ�Ӧ�Ľ�������map
	int InitAsduFunctionMap(void);

	/// 
	/// ����asdu1,M_SP_NA_1���ͱ���,����ʱ��ĵ�����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu1��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu1(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu2,M_SP_TA_1���ͱ���,��CP24Time2aʱ��ĵ�����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu2��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu2(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu3,M_DP_NA_1���ͱ���,����ʱ���˫����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu3��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu3(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu4,M_DP_TA_1���ͱ���,��CP24Time2aʱ���˫����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu4��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu4(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu5,M_ST_NA_1���ͱ���,����ʱ��Ĳ�λ����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu5��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu5(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu6,M_ST_TA_1���ͱ���,��ʱ��Ĳ�λ����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu6��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu6(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu8,M_BO_TA_1���ͱ���,32λ ������״̬��Ϣ,��Ʒ������,��CP24Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu8��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu8(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu9,M_ME_NA_1���ͱ���,��һ����ң��ֵ,��Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu9��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu9(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu10,M_ME_TA_1���ͱ���,��һ����ң��ֵ,��Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu10��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu10(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu11,M_ME_NB_1���ͱ���,��Ȼ���ң��ֵ,��Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu11��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu11(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu23,M_ME_NC_1���ͱ���,��Ȼ���ң��ֵ,��Ʒ������,��CP24Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu13��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu23(unsigned char* chMsg, void* p103Data);
	
	/// 
	/// ����asdu26,M_IT_TA_1���ͱ���,��ʱ����ۼ���
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu16��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu26(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu27,M_EP_TA_1���ͱ���,��ʱ��ļ̵籣���豸�¼�
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu17��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu27(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu28,M_EP_TB_1���ͱ���,��ʱ��ļ̵籣���豸���������¼�
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu18��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu28(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu29,M_EP_TC_1���ͱ���,��ʱ��ļ̵籣���豸���������·��Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu19��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu29(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu30,M_SP_TB_1���ͱ���,��CP56Time2aʱ��ĵ�����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu30��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu30(unsigned char* chMsg, void* p103Data);

	/// 
	/// ����asdu31,M_DP_TB_1���ͱ���,��CP56Time2aʱ���˫����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC103Data* p103Data ������֮�����ݷ��ڴ���vec_Asdu31��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu31(unsigned char* chMsg, void* p103Data);

private:
	//����2�ֽ�ʱ��,��Χ0~59999ms
	int AnalyzeCP16Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

	//����3�ֽ�ʱ��
	int AnalyzeCP24Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

	//����4�ֽ�ʱ��
	int AnalyzeCP32Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

	//����7�ֽ�ʱ��
	int AnalyzeCP56Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

	//�������ݵ�Ԫ��ʶ��
	int AnalyzeDataUnitIdentifier(unsigned char* chMsg);

private:
	//�������ͱ�ʶ
	int AnalyzeAsduType(unsigned char* chMsg);

	//�����ɱ�ṹ�޶���
	int AnalyzeVsq(unsigned char* chMsg, unsigned int& nNum);

	//��������ԭ��
	int AnalyzeCOT(unsigned char* chMsg);

	//����Ӧ�÷������ݵ�Ԫ������ַ
	int AnalyzeCommonAddr(unsigned char* chMsg);

	//��ʼ�����ݵ�Ԫ��ʶ��
	int InitDataUnitIdentifier(void);

	//������Ϣ�����ַ
	int AnalyzeInfoObjAddr(unsigned char* chMsg);

	//�ߵ������е��ֽ���
	int RevertByteOrder(unsigned char* chMsg, const int nLength, unsigned int& nRet);

private:
	int WriteLog(void);

	//�����̵籣���豸�ĵ����¼�SEP
	int AnalyzeDPI(unsigned char* chMsg, DPI& dpi);

	//�����̵籣���豸�������¼�SPE
	int AnalyzeSIN(unsigned char* chMsg, SIN& struc_sin);

	//�����̵籣���豸�¼���Ʒ��������QDP
	int AnalyzeRET(unsigned char* chMsg, RET& ret);

	//�����̵籣���豸�������·����OCI
	int AnalyzeFAN(unsigned char* chMsg, FAN& fan);

	//������Ʒ�������ʵĵ�����ϢSIQ
	int AnalyzeMEA(unsigned char* chMsg, MEA& mea);

	//������Ʒ�������ʵĵ�����ϢDIQ
	int AnalyzeSCL(unsigned char* chMsg, SCL& scl);

	//����Ʒ��������QDS
	int AnalyzeCOL(unsigned char* chMsg, COL& col);

	//������˲��״ָ̬ʾ��ֵ,���ڱ�ѹ���Ĳ�λ�û���������λ����ϢVTI
	int AnalyzeSCN(unsigned char* chMsg, SCN& scn);

	//����32λ������״̬��Ϣ
	int AnalyzeSOF(unsigned char* chMsg, SOF& sof);

	//�����Ƽ���������
	int AnalyzeTOV(unsigned char* chMsg, TOV& tov);

	//����״̬��״̬��λ���
	int AnalyzeNOF(unsigned char* chMsg, NOF& nof);



	int AnalyzeNOC(unsigned char* chMsg, NOC& noc);
	int AnalyzeNOE(unsigned char* chMsg, NOE& noe);
	int AnalyzeINT(unsigned char* chMsg, INT& struc_int);
	int AnalyzeACC(unsigned char* chMsg, ACC& acc);

	int AnalyzeNOT(unsigned char* chMsg, NOT& struc_not);
	int AnalyzeTAP(unsigned char* chMsg, TAP& tap);
	int AnalyzeNDV(unsigned char* chMsg, NDV& ndv);
	int AnalyzeNFE(unsigned char* chMsg, NFE& nfe);
	int AnalyzeSDV(unsigned char* chMsg, SDV& sdv);
	int AnalyzeTOO(unsigned char* chMsg, TOO& too);

	//����ͨ�÷������ݼ���Ŀ
	int AnalyzeNGD(unsigned char* chMsg, NGD& ngd);

	//����Ԫ�ص���Ŀ
	int AnalyzeNDE(unsigned char* chMsg, NDE& nde);

	//����ͨ�÷����ʶ���
	int AnalyzeGIN(unsigned char* chMsg, GIN& gin);

	//�����������
	int AnalyzeKOD(unsigned char* chMsg, unsigned int& nKod);

	//����ͨ�÷�����������
	int AnalyzeGDD(unsigned char* chMsg, GDD& gdd);

	//����ͨ�÷����ʶ����
	int AnalyzeGID(unsigned char* chMsg, unsigned int& type, unsigned int& size, GID& gid);

private:
	//����ASCII8λ��
	int AnalyzeASCII(unsigned char* chMsg, unsigned int& ASCII);

	//����8λ��
    int AnalyzeBSI(unsigned char* chMsg, BSI_103& bsi);

	//�޷�������
	int AnalyzeUnnValue(unsigned char* chMsg, unsigned int& size, unsigned int& UnnValue);


	//����
	int AnalyzenValue(unsigned char* chMsg, unsigned int& size, int& nValue);


	//�޷��Ÿ�����
	int AnalyzeUnfValue(unsigned char* chMsg, unsigned int& size, double& UnfValue);


	//������
	int AnalyzefValue(unsigned char* chMsg, unsigned int& size, float& fValue);


	//IEEE��׼754��ʵ��
	//int AnalyzeIEEE754(unsigned char* chMsg, float& fValue);


	//IEEE��׼754ʵ��
	int AnalyzeIEEER64(unsigned char* chMsg, double& R64);


	//˫����Ϣ
	//int AnalyzeDPI(unsigned char* chMsg, unsigned int& dpi);


	//������Ϣ
	int AnalyzeSPI(unsigned char* chMsg, SPI& spi);


	//��˲��Ͳ���˫����Ϣ
	int AnalyzenTEDPI(unsigned char* chMsg, unsigned int& nTEDPI);


	//��Ʒ�������ʵı���ֵ
	//int AnalyzeMEA(unsigned char* chMsg, MEA& mea);


	//����


	//7��8λ������ʱ��


	//ͨ�÷����ʶ���
	//int AnalyzeGIN(unsigned char* chMsg, GIN& gin);


	//���ʱ��
	//int AnalyzeRET(unsigned char* chMsg, RET& ret);


	//�������ͺ���Ϣ���


	//��ʱ��ı���
	int AnalyzeDPIwiTime(unsigned char* chMsg, DPIwiTime& dpiwitime);


	//�����ʱ���ʱ�걨��
	int AnalyzeDPIwiRET(unsigned char* chMsg, DPIwiRET& dpiwiret);


	//�����ʱ���ʱ��ı���ֵ
	int AnalyzeVALwiRET(unsigned char* chMsg, VALwiRET& valwiret);


	//�ⲿ�ı����


	//ͨ�÷���ش���
	int AnalyzeGRC(unsigned char* chMsg, GRC& grc);


	//���ݽṹ
	int AnalyzeGDDaGID(unsigned char* chMsg, GDDaGID& gddagid);


	//����


private:
	//������һ��ֵ
	int AnalyzeNVA(unsigned char* chMsg, float& fValue);

	//������Ȼ�ֵ
	int AnalyzeSVA(unsigned char* chMsg, int& nValue);

	//����IEEE754 ������
	int AnalyzeIEEE754(unsigned char* chMsg, float& fValue);

private:
	//ÿ������asdu�ĺ���Ӧ�������������ģʽ
	typedef int(CCommon103Analyzer::*pFun)(unsigned char* chMsg, void* p103Data);
	std::map<int, pFun> m_map_asdu_function;

private:
	/// Asdu����
	int m_nAsduType;
	/// ���ͱ�ʶ�ֽ���,Ŀǰ�̶�Ϊ1
	int m_nAsduNum;
	/// �ɱ�ṹ�޶�����,Ŀǰ�̶�Ϊ1
	int m_nVsqNum;
	/// ����ԭ���ֽ���
	int m_nCotNum;
	/// ��Ԫ������ַ�ֽ���
	int m_nCommonAddrNum;
	/// ��Ϣ�����ַ�ֽ���
	int m_nInfObjAddrNum;
	/// ��һ����Ϣ��λ��
	int m_nFirstInfoAddr;
	/// ʱ�����������
	char m_chTimeBuf[TIME_BUF_SIZE_103];
	/// ������Ϣ������
	char m_chErrBuf[LOG_BUF_SIZE_103];
	/// ���ݵ�Ԫ��ʶ��
    DataUnitIdentifier_103 m_dataUnitIdent;
};

#endif
