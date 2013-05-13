/*
 *  CStringArray.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CSTRINGARRAY_DEFINE
#define CSTRINGARRAY_DEFINE 1

#include "CDef.h"
#include "CString.h"
#include <vector>

class CStringArray 
{
	
public:
	
	CStringArray();
	virtual ~CStringArray();
	
	int GetSize();
	void SetSize(int nNewSize, int nGrowBy = -1);
	
	void SetAtGrow(int nIndex, char const* newElement);
	
	void Add(const CString &str);
	
	//CString* operator [](int nIndex) const;
	//CString*& operator [](int nIndex) const;
	CString operator[](int nIndex) const;
	
private:
	
	std::vector<CString> m_arr;
	
};

#endif//CSTRINGARRAY_DEFINE