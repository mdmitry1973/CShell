/*
 *  CToolBar.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CTOOLBAR_DEFINE
#define CTOOLBAR_DEFINE 1

#include "CDef.h"
#include "CWnd.h"
#include "CToolBarCtrl.h"

class CToolBar : public CWnd
{
	
public:
	
	CToolBar();
	
	virtual ~CToolBar();
	
	virtual BOOL Create(CWnd* pParentWnd,
						DWORD dwStyle = WS_CHILD |  WS_VISIBLE | CBRS_TOP,
						UINT nID = AFX_IDW_TOOLBAR);
						
	virtual BOOL CreateEx( CWnd* pParentWnd,
						  DWORD dwCtrlStyle = TBSTYLE_FLAT,
						  DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP,
						  CRect rcBorders = CRect(
												  0,
												  0,
												  0,
												  0
												  ),
						  UINT nID = AFX_IDW_TOOLBAR);
						  
	BOOL LoadToolBar(LPCTSTR lpszResourceName);
	BOOL LoadToolBar(UINT nIDResource);
	
	//CControlBar
	void EnableDocking(DWORD dwDockStyle);
	
	
	/*
	
	virtual BOOL Create(CWnd* pParentWnd,
						DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP,
						UINT nID = AFX_IDW_TOOLBAR);
	virtual BOOL CreateEx(CWnd* pParentWnd, DWORD dwCtrlStyle = TBSTYLE_FLAT,
						  DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP,
						  CRect rcBorders = CRect(0, 0, 0, 0),
						  UINT nID = AFX_IDW_TOOLBAR);
	
	void SetSizes(SIZE sizeButton, SIZE sizeImage);
	// button size should be bigger than image
	void SetHeight(int cyHeight);
	// call after SetSizes, height overrides bitmap size
	BOOL LoadToolBar(LPCTSTR lpszResourceName);
	BOOL LoadToolBar(UINT nIDResource);
	BOOL LoadBitmap(LPCTSTR lpszResourceName);
	BOOL LoadBitmap(UINT nIDResource);
	BOOL SetBitmap(HBITMAP hbmImageWell);
	BOOL SetButtons(const UINT* lpIDArray, int nIDCount);
	// lpIDArray can be NULL to allocate empty buttons
	*/
	// Attributes
public:
	/*
	// standard control bar things
	int CommandToIndex(UINT nIDFind) const;
	UINT GetItemID(int nIndex) const;
	virtual void GetItemRect(int nIndex, LPRECT lpRect) const;
	UINT GetButtonStyle(int nIndex) const;
	void SetButtonStyle(int nIndex, UINT nStyle);
	
	// for changing button info
	void GetButtonInfo(int nIndex, UINT& nID, UINT& nStyle, int& iImage) const;
	void SetButtonInfo(int nIndex, UINT nID, UINT nStyle, int iImage);
	BOOL SetButtonText(int nIndex, LPCTSTR lpszText);
	CString GetButtonText(int nIndex) const;
	void GetButtonText(int nIndex, CString& rString) const;
	*/
	// for direct access to the underlying common control
	CToolBarCtrl& GetToolBarCtrl() const;
	
	// Implementation
public:
	/*
	virtual CSize CalcFixedLayout(BOOL bStretch, BOOL bHorz);
	virtual CSize CalcDynamicLayout(int nLength, DWORD nMode);
	virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
	virtual void OnUpdateCmdUI(CFrameWnd* pTarget, BOOL bDisableIfNoHndler);
	void SetOwner(CWnd* pOwnerWnd);
	BOOL AddReplaceBitmap(HBITMAP hbmImageWell);
	virtual void OnBarStyleChange(DWORD dwOldStyle, DWORD dwNewStyle);
	virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
	*/

	
	
};

#define CMFCToolBar CToolBar


#endif//CTOOLBAR_DEFINE