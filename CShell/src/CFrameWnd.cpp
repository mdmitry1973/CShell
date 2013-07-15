/*
 *  CFrameWnd.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QFrame>
#include <QMainWindow>

#include "afxext.h"

#include "CWinApp.h"
#include "CView.h"
#include "CDocument.h"
#include "CFrameWnd.h"

const CRect CFrameWnd::rectDefault = CRect(100, 100, 600, 500);

IMPLEMENT_DYNAMIC(CFrameWnd, CWnd)

CFrameWnd::CFrameWnd() : CWnd()
{

}

BOOL CFrameWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
					DWORD dwStyle,
					const RECT& rect,
					CWnd* pParentWnd,
					LPCTSTR lpszMenuName,
					DWORD dwExStyle,
					CCreateContext* pContext)
{
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

    m_hWnd = frame;
    mMainWindow = TRUE;

    if (pContext)
    {
        CDocument *doc = pContext->m_pCurrentDoc;

        if (doc)
        {

        }
    }

    //[doc addWindowController: (NSWindowController *)mWindowController];

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

CFrameWnd::~CFrameWnd()
{

}

BOOL CFrameWnd::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{
    qDebug() << "TO DO CFrameWnd::LoadFrame";
	
	/*
	// only do this once
	ASSERT_VALID_IDR(nIDResource);
	ASSERT(m_nIDHelp == 0 || m_nIDHelp == nIDResource);
	
	m_nIDHelp = nIDResource;    // ID for help context (+HID_BASE_RESOURCE)
	*/

	CString strFullString;
	if (strFullString.LoadString(nIDResource))
	{
        int pos = strFullString.Find(_T("\n"));
		
		if (pos != -1)
		{
			strFullString = strFullString.Mid(0, pos); 
		}
		
		//AfxExtractSubString(m_strTitle, strFullString, 0);    // first sub-string
	}

	//VERIFY(AfxDeferRegisterClass(AFX_WNDFRAMEORVIEW_REG));
	
	// attempt to create the window
	//LPCTSTR lpszClass = GetIconWndClass(dwDefaultStyle, nIDResource);
	CString strClass;
	CString strTitle = strFullString;
	CString strResID;
    strResID = strResID.Format(_T("%d"), nIDResource);
	if (!Create(strClass, strTitle, dwDefaultStyle, rectDefault,
				pParentWnd, strResID, 0, pContext))
	{
		return FALSE;   // will self destruct on failure normally
	}
	
	
	
	// save the default menu handle
	//ASSERT(m_hWnd != NULL);
	//m_hMenuDefault = ::GetMenu(m_hWnd);
	
	// load accelerator resource
	//LoadAccelTable(MAKEINTRESOURCE(nIDResource));
	
	//if (pContext == NULL)   // send initial update
	//	SendMessageToDescendants(WM_INITIALUPDATE, 0, 0, TRUE, TRUE);
	
	SetMessageMap();
	
    //CView *view = (CView *)(pContext->m_pNewViewClass->CreateObject());
	
    //pContext->m_pCurrentDoc->AddView(view);

	return TRUE;
}

void CFrameWnd::EnableDocking(DWORD dwDockStyle)
{
    qDebug() << "TO DO CFrameWnd::EnableDocking";
}

void CFrameWnd::DockControlBar(CControlBar* pBar, UINT nDockBarID, LPCRECT lpRect)
{
    qDebug() << "TO DO CFrameWnd::DockControlBar";
}

BOOL CFrameWnd::ShowWindow(int nCmdShow)
{
    QMainWindow *mainWindow = (QMainWindow *)m_hWnd;

	if (nCmdShow == SW_SHOWNORMAL)
	{
        mainWindow->show();
	}
	else 
	{
        mainWindow->close();
	}

	return TRUE;
}

void CFrameWnd::RecalcLayout(BOOL bNotify)
{
    qDebug() << "TO DO CFrameWnd::RecalcLayout";
}

void CFrameWnd::ShowControlBar(CControlBar* pBar, BOOL bShow, BOOL bDelay)
{
    qDebug() << "TO DO CFrameWnd::ShowControlBar";
}

BOOL CFrameWnd::SetMenu(CMenu* pMenu)
{
    QMenuBar *menuBar = (QMenuBar *)pMenu->GetNSMenu();

    if (m_hWnd && menuBar)
    {
        QMainWindow *mainWindow = (QMainWindow *)m_hWnd;

        mainWindow->setMenuBar(menuBar);
       // mainWindow->setMenuWidget((QWidget *)menuBar);

        return TRUE;
    }

    mMenu.SetNSMenu(menuBar, this);

    return FALSE;
}
