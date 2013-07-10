/*
 *  CMultiDocTemplate.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
 
#include "afx.h"
#include "afxwin.h"
#include "CObject.h"
#include "CDocument.h"
#include "CFrameWnd.h"
#include "CWinApp.h"

#include "CMultiDocTemplate.h"

CMultiDocTemplate::CMultiDocTemplate()
{
	
}

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
    qDebug() << "TO DO CMultiDocTemplate::GetDocString";
    return FALSE;
}

void CMultiDocTemplate::AddDocument(CDocument* pDoc)
{
	ASSERT_VALID(pDoc);
	
	CDocTemplate::AddDocument(pDoc);
	
	for (std::vector<CDocument *>::iterator it = m_docList.begin(); it != m_docList.end(); ++it)
	{
		if (*it == pDoc)
		{
			ASSERT(FALSE);
		}
	}
	
	m_docList.push_back(pDoc);
}

CDocument* CMultiDocTemplate::OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible)
{
    qDebug() << "TO DO CMultiDocTemplate::OpenDocumentFile";
	
    /*
	NSDocumentController *docManager = [NSDocumentController sharedDocumentController];
	NSError *error;
	
	CNSDocument *doc = [[[CNSDocument alloc] initWithType:@"CShellDoc" error:&error] autorelease];
	if (!doc) return nil; // error has been set
	
	[docManager addDocument:doc];
    */
	CDocument*  pDocument = (CDocument *)m_pDocClass->CreateObject();
	
    //pDocument->SetNSDoc(doc);
	
	AddDocument(pDocument);
	
	
	if (pDocument == NULL)
	{
		TRACE(traceAppMsg, 0, "CDocTemplate::CreateNewDocument returned NULL.\n");
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		return NULL;
	}
	ASSERT_VALID(pDocument);
	
	//BOOL bAutoDelete = pDocument->m_bAutoDelete;
	//pDocument->m_bAutoDelete = FALSE;   // don't destroy if something goes wrong
	CFrameWnd* pFrame = CreateNewFrame(pDocument, NULL);
	//pDocument->m_bAutoDelete = bAutoDelete;
	if (pFrame == NULL)
	{
		AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
		delete pDocument;       // explicit delete on error
		return NULL;
	}
	ASSERT_VALID(pFrame);
	
    //[doc setDoc: pDocument];
    //[doc setFrame: pFrame];
	
	pFrame->ShowWindow(SW_SHOWNORMAL);
	
	//if (lpszPathName == NULL)
	//{
		// create a new document - with default document name
	//	SetDefaultTitle(pDocument);
		
		// avoid creating temporary compound file when starting up invisible
	//	if (!bMakeVisible)
	//		pDocument->m_bEmbedded = TRUE;
		
	//	if (!pDocument->OnNewDocument())
	//	{
	//		// user has be alerted to what failed in OnNewDocument
	//		TRACE(traceAppMsg, 0, "CDocument::OnNewDocument returned FALSE.\n");
	//		pFrame->DestroyWindow();
	//		return NULL;
	//	}
		
		// it worked, now bump untitled count
	//	m_nUntitledCount++;
	//}
	//else
	//{
		// open an existing document
	///	CWaitCursor wait;
	//	if (!pDocument->OnOpenDocument(lpszPathName))
	//	{
			// user has be alerted to what failed in OnOpenDocument
	//		TRACE(traceAppMsg, 0, "CDocument::OnOpenDocument returned FALSE.\n");
	//		pFrame->DestroyWindow();
	//		return NULL;
	//	}
	//	pDocument->SetPathName(lpszPathName);
	//}
	
	//InitialUpdateFrame(pFrame, pDocument, bMakeVisible);


    return pDocument;
}

void CMultiDocTemplate::SetDefaultTitle(CDocument* pDocument)
{
    qDebug() << "TO DO CMultiDocTemplate::SetDefaultTitle";
}

POSITION CMultiDocTemplate::GetFirstDocPosition() const
{
    qDebug() << "TO DO CMultiDocTemplate::GetFirstDocPosition";
    return 0;
}

CDocument* CMultiDocTemplate::GetNextDoc(POSITION& rPos) const
{
    qDebug() << "TO DO CMultiDocTemplate::GetNextDoc";
    return 0;
}
