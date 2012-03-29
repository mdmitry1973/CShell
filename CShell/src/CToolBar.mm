/*
 *  CToolBar.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CToolBar.h"


CToolBar::CToolBar() : CWnd()
{
	
}

CToolBar::~CToolBar()
{

}

BOOL CToolBar::Create(CWnd* pParentWnd, DWORD dwStyle, UINT nID)
{
	NSLog(@"TO DO CToolBar::Create");
	return TRUE;
}

BOOL CToolBar::CreateEx(CWnd* pParentWnd, DWORD dwCtrlStyle, DWORD dwStyle, CRect rcBorders, UINT nID)
{	
	NSLog(@"TO DO CToolBar::CreateEx");
	return TRUE;
}

BOOL CToolBar::LoadToolBar(LPCTSTR lpszResourceName)
{
	NSLog(@"TO DO CToolBar::LoadToolBar");
	return TRUE;
}

BOOL CToolBar::LoadToolBar(UINT nIDResource)
{
	NSLog(@"TO DO CToolBar::LoadToolBar");
	return TRUE;
}

void CToolBar::EnableDocking(DWORD dwDockStyle)
{
	NSLog(@"TO DO CToolBar::EnableDocking");
}
