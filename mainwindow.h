#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include "CommonAsduAnalyzer101_104/Common101Or104Analyzer.h"
#include "cdatadisplay101.h"

#include "CommonAsduAnalyzer103/Common103Analyzer.h"
#include "cdatadisplay103.h"

#include "sf_103_udp_analyzer/Sf103UdpAnalyzer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
