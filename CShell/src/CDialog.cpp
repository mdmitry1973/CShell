/*
 *  CDialog.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#include <QDialog>

#include "CDef.h"
#include "CWinApp.h"

#include "CDialog.h"
#include "CTabCtrl.h"

CDialog::CDialog() : CWnd()
{
	
}

CDialog::CDialog(UINT nIDTemplate, CWnd* pParentWnd) : CWnd()
{
    mStrID.Format(_T("%d"), nIDTemplate);
	mParentWin = pParentWnd;
}

CDialog::CDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd) : CWnd()
{
	mStrID = lpszTemplateName;
	mParentWin = pParentWnd;
}

CDialog::~CDialog()
{
	
}

BOOL CDialog::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	CTabCtrl *pTabCtrl = dynamic_cast<CTabCtrl *>(pParentWnd);
	
	if (pTabCtrl)
	{
		return CreatFromResFile(lpszTemplateName, TRUE, pParentWnd);
	}
	
	return CreatFromResFile(lpszTemplateName, FALSE);
}

BOOL CDialog::Create(UINT nIDTemplate, CWnd* pParentWnd)
{
	CTabCtrl *pTabCtrl = dynamic_cast<CTabCtrl *>(pParentWnd);
	
	if (pTabCtrl)
	{
		return CreatFromResFile(nIDTemplate, TRUE, pParentWnd);
	}
	
	return CreatFromResFile(nIDTemplate, FALSE, pParentWnd);
}

INT_PTR CDialog::DoModal()
{
    int endCode = 0;
	
    if (Create(mStrID, mParentWin))
	{
		FinaleSetup();

        QDialog *dlg = (QDialog *)m_hWnd;

        dlg->setModal( true );
        endCode = dlg->exec();
	}
	else 
	{
		assert(false);
	}
	
	return endCode;
}

BOOL CDialog::OnInitDialog()
{
	return CWnd::OnInitDialog();
}

BOOL CDialog::IsDialog()
{
	return true;
}
