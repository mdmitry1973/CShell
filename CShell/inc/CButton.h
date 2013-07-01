/*
 *  CButton.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CBUTTON_DEFINE
#define CBUTTON_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CSHELL_LIB_EXPORT CButton : public CWnd
{
	
public:
	
	CButton();
	
	virtual ~CButton();
	
	virtual BOOL Create(LPCTSTR lpszCaption,
						DWORD dwStyle,
						const RECT& rect,
						CWnd* pParentWnd,
						UINT nID 
						);	
	
	void SetCheck(int nCheck);
	void SetButtonStyle(UINT nStyle, BOOL bRedraw = TRUE);
	void SetState(BOOL bHighlight);
	int GetCheck() const;
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HICON SetIcon(HICON hIcon);
};


#endif//CBUTTON_DEFINE
