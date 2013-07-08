/*
 *  CMapPtrToPtr.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CMAPPRTTOPTR_DEFINE
#define CMAPPRTTOPTR_DEFINE 1

#include "CDef.h"

#include "CObject.h"

struct CPlex;

class CSHELL_LIB_EXPORT CMapPtrToPtr : public CObject
{
	
protected:
	// Association
	struct CAssoc
	{
		CAssoc* pNext;
		
		void* key;
		void* value;
	};
	
public:
	
	// Construction
	CMapPtrToPtr(int nBlockSize = 10);
	
	// Attributes
	// number of elements
	int GetCount() const;
	BOOL IsEmpty() const;
	
	// Lookup
	BOOL Lookup(void* key, void*& rValue) const;
	
	// Operations
	// Lookup and add if not there
	void*& operator[](void* key);
	
	// add a new (key, value) pair
	void SetAt(void* key, void* newValue);
	
	// removing existing (key, ?) pair
	BOOL RemoveKey(void* key);
	void RemoveAll();
	
	// iterating all (key, value) pairs
	POSITION GetStartPosition() const;
	void GetNextAssoc(POSITION& rNextPosition, void*& rKey, void*& rValue) const;
	
	// advanced features for derived classes
	UINT GetHashTableSize() const;
	void InitHashTable(UINT hashSize, BOOL bAllocNow = TRUE);
	
	// Overridables: special non-virtual (see map implementation for details)
	// Routine used to user-provided hash keys
	UINT HashKey(void* key) const;
	
	// Implementation
protected:
	CAssoc** m_pHashTable;
	UINT m_nHashTableSize;
	int m_nCount;
	CAssoc* m_pFreeList;
	struct CPlex* m_pBlocks;
	int m_nBlockSize;
	
	CAssoc* NewAssoc();
	void FreeAssoc(CAssoc*);
	CAssoc* GetAssocAt(void*, UINT&) const;
	
public:
	~CMapPtrToPtr();
	
#ifdef DEBUG
	void AssertValid() const;
#endif	//	DEBUG
	
	void* GetValueAt(void* key) const;
	
	
protected:
	// local typedefs for CTypedPtrMap class template
	typedef void* BASE_KEY;
	typedef void* BASE_ARG_KEY;
	typedef void* BASE_VALUE;
	typedef void* BASE_ARG_VALUE;
	
};

#endif//CMAPPRTTOPTR_DEFINE
