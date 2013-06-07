/*
 *  CMDIChildWnd.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CMDICHILDWND_DEFINE
#define CMDICHILDWND_DEFINE 1

#include "CDef.h"
#include "CWnd.h"

class CMDIChildWnd : public CWnd
{
	
public:
	
	CMDIChildWnd();
	
	virtual ~CMDIChildWnd();
	

};

#define CMDIChildWndEx CMDIChildWnd


#endif//CMDICHILDWND_DEFINE