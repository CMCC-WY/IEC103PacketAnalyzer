#include "XjTcp103Analyzer.h"


CXjTcp103Analyzer::CXjTcp103Analyzer(void)
{
}


CXjTcp103Analyzer::~CXjTcp103Analyzer(void)
{
}

int CXjTcp103Analyzer::AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data, void* pData)
{

	//先调用iec103的解析函数
	CCommon103Analyzer::AnalyzeAsduMsg(chMsg, p103Data);

	//调用厂家自定义的解析,如果厂家有自定义的报文的话
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