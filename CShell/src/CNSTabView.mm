//
//  CNSTabView.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSTabView.h"

@implementation CNSTabView

CSHELL_IMPL_STANDARD_METHOD
CSHELL_IMPL_CONTROL_STANDARD_METHOD
CSHELL_IMPL_STANDARD_EVENTS

- (id)init 
{
	self = [super init];
	
    return self;
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