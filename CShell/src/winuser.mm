/*
 *  winuser.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "winuser.h"

#import <Cocoa/Cocoa.h>

DWORD GetSysColor(int nIndex)
{
	NSLog(@"TO DO GetSysColor");
	return 0;
}

BOOL DestroyIcon(HICON hIcon)
{
	NSLog(@"TO DO DestroyIcon");
	return 0;
}

UINT ExtractIconEx(LPCSTR lpszFile, int nIconIndex, HICON *phiconLarge, HICON *phiconSmall, UINT nIcons)
{
	NSLog(@"TO DO ExtractIconEx");
	return 0;
}

int SHFileOperation(LPSHFILEOPSTRUCT lpFileOp)
{
	NSLog(@"TO DO SHFileOperation");
	return 0;
}

