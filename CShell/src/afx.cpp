/*
 *  afx.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CDef.h"

#include "CObject.h"
#include "COleMessageFilter.h"

#include "afx.h"
#include "winbase.h"


void AfxThrowInvalidArgException()
{
    qDebug() << "TO DO AfxThrowInvalidArgException";
}

void AfxThrowArchiveException(int cause)
{
    qDebug() << "TO DO AfxThrowArchiveException";
}

void AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName)
{
    qDebug() << "TO DO AfxThrowArchiveException";
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

BOOL AfxIsValidString(LPCTSTR lpsz, int nLength )
{
	ASSERT(lpsz[nLength]);
	
	return TRUE;
}

void AfxThrowFileException(int cause, LONG lOsError, LPCTSTR lpszFileName)
{
    qDebug() << "TO DO AfxThrowFileException";
}

void AfxThrowMemoryException()
{
    qDebug() << "TO DO AfxThrowMemoryException";
}

void AfxThrowOleFileException(long )
{
    qDebug() << "TO DO AfxThrowOleFileException";
}

void AfxThrowOleException(SCODE)
{
    qDebug() << "TO DO AfxThrowOleException";
}

void AfxSetResourceHandle(HINSTANCE hInstResource)
{
    qDebug() << "TO DO AfxSetResourceHandle";
}

BOOL AfxEnableMemoryTracking(BOOL bTrack)
{
    qDebug() << "TO DO AfxEnableMemoryTracking";
	
	return bTrack;
}

BOOL AfxSocketInit(void* lpwsaData)
{
    qDebug() << "TO DO AfxSocketInit";
    return TRUE;
}

BOOL AfxOleInit()
{
    qDebug() << "TO DO AfxOleInit";
    return TRUE;
}

COleMessageFilter* AfxOleGetMessageFilter()
{
    qDebug() << "TO DO AfxOleGetMessageFilter";
	
	return NULL;
}

HMODULE AfxLoadLibrary(LPCTSTR lpLibFileName)
{
	return LoadLibrary(lpLibFileName);
}

BOOL AfxFreeLibrary(HMODULE hLibModule)
{
	return FreeLibrary(hLibModule);
}
