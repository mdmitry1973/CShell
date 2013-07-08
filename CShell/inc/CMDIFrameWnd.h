/*
 *  CMDIFrameWnd.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CMDIFRAMEWND_DEFINE
#define CMDIFRAMEWND_DEFINE 1

#include "CDef.h"

#include "CWnd.h"
#include "CFrameWnd.h"

//virtual class only for menu and toll bar

class CMDIChildWnd;

class CSHELL_LIB_EXPORT CMDIFrameWnd : public CFrameWnd
{

public:
	
	CMDIFrameWnd();
	
	virtual ~CMDIFrameWnd();

    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                        DWORD dwStyle = WS_OVERLAPPEDWINDOW,
                        const RECT& rect = rectDefault,
                        CWnd* pParentWnd = NULL,
                        LPCTSTR lpszMenuName = NULL,
                        DWORD dwExStyle = 0,
                        CCreateContext* pContext = NULL);
	
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
	
	virtual BOOL CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu );
	
	virtual BOOL ShowWindow(int nCmdShow);
	
	//CMDIChildWnd* CreateNewChild(
	//							 CRuntimeClass* pClass,
	//							 UINT nResource,
	//							 HMENU hMenu = NULL,
	//							 HACCEL hAccel = NULL
	//							 );
	
	virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);
	
	void MDINext();
	void MDIPrev();
	
	CMDIChildWnd* MDIGetActive(BOOL* pbMaximized = NULL) const;
	
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	DECLARE_DYNAMIC(CMDIFrameWnd)

};

#define CMDIFrameWndEx CMDIFrameWnd

#endif//CMDIFRAMEWND_DEFINE
