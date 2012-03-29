/*
 *  CComboBox.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/12/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CComboBox.h"

#import "CNSPopUpButton.h"

CComboBox::CComboBox() : CWnd()
{
	type = eNSPopUpButton;
}

BOOL CComboBox::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	CNSPopUpButton *control = [[[CNSPopUpButton alloc] initWithFrame: contentRect] autorelease];
	
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

int CComboBox::AddString(LPCTSTR lpszString)
{
	int index = CB_ERR;
	
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		if (type == eNSPopUpButton)
		{
			[(NSPopUpButton *)m_hWnd addItemWithTitle:[NSString stringWithUTF8String: lpszString]];
			
			index = [(NSPopUpButton *)m_hWnd numberOfItems];
		}
		else
		{
			[(NSComboBox *)m_hWnd addItemWithObjectValue:[NSString stringWithUTF8String: lpszString]];
			
			index = [(NSComboBox *)m_hWnd numberOfVisibleItems];
		}
	}
	
	return index;
}

int CComboBox::GetCount() const
{
	int res = 0;
	
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		if (type == eNSPopUpButton)
		{
			res = [(NSPopUpButton *)m_hWnd numberOfItems];
		}
		else
		{
			res = [(NSComboBox *)m_hWnd numberOfItems];
		}
	}
	
	return res;
}

int CComboBox::GetCurSel() const
{
	int res = 0;
	
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		if (type == eNSPopUpButton)
		{
			res = [(NSPopUpButton *)m_hWnd indexOfSelectedItem];
		}
		else
		{
			res = [(NSComboBox *)m_hWnd indexOfSelectedItem];
		}
	}
	
	return res;
}

int CComboBox::SetCurSel(int nSelect)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		if (type == eNSPopUpButton)
		{
			[(NSPopUpButton *)m_hWnd selectItemAtIndex: nSelect];
		}
		else
		{
			[(NSComboBox *)m_hWnd selectItemAtIndex: nSelect];
		}
	}
	
	return GetCurSel();
}

int CComboBox::SelectString(int nStartAfter, LPCTSTR lpszString)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		int count = GetCount();
		int start = nStartAfter != -1 ? nStartAfter : 0;
		CString rString;
		
		for(int i = start; i < count; i++)
		{
			GetLBText(i, rString);
			
			if (rString == lpszString)
			{
				SetCurSel(i);
				return i;
			}
		}
	}
	
	return CB_ERR;
}

int CComboBox::InsertString(int nIndex, LPCTSTR lpszString)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		if (type == eNSPopUpButton)
		{
			[(NSPopUpButton *)m_hWnd insertItemWithTitle:[NSString stringWithUTF8String: lpszString] atIndex:nIndex];
		}
		else
		{
			[(NSComboBox *)m_hWnd insertItemWithObjectValue:[NSString stringWithUTF8String: lpszString] atIndex:nIndex];
		}
		
		return nIndex + 1;
	}
	
	return CB_ERR;
}

int CComboBox::GetLBText(int nIndex, LPTSTR lpszText) const
{
	CString rString;
	
	GetLBText(nIndex, rString);
	
	strcpy(lpszText, rString.c_str());
	
	return rString.length();
}

void CComboBox::GetLBText(int nIndex, CString& rString) const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		if (type == eNSPopUpButton)
		{
			NSString *str = [(NSPopUpButton *)m_hWnd itemTitleAtIndex: nIndex];
			rString = [str UTF8String];
		}
		else
		{
			NSObject *obj = [(NSComboBox *)m_hWnd itemObjectValueAtIndex: nIndex];
			
			if ([obj isKindOfClass: [NSString class]])
			{
				rString = [(NSString *)obj UTF8String];
			}
		}
	}
}

int CComboBox::GetLBTextLen(int nIndex) const
{
	NSString *str = nil;
	
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		if (type == eNSPopUpButton)
		{
			str = [(NSPopUpButton *)m_hWnd itemTitleAtIndex: nIndex];
		}
		else
		{
			str = [(NSComboBox *)m_hWnd itemObjectValueAtIndex: nIndex];
			
			if (![str isKindOfClass: [NSString class]])
			{
				str = nil;
			}
		}
	}
	
	if (str)
	{
		return [str length];
	}
	
	return 0;
}

