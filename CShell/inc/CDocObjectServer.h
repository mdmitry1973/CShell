/*
 *  CDocObjectServer.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDOCOBJECTSERVER_DEFINE
#define CDOCOBJECTSERVER_DEFINE 1

#include "CDef.h"

#include "CTargetEvent.h"

class COleServerDoc;

class CDocObjectServer 
{

public:
	
	CDocObjectServer();
	CDocObjectServer(COleServerDoc* pOwner, LPOLEDOCUMENTSITE pDocSite = NULL);
	virtual ~CDocObjectServer();
	
	
};

#endif//CDOCOBJECTSERVER_DEFINE