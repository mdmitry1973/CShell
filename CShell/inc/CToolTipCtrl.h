/*
 *  CToolTipCtrl.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CTOOLTIPCTRL_DEFINE
#define CTOOLTIPCTRL_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CToolTipCtrl : public CWnd
{
	
	
	// Constructors
public:
	CToolTipCtrl();
	virtual ~CToolTipCtrl();
	
	// Generic creator
	virtual BOOL Create( CWnd* pParentWnd,  DWORD dwStyle = 0);
	
	// Generic creator allowing extended style bits
	virtual BOOL CreateEx( CWnd* pParentWnd,  DWORD dwStyle = 0,  DWORD dwStyleEx = 0);
	
	// Attributes
	// Retrieves the text for a tool in the ToolTip control .
	void GetText( CString& str,  CWnd* pWnd,  UINT_PTR nIDTool = 0) const;
	
	// Retrieves the information that the ToolTip control maintains about a tool.
	//BOOL GetToolInfo( CToolInfo& ToolInfo,  CWnd* pWnd,  UINT_PTR nIDTool = 0) const;
	
	// Sets the information that the ToolTip control maintains about a tool.
	//void SetToolInfo( LPTOOLINFO lpToolInfo);
	
	// Sets a new bounding rectangle for a tool.
	void SetToolRect( CWnd* pWnd,  UINT_PTR nIDTool,  LPCRECT lpRect);
	
	// Retrieves a count of the tools maintained by the ToolTip control.
	int GetToolCount() const;
	
	// Retrieves the initial, pop-up, or reshow duration currently set for the ToolTip control.
	int GetDelayTime( DWORD dwDuration) const;
	
	// Sets the initial, pop-up, or reshow duration for the ToolTip control.
	void SetDelayTime( DWORD dwDuration,  int iTime);
	
	// Retrieves the top, left, bottom, and right margins set for the ToolTip window.
	void GetMargin( LPRECT lprc) const;
	
	// Sets the top, left, bottom, and right margins for the ToolTip window.
	void SetMargin( LPRECT lprc);
	
	// Retrieves the maximum width for the ToolTip window.
	int GetMaxTipWidth() const;
	
	// Sets the maximum width for the ToolTip window.
	int SetMaxTipWidth( int iWidth);
	
	// Retrieves the background color in the ToolTip window.
	COLORREF GetTipBkColor() const;
	
	// Sets the background color in the ToolTip window.
	void SetTipBkColor( COLORREF clr);
	
	// Retrieves the text color in the ToolTip window.
	COLORREF GetTipTextColor() const;
	
	// Sets the text color in the ToolTip window.
	void SetTipTextColor( COLORREF clr);
	
	// Retrieves the information for the current tool in the ToolTip control.
	//BOOL GetCurrentTool( LPTOOLINFO lpToolInfo) const;
	

	// Returns the width and height of the ToolTip control.
	//CSize GetBubbleSize(_In_ LPTOOLINFO lpToolInfo) const;

	// Sets the visual style of the ToolTip control.
	//AFX_ANSI_DEPRECATED HRESULT SetWindowTheme(_In_z_ LPCWSTR pszSubAppName);

	
	// Operations
	// Activates or deactivates the ToolTip control.
	void Activate( BOOL bActivate);
	
	// Registers a tool with the ToolTip control.
	BOOL AddTool( CWnd* pWnd,  UINT nIDText,  LPCRECT lpRectTool = NULL,
				  UINT_PTR nIDTool = 0);
	BOOL AddTool( CWnd* pWnd,  LPCTSTR lpszText = LPSTR_TEXTCALLBACK,
				  LPCRECT lpRectTool = NULL,  UINT_PTR nIDTool = 0);
	
	// Removes a tool from the ToolTip control.
	void DelTool( CWnd* pWnd,  UINT_PTR nIDTool = 0);
	
	// Tests a point to determine whether it is within the bounding rectangle of
	// the specified tool and, if it is, retrieves information about the tool.
	//BOOL HitTest( CWnd* pWnd,  CPoint pt,  LPTOOLINFO lpToolInfo) const;
	
	// Passes a mouse message to the ToolTip control for processing.
	void RelayEvent( LPMSG lpMsg);
	
	void SetDelayTime( UINT nDelay);
	
	// Sets the ToolTip text for a tool.
	void UpdateTipText( LPCTSTR lpszText,  CWnd* pWnd,  UINT_PTR nIDTool = 0);
	void UpdateTipText( UINT nIDText,  CWnd* pWnd,  UINT_PTR nIDTool = 0);
	
	// Forces the current tool to be redrawn.
	void Update();
	
	// Removes the displayed ToolTip window from view.
	void Pop();

	// Calculates a ToolTip control's text display rectangle
	// from its window rectangle, or the ToolTip window rectangle
	// needed to display a specified text display rectangle.
	BOOL AdjustRect( LPRECT lprc,  BOOL bLarger = TRUE);
	
	// Adds a standard icon and title string to the ToolTip.
	BOOL SetTitle( UINT uIcon,  LPCTSTR lpstrTitle);

	// Causes the ToolTip to display at the coordinates of the last mouse message.
	void Popup();
	
	// Retrieves information concerning the title of a tooltip control.
	void GetTitle(PTTGETTITLE pTTGetTitle) const;

	
	// Implementation
public:
	void FillInToolInfo( TOOLINFO& ti,  CWnd* pWnd,  UINT_PTR nIDTool) const;
	
//#ifndef _AFXDLL
//	virtual BOOL DestroyToolTipCtrl();
//#else
//	BOOL DestroyToolTipCtrl();
//#endif
	
	DECLARE_DYNAMIC(CToolTipCtrl)
	
protected:
	//{{AFX_MSG(CToolTipCtrl)
//	afx_msg LRESULT OnDisableModal(WPARAM, LPARAM);
//	afx_msg LRESULT OnWindowFromPoint(WPARAM, LPARAM);
//	afx_msg LRESULT OnAddTool(WPARAM, LPARAM);
//	afx_msg void OnEnable(BOOL bEnable);
	//}}AFX_MSG
//	DECLARE_MESSAGE_MAP()
	
//	CMapStringToPtr m_mapString;
	
//	friend class CWnd;
//	friend class CToolBar;
};

#endif//CTOOLTIPCTRL_DEFINE