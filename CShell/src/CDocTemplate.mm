/*
 *  CDocTemplate.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDocTemplate.h"

#include "CRuntimeClass.h"
#include "CDocument.h"
#include "CFrameWnd.h"

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
	NSLog(@"TO DO CDocTemplate::GetDocString");
}

void CDocTemplate::AddDocument(CDocument* pDoc)
{
	NSLog(@"TO DO CDocTemplate::AddDocument");
}

void CDocTemplate::CloseAllDocuments(BOOL bEndSession)
{
	NSLog(@"TO DO CDocTemplate::CloseAllDocuments");
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
	NSLog(@"TO DO CDocTemplate::RemoveDocument");
}

void CDocTemplate::SetContainerInfo(UINT nIDOleInPlaceContainer)
{
	NSLog(@"TO DO CDocTemplate::SetContainerInfo");
}

void CDocTemplate::SetServerInfo(UINT nIDOleEmbedding, UINT nIDOleInPlaceServer,
				   CRuntimeClass* pOleFrameClass, CRuntimeClass* pOleViewClass)
{
	NSLog(@"TO DO CDocTemplate::SetServerInfo");
}

void CDocTemplate::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)
{
	
}

void CDocTemplate::AddEventHandle(int objID, EventFun fun, int eventType)
{
	/*
	 if (m_hWnd)
	 {
	 PtrNSWindowHandle	pWindowHandle = mWindowHandle;
	 CCmdTEHData			*p_mapEventHandle = &(m_mapEventHandle);
	 NSControl			*control	= nil;
	 
	 if ([(NSObject*)m_hWnd isKindOfClass: [NSWindow class]])
	 {
	 control = [[(NSWindow *)m_hWnd contentView] viewWithTag: objID];   
	 }
	 else
	 if ([(NSObject*)m_hWnd isKindOfClass: [NSControl class]])
	 {
	 control = (NSControl *)m_hWnd;  
	 
	 if (objID != 0 && [control tag] != objID)
	 {
	 control = nil;
	 assert(false);
	 }
	 
	 if (objID == 0 && control)
	 {
	 objID = [control tag];
	 }
	 }
	 //else
	 //if ([(NSObject*)m_hWnd isKindOfClass: [NSView class]])
	 //{
	 //	NSLog(@"CANNOT ADD EVENT IT IS VIEWER");
	 //	return;
	 //}
	 
	 CCmdTargetEventHandle handle;
	 
	 handle.tag			= objID;
	 handle.fun			= fun;
	 handle.eventType	= eventType;
	 handle.control		= this;
	 
	 p_mapEventHandle->push_back(handle);
	 
	 if (control)
	 {
	 //CCmdTargetEventHandle handle;
	 
	 //handle.tag			= objID;
	 //handle.fun			= fun;
	 //handle.eventType	= eventType;
	 //handle.control		= this;
	 
	 //p_mapEventHandle->push_back(handle);
	 
	 SEL eventHandle = @selector(controlEventHandle:);
	 
	 [control setTarget:(CNSWindowHandle *)pWindowHandle];
	 [control setAction:eventHandle];
	 }
	 else 
	 {
	 NSLog(@"CANNOT ADD EVENT IT IS VIEWER");
	 }
	 }
	 */
}

void CDocTemplate::AddEventHandle(void *obj, EventFun fun, int eventType)
{
	AddEventHandle([(NSView *)obj tag], fun, eventType);
}

