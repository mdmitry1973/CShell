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

class CSHELL_LIB_EXPORT CCommandLineInfo : public CObject
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
	
	BOOL m_bShowSplash;
	BOOL m_bRunEmbedded;
	BOOL m_bRunAutomated;
	BOOL m_bRegisterPerUser;
	
	// not valid for FileNew
	CString m_strFileName;
	
	// valid only for FilePrintTo
	CString m_strPrinterName;
	CString m_strDriverName;
	CString m_strPortName;
	
	// valid only for RestartByRestartManager
	CString m_strRestartIdentifier;
	
	CCommandLineInfo();
	virtual ~CCommandLineInfo();
	
	virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast);
	
	int m_nShellCommand;
	
};


#endif//CCOMMANDLINEINFO_DEFINE
