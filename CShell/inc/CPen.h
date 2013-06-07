/*
 *  CPen.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CPEN_DEFINE
#define CPEN_DEFINE 1

#include "CDef.h"
#include "wingdi.h"
#include "CGdiObject.h"

class CPen : public CGdiObject
{
	//DECLARE_DYNAMIC(CPen)
	
public:
	
	// Constructors
	CPen();
	CPen(int nPenStyle, int nWidth, COLORREF crColor);
	CPen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
		 int nStyleCount = 0, const DWORD* lpStyle = NULL);
	virtual ~CPen();
	BOOL CreatePen(int nPenStyle, int nWidth, COLORREF crColor);
	BOOL CreatePen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
				   int nStyleCount = 0, const DWORD* lpStyle = NULL);
	//BOOL CreatePenIndirect(LPLOGPEN lpLogPen);
	
	// Attributes
	operator HPEN() const;
	
	static CPen* FromHandle(HPEN hPen);
	//int GetLogPen(LOGPEN* pLogPen);
	//int GetExtLogPen(EXTLOGPEN* pLogPen)
};


#endif//CPEN_DEFINE