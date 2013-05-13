/*
 *  CCmdUI.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CCMDUI_DEFINE
#define CCMDUI_DEFINE 1

#include "CWnd.h"

class CCmdUI        // simple helper class
{
public:
	// Attributes
	UINT m_nID;
	UINT m_nIndex;          // menu item or other index
	
	// if a menu item
	CMenu* m_pMenu;         // NULL if not a menu
	CMenu* m_pSubMenu;      // sub containing menu item
	// if a popup sub menu - ID is for first in popup
	
	// if from some other window
	CWnd* m_pOther;         // NULL if a menu or not a CWnd
	
	// Operations to do in ON_UPDATE_COMMAND_UI
	virtual void Enable(BOOL bOn = TRUE);
	virtual void SetCheck(int nCheck = 1);   // 0, 1 or 2 (indeterminate)
	virtual void SetRadio(BOOL bOn = TRUE);
	virtual void SetText(LPCTSTR lpszText);
	
	// Advanced operation
	void ContinueRouting();
	
	// Implementation
	CCmdUI();
	BOOL m_bEnableChanged;
	BOOL m_bContinueRouting;
	UINT m_nIndexMax;       // last + 1 for iterating m_nIndex
	
	CMenu* m_pParentMenu;   // NULL if parent menu not easily determined
	//  (probably a secondary popup menu)
	
	BOOL DoUpdate(CCmdTarget* pTarget, BOOL bDisableIfNoHndler);
	
};

#endif//CCMDUI_DEFINE