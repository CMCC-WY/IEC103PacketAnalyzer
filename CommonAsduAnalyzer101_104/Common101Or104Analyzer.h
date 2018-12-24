#ifndef _Common101Or104Analyzer_H
#define _Common101Or104Analyzer_H
#pragma once

//����sprintf_s����
#pragma warning (disable : 4996)

#include <map>
#include <vector>
#include "C101Or104Data.h"

//ASDU����λ��
const int ASDU_TYPE_POISION = 0;

const int ASDU_TYPE_NUM = 1;

const int VSQ_NUM = 1;

const int LOG_BUF_SIZE = 1024;

class CCommon101Or104Analyzer
{
public:
	CCommon101Or104Analyzer(void);
	virtual ~CCommon101Or104Analyzer(void);

public:

	/// 
	/// ���ñ���DUI�����пɱ�Ĳ���
	///    @param int nCotNum ����ԭ��ռ�õ��ֽ���
	///    @param int nCommonAddrNum ������ַռ�õ��ֽ���
	///    @param int nInfObjAddrNum ��Ϣ�����ַռ�õ��ֽ���
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	int SetDuiValue(int nCotNum, int nCommonAddrNum, int nInfObjAddrNum);

	/// 
	/// ����Asdu����
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ�����Ӧ�Ľṹ��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsduMsg(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

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
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu1��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu1(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu2,M_SP_TA_1���ͱ���,��CP24Time2aʱ��ĵ�����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu2��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu2(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu3,M_DP_NA_1���ͱ���,����ʱ���˫����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu3��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu3(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu4,M_DP_TA_1���ͱ���,��CP24Time2aʱ���˫����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu4��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu4(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu5,M_ST_NA_1���ͱ���,����ʱ��Ĳ�λ����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu5��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu5(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu6,M_ST_TA_1���ͱ���,��ʱ��Ĳ�λ����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu6��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu6(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu7,M_BO_NA_1���ͱ���,32λ ������״̬��Ϣ,��Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu7��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu7(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu8,M_BO_TA_1���ͱ���,32λ ������״̬��Ϣ,��Ʒ������,��CP24Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu8��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu8(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu9,M_ME_NA_1���ͱ���,��һ����ң��ֵ,��Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu9��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu9(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu10,M_ME_TA_1���ͱ���,��һ����ң��ֵ,��Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu10��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu10(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu11,M_ME_NB_1���ͱ���,��Ȼ���ң��ֵ,��Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu11��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu11(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu12,M_ME_TB_1���ͱ���,��Ȼ���ң��ֵ,��Ʒ������,��CP24Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu12��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu12(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu13,M_ME_NC_1���ͱ���,��Ȼ���ң��ֵ,��Ʒ������,��CP24Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu13��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu13(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu14,M_ME_TC_1���ͱ���,IEEE754��ң��ֵ,��Ʒ������,��CP24Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu14��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu14(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu15,M_IT_NA_1���ͱ���,�ۼ���
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu15��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu15(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu16,M_IT_TA_1���ͱ���,��ʱ����ۼ���
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu16��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu16(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu17,M_EP_TA_1���ͱ���,��ʱ��ļ̵籣���豸�¼�
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu17��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu17(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu18,M_EP_TB_1���ͱ���,��ʱ��ļ̵籣���豸���������¼�
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu18��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu18(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu19,M_EP_TC_1���ͱ���,��ʱ��ļ̵籣���豸���������·��Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu19��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu19(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu20,M_PS_NA_1���ͱ���,����λ����ĳ��鵥����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu20��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu20(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu21,M_ME_NA_1���ͱ���,��һ����ң��ֵ,����Ʒ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu21��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu21(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu30,M_SP_TB_1���ͱ���,��CP56Time2aʱ��ĵ�����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu30��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu30(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu31,M_DP_TB_1���ͱ���,��CP56Time2aʱ���˫����Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu31��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu31(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu32,M_ST_TB_1���ͱ���,��CP56Time2aʱ��Ĳ�λ��Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu32��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu32(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu33,M_BO_TB_1���ͱ���,32λ������״̬��Ϣ,��Ʒ������,��CP56Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu33��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu33(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu34,M_ME_TD_1���ͱ���,��һ����ң��ֵ,��Ʒ������,��CP56Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu34��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu34(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu35,M_ME_TE_1���ͱ���,��Ȼ���ң��ֵ,��Ʒ������,��CP56Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu35��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu35(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu36,M_ME_TF_1���ͱ���,�̸�������ң��ֵ,��Ʒ������,��CP56Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu36��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu36(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu37,M_IT_TB_1���ͱ���,�����Ƽ���������,��CP56Time2aʱ��
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu37��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu37(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu38,M_EP_TD_1���ͱ���,��CP56Time2aʱ��ļ̵籣���豸�¼�
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu38��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu38(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu39,M_EP_TE_1���ͱ���,��CP56Time2aʱ��ļ̵籣�����������¼�
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu39��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu39(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu40,M_EP_TF_1���ͱ���,��CP56Time2aʱ��ļ̵籣�����������·��Ϣ
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu40��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu40(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// ����asdu70,M_EI_NA_1���ͱ���,��ʼ������
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param CC101Or104Data* p101Or104Data ������֮�����ݷ��ڴ���vec_Asdu70��
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsdu70(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

private:
	//����2�ֽ�ʱ��,��Χ0~59999ms
	int AnalyzeCP16Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE]);

	//����3�ֽ�ʱ��
	int AnalyzeCP24Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE]);

	//����7�ֽ�ʱ��
	int AnalyzeCP56Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE]);

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
	int AnalyzeSEP(unsigned char* chMsg, SEP& sep);

	//�����̵籣���豸�������¼�SPE
	int AnalyzeSPE(unsigned char* chMsg, SPE& spe);

	//�����̵籣���豸�¼���Ʒ��������QDP
	int AnalyzeQDP(unsigned char* chMsg, QDP& qdp);

	//�����̵籣���豸�������·����OCI
	int AnalyzeOCI(unsigned char* chMsg, OCI& oci);

	//������Ʒ�������ʵĵ�����ϢSIQ
	int AnalyzeSIQ(unsigned char* chMsg, SIQ& siq);

	//������Ʒ�������ʵĵ�����ϢDIQ
	int AnalyzeDIQ(unsigned char* chMsg, DIQ& diq);

	//����Ʒ��������QDS
	int AnalyzeQDS(unsigned char* chMsg, QDS& qds);

	//������˲��״ָ̬ʾ��ֵ,���ڱ�ѹ���Ĳ�λ�û���������λ����ϢVTI
	int AnalyzeVTI(unsigned char* chMsg, VTI& vti);

	//����32λ������״̬��Ϣ
	int AnalyzeBSI(unsigned char* chMsg, BSI& bsi);

	//�����Ƽ���������
	int AnalyzeBCR(unsigned char* chMsg, BCR& bcr);

	//����״̬��״̬��λ���
	int AnalyzeSCD(unsigned char* chMsg, SCD& scd);

private:
	//������һ��ֵ
	int AnalyzeNVA(unsigned char* chMsg, float& fValue);

	//������Ȼ�ֵ
	int AnalyzeSVA(unsigned char* chMsg, int& nValue);

	//����IEEE754 ������
	int AnalyzeIEEE754(unsigned char* chMsg, float& fValue);

private:
	//ÿ������asdu�ĺ���Ӧ�������������ģʽ
	typedef int(CCommon101Or104Analyzer::*pFun)(unsigned char* chMsg, CC101Or104Data* p101Or104Data);
	std::map<int, pFun> m_map_asdu_function;

private:
	/// Asdu��
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
	char m_chTimeBuf[TIME_BUF_SIZE];
	/// ������Ϣ������
	char m_chErrBuf[LOG_BUF_SIZE];
	/// ���ݵ�Ԫ��ʶ��
	DataUnitIdentifier m_dataUnitIdent;
};

#endif