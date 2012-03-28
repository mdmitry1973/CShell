/*
 *  CObArray.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <vector>

#include "CObject.h"

#ifndef COBARRAY_DEFINE
#define COBARRAY_DEFINE 1

class CObArray : public std::vector<CObject*>
{
	
public:
	
	CObArray();
	virtual ~CObArray();
	
	INT_PTR GetCount( ) const;
	INT_PTR Add(CObject* newElement);
	
protected:

};

#endif//COBARRAY_DEFINE