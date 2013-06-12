/*
 *  COleServerDoc.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef COLESERVERDOC_DEFINE
#define COLESERVERDOC_DEFINE 1

#include "CDef.h"

#include "COleDocument.h"

class COleServerDoc : public COleDocument
{
	// Constructors
public:
	COleServerDoc();
	
	~COleServerDoc();
	
	// Attributes
	BOOL IsEmbedded() const;    // TRUE if document is an embedding
	BOOL IsDocObject() const;   // TRUE if document is a DocObject
	COleServerItem* GetEmbeddedItem();
	// return embedded item for document (will allocate if necessary)
	
	// attributes specific to in-place activation
	BOOL IsInPlaceActive() const;
	void GetItemPosition(LPRECT lpPosRect) const;
	// get current position rectangle of in-place edit
	void GetItemClipRect(LPRECT lpClipRect) const;
	// get current clipping rectangle of in-place edit
	//BOOL GetZoomFactor(LPSIZE lpSizeNum = NULL, LPSIZE lpSizeDenom = NULL,
	//				   LPCRECT lpPosRect = NULL) const;
	// returns the zoom factor in pixels
	
	// Operations
	void NotifyChanged();
	// call this after you change some global attribute like
	//  document dimensions
	//void UpdateAllItems(COleServerItem* pSender,
	//					LPARAM lHint = 0L, CObject* pHint = NULL,
	//					DVASPECT nDrawAspect = DVASPECT_CONTENT);
	
	// changes to the entire document (automatically notifies clients)
	void NotifyRename(LPCTSTR lpszNewName);
	void NotifySaved();
	void NotifyClosed();        // call this after you close document
	
	// specific operations for embedded documents
	void SaveEmbedding();       // call this to save embedded (before closing)
	
	// specific to in-place activation
	BOOL ActivateInPlace();
	void ActivateDocObject();
	void RequestPositionChange(LPCRECT lpPosRect);
	BOOL ScrollContainerBy(CSize sizeScroll);
	BOOL DeactivateAndUndo();
	BOOL DiscardUndoState();
	
public:
	// Overridables for standard user interface (full server)
	virtual BOOL OnUpdateDocument(); // implementation of embedded update
	

public:
	virtual void OnDeactivate();
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual void OnDocWindowActivate(BOOL bActivate);
	virtual void OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow);
	//virtual void OnResizeBorder(LPCRECT lpRectBorder,
	//							LPOLEINPLACEUIWINDOW lpUIWindow, BOOL bFrame);
	
	//LPOLECLIENTSITE GetClientSite() const;
	

#ifdef _DEBUG
	//virtual void AssertValid() const;
	//virtual void Dump(CDumpContext& dc) const;
#endif
	
	// overridables for implementation
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
	virtual void DeleteContents(); // delete auto-delete server items
	//virtual LPMONIKER GetMoniker(OLEGETMONIKER nAssign);
	virtual COleServerItem* OnGetLinkedItem(LPCTSTR lpszItemName);
	// return item for the named linked item (only if supporting links)
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	
	void UpdateAllItems(COleServerItem* pSender, LPARAM lHint = 0L, CObject* pHint = NULL,
						DVASPECT nDrawAspect = DVASPECT_CONTENT);
	
	DECLARE_DYNAMIC(COleServerDoc)
};


#endif//COLESERVERDOC_DEFINE