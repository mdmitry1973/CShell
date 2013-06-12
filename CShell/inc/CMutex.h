/*
 *  CMutex.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CMUTEX_DEFINE
#define CMUTEX_DEFINE 1

#include "CSyncObject.h"

class CMutex : public CSyncObject
{
	
public:
	
	CMutex(BOOL bInitiallyOwn = FALSE, LPCTSTR lpszName = NULL,
		   LPSECURITY_ATTRIBUTES lpsaAttribute = NULL);
	virtual ~CMutex();
	
	virtual BOOL Lock(DWORD dwTimeout = INFINITE );
	
	virtual BOOL Unlock(); 
	virtual BOOL Unlock(LONG lCount, LPLONG lpPrevCount = NULL);
	
	operator HANDLE() const;
};

#endif//CMUTEX_DEFINE