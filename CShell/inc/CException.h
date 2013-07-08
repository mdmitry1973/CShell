/*
 *  CException.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CEXCEPTION_DEFINE
#define CEXCEPTION_DEFINE 1

#include "CObject.h"

class CSHELL_LIB_EXPORT CException : public CObject
{
	
public:
	
	CException();
	virtual ~CException();
	
	void Delete();
	
};

#endif//CEXCEPTION_DEFINE
