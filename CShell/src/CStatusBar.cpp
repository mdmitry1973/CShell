/*
 *  CStatusBar.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QStatusBar>
#include <QMainWindow>

#include "CStatusBar.h"

CStatusBar::CStatusBar() : CWnd()
{
	
}

CStatusBar::~CStatusBar()
{

}

BOOL CStatusBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
    QWidget *parent = NULL;

    if (pParentWnd)
    {
        parent = (QWidget *)pParentWnd->GetNSWindow();
    }

    QStatusBar *statusBar = new QStatusBar(parent);

    statusBar->setAccessibleName(QString().setNum(nID));

    QMainWindow *mainWnd = dynamic_cast<QMainWindow *>(parent);

    if (mainWnd)
    {
        mainWnd->setStatusBar(statusBar);
        statusBar->showMessage("Ready");
    }

    m_hWnd = statusBar;
    mParentWin = pParentWnd;

    return TRUE;
}

BOOL CStatusBar::CreateEx(CWnd* pParentWnd, DWORD dwCtrlStyle, DWORD dwStyle, UINT nID)
{
    BOOL res = Create(pParentWnd, dwStyle, nID);
    QStatusBar *statusBar = (QStatusBar *)m_hWnd;

    return res;
}

BOOL CStatusBar::SetIndicators(const UINT* lpIDArray, int nIDCount)
{
    qDebug() << "TO DO CStatusBar::SetIndicators";
	return TRUE;
}
