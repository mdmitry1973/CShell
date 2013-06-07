/*
 *  CTreeCtrl.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CTREECTRL_DEFINE
#define CTREECTRL_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CToolTipCtrl;

class CTreeCtrl : public CWnd
{
	// DECLARE_DYNAMIC virtual OK - CWnd has DECLARE_DYNAMIC
	DECLARE_DYNAMIC(CTreeCtrl)
	
	// Constructors
public:
	CTreeCtrl();
	
	// Generic creator
	BOOL Create( DWORD dwStyle,  const RECT& rect,  CWnd* pParentWnd,  UINT nID);
	
	// Generic creator allowing extended style bits
	BOOL CreateEx( DWORD dwExStyle,  DWORD dwStyle,  const RECT& rect,
				   CWnd* pParentWnd,  UINT nID);
	
	// Attributes
	
	// Retrieves the bounding rectangle for the specified item.
	BOOL GetItemRect( HTREEITEM hItem,  LPRECT lpRect,  BOOL bTextOnly) const;
	
	// Gets the count of items in the control.
	UINT GetCount() const;
	
	// Returns the level-to-level indentation (in pixels).
	UINT GetIndent() const;
	
	// Sets the level-to-level indentation (in pixels).
	void SetIndent( UINT nIndent);
	
	// Retrieves the image list associated with the control.
	CImageList* GetImageList( int nImageList) const;
	
	// Sets the image list associated with this control.
	CImageList* SetImageList( CImageList* pImageList,  int nImageList);
	
	// Retrieves the next item having the given relationship with the
	// specified item.
	HTREEITEM GetNextItem( HTREEITEM hItem,  UINT nCode) const;
	
	// Retrieves the next child item after the specified item.
	HTREEITEM GetChildItem( HTREEITEM hItem) const;
	
	// Retrieves the next sibling item after the specified item.
	HTREEITEM GetNextSiblingItem( HTREEITEM hItem) const;
	
	// Retrieves the previous sibling item of the specified item.
	HTREEITEM GetPrevSiblingItem( HTREEITEM hItem) const;
	
	// Retrieves the parent of the specified item.
	HTREEITEM GetParentItem( HTREEITEM hItem) const;
	
	// Retrieves the topmost visible item in the control.
	HTREEITEM GetFirstVisibleItem() const;
	
	// Retrieves the next visible item after the specified item.
	HTREEITEM GetNextVisibleItem( HTREEITEM hItem) const;
	
	// Retrieves the previous visible item before the specified item.
	HTREEITEM GetPrevVisibleItem( HTREEITEM hItem) const;
	
	// Retrieves the last expanded item in the tree. This does not retrieve the last item visible in the tree-view window.
	HTREEITEM GetLastVisibleItem() const;
	
	// Retrieves the higlighted item, NULL if none.
	HTREEITEM GetSelectedItem() const;
	
	// Retrieves the currently drop-highlighted item, NULL if none.
	HTREEITEM GetDropHilightItem() const;
	
	// Retrieves the root item of the control, NULL if none.
	HTREEITEM GetRootItem() const;
	
	// Retrieves information about a particular item in the control.
	BOOL GetItem( TVITEM* pItem) const;
	
	// Retrieves the text associated with the given item.
	CString GetItemText( HTREEITEM hItem) const;
	
	// Retrieves the images associated with the given item.
	BOOL GetItemImage( HTREEITEM hItem,  int& nImage,
					   int& nSelectedImage) const;
	
	// Retrieves the state of the given item.
	UINT GetItemState( HTREEITEM hItem,  UINT nStateMask) const;
	
	// Retrieves the user-supplied data associated with the given item.
	DWORD_PTR GetItemData( HTREEITEM hItem) const;
	
	// Sets the state of the an item.
	BOOL SetItem( TVITEM* pItem);
	BOOL SetItem( HTREEITEM hItem,  UINT nMask,  LPCTSTR lpszItem,  int nImage,
				  int nSelectedImage,  UINT nState,  UINT nStateMask,  LPARAM lParam);
	

	BOOL SetItemEx( HTREEITEM hItem,  UINT nMask,  LPCTSTR lpszItem,  int nImage,
				    int nSelectedImage,  UINT nState,  UINT nStateMask,  LPARAM lParam,
				    UINT uStateEx,  HWND hWnd,  int iExpandedImage);

	
	// Sets the text of the specified item.
	BOOL SetItemText( HTREEITEM hItem,  LPCTSTR lpszItem);
	
	// Sets the image on the specified item.
	BOOL SetItemImage( HTREEITEM hItem,  int nImage,  int nSelectedImage);
	
	// Sets the state of the specified item.
	BOOL SetItemState( HTREEITEM hItem,  UINT nState,  UINT nStateMask);
	
	// Sets the user data on the specified item.
	BOOL SetItemData( HTREEITEM hItem,  DWORD_PTR dwData);
	
	// Determines if the specified item has children.
	BOOL ItemHasChildren( HTREEITEM hItem) const;
	
	// Retrieves the edit control used to perform in-place editing.
	CEdit* GetEditControl() const;
	
	// Gets the count of items presently visible in the control.
	UINT GetVisibleCount() const;
	
	// Retrieves the tool tip control associated with this control.
	CToolTipCtrl* GetToolTips() const;
	
	// Sets the tool tip control to be used by this control.
	CToolTipCtrl* SetToolTips( CToolTipCtrl* pWndTip);
	
	// Retrieves the background colour used throughout the control.
	COLORREF GetBkColor() const;
	
	// Sets the background color to be used throughout the control.
	COLORREF SetBkColor( COLORREF clr);
	
	// Retrieves the height of items in the control.
	int GetItemHeight() const;
	
	// Sets the height of items in the control.
	void SetItemHeight(int  cyHeight);
	
	// Retrieves the text color used for all items in the control.
	COLORREF GetTextColor() const;
	
	// Sets the text color used for all items in the control.
	COLORREF SetTextColor( COLORREF clr);
	
	// Sets the insertion mark to the specified item in the control.
	BOOL SetInsertMark( HTREEITEM hItem,  BOOL fAfter = TRUE);
	
	// Gets the checked state of the specified item in the control.
	// (Only useful on a control with the TVS_CHECKBOXES style.)
	BOOL GetCheck( HTREEITEM hItem) const;
	
	// Sets the checked state of the specified item in the control.
	// (Only useful on a control with the TVS_CHECKBOXES style.)
	BOOL SetCheck( HTREEITEM hItem,  BOOL fCheck = TRUE);
	
	COLORREF GetInsertMarkColor() const;
	COLORREF SetInsertMarkColor( COLORREF clrNew);
	
	// Sets the maximum time (in milliseconds) the control will
	// spend smooth scrolling its content.
	UINT SetScrollTime( UINT uScrollTime);
	
	// Retrieves the maximum time (in milliseconds) the control will
	// spend smooth scrolling its content.
	UINT GetScrollTime() const;
	
	COLORREF GetLineColor() const;
	COLORREF SetLineColor( COLORREF clrNew = CLR_DEFAULT);
	
	// Maps treeview item id to accessibility identifier.
	UINT MapItemToAccId(HTREEITEM hItem) const;
	
	// Maps accessibility identifier id to treeview item.
	HTREEITEM MapAccIdToItem(UINT uAccId) const;
	
	// Set autoscrolling rate and delay (?).
	BOOL SetAutoscrollInfo(UINT uPixelsPerSec, UINT uUpdateTime);

	// Get count of selected items in the tree control.
	UINT GetSelectedCount();
	
	// Get rectangle for the specified part of the specified item.
	//BOOL GetItemPartRect(HTREEITEM hItem, TVITEMPART nPart, LPRECT lpRect);
	
	// Get the extended state of the item
	UINT GetItemStateEx(HTREEITEM hItem) const;
	
	// Set the extended state of the item
	BOOL SetItemStateEx(HTREEITEM hItem, UINT uStateEx);
	
	// Get the expanded image index for the specified item
	int GetItemExpandedImageIndex(HTREEITEM hItem) const;
	
	// Set the expanded image index for the specified item
	BOOL SetItemExpandedImageIndex(HTREEITEM hItem, int nIndex);
	
	// Get extended styles for the tree control.
	DWORD GetExtendedStyle() const;
	
	// Set extended styles on the tree control.
	DWORD SetExtendedStyle(DWORD dwExMask, DWORD dwExStyles);

	// Operations
	
	// Inserts a new item to the control.
	HTREEITEM InsertItem( LPTVINSERTSTRUCT lpInsertStruct);
	HTREEITEM InsertItem( UINT nMask,  LPCTSTR lpszItem,  int nImage,
						  int nSelectedImage,  UINT nState,  UINT nStateMask,  LPARAM lParam,
						  HTREEITEM hParent,  HTREEITEM hInsertAfter);
	HTREEITEM InsertItem( LPCTSTR lpszItem,  HTREEITEM hParent = TVI_ROOT,
						  HTREEITEM hInsertAfter = TVI_LAST);
	HTREEITEM InsertItem( LPCTSTR lpszItem,  int nImage,  int nSelectedImage,
						  HTREEITEM hParent = TVI_ROOT,  HTREEITEM hInsertAfter = TVI_LAST);
	
	// Removes the specified item from the control.
	BOOL DeleteItem( HTREEITEM hItem);
	
	// Removes all items from the control.
	BOOL DeleteAllItems();
	
	// Expands the children of the specified item.
	BOOL Expand( HTREEITEM hItem,  UINT nCode);
	
	// Selects the specified item.
	BOOL Select( HTREEITEM hItem,  UINT nCode);
	
	// Selects the specified item.
	BOOL SelectItem( HTREEITEM hItem);
	
	// Selects an item to be the drop target in the control.
	BOOL SelectDropTarget( HTREEITEM hItem);
	
	// Draws the specified item as the drop target for the control.
	BOOL SelectSetFirstVisible( HTREEITEM hItem);
	
	// Begins editing the label of the specified item.
	CEdit* EditLabel( HTREEITEM hItem);
	
	// Determines the visual feature of the control under
	// the specified point.
	//HTREEITEM HitTest( CPoint pt,  UINT* pFlags = NULL) const;
	//HTREEITEM HitTest( TVHITTESTINFO* pHitTestInfo) const;
	
	// Create a drag image for the specified item.
	//CImageList* CreateDragImage( HTREEITEM hItem);
	
	// Sorts all children of the specified item.
	BOOL SortChildren( HTREEITEM hItem);
	
	// Scrolls the control to ensure the specified item is visible.
	BOOL EnsureVisible( HTREEITEM hItem);
	
	// Sorts items in the control using the provided callback function.
	//BOOL SortChildrenCB( LPTVSORTCB pSort);
	
	// Terminates label editing operation.
	BOOL EndEditLabelNow(BOOL fCancelWithoutSave);
	
	// Shows information tooltip on the specified item.
	void ShowInfoTip(HTREEITEM hItem);
	
	// Implementation
protected:
	
public:
	// virtual OK here - ~CWnd is virtual
	virtual ~CTreeCtrl();
	//{{AFX_MSG(CTreeCtrl)
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif//CTREECTRL_DEFINE