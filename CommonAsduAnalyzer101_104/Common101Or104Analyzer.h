#ifndef _Common101Or104Analyzer_H
#define _Common101Or104Analyzer_H
#pragma once

//屏蔽sprintf_s警告
#pragma warning (disable : 4996)

#include <map>
#include <vector>
#include "C101Or104Data.h"

//ASDU类型位置
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
	/// 设置报文DUI部分中可变的部分
	///    @param int nCotNum 传输原因占用的字节数
	///    @param int nCommonAddrNum 公共地址占用的字节数
	///    @param int nInfObjAddrNum 信息对象地址占用的字节数
	///    @return -1 解析出错
	///    @return 1 解析成功
	int SetDuiValue(int nCotNum, int nCommonAddrNum, int nInfObjAddrNum);

	/// 
	/// 解析Asdu报文
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类相应的结构中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsduMsg(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 获取asdu报文号
	///    @param void 无参数
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int GetAsduType(void);

	/// 
	/// 获取最近一次的错误信息
	///    @param void 无参数
	///    @return char* 具体的错误信息
	char* GetLastLogMsg(void);

private:
	//初始化asdu类型号和对应的解析函数map
	int InitAsduFunctionMap(void);

	/// 
	/// 解析asdu1,M_SP_NA_1类型报文,不带时标的单点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu1中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu1(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu2,M_SP_TA_1类型报文,带CP24Time2a时标的单点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu2中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu2(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu3,M_DP_NA_1类型报文,不带时标的双点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu3中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu3(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu4,M_DP_TA_1类型报文,带CP24Time2a时标的双点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu4中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu4(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu5,M_ST_NA_1类型报文,不带时标的步位置信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu5中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu5(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu6,M_ST_TA_1类型报文,带时标的步位置信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu6中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu6(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu7,M_BO_NA_1类型报文,32位 二进制状态信息,带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu7中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu7(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu8,M_BO_TA_1类型报文,32位 二进制状态信息,带品质描述,带CP24Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu8中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu8(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu9,M_ME_NA_1类型报文,归一化的遥测值,带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu9中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu9(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu10,M_ME_TA_1类型报文,归一化的遥测值,带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu10中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu10(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu11,M_ME_NB_1类型报文,标度化的遥测值,带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu11中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu11(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu12,M_ME_TB_1类型报文,标度化的遥测值,带品质描述,带CP24Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu12中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu12(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu13,M_ME_NC_1类型报文,标度化的遥测值,带品质描述,带CP24Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu13中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu13(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu14,M_ME_TC_1类型报文,IEEE754的遥测值,带品质描述,带CP24Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu14中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu14(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu15,M_IT_NA_1类型报文,累计量
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu15中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu15(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu16,M_IT_TA_1类型报文,带时标的累计量
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu16中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu16(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu17,M_EP_TA_1类型报文,带时标的继电保护设备事件
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu17中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu17(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu18,M_EP_TB_1类型报文,带时标的继电保护设备成组启动事件
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu18中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu18(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu19,M_EP_TC_1类型报文,带时标的继电保护设备成组输出电路信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu19中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu19(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu20,M_PS_NA_1类型报文,带变位检出的成组单点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu20中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu20(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu21,M_ME_NA_1类型报文,归一化的遥测值,不带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu21中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu21(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu30,M_SP_TB_1类型报文,带CP56Time2a时标的单点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu30中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu30(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu31,M_DP_TB_1类型报文,带CP56Time2a时标的双点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu31中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu31(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu32,M_ST_TB_1类型报文,带CP56Time2a时标的步位信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu32中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu32(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu33,M_BO_TB_1类型报文,32位二进制状态信息,带品质描述,带CP56Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu33中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu33(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu34,M_ME_TD_1类型报文,归一化的遥测值,带品质描述,带CP56Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu34中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu34(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu35,M_ME_TE_1类型报文,标度化的遥测值,带品质描述,带CP56Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu35中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu35(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu36,M_ME_TF_1类型报文,短浮点数的遥测值,带品质描述,带CP56Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu36中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu36(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu37,M_IT_TB_1类型报文,二进制计数器读数,带CP56Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu37中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu37(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu38,M_EP_TD_1类型报文,带CP56Time2a时标的继电保护设备事件
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu38中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu38(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu39,M_EP_TE_1类型报文,带CP56Time2a时标的继电保护成组启动事件
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu39中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu39(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu40,M_EP_TF_1类型报文,带CP56Time2a时标的继电保护成组输出电路信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu40中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu40(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

	/// 
	/// 解析asdu70,M_EI_NA_1类型报文,初始化结束
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC101Or104Data* p101Or104Data 解析好之后数据放在此类vec_Asdu70中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu70(unsigned char* chMsg, CC101Or104Data* p101Or104Data);

private:
	//解析2字节时标,范围0~59999ms
	int AnalyzeCP16Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE]);

	//解析3字节时标
	int AnalyzeCP24Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE]);

	//解析7字节时标
	int AnalyzeCP56Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE]);

	//解析数据单元标识符
	int AnalyzeDataUnitIdentifier(unsigned char* chMsg);

private:
	//解析类型标识
	int AnalyzeAsduType(unsigned char* chMsg);

	//解析可变结构限定词
	int AnalyzeVsq(unsigned char* chMsg, unsigned int& nNum);

	//解析传送原因
	int AnalyzeCOT(unsigned char* chMsg);

	//解析应用服务数据单元公共地址
	int AnalyzeCommonAddr(unsigned char* chMsg);

	//初始化数据单元标识符
	int InitDataUnitIdentifier(void);

	//解析信息对象地址
	int AnalyzeInfoObjAddr(unsigned char* chMsg);

	//颠倒报文中的字节序
	int RevertByteOrder(unsigned char* chMsg, const int nLength, unsigned int& nRet);

private:
	int WriteLog(void);

	//解析继电保护设备的单个事件SEP
	int AnalyzeSEP(unsigned char* chMsg, SEP& sep);

	//解析继电保护设备的启动事件SPE
	int AnalyzeSPE(unsigned char* chMsg, SPE& spe);

	//解析继电保护设备事件的品质描述词QDP
	int AnalyzeQDP(unsigned char* chMsg, QDP& qdp);

	//解析继电保护设备的输出电路命令OCI
	int AnalyzeOCI(unsigned char* chMsg, OCI& oci);

	//解析带品质描述词的单点信息SIQ
	int AnalyzeSIQ(unsigned char* chMsg, SIQ& siq);

	//解析带品质描述词的单点信息DIQ
	int AnalyzeDIQ(unsigned char* chMsg, DIQ& diq);

	//解析品质描述词QDS
	int AnalyzeQDS(unsigned char* chMsg, QDS& qds);

	//解析带瞬变状态指示的值,用于变压器的步位置或者其他步位置信息VTI
	int AnalyzeVTI(unsigned char* chMsg, VTI& vti);

	//解析32位二进制状态信息
	int AnalyzeBSI(unsigned char* chMsg, BSI& bsi);

	//二进制计数器读数
	int AnalyzeBCR(unsigned char* chMsg, BCR& bcr);

	//解析状态和状态变位检出
	int AnalyzeSCD(unsigned char* chMsg, SCD& scd);

private:
	//解析归一化值
	int AnalyzeNVA(unsigned char* chMsg, float& fValue);

	//解析标度化值
	int AnalyzeSVA(unsigned char* chMsg, int& nValue);

	//解析IEEE754 浮点数
	int AnalyzeIEEE754(unsigned char* chMsg, float& fValue);

private:
	//每个解析asdu的函数应当满足这个函数模式
	typedef int(CCommon101Or104Analyzer::*pFun)(unsigned char* chMsg, CC101Or104Data* p101Or104Data);
	std::map<int, pFun> m_map_asdu_function;

private:
	/// Asdu号
	int m_nAsduType;
	/// 类型标识字节数,目前固定为1
	int m_nAsduNum;
	/// 可变结构限定词数,目前固定为1
	int m_nVsqNum;
	/// 传送原因字节数
	int m_nCotNum;
	/// 单元公共地址字节数
	int m_nCommonAddrNum;
	/// 信息对象地址字节数
	int m_nInfObjAddrNum;
	/// 第一个信息体位置
	int m_nFirstInfoAddr;
	/// 时间解析缓冲区
	char m_chTimeBuf[TIME_BUF_SIZE];
	/// 错误信息缓冲区
	char m_chErrBuf[LOG_BUF_SIZE];
	/// 数据单元标识符
	DataUnitIdentifier m_dataUnitIdent;
};

#endif