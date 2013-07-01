/*
 *  CEdit.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CEDIT_DEFINE
#define CEDIT_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CSHELL_LIB_EXPORT CEdit : public CWnd
{
	
public:
	
	CEdit();
	virtual ~CEdit();
	
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	
	DWORD GetSel() const;
	void GetSel(int& nStartChar, int& nEndChar) const;
	
	void SetSel(DWORD dwSelection, BOOL bNoScroll = FALSE);
	void SetSel(int nStartChar, int nEndChar, BOOL bNoScroll = FALSE);
	void SetLimitText(UINT nMax);
	BOOL SetCueBanner(LPCWSTR lpcwText);
	
	virtual void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};


#endif//CBUTTON_DEFINE
