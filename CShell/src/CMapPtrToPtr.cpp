/*
 *  CMapPtrToPtr.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "afxwin.h"
#include "CPlex.h"

#include "CMapPtrToPtr.h"

CMapPtrToPtr::CMapPtrToPtr(int nBlockSize)
{
	ASSERT(nBlockSize > 0);
	
	m_pHashTable = NULL;
	m_nHashTableSize = 17;  // default size
	m_nCount = 0;
	m_pFreeList = NULL;
	m_pBlocks = NULL;
	m_nBlockSize = nBlockSize;
}

UINT CMapPtrToPtr::HashKey(void* key) const
{
	// default identity hash - works for most primitive values
	long res = (DWORD)key;
	
	return res >> 4;
	//return ((UINT)(void*)(DWORD)key) >> 4;
}

void CMapPtrToPtr::InitHashTable(UINT nHashSize, BOOL bAllocNow)
//
// Used to force allocation of a hash table or to override the default
//   hash table size of (which is fairly small)
{
	ASSERT_VALID(this);
	ASSERT(m_nCount == 0);
	ASSERT(nHashSize > 0);
	
	if (m_pHashTable != NULL)
	{
		// free hash table
		delete[] m_pHashTable;
		m_pHashTable = NULL;
	}
	
	if (bAllocNow)
	{
		m_pHashTable = new CAssoc* [nHashSize];
		memset(m_pHashTable, 0, sizeof(CAssoc*) * nHashSize);
	}
	m_nHashTableSize = nHashSize;
}

void CMapPtrToPtr::RemoveAll()
{
	ASSERT_VALID(this);
	
	if (m_pHashTable != NULL)
	{
		// free hash table
		delete[] m_pHashTable;
		m_pHashTable = NULL;
	}
	
	m_nCount = 0;
	m_pFreeList = NULL;
	m_pBlocks->FreeDataChain();
	m_pBlocks = NULL;
}

CMapPtrToPtr::~CMapPtrToPtr()
{
	RemoveAll();
	ASSERT(m_nCount == 0);
}

/////////////////////////////////////////////////////////////////////////////
// Assoc helpers
// same as CList implementation except we store CAssoc's not CNode's
//    and CAssoc's are singly linked all the time

CMapPtrToPtr::CAssoc* CMapPtrToPtr::NewAssoc()
{
	if (m_pFreeList == NULL)
	{
		// add another block
		CPlex* newBlock = CPlex::Create(m_pBlocks, m_nBlockSize, sizeof(CMapPtrToPtr::CAssoc));
		// chain them into free list
		CMapPtrToPtr::CAssoc* pAssoc = (CMapPtrToPtr::CAssoc*) newBlock->data();
		// free in reverse order to make it easier to debug
		pAssoc += m_nBlockSize - 1;
		for (int i = m_nBlockSize-1; i >= 0; i--, pAssoc--)
		{
			pAssoc->pNext = m_pFreeList;
			m_pFreeList = pAssoc;
		}
	}
	ASSERT(m_pFreeList != NULL);  // we must have something
	
	CMapPtrToPtr::CAssoc* pAssoc = m_pFreeList;
	m_pFreeList = m_pFreeList->pNext;
	m_nCount++;
	ASSERT(m_nCount > 0);  // make sure we don't overflow
	
	pAssoc->key = 0;
	pAssoc->value = 0;
	
	return pAssoc;
}

void CMapPtrToPtr::FreeAssoc(CMapPtrToPtr::CAssoc* pAssoc)
{
	
	pAssoc->pNext = m_pFreeList;
	m_pFreeList = pAssoc;
	m_nCount--;
	ASSERT(m_nCount >= 0);  // make sure we don't underflow
	
	// if no more elements, cleanup completely
	if (m_nCount == 0)
		RemoveAll();
}

CMapPtrToPtr::CAssoc* CMapPtrToPtr::GetAssocAt(void* key, UINT& nHash) const
// find association (or return NULL)
{
	nHash = HashKey(key) % m_nHashTableSize;
	
	if (m_pHashTable == NULL)
		return NULL;
	
	// see if it exists
	CAssoc* pAssoc;
	for (pAssoc = m_pHashTable[nHash]; pAssoc != NULL; pAssoc = pAssoc->pNext)
	{
		if (pAssoc->key == key)
			return pAssoc;
	}
	return NULL;
}


void* CMapPtrToPtr::GetValueAt(void* key) const
// find value (or return NULL -- NULL values not different as a result)
{
	if (m_pHashTable == NULL)
		return NULL;
	
	UINT nHash = HashKey(key) % m_nHashTableSize;
	
	// see if it exists
	CAssoc* pAssoc;
	for (pAssoc = m_pHashTable[nHash]; pAssoc != NULL; pAssoc = pAssoc->pNext)
	{
		if (pAssoc->key == key)
			return pAssoc->value;
	}
	return NULL;
}


/////////////////////////////////////////////////////////////////////////////

BOOL CMapPtrToPtr::Lookup(void* key, void*& rValue) const
{
	ASSERT_VALID(this);
	
	UINT nHash;
	CAssoc* pAssoc = GetAssocAt(key, nHash);
	if (pAssoc == NULL)
		return FALSE;  // not in map
	
	rValue = pAssoc->value;
	return TRUE;
}

void*& CMapPtrToPtr::operator[](void* key)
{
	ASSERT_VALID(this);
	
	UINT nHash;
	CAssoc* pAssoc;
	if ((pAssoc = GetAssocAt(key, nHash)) == NULL)
	{
		if (m_pHashTable == NULL)
			InitHashTable(m_nHashTableSize);
		
		// it doesn't exist, add a new Association
		pAssoc = NewAssoc();
		
		pAssoc->key = key;
		// 'pAssoc->value' is a constructed object, nothing more
		
		// put into hash table
		pAssoc->pNext = m_pHashTable[nHash];
		m_pHashTable[nHash] = pAssoc;
	}
	return pAssoc->value;  // return new reference
}


BOOL CMapPtrToPtr::RemoveKey(void* key)
// remove key - return TRUE if removed
{
	ASSERT_VALID(this);
	
	if (m_pHashTable == NULL)
		return FALSE;  // nothing in the table
	
	CAssoc** ppAssocPrev;
	ppAssocPrev = &m_pHashTable[HashKey(key) % m_nHashTableSize];
	
	CAssoc* pAssoc;
	for (pAssoc = *ppAssocPrev; pAssoc != NULL; pAssoc = pAssoc->pNext)
	{
		if (pAssoc->key == key)
		{
			// remove it
			*ppAssocPrev = pAssoc->pNext;  // remove from list
			FreeAssoc(pAssoc);
			return TRUE;
		}
		ppAssocPrev = &pAssoc->pNext;
	}
	return FALSE;  // not found
}


/////////////////////////////////////////////////////////////////////////////
// Iterating

void CMapPtrToPtr::GetNextAssoc(POSITION& rNextPosition,
								void*& rKey, void*& rValue) const
{
	ASSERT_VALID(this);
	ASSERT(m_pHashTable != NULL);  // never call on empty map
	
	CAssoc* pAssocRet = (CAssoc*)rNextPosition;
	ASSERT(pAssocRet != NULL);
	
	if (pAssocRet == (CAssoc*) BEFORE_START_POSITION)
	{
		// find the first association
		for (UINT nBucket = 0; nBucket < m_nHashTableSize; nBucket++)
			if ((pAssocRet = m_pHashTable[nBucket]) != NULL)
				break;
		ASSERT(pAssocRet != NULL);  // must find something
	}
	
	// find next association
	ASSERT(AfxIsValidAddress(pAssocRet, sizeof(CAssoc)));
	CAssoc* pAssocNext;
	if ((pAssocNext = pAssocRet->pNext) == NULL)
	{
		
		// go to next bucket
		for (UINT nBucket = (HashKey(pAssocRet->key) % m_nHashTableSize) + 1;
			 nBucket < m_nHashTableSize; nBucket++)
			if ((pAssocNext = m_pHashTable[nBucket]) != NULL)
				break;
		
	}
	
	rNextPosition = (POSITION) pAssocNext;
	
	// fill in return data
	rKey = pAssocRet->key;
	rValue = pAssocRet->value;
}


/////////////////////////////////////////////////////////////////////////////
// Diagnostics

#ifdef DEBUG


void CMapPtrToPtr::AssertValid() const
{
	//CObject::AssertValid();
	
	ASSERT(m_nHashTableSize > 0);
	ASSERT(m_nCount == 0 || m_pHashTable != NULL);
	// non-empty map should have hash table
}

#endif	//	DEBUG

int CMapPtrToPtr::GetCount() const
{ 
	return m_nCount; 
}

BOOL CMapPtrToPtr::IsEmpty() const
{ 
	return m_nCount == 0; 
}

void CMapPtrToPtr::SetAt(void* key, void* newValue)
{ 
	(*this)[key] = newValue; 
}

POSITION CMapPtrToPtr::GetStartPosition() const
{ 
	return (m_nCount == 0) ? NULL : BEFORE_START_POSITION; 
}

UINT CMapPtrToPtr::GetHashTableSize() const
{ 
	return m_nHashTableSize; 
}
