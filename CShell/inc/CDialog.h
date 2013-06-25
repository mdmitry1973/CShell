/*
 *  CDialog.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CWnd.h"

#ifndef CDIALOG_DEFINE
#define CDIALOG_DEFINE 1

class CSHELL_LIB_EXPORT CDialog : public CWnd
{

public:
	
	CDialog();
	
	CDialog(UINT nIDTemplate, CWnd* pParent = NULL);
	CDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL); 
	
	virtual ~CDialog();
	
	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	virtual BOOL Create(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	
	virtual INT_PTR DoModal();
	
	virtual  BOOL OnInitDialog();
	
	LPCTSTR m_lpszTemplateName;     // name or MAKEINTRESOURCE
	
	//not mfc methods
	
	virtual BOOL IsDialog();
	
	void EndDialog(int nResult);
	
	CString			mStrID;

};

#endif//CDIALOG_DEFINE