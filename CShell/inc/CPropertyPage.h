/*
 *  CPropertyPage.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CPROPERTYPAGE_DEFINE
#define CPROPERTYPAGE_DEFINE 1

#include "CDef.h"
#include "CWnd.h"
#include "CDialog.h"

class CPropertyPage : public CDialog
{

public:
	
	CPropertyPage();
	CPropertyPage(UINT nIDTemplate, UINT nIDCaption = 0, DWORD dwSize = sizeof(PROPSHEETPAGE));
	CPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption = 0, DWORD dwSize = sizeof(PROPSHEETPAGE));
	CPropertyPage(UINT nIDTemplate, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle = 0, DWORD dwSize = sizeof(PROPSHEETPAGE));
	CPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle = 0, DWORD dwSize = sizeof(PROPSHEETPAGE)); 
	
	virtual ~CPropertyPage();
	
	void Construct(UINT nIDTemplate, UINT nIDCaption = 0);
	void Construct(LPCTSTR lpszTemplateName, UINT nIDCaption = 0);
	void Construct(UINT nIDTemplate, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle = 0);
	void Construct(LPCTSTR lpszTemplateName, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle = 0 );
				   
	void CancelToClose();
	
	virtual BOOL OnApply();
	virtual void OnCancel();
	virtual BOOL OnKillActive();
	virtual void OnOK();
	virtual BOOL OnQueryCancel();
	virtual void OnReset();
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardBack();
	virtual BOOL OnWizardFinish();
	virtual LRESULT OnWizardNext();
	LRESULT QuerySiblings(WPARAM wParam, LPARAM lParam);
	void SetModified(BOOL bChanged = TRUE);
	
	
	CString m_strCaption;
	
	//not mfc method
	
	CString			mStrID;
};

#endif//CPROPERTYPAGE_DEFINE