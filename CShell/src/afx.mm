/*
 *  afx.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CObject.h"

#include "afx.h"

#import <Cocoa/Cocoa.h>

void AfxThrowInvalidArgException()
{
	NSLog(@"TO DO AfxThrowInvalidArgException");
}

void AfxThrowArchiveException(int cause)
{
	NSLog(@"TO DO AfxThrowArchiveException");
}

void AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName)
{
	NSLog(@"TO DO AfxThrowArchiveException");
}

void AfxAssertValidObject(const CObject* pOb, LPCSTR lpszFileName, int nLine)
{
	ASSERT(pOb != NULL);
}

BOOL AfxIsValidAddress(const void* lp, UINT nBytes, BOOL bReadWrite)
{
	ASSERT(lp != NULL);
	
	return TRUE;
}

BOOL AfxIsValidString(LPCSTR lpsz, int nLength )
{
	ASSERT(lpsz[nLength] == NULL);
	
	return TRUE;
}

void AfxThrowFileException(int cause, LONG lOsError, LPCTSTR lpszFileName)
{
	NSLog(@"TO DO AfxThrowFileException");
}

void AfxThrowMemoryException()
{
	NSLog(@"TO DO AfxThrowMemoryException");
}
