/*
 *  CFile.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CFileException.h"

#include "CFile.h"

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

CFile::CFile()
{
	m_hFile = NULL;
}

CFile::~CFile()
{
	if (m_hFile)
	{
		Close();
	}
}

CFile::CFile(HANDLE hFile )
{
	m_hFile = hFile;
}

CFile::CFile(LPCTSTR lpszFileName, UINT nOpenFlags)
{
	CFileException e;
	
	if (!Open(lpszFileName, nOpenFlags, &e))
	{
		std::cout << "File could not be opened " << e.m_cause << "\n";
	}
}

BOOL CFile::Open(LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError)
{
	std::string mode;
	
	m_strPath = lpszFileName;
	
	if (nOpenFlags & modeRead)
	{
		mode = mode + "r";
	} 
	
	if (nOpenFlags & modeWrite)
	{
		mode = mode + "w";
	}
	
	if (nOpenFlags & modeReadWrite)
	{
		mode = mode + "r+";
	}
	
	if (nOpenFlags & typeBinary)
	{
		mode = mode + "b";
	}
	
	if (!mode.length())
	{
		mode = "rb";
	}
	
	if (nOpenFlags & shareCompat) {printf("TO DO nOpenFlags == shareCompat \n");}
	if (nOpenFlags & shareExclusive ) {printf("TO DO nOpenFlags == shareExclusive \n");}
	if (nOpenFlags & shareDenyWrite ) {printf("TO DO nOpenFlags == shareDenyWrite \n");}
	if (nOpenFlags & shareDenyRead ) {printf("TO DO nOpenFlags == shareDenyRead \n");}
	if (nOpenFlags & shareDenyNone ) {printf("TO DO nOpenFlags == shareDenyNone \n");}
	if (nOpenFlags & modeNoInherit ) {printf("TO DO nOpenFlags == modeNoInherit \n");}
	if (nOpenFlags & modeCreate ) {printf("TO DO nOpenFlags == modeCreate \n");}
	if (nOpenFlags & modeNoTruncate ) {printf("TO DO nOpenFlags == modeNoTruncate \n");}
	if (nOpenFlags & typeText ) {printf("TO DO nOpenFlags == typeText \n");}
	if (nOpenFlags & osNoBuffer ) {printf("TO DO nOpenFlags == osNoBuffer \n");}
	if (nOpenFlags & osWriteThrough ) {printf("TO DO nOpenFlags == osWriteThrough \n");}
	if (nOpenFlags & osRandomAccess ) {printf("TO DO nOpenFlags == osRandomAccess \n");}
	if (nOpenFlags & osSequentialScan ) {printf("TO DO nOpenFlags == osSequentialScan \n");}
	
	m_hFile = (HANDLE)fopen((const char *)lpszFileName, mode.c_str());
	
	return !(m_hFile == NULL);
}

CString CFile::GetFilePath( ) const
{
	return m_strPath;
}

UINT CFile::Read(void* lpBuf, UINT nCount)
{
	if (m_hFile)
		return fread(lpBuf, 1, nCount, (FILE *)m_hFile);
	return 0;
}

void CFile::Write(const void* lpBuf, UINT nCount)
{
	if (m_hFile)
		fwrite(lpBuf, 1, nCount, (FILE *)m_hFile);
}

ULONGLONG CFile::Seek(LONGLONG lOff, UINT nFrom)
{
	int mode;
	
	if (nFrom == begin)
	{
		mode = SEEK_SET;
	}
	else
	if (nFrom == current)
	{
		mode = SEEK_CUR;
	}
	else
	if (nFrom == end)
	{
		mode = SEEK_END;	
	}
	
	fseek((FILE *)m_hFile, lOff, mode);
	
	return GetLength();
}

void CFile::SetLength(ULONGLONG dwNewLen)
{
	int ifd = fileno((FILE *)m_hFile);
	ftruncate(ifd, dwNewLen);
}

ULONGLONG CFile::GetLength() const
{
	struct stat buf;
	ULONGLONG len;
	int ifd = fileno((FILE *)m_hFile); 
	fstat(ifd, &buf);
	len = buf.st_size;
	
	return len;
}

void CFile::Abort()
{
	
}

void CFile::Flush()
{
	if (m_hFile)
	{
		fflush((FILE *)m_hFile);
	}
}

void CFile::Close()
{
	if (m_hFile)
	{
		fclose((FILE *)m_hFile);
	}
}

ULONGLONG CFile::GetPosition() const
{
	return ftell((FILE *)m_hFile);
}

ULONGLONG CFile::SeekToEnd()
{
	return Seek(0, end);
}

void CFile::SeekToBegin()
{
	Seek(0, begin);
}

CString CFile::GetFileName() const
{
	CString res;
	
	int pos = m_strPath.rfind('/');
	
	if (pos != -1)
	{
		res = m_strPath.substr(pos, m_strPath.length()).c_str();
	}
	
	return res;
}

CString CFile::GetFileTitle() const
{
	CString res = GetFileName();
	
	int pos = res.rfind('.');
	
	if (pos != -1)
	{
		res = res.substr(0, pos).c_str();
	}
	
	return res;
}

