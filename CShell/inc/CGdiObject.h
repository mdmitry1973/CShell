/*
 *  CPen.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CGDIOBJECT_DEFINE
#define CGDIOBJECT_DEFINE 1

#include "CDef.h"
#include "CObject.h"

class CGdiObject : public CObject
{
	//DECLARE_DYNCREATE(CGdiObject)
public:
	
	// Attributes
	HGDIOBJ m_hObject;                  // must be first data member
	operator HGDIOBJ() const;
	HGDIOBJ GetSafeHandle() const;
	
	static CGdiObject* FromHandle(HGDIOBJ hObject);
	static void DeleteTempMap();
	BOOL Attach(HGDIOBJ hObject);
	HGDIOBJ Detach();
	
	// Constructors
	CGdiObject(); // must Create a derived class object
	virtual ~CGdiObject();
	
	BOOL DeleteObject();
	
	// Operations
//#pragma push_macro("GetObject")
///#undef GetObject
//	int _AFX_FUNCNAME(GetObject)(int nCount, LPVOID lpObject) const;
//	int GetObject(int nCount, LPVOID lpObject) const;
//#pragma pop_macro("GetObject")
	UINT GetObjectType() const;
	BOOL CreateStockObject(int nIndex);
	BOOL UnrealizeObject();
	BOOL operator==(const CGdiObject& obj) const;
	BOOL operator!=(const CGdiObject& obj) const;
	

};


#endif//CGDIOBJECT_DEFINE