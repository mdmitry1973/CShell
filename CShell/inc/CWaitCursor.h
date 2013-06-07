/*
 *  CWaitCursor.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CWAITCURSOR_DEFINE
#define CWAITCURSOR_DEFINE 1

#include "CDef.h"

class CWaitCursor
{
	// Construction/Destruction
public:
	CWaitCursor();
	~CWaitCursor();
	
	void Restore();
	
	void *m_hWnd;
	void *m_mWindowController;
	void *m_session;
	void *m_timer;
	void *m_helper;
};


#endif//CWAITCURSOR_DEFINE