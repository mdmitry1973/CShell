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
/*
template<class type> inline type max(const type a, const type b) { 
	return(((a) > (b)) ? (a) : (b));
}

template<class type> inline type min(const type a, const type b) {  
	return (((a) < (b)) ? (a) : (b));
}

*/

void AfxThrowArchiveException(int cause);
void AfxThrowArchiveException(int cause, LPCTSTR lpszArchiveName);
void AfxAssertValidObject(const CObject* pOb, LPCSTR lpszFileName, int nLine);
BOOL AfxIsValidAddress(const void* lp, UINT nBytes, BOOL bReadWrite = TRUE); 
BOOL AfxIsValidString(LPCSTR lpsz, int nLength = -1);
void AfxThrowFileException(int cause, LONG lOsError = -1, LPCTSTR lpszFileName = NULL);
void AfxThrowMemoryException();
void AfxThrowInvalidArgException();

AFX_MODULE_STATE* AFXAPI AfxGetAppModuleState();


#endif//AFX