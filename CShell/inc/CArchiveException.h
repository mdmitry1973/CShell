/*
 *  CArchiveException.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CARCHIVEEXCEPTION_DEFINE
#define CARCHIVEEXCEPTION_DEFINE 1

#include "CException.h"

class CArchiveException : public CException
{
	
public:
	
	CArchiveException();
	virtual ~CArchiveException();
	
	enum{
		none,
		genericException,
		readOnly,
		endOfFile,
		writeOnly,
		badIndex,
		badClass,
		badSchema,
		bufferFull
	};
	
	int m_cause;
};

#endif//CARCHIVEEXCEPTION_DEFINE