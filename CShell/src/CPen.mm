/*
 *  CPen.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CPen.h"

CPen::CPen()
{
	NSLog(@"TO DO CPen::CPen");
}

CPen::CPen(int nPenStyle, int nWidth, COLORREF crColor)
{
	NSLog(@"TO DO CPen::CPen");
}

CPen::CPen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
	 int nStyleCount, const DWORD* lpStyle)
{
	NSLog(@"TO DO CPen::CPen");
}

CPen::~CPen()
{
	NSLog(@"TO DO CPen::CPen");
}

BOOL CPen::CreatePen(int nPenStyle, int nWidth, COLORREF crColor)
{
	NSLog(@"TO DO CPen::CreatePen");
}

BOOL CPen::CreatePen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
			   int nStyleCount, const DWORD* lpStyle)
{
	NSLog(@"TO DO CPen::CreatePen");
}

CPen::operator HPEN() const
{
	NSLog(@"TO DO CPen::HPEN");
}

CPen* CPen::FromHandle(HPEN hPen)
{
	NSLog(@"TO DO CPen::FromHandle");
}
