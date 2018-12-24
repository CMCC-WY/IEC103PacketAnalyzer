#include "cdatadisplay103.h"

CDataDisplay103::CDataDisplay103(QWidget *parent) : QMainWindow(parent)
{
    InitDisplayFunctionMap();
}


int CDataDisplay103::displayData(const int nAsduType, CC103Data &c103Data, QString &strData)
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
        return (this->*(itor.value()))(c103Data, strData);
    }
}//displayData

int CDataDisplay103::InitDisplayFunctionMap()
{

    m_map_display_function[1] = &CDataDisplay103::DisplayAsdu1;
    m_map_display_function[2] = &CDataDisplay103::DisplayAsdu2;
    m_map_display_function[3] = &CDataDisplay103::DisplayAsdu3;
    m_map_display_function[4] = &CDataDisplay103::DisplayAsdu4;
    m_map_display_function[5] = &CDataDisplay103::DisplayAsdu5;
    m_map_display_function[6] = &CDataDisplay103::DisplayAsdu6;

    m_map_display_function[8] = &CDataDisplay103::DisplayAsdu8;
    m_map_display_function[9] = &CDataDisplay103::DisplayAsdu9;
    m_map_display_function[10] = &CDataDisplay103::DisplayAsdu10;
    m_map_display_function[11] = &CDataDisplay103::DisplayAsdu11;

    m_map_display_function[23] = &CDataDisplay103::DisplayAsdu23;
    m_map_display_function[26] = &CDataDisplay103::DisplayAsdu26;
    m_map_display_function[27] = &CDataDisplay103::DisplayAsdu27;
    m_map_display_function[28] = &CDataDisplay103::DisplayAsdu28;
    m_map_display_function[29] = &CDataDisplay103::DisplayAsdu29;
    m_map_display_function[30] = &CDataDisplay103::DisplayAsdu30;
    m_map_display_function[31] = &CDataDisplay103::DisplayAsdu31;


    return 1;
}//InitDisplayFunctionMap

int CDataDisplay103::DisplayAsdu1(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_1 asdu1;

        if(c103Data.vec_Asdu103_1.size() > 0)
        {
            asdu1 = c103Data.vec_Asdu103_1[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu1.dui.nType, asdu1.dui.vsq.nContinuous, asdu1.dui.vsq.nVsq, asdu1.dui.nCot, asdu1.dui.nCommonAddr );
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c103Data.vec_Asdu103_1.size(); i++)
        {
           asdu1 = c103Data.vec_Asdu103_1[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu1.nFUN, asdu1.nINF);
           strData += m_strTmp;

           //双点信息
           m_strTmp.sprintf("双点信息(1-开,2-合,0/3-未用) = %d\n", \
                          asdu1.dpi.nDpi);
           strData += m_strTmp;

           //4字节时间
           m_strTmp.sprintf("四字节时间 = %s\n", asdu1.ch4ByteTime);
           strData += m_strTmp;

           //附加信息
           m_strTmp.sprintf("附加信息 = %d\n", asdu1.stru_sin.nSIN);
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

int CDataDisplay103::DisplayAsdu2(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_2 asdu2;

        if(c103Data.vec_Asdu103_2.size() > 0)
        {
            asdu2 = c103Data.vec_Asdu103_2[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_2.size(); i++)
        {
           asdu2 = c103Data.vec_Asdu103_2[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu2.nFUN, asdu2.nINF);
           strData += m_strTmp;

           //双点信息、相对时间和故障序号
           m_strTmp.sprintf("双点信息(1-开,2-合,0/3-未用) = %d\n相对时间 = %d\n故障序号 = %d\n", \
                          asdu2.dpi.nDpi, asdu2.ret.nRET, asdu2.fan.nFAN);
           strData += m_strTmp;

           //4字节时间
           m_strTmp.sprintf("四字节时间 = %s\n", asdu2.ch4ByteTime);
           strData += m_strTmp;

           //附加信息
           m_strTmp.sprintf("附加信息 = %d\n", asdu2.stru_sin.nSIN);
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

int CDataDisplay103::DisplayAsdu3(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_3 asdu3;

        if(c103Data.vec_Asdu103_3.size() > 0)
        {
            asdu3 = c103Data.vec_Asdu103_3[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu3.dui.nType, asdu3.dui.vsq.nContinuous, asdu3.dui.vsq.nVsq, asdu3.dui.nCot, asdu3.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c103Data.vec_Asdu103_3.size(); i++)
        {
           asdu3 = c103Data.vec_Asdu103_3[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu3.nFUN, asdu3.nINF);
           strData += m_strTmp;

           //被测值
           MEA tempMEA;
           for(int i = 0; i < (int)asdu3.vec_meaValue.size(); i++)
           {
               tempMEA = asdu3.vec_meaValue[i];
               switch(i)
               {
               case 0:
               {
                 m_strTmp.sprintf("B相电流(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                          tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 1:
               {
                 m_strTmp.sprintf("AB线电压(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                        tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 2:
               {
                 m_strTmp.sprintf("有功功率(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                      tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;

               case 3:
               {
                 m_strTmp.sprintf("无功功率(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                      tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               default: break;
               }

           }

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu3

int CDataDisplay103::DisplayAsdu4(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_4 asdu4;

        if(c103Data.vec_Asdu103_4.size() > 0)
        {
            asdu4 = c103Data.vec_Asdu103_4[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_4.size(); i++)
        {
           asdu4 = c103Data.vec_Asdu103_4[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu4.nFUN, asdu4.nINF);
           strData += m_strTmp;

           //短路位置、相对时间和故障序号
           m_strTmp.sprintf("短路位置 = %f\n相对时间 = %d\n故障序号 = %d\n", \
                          asdu4.scl.fSCL, asdu4.ret.nRET, asdu4.fan.nFAN);
           strData += m_strTmp;

           //4字节时间
           m_strTmp.sprintf("四字节时间 = %s\n", asdu4.ch4ByteTime);
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

int CDataDisplay103::DisplayAsdu5(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_5 asdu5;

        if(c103Data.vec_Asdu103_5.size() > 0)
        {
            asdu5 = c103Data.vec_Asdu103_5[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_5.size(); i++)
        {
           asdu5 = c103Data.vec_Asdu103_5[i];

           //功能号、信息序号和兼容级别
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\nCOL = %d\n", asdu5.nFUN, asdu5.nINF, asdu5.col.nCOL);
           strData += m_strTmp;

           //ASCII字符
           /*m_strTmp.sprintf("ASCII1 = %d\nASCII2 = %d\nASCII3 = %d\nASCII4 = %d\nASCII5 = %d\nASCII6 = %d\nASCII7 = %d\nASCII8 = %d\n",
                          asdu5.ASCII1, asdu5.ASCII2, asdu5.ASCII3, asdu5.ASCII4, asdu5.ASCII5, asdu5.ASCII6, asdu5.ASCII7, asdu5.ASCII8);*/

           m_strTmp.sprintf("ASCII1 = %c%c %c%c %c%c %c%c\n", \
                          asdu5.ASCII1, asdu5.ASCII2, asdu5.ASCII3, asdu5.ASCII4, asdu5.ASCII5, asdu5.ASCII6, asdu5.ASCII7, asdu5.ASCII8);
           strData += m_strTmp;

           //自由赋值
           m_strTmp.sprintf("自由赋值1 = %d\n自由赋值2 = %d\n自由赋值3 = %d\n自由赋值4 = %d\n", \
                            asdu5.FreeValue1, asdu5.FreeValue2, asdu5.FreeValue3, asdu5.FreeValue4);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu5

int CDataDisplay103::DisplayAsdu6(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_6 asdu6;

        if(c103Data.vec_Asdu103_6.size() > 0)
        {
            asdu6 = c103Data.vec_Asdu103_6[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_6.size(); i++)
        {
           asdu6 = c103Data.vec_Asdu103_6[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu6.nFUN, asdu6.nINF);
           strData += m_strTmp;

           //7字节时间
           m_strTmp.sprintf("七字节时间 = %s\n", asdu6.ch7ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu6

int CDataDisplay103::DisplayAsdu8(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_8 asdu8;

        if(c103Data.vec_Asdu103_8.size() > 0)
        {
            asdu8 = c103Data.vec_Asdu103_8[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_8.size(); i++)
        {
           asdu8 = c103Data.vec_Asdu103_8[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu8.nFUN, asdu8.nINF);
           strData += m_strTmp;

           //扫描序号
           m_strTmp.sprintf("扫描序号 = %d\n", asdu8.scn.nSCN);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu8

int CDataDisplay103::DisplayAsdu9(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_9 asdu9;

        if(c103Data.vec_Asdu103_9.size() > 0)
        {
            asdu9 = c103Data.vec_Asdu103_9[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_9.size(); i++)
        {
           asdu9 = c103Data.vec_Asdu103_9[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu9.nFUN, asdu9.nINF);
           strData += m_strTmp;

           //被测值
           MEA tempMEA;
           for(int i = 0; i < (int)asdu9.dui.vsq.nVsq; i++)
           {
               tempMEA = asdu9.vec_meaValue[i];
               switch(i)
               {
               case 0:
               {
                 m_strTmp.sprintf("A相电流(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                          tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 1:
               {
                 m_strTmp.sprintf("B相电流(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                        tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 2:
               {
                 m_strTmp.sprintf("C相电流(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                      tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;

               case 3:
               {
                 m_strTmp.sprintf("A相电压(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                      tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 4:
               {
                 m_strTmp.sprintf("B相电压(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                          tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 5:
               {
                 m_strTmp.sprintf("C相电压(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                        tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 6:
               {
                 m_strTmp.sprintf("有功功率(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                      tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;

               case 7:
               {
                 m_strTmp.sprintf("无功功率(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                      tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;
               case 8:
               {
                 m_strTmp.sprintf("频率(溢出位 = %d 差错位 = %d 备用位 = %d 被测值 = %f)\n", \
                          tempMEA.nOV, tempMEA.nER, tempMEA.nRES, tempMEA.fMVAL);
                 strData += m_strTmp;
               }break;

               default: break;
               }

           }

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu9

int CDataDisplay103::DisplayAsdu10(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_10 asdu10;

        if(c103Data.vec_Asdu103_10.size() > 0)
        {
            asdu10 = c103Data.vec_Asdu103_10[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_10.size(); i++)
        {
           asdu10 = c103Data.vec_Asdu103_10[i];

           //功能类型、信息序号和返回信息标识符
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\nRII = %d\n\n", asdu10.nGENTYP, asdu10.nINF, asdu10.nRII);
           strData += m_strTmp;

           //通用分类数据集数目
           m_strTmp.sprintf("数目 = %d\n后续状态位 = %d\n\n", \
                            asdu10.ngd.nNo, asdu10.ngd.nCont);
           strData += m_strTmp;

           //数据集
           Asdu103_10DataSet temp;
           for(int i = 0; i < (int)asdu10.ngd.nNo; i++)
           {
               temp = asdu10.vec_Asdu103_10DataSet[i];

               //通用分类标识序号
               m_strTmp.sprintf("组号 = %d\n条目号 = %d\n\n", \
                          temp.gin.nGroup, temp.gin.nEntry);
               strData += m_strTmp;

               //描述类别
               m_strTmp.sprintf("描述类别 = %d  : ", \
                                temp.nKod);
               strData += m_strTmp;

               switch (temp.nKod)
               {
               case 0:
                   m_strTmp.sprintf("无所指定的描述类别\n\n");
                   strData += m_strTmp;
                   break;
               case 1:
                   m_strTmp.sprintf("实际值\n\n");
                   strData += m_strTmp;
                   break;
               case 2:
                   m_strTmp.sprintf("缺省值\n\n");
                   strData += m_strTmp;
                   break;
               case 3:
                   m_strTmp.sprintf("量程（最小值、最大值、步长\n\n");
                   strData += m_strTmp;
                   break;

               case 5:
                   m_strTmp.sprintf("精度（n，m\n\n");
                   strData += m_strTmp;
                   break;
               case 6:
                   m_strTmp.sprintf("因子\n\n");
                   strData += m_strTmp;
                   break;
               case 7:
                   m_strTmp.sprintf("%参比\n\n");
                   strData += m_strTmp;
                   break;
               case 8:
                   m_strTmp.sprintf("列表\n\n");
                   strData += m_strTmp;
                   break;
               case 9:
                   m_strTmp.sprintf("量纲\n\n");
                   strData += m_strTmp;
                   break;
               case 10:
                   m_strTmp.sprintf("描述\n\n");
                   strData += m_strTmp;
                   break;

               case 12:
                   m_strTmp.sprintf("口令条目\n\n");
                   strData += m_strTmp;
                   break;
               case 13:
                   m_strTmp.sprintf("只读\n\n");
                   strData += m_strTmp;
                   break;
               case 14:
                   m_strTmp.sprintf("只写\n\n");
                   strData += m_strTmp;
                   break;
               case 19:
                   m_strTmp.sprintf("相应的功能类型和信息序号\n\n");
                   strData += m_strTmp;
                   break;
               case 20:
                   m_strTmp.sprintf("相应的事件\n\n");
                   strData += m_strTmp;
                   break;
               case 21:
                   m_strTmp.sprintf("列表的文本阵列\n\n");
                   strData += m_strTmp;
                   break;
               case 22:
                   m_strTmp.sprintf("列表的值阵列\n\n");
                   strData += m_strTmp;
                   break;
               case 23:
                   m_strTmp.sprintf("相关联的条目\n\n");
                   strData += m_strTmp;
                   break;

               default:
                   m_strTmp.sprintf("备用\n\n");
                   strData += m_strTmp;
                   break;
               }

               //通用分类数据描述
               m_strTmp.sprintf("数据宽度 = %d\n数目 = %d\n后续状态位 = %d\n数据类型 = %d\n\n", \
                                temp.gdd.nSize, temp.gdd.nNum, temp.gdd.n_Cont, temp.gdd.nType);
               strData += m_strTmp;

               GID tempgid;
               for(unsigned int i =0; i < temp.gdd.nNum; i++)
               {
                  tempgid = temp.vec_GID[i];
                  switch(temp.gdd.nType)
                  {
                  case 0:
                  {
                    m_strTmp.sprintf("无数据\n");
                    strData += m_strTmp;
                  }break;
                  case 1:
                  {
                      m_strTmp.sprintf("ASCII八位码 = %c\n", tempgid.ASCII);
                      strData += m_strTmp;
                  }break;
                  case 2:
                  {
                      m_strTmp.sprintf("成组八位串 = %d %d %d %d\n", \
                                       tempgid.bsi.chBsi[0], tempgid.bsi.chBsi[1], tempgid.bsi.chBsi[2], tempgid.bsi.chBsi[3]);
                      strData += m_strTmp;
                  }break;
                  case 3:
                  {
                      m_strTmp.sprintf("无符号整数 = %u\n", tempgid.UnnValue);
                      strData += m_strTmp;
                  }break;
                  case 4:
                  {
                      m_strTmp.sprintf("整数 = %d\n", tempgid.nValue);
                      strData += m_strTmp;
                  }break;
                  case 5:
                  {
                      m_strTmp.sprintf("无符号浮点数 = %f\n", tempgid.UnfValue);
                      strData += m_strTmp;
                  }break;
                  case 6:
                  {
                      m_strTmp.sprintf("浮点数 = %lf\n", tempgid.fValue);
                      strData += m_strTmp;
                  }break;
                  case 7:
                  {
                      m_strTmp.sprintf("IEEE标准754短实数 = %f\n", tempgid.R32);
                      strData += m_strTmp;
                  }break;
                  case 8:
                  {
                      m_strTmp.sprintf("IEEE标准754实数 = %lf\n", tempgid.R64);
                      strData += m_strTmp;
                  }break;
                  case 9:
                  {
                      m_strTmp.sprintf("双点信息 = %d\n", tempgid.dpi.nDpi);
                      strData += m_strTmp;
                  }break;
                  case 10:
                  {
                      m_strTmp.sprintf("单点信息 = %d\n", tempgid.spi.nSpi);
                      strData += m_strTmp;
                  }break;
                  case 11:
                  {
                      m_strTmp.sprintf("带瞬变和差错的双点信息 = %d\n", tempgid.nTEDPI);
                      strData += m_strTmp;
                  }break;
                  case 12:
                  {
                      m_strTmp.sprintf("带品质描述词的被测值:\n溢出位 = %d 差错位 = %d 被测值 = %f\n", \
                                       tempgid.mea.nOV, tempgid.mea.nER, tempgid.mea.fMVAL);
                      strData += m_strTmp;
                  }break;
                  case 13:
                  {
                      m_strTmp.sprintf("备用\n");
                      strData += m_strTmp;
                  }break;
                  case 14:
                  {
                      m_strTmp.sprintf("7个8位二进制时间 = %s\n", tempgid.ch7ByteTime);
                      strData += m_strTmp;
                  }break;
                  case 15:
                  {
                      m_strTmp.sprintf("通用分类标识序号:\n组号 = %d 条目号 = %d", tempgid.gin.nGroup, tempgid.gin.nEntry);
                      strData += m_strTmp;
                  }break;
                  case 16:
                  {
                      m_strTmp.sprintf("相对时间 = %d", tempgid.ret.nRET);
                      strData += m_strTmp;
                  }break;
                  case 17:
                  {
                      m_strTmp.sprintf("功能类型和信息序号:\n功能类型 = %d 信息序号 =%d", tempgid.nFUN, tempgid.nINF);
                      strData += m_strTmp;
                  }break;
                  case 18:
                  {
                      m_strTmp.sprintf("带时标的报文:\n双点信息 = %d\n四字节时间 = %s\n附加信息 = %d\n", \
                                       tempgid.dpiwitime.dpi.nDpi, tempgid.dpiwitime.ch4ByteTime, tempgid.dpiwitime.sin);
                      strData += m_strTmp;
                  }break;
                  case 19:
                  {
                      m_strTmp.sprintf("带相对时间的时标报文:\n双点信息 = %d\n相对时间 = %d\n故障序号 = %d\n四字节时间 = %s\n附加信息 = %d\n", \
                                       tempgid.dpiwiret.dpi.nDpi, tempgid.dpiwiret.ret.nRET, tempgid.dpiwiret.fan.nFAN, \
                                       tempgid.dpiwiret.ch4ByteTime, tempgid.dpiwiret.sin);
                      strData += m_strTmp;
                  }break;
                  case 20:
                  {
                      m_strTmp.sprintf("带相对时间的时标的被测值:\n被测值 = %f\n 相对时间 = %d\n故障序号 = %d\n四字节时间 = %s\n", \
                                       tempgid.valwiret.R32, tempgid.valwiret.ret, tempgid.valwiret.fan, tempgid.valwiret.ch4ByteTime);
                      strData += m_strTmp;
                  }break;
                  case 21:
                  {
                      m_strTmp.sprintf("外部文本序号\n");
                      strData += m_strTmp;
                  }break;
                  case 22:
                  {
                      m_strTmp.sprintf("通用分类回答码 = %d\n", tempgid.grc.nGrc);
                      strData += m_strTmp;
                  }break;
                  case 23:
                  {
                      m_strTmp.sprintf("数据结构\n");
                      strData += m_strTmp;
                  }break;
                  case 24:
                  {
                      m_strTmp.sprintf("索引\n");
                      strData += m_strTmp;
                  }break;

                  default :
                  {
                      m_strTmp.sprintf("备用\n");
                      strData += m_strTmp;
                  }break;

                  }
               }


               strData += "\n";
           }

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu10

int CDataDisplay103::DisplayAsdu11(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_11 asdu11;

        if(c103Data.vec_Asdu103_11.size() > 0)
        {
            asdu11 = c103Data.vec_Asdu103_11[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_11.size(); i++)
        {
           asdu11 = c103Data.vec_Asdu103_11[i];

           //功能类型、信息序号和返回信息标识符
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\nRII = %d\n\n", asdu11.nGENFUN, asdu11.nINF, asdu11.nRII);
           strData += m_strTmp;

           //通用分类标识序号
           m_strTmp.sprintf("组号 = %d\n条目号 = %d\n\n", \
                            asdu11.gin.nGroup, asdu11.gin.nEntry);
           strData += m_strTmp;

           //描述元素的数目
           m_strTmp.sprintf("数目 = %d\n后续状态位 = %d\n\n", \
                            asdu11.nde.nNO, asdu11.nde.nCONT);
           strData += m_strTmp;

           //数据集
           Asdu103_11DataSet temp;
           for(int i = 0; i < (int)asdu11.nde.nNO; i++)
           {
               temp = asdu11.vec_Asdu103_11DataSet[i];

               //描述类别
               m_strTmp.sprintf("描述类别 = %d  : ", \
                                temp.nKod);
               strData += m_strTmp;

               switch (temp.nKod)
               {
               case 0:
                   m_strTmp.sprintf("无所指定的描述类别\n\n");
                   strData += m_strTmp;
                   break;
               case 1:
                   m_strTmp.sprintf("实际值\n\n");
                   strData += m_strTmp;
                   break;
               case 2:
                   m_strTmp.sprintf("缺省值\n\n");
                   strData += m_strTmp;
                   break;
               case 3:
                   m_strTmp.sprintf("量程（最小值、最大值、步长)\n\n");
                   strData += m_strTmp;
                   break;

               case 5:
                   m_strTmp.sprintf("精度（n，m)\n\n");
                   strData += m_strTmp;
                   break;
               case 6:
                   m_strTmp.sprintf("因子\n\n");
                   strData += m_strTmp;
                   break;
               case 7:
                   m_strTmp.sprintf("%参比\n\n");
                   strData += m_strTmp;
                   break;
               case 8:
                   m_strTmp.sprintf("列表\n\n");
                   strData += m_strTmp;
                   break;
               case 9:
                   m_strTmp.sprintf("量纲\n\n");
                   strData += m_strTmp;
                   break;
               case 10:
                   m_strTmp.sprintf("描述\n\n");
                   strData += m_strTmp;
                   break;

               case 12:
                   m_strTmp.sprintf("口令条目\n\n");
                   strData += m_strTmp;
                   break;
               case 13:
                   m_strTmp.sprintf("只读\n\n");
                   strData += m_strTmp;
                   break;
               case 14:
                   m_strTmp.sprintf("只写\n\n");
                   strData += m_strTmp;
                   break;
               case 19:
                   m_strTmp.sprintf("相应的功能类型和信息序号\n\n");
                   strData += m_strTmp;
                   break;
               case 20:
                   m_strTmp.sprintf("相应的事件\n\n");
                   strData += m_strTmp;
                   break;
               case 21:
                   m_strTmp.sprintf("列表的文本阵列\n\n");
                   strData += m_strTmp;
                   break;
               case 22:
                   m_strTmp.sprintf("列表的值阵列\n\n");
                   strData += m_strTmp;
                   break;
               case 23:
                   m_strTmp.sprintf("相关联的条目\n\n");
                   strData += m_strTmp;
                   break;

               default:
                   m_strTmp.sprintf("备用\n\n");
                   strData += m_strTmp;
                   break;
               }

               //通用分类数据描述
               m_strTmp.sprintf("数据宽度 = %d\n数目 = %d\n后续状态位 = %d\n数据类型 = %d\n\n", \
                                temp.gdd.nSize, temp.gdd.nNum, temp.gdd.n_Cont, temp.gdd.nType);
               strData += m_strTmp;

               GID tempgid;
               for(unsigned int i =0; i < temp.gdd.nNum; i++)
               {
                  tempgid = temp.vec_GID[i];
                  switch(temp.gdd.nType)
                  {
                  case 0:
                  {
                    m_strTmp.sprintf("无数据\n");
                    strData += m_strTmp;
                  }break;
                  case 1:
                  {
                      m_strTmp.sprintf("ASCII八位码 = %c\n", tempgid.ASCII);
                      strData += m_strTmp;
                  }break;
                  case 2:
                  {
                      m_strTmp.sprintf("成组八位串 = %d %d %d %d\n", \
                                       tempgid.bsi.chBsi[0], tempgid.bsi.chBsi[1], tempgid.bsi.chBsi[2], tempgid.bsi.chBsi[3]);
                      strData += m_strTmp;
                  }break;
                  case 3:
                  {
                      m_strTmp.sprintf("无符号整数 = %u\n", tempgid.UnnValue);
                      strData += m_strTmp;
                  }break;
                  case 4:
                  {
                      m_strTmp.sprintf("整数 = %d\n", tempgid.nValue);
                      strData += m_strTmp;
                  }break;
                  case 5:
                  {
                      m_strTmp.sprintf("无符号浮点数 = %f\n", tempgid.UnfValue);
                      strData += m_strTmp;
                  }break;
                  case 6:
                  {
                      m_strTmp.sprintf("浮点数 = %lf\n", tempgid.fValue);
                      strData += m_strTmp;
                  }break;
                  case 7:
                  {
                      m_strTmp.sprintf("IEEE标准754短实数 = %f\n", tempgid.R32);
                      strData += m_strTmp;
                  }break;
                  case 8:
                  {
                      m_strTmp.sprintf("IEEE标准754实数 = %lf\n", tempgid.R64);
                      strData += m_strTmp;
                  }break;
                  case 9:
                  {
                      m_strTmp.sprintf("双点信息 = %d\n", tempgid.dpi.nDpi);
                      strData += m_strTmp;
                  }break;
                  case 10:
                  {
                      m_strTmp.sprintf("单点信息 = %d\n", tempgid.spi.nSpi);
                      strData += m_strTmp;
                  }break;
                  case 11:
                  {
                      m_strTmp.sprintf("带瞬变和差错的双点信息 = %d\n", tempgid.nTEDPI);
                      strData += m_strTmp;
                  }break;
                  case 12:
                  {
                      m_strTmp.sprintf("带品质描述词的被测值:\n溢出位 = %d 差错位 = %d 被测值 = %f\n", \
                                       tempgid.mea.nOV, tempgid.mea.nER, tempgid.mea.fMVAL);
                      strData += m_strTmp;
                  }break;
                  case 13:
                  {
                      m_strTmp.sprintf("备用\n");
                      strData += m_strTmp;
                  }break;
                  case 14:
                  {
                      m_strTmp.sprintf("7个8位二进制时间 = %s\n", tempgid.ch7ByteTime);
                      strData += m_strTmp;
                  }break;
                  case 15:
                  {
                      m_strTmp.sprintf("通用分类标识序号:\n组号 = %d 条目号 = %d", tempgid.gin.nGroup, tempgid.gin.nEntry);
                      strData += m_strTmp;
                  }break;
                  case 16:
                  {
                      m_strTmp.sprintf("相对时间 = %d", tempgid.ret.nRET);
                      strData += m_strTmp;
                  }break;
                  case 17:
                  {
                      m_strTmp.sprintf("功能类型和信息序号:\n功能类型 = %d 信息序号 =%d", tempgid.nFUN, tempgid.nINF);
                      strData += m_strTmp;
                  }break;
                  case 18:
                  {
                      m_strTmp.sprintf("带时标的报文:\n双点信息 = %d\n四字节时间 = %s\n附加信息 = %d\n", \
                                       tempgid.dpiwitime.dpi.nDpi, tempgid.dpiwitime.ch4ByteTime, tempgid.dpiwitime.sin);
                      strData += m_strTmp;
                  }break;
                  case 19:
                  {
                      m_strTmp.sprintf("带相对时间的时标报文:\n双点信息 = %d\n相对时间 = %d\n故障序号 = %d\n四字节时间 = %s\n附加信息 = %d\n", \
                                       tempgid.dpiwiret.dpi.nDpi, tempgid.dpiwiret.ret.nRET, tempgid.dpiwiret.fan.nFAN, \
                                       tempgid.dpiwiret.ch4ByteTime, tempgid.dpiwiret.sin);
                      strData += m_strTmp;
                  }break;
                  case 20:
                  {
                      m_strTmp.sprintf("带相对时间的时标的被测值:\n被测值 = %f\n 相对时间 = %d\n故障序号 = %d\n四字节时间 = %s\n", \
                                       tempgid.valwiret.R32, tempgid.valwiret.ret, tempgid.valwiret.fan, tempgid.valwiret.ch4ByteTime);
                      strData += m_strTmp;
                  }break;
                  case 21:
                  {
                      m_strTmp.sprintf("外部文本序号\n");
                      strData += m_strTmp;
                  }break;
                  case 22:
                  {
                      m_strTmp.sprintf("通用分类回答码 = %d\n", tempgid.grc.nGrc);
                      strData += m_strTmp;
                  }break;
                  case 23:
                  {
                      m_strTmp.sprintf("数据结构\n");
                      strData += m_strTmp;
                  }break;
                  case 24:
                  {
                      m_strTmp.sprintf("索引\n");
                      strData += m_strTmp;
                  }break;

                  default :
                  {
                      m_strTmp.sprintf("备用\n");
                      strData += m_strTmp;
                  }break;

                  }
               }


               strData += "\n";
           }

           strData += "\n";
        }


















        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu11

int CDataDisplay103::DisplayAsdu23(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_23 asdu23;

        if(c103Data.vec_Asdu103_23.size() > 0)
        {
            asdu23 = c103Data.vec_Asdu103_23[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu23.dui.nType, asdu23.dui.vsq.nContinuous, asdu23.dui.vsq.nVsq, asdu23.dui.nCot, asdu23.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c103Data.vec_Asdu103_23.size(); i++)
        {
           asdu23 = c103Data.vec_Asdu103_23[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu23.nFUN, asdu23.nINF);
           strData += m_strTmp;

           //被测值
           Asdu103_23DataSet temp;
           for(int i = 0; i < (int)asdu23.dui.vsq.nVsq; i++)
           {
               temp = asdu23.vec_Asdu103_23DataSet[i];

                 m_strTmp.sprintf("故障序号 = %d\n故障的状态(被记录的故障跳闸状态 = %d 扰动数据传输状态 = %d 是否是测试数据 = %d 扰动数据触发方式 = %d 保留位 = %d)\n七字节时间 = %s\n", \
                          temp.fan.nFAN, temp.sof.nTP, temp.sof.nTM, temp.sof.nTEST, temp.sof.nOTEV, temp.sof.nRES, temp.ch7ByteTime);
                 strData += m_strTmp;
                 strData += "\n";
           }

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu23

int CDataDisplay103::DisplayAsdu26(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_26 asdu26;

        if(c103Data.vec_Asdu103_26.size() > 0)
        {
            asdu26 = c103Data.vec_Asdu103_26[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu26.dui.nType, asdu26.dui.vsq.nContinuous, asdu26.dui.vsq.nVsq, asdu26.dui.nCot, asdu26.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c103Data.vec_Asdu103_26.size(); i++)
        {
           asdu26 = c103Data.vec_Asdu103_26[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu26.nFUN, asdu26.nINF);
           strData += m_strTmp;

           //扰动信息
           m_strTmp.sprintf("扰动值类型 = %d\n故障序号 = %d\n电网故障序号 = %d\n通道数目 = %d\n一个通道信息元素的数目 = %d\n信息元素间的间隔 = %d\n", \
                            asdu26.tov.nTOV, asdu26.fan.nFAN, asdu26.nof.nNOF, asdu26.noc.nNOC, asdu26.noe.nNOE, asdu26.stru_INT.nINT);
           strData += m_strTmp;

           m_strTmp.sprintf("四字节时间 = %s\n", asdu26.ch4ByteTime);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu26

int CDataDisplay103::DisplayAsdu27(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_27 asdu27;

        if(c103Data.vec_Asdu103_27.size() > 0)
        {
            asdu27 = c103Data.vec_Asdu103_27[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu27.dui.nType, asdu27.dui.vsq.nContinuous, asdu27.dui.vsq.nVsq, asdu27.dui.nCot, asdu27.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c103Data.vec_Asdu103_27.size(); i++)
        {
           asdu27 = c103Data.vec_Asdu103_27[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu27.nFUN, asdu27.nINF);
           strData += m_strTmp;

           //扰动信息
           m_strTmp.sprintf("扰动值类型 = %d\n故障序号 = %d\n实际通道序号 = %d\n", \
                            asdu27.tov.nTOV, asdu27.fan.nFAN, asdu27.acc.nACC);
           strData += m_strTmp;

           //额定值
           m_strTmp.sprintf("一次额定值 = %f\n二次额定值 = %f\n参比因子 = %f\n", asdu27.fPrimValue,asdu27.fSecValue, asdu27.fRatio);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu27

int CDataDisplay103::DisplayAsdu28(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_28 asdu28;

        if(c103Data.vec_Asdu103_28.size() > 0)
        {
            asdu28 = c103Data.vec_Asdu103_28[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu28.dui.nType, asdu28.dui.vsq.nContinuous, asdu28.dui.vsq.nVsq, asdu28.dui.nCot, asdu28.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c103Data.vec_Asdu103_28.size(); i++)
        {
           asdu28 = c103Data.vec_Asdu103_28[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu28.nFUN, asdu28.nINF);
           strData += m_strTmp;

           //扰动信息
           m_strTmp.sprintf("故障序号 = %d\n", \
                            asdu28.fan.nFAN);
           strData += m_strTmp;

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu28

int CDataDisplay103::DisplayAsdu29(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_29 asdu29;

        if(c103Data.vec_Asdu103_29.size() > 0)
        {
            asdu29 = c103Data.vec_Asdu103_29[0];
            //数据单元标识符
            m_strTmp.sprintf("类型标识符 = %d\n可变结构限定词--SQ = %d Num = %d\n传送原因 = %d\n公共地址 = %d\n", \
                            asdu29.dui.nType, asdu29.dui.vsq.nContinuous, asdu29.dui.vsq.nVsq, asdu29.dui.nCot, asdu29.dui.nCommonAddr);
            strData += m_strTmp;
            strData += "\n";
        }
        else
        {
            return -1;
        }

        for(int i = 0; i < (int)c103Data.vec_Asdu103_29.size(); i++)
        {
           asdu29 = c103Data.vec_Asdu103_29[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu29.nFUN, asdu29.nINF);
           strData += m_strTmp;

           //故障序号、数目、标志的位置
           m_strTmp.sprintf("故障序号 = %d\n带标志的状态变位数目 = %d\n标志的位置 = %d\n", \
                            asdu29.fan.nFAN, asdu29.stru_NOT.nNot, asdu29.stru_TAP.nTap);
           strData += m_strTmp;
           strData += "\n";

           //状态变位
           Asdu103_29DataSet temp;
           for(unsigned int i = 0; i < (asdu29.stru_NOT.nNot);i++)
           {
               temp = asdu29.vec_Asdu103_29DataSet[i];
               m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n双点信息(1-开,2-合,0/3-未用) = %d\n", temp.nStateFUN, temp.nStateINF, temp.dpi.nDpi);

               strData += m_strTmp;
               strData += "\n";
           }

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu29

int CDataDisplay103::DisplayAsdu30(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_30 asdu30;

        if(c103Data.vec_Asdu103_30.size() > 0)
        {
            asdu30 = c103Data.vec_Asdu103_30[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_30.size(); i++)
        {
           asdu30 = c103Data.vec_Asdu103_30[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu30.nFUN, asdu30.nINF);
           strData += m_strTmp;

           //扰动信息
           m_strTmp.sprintf("扰动值类型 = %d\n故障序号 = %d\n实际通道序号 = %d\n", \
                            asdu30.tov.nTOV, asdu30.fan.nFAN, asdu30.acc.nACC);
           strData += m_strTmp;

           //
           m_strTmp.sprintf("每个Asdu有关扰动值的数目 = %d\nAsdu的第一个信息元素序号 = %d\n", asdu30.ndv.nNDV, asdu30.nfe.nNFE);
           strData += m_strTmp;

           for(int i = 0; i < (asdu30.ndv.nNDV); i++)
           {
               m_strTmp.sprintf("单个扰动值%d = %f\n", i+1, asdu30.sdv[i]);
               strData += m_strTmp;
           }

           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu30

int CDataDisplay103::DisplayAsdu31(CC103Data &c103Data, QString &strData)
{
    try
    {
        Asdu103_31 asdu31;

        if(c103Data.vec_Asdu103_31.size() > 0)
        {
            asdu31 = c103Data.vec_Asdu103_31[0];
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

        for(int i = 0; i < (int)c103Data.vec_Asdu103_31.size(); i++)
        {
           asdu31 = c103Data.vec_Asdu103_31[i];

           //功能号和信息序号
           m_strTmp.sprintf("功能类型 = %d\n信息序号 = %d\n", asdu31.nFUN, asdu31.nINF);
           strData += m_strTmp;

           //命令类型、扰动值类型、故障序号、实际通道
           m_strTmp.sprintf("命令类型 = %d\n扰动值类型 = %d\n故障序号 = %d\n实际通道 = %d\n", \
                            asdu31.too.nToo, asdu31.tov.nTOV, asdu31.fan.nFAN, asdu31.acc.nACC);
           strData += m_strTmp;


           strData += "\n";
        }

        return 1;
    }
    catch(...)
    {
        return -1;
    }
}//DisplayAsdu31
