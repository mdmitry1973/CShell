//
//  CNSWindowDelegate.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 CShell. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSWindowDelegate : NSWindowController <NSWindowDelegate>
{
	CWnd *mWindow;
}

-(void)setCWnd:(CWnd *)window;
-(SEL)getMenuCall;
-(void)setMenuAction:(NSMenuItem *)item;

- (IBAction)menuEventHandle:(id)sender;

@end