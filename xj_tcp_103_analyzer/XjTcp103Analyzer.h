#ifndef XjTcp103Analyzer_h_
#define XjTcp103Analyzer_h_
#pragma once
#include "../CommonAsduAnalyzer103/Common103Analyzer.h"
class CXjTcp103Analyzer : public CCommon103Analyzer
{
public:
	CXjTcp103Analyzer(void);
	virtual ~CXjTcp103Analyzer(void);

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
