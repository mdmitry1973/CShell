/*
 *  CDocument.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDocument.h"

CDocument::CDocument()
{

}

CDocument::~CDocument()
{
	
}

BOOL CDocument::OnNewDocument()
{
	NSLog(@"TO DO CDocument::OnNewDocument");
	return TRUE;
}

BOOL CDocument::OnSaveDocument(LPCTSTR lpszPathName)
{
	NSLog(@"TO DO CDocument::OnSaveDocument");
	return TRUE;
}

BOOL CDocument::OnOpenDocument(LPCTSTR lpszPathName)
{
	NSLog(@"TO DO CDocument::OnNewDocument");
	return TRUE;
}

void CDocument::OnCloseDocument()
{
	NSLog(@"TO DO CDocument::OnCloseDocument");
}

void CDocument::SetPathName(LPCTSTR lpszPathName, BOOL bAddToMRU)
{
	NSLog(@"TO DO CDocument::SetPathName");
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

void CDocument::AddEventHandle(void *obj, EventFun fun, int eventType)
{
	AddEventHandle([(NSView *)obj tag], fun, eventType);
}

