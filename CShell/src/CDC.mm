/*
 *  CDC.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CDC.h"

CDC::CDC()
{
	m_hAttribDC = 0;
	m_hDC = 0;
}

CDC::~CDC()
{

}

COLORREF CDC::SetBkColor(COLORREF crColor)
{
	NSLog(@"TO DO CWnd::GetFont");
	return 0;
}

COLORREF CDC::SetTextColor(COLORREF crColor)
{
	NSLog(@"TO DO CWnd::GetFont");
	return 0;
}

CGdiObject* CDC::SelectStockObject(int nIndex)
{
	NSLog(@"TO DO CWnd::SelectStockObject");
	return 0;
}

CFont* CDC::SelectObject(CFont* pFont)
{
	NSLog(@"TO DO CWnd::SelectObject");
	return 0;
}

int CDC::SetMapMode(int nMapMode)
{
	NSLog(@"TO DO CWnd::SelectObject");
	return 0;
}

CPoint CDC::SetViewportOrg(int x, int y)
{
	NSLog(@"TO DO CWnd::SelectObject");
	return CPoint(0,0);
}

CPoint CDC::OffsetViewportOrg(int nWidth, int nHeight)
{
	NSLog(@"TO DO CWnd::SelectObject");
	return CPoint(0,0);
}

CSize CDC::SetViewportExt(int cx, int cy)
{
	NSLog(@"TO DO CWnd::SelectObject");
	return CSize(0,0);
}

CSize CDC::ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom)
{
	NSLog(@"TO DO CWnd::SelectObject");
	return CSize(0,0);
}

void CDC::SetAttribDC(HDC hDC)
{
	NSLog(@"TO DO CWnd::SelectObject");
}

void CDC::SetOutputDC(HDC hDC)
{
	NSLog(@"TO DO CWnd::SelectObject");
}

void CDC::ReleaseAttribDC()
{
	NSLog(@"TO DO CWnd::SelectObject");
}

void CDC::ReleaseOutputDC()
{
	NSLog(@"TO DO CWnd::SelectObject");
}

int CDC::SaveDC()
{
	NSLog(@"TO DO CWnd::SelectObject");
	return 0;
}

BOOL CDC::RestoreDC(int nSavedDC)
{
	NSLog(@"TO DO CDC::SelectObject");
	return FALSE;
}

CSize CDC::SetWindowExt(int cx, int cy)
{
	NSLog(@"TO DO CDC::SelectObject");
}

CSize CDC::ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom)
{
	NSLog(@"TO DO CDC::SelectObject");
}

int CDC::GetClipBox(LPRECT lpRect) const
{
	NSLog(@"TO DO CDC::GetClipBox");
	return 0;
}

BOOL CDC::PtVisible(int x, int y) const
{
	NSLog(@"TO DO CDC::PtVisible");
	return FALSE;
}

BOOL CDC::RectVisible(LPCRECT lpRect) const
{
	NSLog(@"TO DO CDC::RectVisible");
	return FALSE;
}

BOOL CDC::TextOut(int x, int y, LPCTSTR lpszString, int nCount)
{
	NSLog(@"TO DO CDC::RectVisible");
}

BOOL CDC::ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
						LPCTSTR lpszString, UINT nCount, LPINT lpDxWidths)
{
	NSLog(@"TO DO CDC::RectVisible");
}

CSize CDC::TabbedTextOut(int x, int y, LPCTSTR lpszString, int nCount,
							int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)
{
	NSLog(@"TO DO CDC::RectVisible");
}

int CDC::Escape( int nEscape,  int nCount, LPCSTR lpszInData,  LPVOID lpOutData)
{
	NSLog(@"TO DO CDC::Escape");
}


