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

#include "CDef.h"
#include "afxext.h"
#include "CWnd.h"
#include "CToolBar.h"
#include "CMenu.h"

typedef CToolBar CControlBar;

/////////////////////////////////////////////////////////////////////////////
// CFrameWnd - base class for SDI and other frame windows

// Frame window styles
#define FWS_ADDTOTITLE  0x00008000L // modify title based on content
#define FWS_PREFIXTITLE 0x00004000L // show document name before app name
#define FWS_SNAPTOBARS  0x00002000L // snap size to size of contained bars

// Frame window menu bar visibility styles
#define AFX_MBV_KEEPVISIBLE    0x01L // always visible
#define AFX_MBV_DISPLAYONFOCUS 0x02L // toggle state on ALT
#define AFX_MBV_DISPLAYONF10   0x04L // display on F10

// Frame window menu bar visibility states
#define AFX_MBS_VISIBLE 0x01L // visible
#define AFX_MBS_HIDDEN  0x02L // hidden

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
	
	virtual void RecalcLayout(BOOL bNotify = TRUE);
	
	void ShowControlBar(CControlBar* pBar, BOOL bShow, BOOL bDelay);
	
	DECLARE_DYNAMIC(CFrameWnd)
	
	//not mfc methods
	
	CString m_strTitle;         // default title (original)
	
	

};

#endif//CFRAMEWND_DEFINE
