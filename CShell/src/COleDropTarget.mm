/*
 *  COleDropTarget.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CWnd.h"

#include "COleDropTarget.h"

//IMPLEMENT_DYNAMIC(COleServerDoc, COleDocument)

COleDropTarget::COleDropTarget()
{
	
}

COleDropTarget::~COleDropTarget()
{

}

BOOL COleDropTarget::Register(CWnd* pWnd)
{
	NSLog(@"TO DO COleDropTarget::Register");
	
	return FALSE;
}

void COleDropTarget::Revoke()
{
	NSLog(@"TO DO COleDropTarget::Revoke");
}
