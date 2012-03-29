//
//  CNSTextFieldDelegate.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSWindow.h"
#import "CNSTextFieldDelegate.h"

@implementation CNSTextFieldDelegate

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
	//NSText *fieldEditor = [[aNotification userInfo] objectForKey:@"NSFieldEditor"];  
	
	//NSString *strrr = [fieldEditor string];           
	
    //NSControl *postingObject = [aNotification object]; // the object that posted the notification
	
	if (mWindow)
	{
		//NSEvent *event = [NSApp currentEvent];
		
		//if ([event type] == NSKeyDown)
		//{
		//	UINT nChar = [event keyCode];
		//	UINT nRepCnt = 1; 
		//	UINT nFlags = [event modifierFlags];
		//	//NSTextField *ed = [aNotification object];
		
		//std::string str2 = [[ed stringValue] UTF8String];
		
		//	mWindow->OnChar(nChar, nRepCnt, nFlags);
		//mWindow->SendEventHandle([[aNotification object] tag], [aNotification object], EVENT_TYPE_WM_CHAR);
		//}
		//UINT nChar;
		//UINT nRepCnt; 
		//UINT nFlags;
		//NSTextField *ed = [aNotification object];
		
		//std::string str2 = [[ed stringValue] UTF8String];
		
		//mWindow->OnChar(nChar, nRepCnt, nFlags);
		//mWindow->SendEventHandle([[aNotification object] tag], [aNotification object], EVENT_TYPE_WM_CHAR);
	}
}

- (void)controlTextDidEndEditing:(NSNotification *)aNotification
{
	NSView *postingObject = [aNotification object];
	
	NSLog(@"controlTextDidEndEditing %d", postingObject);
	
	if ([postingObject isKindOfClass: [NSView class]])
	{
		CWnd *mainwnd = nil;
		CWnd *newWin = nil;
		NSInteger id_obj = -1;
		CNSWindow *win = (CNSWindow *)[postingObject window];
		
		if (win)
		{
			NSView *obj = (NSView *)[win getCurrentFocus];
			
			mainwnd = [win getWnd];
			
			if (obj && [obj isKindOfClass: [NSView class]])
			{
				id_obj = [obj tag];
				newWin = mainwnd->GetDlgItem(id_obj);
			}			
		}
		
		NSLog(@"mWindow->OnKillFocus");
		mWindow->OnKillFocus(newWin);
	}
}

- (void)controlTextDidBeginEditing:(NSNotification *)aNotification
{
	NSControl *postingObject = [aNotification object];
	
	NSLog(@"controlTextDidBeginEditings %d", postingObject);
	
	////if (mWindow)
	//{
	//	NSTextField *ed = [aNotification object];
	
	//	str = [[ed stringValue] UTF8String];
	//}
}

//- (BOOL)control:(NSControl *)control textShouldEndEditing:(NSText *)fieldEditor
//{

//	return true;
//}

//- (NSArray *)control:(NSControl *)control textView:(NSTextView *)textView completions:(NSArray *)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(NSInteger *)index
//{
//return words;
//}

- (BOOL)control:(NSControl *)control textView:(NSTextView *)fieldEditor 
doCommandBySelector:(SEL)commandSelector {
    if( commandSelector == @selector(moveUp:) ){
        // Your increment code
        return YES;    // We handled this command; don't pass it on
    }
    if( commandSelector == @selector(moveDown:) ){
        // Your decrement code
        return YES;
    }
	
    return NO;    // Default handling of the command
	
} 

- (BOOL)performKeyEquivalent:(NSEvent *)theEvent{
    switch ([[theEvent charactersIgnoringModifiers] characterAtIndex:0]) {
        case NSUpArrowFunctionKey:
            // Increase by 5 here
            return YES;
            break;
        case NSDownArrowFunctionKey:;
            // Decrease by 5 here
            return YES;
            break;
        default:
            break;
    }
    return [super performKeyEquivalent:theEvent];
}


//- (NSArray *)control:(NSControl *)control textView:(NSTextView *)textView completions:(NSArray *)words forPartialWordRange:(NSRange)charRange indexOfSelectedItem:(NSInteger *)index
//{
//
//}

///- (BOOL)textView:(NSTextView *)aTextView shouldChangeTextInRange:(NSRange)affectedCharRange replacementString:(NSString *)replacementString
//{
//	return true;
//}

//- (BOOL)textView:(NSTextView *)textView shouldChangeTextInRanges:(NSArray *)affectedRanges replacementStrings:(NSArray *)replacementStrings
//{
//	return true;
//}

@end
