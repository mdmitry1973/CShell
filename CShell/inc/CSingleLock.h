/*
 *  CSingleLock.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CSINGLELOCK_DEFINE
#define CSINGLELOCK_DEFINE 1

#include "CDef.h"

#include "CSyncObject.h"

class CSingleLock
{

public:
	
	CSingleLock();
	CSingleLock(CSyncObject* pObject,
				BOOL bInitialLock = FALSE );
	~CSingleLock();
	
	BOOL Lock(DWORD dwTimeOut = INFINITE);
	BOOL Unlock();
	BOOL Unlock(LONG lCount, LPLONG lPrevCount = NULL);
	BOOL IsLocked();
	
	HANDLE	m_hObject;
	BOOL	m_IsLocked;
};

#endif//CSINGLELOCK_DEFINE