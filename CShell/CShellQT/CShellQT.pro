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
        CSHELL_USE_QT

SOURCES += cshellqt.cpp\
      CShellEventReceiver.cpp \
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
    ../src/CButton.cpp \
    ../src/CEdit.cpp \
    ../src/CSpinButtonCtrl.cpp \
    ../src/CScrollBar.cpp \
    ../src/CQSlider.cpp \
    ../src/CMDIFrameWnd.cpp \
    ../src/CMDIChildWnd.cpp \
    ../src/CFrameWnd.cpp \
    ../src/CPoint.cpp \
    ../src/CRect.cpp \
    ../src/CSize.cpp \
    ../src/afx.cpp \
    ../src/CCommandLineInfo.cpp \
    ../src/CMultiDocTemplate.cpp \
    ../src/CSingleDocTemplate.cpp \
    ../src/CDocTemplate.cpp \
    ../src/CDocument.cpp \
    ../src/CArchive.cpp \
    ../src/CArchiveException.cpp \
    ../src/CMapPtrToPtr.cpp \
    ../src/CPtrArray.cpp \
    ../src/CException.cpp \
    ../src/CPlex.cpp \
    ../src/CView.cpp \
    ../src/CStatusBar.cpp \
    ../src/CToolBar.cpp \
    ../src/CToolBarCtrl.cpp

HEADERS += cshellqt.h\
        cshellqt_global.h \
        /inc/*.h \
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

Debug:DESTDIR = ../build/MinGW_32bit-Debug
Release:DESTDIR = ../build/MinGW_32bit-Release

OTHER_FILES +=
