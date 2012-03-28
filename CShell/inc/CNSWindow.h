//
//  CNSWindow.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSWindow : NSWindow
{
	CSHELL_DEF_STANDARD_VAL
	
	
	NSObject *mViewFocus;
}

CSHELL_DEF_STANDARD_METHOD

- (NSObject *)getCurrentFocus;

@end
