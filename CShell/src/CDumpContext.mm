/*
 *  CArchive.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "afxwin.h"
#include "CFile.h"

#include "CDumpContext.h"

#import <Cocoa/Cocoa.h>

CDumpContext::CDumpContext(CFile* pFile)
{
	NSLog(@"TO DO CDumpContext");
}

int CDumpContext::GetDepth() const
{
	NSLog(@"TO DO CDumpContext");
	return 0;
}

void CDumpContext::SetDepth(int nNewDepth)
{
	NSLog(@"TO DO CDumpContext");
}

CDumpContext& CDumpContext::CDumpContext::operator<<(LPCTSTR lpsz)
{
	return *this;
}

CDumpContext& CDumpContext::operator<<(const void* lp)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(const CObject* pOb)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(const CObject& ob)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(BYTE by)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(WORD w)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::DumpAsHex(BYTE b)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::DumpAsHex(WORD w)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(LONG l)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(DWORD dw)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(UINT u)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::DumpAsHex(LONG l)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::DumpAsHex(DWORD dw)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::DumpAsHex(UINT u)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(float f)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(double d)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(LONGLONG n)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::operator<<(ULONGLONG n)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::DumpAsHex(LONGLONG n)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}

CDumpContext& CDumpContext::DumpAsHex(ULONGLONG n)
{
	NSLog(@"TO DO CDumpContext");
	return *this;
}



void CDumpContext::HexDump(LPCTSTR lpszLine, BYTE* pby, int nBytes, int nWidth)
{
	
}

void CDumpContext::Flush()
{
	
}


//CDumpContext(const CDumpContext& dcSrc);
//void operator=(const CDumpContext& dcSrc);
//void OutputString(LPCTSTR lpsz);
