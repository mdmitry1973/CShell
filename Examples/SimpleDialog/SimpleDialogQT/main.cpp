//#include "mainwindow.h"
#include <QApplication>

#include "CDef.h"
#include "CWnd.h"
#include "CWinApp.h"

extern CWinApp	 *pMainApp;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if (!pMainApp->InitInstance())
    {

    }

    pMainApp->SetMessageMap();
    
    return a.exec();
}
