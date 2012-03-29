//
//  MyWindowController.mm.m
//
//  Created by Dmitry Mikhaevich on 11/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MyWindowController.h"

@implementation MyWindowController

- (IBAction)browserButton:(id)sender
{
	NSOpenPanel *openDialog = [NSOpenPanel openPanel];
	
	[openDialog setCanChooseDirectories:false];
	[openDialog setCanChooseFiles:true];
	[openDialog setAllowsMultipleSelection:false];
	
	if ([openDialog runModal] == NSFileHandlingPanelOKButton)
	{
		
	}
}

@end
