/*
 *  CRuntimeClass.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CRuntimeClass.h"

CRuntimeClass::CRuntimeClass()
{
	//NSLog(@"to do CRuntimeClass");
}

CRuntimeClass::~CRuntimeClass()
{
	//NSLog(@"to do CRuntimeClass");
}
	
CObject* CRuntimeClass::CreateObject()
{
	NSLog(@"to do CRuntimeClass CreateObject");
	return NULL;
}

CObject* CRuntimeClass::CreateObjectStatic()
{
	NSLog(@"to do CRuntimeClass CreateObjectStatic");
	return NULL;
}

BOOL CRuntimeClass::IsDerivedFrom(const CRuntimeClass* pBaseClass) const
{
	NSLog(@"to do CRuntimeClass IsDerivedFrom");
	return FALSE;
}
	
CRuntimeClass* CRuntimeClass::FromName(LPCSTR lpszClassName)
{
	NSLog(@"to do CRuntimeClass FromName");
	return NULL;
}

//CObject* CRuntimeClass::CreateObject(LPCSTR lpszClassName)
//{
//	NSLog(@"to do CRuntimeClass CreateObject");
//	return NULL;
//}
	