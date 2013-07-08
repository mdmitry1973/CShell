/*
 *  CSliderCtrl.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CWnd.h"

#ifndef CSLIDERCTRL_DEFINE
#define CSLIDERCTRL_DEFINE 1

class CSHELL_LIB_EXPORT CSliderCtrl : public CWnd
{
	
public:
	
	CSliderCtrl();
    virtual ~CSliderCtrl();

	virtual BOOL Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual BOOL CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	
	void SetRange(short nLower, short nUpper);
	void SetRange32(int nLower, int nUpper);
	int SetPos(int nPos);
	
	int GetPos();
};


#endif//CSLIDERCTRL_DEFINE
