/*
 *  CObject.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CObject.h"

#import <Cocoa/Cocoa.h>
//NSException.h

CObject::CObject()
{
	
}

CObject::~CObject()
{

}

void CObject::AssertValid( ) const
{
	ASSERT(FALSE);
}

BOOL CObject::IsKindOf(CRuntimeClass *className) const
{
	if (GetClassName().Compare(className->GetClassName()) == 0)
	{ 
		return 1; 
	}
	
	if (GetBaseClassName().Compare(className->GetBaseClassName()) == 0)
	{ 
		return 2; 
	}
	
	return 0;
}

