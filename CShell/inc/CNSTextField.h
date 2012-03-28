//
//  CNSTextField.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 CShell. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSTextField : NSTextField
{
	CSHELL_DEF_STANDARD_VAL
	bool mSkipChar;
}

CSHELL_DEF_STANDARD_METHOD

- (void)setSkipChar:(bool)skipChar;

@end