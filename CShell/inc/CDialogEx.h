/*
 *  CDialogEx.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDialog.h"

#ifndef CDIALOGEX_DEFINE
#define CDIALOGEX_DEFINE 1

class CSHELL_LIB_EXPORT CDialogEx: public CDialog
{

public:
	
	CDialogEx();
	
	CDialogEx(UINT nIDTemplate, CWnd* pParent = NULL);
	CDialogEx(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL); 
	
	virtual ~CDialogEx();
};

#endif//CDIALOGEX_DEFINE