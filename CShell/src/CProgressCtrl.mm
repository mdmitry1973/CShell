/*
 *  CProgressCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CProgressCtrl.h"

#import "CNSProgressIndicator.h"

CProgressCtrl::CProgressCtrl() : CWnd()
{
	
}

BOOL CProgressCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CreateEx(0, dwStyle, rect, pParentWnd, nID);
}

BOOL CProgressCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	CNSProgressIndicator *control = [[[CNSProgressIndicator alloc] initWithFrame: contentRect] autorelease];
	
	[control setIndeterminate: false];
	[control setTag:nID];
	
	NSObject *parentView = (NSObject *)pParentWnd->GetNSWindow();
	NSView	*pView = nil;
	
	if ([parentView isKindOfClass:[NSView class]])
	{
		pView = (NSView *)parentView;
	}
	else 
	if ([parentView isKindOfClass:[NSWindow class]])
	{
		pView = [(NSWindow *)parentView contentView];
	}
	else
	{
		assert(false);
	}

	[pView addSubview: control];
	
	m_hWnd = control;
	mParentWin = pParentWnd;	
	
	return TRUE;
}

void CProgressCtrl::SetRange(short nLower, short nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSProgressIndicator *)m_hWnd) setMinValue: nLower];
		[((NSProgressIndicator *)m_hWnd) setMaxValue: nUpper];
	}
}

void CProgressCtrl::SetRange32(int nLower, int nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSProgressIndicator *)m_hWnd) setMinValue: nLower];
		[((NSProgressIndicator *)m_hWnd) setMaxValue: nUpper];
	}
}

int CProgressCtrl::SetPos(int nPos)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSProgressIndicator *)m_hWnd) setDoubleValue:nPos];
		return [((NSProgressIndicator *)m_hWnd) doubleValue];
	}
	
	return 0;
}

int CProgressCtrl::GetPos()
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((NSProgressIndicator *)m_hWnd) doubleValue];
	}
	
	return 0;
}
