/*
 *  CDialogEx.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CWinApp.h"

#include "CDialogEx.h"

CDialogEx::CDialogEx()
{
	
}

CDialogEx::CDialogEx(UINT nIDTemplate, CWnd* pParent) : CDialog(nIDTemplate, pParent)
{
	
}

CDialogEx::CDialogEx(LPCTSTR lpszTemplateName, CWnd* pParentWnd) : CDialog(lpszTemplateName, pParentWnd)
{
	
}

CDialogEx::~CDialogEx()
{
	
}

