/*
 *  CScrollView.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CScrollView.h"

//IMPLEMENT_DYNAMIC(CScrollView, CView)

CScrollView::CScrollView() 
{
	NSLog(@"TO DO CScrollView::CScrollView");
}

CScrollView::~CScrollView()
{
	NSLog(@"TO DO CScrollView::CScrollView");
}
	
void CScrollView::SetScaleToFitSize(SIZE sizeTotal)
{
	NSLog(@"TO DO CScrollView::SetScaleToFitSize");
}

CPoint CScrollView::GetScrollPosition() const
{
	NSLog(@"TO DO CScrollView::GetScrollPosition");
}

CSize CScrollView::GetTotalSize()const
{
	NSLog(@"TO DO CScrollView::GetTotalSize");
}
	
void CScrollView::CheckScrollBars(BOOL& bHasHorzBar, BOOL& bHasVertBar) const
{
	NSLog(@"TO DO CScrollView::CheckScrollBars");
}

CPoint CScrollView::GetDeviceScrollPosition() const
{
	NSLog(@"TO DO CScrollView::GetDeviceScrollPosition");
}

void CScrollView::GetDeviceScrollSizes(int& nMapMode, SIZE& sizeTotal,
							  SIZE& sizePage, SIZE& sizeLine) const
{
	NSLog(@"TO DO CScrollView::GetDeviceScrollSizes");
}

void CScrollView::ScrollToPosition(POINT pt)
{
	NSLog(@"TO DO CScrollView::ScrollToPosition");
}

void CScrollView::FillOutsideRect(CDC* pDC, CBrush* pBrush)
{
	NSLog(@"TO DO CScrollView::FillOutsideRect");
}

void CScrollView::ResizeParentToFit(BOOL bShrinkOnly)
{
	NSLog(@"TO DO CScrollView::ResizeParentToFit");
}

BOOL CScrollView::DoMouseWheel(UINT fFlags, short zDelta, CPoint point)
{
	NSLog(@"TO DO CScrollView::DoMouseWheel");
	return FALSE;
}
	
void CScrollView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo )
{
	NSLog(@"TO DO CScrollView::OnPrepareDC");
}

CSize CScrollView::GetWheelScrollDistance(CSize sizeDistance, BOOL bHorz, BOOL bVert)
{
	NSLog(@"TO DO CScrollView::GetWheelScrollDistance");
}

BOOL CScrollView::OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll)
{
	NSLog(@"TO DO CScrollView::OnScroll");
	return FALSE;
}

BOOL CScrollView::OnScrollBy(CSize sizeScroll, BOOL bDoScroll)
{
	NSLog(@"TO DO CScrollView::OnScrollBy");
	return FALSE;
}

void CScrollView::SetScrollSizes(int nMapMode, SIZE sizeTotal,
					const SIZE& sizePage,
					const SIZE& sizeLine)
{
	NSLog(@"TO DO CScrollView::SetScrollSizes");
}
