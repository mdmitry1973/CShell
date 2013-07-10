/*
 *  CToolBarCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CToolBarCtrl.h"


CToolBarCtrl::CToolBarCtrl() : CWnd()
{
	
}

CToolBarCtrl::~CToolBarCtrl()
{

}

BOOL CToolBarCtrl::Create( DWORD dwStyle,  const RECT& rect,  CWnd* pParentWnd,  UINT nID)
{
    qDebug() << "to do CToolBarCtrl::Create";
}

BOOL CToolBarCtrl::CreateEx( DWORD dwExStyle,  DWORD dwStyle,  const RECT& rect,
			  CWnd* pParentWnd,  UINT nID)
{
    qDebug() << "to do CToolBarCtrl::Create";
}


BOOL CToolBarCtrl::IsButtonEnabled( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::IsButtonChecked( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::IsButtonPressed( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::IsButtonHidden( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::IsButtonIndeterminate( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetState( int nID,  UINT nState)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetState( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::GetButton( int nIndex,  LPTBBUTTON lpButton) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetButtonCount() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::GetItemRect( int nIndex,  LPRECT lpRect) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::GetRect( int nID,  LPRECT lpRect) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::SetButtonStructSize( int nSize)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

DWORD CToolBarCtrl::GetButtonSize() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetButtonSize( CSize size)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetBitmapSize( CSize size)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

CToolTipCtrl* CToolBarCtrl::GetToolTips() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::SetToolTips( CToolTipCtrl* pTip)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::SetOwner( CWnd* pWnd)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::SetRows( int nRows,  BOOL bLarger,  LPRECT lpRect)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetRows() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetCmdID( int nIndex,  UINT nID)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

UINT CToolBarCtrl::GetBitmapFlags() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetBitmap( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::ReplaceBitmap( LPTBREPLACEBITMAP pReplaceBitmap)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::ChangeBitmap( int idButton,  int iBitmap)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

CImageList* CToolBarCtrl::GetDisabledImageList() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

CImageList* CToolBarCtrl::GetHotImageList() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

CImageList* CToolBarCtrl::GetImageList() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

DWORD CToolBarCtrl::GetStyle() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetMaxTextRows() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::IsButtonHighlighted( int nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetButtonWidth( int cxMin,  int cxMax)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

CImageList* CToolBarCtrl::SetDisabledImageList( CImageList* pImageList)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

CImageList* CToolBarCtrl::SetHotImageList( CImageList* pImageList)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

CImageList* CToolBarCtrl::SetImageList( CImageList* pImageList)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

HRESULT CToolBarCtrl::GetDropTarget( IDropTarget** ppDropTarget) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetIndent( int iIndent)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetMaxTextRows( int iMaxRows)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::SetStyle( DWORD dwStyle)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetButtonInfo( int nID,  TBBUTTONINFO* ptbbi) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetButtonInfo( int nID,  TBBUTTONINFO* ptbbi)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

DWORD CToolBarCtrl::SetDrawTextFlags( DWORD dwMask,  DWORD dwDTFlags)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::GetAnchorHighlight() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::SetAnchorHighlight( BOOL fAnchor )
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetHotItem() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::SetHotItem( int nHot)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::GetInsertMark( TBINSERTMARK* ptbim) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::SetInsertMark( TBINSERTMARK* ptbim)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::GetMaxSize( LPSIZE pSize) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::InsertMarkHitTest( LPPOINT ppt,  LPTBINSERTMARK ptbim) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

DWORD CToolBarCtrl::GetExtendedStyle() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

DWORD CToolBarCtrl::SetExtendedStyle( DWORD dwExStyle)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::GetPadding( int& nHorzPadding,  int& nVertPadding) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

DWORD CToolBarCtrl::SetPadding( int nHorzPadding,  int nVertPadding)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

COLORREF CToolBarCtrl::GetInsertMarkColor() const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

COLORREF CToolBarCtrl::SetInsertMarkColor( COLORREF clrNew)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::EnableButton( int nID,  BOOL bEnable )
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::CheckButton( int nID,  BOOL bCheck )
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::PressButton( int nID,  BOOL bPress)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::HideButton( int nID,  BOOL bHide)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::Indeterminate( int nID,  BOOL bIndeterminate )
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::AddBitmap( int nNumButtons,  UINT nBitmapID)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::AddBitmap( int nNumButtons,  CBitmap* pBitmap)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::AddButtons( int nNumButtons,  LPTBBUTTON lpButtons)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::InsertButton( int nIndex,  LPTBBUTTON lpButton)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::DeleteButton( int nIndex)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

UINT CToolBarCtrl::CommandToIndex( UINT nID) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::SaveState( HKEY hKeyRoot,  LPCTSTR lpszSubKey,
							 LPCTSTR lpszValueName)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::RestoreState( HKEY hKeyRoot,  LPCTSTR lpszSubKey,
								LPCTSTR lpszValueName)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void LoadImages( int iBitmapID,  HINSTANCE hinst)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::CToolBarCtrl::MapAccelerator( TCHAR chAccel,  UINT* pIDBtn)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::MarkButton( int nID,  BOOL fHighlight )
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

BOOL CToolBarCtrl::MoveButton( UINT nOldPos,  UINT nNewPos)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::HitTest( LPPOINT ppt) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::Customize()
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::AddString( UINT nStringID)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::AddStrings( LPCTSTR lpszStrings)
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

void CToolBarCtrl::AutoSize()
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}


int CToolBarCtrl::GetString( int nString, LPTSTR lpstrString,  size_t cchMaxLen) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}

int CToolBarCtrl::GetString( int nString,  CString& str) const
{
    qDebug() << "to do CToolBarCtrl::IsButtonEnabled";
}
