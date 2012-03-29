/*
 *  CEdit.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CEdit.h"

#include "CNSTextField.h"

CEdit::CEdit() : CWnd()
{
	
}

CEdit::~CEdit()
{

}

BOOL CEdit::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	CNSTextField *control = [[[CNSTextField alloc] initWithFrame: contentRect] autorelease];
	
	[control setBezeled:YES];
	[control setDrawsBackground:YES];
	[control setEditable:YES];
	[control setSelectable:YES];
	
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

DWORD CEdit::GetSel() const
{
	int nStartChar; 
	int nEndChar;
	DWORD res = 0;
	
	GetSel(nStartChar, nEndChar);
	
	res = (short)nStartChar;
	res = ((short)nEndChar << 16) | res;
	
	return res;
}

void CEdit::GetSel(int& nStartChar, int& nEndChar) const
{
	if (m_hWnd)
	{
		NSRange range = [[((CNSTextField *)m_hWnd) currentEditor] selectedRange];
		
		nStartChar = range.location;
		nEndChar = range.location + range.length;
	}
}

void CEdit::SetSel(DWORD dwSelection, BOOL bNoScroll)
{
	if (m_hWnd)
	{
		NSRange range = { 0, dwSelection };
		
		[[((CNSTextField *)m_hWnd) currentEditor] setSelectedRange: range];
	}
}

void CEdit::SetSel(int nStartChar, int nEndChar, BOOL bNoScroll)
{
	if (m_hWnd)
	{
		NSRange range = { nStartChar, nEndChar };
		
		if (nEndChar == -1)
		{
			range.length = [[((CNSTextField *)m_hWnd) stringValue] length];
		}
		
		[[((CNSTextField *)m_hWnd) currentEditor] setSelectedRange: range];
	}
}

void CEdit::SetLimitText(UINT nMax)
{
	NSLog(@"TO DO CEdit::SetLimitText");
}

BOOL CEdit::SetCueBanner(LPCWSTR lpcwText)
{
	NSLog(@"TO DO CEdit::SetLimitText");
	
	return TRUE;
}

void CEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		NSRange range;
		
		range = [[((CNSTextField *)m_hWnd) currentEditor] selectedRange];
		[[((CNSTextField *)m_hWnd) currentEditor] replaceCharactersInRange:range
													withString:[NSString stringWithFormat: @"%c", nChar]];
		[((CNSTextField *)m_hWnd) setSkipChar: true];
	}
}

