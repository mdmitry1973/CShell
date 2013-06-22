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

// Layout Modes for CalcDynamicLayout
#define LM_STRETCH  0x01    // same meaning as bStretch in CalcFixedLayout.  If set, ignores nLength
// and returns dimensions based on LM_HORZ state, otherwise LM_HORZ is used
// to determine if nLength is the desired horizontal or vertical length
// and dimensions are returned based on nLength
#define LM_HORZ     0x02    // same as bHorz in CalcFixedLayout
#define LM_MRUWIDTH 0x04    // Most Recently Used Dynamic Width
#define LM_HORZDOCK 0x08    // Horizontal Docked Dimensions
#define LM_VERTDOCK 0x10    // Vertical Docked Dimensions
#define LM_LENGTHY  0x20    // Set if nLength is a Height instead of a Width
#define LM_COMMIT   0x40    // Remember MRUWidth

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