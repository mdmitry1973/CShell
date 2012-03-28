/*
 *  CPropertySheet.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CPROPERTYSHEET_DEFINE
#define CPROPERTYSHEET_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CPropertyPage;
class CTabCtrl;

class CPropertySheet : public CWnd
{

public:
	
	CPropertySheet(); 
	CPropertySheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark = NULL, HBITMAP hbmHeader = NULL);
	CPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark = NULL, HBITMAP hbmHeader = NULL); 
	
	virtual ~CPropertySheet();
	
	virtual BOOL Create(CWnd* pParentWnd = NULL, DWORD dwStyle = -1, DWORD dwExStyle = 0);
	
	virtual INT_PTR DoModal();
	
	virtual  BOOL OnInitDialog();
	
	void AddPage(CPropertyPage *pPage);
	
	BOOL SetActivePage(int nPage);
	BOOL SetActivePage(CPropertyPage* pPage);
					   
	void RemovePage(CPropertyPage *pPage);
	void RemovePage(int nPage );
					
	int GetPageCount() const;
	CPropertyPage* GetPage(int nPage) const;
	CPropertyPage* GetActivePage() const;
	int GetActiveIndex() const;
	int GetPageIndex(CPropertyPage* pPage);
	CTabCtrl* GetTabControl() const;
	
	void SetWizardButtons(DWORD dwFlags);
	void SetFinishText(LPCTSTR lpszText);
	void SetTitle(LPCTSTR lpszText, UINT nStyle = 0);
	void SetWizardMode();
	
	//not mfc methods
	
	virtual BOOL IsDialog();
	
	UINT			mISelectPage;
	HBITMAP			mHbmWatermark; 
	HPALETTE		mHpalWatermark; 
	HBITMAP			mHbmHeader;
	
	HANDLE			m_hTab;
	HANDLE			mPropertySheetDelegate;
	
	std::vector<CPropertyPage *> m_arrPages;
};

#endif//CPROPERTYSHEET_DEFINE