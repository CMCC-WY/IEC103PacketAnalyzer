#ifndef Sf103UdpAnalyzer_h_
#define Sf103UdpAnalyzer_h_
#pragma once
#include "../CommonAsduAnalyzer103/Common103Analyzer.h"
class CSf103UdpAnalyzer : public CCommon103Analyzer
{
public:
	CSf103UdpAnalyzer(void);
	virtual ~CSf103UdpAnalyzer(void);

public:
	/// 
	/// ����Asdu����
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param void* p103Data ������֮�����ݷ��ڴ�����Ӧ�Ľṹ��,��iec103���Ľṹ��ͬ������
	///    @param void* p103Data ������֮�����ݷ��ڴ�����Ӧ�Ľṹ��,���������Զ��������
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data, void* pData);

private:
	/// 
	/// �����������ӵķǱ�׼Asdu����
	///    @param unsigned char* chMsg ԭʼ�ı���
	///    @param void* pData ������֮�����ݷ��ڴ�����Ӧ�Ľṹ��,��iec103���Ľṹ��ͬ������
	///    @return -1 ��������
	///    @return 1 �����ɹ�
	///    @note ����֮�����GetLastLogMsg()��ȡ������Ϣ
	int AnalyzeFactoryAsdu(unsigned char* chMsg, void* pData);

};
#endif



