/*
 *  CObList.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef COBLIST_DEFINE
#define COBLIST_DEFINE 1

#include "CDef.h"

#include <list>

#include "CObject.h"

class CObList : public std::list<CObject**>
{
	// Constructors
public:
	
	CObList(INT_PTR nBlockSize = 10);
	
	~CObList();
	
	static CObject *p_null;
	
	POSITION Find(CObject* searchValue, POSITION startAfter = NULL) const;
	
	POSITION FindIndex(INT_PTR nIndex) const;
	
	POSITION AddHead(CObject* newElement);
	void AddHead( CObList* pNewList);
	
	CObject*& GetNext(POSITION& rPosition );
	const CObject* GetNext(POSITION& rPosition  ) const;
								 
	POSITION AddTail(CObject* newElement);
	 void AddTail(CObList* pNewList);
	
	INT_PTR GetCount() const;
	BOOL IsEmpty( ) const;
	
	CObject*& GetAt(POSITION position);
	//const CObject*& GetAt(POSITION position) const;
	
	CObject*& GetHead();
	//const CObject*& GetHead() const;
	
	POSITION GetHeadPosition() const;
	
	void RemoveAll();	
	void RemoveAt(POSITION position);
	
	CObject* RemoveHead();
	
	CObject* RemoveTail();
	
	void SetAt(POSITION pos, CObject* newElement);
	
	CObject* m_constObj;
};


#endif//COBLIST_DEFINE