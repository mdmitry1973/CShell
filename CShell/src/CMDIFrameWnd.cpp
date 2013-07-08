/*
 *  CMDIFrameWnd.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QMainWindow>
#include <QMdiArea>

#include "CDef.h"

#include "CMDIFrameWnd.h"
#include "CFrameWnd.h"
#include "CMDIChildWnd.h"

IMPLEMENT_DYNAMIC(CMDIFrameWnd, CFrameWnd)

CMDIFrameWnd::CMDIFrameWnd()
{
	
}

CMDIFrameWnd::~CMDIFrameWnd()
{
	
}

BOOL CMDIFrameWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                    DWORD dwStyle, const RECT& rect,
                    CWnd* pParentWnd, LPCTSTR lpszMenuName, DWORD dwExStyle, CCreateContext* pContext)
{
    if (!CFrameWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd,  lpszMenuName,  dwExStyle, pContext))
    {
        qDebug() << "to do CFrameWnd::Create";
        return FALSE;
    }

    QMainWindow *mainWindow = (QMainWindow *)m_hWnd;
    QMdiArea *mdi = new QMdiArea(mainWindow);

    mainWindow->setCentralWidget(mdi);

    return TRUE;
}

BOOL CMDIFrameWnd::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd , CCreateContext* pContext)
{
	CString strResID;

    strResID = strResID.Format(_T("%d"), nIDResource);

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

    CString strClass;
    CString strTitle = strFullString;

    return Create(strClass, strTitle, dwDefaultStyle, rectDefault, pParentWnd, strResID, 0, pContext);
}


BOOL CMDIFrameWnd::CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu )
{
    qDebug() << "to do CMDIFrameWnd::CreateClient";
	
	return FALSE;
}

BOOL CMDIFrameWnd::ShowWindow(int nCmdShow)
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

HMENU CMDIFrameWnd::GetWindowMenuPopup(HMENU hMenuBar)
{
    qDebug() << "to do CMDIFrameWnd::GetWindowMenuPopup";
	
	return NULL;
}

void CMDIFrameWnd::MDINext()
{
    qDebug() << "to do CMDIFrameWnd::MDINext";
}

void CMDIFrameWnd::MDIPrev()
{
    qDebug() << "to do CMDIFrameWnd::MDIPrev";
}

BOOL CMDIFrameWnd::PreCreateWindow(CREATESTRUCT& cs)
{
    qDebug() << "to do CMDIFrameWnd::PreCreateWindow";
	
	return FALSE;
}

CMDIChildWnd* CMDIFrameWnd::MDIGetActive(BOOL* pbMaximized ) const
{
    qDebug() << "to do CMDIFrameWnd::MDIGetActive";

    //NSDocumentController *docManager = [NSDocumentController sharedDocumentController];
	
    //CNSDocument  *doc = [docManager currentDocument];
	
    //if (doc)
    //{
    //	return (CMDIChildWnd*)[doc getFrame];
    //}
	
	return 0;
}
