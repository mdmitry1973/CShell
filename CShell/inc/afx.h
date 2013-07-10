/*
 *  afx.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef AFX
#define AFX 1

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

#ifndef BASED_CODE
#define BASED_CODE
#endif

#define AFX_STATIC_DATA static
#define AFX_STATIC static

void AfxThrowArchiveException(int cause);
void AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName);
void AfxAssertValidObject(const CObject* pOb, LPCSTR lpszFileName, int nLine);
BOOL AfxIsValidAddress(const void* lp, UINT nBytes, BOOL bReadWrite = TRUE); 
BOOL AfxIsValidString(LPCTSTR lpsz, int nLength = -1);
void AfxThrowFileException(int cause, LONG lOsError = -1, LPCTSTR lpszFileName = NULL);
void AfxThrowMemoryException();
void AfxThrowInvalidArgException();
void AfxThrowOleFileException(long );
void AfxThrowOleException(SCODE);

BOOL AfxEnableMemoryTracking(BOOL bTrack);

AFX_MODULE_STATE* AFXAPI AfxGetAppModuleState();

void AfxSetResourceHandle(HINSTANCE hInstResource); 
BOOL AfxSocketInit(void* lpwsaData = NULL);
CSHELL_LIB_EXPORT BOOL AfxOleInit();
COleMessageFilter* AfxOleGetMessageFilter();

HMODULE AfxLoadLibrary(LPCTSTR lpLibFileName);
BOOL AfxFreeLibrary(HMODULE hLibModule);

LPCTSTR AFXAPI AfxRegisterWndClass(UINT nClassStyle, HCURSOR hCursor = 0, HBRUSH hbrBackground = 0, HICON hIcon = 0);

#endif//AFX
