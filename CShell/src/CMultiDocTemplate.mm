/*
 *  CMultiDocTemplate.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */
 
#include "CObject.h"
#include "CDocument.h"
#include "CFrameWnd.h"

#include "CMultiDocTemplate.h"

CMultiDocTemplate::CMultiDocTemplate(UINT nIDResource,
				  CRuntimeClass* pDocClass,
				  CRuntimeClass* pFrameClass,
				CRuntimeClass* pViewClass) : CDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{

}

CMultiDocTemplate::~CMultiDocTemplate()
{
	
}

BOOL CMultiDocTemplate::GetDocString(CString& rString, enum DocStringIndex index) const
{
	NSLog(@"TO DO CMultiDocTemplate::GetDocString");
}

void CMultiDocTemplate::AddDocument(CDocument* pDoc)
{
	NSLog(@"TO DO CMultiDocTemplate::AddDocument");
}

CDocument* CMultiDocTemplate::OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible)
{
	NSLog(@"TO DO CMultiDocTemplate::OpenDocumentFile");
}

void CMultiDocTemplate::SetDefaultTitle(CDocument* pDocument)
{
	NSLog(@"TO DO CMultiDocTemplate::SetDefaultTitle");
}
