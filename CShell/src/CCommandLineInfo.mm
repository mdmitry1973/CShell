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
}

CCommandLineInfo::~CCommandLineInfo()
{

}

void CCommandLineInfo::ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast)
{
	NSLog(@"TO DO CCommandLineInfo::ParseParam");
}
