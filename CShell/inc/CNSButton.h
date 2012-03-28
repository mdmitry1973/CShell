//
//  CNSButton.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 CShell. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSButton : NSButton
{
	CSHELL_DEF_STANDARD_VAL
	
	NSButtonType	mTypeButton;
	bool			mGroup;
}

CSHELL_DEF_STANDARD_METHOD

- (void)resetRadioButton;
- (void)setCButtonType:(NSButtonType)aType;
- (NSButtonType)getCButtonType;
- (void)setGroup:(bool)group;
- (bool)getGroup;

@end
