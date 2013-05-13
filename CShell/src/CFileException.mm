/*
 *  CFileException.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CFileException.h"

CFileException::CFileException(int cause, LONG lOsError, LPCTSTR lpszArchiveName)
{
	
}

CFileException::~CFileException()
{
	
}

int CFileException::OsErrorToException(LONG lOsError)
{
	return 0;
}

int CFileException::ErrnoToException(int nErrno)
{
	return 0;
}

void CFileException::ThrowOsError(LONG lOsError, LPCTSTR lpszFileName)
{
	
}

void CFileException::ThrowErrno(int nErrno, LPCTSTR lpszFileName)
{
	
}

BOOL CFileException::GetErrorMessage(LPTSTR lpszError, UINT nMaxError, UINT *pnHelpContext) const
{
	return FALSE;
}


