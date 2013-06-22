/*
 *  COleResizeBar.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef COLERESIZEBAR_DEFINE
#define COLERESIZEBAR_DEFINE 1

class CWnd;

class COleResizeBar
{

public:
	
	COleResizeBar();
	virtual ~COleResizeBar();
	
	virtual BOOL Create(CWnd* pParentWnd, DWORD dwStyle = WS_CHILD | WS_VISIBLE,
						UINT nID = AFX_IDW_RESIZE_BAR);
};

#endif//COLERESIZEBAR_DEFINE