/*
 *  CDocTemplate.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "afx.h"

#include "CRuntimeClass.h"
#include "CDocument.h"
#include "CFrameWnd.h"

#include "CDocTemplate.h"

CDocTemplate::CDocTemplate()
{
	m_nIDResource = 0;
	m_pDocClass = 0;
	m_pFrameClass = 0;
	m_pViewClass = 0;
}

CDocTemplate::CDocTemplate(UINT nIDResource,
			 CRuntimeClass* pDocClass,
			 CRuntimeClass* pFrameClass,
			 CRuntimeClass* pViewClass)
{
	m_nIDResource = nIDResource;
	m_pDocClass = pDocClass;
	m_pFrameClass = pFrameClass;
	m_pViewClass = pViewClass;
}

CDocTemplate::~CDocTemplate()
{
	if (m_pDocClass)
	{
		delete m_pDocClass;
	}
	
	if (m_pFrameClass)
	{
		delete m_pFrameClass;
	}
	
	if (m_pViewClass)
	{
		delete m_pViewClass;
	}
}

BOOL CDocTemplate::GetDocString(CString& rString, enum DocStringIndex index) const
{
     qDebug() << "TO DO CDocTemplate::GetDocString";
}

void CDocTemplate::AddDocument(CDocument* pDoc)
{
	ASSERT_VALID(pDoc);
	ASSERT(pDoc->m_pDocTemplate == NULL);   // no template attached yet
	pDoc->m_pDocTemplate = this;
}

void CDocTemplate::CloseAllDocuments(BOOL bEndSession)
{
     qDebug() << "TO DO CDocTemplate::CloseAllDocuments";
}

CDocument* CDocTemplate::CreateNewDocument()
{
	CDocument* pDocument = (CDocument*)m_pDocClass->CreateObject();
	
	AddDocument(pDocument);
	
	return pDocument;
}

CFrameWnd* CDocTemplate::CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther)
{
	CFrameWnd* pFrame = (CFrameWnd*)m_pFrameClass->CreateObject();
	
	CCreateContext context;
	
	context.m_pNewViewClass = m_pViewClass;
	context.m_pCurrentDoc = pDoc;
	context.m_pNewDocTemplate = this;
	
	if (!pFrame->LoadFrame(m_nIDResource, WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, NULL, &context))
	{
		//TRACE(traceAppMsg, 0, "Warning: CDocTemplate couldn't create a frame.\n");
		// frame will be deleted in PostNcDestroy cleanup
		return NULL;
	}
	
	return pFrame;
}

void CDocTemplate::RemoveDocument(CDocument* pDoc)
{
     qDebug() << "TO DO CDocTemplate::RemoveDocument";
}

void CDocTemplate::SetContainerInfo(UINT nIDOleInPlaceContainer)
{
     qDebug() << "TO DO CDocTemplate::SetContainerInfo";
}

void CDocTemplate::SetServerInfo(UINT nIDOleEmbedding, UINT nIDOleInPlaceServer,
				   CRuntimeClass* pOleFrameClass, CRuntimeClass* pOleViewClass)
{
     qDebug() << "TO DO CDocTemplate::SetServerInfo";
}

void CDocTemplate::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)
{
    qDebug() << "TO DO CDocTemplate::AddEventRangeHandle";
}

void CDocTemplate::AddEventHandle(int objID, EventFun fun, int eventType)
{
    qDebug() << "TO DO CDocTemplate::AddEventHandle";
}

void CDocTemplate::AddEventHandle(void *obj, EventFun fun, int eventType)
{
    qDebug() << "TO DO CDocTemplate::AddEventHandle";
    //AddEventHandle([(NSView *)obj tag], fun, eventType);
}


