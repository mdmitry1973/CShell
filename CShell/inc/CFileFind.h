/*
 *  CFileFind.h
 *  Untitled
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 CShell. All rights reserved.
 *
 */

#include "CDef.h"

#include "CString.h"
#include "CObject.h"
#include "CTime.h"
#include "winbase.h"

#ifndef CFILEFIND_DEFINE
#define CFILEFIND_DEFINE 1

class CFileFind : public CObject
{

public:
	
	CFileFind();
	virtual ~CFileFind();

// Attributes
public:
	ULONGLONG GetLength() const;
	virtual CString GetFileName() const;
	virtual CString GetFilePath() const;
	virtual CString GetFileTitle() const;
	virtual CString GetFileURL() const;
	virtual CString GetRoot() const;

	virtual BOOL GetLastWriteTime(FILETIME* pTimeStamp) const;
	virtual BOOL GetLastAccessTime(FILETIME* pTimeStamp) const;
	virtual BOOL GetCreationTime(FILETIME* pTimeStamp) const;
	virtual BOOL GetLastWriteTime(CTime& refTime) const;
	virtual BOOL GetLastAccessTime(CTime& refTime) const;
	virtual BOOL GetCreationTime(CTime& refTime) const;

	virtual BOOL MatchesMask(DWORD dwMask) const;

	virtual BOOL IsDots() const;
	// these aren't virtual because they all use MatchesMask(), which is
	BOOL IsReadOnly() const;
	BOOL IsDirectory() const;
	BOOL IsCompressed() const;
	BOOL IsSystem() const;
	BOOL IsHidden() const;
	BOOL IsTemporary() const;
	BOOL IsNormal() const;
	BOOL IsArchived() const;

	// Operations
	void Close();
	virtual BOOL FindFile(LPCTSTR pstrName = NULL, DWORD dwUnused = 0);
	virtual BOOL FindNextFile();
	
private:
	
	void *dirEnum;
	void *localFileManager;
	std::string windCard;
	std::string extension;
	std::string res;
	BOOL all;
};

#endif CFILEFIND_DEFINE
