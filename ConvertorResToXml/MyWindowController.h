//
//  MyWindowController.mm.h
//
//  Created by Dmitry Mikhaevich on 11/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface MyWindowController : NSWindowController 
{

	IBOutlet NSPathControl	*pathControl;
	IBOutlet NSTextView		*logControl;
}

- (IBAction)browserButton:(id)sender;

@end
