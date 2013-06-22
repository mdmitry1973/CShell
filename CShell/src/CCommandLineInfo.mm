/*
 *  CCommandLineInfo.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CCommandLineInfo.h"

CCommandLineInfo::CCommandLineInfo() : CObject()
{
	m_nShellCommand = FileNew;
	
	m_bShowSplash = 0;
	m_bRunEmbedded = 0;
	m_bRunAutomated = 0;
	m_bRegisterPerUser = 0;
}

CCommandLineInfo::~CCommandLineInfo()
{

}

void CCommandLineInfo::ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast)
{
	
}
