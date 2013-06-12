/*
 *  CRect.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CRECT_DEFINE
#define CRECT_DEFINE 1

#include "CPoint.h"

class CRect : public RECT
{
	
public:
	
	CRect();
	CRect(int l, int t, int r, int b);
	CRect(const RECT& srcRect);
	CRect(LPCRECT lpSrcRect);
	CRect(POINT point, SIZE size);
	CRect(POINT topLeft, POINT bottomRight);
	
	virtual ~CRect();
	
	operator LPRECT();
	operator LPCRECT()const;
	void operator =(const RECT& srcRect);
	BOOL operator ==(const RECT& rect) const;
	void operator&=(const RECT& rect);
	BOOL operator!=(const RECT& rect)const;

	int Height();
	int Width();
	
	BOOL IsRectEmpty() const;
	
	CPoint& TopLeft();
	const CPoint& TopLeft() const;
	
	void InflateRect(int x, int y);
	void InflateRect(SIZE size);
	void InflateRect(LPCRECT lpRect);
	void InflateRect(int l, int t, int r, int b);
};

#endif//CRECT_DEFINE