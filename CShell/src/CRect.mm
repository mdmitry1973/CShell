/*
 *  CRect.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CRect.h"

CRect::CRect()
{
	left = 0;
	top = 0;
	bottom = 0;
	right = 0;
}

CRect::CRect(int l, int t, int r, int b)
{
	left = l;
	top = t;
	bottom = b;
	right = r;
}

CRect::CRect(const RECT& srcRect)
{
	(*this) = srcRect;
}

CRect::CRect(LPCRECT lpSrcRect)
{
	(*this) = lpSrcRect;
}

CRect::CRect(POINT point, SIZE size)
{
	left = point.x;
	top = point.y;
	bottom = point.x + size.cx;
	right = point.y + size.cy;
}

CRect::CRect(POINT topLeft, POINT bottomRight)
{
	left = topLeft.x;
	top = topLeft.y;
	bottom = bottomRight.y;
	right = bottomRight.x;
}

CRect::~CRect()
{

}

CRect::operator LPRECT()
{
	return *this;
}

CRect::operator LPCRECT()const
{
	return *this;
}

void CRect::operator =(const RECT& srcRect)
{
	(*this) = srcRect;
}

BOOL CRect::operator ==(const RECT& rect) const
{
	return (*this) == rect;
}

int CRect::Height()
{
	return bottom - top;
}

int CRect::Width()
{
	return right - left;
}
