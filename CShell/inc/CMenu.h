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

class CBitmap;
class CWnd;

class CMenu
{

public:
	
	CMenu();
	virtual ~CMenu();
	
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);
	
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
	BOOL InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp);
	
	BOOL LoadMenu(LPCTSTR lpszResourceName);
	BOOL LoadMenu(UINT nIDResource);
	
	void SetNSMenu(void *menu, CWnd *owner);
	BOOL MenuParser(void *currentMenu, void *rootMenuNode);
	void *GetNSMenu();
	
	void *m_NMenu;
	CWnd *m_owner;
};

#endif//CMENU_DEFINE