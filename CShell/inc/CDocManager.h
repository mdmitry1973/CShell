/*
 *  CDocManager.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDOCMANAGER_DEFINE
#define CDOCMANAGER_DEFINE 1

#include "CDef.h"

class CDocTemplate;
class CDocument;

class CDocManager
{

public:
	
	CDocManager();
	virtual ~CDocManager();
	
	//Document functions
	virtual void AddDocTemplate(CDocTemplate* pTemplate);
	virtual POSITION GetFirstDocTemplatePosition() const;
	virtual CDocTemplate* GetNextDocTemplate(POSITION& pos) const;
	virtual void RegisterShellFileTypes(BOOL bCompat);
	void UnregisterShellFileTypes();
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName); // open named file
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName, BOOL bAddToMRU); // open named file
	virtual BOOL SaveAllModified(); // save before exit
	virtual void CloseAllDocuments(BOOL bEndSession); // close documents before exiting
	virtual int GetOpenDocumentCount();
	virtual CDocTemplate* GetBestTemplate(LPCTSTR lpszFileName); // return best template named file
	
};

#endif//CDOCMANAGER_DEFINE