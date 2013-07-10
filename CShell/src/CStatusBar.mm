/*
 *  CStatusBar.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CStatusBar.h"

CStatusBar::CStatusBar() : CWnd()
{
	
}

CStatusBar::~CStatusBar()
{

}

BOOL CStatusBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
	NSLog(@"TO DO CStatusBar::Create");
	return TRUE;
}

BOOL CStatusBar::CreateEx(CWnd* pParentWnd, DWORD dwCtrlStyle, DWORD dwStyle, UINT nID)
{
	NSLog(@"TO DO CStatusBar::CreateEx");
	return TRUE;				  
}

BOOL CStatusBar::SetIndicators(const UINT* lpIDArray, int nIDCount)
{
	NSLog(@"TO DO CStatusBar::SetIndicators");
	return TRUE;
}

void CStatusBar::SetPaneInfo(int nIndex, UINT nID, UINT nStyle, int cxWidth)
{
	NSLog(@"TO DO CStatusBar::SetPaneInfo");
}

BOOL CStatusBar::SetPaneText(int nIndex, LPCTSTR lpszNewText, BOOL bUpdate )
{
	NSLog(@"TO DO CStatusBar::SetPaneText");
	return TRUE;
}

void CStatusBar::SetPaneStyle(int nIndex, UINT nStyle)
{
	NSLog(@"TO DO CStatusBar::SetPaneStyle");
}

DWORD CStatusBar::GetBarStyle()
{
	NSLog(@"TO DO CStatusBar::CStatusBar");
	return 0;
}


