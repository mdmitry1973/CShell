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

	int Height();
	int Width();
};

#endif//CRECT_DEFINE