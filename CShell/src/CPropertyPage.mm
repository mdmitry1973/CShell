/*
 *  CPropertyPage.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CPropertyPage.h"

CPropertyPage::CPropertyPage() : CDialog()
{
	NSLog(@"TO DO CPropertyPage::CPropertyPage");
}

CPropertyPage::CPropertyPage(UINT nIDTemplate, UINT nIDCaption, DWORD dwSize) : CDialog()
{
	mStrID.Format("%d", nIDTemplate);
	mCaptionStr.LoadString(nIDCaption);
}

CPropertyPage::CPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption, DWORD dwSize) : CDialog()
{
	mStrID = lpszTemplateName;
	mCaptionStr.LoadString(nIDCaption);
}

CPropertyPage::CPropertyPage(UINT nIDTemplate, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle, DWORD dwSize) : CDialog()
{
	mStrID.Format("%d", nIDTemplate);
	mCaptionStr.LoadString(nIDCaption);
}

CPropertyPage::CPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle, DWORD dwSize) : CDialog()
{
	mStrID = lpszTemplateName;
	mCaptionStr.LoadString(nIDCaption);
}

CPropertyPage::~CPropertyPage()
{
	
}

void CPropertyPage::Construct(UINT nIDTemplate, UINT nIDCaption)
{
	mStrID.Format("%d", nIDTemplate);
	mCaptionStr.LoadString(nIDCaption);
	
	CreatFromResFile(nIDTemplate, TRUE);
}

void CPropertyPage::Construct(LPCTSTR lpszTemplateName, UINT nIDCaption)
{
	mStrID = lpszTemplateName;
	mCaptionStr.LoadString(nIDCaption);
	
	CreatFromResFile(lpszTemplateName, TRUE);
}	

void CPropertyPage::Construct(UINT nIDTemplate, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle)
{
	mStrID.Format("%d", nIDTemplate);
	mCaptionStr.LoadString(nIDCaption);
	
	CreatFromResFile(nIDTemplate, TRUE);
}

void CPropertyPage::Construct(LPCTSTR lpszTemplateName, UINT nIDCaption, UINT nIDHeaderTitle, UINT nIDHeaderSubTitle)
{
	mStrID = lpszTemplateName;
	mCaptionStr.LoadString(nIDCaption);
	
	CreatFromResFile(lpszTemplateName, TRUE);
}

void CPropertyPage::CancelToClose()
{
	NSLog(@"TO DO CPropertyPage::CancelToClose");
}

BOOL CPropertyPage::OnApply()
{
	NSLog(@"TO DO CPropertyPage::OnApply");
	return FALSE;
}

void CPropertyPage::OnCancel()
{
	NSLog(@"TO DO CPropertyPage::OnCancel");
}

BOOL CPropertyPage::OnKillActive()
{
	NSLog(@"TO DO CPropertyPage::OnKillActive");
	return FALSE;
}

void CPropertyPage::OnOK()
{
	NSLog(@"TO DO CPropertyPage::OnOK");
}

BOOL CPropertyPage::OnQueryCancel()
{
	NSLog(@"TO DO CPropertyPage::OnQueryCancel");
	return FALSE;
}

void CPropertyPage::OnReset()
{
	NSLog(@"TO DO CPropertyPage::OnReset");
}

BOOL CPropertyPage::OnSetActive()
{
	NSLog(@"TO DO CPropertyPage::OnSetActive");
	return FALSE;
}

LRESULT CPropertyPage::OnWizardBack()
{
	NSLog(@"TO DO CPropertyPage::OnWizardBack");
	return 0;
}

BOOL CPropertyPage::OnWizardFinish()
{
	NSLog(@"TO DO CPropertyPage::OnWizardFinish");
	return FALSE;
}

LRESULT CPropertyPage::OnWizardNext()
{
	NSLog(@"TO DO CPropertyPage::OnWizardNext");
	return 0;
}

LRESULT CPropertyPage::QuerySiblings(WPARAM wParam, LPARAM lParam)
{
	NSLog(@"TO DO CPropertyPage::QuerySiblings");
	return 0;
}

void CPropertyPage::SetModified(BOOL bChanged)
{
	NSLog(@"TO DO CPropertyPage::SetModified");
}
