/*
 *  CDocument.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDOCUMENT_DEFINE
#define CDOCUMENT_DEFINE 1

#include "CDef.h"

#include "CTargetEvent.h"

class CDocTemplate;
class CView;

class CDocument : public CCmdTarget
{

public:
	
	CDocument();
	//CDocument(const CDocument &);
	virtual ~CDocument();
	
	const CString& GetTitle() const;
	virtual void SetTitle(LPCTSTR lpszTitle);
	const CString& GetPathName() const;
	virtual void SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU = TRUE);
	virtual void ClearPathName();
	
	CDocTemplate* GetDocTemplate() const;
	virtual BOOL IsModified();
	virtual void SetModifiedFlag(BOOL bModified = TRUE);
	
	virtual POSITION GetFirstViewPosition() const;
	virtual CView* GetNextView(POSITION& rPosition) const;
	
	// Update Views (simple update - DAG only)
	void UpdateAllViews(CView* pSender, LPARAM lHint = 0L, CObject* pHint = NULL);
	
	virtual BOOL OnNewDocument();	
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);	
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void OnCloseDocument();
								
	virtual void AddEventHandle(int objID, EventFun fun, int eventType);
	virtual void AddEventHandle(void *obj, EventFun fun, int eventType);
	virtual void AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType);
	
protected:
	
	CString m_strTitle;
	CString m_strPathName;
	
};

#endif//CDOCUMENT_DEFINE