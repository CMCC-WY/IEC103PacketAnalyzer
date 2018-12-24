#ifndef CDATADISPLAY103_H
#define CDATADISPLAY103_H

#if _MSC_VER >= 1600
#pragma execution_character_set("UTF-8")
#endif

#include <QMainWindow>
#include "CommonAsduAnalyzer103/Common103Analyzer.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QMap>




class CDataDisplay103 : public QMainWindow
{
    Q_OBJECT
public:
    explicit CDataDisplay103(QWidget *parent = 0);

signals:

public slots:

public:
     int displayData(const int nAsduType, CC103Data &c103Data, QString &strData);

private:
     //每个展示的函数应当满足这个函数模式
     typedef int(CDataDisplay103::*pFun)(CC103Data &c103Data, QString &strData);
     QMap<int, pFun> m_map_display_function;

private:
     //初始化asdu类型号和对应的展示函数map
     int InitDisplayFunctionMap(void);

     /// 展示asdu1数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu1(CC103Data &c103Data, QString &strData);

     /// 展示asdu2数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu2(CC103Data &c103Data, QString &strData);

     /// 展示asdu3数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu3(CC103Data &c103Data, QString &strData);

     /// 展示asdu4数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu4(CC103Data &c103Data, QString &strData);

     /// 展示asdu5数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu5(CC103Data &c103Data, QString &strData);

     /// 展示asdu6数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu6(CC103Data &c103Data, QString &strData);

     /// 展示asdu8数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu8(CC103Data &c103Data, QString &strData);


     /// 展示asdu9数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu9(CC103Data &c103Data, QString &strData);

     /// 展示asdu10数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu10(CC103Data &c103Data, QString &strData);

     /// 展示asdu11数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu11(CC103Data &c103Data, QString &strData);

     /// 展示asdu23数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu23(CC103Data &c103Data, QString &strData);

     /// 展示asdu26数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu26(CC103Data &c103Data, QString &strData);

     /// 展示asdu27数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu27(CC103Data &c103Data, QString &strData);

     /// 展示asdu28数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu28(CC103Data &c103Data, QString &strData);

     /// 展示asdu29数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu29(CC103Data &c103Data, QString &strData);

     /// 展示asdu30数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu30(CC103Data &c103Data, QString &strData);

     /// 展示asdu31数据
     ///    @param CC103Data &c103Data 解析之后的数据
     ///    @param QString &strData 展示的字符串
     ///    @return -1 解析出错
     ///    @return 1 解析成功
     int DisplayAsdu31(CC103Data &c103Data, QString &strData);

private:
    QString m_strTmp;
};

#endif // CDATADISPLAY103_H
