#include "CDataDisplay101.h"

CDataDisplay101::CDataDisplay101(QWidget *parent) : QMainWindow(parent)
{
    InitDisplayFunctionMap();
}


int CDataDisplay101::displayData(const int nAsduType, CC101Or104Data &c101Or104Data, QString &strData)
{

    QMap<int, pFun>::iterator itor = m_map_display_function.find(nAsduType);

    if(itor == m_map_display_function.end())
    {
        QMessageBox::warning(this, "Display Error", "Can\'t find display function!");
        return -1;
    }
    else if (NULL == itor.value())
    {
         QMessageBox::warning(this, "Display Error", "The address of display function is NULL!");
        return -1;
    }
    else
    {
        return (this->*(itor.value()))(c101Or104Data, strData);
    }
}//displayData

int CDataDisplay101::InitDisplayFunctionMap()
{

    m_map_display_function[1] = &CDataDisplay101::DisplayAsdu1;
    m_map_display_function[2] = &CDataDisplay101::DisplayAsdu2;
    m_map_display_function[3] = &CDataDisplay101::DisplayAsdu3;
    m_map_display_function[4] = &CDataDisplay101::DisplayAsdu4;
    m_map_display_function[5] = &CDataDisplay101::DisplayAsdu5;
    m_map_display_function[6] = &CDataDisplay101::DisplayAsdu6;
    m_map_display_function[7] = &CDataDisplay101::DisplayAsdu7;
    m_map_display_function[8] = &CDataDisplay101::DisplayAsdu8;
    m_map_display_function[9] = &CDataDisplay101::DisplayAsdu9;
    m_map_display_function[10] = &CDataDisplay101::DisplayAsdu10;
    m_map_display_function[11] = &CDataDisplay101::DisplayAsdu11;
    m_map_display_function[12] = &CDataDisplay101::DisplayAsdu12;
    m_map_display_function[13] = &CDataDisplay101::DisplayAsdu13;
    m_map_display_function[14] = &CDataDisplay101::DisplayAsdu14;
    m_map_display_function[15] = &CDataDisplay101::DisplayAsdu15;
    m_map_display_function[16] = &CDataDisplay101::DisplayAsdu16;
    m_map_display_function[17] = &CDataDisplay101::DisplayAsdu17;
    m_map_display_function[18] = &CDataDisplay101::DisplayAsdu18;
    m_map_display_function[19] = &CDataDisplay101::DisplayAsdu19;
    m_map_display_function[20] = &CDataDisplay101::DisplayAsdu20;
    m_map_display_function[21] = &CDataDisplay101::DisplayAsdu21;

    m_map_display_function[30] = &CDataDisplay101::DisplayAsdu30;
    m_map_display_function[31] = &CDataDisplay101::DisplayAsdu31;
    m_map_display_function[32] = &CDataDisplay101::DisplayAsdu32;
    m_map_display_function[33] = &CDataDisplay101::DisplayAsdu33;
    m_map_display_function[34] = &CDataDisplay101::DisplayAsdu34;
    m_map_display_function[35] = &CDataDisplay101::DisplayAsdu35;
    m_map_display_function[36] = &CDataDisplay101::DisplayAsdu36;
    m_map_display_function[37] = &CDataDisplay101::DisplayAsdu37;
    m_map_display_function[38] = &CDataDisplay101::DisplayAsdu38;
    m_map_display_function[39] = &CDataDisplay101::DisplayAsdu39;
    m_map_display_function[40] = &CDataDisplay101::DisplayAsdu40;

    m_map_display_function[70] = &CDataDisplay101::DisplayAsdu70;


    return 1;
}//InitDisplayFunctionMap

int CDataDisplay101::DisplayAsdu1(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu1 asdu1;

        if(c101Or104Data.vec_Asdu1.size() > 0)
        {
            asdu1 = c101Or104Data.vec_Asdu1[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu1.dui.nType, asdu1.dui.vsq.nContinuous, asdu1.dui.vsq.nVsq, asdu1.dui.nCot, asdu1.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu1.size(); i++)
        {
           asdu1 = c101Or104Data.vec_Asdu1[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n", asdu1.nInfoAddr);
           strData += m_strTmp;

           //带品质描述词的单点信息
           m_strTmp.sprintf("带品质描述词的单点信息(有效位 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 保留位 = %d 单点信息0-开,1-合 = %d)\n", \
                          asdu1.siq.nIV, asdu1.siq.nNT, asdu1.siq.nSB, asdu1.siq.nBL, asdu1.siq.nRES, asdu1.siq.nSPI);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu1

int CDataDisplay101::DisplayAsdu2(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu2 asdu2;

        if(c101Or104Data.vec_Asdu2.size() > 0)
        {
            asdu2 = c101Or104Data.vec_Asdu2[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu2.dui.nType, asdu2.dui.vsq.nContinuous, asdu2.dui.vsq.nVsq, asdu2.dui.nCot, asdu2.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu2.size(); i++)
        {
           asdu2 = c101Or104Data.vec_Asdu2[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n", asdu2.nInfoAddr);
           strData += m_strTmp;

           //带品质描述词的单点信息
           m_strTmp.sprintf("带品质描述词的单点信息(有效位 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 保留位 = %d 单点信息0-开,1-合 = %d)\n", \
                          asdu2.siq.nIV, asdu2.siq.nNT, asdu2.siq.nSB, asdu2.siq.nBL, asdu2.siq.nRES, asdu2.siq.nSPI);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu2.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu2

int CDataDisplay101::DisplayAsdu3(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu3 asdu3;

        if(c101Or104Data.vec_Asdu3.size() > 0)
        {
            asdu3 = c101Or104Data.vec_Asdu3[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu3.dui.nType, asdu3.dui.vsq.nContinuous, asdu3.dui.vsq.nVsq, asdu3.dui.nCot,asdu3.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu3.size(); i++)
        {
           asdu3 = c101Or104Data.vec_Asdu3[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n", asdu3.nInfoAddr);
           strData += m_strTmp;

           //带品质描述词的双点信息
           m_strTmp.sprintf("带品质描述词的双点信息(有效位 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 保留位 = %d 单点信息1-开,2-合,0/3-不确定 = %d)\n", \
                          asdu3.diq.nIV, asdu3.diq.nNT, asdu3.diq.nSB, asdu3.diq.nBL, asdu3.diq.nRES, asdu3.diq.nDPI);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu3

int CDataDisplay101::DisplayAsdu4(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu4 asdu4;

        if(c101Or104Data.vec_Asdu4.size() > 0)
        {
            asdu4 = c101Or104Data.vec_Asdu4[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu4.dui.nType, asdu4.dui.vsq.nContinuous, asdu4.dui.vsq.nVsq, asdu4.dui.nCot, asdu4.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu4.size(); i++)
        {
           asdu4 = c101Or104Data.vec_Asdu4[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n", asdu4.nInfoAddr);
           strData += m_strTmp;

           //带品质描述词的单点信息
           m_strTmp.sprintf("带品质描述词的双点信息(有效位 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 保留位 = %d 单点信息1-开,2-合,0/3-不确定 = %d)\n", \
                          asdu4.diq.nIV, asdu4.diq.nNT, asdu4.diq.nSB, asdu4.diq.nBL, asdu4.diq.nRES, asdu4.diq.nDPI);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu4.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu4

int CDataDisplay101::DisplayAsdu5(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu5 asdu5;

        if(c101Or104Data.vec_Asdu5.size() > 0)
        {
            asdu5 = c101Or104Data.vec_Asdu5[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu5.dui.nType, asdu5.dui.vsq.nContinuous, asdu5.dui.vsq.nVsq, asdu5.dui.nCot, asdu5.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu5.size(); i++)
        {
           asdu5 = c101Or104Data.vec_Asdu5[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n带瞬变状态指示的值(标志位 = %d 值 = %d)\n",\
                                          asdu5.nInfoAddr,asdu5.vti.nT, asdu5.vti.nValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu5.qds.nIV, asdu5.qds.nNT, asdu5.qds.nSB, asdu5.qds.nBL, asdu5.qds.nRES, asdu5.qds.nOV);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu5

int CDataDisplay101::DisplayAsdu6(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu6 asdu6;

        if(c101Or104Data.vec_Asdu6.size() > 0)
        {
            asdu6 = c101Or104Data.vec_Asdu6[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu6.dui.nType, asdu6.dui.vsq.nContinuous, asdu6.dui.vsq.nVsq, asdu6.dui.nCot, asdu6.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu6.size(); i++)
        {
           asdu6 = c101Or104Data.vec_Asdu6[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n带瞬变状态指示的值(标志位 = %d 值 = %d)\n",\
                                          asdu6.nInfoAddr,asdu6.vti.nT, asdu6.vti.nValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu6.qds.nIV, asdu6.qds.nNT, asdu6.qds.nSB, asdu6.qds.nBL, asdu6.qds.nRES, asdu6.qds.nOV);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu6.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu6

int CDataDisplay101::DisplayAsdu7(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu7 asdu7;

        if(c101Or104Data.vec_Asdu7.size() > 0)
        {
            asdu7 = c101Or104Data.vec_Asdu7[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu7.dui.nType, asdu7.dui.vsq.nContinuous, asdu7.dui.vsq.nVsq, asdu7.dui.nCot, asdu7.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu7.size(); i++)
        {
           asdu7 = c101Or104Data.vec_Asdu7[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nBSI = %d %d %d %d\n",\
                                          asdu7.nInfoAddr, asdu7.bsi.chBsi[0], asdu7.bsi.chBsi[1], asdu7.bsi.chBsi[2], asdu7.bsi.chBsi[3]);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu7.qds.nIV, asdu7.qds.nNT, asdu7.qds.nSB, asdu7.qds.nBL, asdu7.qds.nRES, asdu7.qds.nOV);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu7

int CDataDisplay101::DisplayAsdu8(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu8 asdu8;

        if(c101Or104Data.vec_Asdu8.size() > 0)
        {
            asdu8 = c101Or104Data.vec_Asdu8[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu8.dui.nType, asdu8.dui.vsq.nContinuous, asdu8.dui.vsq.nVsq, asdu8.dui.nCot, asdu8.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu8.size(); i++)
        {
           asdu8 = c101Or104Data.vec_Asdu8[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nBSI = %d %d %d %d\n",\
                                          asdu8.nInfoAddr, asdu8.bsi.chBsi[0], asdu8.bsi.chBsi[1], asdu8.bsi.chBsi[2], asdu8.bsi.chBsi[3]);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu8.qds.nIV, asdu8.qds.nNT, asdu8.qds.nSB, asdu8.qds.nBL, asdu8.qds.nRES, asdu8.qds.nOV);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu8.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu8

int CDataDisplay101::DisplayAsdu9(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu9 asdu9;

        if(c101Or104Data.vec_Asdu9.size() > 0)
        {
            asdu9 = c101Or104Data.vec_Asdu9[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu9.dui.nType, asdu9.dui.vsq.nContinuous, asdu9.dui.vsq.nVsq, asdu9.dui.nCot, asdu9.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu9.size(); i++)
        {
           asdu9 = c101Or104Data.vec_Asdu9[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n归一化值 = %f\n",\
                                          asdu9.nInfoAddr, asdu9.fValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu9.qds.nIV, asdu9.qds.nNT, asdu9.qds.nSB, asdu9.qds.nBL, asdu9.qds.nRES, asdu9.qds.nOV);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu9

int CDataDisplay101::DisplayAsdu10(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu10 asdu10;

        if(c101Or104Data.vec_Asdu10.size() > 0)
        {
            asdu10 = c101Or104Data.vec_Asdu10[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu10.dui.nType, asdu10.dui.vsq.nContinuous, asdu10.dui.vsq.nVsq, asdu10.dui.nCot, asdu10.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu10.size(); i++)
        {
           asdu10 = c101Or104Data.vec_Asdu10[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n归一化值 = %f\n",\
                                          asdu10.nInfoAddr, asdu10.fValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu10.qds.nIV, asdu10.qds.nNT, asdu10.qds.nSB, asdu10.qds.nBL, asdu10.qds.nRES, asdu10.qds.nOV);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu10.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu10

int CDataDisplay101::DisplayAsdu11(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu11 asdu11;

        if(c101Or104Data.vec_Asdu11.size() > 0)
        {
            asdu11 = c101Or104Data.vec_Asdu11[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu11.dui.nType, asdu11.dui.vsq.nContinuous, asdu11.dui.vsq.nVsq, asdu11.dui.nCot, asdu11.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu11.size(); i++)
        {
           asdu11 = c101Or104Data.vec_Asdu11[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n标度化值 = %d\n",\
                                          asdu11.nInfoAddr, asdu11.nValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu11.qds.nIV, asdu11.qds.nNT, asdu11.qds.nSB, asdu11.qds.nBL, asdu11.qds.nRES, asdu11.qds.nOV);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu11

int CDataDisplay101::DisplayAsdu12(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu12 asdu12;

        if(c101Or104Data.vec_Asdu12.size() > 0)
        {
            asdu12 = c101Or104Data.vec_Asdu12[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu12.dui.nType, asdu12.dui.vsq.nContinuous, asdu12.dui.vsq.nVsq, asdu12.dui.nCot, asdu12.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu12.size(); i++)
        {
           asdu12 = c101Or104Data.vec_Asdu12[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n标度化值 = %d\n",\
                                          asdu12.nInfoAddr, asdu12.nValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu12.qds.nIV, asdu12.qds.nNT, asdu12.qds.nSB, asdu12.qds.nBL, asdu12.qds.nRES, asdu12.qds.nOV);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu12.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu12

int CDataDisplay101::DisplayAsdu13(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu13 asdu13;

        if(c101Or104Data.vec_Asdu13.size() > 0)
        {
            asdu13 = c101Or104Data.vec_Asdu13[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu13.dui.nType, asdu13.dui.vsq.nContinuous, asdu13.dui.vsq.nVsq, asdu13.dui.nCot, asdu13.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu13.size(); i++)
        {
           asdu13 = c101Or104Data.vec_Asdu13[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n浮点值 = %f\n",\
                                          asdu13.nInfoAddr, asdu13.fValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu13.qds.nIV, asdu13.qds.nNT, asdu13.qds.nSB, asdu13.qds.nBL, asdu13.qds.nRES, asdu13.qds.nOV);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu13

int CDataDisplay101::DisplayAsdu14(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu14 asdu14;

        if(c101Or104Data.vec_Asdu14.size() > 0)
        {
            asdu14 = c101Or104Data.vec_Asdu14[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu14.dui.nType, asdu14.dui.vsq.nContinuous, asdu14.dui.vsq.nVsq, asdu14.dui.nCot, asdu14.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu14.size(); i++)
        {
           asdu14 = c101Or104Data.vec_Asdu14[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n浮点值 = %f\n",\
                                          asdu14.nInfoAddr, asdu14.fValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu14.qds.nIV, asdu14.qds.nNT, asdu14.qds.nSB, asdu14.qds.nBL, asdu14.qds.nRES, asdu14.qds.nOV);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu14.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu14

int CDataDisplay101::DisplayAsdu15(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu15 asdu15;

        if(c101Or104Data.vec_Asdu15.size() > 0)
        {
            asdu15 = c101Or104Data.vec_Asdu15[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu15.dui.nType, asdu15.dui.vsq.nContinuous, asdu15.dui.vsq.nVsq, asdu15.dui.nCot, asdu15.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu15.size(); i++)
        {
           asdu15 = c101Or104Data.vec_Asdu15[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n二进制计数器读数 = %d %d %d %d %d\n",\
                                          asdu15.nInfoAddr, asdu15.bcr.nValue, asdu15.bcr.IV ,asdu15.bcr.CA ,asdu15.bcr.CY, asdu15.bcr.SQ);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu15

int CDataDisplay101::DisplayAsdu16(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu16 asdu16;

        if(c101Or104Data.vec_Asdu16.size() > 0)
        {
            asdu16 = c101Or104Data.vec_Asdu16[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu16.dui.nType, asdu16.dui.vsq.nContinuous, asdu16.dui.vsq.nVsq, asdu16.dui.nCot, asdu16.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu16.size(); i++)
        {
           asdu16 = c101Or104Data.vec_Asdu16[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n二进制计数器读数 = %d %d %d %d %d\n",\
                                          asdu16.nInfoAddr, asdu16.bcr.nValue, asdu16.bcr.IV ,asdu16.bcr.CA ,asdu16.bcr.CY, asdu16.bcr.SQ);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu16.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu16

int CDataDisplay101::DisplayAsdu17(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu17 asdu17;

        if(c101Or104Data.vec_Asdu17.size() > 0)
        {
            asdu17 = c101Or104Data.vec_Asdu17[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu17.dui.nType, asdu17.dui.vsq.nContinuous, asdu17.dui.vsq.nVsq, asdu17.dui.nCot, asdu17.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu17.size(); i++)
        {
           asdu17 = c101Or104Data.vec_Asdu17[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n",\
                                          asdu17.nInfoAddr);
           strData += m_strTmp;

           //继电保护设备的单个事件
           m_strTmp.sprintf("继电保护设备的单个事件(是否有效 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 动作时间是否有效 = %d 保留位 = %d 事件状态 = %d) \n", \
                          asdu17.sep.nIV, asdu17.sep.nNT, asdu17.sep.nSB, asdu17.sep.nBL, asdu17.sep.nEI, asdu17.sep.nRES, asdu17.sep.nES);
           strData += m_strTmp;

           //2字节时间
           m_strTmp.sprintf("两字节时间(动作时间) = %s\n", asdu17.ch2ByteTime);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu17.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu17

int CDataDisplay101::DisplayAsdu18(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu18 asdu18;

        if(c101Or104Data.vec_Asdu18.size() > 0)
        {
            asdu18 = c101Or104Data.vec_Asdu18[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu18.dui.nType, asdu18.dui.vsq.nContinuous, asdu18.dui.vsq.nVsq, asdu18.dui.nCot, asdu18.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu18.size(); i++)
        {
           asdu18 = c101Or104Data.vec_Asdu18[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nSPE.RES = %d SPE.SRD = %d SPE.SIE = %d SPE.SL3 = %d SPE.SL2 = %d SPE.SL1 = %d SPE.GS = %d ", \
                                          asdu18.nInfoAddr, asdu18.spe.nRES, asdu18.spe.nSRD, asdu18.spe.nSIE, asdu18.spe.nSL3, asdu18.spe.nSL2, asdu18.spe.nSL1, asdu18.spe.nGS);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 动作时间是否有效 = %d 保留位 = %d) \n", \
                          asdu18.qdp.nIV, asdu18.qdp.nNT, asdu18.qdp.nSB, asdu18.qdp.nBL, asdu18.qdp.nEI, asdu18.qdp.nRES);
           strData += m_strTmp;

           //2字节时间
           m_strTmp.sprintf("两字节时间(动作时间) = %s\n", asdu18.ch2ByteTime);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu18.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu18

int CDataDisplay101::DisplayAsdu19(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu19 asdu19;

        if(c101Or104Data.vec_Asdu19.size() > 0)
        {
            asdu19 = c101Or104Data.vec_Asdu19[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu19.dui.nType, asdu19.dui.vsq.nContinuous, asdu19.dui.vsq.nVsq, asdu19.dui.nCot, asdu19.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu19.size(); i++)
        {
           asdu19 = c101Or104Data.vec_Asdu19[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nOCI.RES = %d OCI.CL3 = %d OCI.SIE = %d OCI.CL2 = %d OCI.CL1 = %d OCI.GC = %d", \
                                          asdu19.nInfoAddr, asdu19.oci.nRES, asdu19.oci.nCL3, asdu19.oci.nCL2, asdu19.oci.nCL1, asdu19.oci.nGC);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 动作时间是否有效 = %d 保留位 = %d) \n", \
                          asdu19.qdp.nIV, asdu19.qdp.nNT, asdu19.qdp.nSB, asdu19.qdp.nBL, asdu19.qdp.nEI, asdu19.qdp.nRES);
           strData += m_strTmp;

           //2字节时间
           m_strTmp.sprintf("两字节时间(动作时间) = %s\n", asdu19.ch2ByteTime);
           strData += m_strTmp;

           //3字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu19.ch3ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu19

int CDataDisplay101::DisplayAsdu20(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu20 asdu20;

        if(c101Or104Data.vec_Asdu20.size() > 0)
        {
            asdu20 = c101Or104Data.vec_Asdu20[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu20.dui.nType, asdu20.dui.vsq.nContinuous, asdu20.dui.vsq.nVsq, asdu20.dui.nCot, asdu20.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu20.size(); i++)
        {
           asdu20 = c101Or104Data.vec_Asdu20[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nSCD = d% d% d% d%", \
                                          asdu20.nInfoAddr, asdu20.scd.chScd[0], asdu20.scd.chScd[1], asdu20.scd.chScd[2], asdu20.scd.chScd[3]);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu20.qds.nIV, asdu20.qds.nNT, asdu20.qds.nSB, asdu20.qds.nBL, asdu20.qds.nRES, asdu20.qds.nOV);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu20

int CDataDisplay101::DisplayAsdu21(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu21 asdu21;

        if(c101Or104Data.vec_Asdu21.size() > 0)
        {
            asdu21 = c101Or104Data.vec_Asdu21[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu21.dui.nType, asdu21.dui.vsq.nContinuous, asdu21.dui.vsq.nVsq, asdu21.dui.nCot, asdu21.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu21.size(); i++)
        {
           asdu21 = c101Or104Data.vec_Asdu21[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nNVA=%f", \
                                          asdu21.nInfoAddr, asdu21.fValue);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu21

int CDataDisplay101::DisplayAsdu30(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu30 asdu30;

        if(c101Or104Data.vec_Asdu30.size() > 0)
        {
            asdu30 = c101Or104Data.vec_Asdu30[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu30.dui.nType, asdu30.dui.vsq.nContinuous, asdu30.dui.vsq.nVsq, asdu30.dui.nCot, asdu30.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu30.size(); i++)
        {
           asdu30 = c101Or104Data.vec_Asdu30[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n", \
                                          asdu30.nInfoAddr);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("带品质描述词的单点信息(有效位 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 保留位 = %d 单点信息0-开,1-合 = %d)\n", \
                          asdu30.siq.nIV, asdu30.siq.nNT, asdu30.siq.nSB, asdu30.siq.nBL, asdu30.siq.nRES, asdu30.siq.nSPI);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu30.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu30

int CDataDisplay101::DisplayAsdu31(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu31 asdu31;

        if(c101Or104Data.vec_Asdu31.size() > 0)
        {
            asdu31 = c101Or104Data.vec_Asdu31[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu31.dui.nType, asdu31.dui.vsq.nContinuous, asdu31.dui.vsq.nVsq, asdu31.dui.nCot, asdu31.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu31.size(); i++)
        {
           asdu31 = c101Or104Data.vec_Asdu31[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n", \
                                          asdu31.nInfoAddr);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("带品质描述词的双点信息(是否有效 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 双点信息1-开 2-合 0/3-不确定 = %d) \n", \
                          asdu31.diq.nIV, asdu31.diq.nNT, asdu31.diq.nSB, asdu31.diq.nBL, asdu31.diq.nRES, asdu31.diq.nDPI);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu31.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu31

int CDataDisplay101::DisplayAsdu32(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu32 asdu32;

        if(c101Or104Data.vec_Asdu32.size() > 0)
        {
            asdu32 = c101Or104Data.vec_Asdu32[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu32.dui.nType, asdu32.dui.vsq.nContinuous, asdu32.dui.vsq.nVsq, asdu32.dui.nCot, asdu32.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu32.size(); i++)
        {
           asdu32 = c101Or104Data.vec_Asdu32[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nVTI.T = d% VTI.Value = d%", \
                                          asdu32.nInfoAddr, asdu32.vti.nT, asdu32.vti.nValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu32.qds.nIV, asdu32.qds.nNT, asdu32.qds.nSB, asdu32.qds.nBL, asdu32.qds.nRES, asdu32.qds.nOV);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu32.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu32

int CDataDisplay101::DisplayAsdu33(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu33 asdu33;

        if(c101Or104Data.vec_Asdu33.size() > 0)
        {
            asdu33 = c101Or104Data.vec_Asdu33[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu33.dui.nType, asdu33.dui.vsq.nContinuous, asdu33.dui.vsq.nVsq, asdu33.dui.nCot, asdu33.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu33.size(); i++)
        {
           asdu33 = c101Or104Data.vec_Asdu33[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nBSI = %d %d %d %d\n",\
                                          asdu33.nInfoAddr, asdu33.bsi.chBsi[0], asdu33.bsi.chBsi[1], asdu33.bsi.chBsi[2], asdu33.bsi.chBsi[3]);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu33.qds.nIV, asdu33.qds.nNT, asdu33.qds.nSB, asdu33.qds.nBL, asdu33.qds.nRES, asdu33.qds.nOV);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu33.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu33

int CDataDisplay101::DisplayAsdu34(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu34 asdu34;

        if(c101Or104Data.vec_Asdu34.size() > 0)
        {
            asdu34 = c101Or104Data.vec_Asdu34[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu34.dui.nType, asdu34.dui.vsq.nContinuous, asdu34.dui.vsq.nVsq, asdu34.dui.nCot, asdu34.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu34.size(); i++)
        {
           asdu34 = c101Or104Data.vec_Asdu34[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n归一化值 = %f\n",\
                                          asdu34.nInfoAddr, asdu34.fValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu34.qds.nIV, asdu34.qds.nNT, asdu34.qds.nSB, asdu34.qds.nBL, asdu34.qds.nRES, asdu34.qds.nOV);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu34.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu34

int CDataDisplay101::DisplayAsdu35(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu35 asdu35;

        if(c101Or104Data.vec_Asdu35.size() > 0)
        {
            asdu35 = c101Or104Data.vec_Asdu35[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu35.dui.nType, asdu35.dui.vsq.nContinuous, asdu35.dui.vsq.nVsq, asdu35.dui.nCot, asdu35.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu35.size(); i++)
        {
           asdu35 = c101Or104Data.vec_Asdu35[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n标度化值 = %d\n",\
                                          asdu35.nInfoAddr, asdu35.nValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu35.qds.nIV, asdu35.qds.nNT, asdu35.qds.nSB, asdu35.qds.nBL, asdu35.qds.nRES, asdu35.qds.nOV);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu35.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu35

int CDataDisplay101::DisplayAsdu36(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu36 asdu36;

        if(c101Or104Data.vec_Asdu36.size() > 0)
        {
            asdu36 = c101Or104Data.vec_Asdu36[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu36.dui.nType, asdu36.dui.vsq.nContinuous, asdu36.dui.vsq.nVsq, asdu36.dui.nCot, asdu36.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu36.size(); i++)
        {
           asdu36 = c101Or104Data.vec_Asdu36[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n浮点值 = %f\n",\
                                          asdu36.nInfoAddr, asdu36.fValue);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 =%d 是否前值 = %d 是否取代 =%d 是否闭锁 = %d 保留位 = %d 是否溢出 = %d)\n", \
                          asdu36.qds.nIV, asdu36.qds.nNT, asdu36.qds.nSB, asdu36.qds.nBL, asdu36.qds.nRES, asdu36.qds.nOV);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu36.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu36

int CDataDisplay101::DisplayAsdu37(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu37 asdu37;

        if(c101Or104Data.vec_Asdu37.size() > 0)
        {
            asdu37 = c101Or104Data.vec_Asdu37[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu37.dui.nType, asdu37.dui.vsq.nContinuous, asdu37.dui.vsq.nVsq, asdu37.dui.nCot, asdu37.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu37.size(); i++)
        {
           asdu37 = c101Or104Data.vec_Asdu37[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n二进制计数器读数 = %d %d %d %d %d\n",\
                                          asdu37.nInfoAddr, asdu37.bcr.nValue, asdu37.bcr.IV ,asdu37.bcr.CA ,asdu37.bcr.CY, asdu37.bcr.SQ);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("三字节时间 = %s\n", asdu37.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu37

int CDataDisplay101::DisplayAsdu38(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu38 asdu38;
        if(c101Or104Data.vec_Asdu38.size() > 0)
        {
            asdu38 = c101Or104Data.vec_Asdu38[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu38.dui.nType, asdu38.dui.vsq.nContinuous, asdu38.dui.vsq.nVsq, asdu38.dui.nCot, asdu38.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu38.size(); i++)
        {
           asdu38 = c101Or104Data.vec_Asdu38[i];

           //数据
           QString tip = tr("信息体地址 = ");
           QString tip2 = QString::fromUtf8(tip.toUtf8().data());
           m_strTmp.sprintf("%s %d\n",tip2.toUtf8().data(), asdu38.nInfoAddr);
           strData += m_strTmp;

           //继电保护设备单个事件
           m_strTmp.sprintf("继电保护设备的单个事件(是否有效 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 动作时间是否有效 = %d 保留位 = %d 事件状态 = %d) \n", \
                          asdu38.sep.nIV, asdu38.sep.nNT, asdu38.sep.nSB, asdu38.sep.nBL, asdu38.sep.nEI, asdu38.sep.nRES, asdu38.sep.nES);
           strData += m_strTmp;

           //2字节时间
           m_strTmp.sprintf("两字节时间(动作时间) = %s\n", asdu38.ch2ByteTime);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu38.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }


        return 1;
    }
    catch (...)
    {
        return -1;
    }
}//DisplayAsdu38

int CDataDisplay101::DisplayAsdu39(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu39 asdu39;

        if(c101Or104Data.vec_Asdu39.size() > 0)
        {
            asdu39 = c101Or104Data.vec_Asdu39[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu39.dui.nType, asdu39.dui.vsq.nContinuous, asdu39.dui.vsq.nVsq, asdu39.dui.nCot, asdu39.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu39.size(); i++)
        {
           asdu39 = c101Or104Data.vec_Asdu39[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nSPE.RES = %d SPE.SRD = %d SPE.SIE = %d SPE.SL3 = %d SPE.SL2 = %d SPE.SL1 = %d SPE.GS = %d ", \
                                          asdu39.nInfoAddr, asdu39.spe.nRES, asdu39.spe.nSRD, asdu39.spe.nSIE, asdu39.spe.nSL3, asdu39.spe.nSL2, asdu39.spe.nSL1, asdu39.spe.nGS);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 动作时间是否有效 = %d 保留位 = %d) \n", \
                          asdu39.qdp.nIV, asdu39.qdp.nNT, asdu39.qdp.nSB, asdu39.qdp.nBL, asdu39.qdp.nEI, asdu39.qdp.nRES);
           strData += m_strTmp;

           //2字节时间
           m_strTmp.sprintf("两字节时间(动作时间) = %s\n", asdu39.ch2ByteTime);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu39.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu39

int CDataDisplay101::DisplayAsdu40(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu40 asdu40;

        if(c101Or104Data.vec_Asdu40.size() > 0)
        {
            asdu40 = c101Or104Data.vec_Asdu40[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu40.dui.nType, asdu40.dui.vsq.nContinuous, asdu40.dui.vsq.nVsq, asdu40.dui.nCot, asdu40.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu40.size(); i++)
        {
           asdu40 = c101Or104Data.vec_Asdu40[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\nOCI.RES = %d OCI.CL3 = %d OCI.SIE = %d OCI.CL2 = %d OCI.CL1 = %d OCI.GC = %d", \
                                          asdu40.nInfoAddr, asdu40.oci.nRES, asdu40.oci.nCL3, asdu40.oci.nCL2, asdu40.oci.nCL1, asdu40.oci.nGC);
           strData += m_strTmp;

           //品质因数
           m_strTmp.sprintf("品质描述词(是否有效 = %d 是否当前值 = %d 是否取代 = %d 是否闭锁 = %d 动作时间是否有效 = %d 保留位 = %d) \n", \
                          asdu40.qdp.nIV, asdu40.qdp.nNT, asdu40.qdp.nSB, asdu40.qdp.nBL, asdu40.qdp.nEI, asdu40.qdp.nRES);
           strData += m_strTmp;

           //2字节时间
           m_strTmp.sprintf("两字节时间(动作时间) = %s\n", asdu40.ch2ByteTime);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu40.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu40

int CDataDisplay101::DisplayAsdu70(CC101Or104Data &c101Or104Data, QString &strData)
{
    try
    {
        Asdu70 asdu70;

        if(c101Or104Data.vec_Asdu70.size() > 0)
        {
            asdu70 = c101Or104Data.vec_Asdu70[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu70.dui.nType, asdu70.dui.vsq.nContinuous, asdu70.dui.vsq.nVsq, asdu70.dui.nCot, asdu70.dui.nCommonAddr);
            strData += m_strTmp;

            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c101Or104Data.vec_Asdu70.size(); i++)
        {
           asdu70 = c101Or104Data.vec_Asdu70[i];

           //数据
           m_strTmp.sprintf("信息体地址 = %d\n初始化原因(本地参数 = %d 原因 = %d)", \
                                          asdu70.nInfoAddr, asdu70.coi.nLocalParam, asdu70.coi.nCoiReason);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch (...)
    {
        return -1;
    }

    return 1;
}//DisplayAsdu70
