//
//  CNSStepper.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 CShell. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSStepper : NSStepper
{
	CSHELL_DEF_STANDARD_VAL
	
	double mStoreValue;
}

CSHELL_DEF_STANDARD_METHOD

- (void)resetStoreValue;
- (double)getStoreValue;

@end