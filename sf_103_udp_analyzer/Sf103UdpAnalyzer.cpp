#include "Sf103UdpAnalyzer.h"


CSf103UdpAnalyzer::CSf103UdpAnalyzer(void)
{
}


CSf103UdpAnalyzer::~CSf103UdpAnalyzer(void)
{
}

int CSf103UdpAnalyzer::AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data, void* pData)
{

	//�ȵ���iec103�Ľ�������
	CCommon103Analyzer::AnalyzeAsduMsg(chMsg, p103Data);

	//���ó����Զ���Ľ���,����������Զ���ı��ĵĻ�
	this->AnalyzeFactoryAsdu(chMsg, pData);

	return 1;

}//AnalyzeAsduMsg

int CSf103UdpAnalyzer::AnalyzeFactoryAsdu(unsigned char* chMsg, void* pData)
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