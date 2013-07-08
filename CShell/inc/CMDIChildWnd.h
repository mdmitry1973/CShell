/*
 *  CMDIChildWnd.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CMDICHILDWND_DEFINE
#define CMDICHILDWND_DEFINE 1

#include "CDef.h"
#include "CFrameWnd.h"

class CSHELL_LIB_EXPORT CMDIChildWnd : public CFrameWnd
{
	
public:
	
	CMDIChildWnd();
	
	virtual ~CMDIChildWnd();

    virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
                        DWORD dwStyle = WS_OVERLAPPEDWINDOW,
                        const RECT& rect = rectDefault,
                        CWnd* pParentWnd = NULL,
                        LPCTSTR lpszMenuName = NULL,
                        DWORD dwExStyle = 0,
                        CCreateContext* pContext = NULL);

    virtual BOOL SetMenu(CMenu* pMenu);
	
	DECLARE_DYNAMIC(CMDIChildWnd)
};

#define CMDIChildWndEx CMDIChildWnd


#endif//CMDICHILDWND_DEFINE
