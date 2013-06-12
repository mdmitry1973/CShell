/*
 *  COleClientItem.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CArchive.h"
#include "CDocItem.h"
#include "CView.h"

#include "COleClientItem.h"

//IMPLEMENT_DYNAMIC(COleServerDoc, COleDocument)

COleClientItem::COleClientItem()
{
	
}

COleClientItem::~COleClientItem()
{

}

void COleClientItem::Delete(BOOL bAutoDelete)
{
	NSLog(@"TO DO COleClientItem::Delete");
}

CView* COleClientItem::GetActiveView() const
{
	NSLog(@"TO DO COleClientItem::GetActiveView");
	
	return NULL;
}