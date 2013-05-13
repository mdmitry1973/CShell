/*
 *  CListBox.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/12/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#include "CListBox.h"

#include "CNSTableView.h"

CListBox::CListBox() : CWnd()
{
	
}

BOOL CListBox::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	NSTableColumn *column = [[NSTableColumn alloc] initWithIdentifier: nil];
	CNSTableView *control = [[[CNSTableView alloc] initWithFrame: contentRect] autorelease];
	
	[control setDataSource: [[CNSTableViewDataSourceString alloc] init]];
	[control addTableColumn:column];
	
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

int CListBox::AddString(LPCTSTR lpszItem)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((CNSTableView *)m_hWnd) addItem:[NSString stringWithUTF8String: lpszItem]];
	}
	
	return LB_ERR;
}

int CListBox::InsertString(int nIndex, LPCTSTR lpszItem)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((CNSTableView *)m_hWnd) insertItem:[NSString stringWithUTF8String: lpszItem] index:nIndex];
	}
	
	return LB_ERR;
}

int CListBox::DeleteString(UINT nIndex)
{
	assert(m_hWnd);

	if (m_hWnd)
	{
		return [((CNSTableView *)m_hWnd) removeItem:nIndex];
	}

	return LB_ERR;
}

int CListBox::FindString(int nStartAfter, LPCTSTR lpszItem) const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((CNSTableView *)m_hWnd) findItem:nStartAfter itemStr:[NSString stringWithUTF8String: lpszItem]];
	}
	
	return LB_ERR;
}

int CListBox::GetCount() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((CNSTableView *)m_hWnd) count];
	}
	
	return LB_ERR;
}

int CListBox::GetCurSel() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		NSIndexSet *indexs = [((CNSTableView *)m_hWnd) selectedRowIndexes];
		
		if ([indexs count])
		{
			return [indexs firstIndex];
		}
	}
	
	return LB_ERR;
}

int CListBox::GetSelCount() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		return [((CNSTableView *)m_hWnd) numberOfSelectedRows];
	}
	
	return LB_ERR;
}

int CListBox::SetCurSel(int nSelect)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		NSIndexSet *indexs =[NSIndexSet indexSetWithIndex:nSelect];
		
		[((CNSTableView *)m_hWnd) selectRowIndexes:indexs byExtendingSelection:NO];
	
		return 0;
	}
	
	return LB_ERR;
}

void CListBox::GetText(int nIndex, CString& rString) const
{
	
}

void CListBox::ResetContent()
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		[((CNSTableView *)m_hWnd) removeAll];
	}
}
