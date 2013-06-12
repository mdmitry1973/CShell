/*
 *  CRgn.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CRGN_DEFINE
#define CRGN_DEFINE 1

class CRgn
{
	
public:
	
	CRgn();
	
	virtual ~CRgn();
	
	BOOL CreateRectRgn(int x1, int y1, int x2, int y2);
	BOOL CreateRectRgnIndirect(LPCRECT lpRect);
	BOOL CreatePolygonRgn(LPPOINT lpPoints, int nCount, int nMode);
	
	int OffsetRgn(int x, int y);
	int OffsetRgn(POINT point);
	
	int GetRgnBox(LPRECT lpRect) const;
	
	
	BOOL RectInRegion(LPCRECT lpRect) const;
	BOOL PtInRegion(int x, int y) const;
	BOOL PtInRegion(POINT point) const;
};

#endif//CRGN_DEFINE