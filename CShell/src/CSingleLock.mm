/*
 *  CSingleLock.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "winbase.h"

#include "CSingleLock.h"

CSingleLock::CSingleLock()
{
	//m_hObject = NULL;
	
	NSLock *theLock = [[NSLock alloc] init];
	
	//[theLock setName: [NSString stringWithUTF8String: lpszName]];	
	m_hObject = theLock;
	m_IsLocked = FALSE;
}

CSingleLock::CSingleLock(CSyncObject* pObject, BOOL bInitialLock )
{
	NSLock *theLock = (NSLock *)pObject->m_hObject;
	NSString *strName = [theLock name];
	
	NSLock *theLock1 = [[NSLock alloc] init];
	
	[theLock1 setName: strName];
	
	m_hObject = theLock1;
}

CSingleLock::~CSingleLock()
{
	if (m_hObject)
	{
		NSLock *theLock = (NSLock *)m_hObject;
		
		[theLock release];
	}
}

BOOL CSingleLock::Lock(DWORD dwTimeout)
{
	NSLock *theLock = (NSLock *)m_hObject;
	[theLock lock];
	m_IsLocked = TRUE;
	return TRUE;
}

BOOL CSingleLock::Unlock()
{
	NSLock *theLock = (NSLock *)m_hObject;
	[theLock unlock];
	m_IsLocked = FALSE;
	return TRUE;
}

BOOL CSingleLock::Unlock(LONG lCount, LPLONG lpPrevCount )
{
	NSLock *theLock = (NSLock *)m_hObject;
	[theLock unlock];
	m_IsLocked = FALSE;
	return TRUE;
}

BOOL CSingleLock::IsLocked()
{
	return m_IsLocked;
}

