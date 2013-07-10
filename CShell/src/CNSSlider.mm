//
//  CNSSlider.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"
#include "CWinApp.h"
#include "CTargetEvent.h"

#import "CNSSlider.h"


@implementation CNSSlider

CSHELL_IMPL_STANDARD_METHOD
CSHELL_IMPL_CONTROL_STANDARD_METHOD

- (id)init 
{
	self = [super init];
	
    return self;
}

- (void)mouseUp:(NSEvent *)theEvent
{
	
}

-(void)controlEventHandle:(id)sender
{
	CWinApp* app = AfxGetApp();
		
	if (app)
	{
		app->SendEventHandle(0, self, EVENT_TYPE_WM_HSCROLL);
	}
}

@end