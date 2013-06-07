/*
 *  COleDocument.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef COLEDOCUMENT_DEFINE
#define COLEDOCUMENT_DEFINE 1

#include "CDef.h"

#include "CDocument.h"

class CDocItem;
class COleClientItem;
class COleServerItem;
class CFrameWnd;

class COleDocument : public CDocument
{
	
public:
	
	COleDocument();
	~COleDocument();
	
	virtual POSITION GetStartPosition() const;
	virtual CDocItem* GetNextItem(POSITION& pos) const;
	
	virtual void PreCloseFrame(CFrameWnd* pFrame);
	
	// iterator helpers (helpers use virtual GetNextItem above)
	COleClientItem* GetNextClientItem(POSITION& pos) const;
	COleServerItem* GetNextServerItem(POSITION& pos) const;
	
	// adding new items - called from item constructors
	virtual void AddItem(CDocItem* pItem);
	virtual void RemoveItem(CDocItem* pItem);
	
};


#endif//COLEDOCUMENT_DEFINE