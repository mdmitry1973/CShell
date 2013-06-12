/*
 *  CMutex.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "winbase.h"

#include "CMutex.h"

CMutex::CMutex(BOOL bInitiallyOwn, LPCTSTR lpszName,  LPSECURITY_ATTRIBUTES lpsaAttribute)
{
	m_hObject = NULL;
	
	NSRecursiveLock *theLock = [[NSRecursiveLock alloc] init];
	
	[theLock setName: [NSString stringWithUTF8String: lpszName]];	
	m_hObject = theLock;
}

CMutex::~CMutex()
{
	if (m_hObject)
	{
		NSRecursiveLock *theLock = (NSRecursiveLock *)m_hObject;
		
		[theLock release];
	}
}

BOOL CMutex::Lock(DWORD dwTimeout)
{
	NSRecursiveLock *theLock = (NSRecursiveLock *)m_hObject;
	[theLock lock];
	return TRUE;
}

BOOL CMutex::Unlock()
{
	NSRecursiveLock *theLock = (NSRecursiveLock *)m_hObject;
	[theLock unlock];
	return TRUE;
}

BOOL CMutex::Unlock(LONG lCount, LPLONG lpPrevCount )
{
	NSRecursiveLock *theLock = (NSRecursiveLock *)m_hObject;
	[theLock unlock];
	return TRUE;
}

CMutex::operator HANDLE() const
{
	return m_hObject;
}
