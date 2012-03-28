/*
 *  CMultiDocTemplate.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CMULTIDOCTEMPLATE_DEFINE
#define CMULTIDOCTEMPLATE_DEFINE 1

#include "CDef.h"
#include "CDocTemplate.h"

class CMultiDocTemplate : public CDocTemplate
{

public:
	
	CMultiDocTemplate(UINT nIDResource,
					  CObject* pDocClass,
					  CObject* pFrameClass,
					  CObject* pViewClass);
					  
	virtual ~CMultiDocTemplate();	
	
	virtual void AddDocument(CDocument* pDoc);
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);
	virtual void SetDefaultTitle(CDocument* pDocument);
};

#endif//CMULTIDOCTEMPLATE_DEFINE