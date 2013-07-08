/*
 *  CToolBar.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CToolBar.h"

CToolBar::CToolBar() : CWnd()
{
	
}

CToolBar::~CToolBar()
{

}

BOOL CToolBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
    qDebug() << "TO DO CToolBar::Create";
	return TRUE;
}

BOOL CToolBar::CreateEx(CWnd* pParentWnd, DWORD dwCtrlStyle, DWORD dwStyle, CRect rcBorders, UINT nID)
{	
    qDebug() << "TO DO CToolBar::CreateEx";
	return TRUE;
}

BOOL CToolBar::LoadToolBar(LPCTSTR lpszResourceName)
{
    qDebug() << "TO DO CToolBar::LoadToolBar";
	return TRUE;
}

BOOL CToolBar::LoadToolBar(UINT nIDResource)
{
    qDebug() << "TO DO CToolBar::LoadToolBar";
	return TRUE;
}

void CToolBar::EnableDocking(DWORD dwDockStyle)
{
    qDebug() << "TO DO CToolBar::EnableDocking";
}


void CToolBar::OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler)
{
    qDebug() << "TO DO CToolBar::OnUpdateCmdUI";
}

DWORD CToolBar::GetBarStyle()
{
    qDebug() << "TO DO CToolBar::EnableDocking";
}

void CToolBar::SetBarStyle(DWORD dwStyle)
{
    qDebug() << "TO DO CToolBar::SetBarStyle";
}

UINT CToolBar::GetItemID(int nIndex) const
{
    qDebug() << "TO DO CToolBar::GetItemID";
}

void CToolBar::GetItemRect(int nIndex, LPRECT lpRect) const
{
    qDebug() << "TO DO CToolBar::GetItemRect";
}

UINT CToolBar::GetButtonStyle(int nIndex) const
{
    qDebug() << "TO DO CToolBar::GetButtonStyle";
}

void CToolBar::SetButtonStyle(int nIndex, UINT nStyle)
{
    qDebug() << "TO DO CToolBar::SetButtonStyle";
}

CToolBarCtrl& CToolBar::GetToolBarCtrl() const
{
    qDebug() << "TO DO CToolBar::GetToolBarCtrl";
}
