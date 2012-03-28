/*
 *  CDocTemplate.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDOCTEMPLATE_DEFINE
#define CDOCTEMPLATE_DEFINE 1

#include "CDef.h"
#include "CTargetEvent.h"

class CFrameWnd;
class CDocument;

class CDocTemplate : public CCmdTarget
{

public:
	
	CDocTemplate(UINT nIDResource,
				  CObject* pDocClass,
				  CObject* pFrameClass,
				  CObject* pViewClass);
				  
	virtual ~CDocTemplate();
	
	virtual void AddDocument(CDocument* pDoc);
	virtual void CloseAllDocuments(BOOL bEndSession);
	virtual CDocument* CreateNewDocument();
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE) = 0;
	virtual void RemoveDocument(CDocument* pDoc);
	
	virtual void SetDefaultTitle(CDocument* pDocument) = 0;
	
	
	//not mfc methods
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType);
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType);
	
protected:

	UINT		m_nIDResource;
	CObject*	m_pDocClass;
	CObject*	m_pFrameClass;
	CObject*	m_pViewClass;

};

#endif//CDOCTEMPLATE_DEFINE