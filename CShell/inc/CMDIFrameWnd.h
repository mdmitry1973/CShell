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

#include "CWnd.h"
#include "CFrameWnd.h"

class CMDIFrameWnd : public CFrameWnd
{

public:
	
	CMDIFrameWnd();
	
	virtual ~CMDIFrameWnd();
	
	virtual BOOL CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu );
	
	//CMDIChildWnd* CreateNewChild(
	//							 CRuntimeClass* pClass,
	//							 UINT nResource,
	//							 HMENU hMenu = NULL,
	//							 HACCEL hAccel = NULL
	//							 );
	
	virtual HMENU GetWindowMenuPopup(HMENU hMenuBar);
	
	void MDINext();
	void MDIPrev();
	
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

};

#define CMDIFrameWndEx CMDIFrameWnd

#endif//CMDIFRAMEWND_DEFINE