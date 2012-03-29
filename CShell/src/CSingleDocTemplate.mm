/*
 *  CSingleDocTemplate.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */
 
#include "CObject.h"
#include "CDocument.h"
#include "CFrameWnd.h"
#include "CWinApp.h"

#include "CSingleDocTemplate.h"

CSingleDocTemplate::CSingleDocTemplate(UINT nIDResource,
				   CObject* pDocClass,
				   CObject* pFrameClass,
				   CObject* pViewClass) : CDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
	m_pOnlyDoc = NULL;
}

CSingleDocTemplate::~CSingleDocTemplate()
{
	if (m_pOnlyDoc)
	{
		delete m_pOnlyDoc;
	}
}

void CSingleDocTemplate::AddDocument(CDocument* pDoc)
{
	if (m_pOnlyDoc)
	{
		delete m_pOnlyDoc;
	}
	
	m_pOnlyDoc = pDoc;
}

void CSingleDocTemplate::SetDefaultTitle(CDocument* pDocument)
{
	
	NSLog(@"TO DO CSingleDocTemplate::SetDefaultTitle");
	
	/*
	CString strDocName;
	if (!GetDocString(strDocName, CDocTemplate::docName) ||
		strDocName.IsEmpty())
	{
		// use generic 'untitled'
		VERIFY(strDocName.LoadString(AFX_IDS_UNTITLED));
	}
	pDocument->SetTitle(strDocName);
	*/
}

CDocument* CSingleDocTemplate::OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible)
{
	CDocument* pDocument = NULL;
	CFrameWnd* pFrame = NULL;
	
	if (m_pOnlyDoc != NULL)
	{
		// already have a document - reinit it
		pDocument = m_pOnlyDoc;
	//	if (!pDocument->SaveModified())
	//		return NULL;        // leave the original one
	//	
		pFrame = (CFrameWnd*)AfxGetMainWnd();
	}
	else
	{
		pDocument = CreateNewDocument();
	}
	
	if (pFrame == NULL)
	{
		pFrame = CreateNewFrame(pDocument, NULL);
		AfxGetApp()->m_pMainWnd = pFrame;
	}
	
	if (lpszPathName == NULL)
	{
		// create a new document
		SetDefaultTitle(pDocument);
		
		// avoid creating temporary compound file when starting up invisible
		//if (!bMakeVisible)
		//	pDocument->m_bEmbedded = TRUE;
		
		if (!pDocument->OnNewDocument())
		{
			// user has been alerted to what failed in OnNewDocument
			//TRACE(traceAppMsg, 0, "CDocument::OnNewDocument returned FALSE.\n");
			//if (bCreated)
			//	pFrame->DestroyWindow();    // will destroy document
			//return NULL;
		}
	}
	else
	{
		//CWaitCursor wait;
		
		// open an existing document
		//bWasModified = pDocument->IsModified();
		//pDocument->SetModifiedFlag(FALSE);  // not dirty for open
		
		if (!pDocument->OnOpenDocument(lpszPathName))
		{
			// user has been alerted to what failed in OnOpenDocument
			//TRACE(traceAppMsg, 0, "CDocument::OnOpenDocument returned FALSE.\n");
			//if (bCreated)
			//{
			//	pFrame->DestroyWindow();    // will destroy document
			//}
			//else if (!pDocument->IsModified())
			//{
				// original document is untouched
			//	pDocument->SetModifiedFlag(bWasModified);
			//}
			//else
			//{
				// we corrupted the original document
			//	SetDefaultTitle(pDocument);
				
			//	if (!pDocument->OnNewDocument())
			//	{
			//		TRACE(traceAppMsg, 0, "Error: OnNewDocument failed after trying "
			//			  "to open a document - trying to continue.\n");
					// assume we can continue
			//	}
			//}
			return NULL;        // open failed
		}
		pDocument->SetPathName(lpszPathName);
	}
	
	//??InitialUpdateFrame(pFrame, pDocument, bMakeVisible);
	
	return pDocument;
}
