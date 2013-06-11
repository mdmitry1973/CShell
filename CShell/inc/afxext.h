/*
 *  afxext.h
 *  Untitled
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 CShell. All rights reserved.
 *
 */

#ifndef AFXEXT_WIN
#define AFXEXT_WIN 1

class CRuntimeClass;
class CDocument;
class CDocTemplate;
class CView;
class CFrameWnd;

struct CCreateContext
{
	CRuntimeClass *m_pNewViewClass;
	CDocument *m_pCurrentDoc;
	CDocTemplate *m_pNewDocTemplate;
	CView *m_pLastView;
	CFrameWnd *m_pCurrentFrame;
	
	CCreateContext()
	{
		m_pNewViewClass = NULL;
		m_pCurrentDoc = NULL;
		m_pNewDocTemplate = NULL;
		m_pLastView = NULL;
		m_pCurrentFrame = NULL;
	}
};

#endif//AFXEXT_WIN