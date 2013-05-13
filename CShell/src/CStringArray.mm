/*
 *  CStringArray.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CStringArray.h"

CStringArray::CStringArray()
{
	
}

CStringArray::~CStringArray()
{
	
}

int CStringArray::GetSize()
{
	return m_arr.size();
}

void CStringArray::SetSize(int nNewSize, int nGrowBy)
{
	m_arr.resize(nNewSize);
}

void CStringArray::SetAtGrow(int nIndex, char const*  newElement)
{
	m_arr[nIndex] = newElement;
}

void CStringArray::Add(const CString &str)
{
	m_arr.push_back(str);
}

CString CStringArray::operator[](int nIndex) const
{
	return m_arr[nIndex];
}