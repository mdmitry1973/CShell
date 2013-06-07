/*
 *  CToolBarCtrl.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CTOOLBARCTRL_DEFINE
#define CTOOLBARCTRL_DEFINE 1

#include "CDef.h"
#include "CommCtrl.h"
#include "CSize.h"
#include "CWnd.h"
#include "CImageList.h"
#include "CToolTipCtrl.h"

class CToolBarCtrl : public CWnd
{
	
public:
	
	CToolBarCtrl();
	
	virtual ~CToolBarCtrl();
	
	// Generic creator
	BOOL Create( DWORD dwStyle,  const RECT& rect,  CWnd* pParentWnd,  UINT nID);
	
	// Generic creator allowing extended style bits
	BOOL CreateEx( DWORD dwExStyle,  DWORD dwStyle,  const RECT& rect,
				   CWnd* pParentWnd,  UINT nID);
	
	// Attributes
public:
	// Determines whether the specified button in the toolbar is enabled.
	BOOL IsButtonEnabled( int nID) const;
	
	// Determines whether the specified button in the toolbar is checked.
	BOOL IsButtonChecked( int nID) const;
	
	// Determines whether the specified button in the toolbar is pressed.
	BOOL IsButtonPressed( int nID) const;
	
	// Determines whether the specified button in the toolbar is hidden.
	BOOL IsButtonHidden( int nID) const;
	
	// Determines whether the specified button in the toolbar is indeterminate.
	BOOL IsButtonIndeterminate( int nID) const;
	
	// Sets the state for the specified button in the toolbar.
	BOOL SetState( int nID,  UINT nState);
	
	// Retrieves the state of the specified button in the toolbar.
	int GetState( int nID) const;
	
	// Retrieves information about the specified button in the toolbar.
	BOOL GetButton( int nIndex,  LPTBBUTTON lpButton) const;
	
	// Retrieves a count of the buttons currently in the toolbar control.
	int GetButtonCount() const;
	
	// Retrieves the bounding rectangle of the specified button in the toolbar (by index).
	BOOL GetItemRect( int nIndex,  LPRECT lpRect) const;
	
	// Retrieves the bounding rectangle for the specified button in the toolbar (by command).
	BOOL GetRect( int nID,  LPRECT lpRect) const;
	
	// Specifies the size of the TBBUTTON structure to the toolbar control.
	void SetButtonStructSize( int nSize);
	
	// Retrieves the current width and height of toolbar buttons, in pixels.
	DWORD GetButtonSize() const;
	
	// Sets the size of the buttons to be added to the toolbar.
	BOOL SetButtonSize( CSize size);
	
	// Sets the size of the bitmapped images to be added to the toolbar.
	BOOL SetBitmapSize( CSize size);
	
	// Retrieves the ToolTip control associated with the toolbar.
	CToolTipCtrl* GetToolTips() const;
	
	// Associates a ToolTip control with the toolbar.
	void SetToolTips( CToolTipCtrl* pTip);
	
	// Sets the window to which the toolbar control sends notification messages.
	void SetOwner( CWnd* pWnd);
	
	// Sets the number of rows of buttons in the toolbar.
	void SetRows( int nRows,  BOOL bLarger,  LPRECT lpRect);
	
	// Retrieves the number of rows of buttons in the toolbar.
	int GetRows() const;
	
	// Sets the command identifier of the specified toolbar button.
	BOOL SetCmdID( int nIndex,  UINT nID);
	
	// Retrieves the flags that describe the type of bitmap to be used.
	UINT GetBitmapFlags() const;
	
	// Retrieves the index of the bitmap associated with the specified button in the toolbar.
	int GetBitmap( int nID) const;
	
	// Replaces one bitmap in the toolbar control with another bitmap.
	BOOL ReplaceBitmap( LPTBREPLACEBITMAP pReplaceBitmap);
	
	// Changes the bitmap for the specified button in the toolbar control.
	BOOL ChangeBitmap( int idButton,  int iBitmap);
	
	// Retrieves the image list that the toolbar control uses to display inactive buttons.
	CImageList* GetDisabledImageList() const;
	
	// Retrieves the image list that the toolbar control uses to display hot buttons.
	CImageList* GetHotImageList() const;
	
	// Retrieves the image list that the toolbar control uses to display buttons in their default state
	CImageList* GetImageList() const;
	
	// Retrieves the styles currently in use for the toolbar control.
	DWORD GetStyle() const;
	
	// Retrieves the maximum number of text rows that can be displayed on a toolbar button.
	int GetMaxTextRows() const;
	
	// Determines whether the specified button in the toolbar is highlighted.
	BOOL IsButtonHighlighted( int nID) const;
	
	// Sets the minimum and maximum button widths in the toolbar control.
	BOOL SetButtonWidth( int cxMin,  int cxMax);
	
	// Sets the image list that the toolbar control will use to display disabled buttons.
	CImageList* SetDisabledImageList( CImageList* pImageList);
	
	// Sets the image list that the toolbar control will use to display hot buttons.
	CImageList* SetHotImageList( CImageList* pImageList);
	
	// Sets the image list that the toolbar control will use to display buttons in their default state.
	CImageList* SetImageList( CImageList* pImageList);
	
	// Retrieves the IDropTarget for the toolbar control.
	HRESULT GetDropTarget( IDropTarget** ppDropTarget) const;
	
	// Sets the indentation for the first button in the toolbar control.
	BOOL SetIndent( int iIndent);
	
	// Sets the maximum number of text rows that can be displayed on a toolbar button.
	BOOL SetMaxTextRows( int iMaxRows);
	
	// Sets the styles for the toolbar control.
	void SetStyle( DWORD dwStyle);
	
	// Retrieves extended information for the specified button in the toolbar.
	int GetButtonInfo( int nID,  TBBUTTONINFO* ptbbi) const;
	
	// Sets the information for the specified button in the toolbar.
	BOOL SetButtonInfo( int nID,  TBBUTTONINFO* ptbbi);
	
	// Sets the text drawing flags for the toolbar.
	DWORD SetDrawTextFlags( DWORD dwMask,  DWORD dwDTFlags);
	
	// Retrieves the anchor highlight setting for the toolbar.
	BOOL GetAnchorHighlight() const;
	
	// Sets the anchor highlight setting for the toolbar.
	BOOL SetAnchorHighlight( BOOL fAnchor = TRUE);
	
	// Retrieves the index of the hot item in the toolbar.
	int GetHotItem() const;
	
	// Sets the index of the hot item in the toolbar.
	int SetHotItem( int nHot);
	
	// Retrieves the current insertion mark for the toolbar.
	void GetInsertMark( TBINSERTMARK* ptbim) const;
	
	// Sets the current insertion mark for the toolbar.
	void SetInsertMark( TBINSERTMARK* ptbim);
	
	// Retrieves the total size of all of the visible buttons and separators in the toolbar.
	BOOL GetMaxSize( LPSIZE pSize) const;
	
	// Retrieves the insertion mark information for a point in the toolbar.
	BOOL InsertMarkHitTest( LPPOINT ppt,  LPTBINSERTMARK ptbim) const;
	
	// Retrieves the extended styles for the toolbar control.
	DWORD GetExtendedStyle() const;
	
	// Sets the extended styles for the toolbar control.
	DWORD SetExtendedStyle( DWORD dwExStyle);
	
	// Retrieves the padding for the toolbar control.
	void GetPadding( int& nHorzPadding,  int& nVertPadding) const;
	
	// Sets the padding for the toolbar control.
	DWORD SetPadding( int nHorzPadding,  int nVertPadding);
	
	// Retrieves the color used to draw the insertion mark for the toolbar.
	COLORREF GetInsertMarkColor() const;
	
	// Sets the color used to draw the insertion mark for the toolbar.
	COLORREF SetInsertMarkColor( COLORREF clrNew);
/*	
	// Retrieves the color scheme information from the toolbar control.
	BOOL GetColorScheme( COLORSCHEME* lpcs) const;
	
	// Sets the color scheme information for the toolbar control.
	void SetColorScheme( const COLORSCHEME* lpcs);
	
#if (_WIN32_WINNT >= 0x0501)
	// Retrieves the metrics of the toolbar control.
	AFX_ANSI_DEPRECATED void GetMetrics( LPTBMETRICS ptbm) const;
	
	// Sets the metrics of the toolbar control.
	AFX_ANSI_DEPRECATED void SetMetrics( LPTBMETRICS ptbm);
	
	// Sets the visual style of the toolbar control.
	AFX_ANSI_DEPRECATED HRESULT SetWindowTheme( LPCWSTR pszSubAppName);
#endif
	
#if (_WIN32_WINNT >= 0x600) && defined(UNICODE)
	// REVIEW: Sets the image list that the toolbar control uses to display buttons in a pressed state.
	CImageList* SetPressedImageList( int iImageID,  CImageList* pImageList);
	
	// REVIEW: Retrieves the image list that the toolbar control uses to display buttons in a pressed state.
	CImageList* GetPressedImageList() const;
#endif // _WIN32_WINNT >= 0x600 && defined(UNICODE)
	*/
	// Operations
public:
	// Enables or disables the specified button in the toolbar.
	BOOL EnableButton( int nID,  BOOL bEnable = TRUE);
	
	// Checks or unchecks the specified button in the toolbar.
	BOOL CheckButton( int nID,  BOOL bCheck = TRUE);
	
	// Presses or releases the specified button in the toolbar.
	BOOL PressButton( int nID,  BOOL bPress = TRUE);
	
	// Hides or shows the specified button in the toolbar.
	BOOL HideButton( int nID,  BOOL bHide = TRUE);
	
	// Sets or clears the indeterminate state of the specified button in the toolbar.
	BOOL Indeterminate( int nID,  BOOL bIndeterminate = TRUE);
	
	// Adds one or more images to the list of button images available for the toolbar control.
	int AddBitmap( int nNumButtons,  UINT nBitmapID);
	int AddBitmap( int nNumButtons,  CBitmap* pBitmap);
	
	// Adds one or more buttons to the toolbar control.
	BOOL AddButtons( int nNumButtons,  LPTBBUTTON lpButtons);
	
	// Inserts a button into the toolbar control.
	BOOL InsertButton( int nIndex,  LPTBBUTTON lpButton);
	
	// Deletes a button from the toolbar control.
	BOOL DeleteButton( int nIndex);
	
	// Retrieves the zero-based index for the button associated with the specified command identifier.
	UINT CommandToIndex( UINT nID) const;
	
	// Saves state for the toolbar control.
	void SaveState( HKEY hKeyRoot,  LPCTSTR lpszSubKey,
				    LPCTSTR lpszValueName);
	
	// Restores state for the toolbar control.
	void RestoreState( HKEY hKeyRoot,  LPCTSTR lpszSubKey,
					   LPCTSTR lpszValueName);
	
	// Loads system-defined button images into the toolbar control's image list.
	void LoadImages( int iBitmapID,  HINSTANCE hinst);
	
	// Determines the ID of the button that corresponds to the specified accelerator character.
	BOOL MapAccelerator( TCHAR chAccel,  UINT* pIDBtn);
	
	// Sets the highlight state of the specified button in the toolbar control.
	BOOL MarkButton( int nID,  BOOL fHighlight = TRUE);
	
	// Moves a button from one index to another in the toolbar control.
	BOOL MoveButton( UINT nOldPos,  UINT nNewPos);
	
	// Determines where a point lies in the toolbar control..
	int HitTest( LPPOINT ppt) const;
	
	// Displays the Customize Toolbar dialog box.
	void Customize();
	
	// Adds one or more strings to the toolbar control's string pool.
	int AddString( UINT nStringID);
	int AddStrings( LPCTSTR lpszStrings);
	
	// Causes the toolbar control to be resized.
	void AutoSize();

	int GetString( int nString, LPTSTR lpstrString,  size_t cchMaxLen) const;
	int GetString( int nString,  CString& str) const;

};


#endif//CTOOLBARCTRL_DEFINE