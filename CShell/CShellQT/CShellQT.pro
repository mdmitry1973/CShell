#-------------------------------------------------
#
# Project created by QtCreator 2013-06-22T12:18:14
#
#-------------------------------------------------

#QT       -= gui
QT += xml
QT += widgets
#QT += webkit

TARGET = CShellQT
TEMPLATE = lib

DEFINES += CSHELLQT_LIBRARY\
        CSHELL_LIB_DLL

SOURCES += cshellqt.cpp\
    ../src/CWinApp.cpp \
    ../src/CTargetEvent.cpp \
    ../src/CObject.cpp \
    ../src/CString.cpp \
    ../src/CRuntimeClass.cpp \
    ../src/CWnd.cpp \
    ../src/CDialogEx.cpp \
    ../src/CDialog.cpp \
    ../src/CDataExchange.cpp \
    ../src/CMenu.cpp \
    ../src/CComboBox.cpp \
    ../src/CListBox.cpp \
    ../src/CSliderCtrl.cpp \
    ../src/CProgressCtrl.cpp \
    CShellEventReceiver.cpp \
    ../src/CButton.cpp \
    ../src/CEdit.cpp \
    ../src/CSpinButtonCtrl.cpp

HEADERS += cshellqt.h\
        cshellqt_global.h \
    ../inc/*.h \
    CShellEventReceiver.h

INCLUDEPATH += ../inc

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

OTHER_FILES +=
