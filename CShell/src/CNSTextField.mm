//
//  CNSTextField.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSTextField.h"
#import "CNSWindow.h"

@implementation CNSTextField

CSHELL_IMPL_STANDARD_METHOD
CSHELL_IMPL_CONTROL_STANDARD_METHOD

- (id)init 
{
	self = [super init];
	
	mSkipChar = false;
	
    return self;
}

- (id)initWithFrame:(NSRect)frameRect
{
	self = [super initWithFrame: frameRect];
	
	if (self)
	{
		mSkipChar = false;
	}
	
    return self;
}

- (void)setSkipChar:(bool)skipChar
{
	mSkipChar = skipChar;
}

- (BOOL) textView: (NSTextView*) textView shouldChangeTextInRange: (NSRange) range replacementString: (NSString*) replacementString
{
	NSEvent *event = [NSApp currentEvent];
	
	if (mWnd && [event type] == NSKeyDown)
	{
		
		UINT nChar = [[event characters] characterAtIndex: 0];
		UINT nRepCnt = 1; 
		UINT nFlags = [event modifierFlags];
		
		mWnd->OnChar(nChar, nRepCnt, nFlags);
		
		if (mSkipChar)
		{
			mSkipChar = false;
			return FALSE;
		}
	}
	
	return TRUE;
}

- (void)keyDown:(NSEvent *)theEvent
{
	[super keyDown:theEvent];
}

- (void)keyUp:(NSEvent *)theEvent
{
	[super keyUp:theEvent];
}

- (void)flagsChanged:(NSEvent *)theEvent
{
	[super flagsChanged:theEvent];
}

- (void)interpretKeyEvents:(NSArray *)eventArray
{
	[super interpretKeyEvents:eventArray];
}

- (void)insertTab:(id)sender 
{
    if ([[self window] firstResponder] == self) 
	{
        [[self window] selectNextKeyView:self];
    }
}

- (void)insertBacktab:(id)sender 
{
    if ([[self window] firstResponder] == self) 
	{
        [[self window] selectPreviousKeyView:self];
		
    }
}

- (BOOL)becomeFirstResponder
{
	//NSView *view = [self previousKeyView];
	//NSLog(@"TO DO becomeFirstResponder view=%d", view, [view class]);
	//NSResponder *view = [[self window] firstResponder];
	//NSLog(@"TO DO becomeFirstResponder view=%d", view, [view class]);
	NSLog(@"TO DO becomeFirstResponder %d", self);
	return [super becomeFirstResponder];
}

- (BOOL)resignFirstResponder
{
	/*
	if (mWnd)
	{
		CNSWindow *wnd = [self window];
		CWnd *cwnd = nil;
		
		if (wnd)
		{
			CWnd *mainwnd = [wnd getWnd];
			NSResponder *resp = [wnd firstResponder];
			
			if (resp && mainwnd && [resp respondsToSelector:@selector(tag:)])
			{
				NSInteger id_obj = (NSInteger)[resp tag];
				cwnd = mainwnd->GetDlgItem(id_obj);
			}
		}
		
		mWnd->OnKillFocus(cwnd);
	}
	*/
	
	return [super resignFirstResponder];
}

@end