
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QMdiArea>
#include <QMdiSubWindow>

#include "CDef.h"
#include "CWnd.h"
#include "CWinApp.h"

extern CWinApp	 *pMainApp;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    QMainWindow *mainWindow = new QMainWindow;
    QMenuBar *menuBar = new QMenuBar;

    QMenu *menuFile = new QMenu("File");
    menuBar->addMenu(menuFile);

    QMenu *menuEdit = new QMenu("Edit");
    menuBar->addMenu(menuEdit);


    mainWindow->setMenuBar(menuBar);
    mainWindow->resize(300, 300);

    QMdiArea *mdi = new QMdiArea(mainWindow);

    mainWindow->setCentralWidget(mdi);


    {
        QMenuBar *menuSubBar = new QMenuBar;

        QMenu *menuFile = new QMenu("File2");
        menuSubBar->addMenu(menuFile);

        QMenu *menuEdit = new QMenu("Edit2");
        menuSubBar->addMenu(menuEdit);


        QMainWindow *mainSubWindow = new QMainWindow;

         mainSubWindow->setMenuBar(menuSubBar);
         mainSubWindow->resize(300, 300);

         QMdiSubWindow *subWindow =mdi->addSubWindow(mainSubWindow);

         subWindow->resize(300, 300);
         mainSubWindow->show();



    }

    {
        QMenuBar *menuSubBar = new QMenuBar;

        QMenu *menuFile = new QMenu("File3");
        menuSubBar->addMenu(menuFile);

        QMenu *menuEdit = new QMenu("Edit3");
        menuSubBar->addMenu(menuEdit);


        QMainWindow *mainSubWindow2 = new QMainWindow;

        mainSubWindow2->setMenuBar(menuSubBar);
        mainSubWindow2->resize(300, 300);

        QMdiSubWindow *subWindow =mdi->addSubWindow(mainSubWindow2);

        subWindow->resize(300, 300);
        mainSubWindow2->show();

    }

    mainWindow->show();
*/

    if (!pMainApp->InitInstance())
    {
        return 0;
    }

    pMainApp->SetMessageMap();

    return a.exec();
}
