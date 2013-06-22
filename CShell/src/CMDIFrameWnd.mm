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
#include "CFrameWnd.h"
#include "CMDIChildWnd.h"

#import "CNSDocument.h"

IMPLEMENT_DYNAMIC(CMDIFrameWnd, CFrameWnd)

CMDIFrameWnd::CMDIFrameWnd()
{
	
}

CMDIFrameWnd::~CMDIFrameWnd()
{
	
}

BOOL CMDIFrameWnd::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd , CCreateContext* pContext)
{
	CString strResID;
	
	strResID = strResID.Format("%d", nIDResource);
	
	if (mMenu.LoadMenu(strResID))
	{
		SetMenu(&mMenu);
	}
	
	return TRUE;
}


BOOL CMDIFrameWnd::CreateClient(LPCREATESTRUCT lpCreateStruct, CMenu* pWindowMenu )
{
	NSLog(@"to do CMDIFrameWnd::CreateClient");
	
	return FALSE;
}

BOOL CMDIFrameWnd::ShowWindow(int nCmdShow)
{
	NSLog(@"to do CMDIFrameWnd::ShowWindow");
	
	return FALSE;
}

HMENU CMDIFrameWnd::GetWindowMenuPopup(HMENU hMenuBar)
{
	NSLog(@"to do CMDIFrameWnd::GetWindowMenuPopup");
	
	return NULL;
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
	
	return FALSE;
}

CMDIChildWnd* CMDIFrameWnd::MDIGetActive(BOOL* pbMaximized ) const
{
	NSDocumentController *docManager = [NSDocumentController sharedDocumentController];
	
	CNSDocument  *doc = [docManager currentDocument];
	
	if (doc)
	{
		return (CMDIChildWnd*)[doc getFrame];
	}
	
	return 0;
}
