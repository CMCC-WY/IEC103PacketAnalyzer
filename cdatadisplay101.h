#ifndef CDATADISPLAY101_H
#define CDATADISPLAY101_H

#if _MSC_VER >= 1600
#pragma execution_character_set("UTF-8")
#endif

#include <QMainWindow>
#include "CommonAsduAnalyzer101_104/Common101Or104Analyzer.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QMap>

class CDataDisplay101 : public QMainWindow
{
    Q_OBJECT
public:
    explicit CDataDisplay101(QWidget *parent = 0);

signals:

public slots:

public:
    int displayData(const int nAsduType, CC101Or104Data &c101Or104Data, QString &strData);

private:
    //每个展示的函数应当满足这个函数模式
    typedef int(CDataDisplay101::*pFun)(CC101Or104Data &c101Or104Data, QString &strData);
    QMap<int, pFun> m_map_display_function;

private:
    //初始化asdu类型号和对应的展示函数map
    int InitDisplayFunctionMap(void);

    /// 展示asdu1数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu1(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu2数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu2(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu3数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu3(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu4数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu4(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu5数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu5(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu6数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu6(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu7数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu7(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu8数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu8(CC101Or104Data &c101Or104Data, QString &strData);


    /// 展示asdu9数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu9(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu10数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu10(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu11数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu11(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu12数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu12(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu13数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu13(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu14数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu14(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu15数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu15(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu16数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu16(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu17数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu17(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu18数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu18(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu19数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu19(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu20数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu20(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu21数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu21(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu30数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu30(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu31数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu31(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu32数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu32(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu33数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu33(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu34数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu34(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu35数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu35(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu36数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu36(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu37数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu37(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu38数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu38(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu39数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu39(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu40数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu40(CC101Or104Data &c101Or104Data, QString &strData);

    /// 展示asdu70数据
    ///    @param CC101Or104Data &c101Or104Data 解析之后的数据
    ///    @param QString &strData 展示的字符串
    ///    @return -1 解析出错
    ///    @return 1 解析成功
    int DisplayAsdu70(CC101Or104Data &c101Or104Data, QString &strData);
private:
    QString m_strTmp;
};

#endif // CDATADISPLAY_H
