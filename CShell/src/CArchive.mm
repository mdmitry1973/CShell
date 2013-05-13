/*
 *  CArchive.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "afxwin.h"

#include "CArchiveException.h"
#include "CFile.h"
#include "CPtrArray.h"
#include "CMapPtrToPtr.h"
#include "CArchive.h"

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

// Pointer mapping constants
static const DWORD dwNullTag 	= 0; 			// special tag indicating NULL ptrs
static const WORD  wNullTag		= 0;			// and another special tag
static const WORD  wNoErrorTag 	= 0x900d;
static const DWORD nMaxMapCount = 0x3FFFFFFE; 	// 0x3FFFFFFE last valid mapCount

void CArchive::CheckCount()
{
	if (m_nMapCount >= nMaxMapCount)
		AfxThrowArchiveException(CArchiveException::badIndex, m_strFileName);
}

CArchive& CArchive::operator<<(BOOL dw)
{
	if (m_lpBufCur + sizeof(BOOL) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((DWORD)dw, m_lpBufCur);
	else
		*(BOOL*)m_lpBufCur = dw;
	
	m_lpBufCur += sizeof(BOOL);
	return *this;
}

CArchive& CArchive::operator<<(INT16 w) 
{
	if (m_lpBufCur + sizeof(INT16) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((WORD) w, m_lpBufCur);
	else
		*(INT16*)m_lpBufCur = w;
	
	m_lpBufCur += sizeof(INT16);
	return *this;
}




CArchive& CArchive::operator<<(WORD w)
{
	if (m_lpBufCur + sizeof(WORD) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(w, m_lpBufCur);
	else
		*(WORD*)m_lpBufCur = w;
	
	m_lpBufCur += sizeof(WORD);
	return *this;
}

CArchive& CArchive::operator<<(LONG l)
{
	ASSERT(sizeof(LONG) == sizeof(DWORD));
	return operator<<((DWORD) l);
}

#if OS_TYPE == WIN32_OS
#if _MSC_VER >= 1200		// VC6
CArchive& CArchive::operator<<(UINT32 u)
{
	if (m_lpBufCur + sizeof(UINT32) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((DWORD)u, m_lpBufCur);
	else
		*(UINT32*)m_lpBufCur = u;
	
	m_lpBufCur += sizeof(UINT32);
	return *this;
}

CArchive& CArchive::operator<<(UINT64 u)
{
	if (m_lpBufCur + sizeof(UINT64) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((DWORD)u, m_lpBufCur);
	else
		*(UINT64*)m_lpBufCur = u;
	
	m_lpBufCur += sizeof(UINT64);
	return *this;
}
#endif
#endif

CArchive& CArchive::operator<<(DWORD dw)
{
	if (m_lpBufCur + sizeof(DWORD) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(dw, m_lpBufCur);
	else
		*(DWORD*)m_lpBufCur = dw;
	
	m_lpBufCur += sizeof(DWORD);
	return *this;
}

CArchive& CArchive::operator<<(FLOAT32 f)
{
	if (m_lpBufCur + sizeof(FLOAT32) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(f, m_lpBufCur);
	else
		*(_AFXFLOAT*)m_lpBufCur = *(_AFXFLOAT*)&f;
	
	m_lpBufCur += sizeof(FLOAT32);
	return *this;
}

CArchive& CArchive::operator<<(FLOAT64 d)
{
	if (m_lpBufCur + sizeof(FLOAT64) > m_lpBufMax)
		Flush();
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(d, m_lpBufCur);
	else
		*(_AFXDOUBLE*)m_lpBufCur = *(_AFXDOUBLE*)&d;
	
	m_lpBufCur += sizeof(FLOAT64);
	return *this;
}

CArchive& CArchive::operator>>(BOOL& dw)
{
	if (m_lpBufCur + sizeof(BOOL) > m_lpBufMax)
		FillBuffer(sizeof(BOOL) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	dw = *(BOOL*)m_lpBufCur;
	m_lpBufCur += sizeof(BOOL);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((DWORD) dw, (BYTE*)&dw);
	
	return *this;
}

CArchive& CArchive::operator>>(INT16 &w) 
{
	if (m_lpBufCur + sizeof(INT16) > m_lpBufMax)
		FillBuffer(sizeof(INT16) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	w = *(INT16*)m_lpBufCur;
	m_lpBufCur += sizeof(INT16);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((WORD) w, (BYTE*)&w);
	
	return *this;
}

CArchive& CArchive::operator>>(UINT16 &w) 
{
	if (m_lpBufCur + sizeof(UINT16) > m_lpBufMax)
		FillBuffer(sizeof(UINT16) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	w = *(UINT16*)m_lpBufCur;
	m_lpBufCur += sizeof(UINT16);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((WORD) w, (BYTE*)&w);
	
	return *this;
}

CArchive& CArchive::operator<<(BYTE by)
{ 
	if (m_lpBufCur + sizeof(BYTE) > m_lpBufMax) 
		Flush();
	*(UNALIGNED BYTE*)m_lpBufCur = by; 
	m_lpBufCur += sizeof(BYTE); 
	
	return *this; 
}

CArchive& CArchive::operator>>(BYTE &by) 
{
	if (m_lpBufCur + sizeof(BYTE) > m_lpBufMax)
		FillBuffer(sizeof(BYTE) - (UINT)(m_lpBufMax - m_lpBufCur));
	by = *(UNALIGNED BYTE*)m_lpBufCur; 
	m_lpBufCur += sizeof(BYTE); 
	
	return *this;
}

CArchive& CArchive::operator>>(WORD& w)
{
	if (m_lpBufCur + sizeof(WORD) > m_lpBufMax)
		FillBuffer(sizeof(WORD) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	w = *(WORD*)m_lpBufCur;
	m_lpBufCur += sizeof(WORD);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(w, (BYTE*)&w);
	
	return *this;
}

CArchive& CArchive::operator>>(LONG& l)
{
	ASSERT(sizeof(LONG) == sizeof(DWORD));
	return operator>>((DWORD&) l);
}

CArchive& CArchive::operator>>(UINT32& u)
{
	if (m_lpBufCur + sizeof(UINT32) > m_lpBufMax)
		FillBuffer(sizeof(UINT32) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	u = *(UINT32*)m_lpBufCur;
	m_lpBufCur += sizeof(UINT32);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((DWORD)u, (BYTE*)&u);
	
	return *this;
}

CArchive& CArchive::operator>>(UINT64& u)
{
	if (m_lpBufCur + sizeof(UINT64) > m_lpBufMax)
		FillBuffer(sizeof(UINT64) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	u = *(UINT64*)m_lpBufCur;
	m_lpBufCur += sizeof(UINT64);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap((DWORD)u, (BYTE*)&u);
	
	return *this;
}


CArchive& CArchive::operator>>(DWORD& dw)
{
	if (m_lpBufCur + sizeof(DWORD) > m_lpBufMax)
		FillBuffer(sizeof(DWORD) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	dw = *(DWORD*)m_lpBufCur;
	m_lpBufCur += sizeof(DWORD);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(dw, (BYTE*)&dw);
	
	return *this;
}

CArchive& CArchive::operator>>(FLOAT32& f)
{
	if (m_lpBufCur + sizeof(FLOAT32) > m_lpBufMax)
		FillBuffer(sizeof(FLOAT32) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	*(_AFXFLOAT*)&f = *(_AFXFLOAT*)m_lpBufCur;
	m_lpBufCur += sizeof(FLOAT32);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(f, (BYTE*)&f);
	
	return *this;
}

CArchive& CArchive::operator>>(FLOAT64& d)
{
	if (m_lpBufCur + sizeof(FLOAT64) > m_lpBufMax)
		FillBuffer(sizeof(FLOAT64) - (UINT)(m_lpBufMax - m_lpBufCur));
	
	*(_AFXDOUBLE*)&d = *(_AFXDOUBLE*)m_lpBufCur;
	m_lpBufCur += sizeof(FLOAT64);
	
	if (!(m_nMode & bNoByteSwap))
		_AfxByteSwap(d, (BYTE*)&d);
	
	return *this;
}



////////////////////////////////////////////////////////////////////////////
// Archive object input/output

// minimum buffer size
enum { nBufSizeMin = 128 };

// default amount to grow m_pLoadArray upon insert
enum { nGrowSize = 64 };
// default size of hash table in m_pStoreMap when storing
enum { nHashSize = 137 };
// default size to grow collision blocks when storing
enum { nBlockSize = 16 };

////////////////////////////////////////////////////////////////////////////

CArchive::CArchive(CFile* pFile, UINT nMode, int nBufSize, void* lpBuf) :
	m_strFileName(pFile->GetFilePath())
{
	ASSERT_VALID(pFile);
	
	// initialize members not dependent on allocated buffer
	m_nMode = nMode;
	m_pFile = pFile;
	m_pLoadArray = NULL;
	m_bForceFlat = TRUE;
	
	if (IsStoring())
		m_nGrowSize = nBlockSize;
	else
		m_nGrowSize = nGrowSize;
	m_nHashSize = nHashSize;
	
	// initialize the buffer.  minimum size is 128
	m_lpBufStart = (BYTE*)lpBuf;
	m_bUserBuf = TRUE;
	m_bDirectBuffer = FALSE;
	
	if (nBufSize < nBufSizeMin)
	{
		// force use of private buffer of minimum size
		m_nBufSize = nBufSizeMin;
		m_lpBufStart = NULL;
	}
	else
		m_nBufSize = nBufSize;
	
	nBufSize = m_nBufSize;
	if (m_lpBufStart == NULL)
	{
		//		Just assume AFile doesn't support buffering
		//		m_bDirectBuffer is FALSE by defualt;
		
		// check for AFile providing buffering support
		//		m_bDirectBuffer = m_pFile->GetBufferPtr(AFile::bufferCheck);
		
		if (!m_bDirectBuffer)
		{
			// no support for direct buffering, allocate new buffer
			m_lpBufStart = new BYTE[m_nBufSize];
			m_bUserBuf = FALSE;
		}
		else
		{
			// AFile* supports direct buffering!
			nBufSize = 0;   // will trigger initial FillBuffer
		}
	}
	
	if (!m_bDirectBuffer)
	{
		ASSERT(m_lpBufStart != NULL);
		ASSERT(AfxIsValidAddress(m_lpBufStart, nBufSize, IsStoring()));
	}
	m_lpBufMax = m_lpBufStart + nBufSize;
	m_lpBufCur = (IsLoading()) ? m_lpBufMax : m_lpBufStart;
	
	ASSERT(m_pStoreMap == NULL);        // same as m_pLoadArray
}

CArchive::~CArchive()
{
	// Close makes m_pFile NULL. If it is not NULL, we must Close the CArchive
	if (m_pFile != NULL && !(m_nMode & bNoFlushOnDelete))
		Close();
	
	Abort();    // abort completely shuts down the archive
}

BOOL CArchive::IsLoading() const
{ return (m_nMode & CArchive::load) != 0; }

BOOL CArchive::IsStoring() const
{ return (m_nMode & CArchive::load) == 0; }

BOOL CArchive::IsByteSwapping() const
{ return (m_nMode & CArchive::bNoByteSwap) == 0; }

BOOL CArchive::IsBufferEmpty() const
{ return m_lpBufCur == m_lpBufMax; }

void CArchive::Abort()
{
	ASSERT(m_bDirectBuffer || m_lpBufStart == NULL ||
		   AfxIsValidAddress(m_lpBufStart, m_lpBufMax - m_lpBufStart, IsStoring()));
	ASSERT(m_bDirectBuffer || m_lpBufCur == NULL ||
		   AfxIsValidAddress(m_lpBufCur, m_lpBufMax - m_lpBufCur, IsStoring()));
	
	// disconnect from the file
	m_pFile = NULL;
	
	if (!m_bUserBuf)
	{
		ASSERT(!m_bDirectBuffer);
		delete[] m_lpBufStart;
		m_lpBufStart = NULL;
		m_lpBufCur = NULL;
	}
	
	// m_pStoreMap and m_pLoadArray are unioned, so we only need to delete one
	ASSERT((CObject*)m_pStoreMap == (CObject*)m_pLoadArray);
	delete (CObject*)m_pLoadArray;
	m_pLoadArray = NULL;
}

void CArchive::Close()
{
	ASSERT_VALID(m_pFile);
	
	Flush();
	m_pFile = NULL;
}

UINT CArchive::Read(void* lpBuf, UINT nMax)
{
	ASSERT_VALID(m_pFile);
	
	if (nMax == 0)
		return 0;
	
	ASSERT(lpBuf != NULL);
	ASSERT(AfxIsValidAddress(lpBuf, nMax));
	ASSERT(m_bDirectBuffer || m_lpBufStart != NULL);
	ASSERT(m_bDirectBuffer || m_lpBufCur != NULL);
	ASSERT(m_lpBufStart == NULL ||
		   AfxIsValidAddress(m_lpBufStart, m_lpBufMax - m_lpBufStart, FALSE));
	ASSERT(m_lpBufCur == NULL ||
		   AfxIsValidAddress(m_lpBufCur, m_lpBufMax - m_lpBufCur, FALSE));
	ASSERT(IsLoading());
	
	// try to fill from buffer first
	UINT nMaxTemp = nMax;
	UINT nTemp = min(nMaxTemp, (UINT)(m_lpBufMax - m_lpBufCur));
	memcpy(lpBuf, m_lpBufCur, nTemp);
	m_lpBufCur += nTemp;
	lpBuf = (BYTE*)lpBuf + nTemp;
	nMaxTemp -= nTemp;
	
	if (nMaxTemp != 0)
	{
		ASSERT(m_lpBufCur == m_lpBufMax);
		
		// read rest in buffer size chunks
		nTemp = nMaxTemp - (nMaxTemp % m_nBufSize);
		UINT nRead = 0;
		
		UINT nLeft = nTemp;
		UINT nBytes;
		do
		{
			nBytes = m_pFile->Read(lpBuf, nLeft);
			lpBuf = (BYTE*)lpBuf + nBytes;
			nRead += nBytes;
			nLeft -= nBytes;
		}
		while ((nBytes > 0) && (nLeft > 0));
		
		nMaxTemp -= nRead;
		
		// read last chunk into buffer then copy
		if (nRead == nTemp)
		{
			ASSERT(m_lpBufCur == m_lpBufMax);
			ASSERT(nMaxTemp < (UINT)m_nBufSize);
			
			// fill buffer (similar to CArchive::FillBuffer, but no exception)
			if (!m_bDirectBuffer)
			{
				UINT nLeft = max(nMaxTemp, (UINT)m_nBufSize);
				UINT nBytes;
				BYTE* lpTemp = m_lpBufStart;
				nRead = 0;
				do
				{
					nBytes = m_pFile->Read(lpTemp, nLeft);
					lpTemp = lpTemp + nBytes;
					nRead += nBytes;
					nLeft -= nBytes;
				}
				while ((nBytes > 0) && (nLeft > 0) && nRead < nMaxTemp);
				
				m_lpBufCur = m_lpBufStart;
				m_lpBufMax = m_lpBufStart + nRead;
			}
			//	Remarks:
			//		We always assume m_bDirectBuffer is FALSE, see CArchive::CArchive()
			//			else
			//			{
			//				nRead = m_pFile->GetBufferPtr(AFile::bufferRead, m_nBufSize,
			//					(void**)&m_lpBufStart, (void**)&m_lpBufMax);
			//				ASSERT(nRead == (UINT)(m_lpBufMax - m_lpBufStart));
			//				m_lpBufCur = m_lpBufStart;
			//			}
			
			// use first part for rest of read
			nTemp = min(nMaxTemp, (UINT)(m_lpBufMax - m_lpBufCur));
			memcpy(lpBuf, m_lpBufCur, nTemp);
			m_lpBufCur += nTemp;
			nMaxTemp -= nTemp;
		}
	}
	return nMax - nMaxTemp;
}

void CArchive::Write(const void* lpBuf, UINT nMax)
{
	ASSERT_VALID(m_pFile);
	
	if (nMax == 0)
		return;
	
	ASSERT(lpBuf != NULL);
	ASSERT(AfxIsValidAddress(lpBuf, nMax, FALSE));  // read-only access needed
	ASSERT(m_bDirectBuffer || m_lpBufStart != NULL);
	ASSERT(m_bDirectBuffer || m_lpBufCur != NULL);
	ASSERT(m_lpBufStart == NULL ||
		   AfxIsValidAddress(m_lpBufStart, m_lpBufMax - m_lpBufStart));
	ASSERT(m_lpBufCur == NULL ||
		   AfxIsValidAddress(m_lpBufCur, m_lpBufMax - m_lpBufCur));
	ASSERT(IsStoring());
	
	// copy to buffer if possible
	UINT nTemp = min(nMax, (UINT)(m_lpBufMax - m_lpBufCur));
	memcpy(m_lpBufCur, lpBuf, nTemp);
	m_lpBufCur += nTemp;
	lpBuf = (BYTE*)lpBuf + nTemp;
	nMax -= nTemp;
	
	if (nMax > 0)
	{
		Flush();    // flush the full buffer
		
		// write rest of buffer size chunks
		nTemp = nMax - (nMax % m_nBufSize);
		m_pFile->Write(lpBuf, nTemp);
		lpBuf = (BYTE*)lpBuf + nTemp;
		nMax -= nTemp;
		
		//	Remarks:
		//		We always assume m_bDirectBuffer is FALSE, see CArchive::CArchive()
		//		if (m_bDirectBuffer)
		//		{
		//			// sync up direct mode buffer to new file position
		//			VERIFY(m_pFile->GetBufferPtr(AFile::bufferWrite, m_nBufSize,
		//				(void**)&m_lpBufStart, (void**)&m_lpBufMax) == (UINT)m_nBufSize);
		//			ASSERT((UINT)m_nBufSize == (UINT)(m_lpBufMax - m_lpBufStart));
		//			m_lpBufCur = m_lpBufStart;
		//		}
		
		// copy remaining to active buffer
		ASSERT(nMax < (UINT)m_nBufSize);
		ASSERT(m_lpBufCur == m_lpBufStart);
		memcpy(m_lpBufCur, lpBuf, nMax);
		m_lpBufCur += nMax;
	}
}

void CArchive::Flush()
{
	ASSERT_VALID(m_pFile);
	ASSERT(m_bDirectBuffer || m_lpBufStart != NULL);
	ASSERT(m_bDirectBuffer || m_lpBufCur != NULL);
	ASSERT(m_lpBufStart == NULL ||
		   AfxIsValidAddress(m_lpBufStart, m_lpBufMax - m_lpBufStart, IsStoring()));
	ASSERT(m_lpBufCur == NULL ||
		   AfxIsValidAddress(m_lpBufCur, m_lpBufMax - m_lpBufCur, IsStoring()));
	
	if (IsLoading())
	{
		// unget the characters in the buffer, seek back unused amount
		if (m_lpBufMax - m_lpBufCur != 0)
			//			m_pFile->Seek(-(m_lpBufMax - m_lpBufCur), AFile::current);
			m_pFile->Seek(-(m_lpBufMax - m_lpBufCur), CFile::current);
		m_lpBufCur = m_lpBufMax;    // empty		   
	}
	else
	{
		if (m_lpBufStart == NULL || m_lpBufCur != m_lpBufStart)
		{
			if (!m_bDirectBuffer)
			{
				// write out the current buffer to file
				m_pFile->Write(m_lpBufStart, m_lpBufCur - m_lpBufStart);
			}
			//	Remarks:
			//		We always assume m_bDirectBuffer is FALSE, see CArchive::CArchive()
			//			else
			//			{
			//				// commit current buffer
			//				m_pFile->GetBufferPtr(AFile::bufferCommit, m_lpBufCur - m_lpBufStart);
			//				// get next buffer
			//				VERIFY(m_pFile->GetBufferPtr(AFile::bufferWrite, m_nBufSize,
			//					(void**)&m_lpBufStart, (void**)&m_lpBufMax) == (UINT)m_nBufSize);
			//				ASSERT((UINT)m_nBufSize == (UINT)(m_lpBufMax - m_lpBufStart));
			//			}
			m_lpBufCur = m_lpBufStart;
		}
	}
}

void CArchive::FillBuffer(UINT nBytesNeeded)
{
	ASSERT_VALID(m_pFile);
	ASSERT(IsLoading());
	ASSERT(m_bDirectBuffer || m_lpBufStart != NULL);
	ASSERT(m_bDirectBuffer || m_lpBufCur != NULL);
	ASSERT(nBytesNeeded > 0);
	ASSERT(nBytesNeeded <= (UINT)m_nBufSize);
	ASSERT(m_lpBufStart == NULL ||
		   AfxIsValidAddress(m_lpBufStart, m_lpBufMax - m_lpBufStart, FALSE));
	ASSERT(m_lpBufCur == NULL ||
		   AfxIsValidAddress(m_lpBufCur, m_lpBufMax - m_lpBufCur, FALSE));
	
	UINT nUnused = m_lpBufMax - m_lpBufCur;
	ULONG nTotalNeeded = ((ULONG)nBytesNeeded) + nUnused;
	
	// fill up the current buffer from file
	if (!m_bDirectBuffer)
	{
		ASSERT(m_lpBufCur != NULL);
		ASSERT(m_lpBufStart != NULL);
		ASSERT(m_lpBufMax != NULL);
		
		if (m_lpBufCur > m_lpBufStart)
		{
			// copy unused
			if ((int)nUnused > 0)
			{
				memmove(m_lpBufStart, m_lpBufCur, nUnused);
				m_lpBufCur = m_lpBufStart;
				m_lpBufMax = m_lpBufStart + nUnused;
			}
			
			// read to satisfy nBytesNeeded or nLeft if possible
			UINT nRead = nUnused;
			UINT nLeft = m_nBufSize-nUnused;
			UINT nBytes;
			BYTE* lpTemp = m_lpBufStart + nUnused;
			do
			{
				nBytes = m_pFile->Read(lpTemp, nLeft);
				lpTemp = lpTemp + nBytes;
				nRead += nBytes;
				nLeft -= nBytes;
			}
			while (nBytes > 0 && nLeft > 0 && nRead < nBytesNeeded);
			
			m_lpBufCur = m_lpBufStart;
			m_lpBufMax = m_lpBufStart + nRead;
		}
	}
	//	Remarks:
	//		We always assume m_bDirectBuffer is FALSE, see CArchive::CArchive()
	//	else
	//	{
	//		// seek to unused portion and get the buffer starting there
	//		if (nUnused != 0)
	//			m_pFile->Seek(-(LONG)nUnused, AFile::current);
	//		UINT nActual = m_pFile->GetBufferPtr(AFile::bufferRead, m_nBufSize,
	//			(void**)&m_lpBufStart, (void**)&m_lpBufMax);
	//		ASSERT(nActual == (UINT)(m_lpBufMax - m_lpBufStart));
	//		m_lpBufCur = m_lpBufStart;
	//	}
	
	// not enough data to fill request?
	if ((ULONG)(m_lpBufMax - m_lpBufCur) < nTotalNeeded)
		AfxThrowArchiveException(CArchiveException::endOfFile, NULL);
}

void CArchive::MapObject(const CObject* pOb)
{
	if (IsStoring())
	{
		if (m_pStoreMap == NULL)
		{
			// initialize the storage map
			//  (use AMapPtrToPtr because it is used for HANDLE maps too)
			m_pStoreMap = new CMapPtrToPtr(m_nGrowSize);
			m_pStoreMap->InitHashTable(m_nHashSize);
			m_pStoreMap->SetAt(NULL, (void*)(DWORD) wNullTag);
			m_nMapCount = 1;
		}
		if (pOb != NULL)
		{
			CheckCount();
			(*m_pStoreMap)[(void*)pOb] = (void*)m_nMapCount++;
		}
	}
	else
	{
		if (m_pLoadArray == NULL)
		{
			// initialize the loaded object pointer array and set special values
			m_pLoadArray = new CPtrArray;
			m_pLoadArray->SetSize(1, m_nGrowSize);
			ASSERT(wNullTag == 0);
			m_pLoadArray->SetAt(wNullTag, NULL);
			m_nMapCount = 1;
		}
		if (pOb != NULL)
		{
			CheckCount();
			m_pLoadArray->InsertAt(m_nMapCount++, (void*)pOb);
		}
	}
}

void CArchive::WriteCount(DWORD dwCount)
{
	if (dwCount < 0xFFFF)
		*this << (WORD)dwCount;
	else
	{
		*this << (WORD)0xFFFF;
		*this << dwCount;
	}
}

DWORD CArchive::ReadCount()
{
	WORD wCount;
	*this >> wCount;
	if (wCount != 0xFFFF)
		return wCount;
	
	DWORD dwCount;
	*this >> dwCount;
	return dwCount;
}

// special functions for text file input and output

void CArchive::WriteString(LPCTSTR lpsz)
{
	ASSERT(AfxIsValidString(lpsz));
	Write(lpsz, strlen(lpsz) * sizeof(TCHAR));
}

LPTSTR CArchive::ReadString(LPTSTR lpsz, UINT nMax)
{
	// if nMax is negative (such a large number doesn't make sense given today's
	// 2gb address space), then assume it to mean "keep the newline".
	int nStop = (int)nMax < 0 ? -(int)nMax : (int)nMax;
	ASSERT(AfxIsValidAddress(lpsz, (nStop+1) * sizeof(TCHAR)));
	
	BYTE ch;
	int nRead = 0;
	
	try
	{
		while (nRead < nStop)
		{
			*this >> ch;
			
			// stop and end-of-line (trailing '\n' is ignored)
			if (ch == '\n' || ch == '\r')
			{
				if (ch == '\r')
					*this >> ch;
				// store the newline when called with negative nMax
				if ((int)nMax != nStop)
					lpsz[nRead++] = ch;
				break;
			}
			lpsz[nRead++] = ch;
		}
	}
	catch (CArchiveException *e)
	{
		if (e->m_cause == CArchiveException::endOfFile)
		{
			e->Delete();
			if (nRead == 0)
				return NULL;
		}
		else
		{
			throw;
		}
	}
	
	lpsz[nRead] = '\0';
	return lpsz;
}

BOOL CArchive::ReadString(CString& rString)
{
	// rString = &afxChNil;    // empty string without deallocating
	rString.Empty();
	const int nMaxSize = 128;
	LPTSTR lpsz = rString.GetBuffer(nMaxSize);
	LPTSTR lpszResult;
	int nLen;
	for (;;)
	{
		lpszResult = ReadString(lpsz, (UINT)-nMaxSize); // store the newline
		rString.ReleaseBuffer();
		
		// if string is read completely or EOF
		if (lpszResult == NULL ||
			(nLen = strlen(lpsz)) < nMaxSize ||
			lpsz[nLen-1] == '\n')
		{
			break;
		}
		
		nLen = rString.GetLength();
		lpsz = rString.GetBuffer(nMaxSize + nLen) + nLen;
	}
	
	// remove '\n' from end of string if present
	lpsz = rString.GetBuffer(0);
	nLen = rString.GetLength();
	if (nLen != 0 && lpsz[nLen-1] == '\n')
		rString.GetBufferSetLength(nLen-1);
	
	return lpszResult != NULL;
}
