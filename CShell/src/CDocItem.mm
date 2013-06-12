/*
 *  CDocItem.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CArchive.h"
#include "CDocument.h"

#include "CDocItem.h"

//IMPLEMENT_DYNAMIC(COleServerDoc, COleDocument)

CDocItem::CDocItem()
{
	
}

CDocItem::~CDocItem()
{

}

CDocument* CDocItem::GetDocument() const
{
	NSLog(@"TO DO CDocItem::GetDocument");
	
	return NULL;
}

BOOL CDocItem::IsBlank() const
{
	NSLog(@"TO DO CDocItem::IsBlank");
	
	return FALSE;
}

void CDocItem::Serialize(CArchive& ar)
{
	NSLog(@"TO DO CDocItem::Serialize");
}