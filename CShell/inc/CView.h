/*
 *  CView.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CVIEW_DEFINE
#define CVIEW_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CDocument;
class CPrintInfo;

class CView : public CWnd
{
	
public:
	
	CView();
	
	virtual ~CView();
	
	BOOL DoPreparePrinting(CPrintInfo* pInfo);
	
	virtual void OnInitialUpdate(){}
	
protected:
	
	CDocument* 	m_pDocument;
};


#endif//CVIEW_DEFINE