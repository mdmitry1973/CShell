/*
 *  CSingleDocTemplate.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CSINGLEDOCTEMPLATE_DEFINE
#define CSINGLEDOCTEMPLATE_DEFINE 1

#include "CDef.h"
#include "CDocTemplate.h"

class CSingleDocTemplate : public CDocTemplate
{

public:
	
	CSingleDocTemplate(UINT nIDResource,
					   CObject* pDocClass,
					   CObject* pFrameClass,
					   CObject* pViewClass);
					   
	virtual ~CSingleDocTemplate();
	
	virtual void AddDocument(CDocument* pDoc);
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);
	virtual void SetDefaultTitle(CDocument* pDocument);
	
protected:
	
	CDocument *m_pOnlyDoc;

};

#endif//CSINGLEDOCTEMPLATE_DEFINE