/*
 *  CScrollView.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CView.h"

#ifndef CSCROLLVIEW_DEFINE
#define CSCROLLVIEW_DEFINE 1

class CScrollView : public CView
{
	//DECLARE_DYNAMIC(CScrollView)
	
	// Constructors
protected:
	CScrollView();
	
public:
	static const SIZE sizeDefault;
	// used to specify default calculated page and line sizes
	
	// in logical units - call one of the following Set routines
	void SetScaleToFitSize(SIZE sizeTotal);
	void SetScrollSizes(int nMapMode, SIZE sizeTotal,
						const SIZE& sizePage = sizeDefault,
						const SIZE& sizeLine = sizeDefault);
	
	// Attributes
public:
	CPoint GetScrollPosition() const;       // upper corner of scrolling
	CSize GetTotalSize() const;             // logical size
	
	void CheckScrollBars(BOOL& bHasHorzBar, BOOL& bHasVertBar) const;
	
	// for device units
	CPoint GetDeviceScrollPosition() const;
	void GetDeviceScrollSizes(int& nMapMode, SIZE& sizeTotal,
							  SIZE& sizePage, SIZE& sizeLine) const;
	
	// Operations
public:
	void ScrollToPosition(POINT pt);    // set upper left position
	void FillOutsideRect(CDC* pDC, CBrush* pBrush);
	void ResizeParentToFit(BOOL bShrinkOnly = TRUE);
	BOOL DoMouseWheel(UINT fFlags, short zDelta, CPoint point);
	
	// Implementation
protected:
	///_AFX_MOUSEANCHORWND* m_pAnchorWindow; // window for wheel mouse anchor
	//friend class _AFX_MOUSEANCHORWND;
	//int m_nMapMode;				 // mapping mode for window creation
	//CSize m_totalLog;           // total size in logical units (no rounding)
	//CSize m_totalDev;           // total size in device units
	//CSize m_pageDev;            // per page scroll size in device units
	//CSize m_lineDev;            // per line scroll size in device units
	
	//BOOL m_bCenter;             // Center output if larger than total size
	//BOOL m_bInsideUpdate;       // internal state for OnSize callback
	//void CenterOnPoint(CPoint ptCenter);
	//void ScrollToDevicePosition(POINT ptDev); // explicit scrolling no checking
	
protected:
	//virtual void OnDraw(CDC* pDC) = 0;      // pass on pure virtual
	
	//void UpdateBars();          // adjust scrollbars etc
	//BOOL GetTrueClientSize(CSize& size, CSize& sizeSb);
	// size with no bars
	//void GetScrollBarSizes(CSize& sizeSb);
	//void GetScrollBarState(CSize sizeClient, CSize& needSb,
	//					   CSize& sizeRange, CPoint& ptMove, BOOL bInsideClient);
	
public:
	virtual ~CScrollView();
	
	

	//virtual void CalcWindowRect(LPRECT lpClientRect,
	//							UINT nAdjustType = adjustBorder);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	
	virtual CSize GetWheelScrollDistance(CSize sizeDistance,
										 BOOL bHorz, BOOL bVert);
	
	// scrolling implementation support for OLE
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	virtual BOOL OnScrollBy(CSize sizeScroll, BOOL bDoScroll = TRUE);
	
	
	//CDocument* 	m_pDocument;
	
	//{{AFX_MSG(CScrollView)
	//afx_msg void OnSize(UINT nType, int cx, int cy);
	//afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//afx_msg BOOL OnMouseWheel(UINT fFlags, short zDelta, CPoint point);
	//	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	//afx_msg LRESULT HandleMButtonDown(WPARAM wParam, LPARAM lParam);
	//afx_msg LRESULT OnPrintClient(WPARAM wParam, LPARAM lParam);
	//DECLARE_MESSAGE_MAP()
};

#endif//CSCROLLVIEW_DEFINE