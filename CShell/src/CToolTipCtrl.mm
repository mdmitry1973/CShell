/*
 *  CToolTipCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CToolTipCtrl.h"

#include "CWnd.h"

IMPLEMENT_DYNAMIC(CToolTipCtrl, CWnd)

CToolTipCtrl::CToolTipCtrl() : CWnd()
{
	
}

CToolTipCtrl::~CToolTipCtrl()
{

}

BOOL CToolTipCtrl::Create( CWnd* pParentWnd,  DWORD dwStyle)
{
	NSLog(@"to do CToolTipCtrl::Create");
	return FALSE;
}

BOOL CToolTipCtrl::CreateEx( CWnd* pParentWnd,  DWORD dwStyle,  DWORD dwStyleEx)
{
	NSLog(@"to do CToolTipCtrl::Create");
	return FALSE;
}

void CToolTipCtrl::GetText( CString& str,  CWnd* pWnd,  UINT_PTR nIDTool) const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::SetToolRect( CWnd* pWnd,  UINT_PTR nIDTool,  LPCRECT lpRect)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

int CToolTipCtrl::GetToolCount() const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

int CToolTipCtrl::GetDelayTime( DWORD dwDuration) const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::SetDelayTime( DWORD dwDuration,  int iTime)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::GetMargin( LPRECT lprc) const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::SetMargin( LPRECT lprc)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

int CToolTipCtrl::GetMaxTipWidth() const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

int CToolTipCtrl::SetMaxTipWidth( int iWidth)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

COLORREF CToolTipCtrl::GetTipBkColor() const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::SetTipBkColor( COLORREF clr)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

COLORREF CToolTipCtrl::GetTipTextColor() const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::SetTipTextColor( COLORREF clr)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::Activate( BOOL bActivate)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

BOOL CToolTipCtrl::AddTool( CWnd* pWnd,  UINT nIDText,  LPCRECT lpRectTool,
						   UINT_PTR nIDTool)
{
	NSLog(@"to do CToolTipCtrl::Create");
	return FALSE;
}

BOOL CToolTipCtrl::AddTool( CWnd* pWnd,  LPCTSTR lpszText,
						   LPCRECT lpRectTool,  UINT_PTR nIDTool)
{
	NSLog(@"to do CToolTipCtrl::Create");
	return FALSE;
}

void CToolTipCtrl::DelTool( CWnd* pWnd,  UINT_PTR nIDTool)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::RelayEvent( LPMSG lpMsg)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::SetDelayTime( UINT nDelay)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::UpdateTipText( LPCTSTR lpszText,  CWnd* pWnd,  UINT_PTR nIDTool)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::UpdateTipText( UINT nIDText,  CWnd* pWnd,  UINT_PTR nIDTool)
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::Update()
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::Pop()
{
	NSLog(@"to do CToolTipCtrl::Create");
}

BOOL CToolTipCtrl::AdjustRect( LPRECT lprc,  BOOL bLarger)
{
	NSLog(@"to do CToolTipCtrl::Create");
	return FALSE;
}

BOOL CToolTipCtrl::SetTitle( UINT uIcon,  LPCTSTR lpstrTitle)
{
	NSLog(@"to do CToolTipCtrl::Create");
	return FALSE;
}

void CToolTipCtrl::Popup()
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::GetTitle(PTTGETTITLE pTTGetTitle) const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

void CToolTipCtrl::FillInToolInfo(TOOLINFO& ti,  CWnd* pWnd,  UINT_PTR nIDTool) const
{
	NSLog(@"to do CToolTipCtrl::Create");
}

