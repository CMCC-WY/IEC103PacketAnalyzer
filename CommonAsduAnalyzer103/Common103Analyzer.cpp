#include "Common103Analyzer.h"
#include <stddef.h>
#include <string>

CCommon103Analyzer::CCommon103Analyzer(void)
{
}


CCommon103Analyzer::~CCommon103Analyzer(void)
{
}

int CCommon103Analyzer::SetDuiValue(int nCotNum, int nCommonAddrNum)
{
    m_nAsduNum = ASDU_TYPE_NUM_103;
    m_nVsqNum = VSQ_NUM_103;

	//传入参数错误的时候取默认值
	if (nCotNum <= 0 ||
		nCommonAddrNum <= 0)
	{
		m_nCotNum = 2;
		m_nCommonAddrNum = 2;
	}
	else
	{
		m_nCotNum = nCotNum;
		m_nCommonAddrNum = nCommonAddrNum;
	}
	
	m_nFirstInfoAddr = m_nAsduNum + m_nVsqNum + m_nCotNum + m_nCommonAddrNum;

	memset(m_chErrBuf, '\0', sizeof(m_chErrBuf));
	memset(m_chTimeBuf, '\0', sizeof(m_chTimeBuf));
	InitAsduFunctionMap();

	return 1;
}

int CCommon103Analyzer::GetAsduType()
{
	return m_nAsduType;
}//GetAsduType

int CCommon103Analyzer::WriteLog()
{
	//TODO
	return 1;
}//WriteLog

char* CCommon103Analyzer::GetLastLogMsg()
{
	return m_chErrBuf;
}//GetLastLogMsg

int CCommon103Analyzer::InitAsduFunctionMap(void)
{
	m_map_asdu_function[1] = &CCommon103Analyzer::AnalyzeAsdu1;
	m_map_asdu_function[2] = &CCommon103Analyzer::AnalyzeAsdu2;
	m_map_asdu_function[3] = &CCommon103Analyzer::AnalyzeAsdu3;
	m_map_asdu_function[4] = &CCommon103Analyzer::AnalyzeAsdu4;
	m_map_asdu_function[5] = &CCommon103Analyzer::AnalyzeAsdu5;
	m_map_asdu_function[6] = &CCommon103Analyzer::AnalyzeAsdu6;
	
	m_map_asdu_function[8] = &CCommon103Analyzer::AnalyzeAsdu8;
	m_map_asdu_function[9] = &CCommon103Analyzer::AnalyzeAsdu9;
	m_map_asdu_function[10] = &CCommon103Analyzer::AnalyzeAsdu10;
	m_map_asdu_function[11] = &CCommon103Analyzer::AnalyzeAsdu11;
	
	m_map_asdu_function[23] = &CCommon103Analyzer::AnalyzeAsdu23;
	m_map_asdu_function[26] = &CCommon103Analyzer::AnalyzeAsdu26;
	m_map_asdu_function[27] = &CCommon103Analyzer::AnalyzeAsdu27;
	m_map_asdu_function[28] = &CCommon103Analyzer::AnalyzeAsdu28;
	m_map_asdu_function[29] = &CCommon103Analyzer::AnalyzeAsdu29;
	m_map_asdu_function[30] = &CCommon103Analyzer::AnalyzeAsdu30;
	m_map_asdu_function[31] = &CCommon103Analyzer::AnalyzeAsdu31;
		
	return 1;
}//InitAsduFunctionMap

int CCommon103Analyzer::AnalyzeAsduMsg(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg ||
		NULL == p103Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsduMsg Input Param Is Invalid!");
		return -1;
	}

	//获取报文中asdu类型
     m_nAsduType = chMsg[ASDU_TYPE_POISION_103];

	//在map中寻找相应的解析函数进行报文解析
	std::map<int, pFun> ::iterator itor = m_map_asdu_function.find(m_nAsduType);
	if (itor == m_map_asdu_function.end())
	{
		//没有找到对应的解析函数
		sprintf(m_chErrBuf, "Asdu103_ Type %d Not Found Corresponding Function!", m_nAsduType);
		return -1;
	}
	else if (NULL == itor->second)
	{
		sprintf(m_chErrBuf, "Asdu103_ Type %d Corresponding Function Addr Is NULL!", m_nAsduType);
		return -1;
	}
	else
	{
		return (this->*(itor->second))(chMsg, p103Data);
	}
}//AnalyzeAsduMsg

int CCommon103Analyzer::AnalyzeAsdu1(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu1 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_1 asdu1;
		((CC103Data*)p103Data)->vec_Asdu103_1.clear();

		asdu1.dui = m_dataUnitIdent;

		{
			asdu1.nFUN = pCh[0];
			asdu1.nINF = pCh[1];
			pCh += 2;

			AnalyzeDPI(pCh, asdu1.dpi);
			pCh += 1;

			int n4ByteTime = AnalyzeCP32Time2a(pCh, m_chTimeBuf);
			pCh += 4;
			memmove(asdu1.ch4ByteTime, m_chTimeBuf, sizeof(asdu1.ch4ByteTime));

			AnalyzeSIN(pCh, asdu1.stru_sin);
			pCh += 1;

			((CC103Data*)p103Data)->vec_Asdu103_1.push_back(asdu1);
		}
		
		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu1 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu1

int CCommon103Analyzer::AnalyzeAsdu2(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu2 Asdu103_ Type Not Match!");
			return -1;
		}


		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_2 asdu2;
		((CC103Data*)p103Data)->vec_Asdu103_2.clear();

		asdu2.dui = m_dataUnitIdent;

		{

			asdu2.nFUN = pCh[0];
			asdu2.nINF = pCh[1];
			pCh += 2;

			AnalyzeDPI(pCh, asdu2.dpi);
			pCh += 1;

			AnalyzeRET(pCh,asdu2.ret);
			pCh += 2;

			AnalyzeFAN(pCh,asdu2.fan);
			pCh += 2;

			int n4ByteTime = AnalyzeCP32Time2a(pCh, m_chTimeBuf);
			pCh += 4;
			memmove(asdu2.ch4ByteTime, m_chTimeBuf, sizeof(asdu2.ch4ByteTime));

			AnalyzeSIN(pCh, asdu2.stru_sin);
			pCh += 1;

			((CC103Data*)p103Data)->vec_Asdu103_2.push_back(asdu2);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu2 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu2

int CCommon103Analyzer::AnalyzeAsdu3(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu3 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_3 asdu3;
		((CC103Data*)p103Data)->vec_Asdu103_3.clear();

		asdu3.dui = m_dataUnitIdent;

		asdu3.nFUN = pCh[0];
		asdu3.nINF = pCh[1];
		pCh += 2;

		MEA tempMea;
		for (int i = 0; i < asdu3.dui.vsq.nVsq; i++)
		{
			AnalyzeMEA(pCh, tempMea);
			asdu3.vec_meaValue.push_back(tempMea);
			pCh += 2;
		}

		((CC103Data*)p103Data)->vec_Asdu103_3.push_back(asdu3);

	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu3 Caught Unhandled Exception!");
		return -1;
	}

	return 1;
}//AnalyzeAsdu3

int CCommon103Analyzer::AnalyzeAsdu4(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu4 Asdu103_ Type Not Match!");
			return -1;
		}


		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_4 asdu4;
		((CC103Data*)p103Data)->vec_Asdu103_4.clear();

		asdu4.dui = m_dataUnitIdent;

		{

			asdu4.nFUN = pCh[0];
			asdu4.nINF = pCh[1];
			pCh += 2;

			AnalyzeSCL(pCh, asdu4.scl);
			pCh += 4;

			AnalyzeRET(pCh, asdu4.ret);
			pCh += 2;

			AnalyzeFAN(pCh, asdu4.fan);
			pCh += 2;

			int n4ByteTime = AnalyzeCP32Time2a(pCh, m_chTimeBuf);
			pCh += 4;
			memmove(asdu4.ch4ByteTime, m_chTimeBuf, sizeof(asdu4.ch4ByteTime));

			((CC103Data*)p103Data)->vec_Asdu103_4.push_back(asdu4);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu4 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu4

int CCommon103Analyzer::AnalyzeAsdu5(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu5 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		//int i = 0;
		Asdu103_5 asdu5;
		((CC103Data*)p103Data)->vec_Asdu103_5.clear();

		asdu5.dui = m_dataUnitIdent;

		asdu5.nFUN = pCh[0];
		asdu5.nINF = pCh[1];
		pCh += 2;

		AnalyzeCOL(pCh, asdu5.col);
		pCh += 1;

		asdu5.ASCII1 = pCh[0];
		asdu5.ASCII2 = pCh[1];
		asdu5.ASCII3 = pCh[2];
		asdu5.ASCII4 = pCh[3];
		asdu5.ASCII5 = pCh[4];
		asdu5.ASCII6 = pCh[5];
		asdu5.ASCII7 = pCh[6];
		asdu5.ASCII8 = pCh[7];
		asdu5.FreeValue1 = pCh[8];
		asdu5.FreeValue2 = pCh[9];
		asdu5.FreeValue3 = pCh[10];
		asdu5.FreeValue4 = pCh[11];

		((CC103Data*)p103Data)->vec_Asdu103_5.push_back(asdu5);

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu5 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu5

int CCommon103Analyzer::AnalyzeAsdu6(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu6 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_6 asdu6;
		((CC103Data*)p103Data)->vec_Asdu103_6.clear();

		asdu6.dui = m_dataUnitIdent;

		{

			asdu6.nFUN = pCh[0];
			asdu6.nINF = pCh[1];
			pCh += 2;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(asdu6.ch7ByteTime, m_chTimeBuf, sizeof(asdu6.ch7ByteTime));

			((CC103Data*)p103Data)->vec_Asdu103_6.push_back(asdu6);
		}

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu6 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu6

int CCommon103Analyzer::AnalyzeAsdu8(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg ||
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu8 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_8 asdu8;
		((CC103Data*)p103Data)->vec_Asdu103_8.clear();

		asdu8.dui = m_dataUnitIdent;

		{
			asdu8.nFUN = pCh[0];
			asdu8.nINF = pCh[1];
			pCh += 2;

			AnalyzeSCN(pCh, asdu8.scn);
			pCh += 1;

			((CC103Data*)p103Data)->vec_Asdu103_8.push_back(asdu8);
		}

		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu8 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu8

int CCommon103Analyzer::AnalyzeAsdu9(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu9 Input Param Is Invalid!");
		return -1;
	}

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
			sprintf(m_chErrBuf, "AnalyzeAsdu9 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_9 asdu9;
		((CC103Data*)p103Data)->vec_Asdu103_9.clear();

		asdu9.dui = m_dataUnitIdent;

		asdu9.nFUN = pCh[0];
		asdu9.nINF = pCh[1];
		pCh += 2;

		MEA tempMea;
		for (int i = 0; i < asdu9.dui.vsq.nVsq; i++)
		{
			AnalyzeMEA(pCh, tempMea);
			asdu9.vec_meaValue.push_back(tempMea);
			pCh += 2;
		}

        ((CC103Data*)p103Data)->vec_Asdu103_9.push_back(asdu9);

		return 1;
	}
	catch(...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu9 Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeAsdu9

int CCommon103Analyzer::AnalyzeAsdu10(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu10 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_10 asdu10;
		((CC103Data*)p103Data)->vec_Asdu103_10.clear();

		asdu10.dui = m_dataUnitIdent;

		asdu10.nGENTYP = pCh[0];
		pCh += 1;

		asdu10.nINF = pCh[0];
		pCh += 1;

		asdu10.nRII = pCh[0];
		pCh += 1;

		AnalyzeNGD(pCh, asdu10.ngd);
		pCh += 1;

		unsigned int i = 0;
		unsigned int j = 0;

		Asdu103_10DataSet tempAsdu103_10DataSet;
		GID tempgid;
		
		for (i = 0; i<asdu10.ngd.nNo; i++)
		{
			AnalyzeGIN(pCh, tempAsdu103_10DataSet.gin);
			pCh += 2;

			AnalyzeKOD(pCh, tempAsdu103_10DataSet.nKod);
			pCh += 1;

			AnalyzeGDD(pCh, tempAsdu103_10DataSet.gdd);
			pCh += 3;
			
			for (j = 0; j < tempAsdu103_10DataSet.gdd.nNum; j++)
			{
				AnalyzeGID(pCh, tempAsdu103_10DataSet.gdd.nType, tempAsdu103_10DataSet.gdd.nSize, tempgid);
				pCh += tempAsdu103_10DataSet.gdd.nSize;

				tempAsdu103_10DataSet.vec_GID.push_back(tempgid);
			}
			
			asdu10.vec_Asdu103_10DataSet.push_back(tempAsdu103_10DataSet);

		}

		((CC103Data*)p103Data)->vec_Asdu103_10.push_back(asdu10);

		return 1;
	}
	catch(...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu9 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu10

int CCommon103Analyzer::AnalyzeAsdu11(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu11 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_11 asdu11;
		((CC103Data*)p103Data)->vec_Asdu103_11.clear();

		asdu11.dui = m_dataUnitIdent;

		asdu11.nGENFUN = pCh[0];
		pCh += 1;

		asdu11.nINF = pCh[0];
		pCh += 1;

		asdu11.nRII = pCh[0];
		pCh += 1;

		AnalyzeGIN(pCh, asdu11.gin);
		pCh += 2;

		AnalyzeNDE(pCh, asdu11.nde);
		pCh += 1;

		unsigned int i = 0;
		unsigned int j = 0;

		Asdu103_11DataSet tempAsdu103_11DataSet;
		GID tempgid;

		for (i = 0; i<asdu11.nde.nNO; i++)
		{

			AnalyzeKOD(pCh, tempAsdu103_11DataSet.nKod);
			pCh += 1;

			AnalyzeGDD(pCh, tempAsdu103_11DataSet.gdd);
			pCh += 3;

			for (j = 0; j < tempAsdu103_11DataSet.gdd.nNum; j++)
			{
				AnalyzeGID(pCh, tempAsdu103_11DataSet.gdd.nType, tempAsdu103_11DataSet.gdd.nSize, tempgid);
				pCh += tempAsdu103_11DataSet.gdd.nSize;

				tempAsdu103_11DataSet.vec_GID.push_back(tempgid);
			}

			asdu11.vec_Asdu103_11DataSet.push_back(tempAsdu103_11DataSet);

		}

		((CC103Data*)p103Data)->vec_Asdu103_11.push_back(asdu11);

		return 1;
	}
	catch(...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu9 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu11

int CCommon103Analyzer::AnalyzeAsdu23(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg ||
		NULL == p103Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu23 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x17 != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu26 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_23 asdu23;
		((CC103Data*)p103Data)->vec_Asdu103_23.clear();

		asdu23.dui = m_dataUnitIdent;

		asdu23.nFUN = pCh[0];
		//INF规约规定为0
		pCh += 2;

		Asdu103_23DataSet tempAsdu103_23DataSet;

		unsigned int i = 0;
		for (i = 1; i <= m_dataUnitIdent.vsq.nVsq; i++)
		{
			AnalyzeFAN(pCh, tempAsdu103_23DataSet.fan);
			pCh += 2;

			AnalyzeSOF(pCh, tempAsdu103_23DataSet.sof);
			pCh += 1;

			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			pCh += 7;
			memmove(tempAsdu103_23DataSet.ch7ByteTime, m_chTimeBuf, sizeof(tempAsdu103_23DataSet.ch7ByteTime));

            asdu23.vec_Asdu103_23DataSet.push_back(tempAsdu103_23DataSet);
		}

		((CC103Data*)p103Data)->vec_Asdu103_23.push_back(asdu23);

		return 1;

	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu23 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu23

int CCommon103Analyzer::AnalyzeAsdu26(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg ||
		NULL == p103Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu26 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x1A != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu26 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_26 asdu26;
		((CC103Data*)p103Data)->vec_Asdu103_26.clear();

		asdu26.dui = m_dataUnitIdent;

		asdu26.nFUN = pCh[0];
		pCh += 3;

		AnalyzeTOV(pCh, asdu26.tov);
		pCh += 1;

		AnalyzeFAN(pCh, asdu26.fan);
		pCh += 2;

		AnalyzeNOF(pCh, asdu26.nof);
		pCh += 2;

		AnalyzeNOC(pCh, asdu26.noc);
		pCh += 1;

		AnalyzeNOE(pCh, asdu26.noe);
		pCh += 2;

		AnalyzeINT(pCh, asdu26.stru_INT);
		pCh += 2;

		int n4ByteTime = AnalyzeCP32Time2a(pCh, m_chTimeBuf);
		pCh += 4;
		memmove(asdu26.ch4ByteTime, m_chTimeBuf, sizeof(asdu26.ch4ByteTime));

		((CC103Data*)p103Data)->vec_Asdu103_26.push_back(asdu26);

		return 1;

	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu26 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu26

int CCommon103Analyzer::AnalyzeAsdu27(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg ||
		NULL == p103Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu27 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x1B != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu27 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_27 asdu27;
		((CC103Data*)p103Data)->vec_Asdu103_27.clear();

		asdu27.dui = m_dataUnitIdent;

		asdu27.nFUN = pCh[0];
		pCh += 3;

		AnalyzeTOV(pCh, asdu27.tov);
		pCh += 1;

		AnalyzeFAN(pCh, asdu27.fan);
		pCh += 2;

		AnalyzeACC(pCh, asdu27.acc);
		pCh += 1;

		//一次额定值
		AnalyzeIEEE754(pCh, asdu27.fPrimValue);
		pCh += 4;
		
		//二次额定值
		AnalyzeIEEE754(pCh, asdu27.fSecValue);
		pCh += 4;

		//参比因子
		AnalyzeIEEE754(pCh, asdu27.fRatio);
		pCh += 4;

		((CC103Data*)p103Data)->vec_Asdu103_27.push_back(asdu27);

		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu27 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu27

int CCommon103Analyzer::AnalyzeAsdu28(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg ||
		NULL == p103Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu28 Input Param Is Invalid!");
		return -1;
	}

	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x1C != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu28 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_28 asdu28;
		((CC103Data*)p103Data)->vec_Asdu103_28.clear();

		asdu28.dui = m_dataUnitIdent;

		asdu28.nFUN = pCh[0];
		pCh += 4;

		AnalyzeFAN(pCh, asdu28.fan);
		pCh += 2;

		((CC103Data*)p103Data)->vec_Asdu103_28.push_back(asdu28);

		return 1;

	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu28 Caught Unhandled Exception!");
		return -1;
	}


}//AnalyzeAsdu28

int CCommon103Analyzer::AnalyzeAsdu29(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg ||
		NULL == p103Data)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu29 Input Param Is Invalid!");
	}
	try
	{
		int nRet = AnalyzeDataUnitIdentifier(chMsg);
		if (-1 == nRet)
		{
			return -1;
		}

		if (0x1d != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu29 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_29 asdu29;
		((CC103Data*)p103Data)->vec_Asdu103_29.clear();

		asdu29.dui = m_dataUnitIdent;

		asdu29.nFUN = pCh[0];
		pCh += 2;

		AnalyzeFAN(pCh, asdu29.fan);
		pCh += 2;

		AnalyzeNOT(pCh, asdu29.stru_NOT);
		pCh += 1;

		AnalyzeTAP(pCh, asdu29.stru_TAP);
		pCh += 2;

		Asdu103_29DataSet tempAsdu103_29DataSet;

		unsigned int i = 0;
		for (i = 1; i <= asdu29.stru_NOT.nNot; i++)
		{
			tempAsdu103_29DataSet.nStateFUN = pCh[0];
			tempAsdu103_29DataSet.nStateINF = pCh[1];
			pCh += 2;

			AnalyzeDPI(pCh, tempAsdu103_29DataSet.dpi);
			pCh += 1;

            asdu29.vec_Asdu103_29DataSet.push_back(tempAsdu103_29DataSet);
		}

		((CC103Data*)p103Data)->vec_Asdu103_29.push_back(asdu29);

		return 1;

	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu29 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu29

int CCommon103Analyzer::AnalyzeAsdu30(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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
			sprintf(m_chErrBuf, "AnalyzeAsdu30 Asdu103_ Type Not Match!");
			return -1;
		}

		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		unsigned int i = 0;
		Asdu103_30 asdu30;
		((CC103Data*)p103Data)->vec_Asdu103_30.clear();

		asdu30.dui = m_dataUnitIdent;

		asdu30.nFUN = pCh[0];
		pCh += 3;

		AnalyzeTOV(pCh, asdu30.tov);
		pCh += 1;

		AnalyzeFAN(pCh, asdu30.fan);
		pCh += 2;

		AnalyzeACC(pCh, asdu30.acc);
		pCh += 1;

		AnalyzeNDV(pCh, asdu30.ndv);
		pCh += 2;

		AnalyzeNFE(pCh, asdu30.nfe);
		pCh += 2;

		if (asdu30.ndv.nNDV > 25)
		{
			sprintf(m_chErrBuf, "NDV is larger than 25,error!");
			return -1;
		}

		//扰动值SDV
		for (i=0; i < asdu30.ndv.nNDV; i++)
		{
			int nSign = (0x80 == (pCh[1] & 0x80)) ? 1 : 0;//符号位
			float fvalue = 0.0;
		
			if (1 == nSign)//负数
			{
				fvalue = -1.0 * (float)((~((pCh[1] << 8) | pCh[0]) & 0xffff) + 0x0001) / 0x8000;
			}
			else if (0 == nSign)//正数
			{
				fvalue = (float)((pCh[1] << 8) | pCh[0]) / 0x8000;
			}

			asdu30.sdv[i] = fvalue;

			pCh += 2;
		}

		((CC103Data*)p103Data)->vec_Asdu103_30.push_back(asdu30);

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu30 Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeAsdu30

int CCommon103Analyzer::AnalyzeAsdu31(unsigned char* chMsg, void* p103Data)
{
	if (NULL == chMsg || 
		NULL == p103Data)
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

		if (0x1f != m_dataUnitIdent.nType)
		{
			//asdu类型不匹配
			sprintf(m_chErrBuf, "AnalyzeAsdu31 Asdu103_ Type Not Match!");
			return -1;
		}


		unsigned char* pCh = chMsg;
		//指向第一个信息体
		pCh += m_nFirstInfoAddr;

		Asdu103_31 asdu31;
		((CC103Data*)p103Data)->vec_Asdu103_31.clear();

		asdu31.dui = m_dataUnitIdent;

		asdu31.nFUN = pCh[0];
		pCh += 2;

		AnalyzeTOO(pCh, asdu31.too);
		pCh += 1;

		AnalyzeTOV(pCh, asdu31.tov);
		pCh += 1;

		AnalyzeFAN(pCh, asdu31.fan);
		pCh += 2;

		AnalyzeACC(pCh, asdu31.acc);
		pCh += 1;

		((CC103Data*)p103Data)->vec_Asdu103_31.push_back(asdu31);

		return 1;	
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeAsdu31 Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeAsdu31

int CCommon103Analyzer::AnalyzeCP56Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103])
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
		int nMillSec = (pCh[1] << 8) | pCh[0];

		memset(chTimeBuf, '\0', sizeof(chTimeBuf));
		if (nYear < 70)
		{
			nYear = nYear + 2000;
		}
		else if (nYear >= 70)
		{
			nYear = nYear + 1900;
		}

		sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", nYear, nMonth, nDay, nHour, nMinute, nMillSec / 1000, nMillSec % 1000);

		return 1;
	}
	catch( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeCP56Time2a Caught Unhandled Exception!");
		return -1;
	}
	
}//AnalyzeCP56Time2a

int CCommon103Analyzer::AnalyzeCP16Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103])
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

int CCommon103Analyzer::AnalyzeCP24Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103])
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
		int nMillSec = (pCh[1] << 8) | pCh[0];

		memset(chTimeBuf, '\0', sizeof(chTimeBuf));

		sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", 0, 0, 0, 0, nMinute, nMillSec / 1000, nMillSec % 1000);

		return 1;
	}
	catch ( ... )
	{
		sprintf(m_chErrBuf, "AnalyzeCP24Time2a Caught Unhandled Exception!");
		return -1;
	}
}//AnalyzeCP24Time2a

int CCommon103Analyzer::AnalyzeCP32Time2a(unsigned char* chMsg, char chTimeBuf[TIME_BUF_SIZE_103])
{
	if (NULL == chMsg ||
		NULL == chTimeBuf)
	{
		sprintf(m_chErrBuf, "AnalyzeCP32Time2a Input Param Is Invalid!");
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		int nHour = pCh[3] & 0x1f;//没有考虑夏令时标志位
		int nMinute = pCh[2] & 0x3f;//没有考虑非法标志位
		int nMillSec = (pCh[1] << 8) | pCh[0];

		memset(chTimeBuf, '\0', sizeof(chTimeBuf));

		sprintf(chTimeBuf, "%04d-%02d-%02d %02d:%02d:%02d.%03d", 0, 0, 0, nHour, nMinute, nMillSec /1000 , nMillSec % 1000);

		return 1;
	}
	catch (...)
	{
		sprintf(m_chErrBuf, "AnalyzeCP32Time2a Caught Unhandled Exception!");
		return -1;
	}

}//AnalyzeCP32Time2a

int CCommon103Analyzer::RevertByteOrder(unsigned char* chMsg, const int nLength, unsigned int& nRet)
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

int CCommon103Analyzer::AnalyzeAsduType(unsigned char* chMsg)
{
	return chMsg[0];
}//AnalyzeAsduType

int CCommon103Analyzer::AnalyzeVsq(unsigned char* chMsg, unsigned int& nNum)
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

int CCommon103Analyzer::AnalyzeCOT(unsigned char* chMsg)
{
	unsigned int nNum;
	RevertByteOrder(chMsg, m_nCotNum, nNum);
	return nNum;
}//AnalyzeCOT

int CCommon103Analyzer::AnalyzeCommonAddr(unsigned char* chMsg)
{
	unsigned int nNum;
	RevertByteOrder(chMsg, m_nCommonAddrNum, nNum);
	return nNum;
}//AnalyzeCommonAddr

int CCommon103Analyzer::AnalyzeDataUnitIdentifier(unsigned char* chMsg)
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

int CCommon103Analyzer::InitDataUnitIdentifier(void)
{
	m_dataUnitIdent.nCommonAddr = 0;
	m_dataUnitIdent.nCot = 0;
	m_dataUnitIdent.nType = 0;
	m_dataUnitIdent.vsq.nContinuous = 0;
	m_dataUnitIdent.vsq.nVsq = 0;
	return 1;
}//InitDataUnitIdentifier

int CCommon103Analyzer::AnalyzeInfoObjAddr(unsigned char* chMsg)
{
	unsigned int nNum;
	RevertByteOrder(chMsg, m_nInfObjAddrNum, nNum);
	return nNum;
}//AnalyzeInfoObjAddr



int CCommon103Analyzer::AnalyzeNVA(unsigned char* chMsg, float& fValue)
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

int CCommon103Analyzer::AnalyzeSVA(unsigned char* chMsg, int& nValue)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		nValue = (pCh[1] << 8) | pCh[0];
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
	
}//AnalyzeSVA


int CCommon103Analyzer::AnalyzeIEEE754(unsigned char* chMsg, float& fValue)
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



int CCommon103Analyzer::AnalyzeDPI(unsigned char* chMsg, DPI& dpi)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		dpi.nDpi = pCh[0] & 0x03;

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeDPI

int CCommon103Analyzer::AnalyzeSIN(unsigned char* chMsg, SIN& struc_sin)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		struc_sin.nSIN = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeSIN

int CCommon103Analyzer::AnalyzeRET(unsigned char* chMsg, RET& ret)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		ret.nRET = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeRET

int CCommon103Analyzer::AnalyzeFAN(unsigned char* chMsg, FAN&fan)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		fan.nFAN = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeFAN

int CCommon103Analyzer::AnalyzeSCL(unsigned char* chMsg, SCL& scl)
{
	if (NULL == chMsg)
	{
		return -1;
	}
	try
	{
		
		unsigned char* pCh = chMsg;
		AnalyzeIEEE754(pCh, scl.fSCL);
        //int nTemp = (pCh[3] << 24) + (pCh[2] << 16) + (pCh[1] << 8) + pCh[0];
        //memcpy(&scl.fSCL, &nTemp, 4);
		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeSCL

int CCommon103Analyzer::AnalyzeCOL(unsigned char* chMsg, COL& col)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		col.nCOL = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeSIN

int CCommon103Analyzer::AnalyzeSCN(unsigned char* chMsg, SCN& scn)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		scn.nSCN = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeSCN

int CCommon103Analyzer::AnalyzeTOV(unsigned char* chMsg, TOV& tov)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		tov.nTOV = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeTOV

int CCommon103Analyzer::AnalyzeNOF(unsigned char* chMsg, NOF& nof)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		nof.nNOF = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeNOF

int CCommon103Analyzer::AnalyzeNOC(unsigned char* chMsg, NOC& noc)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		noc.nNOC = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeNOC

int CCommon103Analyzer::AnalyzeNOE(unsigned char* chMsg, NOE& noe)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		noe.nNOE = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeNOC

int CCommon103Analyzer::AnalyzeINT(unsigned char* chMsg, INT& stru_INT)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		stru_INT.nINT = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeINT

int CCommon103Analyzer::AnalyzeACC(unsigned char* chMsg, ACC& acc)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		acc.nACC = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeACC

int CCommon103Analyzer::AnalyzeTOO(unsigned char* chMsg, TOO& too)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		too.nToo = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeACC

int CCommon103Analyzer::AnalyzeNDV(unsigned char* chMsg, NDV& ndv)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		ndv.nNDV = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeNDV

int CCommon103Analyzer::AnalyzeNFE(unsigned char* chMsg, NFE& nfe)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		nfe.nNFE = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeNFE

int CCommon103Analyzer::AnalyzeNOT(unsigned char* chMsg, NOT& stru_NOT)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		stru_NOT.nNot = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeNOT

int CCommon103Analyzer::AnalyzeTAP(unsigned char* chMsg, TAP& stru_TAP)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		stru_TAP.nTap = (pCh[1] << 8) | pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeTAP

int CCommon103Analyzer::AnalyzeSOF(unsigned char* chMsg, SOF& sof)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		sof.nTP = (0x01 == (pCh[0] & 0x01)) ? 1 : 0;
		sof.nTM = (0x02 == (pCh[0] & 0x02)) ? 1 : 0;
		sof.nTEST = (0x04 == (pCh[0] & 0x04)) ? 1 : 0;
		sof.nOTEV = (0x08 == (pCh[0] & 0x08)) ? 1 : 0;
		sof.nRES = (pCh[0] >> 4) & 0x0f;

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeSOF

int CCommon103Analyzer::AnalyzeMEA(unsigned char* chMsg, MEA& mea)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		mea.nOV = (0x01 == (pCh[0] & 0x01)) ? 1 : 0;
		mea.nER = (0x02 == (pCh[0] & 0x02)) ? 1 : 0;
		mea.nRES = (0x04 == (pCh[0] & 0x04)) ? 1 : 0;

		int nSign = (0x80 == (pCh[1] & 0x80)) ? 1 : 0;//符号位
		if (1 == nSign)//负数
		{
			mea.fMVAL = -1.0 * (float)((~((pCh[1] << 8) | (pCh[0] & 0xf8)) & 0xfff8) + 0x0008) / 0x8000;
		}
		else if (0 == nSign)//正数
		{
			mea.fMVAL = (float)((pCh[1] << 8) | (pCh[0] & 0xf8)) / 0x8000;
		}

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeMEA

int CCommon103Analyzer::AnalyzeNGD(unsigned char* chMsg, NGD& ngd)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		ngd.nNo = pCh[0] & 0x3F;
		ngd.nCont = (0x80 == (pCh[0] & 0x80)) ? 1 : 0;

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeNGD

int CCommon103Analyzer::AnalyzeGIN(unsigned char* chMsg, GIN& gin)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		gin.nGroup = pCh[0];
		gin.nEntry = pCh[1];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeGIN

int CCommon103Analyzer::AnalyzeKOD(unsigned char* chMsg, unsigned int& nKod)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		nKod = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeKOD

int CCommon103Analyzer::AnalyzeGDD(unsigned char* chMsg, GDD& gdd)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		gdd.nType = pCh[0];
		gdd.nSize = pCh[1];
		gdd.nNum = pCh[2] & 0x7F;
		gdd.n_Cont = (0x80 == (pCh[2] & 0x80)) ? 1 : 0;

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeGDD

int CCommon103Analyzer::AnalyzeGID(unsigned char* chMsg, unsigned int& type, unsigned int& size, GID& gid)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		switch (type)
		{
		case 0:		//无数据
			return -1;

		case 1:		//ASCII8位码
			AnalyzeASCII(pCh, gid.ASCII);
			break;

		case 2:		//成组8位串		
			AnalyzeBSI(pCh, gid.bsi);
			break;
		case 3:		//无符号整数
			AnalyzeUnnValue(pCh, size, gid.UnnValue);
			break;
		case 4:		//整数
			AnalyzenValue(pCh, size, gid.nValue);
			break;
		case 5:		//无符号浮点数
			AnalyzeUnfValue(pCh, size, gid.UnfValue);
			break;

		case 6:		//浮点数
			AnalyzefValue(pCh, size, gid.fValue);
			break;
		case 7:		//IEEE标准754短实数
			AnalyzeIEEE754(pCh, gid.R32);
			break;
		case 8:		//IEEE标准754实数
			AnalyzeIEEER64(pCh, gid.R64);
			break;
		case 9:		//双点信息
			AnalyzeDPI(pCh, gid.dpi);
			break;
		case 10:	//单点信息	
			AnalyzeSPI(pCh, gid.spi);
			break;
		case 11:	//带瞬变和差错的双点信息	
			AnalyzenTEDPI(pCh, gid.nTEDPI);
			break;
		case 12:	//带品质描述词的被测值	
			AnalyzeMEA(pCh, gid.mea);
			break;
		case 13:	//备用	

			break;
		case 14:	//7个8位二进制时间
			{
			int n7ByteTime = AnalyzeCP56Time2a(pCh, m_chTimeBuf);
			memmove(gid.ch7ByteTime, m_chTimeBuf, sizeof(gid.ch7ByteTime));
			}

			break;
		case 15:	//通用分类标识序号	
			AnalyzeGIN(pCh, gid.gin);
			break;
		case 16:	//相对时间	
			AnalyzeRET(pCh, gid.ret);
			break;
		case 17:	//功能类型和信息序号	
			gid.nFUN = pCh[0];
			gid.nINF = pCh[1];
			break;
		case 18:	//带时标的报文	
			AnalyzeDPIwiTime(pCh, gid.dpiwitime);
			break;
		case 19:	//带相对时间的时标报文	
			AnalyzeDPIwiRET(pCh, gid.dpiwiret);
			break;
		case 20:	//带相对时间的时标的被测值	
			AnalyzeVALwiRET(pCh, gid.valwiret);
			break;
		case 21:	//外部文本序号	

			break;
		case 22:	//通用分类回答码	
			AnalyzeGRC(pCh, gid.grc);
			break;
		case 23:	//数据结构	
			//AnalyzeGDDaGID(pCh, gddagid);
			break;
		case 24:	//索引	

			break;

		default:
			break;





		}
		

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeGID

int CCommon103Analyzer::AnalyzeASCII(unsigned char* chMsg, unsigned int& ASCII)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		ASCII = pCh[0];

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeASCII

int CCommon103Analyzer::AnalyzeUnnValue(unsigned char* chMsg, unsigned int& size, unsigned int& UnnValue)
{
	if (NULL == chMsg || size > 4)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		UnnValue = 0;
		unsigned int i = 0;
		for (i =0 ;i < size; i++)
		{
			UnnValue |= (pCh[i] << 8 * i);
		}
		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeUnnValue

int CCommon103Analyzer::AnalyzenValue(unsigned char* chMsg, unsigned int& size, int& nValue)
{
	if (NULL == chMsg || size > 4)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		nValue = 0;
		unsigned int i = 0;

		unsigned int nsign = (0x80 == (pCh[size - 1] & 0x80)) ? 1 : 0;
		if (nsign == 0)
		{
			for (i =0 ;i < size; i++)
			{
				nValue |= (pCh[i] << 8 * i);
			}

		} 
		else
		{
			if (size < 4)
			{
				for (i =0 ;i < size; i++)
				{
					nValue |= (pCh[i] << 8 * i);
				}
				switch (size)
				{
				case 1:
					nValue = (-1.0) * ((int)((~nValue) & 0x000000ff)+ 0x01);
					break;
				case 2:
					nValue = (-1.0) * ((int)((~nValue) & 0x0000ffff)+ 0x01);
					break;
				case 3:
					nValue = (-1.0) * ((int)((~nValue) & 0x00ffffff)+ 0x01);
					break;
				default:break;
				}
				
			} 
			else
			{
				for (i =0 ;i < size; i++)
				{
					nValue |= (pCh[i] << 8 * i);
				}
			}
		}

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzenValue

int CCommon103Analyzer::AnalyzeUnfValue(unsigned char* chMsg, unsigned int& size, double& UnfValue)
{
	if (NULL == chMsg || size != 4)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		UnfValue = 0.0;

		unsigned int nValue =0;
		unsigned int i = 0;
		float temp = 0.0;
		float x = 0.0;
		int j = 0;
		unsigned int nsign = (0x80 == (pCh[size - 1] & 0x80)) ? 1 : 0;
		if (nsign == 0)
		{
			for (i =0 ;i < size; i++)
			{
				nValue |= (pCh[i] << 8 * i);
			}
			memcpy(&x, &nValue, 4);
			UnfValue = (double)x;
			return 1;
		} 
		else
		{
			nValue = pCh[0] | (pCh[1] << 8) | (pCh[2] << 16) | (pCh[3] << 24);
			temp = (nValue & 0x007fffff) * 1.0 / 0x800000;
			j = ((nValue & 0xff800000) >> 23) - 127;
			UnfValue = pow(2.0 , j);
			UnfValue = (1 + temp) * UnfValue; 
			
			return 1;
		}

		
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzeUnfValue

int CCommon103Analyzer::AnalyzefValue(unsigned char* chMsg, unsigned int& size, float& fValue)
{
	if (NULL == chMsg || size != 4)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		unsigned int nValue =0;
		unsigned int i = 0;
		fValue = 0.0;
		for (i =0 ;i < size; i++)
		{
			nValue |= (pCh[i] << 8 * i);
		}
		memcpy(&fValue, &nValue, 4);

		return 1;
	}
	catch (...)
	{
		return -1;
	}
}//AnalyzefValue

int CCommon103Analyzer::AnalyzeIEEER64(unsigned char* chMsg, double& R64)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		memcpy(&R64, pCh, 8);
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeIEEE754R64

int CCommon103Analyzer::AnalyzeSPI(unsigned char* chMsg, SPI& spi)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		spi.nSpi = pCh[0] & 0x01;
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeSPI

int CCommon103Analyzer::AnalyzenTEDPI(unsigned char* chMsg, unsigned int& nTEDPI)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		nTEDPI = pCh[0] & 0x03;
		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzenTEDPI

int CCommon103Analyzer::AnalyzeDPIwiTime(unsigned char* chMsg, DPIwiTime& dpiwitime)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		dpiwitime.dpi.nDpi = pCh[0] & 0x03;
		pCh += 1;

		int n4ByteTime = AnalyzeCP32Time2a(pCh, m_chTimeBuf);
		memmove(dpiwitime.ch4ByteTime, m_chTimeBuf, sizeof(dpiwitime.ch4ByteTime));
		pCh += 4;

		dpiwitime.sin.nSIN = pCh[0];

		pCh -= 5;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeDPIwiTime

int CCommon103Analyzer::AnalyzeDPIwiRET(unsigned char* chMsg, DPIwiRET& dpiwiret)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;
		dpiwiret.dpi.nDpi = pCh[0] & 0x03;
		pCh += 1;

		AnalyzeRET(pCh, dpiwiret.ret);
		pCh += 2;

		AnalyzeFAN(pCh, dpiwiret.fan);
		pCh += 2;

		int n4ByteTime = AnalyzeCP32Time2a(pCh, m_chTimeBuf);
		memmove(dpiwiret.ch4ByteTime, m_chTimeBuf, sizeof(dpiwiret.ch4ByteTime));
		pCh += 4;

		dpiwiret.sin.nSIN = pCh[0];

		pCh -= 9;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeDPIwiRET

int CCommon103Analyzer::AnalyzeVALwiRET(unsigned char* chMsg, VALwiRET& valwiret)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		AnalyzeIEEE754(pCh, valwiret.R32);
		pCh += 4;

		AnalyzeRET(pCh, valwiret.ret);
		pCh += 2;

		AnalyzeFAN(pCh, valwiret.fan);
		pCh += 2;

		int n4ByteTime = AnalyzeCP32Time2a(pCh, m_chTimeBuf);
		memmove(valwiret.ch4ByteTime, m_chTimeBuf, sizeof(valwiret.ch4ByteTime));

		pCh -= 8;

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeVALwiRET

int CCommon103Analyzer::AnalyzeGRC(unsigned char* chMsg, GRC& grc)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		grc.nGrc = pCh[0];

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}//AnalyzeGRC

/*int CCommon103Analyzer::AnalyzeGDDaGID(unsigned char* chMsg, GDDaGID& gddagid)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		AnalyzeGDD(pCh, gddagid.gdd);
		pCh +=3;

		AnalyzeGID(pCh, gddagid.gdd.nType, gddagid.gdd.nSize, gddagid.gid);

		return 1;
	}
	catch ( ... )
	{
		return -1;
	}
}*///AnalyzeGRC

int CCommon103Analyzer::AnalyzeBSI(unsigned char* chMsg, BSI_103& bsi)
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

int CCommon103Analyzer::AnalyzeNDE(unsigned char* chMsg, NDE& nde)
{
	if (NULL == chMsg)
	{
		return -1;
	}

	try
	{
		unsigned char* pCh = chMsg;

		nde.nNO = pCh[0] &0x3f;
		nde.nCONT = (0x80 == (pCh[0] & 0x80)) ? 1 : 0;

		return 1;
	}
	catch (...)
	{
		return -1;
	}

}//AnalyzeNDE
