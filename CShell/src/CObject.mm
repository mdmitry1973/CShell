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
