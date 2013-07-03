/*
 *  CRuntimeClass.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CDef.h"
#include "CRuntimeClass.h"

CRuntimeClass::CRuntimeClass()
{

}

CRuntimeClass::~CRuntimeClass()
{

}
	
CObject* CRuntimeClass::CreateObject()
{
    qDebug() << "to do CRuntimeClass CreateObject";
	return NULL;
}

CObject* CRuntimeClass::CreateObjectStatic()
{
    qDebug() << "to do CRuntimeClass CreateObjectStatic";
	return NULL;
}

BOOL CRuntimeClass::IsDerivedFrom(const CRuntimeClass* pBaseClass) const
{
    qDebug() << "to do CRuntimeClass IsDerivedFrom";
	return FALSE;
}
	
CRuntimeClass* CRuntimeClass::FromName(LPCSTR lpszClassName)
{
    qDebug() << "to do CRuntimeClass FromName";
	return NULL;
}

//CObject* CRuntimeClass::CreateObject(LPCSTR lpszClassName)
//{
//	NSLog(@"to do CRuntimeClass CreateObject");
//	return NULL;
//}
	
