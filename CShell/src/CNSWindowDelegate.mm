//
//  CNSWindowDelegate.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSWindowDelegate.h"

@implementation CNSWindowDelegate

- (id)init 
{
	mWindow = nil;
	
    return [super init];
}

-(void)setCWnd:(CWnd *)window
{
	mWindow = window;
	
	[self setWindow: (NSWindow *)(mWindow->GetNSWindow())];
}

- (IBAction)menuEventHandle:(id)sender
{
	if (mWindow)
	{
		NSLog(@"menuEventHandle");
		//mWindow->OnSysCommand(UINT nID, LPARAM lParam);
	}
}

-(void)setMenuAction:(NSMenuItem *)item
{
	[item setTarget: self];
	[item setAction:@selector(menuEventHandle:)];//[dlg getMenuCall]];
}

-(SEL)getMenuCall
{
	return @selector(menuEventHandle:);
}

- (void)windowDidMove:(NSNotification*)notification 
{
	
}

- (void)windowWillBeginSheet:(NSNotification *)notification
{
	NSLog(@"windowWillBeginSheet");
}

- (NSRect)window:(NSWindow *)window willPositionSheet:(NSWindow *)sheet usingRect:(NSRect)rect
{
	NSLog(@"willPositionSheet");
	
	return rect;
}

- (void)windowDidBecomeMain:(NSNotification *)notification
{
	NSString *name = [notification name];
	NSObject *obj = [notification object];
	NSDictionary *dic = [notification userInfo];
	
	NSLog(@"windowDidBecomeMain");
}

- (void)windowDidResignMain:(NSNotification *)notification
{
	NSLog(@"windowDidResignMain");
}

- (void)windowDidBecomeKey:(NSNotification *)notification
{
	NSString *name = [notification name];
	NSObject *obj = [notification object];
	NSDictionary *dic = [notification userInfo];
	
	NSLog(@"windowDidBecomeKey");
}

- (void)windowDidResignKey:(NSNotification *)notification
{
	//NSString *name = [notification name];
	//NSObject *obj = [notification object];
	//NSDictionary *dic = [notification userInfo];
	
	NSLog(@"windowDidResignKey");
}

@end
