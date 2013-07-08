/*
 *  CSize.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QSize>
#include "CDef.h"

#include "CSize.h"

CSize::CSize()
{
	cx = 0;
	cy = 0;
}

CSize::~CSize()
{

}

CSize::CSize(int initCX, int initCY)
{
	cx = initCX;
	cy = initCY;
}

CSize::CSize( SIZE initSize)
{
	cx = initSize.cx;
	cy = initSize.cy;
}

CSize::CSize( POINT initPt)
{
	cx = initPt.x;
	cy = initPt.y;
}

CSize::CSize( DWORD dwSize)
{
	cx = 0;
	cy = 0;
}
