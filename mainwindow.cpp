#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QTextCodec>
#if _MSC_VER >= 1600
#pragma execution_character_set("UTF-8")
#endif
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    ui->setupUi(this);

   //设置最大显示下拉项,超过要用滚动条
    ui->comboBox->setMaxVisibleItems(5);
    ui->comboBox->addItem("IEC101的ASDU");
    ui->comboBox->addItem("IEC103的ASDU");
    ui->comboBox->addItem("四方UDP/串口103");

    //spliter设置比例
    ui->splitter->setStretchFactor(0,3);
    ui->splitter->setStretchFactor(1,7);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void deBlank(QString& str)
{
    int nLen = str.length();

    for(int i = 0; i < nLen; i++)
    {
        if(str.at(i).isSpace())
        {
            str[i] = QChar(' ');
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{

    QString str = ui->plainTextEdit_2->toPlainText();
    //去除输入中的所有空格及回车
    str.remove(QRegExp("\\s"));

    if(str.isEmpty())
    {
        QTextCursor tc = ui->plainTextEdit_2->textCursor();
        tc.setPosition(0);
        ui->plainTextEdit_2->clear();
        QMessageBox::warning(this, "Input Error", "请先输入数据!");
        return;
    }

     //正则比较是否满足16进制数据要求[0-9a-fA-F]{总长度}
    QString rgStr;
    rgStr =  rgStr.sprintf("[0-9a-fA-F]{%d}", str.length());
    qDebug("%s", rgStr.toStdString().data());

    QRegExp rg;
    rg.setPattern(rgStr);

    if(!rg.exactMatch(str))
    {
        qDebug("---!!!---failed,Matched %d Length", rg.matchedLength());
        QMessageBox::warning(this, "Input Error", "输入报文存在非法字符!");
        return;
    }

    if(0 != (str.length() % 2) )
    {
        QMessageBox::warning(this, "Input Error", "输入报文长度不正确!");
        return;
    }

    //qDebug("---InputData %s", str.toStdString().data());

    //文本框输入的字符数据转换成unsigned char*数组
    unsigned char* pSrcData = (unsigned char*) malloc( (str.length()/2) * sizeof(int));

    for(int i = 0; i < (str.length()/2); i++)
    {
        pSrcData[i] = str.mid(i*2,2).toInt(0,16);
        //qDebug("---pSrcData at %d is %.2x", i, pSrcData[i]);
    }

    switch (ui->comboBox->currentIndex())
    {
    case 0://101Aadu解析
    {
        CCommon101Or104Analyzer c101;
        c101.SetDuiValue(2, 2, 3);
        CC101Or104Data c101Data;

        //解析函数返回失败
        if(-1 == c101.AnalyzeAsduMsg(pSrcData, &c101Data))
        {
            QString errStr;
            errStr.sprintf("%s", c101.GetLastLogMsg());
            QMessageBox::warning(this, "Analyze 101/104 Message Error", errStr);
            break;
        }

        //展示解析之后的结果
        CDataDisplay101 dataDis;
        QString displayText;
        dataDis.displayData(c101.GetAsduType(), c101Data, displayText);
        ui->plainTextEdit->setPlainText(displayText);

        break;
    }
    case 1://103Asdu解析
    {
        CCommon103Analyzer c103;
        c103.SetDuiValue(1, 1);
        CC103Data c103Data;

        //解析函数返回失败
        if(-1 == c103.AnalyzeAsduMsg(pSrcData, &c103Data))
        {
            QString errStr;
            errStr.sprintf("%s", c103.GetLastLogMsg());
            QMessageBox::warning(this, "Analyze 103 Message Error", errStr);
            break;
        }

        //展示解析之后的结果
        CDataDisplay103 dataDis;
        QString displayText;
        dataDis.displayData(c103.GetAsduType(), c103Data, displayText);
        ui->plainTextEdit->setPlainText(displayText);

        break;
    }
    case 2://四方UDP或TCP103报文解析
    {
           CSf103UdpAnalyzer csf103udp;
           csf103udp.SetDuiValue(1,1);
           CC103Data c103Data;

           //解析函数返回失败
           if(-1 == csf103udp.AnalyzeAsduMsg(pSrcData, &c103Data, NULL))
           {
               QString errStr;
               errStr.sprintf("%s", csf103udp.GetLastLogMsg());
               QMessageBox::warning(this, "Analyze 103 Message Error", errStr);
               break;
           }

           //展示解析之后的结果
           CDataDisplay103 dataDis;
           QString displayText;
           dataDis.displayData(csf103udp.GetAsduType(), c103Data, displayText);
           ui->plainTextEdit->setPlainText(displayText);
        break;
    }
    default:
        break;
    }

    free(pSrcData);
}

void MainWindow::on_pushButton_3_clicked()
{
    QTextCursor tc = ui->plainTextEdit_2->textCursor();
    tc.setPosition(0);
    ui->plainTextEdit_2->clear();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->plainTextEdit->clear();
}
