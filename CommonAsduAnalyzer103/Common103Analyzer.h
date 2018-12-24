#ifndef _Common103Analyzer_H
#define _Common103Analyzer_H
#pragma once

//屏蔽sprintf_s警告
#pragma warning (disable : 4996)

#include <map>
#include <vector>
#include "C103Data.h"

//ASDU类型位置
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
	/// 设置数据单元标识符
	///    @param int nCotNum 传输原因占用的字节数
	///    @param int nCommonAddrNum 公共地址占用的字节数
	int SetDuiValue(int nCotNum, int nCommonAddrNum);

	/// 
	/// 解析Asdu报文
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类相应的结构中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
    int AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data);

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
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu1中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu1(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu2,M_SP_TA_1类型报文,带CP24Time2a时标的单点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu2中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu2(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu3,M_DP_NA_1类型报文,不带时标的双点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu3中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu3(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu4,M_DP_TA_1类型报文,带CP24Time2a时标的双点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu4中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu4(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu5,M_ST_NA_1类型报文,不带时标的步位置信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu5中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu5(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu6,M_ST_TA_1类型报文,带时标的步位置信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu6中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu6(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu8,M_BO_TA_1类型报文,32位 二进制状态信息,带品质描述,带CP24Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu8中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu8(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu9,M_ME_NA_1类型报文,归一化的遥测值,带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu9中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu9(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu10,M_ME_TA_1类型报文,归一化的遥测值,带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu10中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu10(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu11,M_ME_NB_1类型报文,标度化的遥测值,带品质描述
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu11中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu11(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu23,M_ME_NC_1类型报文,标度化的遥测值,带品质描述,带CP24Time2a时标
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu13中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu23(unsigned char* chMsg, void* p103Data);
	
	/// 
	/// 解析asdu26,M_IT_TA_1类型报文,带时标的累计量
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu16中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu26(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu27,M_EP_TA_1类型报文,带时标的继电保护设备事件
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu17中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu27(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu28,M_EP_TB_1类型报文,带时标的继电保护设备成组启动事件
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu18中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu28(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu29,M_EP_TC_1类型报文,带时标的继电保护设备成组输出电路信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu19中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu29(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu30,M_SP_TB_1类型报文,带CP56Time2a时标的单点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu30中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu30(unsigned char* chMsg, void* p103Data);

	/// 
	/// 解析asdu31,M_DP_TB_1类型报文,带CP56Time2a时标的双点信息
	///    @param unsigned char* chMsg 原始的报文
	///    @param CC103Data* p103Data 解析好之后数据放在此类vec_Asdu31中
	///    @return -1 解析出错
	///    @return 1 解析成功
	///    @note 出错之后调用GetLastLogMsg()获取错误信息
	int AnalyzeAsdu31(unsigned char* chMsg, void* p103Data);

private:
	//解析2字节时标,范围0~59999ms
	int AnalyzeCP16Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

	//解析3字节时标
	int AnalyzeCP24Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

	//解析4字节时标
	int AnalyzeCP32Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

	//解析7字节时标
	int AnalyzeCP56Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103]);

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
	int AnalyzeDPI(unsigned char* chMsg, DPI& dpi);

	//解析继电保护设备的启动事件SPE
	int AnalyzeSIN(unsigned char* chMsg, SIN& struc_sin);

	//解析继电保护设备事件的品质描述词QDP
	int AnalyzeRET(unsigned char* chMsg, RET& ret);

	//解析继电保护设备的输出电路命令OCI
	int AnalyzeFAN(unsigned char* chMsg, FAN& fan);

	//解析带品质描述词的单点信息SIQ
	int AnalyzeMEA(unsigned char* chMsg, MEA& mea);

	//解析带品质描述词的单点信息DIQ
	int AnalyzeSCL(unsigned char* chMsg, SCL& scl);

	//解析品质描述词QDS
	int AnalyzeCOL(unsigned char* chMsg, COL& col);

	//解析带瞬变状态指示的值,用于变压器的步位置或者其他步位置信息VTI
	int AnalyzeSCN(unsigned char* chMsg, SCN& scn);

	//解析32位二进制状态信息
	int AnalyzeSOF(unsigned char* chMsg, SOF& sof);

	//二进制计数器读数
	int AnalyzeTOV(unsigned char* chMsg, TOV& tov);

	//解析状态和状态变位检出
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

	//解析通用分类数据集数目
	int AnalyzeNGD(unsigned char* chMsg, NGD& ngd);

	//描述元素的数目
	int AnalyzeNDE(unsigned char* chMsg, NDE& nde);

	//解析通用分类标识序号
	int AnalyzeGIN(unsigned char* chMsg, GIN& gin);

	//解析描述类别
	int AnalyzeKOD(unsigned char* chMsg, unsigned int& nKod);

	//解析通用分类数据描述
	int AnalyzeGDD(unsigned char* chMsg, GDD& gdd);

	//解析通用分类标识数据
	int AnalyzeGID(unsigned char* chMsg, unsigned int& type, unsigned int& size, GID& gid);

private:
	//解析ASCII8位码
	int AnalyzeASCII(unsigned char* chMsg, unsigned int& ASCII);

	//成组8位串
    int AnalyzeBSI(unsigned char* chMsg, BSI_103& bsi);

	//无符号整数
	int AnalyzeUnnValue(unsigned char* chMsg, unsigned int& size, unsigned int& UnnValue);


	//整数
	int AnalyzenValue(unsigned char* chMsg, unsigned int& size, int& nValue);


	//无符号浮点数
	int AnalyzeUnfValue(unsigned char* chMsg, unsigned int& size, double& UnfValue);


	//浮点数
	int AnalyzefValue(unsigned char* chMsg, unsigned int& size, float& fValue);


	//IEEE标准754短实数
	//int AnalyzeIEEE754(unsigned char* chMsg, float& fValue);


	//IEEE标准754实数
	int AnalyzeIEEER64(unsigned char* chMsg, double& R64);


	//双点信息
	//int AnalyzeDPI(unsigned char* chMsg, unsigned int& dpi);


	//单点信息
	int AnalyzeSPI(unsigned char* chMsg, SPI& spi);


	//带瞬变和差错的双点信息
	int AnalyzenTEDPI(unsigned char* chMsg, unsigned int& nTEDPI);


	//带品质描述词的被测值
	//int AnalyzeMEA(unsigned char* chMsg, MEA& mea);


	//备用


	//7个8位二进制时间


	//通用分类标识序号
	//int AnalyzeGIN(unsigned char* chMsg, GIN& gin);


	//相对时间
	//int AnalyzeRET(unsigned char* chMsg, RET& ret);


	//功能类型和信息序号


	//带时标的报文
	int AnalyzeDPIwiTime(unsigned char* chMsg, DPIwiTime& dpiwitime);


	//带相对时间的时标报文
	int AnalyzeDPIwiRET(unsigned char* chMsg, DPIwiRET& dpiwiret);


	//带相对时间的时标的被测值
	int AnalyzeVALwiRET(unsigned char* chMsg, VALwiRET& valwiret);


	//外部文本序号


	//通用分类回答码
	int AnalyzeGRC(unsigned char* chMsg, GRC& grc);


	//数据结构
	int AnalyzeGDDaGID(unsigned char* chMsg, GDDaGID& gddagid);


	//索引


private:
	//解析归一化值
	int AnalyzeNVA(unsigned char* chMsg, float& fValue);

	//解析标度化值
	int AnalyzeSVA(unsigned char* chMsg, int& nValue);

	//解析IEEE754 浮点数
	int AnalyzeIEEE754(unsigned char* chMsg, float& fValue);

private:
	//每个解析asdu的函数应当满足这个函数模式
	typedef int(CCommon103Analyzer::*pFun)(unsigned char* chMsg, void* p103Data);
	std::map<int, pFun> m_map_asdu_function;

private:
	/// Asdu类型
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
	char m_chTimeBuf[TIME_BUF_SIZE_103];
	/// 错误信息缓冲区
	char m_chErrBuf[LOG_BUF_SIZE_103];
	/// 数据单元标识符
    DataUnitIdentifier_103 m_dataUnitIdent;
};

#endif
