/*
 *  CStringList.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CSTRINGLIST_DEFINE
#define CSTRINGLIST_DEFINE 1

#include <list>

#include "CDef.h"
#include "CString.h"

class CStringList : public std::list<CString*>
{
	
public:
	
	CStringList();
	CStringList(INT_PTR nBlockSize = 10);
	virtual ~CStringList();
	
	static CString strEmpty;
	
	INT_PTR GetCount() const;
	INT_PTR GetSize() const;
	BOOL IsEmpty() const;
	
	CString& GetHead();
	const CString& GetHead() const;
	CString& GetTail();
	const CString& GetTail() const;
	
	CString RemoveHead();
	CString RemoveTail();
	
	POSITION AddHead(LPCTSTR newElement);
	POSITION AddTail(LPCTSTR newElement);
	
	POSITION AddHead(const CString& newElement);
	POSITION AddTail(const CString& newElement);
	
	
	// add another list of elements before head or after tail
	void AddHead(CStringList* pNewList);
	void AddTail(CStringList* pNewList);
	
	// remove all elements
	void RemoveAll();
	
	// iteration
	POSITION GetHeadPosition() const;
	POSITION GetTailPosition() const;
	CString& GetNext(POSITION& rPosition); // return *Position++
	//const CString& GetNext(POSITION& rPosition) const; // return *Position++
	CString& GetPrev(POSITION& rPosition); // return *Position--
	//const CString& GetPrev(POSITION& rPosition) const; // return *Position--
	
	// getting/modifying an element at a given position
	CString& GetAt(POSITION position);
	//const CString& GetAt(POSITION position) const;
	void SetAt(POSITION pos, LPCTSTR newElement);
	
	void SetAt(POSITION pos, const CString& newElement);
	
	void RemoveAt(POSITION position);
	
	// inserting before or after a given position
	POSITION InsertBefore(POSITION position, LPCTSTR newElement);
	POSITION InsertAfter(POSITION position, LPCTSTR newElement);
	
	POSITION InsertBefore(POSITION position, const CString& newElement);
	POSITION InsertAfter(POSITION position, const CString& newElement);
	
	//
	// helper functions (note: O(n) speed)
	POSITION Find(LPCTSTR searchValue, POSITION startAfter = NULL);//const;
	// defaults to starting at the HEAD
	// return NULL if not found
	POSITION FindIndex(INT_PTR nIndex);// const;
	
private:
	
	//std::list<CString>::iterator mPointer;
	
};

#endif//CSTRINGLIST_DEFINE