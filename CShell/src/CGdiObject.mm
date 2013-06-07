/*
 *  CGdiObject.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CGdiObject.h"

CGdiObject::CGdiObject()
{
	NSLog(@"TO DO CGdiObject::CGdiObject");
}

CGdiObject::~CGdiObject()
{
	NSLog(@"TO DO CGdiObject::CGdiObject");
}

CGdiObject::operator HGDIOBJ() const
{
	NSLog(@"TO DO CGdiObject::HGDIOBJ");
}

HGDIOBJ CGdiObject::GetSafeHandle() const
{
	NSLog(@"TO DO CGdiObject::GetSafeHandle");
	return NULL;
}

CGdiObject* CGdiObject::FromHandle(HGDIOBJ hObject)
{
	NSLog(@"TO DO CGdiObject::FromHandle");
	return NULL;
}

void CGdiObject::DeleteTempMap()
{
	NSLog(@"TO DO CGdiObject::DeleteTempMap");
}

BOOL CGdiObject::Attach(HGDIOBJ hObject)
{
	NSLog(@"TO DO CGdiObject::Attach");
	return FALSE;
}

HGDIOBJ CGdiObject::Detach()
{
	NSLog(@"TO DO CGdiObject::Detach");
	return NULL;
}

BOOL CGdiObject::DeleteObject()
{
	NSLog(@"TO DO CGdiObject::DeleteObject");
	return FALSE;
}

UINT CGdiObject::GetObjectType() const
{
	NSLog(@"TO DO CGdiObject::GetObjectType");
	return 0;
}

BOOL CGdiObject::CreateStockObject(int nIndex)
{
	NSLog(@"TO DO CGdiObject::CreateStockObject");
	return FALSE;
}

BOOL CGdiObject::UnrealizeObject()
{
	NSLog(@"TO DO CGdiObject::UnrealizeObject");
	return FALSE;
}

BOOL CGdiObject::operator==(const CGdiObject& obj) const
{
	NSLog(@"TO DO CGdiObject::Detach");
	return FALSE;
}

BOOL CGdiObject::operator!=(const CGdiObject& obj) const
{
	NSLog(@"TO DO CGdiObject::Detach");
	return FALSE;
}
