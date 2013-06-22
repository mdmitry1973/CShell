/*
 *  CObList.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CObList.h"

CObject *CObList::p_null = NULL;

CObList::CObList(INT_PTR nBlockSize)  : std::list<CObject**>(nBlockSize)
{
	
}

CObList::~CObList()
{
	
}

POSITION CObList::Find(CObject* searchValue, POSITION startAfter) const
{
	for (std::list<CObject **>::const_iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CObject **)startAfter)
		{
			if (searchValue == **it)
			{
				return (POSITION)(*it);
			}
		}
	}
	
	return 0;
}

POSITION CObList::FindIndex(INT_PTR nIndex) const
{
	int i = 0;
	
	for (std::list<CObject **>::const_iterator it = begin(); it != end(); ++it)
	{
		if (i == nIndex)
		{
			return (POSITION)(*it);
		}
		
		i++;
	}
	
	return 0;
}

POSITION CObList::AddHead(CObject* newElement)
{
	push_front(new CObject *);
	
	return (POSITION)(*(begin()));
}

void CObList::AddHead( CObList* pNewList)
{
	insert(begin(), pNewList->begin(), pNewList->end());
}

POSITION CObList::AddTail(CObject* newElement)
{
	push_back(new CObject *);
	
	return (POSITION)(*(end()));
}

void CObList::AddTail(CObList* pNewList)
{
	insert(end(), pNewList->begin(), pNewList->end());
}

BOOL CObList::IsEmpty() const
{
	return size() ? FALSE : TRUE;
}

INT_PTR CObList::GetCount() const
{
	return size();
}

CObject*& CObList::GetAt(POSITION position)
{
	for (std::list<CObject **>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CObject **)position)
		{
			return **it;
		}
	}
	
	return p_null;
}

//const CObject*& CObList::GetAt(POSITION position) const
//{
	
//}

CObject*& CObList::GetNext(POSITION& rPosition )
{
	for (std::list<CObject **>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CObject **)rPosition)
		{
			it++;
			
			if (it != end())
			{
				return **it;
			}
		}
	}
	
	return p_null;
}

const CObject* CObList::GetNext(POSITION& rPosition  ) const
{
	for (std::list<CObject **>::const_iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CObject **)rPosition)
		{
			it++;
			
			if (it != end())
			{
				return **it;
			}
		}
	}
	
	return p_null;
}

CObject*& CObList::GetHead()
{
	return *(front());
}

//const CObject*& CObList::GetHead() const
//{
//	std::list<CObject*>::const_iterator it = begin();
	////m_constObj = front();
//	return *it;
	
	//return *(const_iterator(this->_M_impl._M_node._M_next));
//}

POSITION CObList::GetHeadPosition() const
{
	return (POSITION)(*(begin()));
}

void CObList::RemoveAll()
{
	for (std::list<CObject **>::iterator it = begin(); it != end(); ++it)
	{
		delete *it;
	}
	
	clear();
}

void CObList::RemoveAt(POSITION position)
{
	for (std::list<CObject **>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CObject **)position)
		{
			delete *it;
			erase(it);
			break;
		}
	}
}

CObject* CObList::RemoveHead()
{
	std::list<CObject**>::iterator it = begin();
	
	CObject *s = **it;
	
	delete *it;
	
	erase(it);
	
	return s;
}

CObject* CObList::RemoveTail()
{
	std::list<CObject**>::iterator it = end();
	
	CObject *s = **it;
	
	delete *it;
	
	erase(it);
	
	return s;
}

void CObList::SetAt(POSITION pos, CObject* newElement)
{
	for (std::list<CObject **>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CObject **)pos)
		{
			**it = newElement;
			break;
		}
	}
}
