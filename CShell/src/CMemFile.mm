/*
 *  CMemFile.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CMemFile.h"

CMemFile::CMemFile(UINT nGrowBytes)
{
	
}

CMemFile::CMemFile(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes)
{
	
}

void CMemFile::Attach(BYTE* lpBuffer, UINT nBufferSize, UINT nGrowBytes)
{
	assert(1);
}

BYTE* CMemFile::Detach()
{
	assert(1);
	return 0;
}

CMemFile::~CMemFile()
{
	assert(1);
}

#ifdef _DEBUG

void CMemFile::Dump(CDumpContext& dc) const
{
	
}

void CMemFile::AssertValid() const
{
	
}

#endif

ULONGLONG CMemFile::GetPosition() const
{
	assert(1);
	return 0;
}

BOOL CMemFile::GetStatus(CFileStatus& rStatus) const
{
	assert(1);
	return FALSE;
}

ULONGLONG CMemFile::Seek(LONGLONG lOff, UINT nFrom)
{
	assert(1);
	return 0;
}

void CMemFile::SetLength(ULONGLONG dwNewLen)
{
	assert(1);
}

UINT CMemFile::Read(void* lpBuf, UINT nCount)
{
	assert(1);
	return 0;
}

void CMemFile::Write(const void* lpBuf, UINT nCount)
{
	assert(1);
}

void CMemFile::Abort()
{
	assert(1);
}

void CMemFile::Flush()
{
	assert(1);
}

void CMemFile::Close()
{
	assert(1);
}

UINT CMemFile::CMemFile::GetBufferPtr(UINT nCommand, UINT nCount,
						  void** ppBufStart, void** ppBufMax)
{
	assert(1);
	return 0;
}

ULONGLONG CMemFile::GetLength() const
{
	assert(1);
	return 0;
}

CFile* CMemFile::Duplicate() const
{
	assert(1);
	return 0;
}

void CMemFile::LockRange(ULONGLONG dwPos, ULONGLONG dwCount)
{
	assert(1);
}

void CMemFile::UnlockRange(ULONGLONG dwPos, ULONGLONG dwCount)
{
	assert(1);
}

