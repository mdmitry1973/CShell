/*
 *  CStatic.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CWnd.h"

#ifndef CSTATIC_DEFINE
#define CSTATIC_DEFINE 1

class CStatic : public CWnd
{
	DECLARE_DYNAMIC(CStatic)
	
	// Constructors
public:
	CStatic();
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);
	
	// Operations
	HICON SetIcon(HICON hIcon);
	HICON GetIcon() const;
	
	//HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile);
	//HENHMETAFILE GetEnhMetaFile() const;
	HBITMAP SetBitmap(HBITMAP hBitmap);
	HBITMAP GetBitmap() const;
	HCURSOR SetCursor(HCURSOR hCursor);
	HCURSOR GetCursor();
	
	// Overridables (for owner draw only)
	//virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	
	// Implementation
public:
	virtual ~CStatic();
//protected:
//	virtual BOOL OnChildNotify(UINT, WPARAM, LPARAM, LRESULT*);
};

#endif//CSTATIC_DEFINE