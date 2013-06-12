/*
 *  CSyncObject.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CSYNCOBJECT_DEFINE
#define CSYNCOBJECT_DEFINE 1

class CSyncObject
{
	
public:
	
	CSyncObject(BOOL bInitiallyOwn = FALSE, LPCTSTR lpszName = NULL,
				LPSECURITY_ATTRIBUTES lpsaAttribute = NULL){}
	virtual ~CSyncObject(){}
	
	virtual BOOL Lock(DWORD dwTimeout = INFINITE ){ return TRUE; }
	
	virtual BOOL Unlock() = 0; 
	virtual BOOL Unlock(LONG lCount, LPLONG lpPrevCount = NULL){ return TRUE; }
	
	operator HANDLE() const{ return m_hObject; }
	
	HANDLE m_hObject;
	
};

#endif//CMUTEX_DEFINE