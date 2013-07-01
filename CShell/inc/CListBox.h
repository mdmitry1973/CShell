/*
 *  CListBox.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CWnd.h"

#ifndef CLISTBOX_DEFINE
#define CLISTBOX_DEFINE 1

class CSHELL_LIB_EXPORT CListBox : public CWnd
{
	
public:
	
	CListBox();
	
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	
	int AddString(LPCTSTR lpszItem);
	int InsertString(int nIndex, LPCTSTR lpszItem);
	int DeleteString(UINT nIndex);
	int FindString(int nStartAfter, LPCTSTR lpszItem) const;
	int GetCount() const;
	int GetCurSel() const;
	int GetSelCount() const;
	int SetCurSel(int nSelect);
	void GetText(int nIndex, CString& rString) const;
	void ResetContent();
};


#endif//CLISTBOX_DEFINE
