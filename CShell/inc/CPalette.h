/*
 *  CPalette.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CPALETTE_DEFINE
#define CPALETTE_DEFINE 1

#include "CGdiObject.h"

class CDC;

class CPalette : public CGdiObject
{
	
public:
	
	CPalette();
	
	virtual ~CPalette();
	
	BOOL CreateHalftonePalette(CDC* pDC );
	
};

#endif//CPALETTE_DEFINE