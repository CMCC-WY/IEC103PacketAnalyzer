#include "XjTcp103Analyzer.h"


CXjTcp103Analyzer::CXjTcp103Analyzer(void)
{
}


CXjTcp103Analyzer::~CXjTcp103Analyzer(void)
{
}

int CXjTcp103Analyzer::AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data, void* pData)
{

	//�ȵ���iec103�Ľ�������
	CCommon103Analyzer::AnalyzeAsduMsg(chMsg, p103Data);

	//���ó����Զ���Ľ���,����������Զ���ı��ĵĻ�
	this->AnalyzeFactoryAsdu(chMsg, pData);

	return 1;

}//AnalyzeAsduMsg

int CXjTcp103Analyzer::AnalyzeFactoryAsdu(unsigned char* chMsg, void* pData)
{
	try
	{
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeFactoryAsdu