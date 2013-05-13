/*
 *  CFile.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CFILE_DEFINE
#define CFILE_DEFINE 1

#include "CTime.h"
#include "CString.h"
#include "CObject.h"

class CFileException;

#define __MAX_PATH 2000

struct CFileStatus
{
	CTime m_ctime;          // creation date/time of file
	CTime m_mtime;          // last modification date/time of file
	CTime m_atime;          // last access date/time of file
	ULONGLONG m_size;            // logical size of file in bytes
	BYTE m_attribute;       // logical OR of CFile::Attribute enum values
	BYTE _m_padding;        // pad the structure to a WORD
	TCHAR m_szFullName[__MAX_PATH]; // absolute path name
	
//#ifdef _DEBUG
//	void Dump(CDumpContext& dc) const;
//#endif
};

class CFile : public CObject
{
	
public:
	
	// Flag values
	enum OpenFlags {
		modeRead =         (int) 0x00000,
		modeWrite =        (int) 0x00001,
		modeReadWrite =    (int) 0x00002,
		shareCompat =      (int) 0x00000,
		shareExclusive =   (int) 0x00010,
		shareDenyWrite =   (int) 0x00020,
		shareDenyRead =    (int) 0x00030,
		shareDenyNone =    (int) 0x00040,
		modeNoInherit =    (int) 0x00080,
		modeCreate =       (int) 0x01000,
		modeNoTruncate =   (int) 0x02000,
		typeText =         (int) 0x04000, // typeText and typeBinary are
		typeBinary =       (int) 0x08000, // used in derived classes only
		osNoBuffer =       (int) 0x10000,
		osWriteThrough =   (int) 0x20000,
		osRandomAccess =   (int) 0x40000,
		osSequentialScan = (int) 0x80000,
	};
	
	enum Attribute {
		normal =    0x00,
		readOnly =  0x01,
		hidden =    0x02,
		system =    0x04,
		volume =    0x08,
		directory = 0x10,
		archive =   0x20
	};
	
	enum SeekPosition { begin = 0x0, current = 0x1, end = 0x2 };
	
	CFile();
	CFile(HANDLE hFile );
	CFile(LPCTSTR lpszFileName, UINT nOpenFlags);
	
	virtual BOOL Open(LPCTSTR lpszFileName, UINT nOpenFlags, CFileException* pError = NULL);
	
	virtual ~CFile();
	
	virtual CString GetFileName() const;
	virtual CString GetFileTitle() const;
	virtual CString GetFilePath() const;
	
	virtual UINT Read(void* lpBuf, UINT nCount);
	virtual void Write(const void* lpBuf, UINT nCount);
	
	virtual ULONGLONG Seek(LONGLONG lOff, UINT nFrom);
	virtual void SetLength(ULONGLONG dwNewLen);
	virtual ULONGLONG GetLength() const;
	
	virtual void Abort();
	virtual void Flush();
	virtual void Close();
	
	virtual ULONGLONG GetPosition() const;
	ULONGLONG SeekToEnd();
	void SeekToBegin();
	
private:
	
	HANDLE	m_hFile;
	CString m_strPath;
	
};

#endif//CFILE_DEFINE