/*
 *  CCommandLineInfo.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CCOMMANDLINEINFO_DEFINE
#define CCOMMANDLINEINFO_DEFINE 1

#include "CDef.h"
#include "CObject.h"

class CCommandLineInfo : public CObject
{
	
public:

	enum{
		FileNew,
		FileOpen,
		FilePrint,
		FilePrintTo,
		FileDDE,
		FileNothing = -1
	};
	
	CCommandLineInfo();
	virtual ~CCommandLineInfo();
	
	virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast);
	
	int m_nShellCommand;
	
};


#endif//CCOMMANDLINEINFO_DEFINE