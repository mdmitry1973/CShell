/*
 *  CArchive.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CARCHIVE_DEFINE
#define CARCHIVE_DEFINE 1

#include "CDef.h"

#include "CString.h"
#include "CObject.h"

class CDocument;
class CFile;
class CPtrArray;
class CMapPtrToPtr;

#define UNALIGNED

struct _AFXWORD
{
	BYTE WordBits[sizeof(WORD)];
};
struct _AFXDWORD
{
	BYTE DwordBits[sizeof(DWORD)];
};

struct _AFXFLOAT
{
	BYTE FloatBits[sizeof(FLOAT32)];
};
struct _AFXDOUBLE
{
	BYTE DoubleBits[sizeof(FLOAT64)];
};

inline void _AfxByteSwap(WORD w, BYTE* pb)
{
	_AFXWORD wAfx;
	*(WORD*)&wAfx = w;
	
	ASSERT(sizeof(WORD) == 2);
	
	*pb++ = wAfx.WordBits[1];
	*pb = wAfx.WordBits[0];
}

inline void _AfxByteSwap(DWORD dw, BYTE* pb)
{
	_AFXDWORD dwAfx;
	*(DWORD*)&dwAfx = dw;
	
	ASSERT(sizeof(DWORD) == 4);
	
	*pb++ = dwAfx.DwordBits[3];
	*pb++ = dwAfx.DwordBits[2];
	*pb++ = dwAfx.DwordBits[1];
	*pb = dwAfx.DwordBits[0];
}

inline void _AfxByteSwap(float f, BYTE* pb)
{
	_AFXFLOAT fAfx;
	*(float*)&fAfx = f;
	
	ASSERT(sizeof(float) == 4);
	
	*pb++ = fAfx.FloatBits[3];
	*pb++ = fAfx.FloatBits[2];
	*pb++ = fAfx.FloatBits[1];
	*pb = fAfx.FloatBits[0];
}

inline void _AfxByteSwap(double d, BYTE* pb)
{
	_AFXDOUBLE dAfx;
	*(double*)&dAfx = d;
	
	ASSERT(sizeof(double) == 8);
	
	*pb++ = dAfx.DoubleBits[7];
	*pb++ = dAfx.DoubleBits[6];
	*pb++ = dAfx.DoubleBits[5];
	*pb++ = dAfx.DoubleBits[4];
	*pb++ = dAfx.DoubleBits[3];
	*pb++ = dAfx.DoubleBits[2];
	*pb++ = dAfx.DoubleBits[1];
	*pb = dAfx.DoubleBits[0];
}

class CSHELL_LIB_EXPORT CArchive
{
	
public:
	// Flag values
	enum Mode { store = 0, load = 1, bNoFlushOnDelete = 2, bNoByteSwap = 4 };
	
	CArchive(CFile* pFile, UINT nMode, int nBufSize = 4096, void* lpBuf = NULL);
	~CArchive();
	
	// Attributes
	BOOL IsLoading() const;
	BOOL IsStoring() const;
	BOOL IsByteSwapping() const;
	BOOL IsBufferEmpty() const;
	
	CFile* GetFile() const;
	UINT GetObjectSchema(); // only valid when reading a CObject*
	void SetObjectSchema(UINT nSchema);
	
	
	// Operations
	UINT Read(void* lpBuf, UINT nMax);
	void Write(const void* lpBuf, UINT nMax);
	void Flush();
	void Close();
	void Abort();   // close and shutdown without exceptions
	
	// reading and writing strings
	void WriteString(LPCTSTR lpsz);
	LPTSTR ReadString(LPTSTR lpsz, UINT nMax);
	BOOL ReadString(CString& rString);
	
public:
	// insertion operations
	CArchive& operator<<(BYTE by);
	CArchive& operator<<(INT16 i); 
	CArchive& operator<<(BOOL dw);
	CArchive& operator<<(WORD w);
	CArchive& operator<<(LONG l);
	CArchive& operator<<(UINT32 u);
	CArchive& operator<<(DWORD dw);
	CArchive& operator<<(FLOAT32 f);
	CArchive& operator<<(FLOAT64 d);
	CArchive& operator<<(UINT64 u);
	//CArchive& operator<<(UINT8 u);
	
protected:
	// extraction operations
	CArchive& operator>>(BYTE& by);
	CArchive& operator>>(INT16 &i); 
	CArchive& operator>>(UINT16 &i);
	CArchive& operator>>(BOOL &dw);
#ifndef CSHELL_USE_QT
	CArchive& operator>>(WORD& w);
#endif
	CArchive& operator>>(DWORD& dw);
	CArchive& operator>>(LONG& l);
	CArchive& operator>>(UINT32& u);
	CArchive& operator>>(FLOAT32& f);
	CArchive& operator>>(FLOAT64& d);
	CArchive& operator>>(UINT64& u);
	
public:
	void MapObject(const CObject* pOb);
	
	// advanced operations (used when storing/loading many objects)
	void SetStoreParams(UINT nHashSize = 2053, UINT nBlockSize = 128);
	void SetLoadParams(UINT nGrowBy = 1024);
	
	// Implementation
public:
	BOOL m_bForceFlat;  // for COleClientItem implementation (default TRUE)
	BOOL m_bDirectBuffer;   // TRUE if m_pFile supports direct buffering
	void FillBuffer(UINT nBytesNeeded);
	void CheckCount();  // throw exception if m_nMapCount is too large
	
	// special functions for reading and writing (16-bit compatible) counts
	DWORD ReadCount();
	void WriteCount(DWORD dwCount);
	
	// public for advanced use
	UINT m_nObjectSchema;
	CString m_strFileName;
	
	CDocument* m_pDocument;
	
protected:
	// archive objects cannot be copied or assigned
	CArchive(const CArchive& arSrc);
	void operator=(const CArchive& arSrc);
	
	BOOL m_nMode;
	BOOL m_bUserBuf;
	int m_nBufSize;
	CFile* m_pFile;
	BYTE* m_lpBufCur;
	BYTE* m_lpBufMax;
	BYTE* m_lpBufStart;
	
	// array/map for CObject* and CRuntimeClass* load/store
	UINT m_nMapCount;
	union
	{
		CPtrArray*    m_pLoadArray;
		CMapPtrToPtr* m_pStoreMap;
	};
	
	// advanced parameters (controls performance with large archives)
	UINT m_nGrowSize;
	UINT m_nHashSize;
	
};

#endif//CARCHIVE_DEFINE
