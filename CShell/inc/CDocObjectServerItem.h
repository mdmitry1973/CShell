/*
 *  CDocObjectServerItem.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDOCOBJECTSERVERITEM_DEFINE
#define CDOCOBJECTSERVERITEM_DEFINE 1

#include "CDef.h"

#include "COleServerItem.h"

class COleServerDoc;

class CDocObjectServerItem : public COleServerItem
{

public:
	
	CDocObjectServerItem();
	CDocObjectServerItem(COleServerDoc* pServerDoc, BOOL bAutoDelete);
	virtual ~CDocObjectServerItem();
	
	
};

#endif//CDOCOBJECTSERVERITEM_DEFINE