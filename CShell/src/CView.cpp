/*
 *  CView.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CView.h"

#include "CPrintInfo.h"

CView::CView() : CWnd()
{
	
}


CView::~CView()
{
	
}

BOOL CView::DoPreparePrinting(CPrintInfo* pInfo)
{
    qDebug() << "TO DO CView::DoPreparePrinting";
	return TRUE;
}
