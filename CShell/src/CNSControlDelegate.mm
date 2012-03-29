//
//  CNSControlDelegate.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSControlDelegate.h"

@implementation CNSControlDelegate

- (id)init 
{
	mWindow = nil;
	
    return [super init];
}

-(void)setCWnd:(CWnd *)window
{
	mWindow = window;
}

- (void)controlTextDidChange:(NSNotification *)aNotification
{
	if (mWindow)
	{
		NSEvent *event = [NSApp currentEvent];
		
		if ([event type] == NSKeyDown)
		{
			UINT nChar = [event keyCode];
			UINT nRepCnt = 1; 
			UINT nFlags = [event modifierFlags];
			//NSTextField *ed = [aNotification object];
			
			//std::string str2 = [[ed stringValue] UTF8String];
			
			mWindow->OnChar(nChar, nRepCnt, nFlags);
			//mWindow->SendEventHandle([[aNotification object] tag], [aNotification object], EVENT_TYPE_WM_CHAR);
		}
	}
}

- (void)controlTextDidEndEditing:(NSNotification *)aNotification
{
	NSControl *postingObject = [aNotification object];
	
	NSLog(@"controlTextDidEndEditing %d", postingObject);
}

- (void)controlTextDidBeginEditing:(NSNotification *)aNotification
{
	NSControl *postingObject = [aNotification object];
	
	NSLog(@"controlTextDidBeginEditing %d", postingObject);
}

//- (NSArray *)control:(NSControl *)control textView:(NSTextView *)textView completions:(NSArray *)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(NSInteger *)index
//{
//	return words;
//}

@end
