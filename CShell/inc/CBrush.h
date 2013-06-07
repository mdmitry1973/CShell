/*
 *  CBrush.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CBRUSH_DEFINE
#define CBRUSH_DEFINE 1

#include "CDef.h"
#include "CGdiObject.h"
#include "CBitmap.h"

class CBrush : public CGdiObject
{
	DECLARE_DYNAMIC(CBrush)
	
public:
	static CBrush* FromHandle(HBRUSH hBrush);
	
	// Constructors
	CBrush();
	CBrush(COLORREF crColor);             // CreateSolidBrush
	CBrush(int nIndex, COLORREF crColor); // CreateHatchBrush
	explicit CBrush(CBitmap* pBitmap);          // CreatePatternBrush
	
	BOOL CreateSolidBrush(COLORREF crColor);
	BOOL CreateHatchBrush(int nIndex, COLORREF crColor);
	BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
	BOOL CreatePatternBrush(CBitmap* pBitmap);
	//BOOL CreateDIBPatternBrush(HGLOBAL hPackedDIB, UINT nUsage);
	BOOL CreateDIBPatternBrush(const void* lpPackedDIB, UINT nUsage);
	BOOL CreateSysColorBrush(int nIndex);
	
	// Attributes
	operator HBRUSH() const;
	int GetLogBrush(LOGBRUSH* pLogBrush);
	
	// Implementation
public:
	virtual ~CBrush();

};

#endif//CBRUSH_DEFINE