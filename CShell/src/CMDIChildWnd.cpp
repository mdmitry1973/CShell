/*
 *  CMDIChildWnd.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMdiArea>

#include "CWinApp.h"
#include "CDocument.h"
#include "CMDIFrameWnd.h"

#include "CMDIChildWnd.h"

IMPLEMENT_DYNAMIC(CMDIChildWnd, CFrameWnd)

CMDIChildWnd::CMDIChildWnd()
{
	
}

CMDIChildWnd::~CMDIChildWnd()
{

}

BOOL CMDIChildWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                    DWORD dwStyle,
                    const RECT& rect,
                    CWnd* pParentWnd,
                    LPCTSTR lpszMenuName,
                    DWORD dwExStyle,
                    CCreateContext* pContext)
{
    if (pParentWnd == NULL)
    {
        CWinApp *app = AfxGetApp();

        //CWinThread *pThread = AfxGetThread();
        ASSERT(app);
        CWnd* pMainWnd = app->m_pMainWnd;
        ASSERT(pMainWnd != NULL);
        //ASSERT_KINDOF(CMDIFrameWnd, pMainWnd);
        pParentWnd = pMainWnd;
    }

    QWidget *parantFrame = NULL;
    Qt::WindowFlags f = 0;
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    if (pParentWnd)
    {
        parantFrame = (QWidget *)pParentWnd->GetNSWindow();
    }

    QMainWindow *frame =  new QMainWindow (parantFrame);

    f =	frame->windowFlags();

    if (dwStyle & WS_OVERLAPPED)
    {

    }

    if (dwStyle & WS_POPUP)
    {

    }

    if (dwStyle & WS_CHILD)
    {

    }

    if (dwStyle & WS_MINIMIZE)
    {
        f = f | Qt::WindowMinimizeButtonHint;
    }

    if (dwStyle & WS_VISIBLE)
    {

    }

    if (dwStyle & WS_DISABLED)
    {

    }

    if (dwStyle & WS_CLIPSIBLINGS)
    {

    }

    if (dwStyle & WS_CLIPCHILDREN)
    {

    }

    if (dwStyle & WS_MAXIMIZE)
    {

    }

    if (dwStyle & WS_CAPTION)
    {
        f = f | Qt::WindowTitleHint;
    }

    if (dwStyle & WS_BORDER)
    {
       // f = f & ~NSBorderlessWindowMask;
    }

    if (dwStyle & WS_DLGFRAME)
    {

    }

    if (dwStyle & WS_VSCROLL)
    {

    }

    if (dwStyle & WS_HSCROLL)
    {

    }

    if (dwStyle & WS_SYSMENU)
    {
        f = f | Qt::WindowSystemMenuHint;
    }

    if (dwStyle & WS_THICKFRAME)
    {

    }

    if (dwStyle & WS_GROUP)
    {

    }

    if (dwStyle & WS_TABSTOP)
    {

    }

    if (dwStyle & WS_MINIMIZEBOX)
    {
        f = f | Qt::WindowMinimizeButtonHint;
    }

    if (dwStyle & WS_MAXIMIZEBOX)
    {
        f = f | Qt::WindowMinMaxButtonsHint;
    }

    frame->setWindowFlags(f);
    frame->move (contentRect.x(), contentRect.y());
    frame->resize(contentRect.width(), contentRect.height());

    frame->setWindowTitle(QString::fromWCharArray(lpszWindowName));

   // m_hWnd = frame;
    mMainWindow = TRUE;

   // QMainWindow *frame =  (QMainWindow *)m_hWnd;
    QMdiSubWindow *subWindow = NULL;
    QWidget *parentWidget = NULL;

    if (pParentWnd)
    {
        parentWidget = (QWidget *)pParentWnd->GetNSWindow();
    }

    if (!parentWidget)
    {
        qDebug() << "CFrameWnd::CMDIChildWnd parentWidget==NULL";
        return FALSE;
    }

    QMainWindow *parentMainWindow = dynamic_cast<QMainWindow *>(parentWidget);

    if (!parentWidget)
    {
        qDebug() << "CFrameWnd::CMDIChildWnd parentMainWindow==NULL";
        return FALSE;
    }

    if (parentMainWindow)
    {
        QWidget *centralWidget = parentMainWindow->centralWidget();
        QMdiArea *mdiArea = dynamic_cast<QMdiArea *>(centralWidget);

        if (mdiArea)
        {
            subWindow = mdiArea->addSubWindow(frame);//subWindow);
        }
    }

    subWindow->move (parentMainWindow->pos());
    subWindow->resize(parentMainWindow->size());

    subWindow->setWindowTitle(QString::fromWCharArray(lpszWindowName));

    m_hWnd = subWindow;

    if (pContext)
    {
        CDocument *doc = pContext->m_pCurrentDoc;

        if (doc)
        {

        }
    }

    if (mMenu.LoadMenu(lpszMenuName))
    {
        SetMenu(&mMenu);
    }
    else
    {
        //set main frame menu
    }


    CREATESTRUCT data;

    data.lpCreateParams = 0;
    data.hInstance = 0;
    data.hMenu = (HMENU)mMenu.GetNSMenu();
    if (pParentWnd) data.hwndParent = (HWND)pParentWnd->GetNSWindow();
    data.cy = rect.bottom;
    data.cx = rect.right;
    data.y = rect.top;
    data.x = rect.left;
    data.style = dwStyle;
    data.lpszName = lpszWindowName;
    data.lpszClass = lpszClassName;
    data.dwExStyle = dwExStyle;

    OnCreate(&data);

    return TRUE;
}


BOOL CMDIChildWnd::SetMenu(CMenu* pMenu)
{
    QMenuBar *menuBar = (QMenuBar *)pMenu->GetNSMenu();

    if (m_hWnd && menuBar)
    {
        QMdiSubWindow *subWindow = (QMdiSubWindow *)m_hWnd;

        QMainWindow *mainWindow = (QMainWindow *)subWindow->widget();

        mainWindow->setMenuBar(menuBar);
        mainWindow->setMenuWidget((QWidget *)menuBar);

        return TRUE;
    }

    mMenu.SetNSMenu(menuBar, this);

    return FALSE;
}

