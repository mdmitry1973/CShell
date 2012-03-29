/*
 *  CObArray.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CObArray.h"

CObArray::CObArray()
{
	
}

CObArray::~CObArray()
{

}

INT_PTR CObArray::GetCount( ) const
{
	return size();
}

INT_PTR CObArray::Add(CObject* newElement)
{
	push_back(newElement);
	return size();
}
