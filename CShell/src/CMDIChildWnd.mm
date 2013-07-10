/*
 *  CMDIChildWnd.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#include "CWinApp.h"
#include "CDocument.h"

#import "CNSView.h"
#import "CNSWindow.h"
#import "CNSWindowHandle.h"
#import "CNSWindowDelegate.h"

#include "CMDIChildWnd.h"

IMPLEMENT_DYNAMIC(CMDIChildWnd, CFrameWnd)

CMDIChildWnd::CMDIChildWnd()
{
	
}

CMDIChildWnd::~CMDIChildWnd()
{

}

BOOL CMDIChildWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
					DWORD dwStyle,
					const RECT& rect,
					CWnd* pParentWnd,
					LPCTSTR lpszMenuName,
					DWORD dwExStyle,
					CCreateContext* pContext)
{
	return CFrameWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, lpszMenuName, dwExStyle, pContext);
}

BOOL CMDIChildWnd::SetMenu(CMenu* pMenu)
{
	return CWnd::SetMenu(pMenu);
}

