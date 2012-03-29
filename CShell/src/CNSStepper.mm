//
//  CNSStepper.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSStepper.h"

@implementation CNSStepper

CSHELL_IMPL_STANDARD_METHOD
CSHELL_IMPL_CONTROL_STANDARD_METHOD

- (id)init 
{
	self = [super init];
	
	mStoreValue = 0;
	
    return self;
}

- (void)setIntValue:(int)anInt
{
	mStoreValue = anInt;
	[super setIntValue: anInt];
}

- (void)setFloatValue:(float)aFloat
{
	mStoreValue = aFloat;
	[super setFloatValue: aFloat];
}

- (void)setDoubleValue:(double)aDouble
{
	mStoreValue = aDouble;
	[super setDoubleValue: aDouble];
}

- (void)resetStoreValue
{
	mStoreValue = [self doubleValue];
}

- (double)getStoreValue
{
	return mStoreValue;
}

@end