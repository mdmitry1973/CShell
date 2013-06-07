/*
 *  afx.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef AFX
#define AFXN 1

#define __AFX_H__

#include "CDef.h"


class CObject;
class COleMessageFilter;

/*
template<class type> inline type max(const type a, const type b) { 
	return(((a) > (b)) ? (a) : (b));
}

template<class type> inline type min(const type a, const type b) {  
	return (((a) < (b)) ? (a) : (b));
}

*/

#define AFX_STATIC_DATA static
#define AFX_STATIC static

void AfxThrowArchiveException(int cause);
void AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName);
void AfxAssertValidObject(const CObject* pOb, LPCSTR lpszFileName, int nLine);
BOOL AfxIsValidAddress(const void* lp, UINT nBytes, BOOL bReadWrite = TRUE); 
BOOL AfxIsValidString(LPCSTR lpsz, int nLength = -1);
void AfxThrowFileException(int cause, LONG lOsError = -1, LPCTSTR lpszFileName = NULL);
void AfxThrowMemoryException();
void AfxThrowInvalidArgException();
void AfxThrowOleFileException(long );
void AfxThrowOleException(SCODE);

BOOL AfxEnableMemoryTracking(BOOL bTrack);

AFX_MODULE_STATE* AFXAPI AfxGetAppModuleState();

void AfxSetResourceHandle(HINSTANCE hInstResource); 
BOOL AfxSocketInit(void* lpwsaData = NULL);
BOOL AfxOleInit();
COleMessageFilter* AfxOleGetMessageFilter();

HMODULE AfxLoadLibrary(LPCSTR lpLibFileName);
BOOL AfxFreeLibrary(HMODULE hLibModule);


#endif//AFX