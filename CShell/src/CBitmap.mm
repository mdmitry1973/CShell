/*
 *  CBitmap.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CBitmap.h"

CBitmap::CBitmap()
{
	
}

CBitmap::~CBitmap()
{
	
}

BOOL CBitmap::LoadBitmap(LPCTSTR lpszResourceName)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

BOOL CBitmap::LoadBitmap(UINT nIDResource)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

BOOL CBitmap::LoadOEMBitmap(UINT nIDBitmap)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

BOOL CBitmap::CreateBitmap(int nWidth, int nHeight, UINT nPlanes, UINT nBitcount, const void* lpBits)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

BOOL CBitmap::Attach(HGDIOBJ hObject)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

HGDIOBJ CBitmap::Detach()
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

CBitmap::operator HBITMAP() const
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

int CBitmap::GetBitmap(BITMAP* pBitMap)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

// Operations
DWORD CBitmap::SetBitmapBits(DWORD dwCount, const void* lpBits)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

DWORD CBitmap::GetBitmapBits(DWORD dwCount, LPVOID lpBits) const
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

CSize CBitmap::SetBitmapDimension(int nWidth, int nHeight)
{
	NSLog(@"to do CBitmap::LoadBitmap");
}

CSize CBitmap::GetBitmapDimension() const
{
	NSLog(@"to do CBitmap::LoadBitmap");
}