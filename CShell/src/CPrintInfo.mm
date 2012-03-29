/*
 *  CPrintInfo.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CPrintInfo.h"

#include "CPrintDialog.h"

CPrintInfo::CPrintInfo()
{

}

CPrintInfo::~CPrintInfo()
{

}

void CPrintInfo::SetMinPage(UINT nMinPage)
{
	NSLog(@"TO DO CPrintInfo::SetMinPage");
}

void CPrintInfo::SetMaxPage(UINT nMaxPage)
{
	NSLog(@"TO DO CPrintInfo::SetMaxPage");
}

UINT CPrintInfo::GetMinPage() const
{
	NSLog(@"TO DO CPrintInfo::GetMinPage");
	return 0;
}

UINT CPrintInfo::GetMaxPage() const
{
	NSLog(@"TO DO CPrintInfo::GetMaxPage");
	return 0;
}

UINT CPrintInfo::GetFromPage() const
{
	NSLog(@"TO DO CPrintInfo::GetFromPage");
	return 0;
}

UINT CPrintInfo::GetToPage() const
{
	NSLog(@"TO DO CPrintInfo::GetToPage");
	return 0;
}

UINT CPrintInfo::GetOffsetPage() const
{
	NSLog(@"TO DO CPrintInfo::GetOffsetPage");
	return 0;
}
