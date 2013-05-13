/*
 *  CFrameWnd.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CFRAMEWND_DEFINE
#define CFRAMEWND_DEFINE 1

#include "CWnd.h"
#include "CToolBar.h"

typedef CToolBar CControlBar;

class CFrameWnd : public CWnd
{

public:
	
	CFrameWnd();
	
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
						DWORD dwStyle = WS_OVERLAPPEDWINDOW,
						const RECT& rect = rectDefault,
						CWnd* pParentWnd = NULL,
						LPCTSTR lpszMenuName = NULL,
						DWORD dwExStyle = 0,
						CCreateContext* pContext = NULL); 
	
	virtual ~CFrameWnd();
	
	static const CRect rectDefault;
	
	void EnableDocking(DWORD dwDockStyle);
					   
	void DockControlBar(CControlBar* pBar, UINT nDockBarID = 0, LPCRECT lpRect = NULL);
	
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
	
	virtual BOOL ShowWindow(int nCmdShow);
	
	//not mfc methods
	
	CString m_strTitle;         // default title (original)

};

#endif//CFRAMEWND_DEFINE