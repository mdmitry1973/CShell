/*
 *  COleDropTarget.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef COLEDROPTARGET_DEFINE
#define COLEDROPTARGET_DEFINE 1

#include "CDef.h"

#include "CWnd.h"

class COleDropTarget
{
	// Constructors
public:
	
	COleDropTarget();
	
	~COleDropTarget();
	
	BOOL Register(CWnd* pWnd);
	virtual void Revoke();  // virtual for implementation
	
};


#endif//COLEDROPTARGET_DEFINE