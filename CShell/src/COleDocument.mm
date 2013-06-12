/*
 *  COleDocument.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDocument.h"
#include "CArchive.h"
#include "CDocItem.h"
#include "COleClientItem.h"
#include "COleServerItem.h"
#include "CFrameWnd.h"

#include "COleDocument.h"

IMPLEMENT_DYNAMIC(COleDocument, CDocument)

COleDocument::COleDocument()
{
	
}

COleDocument::~COleDocument()
{

}

POSITION COleDocument::GetStartPosition() const
{
	NSLog(@"TO DO COleDocument::GetStartPosition");
	
	return NULL;
}

CDocItem* COleDocument::GetNextItem(POSITION& pos) const
{
	NSLog(@"TO DO COleDocument::GetNextItem");
	
	return NULL;
}

void COleDocument::PreCloseFrame(CFrameWnd* pFrame)
{
	NSLog(@"TO DO COleDocument::PreCloseFrame");
}

COleClientItem* COleDocument::GetNextClientItem(POSITION& pos) const
{
	NSLog(@"TO DO COleDocument::GetNextClientItem");
	
	return NULL;
}

COleServerItem* COleDocument::GetNextServerItem(POSITION& pos) const
{
	NSLog(@"TO DO COleDocument::GetNextServerItem");
	
	return NULL;
}

void COleDocument::AddItem(CDocItem* pItem)
{
	NSLog(@"TO DO COleDocument::AddItem");
}

void COleDocument::RemoveItem(CDocItem* pItem)
{
	NSLog(@"TO DO COleDocument::RemoveItem");
}
