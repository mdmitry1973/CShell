//
//  CNSButton.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSButton.h"

@implementation CNSButton

CSHELL_IMPL_STANDARD_METHOD
CSHELL_IMPL_CONTROL_STANDARD_METHOD

-(void)setHandle
{
	[self setTarget:self];
	[self setAction:@selector(eventHandle:)];
}

- (id)init 
{
	self = [super init];
	
	if (self)
	{
		mWnd = nil;
		mWndParent = nil;
		mTypeButton = 0;
		mGroup = false;
		[self setHandle];
	}
	
    return self;
}

- (id)initWithFrame:(NSRect)frameRect
{
	self = [super initWithFrame: frameRect];
	
	if (self)
	{
		mWnd = nil;
		mWndParent = nil;
		mTypeButton = 0;
		mGroup = false;
		[self setHandle];
	}
	
    return self;
}

-(void)eventHandle:(id)sender
{
	int tag = [sender tag];
	
	switch (tag)
	{
		case IDOK:
		{
			assert(mWndParent);
			mWndParent->OnOK();
		}
		break;
			
		case IDCANCEL:
		{
			assert(mWndParent);
			mWndParent->OnCancel();
		}
		break;
			
		default:
		{
			if (mTypeButton == NSRadioButton)
			{
				[self resetRadioButton];
			}
		}
		break;
	}
}

- (void)resetRadioButton
{
	NSView *superView = [self superview];
	NSRect frameActiveButton = [self frame];
	bool nCheck = [self state];
	
	if (superView)
	{
		NSArray *arrView = [superView subviews];
		std::vector<NSView *> arrRadioButtons; 
		NSView *groupView = nil;
		bool group = false;
		
		for(int i = 0; i < [arrView count]; i++)
		{
			NSView *view = [arrView objectAtIndex: i];
			
			if ([view isKindOfClass:[NSBox class]] && groupView == nil)
			{
				NSRect frameView = [view frame];
				
				if (NSContainsRect (frameView, frameActiveButton))
				{
					groupView = view;
				}
			}
			else
				if ([view isKindOfClass:[CNSButton class]] && 
					[(CNSButton *)view getCButtonType] == NSRadioButton)
				{
					if (!group)
					{
						group = [(CNSButton *)view getGroup];
					}
					
					if (self != view)
					{
						arrRadioButtons.push_back(view);
					}
				}
		}
		
		if (groupView == nil)
		{
			groupView = superView;
		}
		
		NSRect frameGroupView = [groupView frame];
		
		for(int i = 0; i < arrRadioButtons.size(); i++)
		{
			NSView *view = arrRadioButtons[i];					
			NSRect frameView = [view frame];
			
			if (group && !NSContainsRect (frameGroupView, frameView))
			{
				arrRadioButtons.erase(arrRadioButtons.begin() + i);
				i--;
			}
			else 
			{
				[(NSButton *)view setState: !nCheck];
			}
		}
	}
}

- (void)setCButtonType:(NSButtonType)aType
{
	mTypeButton = aType;
	[self setButtonType:aType];
}

- (NSButtonType)getCButtonType
{
	return mTypeButton;
}

- (void)setGroup:(bool)group
{
	mGroup = group;
}

- (bool)getGroup
{
	return mGroup;
}

@end