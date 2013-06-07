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
class CRuntimeClass;

class CDocTemplate : public CCmdTarget
{

public:
	
	CDocTemplate(UINT nIDResource,
				  CRuntimeClass* pDocClass,
				  CRuntimeClass* pFrameClass,
				  CRuntimeClass* pViewClass);
				  
	virtual ~CDocTemplate();
	
	enum DocStringIndex
	{
		windowTitle,        // default window title
		docName,            // user visible name for default document
		fileNewName,        // user visible name for FileNew
		// for file based documents:
		filterName,         // user visible name for FileOpen
		filterExt,          // user visible extension for FileOpen
		// for file based documents with Shell open support:
		regFileTypeId,      // REGEDIT visible registered file type identifier
		regFileTypeName,    // Shell visible registered file type name
	};
	
	virtual void AddDocument(CDocument* pDoc);
	virtual void CloseAllDocuments(BOOL bEndSession);
	virtual CDocument* CreateNewDocument();
	virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible = TRUE) = 0;
	virtual void RemoveDocument(CDocument* pDoc);
	
	virtual void SetDefaultTitle(CDocument* pDocument) = 0;
	
	virtual BOOL GetDocString(CString& rString, enum DocStringIndex index) const;
	
	// setup for OLE containers
	void SetContainerInfo(UINT nIDOleInPlaceContainer);
	
	// setup for OLE servers
	void SetServerInfo(UINT nIDOleEmbedding, UINT nIDOleInPlaceServer = 0,
					   CRuntimeClass* pOleFrameClass = NULL, CRuntimeClass* pOleViewClass = NULL);
	
	
	// iterating over open documents
	virtual POSITION GetFirstDocPosition() const = 0;
	virtual CDocument* GetNextDoc(POSITION& rPos) const = 0;
	
	//not mfc methods
	
	virtual void AddEventHandle(int objID, EventFun fun, int eventType);
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType);
	virtual void AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType);
	
protected:

	UINT		m_nIDResource;
	CRuntimeClass*	m_pDocClass;
	CRuntimeClass*	m_pFrameClass;
	CRuntimeClass*	m_pViewClass;

};

#endif//CDOCTEMPLATE_DEFINE