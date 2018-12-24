#-------------------------------------------------
#
# Project created by QtCreator 2017-12-05T22:01:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AsduLoader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CommonAsduAnalyzer101_104/C101Or104Data.cpp \
    CommonAsduAnalyzer101_104/Common101Or104Analyzer.cpp \
    cdatadisplay103.cpp \
    CommonAsduAnalyzer101_104/C101Or104Data.cpp \
    CommonAsduAnalyzer101_104/Common101Or104Analyzer.cpp \
    sf_103_udp_analyzer/Sf103UdpAnalyzer.cpp \
    cdatadisplay101.cpp \
    CommonAsduAnalyzer103/C103Data.cpp \
    CommonAsduAnalyzer103/Common103Analyzer.cpp

HEADERS  += mainwindow.h \
    cdatadisplay101.h \
    cdatadisplay103.h \
    CommonAsduAnalyzer101_104/101Or104DataDefine.h \
    CommonAsduAnalyzer101_104/C101Or104Data.h \
    CommonAsduAnalyzer101_104/Common101Or104Analyzer.h \
    CommonAsduAnalyzer103/C103Data.h \
    CommonAsduAnalyzer103/Common103Analyzer.h \
    CommonAsduAnalyzer103/103DataDefine.h \
    CommonAsduAnalyzer101_104/101Or104DataDefine.h \
    CommonAsduAnalyzer101_104/C101Or104Data.h \
    CommonAsduAnalyzer101_104/Common101Or104Analyzer.h \
    CommonAsduAnalyzer103/103DataDefine.h \
    CommonAsduAnalyzer103/C103Data.h \
    CommonAsduAnalyzer103/Common103Analyzer.h \
    sf_103_udp_analyzer/Sf103UdpAnalyzer.h

FORMS    += mainwindow.ui
