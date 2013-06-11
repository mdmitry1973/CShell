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
					  CRuntimeClass* pDocClass,
					  CRuntimeClass* pFrameClass,
					  CRuntimeClass* pViewClass);
					  
	virtual ~CMultiDocTemplate();	
	
	virtual BOOL GetDocString(CString& rString, enum DocStringIndex index) const; // get one of the info strings
	
	virtual void AddDocument(CDocument* pDoc);
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE);
	virtual void SetDefaultTitle(CDocument* pDocument);
	
	virtual POSITION GetFirstDocPosition() const;
	virtual CDocument* GetNextDoc(POSITION& rPos) const;
	
private:
	
	std::vector<CDocument*> m_docList;
};

#endif//CMULTIDOCTEMPLATE_DEFINE