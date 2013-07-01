/*
 *  CComboBox.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/12/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CWnd.h"

#ifndef CCOMBOBOX_DEFINE
#define CCOMBOBOX_DEFINE 1

class CSHELL_LIB_EXPORT CComboBox : public CWnd
{
	
public:
	
	enum ComboBoxType {
		
		eNSPopUpButton = 0,
		eNSComboBox = 1,
	};
	
	CComboBox();
	
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	
	int AddString(LPCTSTR lpszString );
	
	int GetCount() const;
	int GetCurSel() const;
	int SetCurSel(int nSelect);
	int SelectString(int nStartAfter, LPCTSTR lpszString);
	int InsertString(int nIndex, LPCTSTR lpszString);
	int GetLBText(int nIndex, LPTSTR lpszText) const;
	void GetLBText(int nIndex, CString& rString) const;
	int GetLBTextLen(int nIndex) const;
	
	ComboBoxType type;
};


#endif//CCOMBOBOX_DEFINE
