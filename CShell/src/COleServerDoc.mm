/*
 *  COleServerDoc.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CArchive.h"
#include "CDocItem.h"
#include "COleClientItem.h"
#include "COleServerItem.h"
#include "CFrameWnd.h"
#include "COleDocument.h"

#include "COleServerDoc.h"

IMPLEMENT_DYNAMIC(COleServerDoc, COleDocument)

COleServerDoc::COleServerDoc()
{
	
}

COleServerDoc::~COleServerDoc()
{

}

BOOL COleServerDoc::IsEmbedded() const
{
	NSLog(@"TO DO COleServerDoc::IsEmbedded");
	
	return FALSE;
}

BOOL COleServerDoc::IsDocObject() const
{
	NSLog(@"TO DO COleServerDoc::IsDocObject");
	
	return FALSE;
}

COleServerItem* COleServerDoc::GetEmbeddedItem()
{
	NSLog(@"TO DO COleServerDoc::GetEmbeddedItem");
	
	return NULL;
}

BOOL COleServerDoc::IsInPlaceActive() const
{
	NSLog(@"TO DO COleServerDoc::IsInPlaceActive");
	
	return FALSE;
}

void COleServerDoc::GetItemPosition(LPRECT lpPosRect) const
{
	NSLog(@"TO DO COleServerDoc::GetItemPosition");
}

void COleServerDoc::GetItemClipRect(LPRECT lpClipRect) const
{
	NSLog(@"TO DO COleServerDoc::GetItemClipRect");
}

void COleServerDoc::NotifyChanged()
{
	NSLog(@"TO DO COleServerDoc::NotifyChanged");
}

void COleServerDoc::NotifyRename(LPCTSTR lpszNewName)
{
	NSLog(@"TO DO COleServerDoc::NotifyRename");
}

void COleServerDoc::NotifySaved()
{
	NSLog(@"TO DO COleServerDoc::NotifySaved");
}

void COleServerDoc::NotifyClosed()
{
	NSLog(@"TO DO COleServerDoc::NotifyClosed");
}

void COleServerDoc::SaveEmbedding()
{
	NSLog(@"TO DO COleServerDoc::SaveEmbedding");
}

BOOL COleServerDoc::ActivateInPlace()
{
	NSLog(@"TO DO COleServerDoc::ActivateInPlace");
	
	return FALSE;
}

void COleServerDoc::ActivateDocObject()
{
	NSLog(@"TO DO COleServerDoc::ActivateDocObject");
}

void COleServerDoc::RequestPositionChange(LPCRECT lpPosRect)
{
	NSLog(@"TO DO COleServerDoc::RequestPositionChange");
}

BOOL COleServerDoc::ScrollContainerBy(CSize sizeScroll)
{
	NSLog(@"TO DO COleServerDoc::ScrollContainerBy");
	
	return FALSE;
}

BOOL COleServerDoc::DeactivateAndUndo()
{
	NSLog(@"TO DO COleServerDoc::DeactivateAndUndo");
	
	return FALSE;
}

BOOL COleServerDoc::DiscardUndoState()
{
	NSLog(@"TO DO COleServerDoc::DiscardUndoState");
	
	return FALSE;
}

BOOL COleServerDoc::OnUpdateDocument()
{
	NSLog(@"TO DO COleServerDoc::OnUpdateDocument");
	
	return FALSE;
}

void COleServerDoc::OnDeactivate()
{
	NSLog(@"TO DO COleServerDoc::OnDeactivate");
}

void COleServerDoc::OnDeactivateUI(BOOL bUndoable)
{
	NSLog(@"TO DO COleServerDoc::OnDeactivateUI");
}

void COleServerDoc::OnDocWindowActivate(BOOL bActivate)
{
	NSLog(@"TO DO COleServerDoc::OnDocWindowActivate");
}

void COleServerDoc::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
	NSLog(@"TO DO COleServerDoc::OnShowControlBars");
}

BOOL COleServerDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	NSLog(@"TO DO COleServerDoc::OnSaveDocument");
	
	return FALSE;
}

void COleServerDoc::OnCloseDocument()
{
	NSLog(@"TO DO COleServerDoc::OnCloseDocument");
}

void COleServerDoc::DeleteContents()
{
	NSLog(@"TO DO COleServerDoc::DeleteContents");
}

COleServerItem* COleServerDoc::OnGetLinkedItem(LPCTSTR lpszItemName)
{
	NSLog(@"TO DO COleServerDoc::OnGetLinkedItem");
}

BOOL COleServerDoc::CanCloseFrame(CFrameWnd* pFrame)
{
	NSLog(@"TO DO COleServerDoc::CanCloseFrame");
	
	return FALSE;
}

void COleServerDoc::UpdateAllItems(COleServerItem* pSender, LPARAM lHint, CObject* pHint,
					DVASPECT nDrawAspect)
{
	NSLog(@"TO DO COleServerDoc::UpdateAllItems");
}