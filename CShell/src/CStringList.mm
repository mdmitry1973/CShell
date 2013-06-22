/*
 *  CStringList.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CStringList.h"

CString CStringList::strEmpty = "";

CStringList::CStringList()
{
	
}

CStringList::CStringList(INT_PTR nBlockSize) : std::list<CString*>(nBlockSize)
{
	
}

CStringList::~CStringList()
{
	
}

INT_PTR CStringList::GetCount() const
{
	return size();
}

INT_PTR CStringList::GetSize() const
{
	return size();
}

BOOL CStringList::IsEmpty() const
{
	return !(size());
}

CString& CStringList::GetHead()
{
	return *(front());
}

const CString& CStringList::GetHead() const
{
	return *(front());
}

CString& CStringList::GetTail()
{
	return *(back());
}

const CString& CStringList::GetTail() const
{
	return *(back());
}

CString CStringList::RemoveHead()
{
	std::list<CString*>::iterator it = begin();
	
	CString s = **it;
	
	delete *it;
	
	erase(it);
	
	return s;
}

CString CStringList::RemoveTail()
{
	std::list<CString*>::iterator it = end();
	
	CString s = **it;
	
	delete *it;
	
	erase(it);
	
	return s;
}

POSITION CStringList::AddHead(LPCTSTR newElement)
{
	push_front(new CString(newElement));
	
	return (POSITION)(*(begin()));
}

POSITION CStringList::AddTail(LPCTSTR newElement)
{
	push_back(new CString(newElement));
	
	return (POSITION)(*(end()));
}

POSITION CStringList::AddHead(const CString& newElement)
{
	push_front(new CString(newElement));
	
	return (POSITION)(*(begin()));
}

POSITION CStringList::AddTail(const CString& newElement)
{
	push_back(new CString(newElement));
	
	return (POSITION)(*(end()));
}

void CStringList::AddHead(CStringList* pNewList)
{
	for (std::list<CString *>::iterator it = pNewList->begin(); it != pNewList->end(); ++it)
	{
		push_front(new CString(**it));
	}
}

void CStringList::AddTail(CStringList* pNewList)
{
	for (std::list<CString *>::iterator it = pNewList->begin(); it != pNewList->end(); ++it)
	{
		push_back(new CString(**it));
	}
}

void CStringList::RemoveAll()
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		delete *it;
	}
	
	clear();
}

POSITION CStringList::GetHeadPosition() const
{
	return (POSITION)(*(begin()));
}

POSITION CStringList::GetTailPosition() const
{
	return (POSITION)(*(end()));
}

CString& CStringList::GetNext(POSITION& rPosition)
{	
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)rPosition)
		{
			++it;
			
			if (it != end())
			{
				return  **it;
			}
		}
	}
	
	return strEmpty;
}

/*
const CString& CStringList::GetNext(POSITION& rPosition) const
{
	CString res;
	
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)rPosition)
		{
			++it;
			
			if (it != end())
			{
				res = **it;
			}
			break;
		}
	}
	
	return res;
}
*/

CString& CStringList::GetPrev(POSITION& rPosition)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)rPosition)
		{
			--it;
			return **it;
		}
	}
	
	return strEmpty;
}

/*
const CString& CStringList::GetPrev(POSITION& rPosition) const
{
	
}
*/

CString& CStringList::GetAt(POSITION position)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)position)
		{
			return **it;
		}
	}
	
	return strEmpty;
}

//const CString& CStringList::GetAt(POSITION position) const
//{
	
//}

void CStringList::SetAt(POSITION pos, LPCTSTR newElement)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)pos)
		{
			**it = newElement;
			break;
		}
	}
}

void CStringList::SetAt(POSITION pos, const CString& newElement)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)pos)
		{
			**it = newElement;
			break;
		}
	}
}

void CStringList::RemoveAt(POSITION position)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)position)
		{
			delete *it;
			erase(it);
			break;
		}
	}
}

POSITION CStringList::InsertBefore(POSITION position, LPCTSTR newElement)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)position)
		{
			--it;
			insert(it, new CString(newElement));
			return (POSITION)(*(it++));
		}
	}
	
	return NULL;
}

POSITION CStringList::InsertAfter(POSITION position, LPCTSTR newElement)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)position)
		{
			insert(it, new CString(newElement));
			return (POSITION)(*(it++));
		}
	}
	
	return NULL;
}

POSITION CStringList::InsertBefore(POSITION position, const CString& newElement)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)position)
		{
			--it;
			insert(it, new CString(newElement));
			return (POSITION)(*(it++));
		}
	}
	
	return NULL;
}

POSITION CStringList::InsertAfter(POSITION position, const CString& newElement)
{
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (*it == (CString *)position)
		{
			insert(it, new CString(newElement));
			return (POSITION)(*(it++));
		}
	}
	
	return NULL;
}

POSITION CStringList::Find(LPCTSTR searchValue, POSITION startAfter)// const
{
	bool start = startAfter == 0 ? true : false;
	
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (!start && *it == (CString *)startAfter)
		{
			start = true;
		}
		
		if (start)
		{
			if (**it == searchValue)
			{
				return (POSITION)(*it);
			}
		}
	}
	
	return NULL;
}

POSITION CStringList::FindIndex(INT_PTR nIndex) ///const
{
	int start = 0;
	
	for (std::list<CString *>::iterator it = begin(); it != end(); ++it)
	{
		if (start == nIndex)
		{
			return (POSITION)(*it);
		}
		
		start++;
	}
	
	return NULL;
}
