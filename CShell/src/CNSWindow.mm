//
//  CNSWindow.m
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSWindow.h"

@implementation CNSWindow

CSHELL_IMPL_STANDARD_METHOD

- (id)initWithContentRect:(NSRect)contentRect styleMask:(NSUInteger)windowStyle backing:(NSBackingStoreType)bufferingType defer:(BOOL)deferCreation
{
	self = [super initWithContentRect: contentRect styleMask:windowStyle backing:bufferingType defer:deferCreation];
	
	mViewFocus = nil;
	
    return self;
}

- (id)initWithContentRect:(NSRect)contentRect styleMask:(NSUInteger)windowStyle backing:(NSBackingStoreType)bufferingType defer:(BOOL)deferCreation screen:(NSScreen *)screen
{
	self = [super initWithContentRect: contentRect styleMask:windowStyle backing:bufferingType defer:deferCreation screen:screen];
	
	mViewFocus = nil;
	
    return self;
}

- (BOOL)makeFirstResponder:(NSResponder *)responder
{
	NSResponder *preFocus = [self firstResponder];
	
	if (![responder isKindOfClass: [NSText class]] &&
		preFocus != responder)
	{
		if (![responder isKindOfClass: [NSTextField class]] )
		{//kill focus
			if ([preFocus respondsToSelector:@selector(getWnd)])
			{
				CWnd *wnd = (CWnd *)[preFocus getWnd];
				CWnd *cwnd = nil;
				
				if (wnd)
				{
					if (mWnd &&
						[mViewFocus respondsToSelector:@selector(tag)])
					{
						NSInteger id_obj = (NSInteger)[mViewFocus tag];
						cwnd = mWnd->GetDlgItem(id_obj);
					}
					
					NSLog(@"wnd->OnKillFocus");
					wnd->OnKillFocus(cwnd);
				}
			}		
		}
		
		mViewFocus = responder;
		
		if ([mViewFocus respondsToSelector:@selector(getWnd)])
		{
			CWnd *wnd = (CWnd *)[mViewFocus getWnd];
			CWnd *cwnd = nil;
			
			if (wnd)
			{
				if (mWnd &&
					[preFocus respondsToSelector:@selector(tag)])
				{
					NSInteger id_obj = (NSInteger)[preFocus tag];
					cwnd = mWnd->GetDlgItem(id_obj);
				}
				
				NSLog(@"wnd->OnSetFocus");
				wnd->OnSetFocus(cwnd);
			}
		}
	}
	
	NSLog(@"TO DO CNSWindow makeFirstResponder %d %@", responder, [responder class]);
	return [super makeFirstResponder: responder];
}

- (NSObject *)getCurrentFocus
{
	return mViewFocus;
}

- (void)makeKeyAndOrderFront:(id)sender
{
	NSLog(@"TO DO CNSWindow makeKeyAndOrderFront %d %@", sender, [sender class]);
	[super makeKeyAndOrderFront: sender];
}

- (NSView *)initialFirstResponder
{
	NSView *view = [super initialFirstResponder];
	
	NSLog(@"TO DO CNSWindow initialFirstResponder %d %@", view, [view class]);
	
	return view;
}

- (void)setInitialFirstResponder:(NSView *)view
{
	NSLog(@"TO DO CNSWindow setInitialFirstResponder %d %@", view, [view class]);
	
	if (![view isKindOfClass: [NSText class]])
	{
		mViewFocus = view;
	}
	
	[super setInitialFirstResponder:view];
}

/*

- (BOOL)validateUserInterfaceItem:(id < NSValidatedUserInterfaceItem >)anItem
{
	return YES;
}

-(void)menuEventHandle:(id)sender
{
	if (mViewFocus)
	{
		//mWindow->OnSysCommand(UINT nID, LPARAM lParam);
	}
}

-(void)setMenuAction:(NSMenuItem *)item
{
	[item setTarget: self];
	[item setAction:@selector(menuEventHandle:)];//[dlg getMenuCall]];
}

- (BOOL)validateMenuItem:(NSMenuItem *)item {
	
	
    return YES;
	
}

*/

@end