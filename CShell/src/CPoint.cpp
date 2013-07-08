/*
 *  CPoint.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */
#include <QPoint>
#include "CDef.h"

#include "CPoint.h"

CPoint::CPoint()
{
	x = 0;
	y = 0;
}

CPoint::~CPoint()
{

}

CPoint::CPoint( int initX, int initY)
{
    x = initX;
    y = initY;
}

CPoint::CPoint( POINT initPt)
{
    x = initPt.x;
    y = initPt.y;
}

CPoint::CPoint( SIZE initSize)
{
    x = initSize.cx;
    y = initSize.cy;
}

CPoint::CPoint( LPARAM dwPoint)
{

}

void CPoint::Offset(int xOffset, int yOffset)
{
    x = x + xOffset;
    y = y + yOffset;
}

void CPoint::Offset( POINT point)
{
    x = x + point.x;
    y = y + point.y;
}

void CPoint::Offset( SIZE size)
{
    x = x + size.cx;
    y = y + size.cy;
}

void CPoint::SetPoint( int X,int Y)
{
    x = X;
    y = Y;
}
