//
//  CNSTabViewDelegate.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSWindow.h"
#import "CNSTabViewDelegate.h"

@implementation CNSTabViewDelegate

- (id)init 
{
	mWindow = nil;
	
    return [super init];
}

-(void)setCWnd:(CWnd *)window
{
	mWindow = window;
}

- (void)tabView:(NSTabView *)tabView willSelectTabViewItem:(NSTabViewItem *)tabViewItem
{
	if (mWindow)
	{
		mWindow->SendEventHandle([tabView tag], tabView, TCN_SELCHANGING);
	}
}

- (void)tabView:(NSTabView *)tabView didSelectTabViewItem:(NSTabViewItem *)tabViewItem
{
	if (mWindow)
	{
		mWindow->SendEventHandle([tabView tag], tabView, TCN_SELCHANGE);
	}
}

@end
