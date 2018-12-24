#include "Common101Or104Analyzer.h"
#include <stddef.h>
#include <string>

CCommon101Or104Analyzer::CCommon101Or104Analyzer(void)
{
}


CCommon101Or104Analyzer::~CCommon101Or104Analyzer(void)
{
}

int CCommon101Or104Analyzer::SetDuiValue(int nCotNum, int nCommonAddrNum, int nInfObjAddrNum)
{
	m_nAsduNum = ASDU_TYPE_NUM;
	m_nVsqNum = VSQ_NUM;

	//传入参数错误的时候取默认值
	if (nCotNum <= 0 ||
		nCommonAddrNum <= 0 ||
		nInfObjAddrNum <= 0)
	{
		m_nCotNum = 2;
		m_nCommonAddrNum = 2;
		m_nInfObjAddrNum = 3;
	}
	else
	{
		m_nCotNum = nCotNum;
		m_nCommonAddrNum = nCommonAddrNum;
		m_nInfObjAddrNum = nInfObjAddrNum;
	}
	
	m_nFirstInfoAddr = m_nAsduNum + m_nVsqNum + m_nCotNum + m_nCommonAddrNum;

	memset(m_chErrBuf, '\0', sizeof(m_chErrBuf));
	memset(m_chTimeBuf, '\0', sizeof(m_chTimeBuf));
	InitAsduFunctionMap();

	return 1;
}

int CCommon101Or104Analyzer::WriteLog()
{
	//TODO
	return 1;
}//WriteLog

char* CCommon101Or104Analyzer::GetLastLogMsg()
{
	return m_chErrBuf;
}//GetLastLogMsg

int CCommon101Or104Analyzer::InitAsduFunctionMap(void)
{
	m_map_asdu_function[1] = &CCommon101Or104Analyzer::AnalyzeAsdu1;
	m_map_asdu_function[2] = &CCommon101Or104Analyzer::AnalyzeAsdu2;
	m_map_asdu_function[3] = &CCommon101Or104Analyzer::AnalyzeAsdu3;
	m_map_asdu_function[4] = &CCommon101Or104Analyzer::AnalyzeAsdu4;
	m_map_asdu_function[5] = &CCommon101Or104Analyzer::AnalyzeAsdu5;
	m_map_asdu_function[6] = &CCommon101Or104Analyzer::AnalyzeAsdu6;
	m_map_asdu_function[7] = &CCommon101Or104Analyzer::AnalyzeAsdu7;
	m_map_asdu_function[8] = &CCommon101Or104Analyzer::AnalyzeAsdu8;
	m_map_asdu_function[9] = &CCommon101Or104Analyzer::AnalyzeAsdu9;
	m_map_asdu_function[10] = &CCommon101Or104Analyzer::AnalyzeAsdu10;
	m_map_asdu_function[11] = &CCommon101Or104Analyzer::AnalyzeAsdu11;
	m_map_asdu_function[12] = &CCommon101Or104Analyzer::AnalyzeAsdu12;
	m_map_asdu_function[13] = &CCommon101Or104Analyzer::AnalyzeAsdu13;
	m_map_asdu_function[14] = &CCommon101Or104Analyzer::AnalyzeAsdu14;
	m_map_asdu_function[15] = &CCommon101Or104Analyzer::AnalyzeAsdu15;
	m_map_asdu_function[16] = &CCommon101Or104Analyzer::AnalyzeAsdu16;
	m_map_asdu_function[17] = &CCommon101Or104Analyzer::AnalyzeAsdu17;
	m_map_asdu_function[18] = &CCommon101Or104Analyzer::AnalyzeAsdu18;
	m_map_asdu_function[19] = &CCommon101Or104Analyzer::AnalyzeAsdu19;
	m_map_asdu_function[20] = &CCommon101Or104Analyzer::AnalyzeAsdu20;
	m_map_asdu_function[21] = &CCommon101Or104Analyzer::AnalyzeAsdu21;

	//asdu22~asdu29标准中未定义
	m_map_asdu_function[30] = &CCommon101Or104Analyzer::AnalyzeAsdu30;
	m_map_asdu_function[31] = &CCommon101Or104Analyzer::AnalyzeAsdu31;
	m_map_asdu_function[32] = &CCommon101Or104Analyzer::AnalyzeAsdu32;
	m_map_asdu_function[33] = &CCommon101Or104Analyzer::AnalyzeAsdu33;
	m_map_asdu_function[34] = &CCommon101Or104Analyzer::AnalyzeAsdu34;
	m_map_asdu_function[35] = &CCommon101Or104Analyzer::AnalyzeAsdu35;
	m_map_asdu_function[36] = &CCommon101Or104Analyzer::AnalyzeAsdu36;
	m_map_asdu_function[37] = &CCommon101Or104Analyzer::AnalyzeAsdu37;
	m_map_asdu_function[38] = &CCommon101Or104Analyzer::AnalyzeAsdu38;
	m_map_asdu_function[39] = &CCommon101Or104Analyzer::AnalyzeAsdu39;
	m_map_asdu_function[40] = &CCommon101Or104Analyzer::AnalyzeAsdu40;

	m_map_asdu_function[70] = &CCommon101Or104Analyzer::AnalyzeAsdu70;
	
	return 1;
}//InitAsduFunctionMap

int CCommon101Or104Analyzer::AnalyzeAsduMsg(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsduMsg Input Param Is Invalid!");
		return -1;
	}

	//获取报文中asdu类型
	m_nAsduType = chMsg[ASDU_TYPE_POISION];

	//在map中寻找相应的解析函数进行报文解析
	std::map<int, pFun> ::iterator itor = m_map_asdu_function.find(m_nAsduType);
	if (itor == m_map_asdu_function.end())
	{
		//没有找到对应的解析函数
		sprintf(m_chErrBuf, "Asdu Type %d Not Found Corresponding Function!", m_nAsduType);
		return -1;
	}
	else if (NULL == itor->second)
	{
		sprintf(m_chErrBuf, "Asdu Type %d Corresponding Function Addr Is NULL!", m_nAsduType);
		return -1;
	}
	else
	{
		return (this->*(itor->second))(chMsg, p101Or104Data);
	}
}//AnalyzeAsduMsg

int CCommon101Or104Analyzer::GetAsduType()
{
	return m_nAsduType;
}//GetAsduType

int CCommon101Or104Analyzer::AnalyzeAsdu1(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu1 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x01 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu1 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu1 asdu1;
		p101Or104Data->vec_Asdu1.clear();

		asdu1.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu1.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeSIQ(pCh, asdu1.siq);
				pCh += 1;

				p101Or104Data->vec_Asdu1.push_back(asdu1);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu1.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu1.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeSIQ(pCh, asdu1.siq);
				pCh += 1;

				p101Or104Data->vec_Asdu1.push_back(asdu1);

				nTempInfoAddr += 1;
				asdu1.nInfoAddr = nTempInfoAddr;
			}
		}
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu1 Caught Unhandled Exception!");
		return -1;
	}
	
	return 1;
}//AnalyzeAsdu1

int CCommon101Or104Analyzer::AnalyzeAsdu2(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu2 Input Param Is Invalid!");
		return -1;
	}
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x02 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu2 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu2 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu2 asdu2;
		p101Or104Data->vec_Asdu2.clear();

		asdu2.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu2.nInfoAddr =AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeSIQ(pCh, asdu2.siq);
			pCh += 1;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu2.ch3ByteTime, m_chTimeBuf, sizeof(asdu2.ch3ByteTime));

			p101Or104Data->vec_Asdu2.push_back(asdu2);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu2 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu2

int CCommon101Or104Analyzer::AnalyzeAsdu3(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu3 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x03 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu3 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu3 asdu3;
		p101Or104Data->vec_Asdu3.clear();

		asdu3.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu3.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeDIQ(pCh, asdu3.diq);
				pCh += 1;

				p101Or104Data->vec_Asdu3.push_back(asdu3);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu3.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu3.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeDIQ(pCh, asdu3.diq);
				pCh += 1;

				p101Or104Data->vec_Asdu3.push_back(asdu3);

				nTempInfoAddr += 1;
				asdu3.nInfoAddr = nTempInfoAddr;
			}
		}
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu3 Caught Unhandled Exception!");
		return -1;
	}

	return 1;
}//AnalyzeAsdu3

int CCommon101Or104Analyzer::AnalyzeAsdu4(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu4 Input Param Is Invalid!");
		return -1;
	}
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x04 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu4 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu4 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu4 asdu4;
		p101Or104Data->vec_Asdu4.clear();

		asdu4.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu4.nInfoAddr =AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeDIQ(pCh, asdu4.diq);
			pCh += 1;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu4.ch3ByteTime, m_chTimeBuf, sizeof(asdu4.ch3ByteTime));

			p101Or104Data->vec_Asdu4.push_back(asdu4);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu4 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu4

int CCommon101Or104Analyzer::AnalyzeAsdu5(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu5 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x05 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu5 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu5 asdu5;
		p101Or104Data->vec_Asdu5.clear();

		asdu5.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu5.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeVTI(pCh, asdu5.vti);
				pCh += 1;

				AnalyzeQDS(pCh, asdu5.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu5.push_back(asdu5);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu5.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu5.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeVTI(pCh, asdu5.vti);
				pCh += 1;

				AnalyzeQDS(pCh, asdu5.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu5.push_back(asdu5);

				nTempInfoAddr += 1;
				asdu5.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu5 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu5

int CCommon101Or104Analyzer::AnalyzeAsdu6(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu6 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x06 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu6 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu6 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu6 asdu6;
		p101Or104Data->vec_Asdu6.clear();

		asdu6.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu6.nInfoAddr =AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeVTI(pCh, asdu6.vti);
			pCh += 1;

			AnalyzeQDS(pCh, asdu6.qds);
			pCh += 1;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu6.ch3ByteTime, m_chTimeBuf, sizeof(asdu6.ch3ByteTime));

			p101Or104Data->vec_Asdu6.push_back(asdu6);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu6 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu6

int CCommon101Or104Analyzer::AnalyzeAsdu7(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu7 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x07 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu7 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu7 asdu7;
		p101Or104Data->vec_Asdu7.clear();

		asdu7.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu7.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeBSI(pCh, asdu7.bsi);
				pCh += 4;

				AnalyzeQDS(pCh, asdu7.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu7.push_back(asdu7);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu7.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu7.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeBSI(pCh, asdu7.bsi);
				pCh += 4;

				AnalyzeQDS(pCh, asdu7.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu7.push_back(asdu7);

				nTempInfoAddr += 1;
				asdu7.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu7 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu7

int CCommon101Or104Analyzer::AnalyzeAsdu8(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu8 Input Param Is Invalid!");
		return -1;
	}
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x08 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu8 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu8 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu8 asdu8;
		p101Or104Data->vec_Asdu8.clear();

		asdu8.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu8.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeBSI(pCh, asdu8.bsi);
			pCh += 4;

			AnalyzeQDS(pCh, asdu8.qds);
			pCh += 1;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu8.ch3ByteTime, m_chTimeBuf, sizeof(asdu8.ch3ByteTime));

			p101Or104Data->vec_Asdu8.push_back(asdu8);
		}

		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu8 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu8

int CCommon101Or104Analyzer::AnalyzeAsdu9(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu9 Input Param Is Invalid!");
		return -1;
	}

	//解析得到的数据是报文中的数据除以32767得到的整数,对于具体的真实值需要调用者自己再进行计算处理
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x09 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu9 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu9 asdu9;
		p101Or104Data->vec_Asdu9.clear();

		asdu9.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu9.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeNVA(pCh, asdu9.fValue);
				pCh += 2;

				AnalyzeQDS(pCh, asdu9.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu9.push_back(asdu9);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu9.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu9.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeNVA(pCh, asdu9.fValue);
				pCh += 2;

				AnalyzeQDS(pCh, asdu9.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu9.push_back(asdu9);

				nTempInfoAddr += 1;
				asdu9.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch(...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu9 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu9

int CCommon101Or104Analyzer::AnalyzeAsdu10(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu10 Input Param Is Invalid!");
		return -1;
	}
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x0a != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu10 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu10 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu10 asdu10;
		p101Or104Data->vec_Asdu10.clear();

		asdu10.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu10.nInfoAddr =AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeNVA(pCh, asdu10.fValue);
			pCh += 2;

			AnalyzeQDS(pCh, asdu10.qds);
			pCh += 1;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu10.ch3ByteTime, m_chTimeBuf, sizeof(asdu10.ch3ByteTime));

			p101Or104Data->vec_Asdu10.push_back(asdu10);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu10 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu10

int CCommon101Or104Analyzer::AnalyzeAsdu11(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu11 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x0b != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu11 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu11 asdu11;
		p101Or104Data->vec_Asdu11.clear();

		asdu11.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu11.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeSVA(pCh, asdu11.nValue);
				pCh += 2;

				AnalyzeQDS(pCh, asdu11.qds);
				pCh += 1;
				
				p101Or104Data->vec_Asdu11.push_back(asdu11);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu11.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu11.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeSVA(pCh, asdu11.nValue);
				pCh += 2;

				AnalyzeQDS(pCh, asdu11.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu11.push_back(asdu11);

				nTempInfoAddr += 1;
				asdu11.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu11 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu11

int CCommon101Or104Analyzer::AnalyzeAsdu12(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu12 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x0c != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu12 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu12 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu12 asdu12;
		p101Or104Data->vec_Asdu12.clear();

		asdu12.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu12.nInfoAddr =AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeSVA(pCh, asdu12.nValue);
			pCh += 2;

			AnalyzeQDS(pCh, asdu12.qds);
			pCh += 1;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu12.ch3ByteTime, m_chTimeBuf, sizeof(asdu12.ch3ByteTime));

			p101Or104Data->vec_Asdu12.push_back(asdu12);
		}
		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu12 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu12

int CCommon101Or104Analyzer::AnalyzeAsdu13(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu13 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x0d != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu13 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu13 asdu13;
		p101Or104Data->vec_Asdu13.clear();

		asdu13.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu13.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeIEEE754(pCh, asdu13.fValue);
				pCh += 4;

				AnalyzeQDS(pCh, asdu13.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu13.push_back(asdu13);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu13.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu13.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeIEEE754(pCh, asdu13.fValue);
				pCh += 4;

				AnalyzeQDS(pCh, asdu13.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu13.push_back(asdu13);

				nTempInfoAddr += 1;
				asdu13.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu13 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu13

int CCommon101Or104Analyzer::AnalyzeAsdu14(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu14 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x0e != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu14 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu14 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu14 asdu14;
		p101Or104Data->vec_Asdu14.clear();

		asdu14.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu14.nInfoAddr =AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeIEEE754(pCh, asdu14.fValue);
			pCh += 4;

			AnalyzeQDS(pCh, asdu14.qds);
			pCh += 1;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu14.ch3ByteTime, m_chTimeBuf, sizeof(asdu14.ch3ByteTime));

			p101Or104Data->vec_Asdu14.push_back(asdu14);
		}
		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu14 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu14

int CCommon101Or104Analyzer::AnalyzeAsdu15(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu15 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x0f != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu15 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu15 asdu15;
		p101Or104Data->vec_Asdu15.clear();

		asdu15.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu15.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeBCR(pCh, asdu15.bcr);
				pCh += 5;

				p101Or104Data->vec_Asdu15.push_back(asdu15);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu15.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu15.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeBCR(pCh, asdu15.bcr);
				pCh += 5;

				p101Or104Data->vec_Asdu15.push_back(asdu15);

				nTempInfoAddr += 1;
				asdu15.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu15 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu15

int CCommon101Or104Analyzer::AnalyzeAsdu16(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu16 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x10 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu16 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu16 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu16 asdu16;
		p101Or104Data->vec_Asdu16.clear();

		asdu16.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu16.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeBCR(pCh, asdu16.bcr);
			pCh += 5;

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu16.ch3ByteTime, m_chTimeBuf, sizeof(asdu16.ch3ByteTime));

			p101Or104Data->vec_Asdu16.push_back(asdu16);
		}
		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu16 Caught Unhandled Exception!");
		return -1;
	}


}//AnalyzeAsdu16

int CCommon101Or104Analyzer::AnalyzeAsdu17(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu17 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x11 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu17 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu17 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu17 asdu17;
		p101Or104Data->vec_Asdu17.clear();

		asdu17.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu17.nInfoAddr =AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeSEP(pCh, asdu17.sep);
			pCh += 1;

			int n2ByteTime = AnalyzeCP16Time2a(pCh, m_chTimeBuf);
			pCh += 2;
			memmove(asdu17.ch2ByteTime, m_chTimeBuf, sizeof(asdu17.ch2ByteTime));

			int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
			pCh += 3;
			memmove(asdu17.ch3ByteTime, m_chTimeBuf, sizeof(asdu17.ch3ByteTime));

			p101Or104Data->vec_Asdu17.push_back(asdu17);
		}
		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu17 Caught Unhandled Exception!");
		return -1;
	}
	

}//AnalyzeAsdu17

int CCommon101Or104Analyzer::AnalyzeAsdu18(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu18 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x12 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu18 Asdu Type Not Match!");
			return -1;
		}

        if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu18 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu18 asdu18;
		p101Or104Data->vec_Asdu18.clear();

		asdu18.dui = m_dataUnitIdent;

		asdu18.nInfoAddr =AnalyzeInfoObjAddr(pCh);
		pCh += m_nInfObjAddrNum;

		AnalyzeSPE(pCh, asdu18.spe);
		pCh += 1;

		AnalyzeQDP(pCh, asdu18.qdp);
		pCh += 1;

		int n2ByteTime = AnalyzeCP16Time2a(pCh, m_chTimeBuf);
		pCh += 2;
		memmove(asdu18.ch2ByteTime, m_chTimeBuf, sizeof(asdu18.ch2ByteTime));

		int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
		pCh += 3;
		memmove(asdu18.ch3ByteTime, m_chTimeBuf, sizeof(asdu18.ch3ByteTime));

		p101Or104Data->vec_Asdu18.push_back(asdu18);

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu18 Caught Unhandled Exception!");
		return -1;
	}


}//AnalyzeAsdu18

int CCommon101Or104Analyzer::AnalyzeAsdu19(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu19 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x13 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu19 Asdu Type Not Match!");
			return -1;
		}

        if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu19 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu19 asdu19;
		p101Or104Data->vec_Asdu19.clear();

		asdu19.dui = m_dataUnitIdent;

		asdu19.nInfoAddr =AnalyzeInfoObjAddr(pCh);
		pCh += m_nInfObjAddrNum;

		AnalyzeOCI(pCh, asdu19.oci);
		pCh += 1;

		AnalyzeQDP(pCh, asdu19.qdp);
		pCh += 1;

		int n2ByteTime = AnalyzeCP16Time2a(pCh, m_chTimeBuf);
		pCh += 2;
		memmove(asdu19.ch2ByteTime, m_chTimeBuf, sizeof(asdu19.ch2ByteTime));

		int n3ByteTime = AnalyzeCP24Time2a(pCh, m_chTimeBuf);
		pCh += 3;
		memmove(asdu19.ch3ByteTime, m_chTimeBuf, sizeof(asdu19.ch3ByteTime));

		p101Or104Data->vec_Asdu19.push_back(asdu19);

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu19 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu19

int CCommon101Or104Analyzer::AnalyzeAsdu20(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu20 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x14 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu20 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu20 asdu20;
		p101Or104Data->vec_Asdu20.clear();

		asdu20.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu20.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeSCD(pCh, asdu20.scd);
				pCh += 4;

				AnalyzeQDS(pCh, asdu20.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu20.push_back(asdu20);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu20.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu20.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{

				AnalyzeSCD(pCh, asdu20.scd);
				pCh += 4;

				AnalyzeQDS(pCh, asdu20.qds);
				pCh += 1;

				p101Or104Data->vec_Asdu20.push_back(asdu20);

				nTempInfoAddr += 1;
				asdu20.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu20 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu20

int CCommon101Or104Analyzer::AnalyzeAsdu21(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu21 Input Param Is Invalid!");
		return -1;
	}

	//解析得到的数据是报文中的数据除以32767得到的整数,对于具体的真实值需要调用者自己再进行计算处理
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x15 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu21 Asdu Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu21 asdu21;
		p101Or104Data->vec_Asdu21.clear();

		asdu21.dui = m_dataUnitIdent;

		if (0 == m_dataUnitIdent.vsq.nContinuous)//信息体地址断续数据
		{
			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				asdu21.nInfoAddr = AnalyzeInfoObjAddr(pCh);
				pCh += m_nInfObjAddrNum;

				AnalyzeNVA(pCh, asdu21.fValue);
				pCh += 2;

				p101Or104Data->vec_Asdu21.push_back(asdu21);
			}
		}
		else if (1 == m_dataUnitIdent.vsq.nContinuous)//信息体地址连续数据
		{
			asdu21.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			int nTempInfoAddr = asdu21.nInfoAddr;
			pCh += m_nInfObjAddrNum;

			for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
			{
				AnalyzeNVA(pCh, asdu21.fValue);
				pCh += 2;

				p101Or104Data->vec_Asdu21.push_back(asdu21);

				nTempInfoAddr += 1;
				asdu21.nInfoAddr = nTempInfoAddr;
			}
		}
		return 1;
	}
	catch(...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu21 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu21

int CCommon101Or104Analyzer::AnalyzeAsdu30(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu30 Input Param Is Invalid!");
		return -1;
	}
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x1e != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu30 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu30 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu30 asdu30;
		p101Or104Data->vec_Asdu30.clear();

		asdu30.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu30.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeSIQ(pCh, asdu30.siq);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu30.ch7ByteTime, m_chTimeBuf, sizeof(asdu30.ch7ByteTime));

			p101Or104Data->vec_Asdu30.push_back(asdu30);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu30 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu30

int CCommon101Or104Analyzer::AnalyzeAsdu31(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu31 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu31 Vsq Is Invalid!");
			return -1;
		}

		if (0x1f != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu31 Asdu Type Not Match!");
			return -1;
		}


		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu31 asdu31;
		p101Or104Data->vec_Asdu31.clear();

		asdu31.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu31.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeDIQ(pCh, asdu31.diq);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu31.ch7ByteTime, m_chTimeBuf, sizeof(asdu31.ch7ByteTime));

			p101Or104Data->vec_Asdu31.push_back(asdu31);
		}

		return 1;	
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu31 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu31

int CCommon101Or104Analyzer::AnalyzeAsdu32(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu32 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x20 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu32 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu32 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu32 asdu32;
		p101Or104Data->vec_Asdu32.clear();

		asdu32.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu32.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeVTI(pCh, asdu32.vti);
			pCh += 1;

			AnalyzeQDS(pCh, asdu32.qds);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu32.ch7ByteTime, m_chTimeBuf, sizeof(asdu32.ch7ByteTime));

			p101Or104Data->vec_Asdu32.push_back(asdu32);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu32 Caught Unhandled Exception!");
		return -1;
	}
	
	return 1;
}//AnalyzeAsdu32

int CCommon101Or104Analyzer::AnalyzeAsdu33(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu33 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu33 Vsq Is Invalid!");
			return -1;
		}

		if (0x21 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu33 Asdu Type Not Match!");
			return -1;
		}


		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu33 asdu33;
		p101Or104Data->vec_Asdu33.clear();

		asdu33.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu33.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeBSI(pCh, asdu33.bsi);
			pCh += 4;

			AnalyzeQDS(pCh, asdu33.qds);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu33.ch7ByteTime, m_chTimeBuf, sizeof(asdu33.ch7ByteTime));

			p101Or104Data->vec_Asdu33.push_back(asdu33);
		}

		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu33 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu33

int CCommon101Or104Analyzer::AnalyzeAsdu34(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu34 Input Param Is Invalid!");
		return -1;
	}

	//解析得到的数据是报文中的数据除以32767得到的整数,对于具体的真实值需要调用者自己再进行计算处理
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x22 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu34 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq不满足规约标准
			sprintf(m_chErrBuf, "AnalyzeAsdu34 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu34 asdu34;
		p101Or104Data->vec_Asdu34.clear();

		asdu34.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu34.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeNVA(pCh, asdu34.fValue);
			pCh += 2;

			AnalyzeQDS(pCh, asdu34.qds);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu34.ch7ByteTime, m_chTimeBuf, sizeof(asdu34.ch7ByteTime));

			p101Or104Data->vec_Asdu34.push_back(asdu34);
		}
	
		return 1;
	}
	catch(...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu34 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu34

int CCommon101Or104Analyzer::AnalyzeAsdu35(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu35 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x23 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu35 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq最高位不满足标准要求
			sprintf(m_chErrBuf, "AnalyzeAsdu35 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu35 asdu35;
		p101Or104Data->vec_Asdu35.clear();

		asdu35.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu35.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeSVA(pCh, asdu35.nValue);
			pCh += 2;

			AnalyzeQDS(pCh, asdu35.qds);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu35.ch7ByteTime, m_chTimeBuf, sizeof(asdu35.ch7ByteTime));

			p101Or104Data->vec_Asdu35.push_back(asdu35);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu35 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu35

int CCommon101Or104Analyzer::AnalyzeAsdu36(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu36 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x24 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu36 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq最高位不满足标准要求
			sprintf(m_chErrBuf, "AnalyzeAsdu36 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu36 asdu36;
		p101Or104Data->vec_Asdu36.clear();

		asdu36.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu36.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeIEEE754(pCh, asdu36.fValue);
			pCh += 4;

			AnalyzeQDS(pCh, asdu36.qds);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu36.ch7ByteTime, m_chTimeBuf, sizeof(asdu36.ch7ByteTime));

			p101Or104Data->vec_Asdu36.push_back(asdu36);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu36 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu36

int CCommon101Or104Analyzer::AnalyzeAsdu37(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg ||
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu37 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x25 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu37 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq最高位不满足标准要求
			sprintf(m_chErrBuf, "AnalyzeAsdu37 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu37 asdu37;
		p101Or104Data->vec_Asdu37.clear();

		asdu37.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu37.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeBCR(pCh, asdu37.bcr);
			pCh += 5;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu37.ch7ByteTime, m_chTimeBuf, sizeof(asdu37.ch7ByteTime));

			p101Or104Data->vec_Asdu37.push_back(asdu37);
		}

		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu37 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu37

int CCommon101Or104Analyzer::AnalyzeAsdu38(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu38 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x26 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu38 Asdu Type Not Match!");
			return -1;
		}

		if (0x00 != m_dataUnitIdent.vsq.nContinuous)
		{
			//vsq最高位不满足标准要求
			sprintf(m_chErrBuf, "AnalyzeAsdu38 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;
		
		int i = 0;
		Asdu38 asdu38;
		p101Or104Data->vec_Asdu38.clear();

		asdu38.dui = m_dataUnitIdent;

		for (i = 0; i < m_dataUnitIdent.vsq.nVsq; i++)
		{
			asdu38.nInfoAddr = AnalyzeInfoObjAddr(pCh);
			pCh += m_nInfObjAddrNum;

			AnalyzeSEP(pCh, asdu38.sep);
			pCh += 1;

			int n2ByteTime = AnalyzeCP16Time2a(pCh, m_chTimeBuf);
			pCh += 2;
			memmove(asdu38.ch2ByteTime, m_chTimeBuf, sizeof(asdu38.ch2ByteTime));

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu38.ch7ByteTime, m_chTimeBuf, sizeof(asdu38.ch7ByteTime));

			p101Or104Data->vec_Asdu38.push_back(asdu38);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu38 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu38

int CCommon101Or104Analyzer::AnalyzeAsdu39(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu39 Input Param Is Invalid!");
		return -1;
	}

	//解析得到的数据是报文中的数据除以32767得到的整数,对于具体的真实值需要调用者自己再进行计算处理
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x27 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu39 Asdu Type Not Match!");
			return -1;
		}

        if (0x01 != m_dataUnitIdent.vsq.nVsq)
		{
			//vsq不满足规范
			sprintf(m_chErrBuf, "AnalyzeAsdu39 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu39 asdu39;
		p101Or104Data->vec_Asdu39.clear();

		asdu39.dui = m_dataUnitIdent;

		asdu39.nInfoAddr = AnalyzeInfoObjAddr(pCh);
		pCh += m_nInfObjAddrNum;

		AnalyzeSPE(pCh, asdu39.spe);
		pCh += 1;

		AnalyzeQDP(pCh, asdu39.qdp);
		pCh += 1;

		int n2ByteTime = AnalyzeCP16Time2a(pCh, m_chTimeBuf);
		pCh += 2;
		memmove(asdu39.ch2ByteTime, m_chTimeBuf, sizeof(asdu39.ch2ByteTime));

		int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
		pCh += 7;
		memmove(asdu39.ch7ByteTime, m_chTimeBuf, sizeof(asdu39.ch7ByteTime));

		p101Or104Data->vec_Asdu39.push_back(asdu39);

		return 1;
	}
	catch( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu39 Caught Unhandled Exception!");
		return -1;
	}
	return -1;
}//AnalyzeAsdu39

int CCommon101Or104Analyzer::AnalyzeAsdu40(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu40 Input Param Is Invalid!");
		return -1;
	}

	//解析得到的数据是报文中的数据除以32767得到的整数,对于具体的真实值需要调用者自己再进行计算处理
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x28 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu40 Asdu Type Not Match!");
			return -1;
		}

        if (0x01 != m_dataUnitIdent.vsq.nVsq)
		{
			//vsq不满足规范
			sprintf(m_chErrBuf, "AnalyzeAsdu40 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu40 asdu40;
		p101Or104Data->vec_Asdu40.clear();

		asdu40.dui = m_dataUnitIdent;

		asdu40.nInfoAddr = AnalyzeInfoObjAddr(pCh);
		pCh += m_nInfObjAddrNum;

		AnalyzeOCI(pCh, asdu40.oci);
		pCh += 1;

		AnalyzeQDP(pCh, asdu40.qdp);
		pCh += 1;

		int n2ByteTime = AnalyzeCP16Time2a(pCh, m_chTimeBuf);
		pCh += 2;
		memmove(asdu40.ch2ByteTime, m_chTimeBuf, sizeof(asdu40.ch2ByteTime));

		int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
		pCh += 7;
		memmove(asdu40.ch7ByteTime, m_chTimeBuf, sizeof(asdu40.ch7ByteTime));

		p101Or104Data->vec_Asdu40.push_back(asdu40);

		return 1;
	}
	catch( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu40 Caught Unhandled Exception!");
		return -1;
	}
	return -1;
}//AnalyzeAsdu40

int CCommon101Or104Analyzer::AnalyzeAsdu70(unsigned char* chMsg, CC101Or104Data* p101Or104Data)
{
	if (NULL == chMsg || 
		NULL == p101Or104Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu70 Input Param Is Invalid!");
		return -1;
	}

	//解析得到的数据是报文中的数据除以32767得到的整数,对于具体的真实值需要调用者自己再进行计算处理
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x46 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu70 Asdu Type Not Match!");
			return -1;
		}

        if (0x01 != m_dataUnitIdent.vsq.nVsq)
		{
			//vsq不满足规范
			sprintf(m_chErrBuf, "AnalyzeAsdu70 Vsq Is Invalid!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		int i = 0;
		Asdu70 asdu70;
		p101Or104Data->vec_Asdu70.clear();

		asdu70.dui = m_dataUnitIdent;

		asdu70.nInfoAddr = AnalyzeInfoObjAddr(pCh);
		pCh += m_nInfObjAddrNum;

        asdu70.coi.nLocalParam = (0x80 == (pCh[0] & 0x80)) ? 1:0;
        asdu70.coi.nCoiReason = pCh[0] & 0x7f;
		pCh += 1;

		p101Or104Data->vec_Asdu70.push_back(asdu70);

		return 1;
	}
	catch( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu70 Caught Unhandled Exception!");
		return -1;
	}
	return -1;
}//AnalyzeAsdu70

int CCommon101Or104Analyzer::AnalyzeCP56Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE])
{
	if (NULL == chMsg || 
		NULL == chTimeBuf)
	{
		sprintf(m_chErrBuf, "AnalyzeCP56Time2a Input Param Is Invalid!");
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		int nYear = pCh[6] & 0x7f;
		int nMonth = pCh[5] & 0x0f;
		int nDay = pCh[4] & 0x1f;
		int nDate = pCh[4] & 0xe0;
		int nHour = pCh[3] & 0x1f;//没有考虑夏令时标志位
		int nMinute = pCh[2] & 0x3f;//没有考虑非法标志位
		/*int nMillSecH = pCh[1] & 0xff;
		int nMillSecL = pCh[0] & 0xff;*/
		int nMillSec = ((pCh[1]<<8) | pCh[0]) & 0xffff;
		int nSec = nMillSec / 1000;
		int nMillSeco = nMillSec % 1000;

		memset(chTimeBuf, '\0', sizeof(chTimeBuf));
		if (nYear < 70)
		{
			nYear = nYear + 2000;
		}
		else if (nYear >= 70)
		{
			nYear = nYear + 1900;
		}
		/*sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%03d.%03d", nYear, nMonth, nDay, nHour, nMinute, nMillSecL, nMillSecH);*/
		sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", nYear, nMonth, nDay, nHour, nMinute, nSec, nMillSeco);

		return 1;
	}
	catch( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeCP56Time2a Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeCP56Time2a

int CCommon101Or104Analyzer::AnalyzeCP16Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE])
{
	if (NULL == chMsg || 
		NULL == chTimeBuf)
	{
		sprintf(m_chErrBuf, "AnalyzeCP16Time2a Input Param Is Invalid!");
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		int nTime = (chMsg[1] << 8) | chMsg[0];

		memset(chTimeBuf, '\0', sizeof(chTimeBuf));
		sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%03d.%03d", 0, 0, 0, 0, 0, nTime/1000, nTime%1000);

		return 1;//标准规定2字节时标范围是0~59999ms,需要调用者自己判断正确与否
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeCP16Time2a Caught Unhandled Exception!");
		return -1;
	}	
}//AnalyzeCP16Time2a

int CCommon101Or104Analyzer::AnalyzeCP24Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE])
{
	if (NULL == chMsg || 
		NULL == chTimeBuf)
	{
		sprintf(m_chErrBuf, "AnalyzeCP24Time2a Input Param Is Invalid!");
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		int nMinute = pCh[2] & 0x3f;//未考虑有效位
		/*int nMillSecH = pCh[1] & 0xff;
		int nMillSecL = pCh[0] & 0xff;*/
        int nMillSec = (pCh[1] << 8) | pCh[0];

		memset(chTimeBuf, '\0', sizeof(chTimeBuf));
       /* sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%03d.%03d", 0, 0, 0, 0, nMinute, nMillSecL, nMillSecH);*/
		sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", 0, 0, 0, 0, nMinute, nMillSec/1000, nMillSec%1000);

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeCP24Time2a Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeCP24Time2a

int CCommon101Or104Analyzer::RevertByteOrder(unsigned char* chMsg, const int nLength, unsigned int& nRet)
{
	unsigned char* pCh = chMsg;
	int nTemp = nLength;
	int nTotalValue = 0;
	int nByteValue;

	while (nTemp > 0)
	{
		nByteValue = *(pCh + nTemp - 1) << ((nTemp - 1)*8);
		nTotalValue |= nByteValue;
		nTemp --;
	}

	nRet = nTotalValue;

	return 1;
}//RevertByteOrder

int CCommon101Or104Analyzer::AnalyzeAsduType(unsigned char* chMsg)
{
	return chMsg[0];
}//AnalyzeAsduType

int CCommon101Or104Analyzer::AnalyzeVsq(unsigned char* chMsg, unsigned int& nNum)
{
	unsigned char* pCh = chMsg;

	//最高字节是chMsg[m_nVsqNum]这个值,将其按位与0x80得到最高位,此位表明后续的信息体中的元素的信息体地址是连续的(1_0x80)还是断续的(0_0x00)
	int nVariable = *(pCh + m_nVsqNum -1) & 0x80;
	
	//之后置最高字节的最高位为0,获取信息体个数,结果存在nNum中
	*(pCh + m_nVsqNum -1) = *(pCh + m_nVsqNum -1) & 0x7f;

	RevertByteOrder(pCh, m_nVsqNum, nNum);

	//返回信息体地址顺序规则给调用者
	if (0x80 == nVariable)
	{
		return 1;
	}
	else if (0x00 == nVariable)
	{
		return 0;
	}

	return -1;
}//AnalyzeVsq

int CCommon101Or104Analyzer::AnalyzeCOT(unsigned char* chMsg)
{
	unsigned int nNum;
	RevertByteOrder(chMsg, m_nCotNum, nNum);
	return nNum;
}//AnalyzeCOT

int CCommon101Or104Analyzer::AnalyzeCommonAddr(unsigned char* chMsg)
{
	unsigned int nNum;
	RevertByteOrder(chMsg, m_nCommonAddrNum, nNum);
	return nNum;
}//AnalyzeCommonAddr

int CCommon101Or104Analyzer::AnalyzeDataUnitIdentifier(unsigned char* chMsg)
{
	InitDataUnitIdentifier();

	unsigned char* pCh = chMsg;

	m_dataUnitIdent.nType = AnalyzeAsduType(pCh);
	if (m_dataUnitIdent.nType > 0)
	{
		pCh += m_nAsduNum;
	}
	else
	{
		return -1;
	}

	m_dataUnitIdent.vsq.nContinuous = AnalyzeVsq(pCh, m_dataUnitIdent.vsq.nVsq);
	if (-1 != m_dataUnitIdent.vsq.nVsq)
	{
		pCh += m_nVsqNum;
	}
	else
	{
		return -1;
	}

	m_dataUnitIdent.nCot = AnalyzeCOT(pCh);
	if (-1 != m_dataUnitIdent.nCot)
	{
		pCh += m_nCotNum;
	}
	else
	{
		return -1;
	}

	m_dataUnitIdent.nCommonAddr = AnalyzeCommonAddr(pCh);
	if (-1 != m_dataUnitIdent.nCommonAddr)
	{
		pCh += m_nCommonAddrNum;
	} 
	else
	{
		return -1;
	}

	return 1;
}//AnalyzeDataUnitIdentifier

int CCommon101Or104Analyzer::InitDataUnitIdentifier(void)
{
	m_dataUnitIdent.nCommonAddr = 0;
	m_dataUnitIdent.nCot = 0;
	m_dataUnitIdent.nType = 0;
	m_dataUnitIdent.vsq.nContinuous = 0;
	m_dataUnitIdent.vsq.nVsq = 0;
	return 1;
}//InitDataUnitIdentifier

int CCommon101Or104Analyzer::AnalyzeInfoObjAddr(unsigned char* chMsg)
{
	unsigned int nNum;
	RevertByteOrder(chMsg, m_nInfObjAddrNum, nNum);
	return nNum;
}//AnalyzeInfoObjAddr

int CCommon101Or104Analyzer::AnalyzeSEP(unsigned char* chMsg, SEP& sep)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		sep.nIV = (0x80 == (pCh[0] & 0x80)) ? 1 : 0;
		sep.nNT = (0x40 == (pCh[0] & 0x40)) ? 1 : 0;
		sep.nSB = (0x20 == (pCh[0] & 0x20)) ? 1 : 0;
		sep.nBL = (0x10 == (pCh[0] & 0x10)) ? 1 : 0;
		sep.nEI = (0x08 == (pCh[0] & 0x08)) ? 1 : 0;
		sep.nES = pCh[0] & 0x03;
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeSEP

int CCommon101Or104Analyzer::AnalyzeSPE(unsigned char* chMsg, SPE& spe)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		spe.nRES = 0;
        spe.nSRD = (0x20 == (pCh[0] & 0x20)) ? 1:0;
        spe.nSIE = (0x10 == (pCh[0] & 0x10)) ? 1:0;
        spe.nSL3 = (0x08 == (pCh[0] & 0x08)) ? 1:0;
        spe.nSL2 = (0x04 == (pCh[0] & 0x04)) ? 1:0;
        spe.nSL1 = (0x02 == (pCh[0] & 0x02)) ? 1:0;
        spe.nGS = (0x01 == (pCh[0] & 0x01)) ? 1:0;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeSPE

int CCommon101Or104Analyzer::AnalyzeQDP(unsigned char* chMsg, QDP& qdp)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
        qdp.nIV = (0x80 == (pCh[0] & 0x80)) ? 1:0;
        qdp.nNT = (0x40 == (pCh[0] & 0x40)) ? 1:0;
        qdp.nSB = (0x20 == (pCh[0] & 0x20)) ? 1:0;
        qdp.nBL = (0x10 == (pCh[0] & 0x10)) ? 1:0;
        qdp.nEI = (0x08 == (pCh[0] & 0x08)) ? 1:0;
		qdp.nRES = 0x00;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeQDP

int CCommon101Or104Analyzer::AnalyzeOCI(unsigned char* chMsg, OCI& oci)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		oci.nRES = 0;
        oci.nCL3 = (0x08 == (pCh[0] & 0x08)) ? 1:0;
        oci.nCL2 = (0x04 == (pCh[0] & 0x04)) ? 1:0;
        oci.nCL1 = (0x02 == (pCh[0] & 0x02)) ? 1:0;
        oci.nGC = (0x01 == (pCh[0] & 0x01)) ? 1:0;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeOCI

int CCommon101Or104Analyzer::AnalyzeSIQ(unsigned char* chMsg, SIQ& siq)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		siq.nIV = (0x80 == (pCh[0] & 0x80)) ? 1 : 0;
		siq.nNT = (0x40 == (pCh[0] & 0x40)) ? 1 : 0;
		siq.nSB = (0x20 == (pCh[0] & 0x20)) ? 1 : 0;
		siq.nBL = (0x10 == (pCh[0] & 0x10)) ? 1 : 0;
		siq.nSPI = pCh[0] & 0x01;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeSIQ

int CCommon101Or104Analyzer::AnalyzeDIQ(unsigned char* chMsg, DIQ& diq)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		diq.nIV = (0x80 == (pCh[0] & 0x80)) ? 1 : 0;
		diq.nNT = (0x40 == (pCh[0] & 0x40)) ? 1 : 0;
		diq.nSB = (0x20 == (pCh[0] & 0x20)) ? 1 : 0;
		diq.nBL = (0x10 == (pCh[0] & 0x10)) ? 1 : 0;
		diq.nDPI = pCh[0] & 0x03;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeDIQ

int CCommon101Or104Analyzer::AnalyzeQDS(unsigned char* chMsg, QDS& qds)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		qds.nIV = (0x80 == (pCh[0] & 0x80)) ? 1 : 0;
		qds.nNT = (0x40 == (pCh[0] & 0x40)) ? 1 : 0;
		qds.nSB = (0x20 == (pCh[0] & 0x20)) ? 1 : 0;
		qds.nBL = (0x10 == (pCh[0] & 0x10)) ? 1 : 0;
		qds.nOV = pCh[0] & 0x01;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeQDS

int CCommon101Or104Analyzer::AnalyzeVTI(unsigned char* chMsg, VTI& vti)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		vti.nT = (0x80 == (pCh[0] & 0x80)) ? 1 : 0;
		vti.nValue = pCh[0] & 0x7f;//需要再考虑7位有符号数的解析

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeVTI

int CCommon101Or104Analyzer::AnalyzeNVA(unsigned char* chMsg, float& fValue)
{
	if (NULL == chMsg)
	{
		return -1;
	}
	try
	{
		unsigned char* pCh = chMsg;
		int nSign = (0x80 == (pCh[1] & 0x80))? 1:0;//符号位
		if (1 == nSign)//负数
		{
            fValue = -1.0 * (float)((~((pCh[1] << 8 ) | pCh[0]) & 0xffff) + 0x0001) / 0x8000;
		}
		else if (0 == nSign)//正数
		{
            fValue = (float)((pCh[1] << 8 ) | pCh[0]) / 0x8000;
		}
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeNVA

int CCommon101Or104Analyzer::AnalyzeSVA(unsigned char* chMsg, int& nValue)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

        int nSign = (0x80 == (pCh[1] & 0x80))? 1:0;//符号位
        if (1 == nSign)//负数
        {
            nValue = -1 * ((~((pCh[1] << 8 ) | pCh[0]) & 0xffff) + 0x0001);
        }
        else if (0 == nSign)//正数
        {
            nValue = (pCh[1] << 8) | pCh[0];
        }

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
	
}//AnalyzeSVA

int CCommon101Or104Analyzer::AnalyzeBSI(unsigned char* chMsg, BSI& bsi)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		
		
		unsigned char* pCh = chMsg;

		bsi.chBsi[0] = pCh[3];
		bsi.chBsi[1] = pCh[2];
		bsi.chBsi[2] = pCh[1];
		bsi.chBsi[3] = pCh[0];
		return 1;
	}
	catch (...)
	{
		return -1;
	}

}//AnalyzeBSI

int CCommon101Or104Analyzer::AnalyzeIEEE754(unsigned char* chMsg, float& fValue)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		int nTemp = (pCh[3] << 24) + (pCh[2] << 16) + (pCh[1] << 8) + pCh[0];
		memcpy(&fValue, &nTemp, 4);
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeIEEE754

int CCommon101Or104Analyzer::AnalyzeBCR(unsigned char* chMsg, BCR& bcr)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		bcr.nValue = (pCh[3] << 24) + (pCh[2] << 16) + (pCh[1] << 8) + pCh[0];
		bcr.IV = (0x80 == (pCh[4] & 0x80)) ? 1 : 0;
		bcr.CA = (0x40 == (pCh[4] & 0x40)) ? 1 : 0;
		bcr.CY = (0x20 == (pCh[4] & 0x20)) ? 1 : 0;
		bcr.SQ = pCh[4] & 0x1f;

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeBCR

int CCommon101Or104Analyzer::AnalyzeSCD(unsigned char* chMsg, SCD& scd)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		scd.chScd[0] = pCh[3];
		scd.chScd[1] = pCh[2];
		scd.chScd[2] = pCh[1];
		scd.chScd[3] = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeBCR
