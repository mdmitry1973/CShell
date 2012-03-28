/*
 *  CToolBar.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CTOOLBAR_DEFINE
#define CTOOLBAR_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CToolBar : public CWnd
{
	
public:
	
	CToolBar();
	
	virtual ~CToolBar();
	
	virtual BOOL Create(CWnd* pParentWnd,
						DWORD dwStyle = WS_CHILD |  WS_VISIBLE | CBRS_TOP,
						UINT nID = AFX_IDW_TOOLBAR);
						
	virtual BOOL CreateEx( CWnd* pParentWnd,
						  DWORD dwCtrlStyle = TBSTYLE_FLAT,
						  DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP,
						  CRect rcBorders = CRect(
												  0,
												  0,
												  0,
												  0
												  ),
						  UINT nID = AFX_IDW_TOOLBAR);
						  
	BOOL LoadToolBar(LPCTSTR lpszResourceName);
	BOOL LoadToolBar(UINT nIDResource);
	
	//CControlBar
	void EnableDocking(DWORD dwDockStyle);
	
};


#endif//CTOOLBAR_DEFINE