/*
 *  CTabCtrl.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CWnd.h"

#ifndef CTABCTRL_DEFINE
#define CTABCTRL_DEFINE 1

typedef struct {
	UINT   mask;
	DWORD  dwState;
	DWORD  dwStateMask; 
	LPTSTR pszText;
	int    cchTextMax;
	int    iImage;
	LPARAM lParam;
} TCITEM, *LPTCITEM;

class CTabCtrl : public CWnd
{
	
public:
	
	CTabCtrl();
	
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	
	int GetCurFocus() const;
	int GetCurSel() const;
	int SetCurSel(int nItem);	
	
	BOOL GetItemRect(int nItem, LPRECT lpRect) const;
	
	LONG InsertItem(int nItem, TCITEM* pTabCtrlItem);
	LONG InsertItem(int nItem, LPCTSTR lpszItem);
	LONG InsertItem(int nItem, LPCTSTR lpszItem, int nImage);
	LONG InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam);
	LONG InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam, DWORD dwState, DWORD dwStateMask);
	
	BOOL DeleteItem(int nItem);
	
	void AdjustRect( BOOL bLarger, LPRECT lpRect );
};


#endif//CTABCTRL_DEFINE