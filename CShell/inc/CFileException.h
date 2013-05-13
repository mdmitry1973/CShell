/*
 *  CFileException.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CFILEEXCEPTION_DEFINE
#define CFILEEXCEPTION_DEFINE 1

#include "CException.h"
#include "CString.h"

class CFileException  : public CException
{
	
public:
	enum {
		none,
		generic,
		genericException,
		fileNotFound,
		badPath,
		tooManyOpenFiles,
		accessDenied,
		invalidFile,
		removeCurrentDir,
		directoryFull,
		badSeek,
		hardIO,
		sharingViolation,
		lockViolation,
		diskFull,
		endOfFile
	};
	
//#pragma warning(push)
//#pragma warning(disable:4996)
//	AFX_DEPRECATED("CFileException::generic clashes with future language keyword generic and should not be used. Use CFileException::genericException instead.") static const int __identifier(generic) = genericException;
//#pragma warning(pop)
	
	// Constructor
	/* explicit */ CFileException(int cause = CFileException::none, LONG lOsError = -1,
								  LPCTSTR lpszArchiveName = NULL);
	
	// Attributes
	int     m_cause;
	LONG    m_lOsError;
	CString m_strFileName;
	
	// Operations
	// convert a OS dependent error code to a Cause
	static int OsErrorToException(LONG lOsError);
	static int ErrnoToException(int nErrno);
	
	// helper functions to throw exception after converting to a Cause
	static void ThrowOsError(LONG lOsError, LPCTSTR lpszFileName = NULL);
	static void ThrowErrno(int nErrno, LPCTSTR lpszFileName = NULL);
	
	// Implementation
public:
	virtual ~CFileException();
//#ifdef _DEBUG
//	virtual void Dump(CDumpContext&) const;
//#endif
	virtual BOOL GetErrorMessage(LPTSTR lpszError, UINT nMaxError, UINT *pnHelpContext = NULL) const;
	
};

#endif//CFILEEXCEPTION_DEFINE