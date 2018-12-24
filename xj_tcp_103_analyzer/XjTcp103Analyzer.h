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
	/// 解析Asdu报文
	///    @param unsigned char* chMsg 原始的报文
	///    @param void* p103Data 解析好之后数据放在此类相应的结构中,与iec103报文结构相同的数据
	///    @param void* p103Data 解析好之后数据放在此类相应的结构中,各个厂家自定义的数据
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data, void* pData);

private:
	/// 
	/// 解析厂家增加的非标准Asdu报文
	///    @param unsigned char* chMsg 原始的报文
	///    @param void* pData 解析好之后数据放在此类相应的结构中,与iec103报文结构相同的数据
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeFactoryAsdu(unsigned char* chMsg, void* pData);
};
#endif
