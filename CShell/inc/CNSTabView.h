//
//  CNSTabView.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 CShell. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSTabView : NSTabView
{
	CSHELL_DEF_STANDARD_VAL
	
	NSInteger m_anInt;
}

- (void)setTag:(NSInteger)anInt;

CSHELL_DEF_STANDARD_METHOD

@end