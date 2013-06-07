/*
 *  CRuntimeClass.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CRUNTIME_DEFINE
#define CRUNTIME_DEFINE 1

#include "CDef.h"

#include "CString.h"

class CObject;

class CRuntimeClass
{

public:
	
	CRuntimeClass();
	virtual ~CRuntimeClass();
	
	virtual CString GetClassName() const 
	{ 
		return "CRuntimeClass"; 
	}
	
	virtual CString GetBaseClassName() const 
	{ 
		return "CRuntimeClass"; 
	}
	
	// Operations
	CObject* CreateObject();
	BOOL IsDerivedFrom(const CRuntimeClass* pBaseClass) const;
	
	// dynamic name lookup and creation
	static CRuntimeClass* FromName(LPCSTR lpszClassName);
	//static CRuntimeClass* FromName(LPCWSTR lpszClassName);
	static CObject* CreateObject(LPCSTR lpszClassName);
	//static CObject* CreateObject(LPCWSTR lpszClassName);
	
};

#endif//CRUNTIME_DEFINE