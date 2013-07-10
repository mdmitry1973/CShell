/*
 *  CDocument.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CDocTemplate.h"

#include "CDocument.h"

IMPLEMENT_DYNAMIC(CDocument, CObject)

CDocument::CDocument()
{
	m_pDocTemplate = NULL;
}

CDocument::~CDocument()
{
	for (std::vector<CView*>::iterator it = m_viewList.begin() ; it != m_viewList.end(); ++it)
	{
		delete (*it);
	}
	
	m_viewList.clear();
}

const CString& CDocument::GetTitle() const
{
    qDebug() << "TO DO CDocument::GetTitle";
    return _T("");
}

void CDocument::SetTitle(LPCTSTR lpszTitle)
{
    qDebug() << "TO DO CDocument::SetTitle";
}

const CString& CDocument::GetPathName() const
{
    qDebug() << "TO DO CDocument::GetPathName";
    return _T("");
}

void CDocument::ClearPathName()
{
    qDebug() << "TO DO CDocument::ClearPathName";
}

CDocTemplate* CDocument::GetDocTemplate() const
{
    qDebug() << "TO DO CDocument::GetDocTemplate";
	return 0;
}

BOOL CDocument::IsModified()
{
    qDebug() << "TO DO CDocument::IsModified";
	return FALSE;
}

void CDocument::SetModifiedFlag(BOOL bModified)
{
    qDebug() << "TO DO CDocument::SetModifiedFlag";
}

POSITION CDocument::GetFirstViewPosition() const
{
    qDebug() << "TO DO CDocument::GetFirstViewPosition";
    return 0;
}

CView* CDocument::GetNextView(POSITION& rPosition) const
{
    qDebug() << "TO DO CDocument::GetNextView";
	return 0;
}

BOOL CDocument::OnNewDocument()
{
    qDebug() << "TO DO CDocument::OnNewDocument";
	return TRUE;
}

BOOL CDocument::OnSaveDocument(LPCTSTR lpszPathName)
{
    qDebug() << "TO DO CDocument::OnSaveDocument";
	return TRUE;
}

BOOL CDocument::OnOpenDocument(LPCTSTR lpszPathName)
{
    qDebug() << "TO DO CDocument::OnNewDocument";
	return TRUE;
}

void CDocument::OnCloseDocument()
{
    qDebug() << "TO DO CDocument::OnCloseDocument";
}

void CDocument::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU)
{
    qDebug() << "TO DO CDocument::SetPathName";
}

void CDocument::UpdateAllViews(CView* pSender, LPARAM lHint, CObject* pHint)
{
    qDebug() << "TO DO CDocument::UpdateAllViews";
}

void CDocument::AddView(CView* pView)
{
	m_viewList.push_back(pView);
	
	OnChangedViewList(); 
}

void CDocument::RemoveView(CView* pView )
{
	m_viewList.push_back(pView);
	
	for (std::vector<CView*>::iterator it = m_viewList.begin() ; it != m_viewList.end(); ++it)
	{
		if (pView == *it)
		{
			m_viewList.erase(it);
			delete pView;
			break;
		}
	}
	
	OnChangedViewList();  
}

void CDocument::OnChangedViewList()
{
    qDebug() << "TO DO CDocument::OnChangedViewList";
}

void CDocument::AddEventHandle(int objID, EventFun fun, int eventType)
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

void CDocument::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)
{
	
}

void CDocument::AddEventHandle(void *obj, EventFun fun, int eventType)
{
    //AddEventHandle([(NSView *)obj tag], fun, eventType);
}

