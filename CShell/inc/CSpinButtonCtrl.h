/*
 *  CSpinButtonCtrl.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CWnd.h"

#ifndef CSPINBUTTONCTRL_DEFINE
#define CSPINBUTTONCTRL_DEFINE 1

class CSpinButtonCtrl : public CWnd
{
	
public:
	
	CSpinButtonCtrl();
	
	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	
	void SetRange(short nLower, short nUpper);
	void SetRange32(int nLower, int nUpper);
	int GetPos() const;
	int GetPos32(LPBOOL lpbError = NULL ) const;
	int SetPos(int nPos );
	int SetPos32(int nPos );
	CWnd* GetBuddy() const;
	CWnd* SetBuddy(CWnd* pWndBuddy );
	
protected:

	CWnd* m_pWndBuddy;

};


#endif//CSPINBUTTONCTRL_DEFINE