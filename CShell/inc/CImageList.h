/*
 *  CImageList.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CIMAGELIST_DEFINE
#define CIMAGELIST_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CImageList : public CObject
{
	DECLARE_DYNCREATE(CImageList)
	
	// Constructors
public:
	CImageList();
	BOOL Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow);
	BOOL Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(LPCTSTR lpszBitmapID, int cx, int nGrow, COLORREF crMask);
	BOOL Create(CImageList& imagelist1, int nImage1, CImageList& imagelist2,
				int nImage2, int dx, int dy);
	BOOL Create(CImageList* pImageList);
	
	// Attributes
	/*HIMAGELIST m_hImageList;            // must be first data member
	operator HIMAGELIST() const;
	HIMAGELIST GetSafeHandle() const;
	
	static CImageList* FromHandle(HIMAGELIST hImageList);
	static CImageList* FromHandlePermanent(HIMAGELIST hImageList);
	static void  DeleteTempMap();
	BOOL Attach(HIMAGELIST hImageList);
	HIMAGELIST Detach();
	*/
	
	int GetImageCount() const;
	COLORREF SetBkColor(COLORREF cr);
	COLORREF GetBkColor() const;
	//BOOL GetImageInfo(int nImage, IMAGEINFO* pImageInfo) const;
	
	// Operations
	BOOL DeleteImageList();
	BOOL SetImageCount(UINT uNewCount);
	
	int Add(CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(CBitmap* pbmImage, COLORREF crMask);
	BOOL Remove(int nImage);
	BOOL Replace(int nImage, CBitmap* pbmImage, CBitmap* pbmMask);
	int Add(HICON hIcon);
	int Replace(int nImage, HICON hIcon);
	HICON ExtractIcon(int nImage);
	
	/*
	BOOL Draw(CDC* pDC, int nImage, POINT pt, UINT nStyle);
	BOOL DrawEx(CDC* pDC, int nImage, POINT pt, SIZE sz, COLORREF clrBk, COLORREF clrFg, UINT nStyle);
	BOOL SetOverlayImage(int nImage, int nOverlay);
	BOOL Copy(int iDst, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL Copy(int iDst, CImageList* pSrc, int iSrc, UINT uFlags = ILCF_MOVE);
	BOOL DrawIndirect(IMAGELISTDRAWPARAMS* pimldp);
	BOOL DrawIndirect(CDC* pDC, int nImage, POINT pt, SIZE sz, POINT ptOrigin,
					  UINT fStyle = ILD_NORMAL, DWORD dwRop = SRCCOPY,
					  COLORREF rgbBack = CLR_DEFAULT, COLORREF rgbFore = CLR_DEFAULT,
					  DWORD fState = ILS_NORMAL, DWORD Frame = 0, COLORREF crEffect = CLR_DEFAULT);
	*/
	
//#ifndef _AFX_NO_OLE_SUPPORT
//	BOOL Read(CArchive* pArchive);
//	BOOL Write(CArchive* pArchive);
//#endif
	
	// Drag APIs
	BOOL BeginDrag(int nImage, CPoint ptHotSpot);
	static void EndDrag();
	static BOOL DragMove(CPoint pt);
	BOOL SetDragCursorImage(int nDrag, CPoint ptHotSpot);
	static BOOL DragShowNolock(BOOL bShow);
	static CImageList*  GetDragImage(LPPOINT lpPoint, LPPOINT lpPointHotSpot);
	static BOOL DragEnter(CWnd* pWndLock, CPoint point);
	static BOOL DragLeave(CWnd* pWndLock);
	
	// Implementation
public:
	virtual ~CImageList();

};

#endif//CIMAGELIST_DEFINE