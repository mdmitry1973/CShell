//
//  CNSProgressIndicator.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSProgressIndicator.h"


@implementation CNSProgressIndicator

CSHELL_IMPL_STANDARD_METHOD
CSHELL_IMPL_CONTROL_STANDARD_METHOD

- (id)init 
{
	self = [super init];
	
	if (self)
	{
		m_anInt = -1;
	}
	
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