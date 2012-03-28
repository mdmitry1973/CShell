/*
 *  CDocument.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDOCUMENT_DEFINE
#define CDOCUMENT_DEFINE 1

#include "CDef.h"

#include "CTargetEvent.h"

class CDocument : public CCmdTarget
{

public:
	
	CDocument();
	//CDocument(const CDocument &);
	virtual ~CDocument();
	
	virtual BOOL OnNewDocument();	
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);	
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
								
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType);
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType);
	
};

#endif//CDOCUMENT_DEFINE