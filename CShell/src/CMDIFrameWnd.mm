/*
 *  CMDIFrameWnd.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CMDIFrameWnd.h"

CMDIFrameWnd::CMDIFrameWnd()
{
	
}

CMDIFrameWnd::~CMDIFrameWnd()
{
	
}

BOOL CMDIFrameWnd::CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu )
{
	
}

HMENU CMDIFrameWnd::GetWindowMenuPopup(HMENU hMenuBar)
{
	NSLog(@"to do CMDIFrameWnd::GetWindowMenuPopup");
}

void CMDIFrameWnd::MDINext()
{
	NSLog(@"to do CMDIFrameWnd::MDINext");
}

void CMDIFrameWnd::MDIPrev()
{
	NSLog(@"to do CMDIFrameWnd::MDIPrev");
}

BOOL CMDIFrameWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	NSLog(@"to do CMDIFrameWnd::PreCreateWindow");
}
