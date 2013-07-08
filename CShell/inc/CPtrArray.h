/*
 *  CPtrArray.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CPRTARRAY_DEFINE
#define CPRTARRAY_DEFINE 1

#include "CDef.h"

#include "CObject.h"

class CPtrArray;

class CSHELL_LIB_EXPORT CPtrArray  : public CObject
{
	
public:
	
	CPtrArray();
	
	INT_PTR GetSize() const;
	INT_PTR GetCount() const;
	BOOL IsEmpty() const;
	INT_PTR GetUpperBound() const;
	
	void FreeExtra();
	void RemoveAll();
	
	void* GetAt(INT_PTR nIndex) const;
	void SetAt(INT_PTR nIndex, void* newElement);
	
	void*& ElementAt(INT_PTR nIndex);
	
	// Direct Access to the element data (may return NULL)
	const void** GetData() const;
	void** GetData();

	void SetSize( INT_PTR nNewSize , int nGrowBy = -1 );
	
	void SetAtGrow(INT_PTR nIndex, void* newElement);
	
	INT_PTR Add(void* newElement);
	
	void InsertAt( INT_PTR nIndex , void* newElement , int nCount = 1 );	
	void InsertAt( INT_PTR nStartIndex , CPtrArray* pNewArray );
		
	void RemoveAt( INT_PTR nIndex , INT_PTR nCount = 1 );
	
	INT_PTR Append(const CPtrArray& src);
	void Copy(const CPtrArray& src);
	
	// overloaded operator helpers
	void* operator[](INT_PTR nIndex) const;
	void*& operator[](INT_PTR nIndex);
	
	// Implementation
protected:
	void** m_pData;   // the actual array of data
	int m_nSize;     // # of elements (upperBound - 1)
	int m_nMaxSize;  // max allocated
	int m_nGrowBy;   // grow amount
	
public:
	~CPtrArray();
};

#endif//CPRTARRAY_DEFINE
