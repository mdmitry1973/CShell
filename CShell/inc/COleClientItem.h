/*
 *  COleClientItem.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef COLECLIENTITEM_DEFINE
#define COLECLIENTITEM_DEFINE 1

#include "CDef.h"

#include "CDocItem.h"

class CView;

class COleClientItem : public CDocItem
{
	// Constructors
public:
	COleClientItem();
	
	~COleClientItem();
	
	void Delete(BOOL bAutoDelete = TRUE);
	
	CView* GetActiveView() const;
	
};


#endif//COLECLIENTITEM_DEFINE