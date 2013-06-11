/*
 *  CFrameWnd.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "afxext.h"

#include "CWinApp.h"

#import "CNSView.h"
#import "CNSWindow.h"
#import "CNSWindowHandle.h"
#import "CNSWindowDelegate.h"

#include "CView.h"
#include "CDocument.h"
#include "CFrameWnd.h"

const CRect CFrameWnd::rectDefault = CRect(100, 100, 600, 500);

IMPLEMENT_DYNAMIC(CFrameWnd, CWnd)

CFrameWnd::CFrameWnd() : CWnd()
{

}

BOOL CFrameWnd::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
					DWORD dwStyle,
					const RECT& rect,
					CWnd* pParentWnd,
					LPCTSTR lpszMenuName,
					DWORD dwExStyle,
					CCreateContext* pContext)
{
	
	NSRect contentRect;
	NSBackingStoreType bufferingType = NSBackingStoreBuffered;
	NSUInteger windowStyle = NSBorderlessWindowMask;	
	NSScreen *screen = [NSScreen mainScreen];
	NSRect screenRect = [screen frame];
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = (screenRect.size.height/2) - rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	if (dwStyle & WS_OVERLAPPED)
	{

	}

	if (dwStyle & WS_POPUP)
	{

	}

	if (dwStyle & WS_CHILD)
	{
		
	}

	if (dwStyle & WS_MINIMIZE)
	{
		windowStyle = windowStyle | NSMiniaturizableWindowMask;
	}

	if (dwStyle & WS_VISIBLE)
	{

	}

	if (dwStyle & WS_DISABLED)
	{

	}

	if (dwStyle & WS_CLIPSIBLINGS)
	{

	}

	if (dwStyle & WS_CLIPCHILDREN)
	{

	}

	if (dwStyle & WS_MAXIMIZE)
	{

	}

	if (dwStyle & WS_CAPTION) /* WS_BORDER | WS_DLGFRAME */
	{
		windowStyle = windowStyle | NSTitledWindowMask;
		windowStyle = windowStyle & ~NSBorderlessWindowMask;
	}
	
	if (dwStyle & WS_BORDER)
	{
		windowStyle = windowStyle & ~NSBorderlessWindowMask;
	}

	if (dwStyle & WS_DLGFRAME)
	{
		
	}

	if (dwStyle & WS_VSCROLL)
	{
		
	}

	if (dwStyle & WS_HSCROLL)
	{
		
	}

	if (dwStyle & WS_SYSMENU)
	{
		windowStyle = windowStyle | NSClosableWindowMask;
		windowStyle = windowStyle | NSTitledWindowMask;
		windowStyle = windowStyle | NSMiniaturizableWindowMask;
	}

	if (dwStyle & WS_THICKFRAME)
	{
		
	}

	if (dwStyle & WS_GROUP)
	{
		
	}

	if (dwStyle & WS_TABSTOP)
	{
		
	}

	if (dwStyle & WS_MINIMIZEBOX)
	{
		windowStyle = windowStyle | NSResizableWindowMask;
	}

	if (dwStyle & WS_MAXIMIZEBOX)
	{
		windowStyle = windowStyle | NSResizableWindowMask;
	}
			
	m_hWnd = [[CNSWindow alloc] initWithContentRect:contentRect styleMask:windowStyle backing:bufferingType defer:YES];
	[(CNSWindow *)m_hWnd setContentView: [[[CNSView alloc] initWithFrame: contentRect] autorelease]];
	mMainWindow = TRUE;
	[(CNSWindow *)m_hWnd setParentWnd:nil];
	
	if (lpszWindowName)
	{
		[(CNSWindow *)m_hWnd setTitle: [NSString stringWithUTF8String: lpszWindowName]];
	}
	
	mWindowHandle = [[CNSWindowHandle alloc] init];
	[(CNSWindowHandle *)mWindowHandle setCWnd: this];
	
	mWindowDelegate = [[CNSWindowDelegate alloc] init];
	[(CNSWindowDelegate *)mWindowDelegate setCWnd: this];
	[(CNSWindow *)m_hWnd setDelegate: (CNSWindowDelegate *)mWindowDelegate];
	
	mWindowController = [[NSWindowController alloc] initWithWindow: (NSWindow *)m_hWnd];
	
	if (!mWindowController)
	{
		assert(false);
	}
	
	NSDocument *doc = (NSDocument *)pContext->m_pCurrentDoc->GetNSDoc();
	
	[doc addWindowController: (NSWindowController *)mWindowController];
	
	if (m_menuBar.LoadMenu(lpszMenuName))
	{
		[NSApp setMenu: (NSMenu *)(m_menuBar.GetNSMenu())];
	}
	
	return TRUE;				
}

CFrameWnd::~CFrameWnd()
{

}

BOOL CFrameWnd::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{
	NSLog(@"TO DO CFrameWnd::LoadFrame");
	
	/*
	// only do this once
	ASSERT_VALID_IDR(nIDResource);
	ASSERT(m_nIDHelp == 0 || m_nIDHelp == nIDResource);
	
	m_nIDHelp = nIDResource;    // ID for help context (+HID_BASE_RESOURCE)
	*/
	
	CString strFullString;
	if (strFullString.LoadString(nIDResource))
	{
		int pos = strFullString.Find("\n");
		
		if (pos != -1)
		{
			strFullString = strFullString.Mid(0, pos); 
		}
		
		//AfxExtractSubString(m_strTitle, strFullString, 0);    // first sub-string
	}
	
	//VERIFY(AfxDeferRegisterClass(AFX_WNDFRAMEORVIEW_REG));
	
	// attempt to create the window
	//LPCTSTR lpszClass = GetIconWndClass(dwDefaultStyle, nIDResource);
	CString strClass;
	CString strTitle = strFullString;
	CString strResID;
	strResID = strResID.Format("%d", nIDResource);
	if (!Create(strClass, strTitle, dwDefaultStyle, rectDefault,
				pParentWnd, strResID, 0, pContext))
	{
		return FALSE;   // will self destruct on failure normally
	}
	
	
	
	// save the default menu handle
	//ASSERT(m_hWnd != NULL);
	//m_hMenuDefault = ::GetMenu(m_hWnd);
	
	// load accelerator resource
	//LoadAccelTable(MAKEINTRESOURCE(nIDResource));
	
	//if (pContext == NULL)   // send initial update
	//	SendMessageToDescendants(WM_INITIALUPDATE, 0, 0, TRUE, TRUE);
	
	SetMessageMap();
	
	CView *view = (CView *)(pContext->m_pNewViewClass->CreateObject());
	
	pContext->m_pCurrentDoc->AddView(view);
	
	return TRUE;
}

void CFrameWnd::EnableDocking(DWORD dwDockStyle)
{
	NSLog(@"TO DO CFrameWnd::EnableDocking");
}

void CFrameWnd::DockControlBar(CControlBar* pBar, UINT nDockBarID, LPCRECT lpRect)
{
	NSLog(@"TO DO CFrameWnd::DockControlBar");
}

BOOL CFrameWnd::ShowWindow(int nCmdShow)
{
	if (nCmdShow == SW_SHOWNORMAL)
	{
		[(CNSWindow *)m_hWnd  makeKeyAndOrderFront:(CNSWindow *)m_hWnd];
		//[mWindowController showWindow:nil];
	}
	else 
	{
		
			
	}
	
	return TRUE;
}

void CFrameWnd::RecalcLayout(BOOL bNotify)
{
	NSLog(@"TO DO CFrameWnd::RecalcLayout");
}
