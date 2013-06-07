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

class CSingleLock
{

public:
	
	CSingleLock();
	~CSingleLock();
	
	// Constructors
//public:
//	explicit CSingleLock(CSyncObject* pObject, BOOL bInitialLock = FALSE);
	
	// Operations
public:
	BOOL Lock(DWORD dwTimeOut = INFINITE);
	BOOL Unlock();
	BOOL Unlock(LONG lCount, LPLONG lPrevCount = NULL);
	BOOL IsLocked();
	
		
//protected:
//	CSyncObject* m_pObject;
//	HANDLE  m_hObject;
//	BOOL    m_bAcquired;
};

#endif//CSINGLELOCK_DEFINE