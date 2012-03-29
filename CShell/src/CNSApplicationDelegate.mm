//
//  CNSApplicationDelegate.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"
#include "CWinApp.h"

#import "CNSApplicationDelegate.h"
#import "CNSWindow.h"

extern CNSApplicationDelegate	*pMainAppCocoa;
extern CWinApp					*pMainApp;

@implementation CNSApplicationDelegate

- (id)init 
{
    return [super init];
}

- (void)orderFrontStandardAboutPanel:(id)sender
{
	NSLog(@"orderFrontStandardAboutPanel");
}

- (void)orderFrontStandardAboutPanelWithOptions:(NSDictionary *)optionsDictionary
{
	NSLog(@"orderFrontStandardAboutPanelWithOptions");
}

- (void)applicationDidBecomeActive:(NSNotification *)notification
{
	NSLog(@"applicationDidBecomeActive");
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
	pMainAppCocoa = self;
	
	if (!pMainApp->InitInstance())
	{
		//assert(false);
	}
	
	pMainApp->SetMessageMap();
}

- (void)setAppPointer:(CWinApp*)app
{
	
}

- (IBAction)menuEventHandle:(id)sender
{
	if (pMainApp && [sender isKindOfClass: [NSMenuItem class]])
	{
		NSMenuItem *item = (NSMenuItem *)sender;
		
		if (!pMainApp->SendEventHandle([item tag], item, EVENT_TYPE_COMMAND))
		{
			CNSWindow *winCurrent = [NSApp keyWindow];
			
			if (winCurrent && [winCurrent isKindOfClass: [CNSWindow class]])
			{
				CWnd *wnd = [winCurrent getWnd];
				
				if (wnd)
				{
					wnd->SendEventHandle([item tag], item, EVENT_TYPE_COMMAND);
				}
			}
		}
	}
}

@end

