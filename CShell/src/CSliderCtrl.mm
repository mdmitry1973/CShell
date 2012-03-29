/*
 *  CSliderCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CSliderCtrl.h"

#import "CNSSlider.h"

CSliderCtrl::CSliderCtrl() : CWnd()
{
	
}

BOOL CSliderCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CreateEx(0, dwStyle, rect, pParentWnd, nID);
}

BOOL CSliderCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	CNSSlider *control = [[[CNSSlider alloc] initWithFrame: contentRect] autorelease];
	
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
	
	[control setParentWnd:pParentWnd];
	
	m_hWnd = control;
	mParentWin = pParentWnd;
	
	return TRUE;
}

void CSliderCtrl::SetRange(short nLower, short nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSSlider *)m_hWnd) setMinValue: nLower];
		[((NSSlider *)m_hWnd) setMaxValue: nUpper];
	}
}

void CSliderCtrl::SetRange32(int nLower, int nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSSlider *)m_hWnd) setMinValue: nLower];
		[((NSSlider *)m_hWnd) setMaxValue: nUpper];
	}
}

int CSliderCtrl::SetPos(int nPos)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSSlider *)m_hWnd) setIntValue:nPos];
		return [((NSSlider *)m_hWnd) intValue];
	}
	
	return 0;
}

int CSliderCtrl::GetPos()
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((NSSlider *)m_hWnd) intValue];
	}
	
	return 0;
}
