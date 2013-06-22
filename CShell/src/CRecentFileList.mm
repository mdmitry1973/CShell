/*
 *  CRecentFileList.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CString.h"
#include "CRecentFileList.h"

CRecentFileList::CRecentFileList()
{

}

CRecentFileList::CRecentFileList(UINT nStart, LPCTSTR lpszSection,
				LPCTSTR lpszEntryFormat, int nSize,
				int nMaxDispLen )
{
	
}

CRecentFileList::~CRecentFileList()
{

}

int CRecentFileList::GetSize() const
{
	NSLog(@"to do CRecentFileList::GetSize");
}

CString& CRecentFileList::operator[](int nIndex)
{
	NSLog(@"to do CRecentFileList::GetSize");
}

void CRecentFileList::Remove(int nIndex)
{
	NSLog(@"to do CRecentFileList::Remove");
}

void CRecentFileList::Add(LPCTSTR lpszPathName)
{
	NSLog(@"to do CRecentFileList::Add");
}

void CRecentFileList::Add(LPCTSTR lpszPathName, LPCTSTR lpszAppID)
{
	NSLog(@"to do CRecentFileList::Add");
}

BOOL CRecentFileList::GetDisplayName(CString& strName, int nIndex,
									 LPCTSTR lpszCurDir, int nCurDir, BOOL bAtLeastName ) const
{
	NSLog(@"to do CRecentFileList::GetDisplayName");
}
