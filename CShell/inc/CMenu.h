/*
 *  CMenu.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CMENU_DEFINE
#define CMENU_DEFINE 1

#include "CDef.h"

#include "CString.h"

#include <vector>

class CBitmap;
class CWnd;

class CSHELL_LIB_EXPORT CMenu
{

public:
	
	CMenu();
	virtual ~CMenu();
	
	BOOL Attach(HMENU hMenu);
	
	BOOL CreateMenu();
	
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);
	
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);
	
	BOOL LoadMenu(LPCTSTR lpszResourceName);
	BOOL LoadMenu(UINT nIDResource);
	
	
	BOOL ModifyMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	BOOL ModifyMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);
	
	CMenu* GetSubMenu(int nPos);// const;
	int GetMenuItemCount() const;
	int GetMenuString( UINT nIDItem,  LPTSTR lpString,  int nMaxCount, UINT nFlags) const;
	int GetMenuString(UINT nIDItem, CString& rString, UINT nFlags) const;
	UINT GetMenuItemID(int nPos) const;
	
	BOOL DeleteMenu(UINT nPosition, UINT nFlags);
	
	UINT CheckMenuItem(UINT nIDCheckItem, UINT nCheck);
	
	BOOL TrackPopupMenu(UINT nFlags, int x, int y, CWnd* pWnd, LPCRECT lpRect = 0);
	
	void SetNSMenu(void *menu, CWnd *owner);
	BOOL MenuParser(void *currentMenu, void *rootMenuNode);
	void *GetNSMenu();

    static std::map<std::string, long> &GetStandardCommand();

	void *m_NMenu;
	CWnd *m_owner;
	
	std::vector<CMenu*>		mMapSumMenu;
};

#endif//CMENU_DEFINE
