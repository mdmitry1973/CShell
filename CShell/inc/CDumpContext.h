/*
 *  CDumpContext.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <vector>

#include "CObject.h"

#ifndef CDUMPCONTEXT_DEFINE
#define CDUMPCONTEXT_DEFINE 1

class CFile;

class CDumpContext
{
public:
	CDumpContext(CFile* pFile = NULL);
	
	// Attributes
	int GetDepth() const;      // 0 => this object, 1 => children objects
	void SetDepth(int nNewDepth);
	
	// Operations
	CDumpContext& operator<<(LPCTSTR lpsz);
//#ifdef _UNICODE
//	CDumpContext& operator<<(LPCSTR lpsz);  // automatically widened
//#else
//	CDumpContext& operator<<(LPCWSTR lpsz); // automatically thinned
//#endif
//	template< typename BaseType, class StringTraits >
//	CDumpContext& operator<<(const ATL::CStringT<BaseType, 
//							 StringTraits>& str)
//	{
//		*this << static_cast< const BaseType* >( str );
//		return *this;
//	}
	CDumpContext& operator<<(const void* lp);
	CDumpContext& operator<<(const CObject* pOb);
	CDumpContext& operator<<(const CObject& ob);
	CDumpContext& operator<<(BYTE by);
	CDumpContext& operator<<(WORD w);
	CDumpContext& DumpAsHex(BYTE b);
	CDumpContext& DumpAsHex(WORD w);
	
//#ifdef _WIN64
	CDumpContext& operator<<(LONG l);
	CDumpContext& operator<<(DWORD dw);
	//CDumpContext& operator<<(int n);
	CDumpContext& operator<<(UINT u);
	CDumpContext& DumpAsHex(LONG l);
	CDumpContext& DumpAsHex(DWORD dw);
	//CDumpContext& DumpAsHex(int n);
	CDumpContext& DumpAsHex(UINT u);
//#else
	 
/*	CDumpContext& operator<<(LONG_PTR l);
	CDumpContext& operator<<(DWORD_PTR dw);
	CDumpContext& operator<<(INT_PTR n);
	CDumpContext& operator<<(UINT_PTR u);
	CDumpContext& DumpAsHex(LONG_PTR l);
	CDumpContext& DumpAsHex(DWORD_PTR dw);
	CDumpContext& DumpAsHex(INT_PTR n);
	CDumpContext& DumpAsHex(UINT_PTR u);*/
//#endif
	 
	CDumpContext& operator<<(float f);
	CDumpContext& operator<<(double d);
	CDumpContext& operator<<(LONGLONG n);
	CDumpContext& operator<<(ULONGLONG n);
	CDumpContext& DumpAsHex(LONGLONG n);
	CDumpContext& DumpAsHex(ULONGLONG n);
	//CDumpContext& operator<<(HWND h);
	//CDumpContext& operator<<(HDC h);
	//CDumpContext& operator<<(HMENU h);
	//CDumpContext& operator<<(HACCEL h);
	//CDumpContext& operator<<(HFONT h);
	void HexDump(LPCTSTR lpszLine, BYTE* pby, int nBytes, int nWidth);
	void Flush();
	
	// Implementation
protected:
	// dump context objects cannot be copied or assigned
	//CDumpContext(const CDumpContext& dcSrc);
	//void operator=(const CDumpContext& dcSrc);
	///void OutputString(LPCTSTR lpsz);
	
	//int m_nDepth;
	
public:
	CFile* m_pFile;
};

#endif//CDUMPCONTEXT_DEFINE