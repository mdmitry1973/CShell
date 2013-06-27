/*
 *  CObject.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef COBJECT_DEFINE
#define COBJECT_DEFINE 1

#include "CDef.h"
#include "CRuntimeClass.h"
#include "CString.h"

class CSHELL_LIB_EXPORT CObject : public CRuntimeClass
{
	
public:
	
	CObject();
	virtual ~CObject();
	
	BOOL IsKindOf(CRuntimeClass *className) const;
	
	virtual CString GetClassName() const 
	{ 
        return _T("CObject");
	}
	
	virtual CString GetBaseClassName() const 
	{ 
        return _T("CObject");
	}
	
	virtual CObject* CreateObject() 
	{ 
		return new CObject; 
	}
	
	static CObject* CreateObjectStatic() 
	{ 
		return new CObject; 
	}
	
	virtual void AssertValid( ) const;
	
protected:

};

BOOL AfxAssertObjectValid(const CObject *pOb);

#endif//COBJECT_DEFINE
