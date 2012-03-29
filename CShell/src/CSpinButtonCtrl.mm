/*
 *  CSpinButtonCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CSpinButtonCtrl.h"

#import "CNSStepper.h"

CSpinButtonCtrl::CSpinButtonCtrl() : CWnd()
{
	m_pWndBuddy = 0;
}

BOOL CSpinButtonCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CreateEx(0, dwStyle, rect, pParentWnd, nID);
}

BOOL CSpinButtonCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	CNSStepper *control = [[[CNSStepper alloc] initWithFrame: contentRect] autorelease];
	
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

void CSpinButtonCtrl::SetRange(short nLower, short nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSStepper *)m_hWnd) setMinValue: nLower];
		[((NSStepper *)m_hWnd) setMaxValue: nUpper];
	}
}

void CSpinButtonCtrl::SetRange32(int nLower, int nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSStepper *)m_hWnd) setMinValue: nLower];
		[((NSStepper *)m_hWnd) setMaxValue: nUpper];
	}
}

int CSpinButtonCtrl::GetPos() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

int CSpinButtonCtrl::GetPos32(LPBOOL lpbError ) const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

int CSpinButtonCtrl::SetPos(int nPos )
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSStepper *)m_hWnd) setIntValue:nPos];
		return [((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

int CSpinButtonCtrl::SetPos32(int nPos )
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((NSStepper *)m_hWnd) setIntValue:nPos];
		return [((NSStepper *)m_hWnd) intValue];
	}
	
	return 0;
}

CWnd* CSpinButtonCtrl::GetBuddy() const
{
	return m_pWndBuddy;
}

CWnd* CSpinButtonCtrl::SetBuddy(CWnd* pWndBuddy )
{
	m_pWndBuddy = pWndBuddy;
	
	return m_pWndBuddy;
}
