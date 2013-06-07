/*
 *  CStatusBar.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CSTATUSBAR_DEFINE
#define CSTATUSBAR_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CStatusBar : public CWnd
{
	
public:
	
	CStatusBar();
	
	virtual ~CStatusBar();
	
	virtual BOOL Create(CWnd* pParentWnd,
						DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
						UINT nID = AFX_IDW_STATUS_BAR);
						
	virtual BOOL CreateEx(CWnd* pParentWnd,
						  DWORD dwCtrlStyle = 0 ,
						  DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_BOTTOM,
						  UINT nID = AFX_IDW_STATUS_BAR);
						  
	BOOL SetIndicators(const UINT* lpIDArray, int nIDCount);
	
};


#endif//CSTATUSBAR_DEFINE