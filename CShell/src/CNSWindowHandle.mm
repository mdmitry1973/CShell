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
		mWindow->SendEventHandle([sender tag], sender, -1);
	}
}

@end