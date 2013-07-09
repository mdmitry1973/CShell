#-------------------------------------------------
#
# Project created by QtCreator 2013-06-22T13:17:37
#
#-------------------------------------------------

QT       += core gui

DEFINES += CSHELL_USE_QT

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleDialogQT
TEMPLATE = app

INCLUDEPATH += ../../../CShell/inc\
                ../inc

SOURCES += main.cpp\
    ../SimpleDialog2.cpp \
    ../SimpleDialog2Dlg.cpp \
    ../NumSpinCtrl.cpp \
    ../NumEdit.cpp

HEADERS  +=\
            ../*.h \
    ../SimpleDialog2.h \
    ../SimpleDialog2Dlg.h

FORMS    += mainwindow.ui

Debug:LIBS += ../../../CShell/build/MinGW_32bit-Debug/CShellQT.dll
Release:LIBS += ../../../CShell/build/MinGW_32bit-Release/CShellQT.dll

QMAKE_POST_LINK = copy /y ..\..\..\CShell\build\MinGW_32bit-Debug\CShellQT.dll .\debug\&copy /y ..\..\..\Examples\SimpleDialog\English.lproj\Resources.xml .\&copy /y ..\..\..\Examples\SimpleDialog\English.lproj\bitmap1.bmp .\
