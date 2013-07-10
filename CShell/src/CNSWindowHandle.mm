//
//  CNSWindowHandle.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSWindowHandle.h"
#import "CNSSlider.h"

@implementation CNSWindowHandle

- (id)init 
{
	mWindow = nil;
	
    return [super init];
}

-(void)setCWnd:(CWnd *)window
{
	mWindow = window;
}

-(void)controlEventHandle:(id)sender
{
	if (mWindow)
	{
		int eventType = -1;
		int tag = [sender tag];
		
		if ([sender isKindOfClass:[CNSSlider class]])
		{
			eventType = EVENT_TYPE_WM_HSCROLL;
			tag = 0;
		}
		
		mWindow->SendEventHandle(tag, sender, eventType);
	}
}

@end