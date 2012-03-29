//
//  CNSView.m
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSView.h"

@implementation CNSView

CSHELL_IMPL_STANDARD_METHOD

- (BOOL)isFlipped
{
	return YES;
}

- (void)setTag:(NSInteger)anInt
{
	m_anInt = anInt;
}

- (NSInteger)tag
{
	return m_anInt;
}

@end