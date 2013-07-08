/*
 *  CRect.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QRect>
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

BOOL CRect::IsRectEmpty() const
{
    QRect rect(left, top, right - left, bottom - top);
	
    return rect.isEmpty();
}

CPoint& CRect::TopLeft()
{
	mTopLeft = CPoint(left, top);
	
	return mTopLeft;
}

const CPoint& CRect::TopLeft() const
{
	mTopLeft = CPoint(left, top);
	
	return mTopLeft;
}

CPoint& CRect::BottomRight()
{
	mBottomRight = CPoint(bottom, right);
	
	return mBottomRight;
}

const CPoint& CRect::BottomRight() const
{
	mBottomRight = CPoint(bottom, right);
	
	return mBottomRight;
}

void CRect::InflateRect(int x, int y)
{
	left -= x;
	top -= y;
	right += x;
	bottom += y;
}

void CRect::InflateRect(SIZE size)
{
	left -= size.cx;
	top -= size.cy;
	right += size.cx;
	bottom += size.cy;
}

void CRect::InflateRect(LPCRECT lpRect)
{
	left -= lpRect->left;
	top -= lpRect->top;
	right += lpRect->right;
	bottom += lpRect->bottom;
}

void CRect::InflateRect(int l, int t, int r, int b)
{
	left -= l;
	top -= t;
	right += r;
	bottom += b;
}

void CRect::NormalizeRect()
{
	int nTemp;
	if (left > right)
	{
		nTemp = left;
		left = right;
		right = nTemp;
	}
	if (top > bottom)
	{
		nTemp = top;
		top = bottom;
		bottom = nTemp;
	}
}

void CRect::SetRect( int x1, int y1, int x2, int y2)
{
	left = x1;
	right = x2;
	top = y1;
	bottom = y2;
}

BOOL CRect::PtInRect(POINT point) const
{
	if (point.x > left && point.x < right &&
		point.y > top && point.y < bottom)
		return TRUE;
	return FALSE;
}
