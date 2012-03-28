/*
 *  CDC.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CDC_DEFINE
#define CDC_DEFINE 1

#include "CDef.h"
#include "CObject.h"

class CDC : public CObject
{
	
public:
	
	CDC();
	virtual ~CDC();
	
	HDC m_hAttribDC;
	HDC m_hDC;
};

#endif//CDC_DEFINE