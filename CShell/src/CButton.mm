/*
 *  CButton.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CButton.h"

#import "CNSButton.h"

CButton::CButton() : CWnd()
{
	
}

CButton::~CButton()
{
	
}

BOOL CButton::Create(LPCTSTR lpszCaption,
					DWORD dwStyle,
					const RECT& rect,
					CWnd* pParentWnd,
					UINT nID 
					)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	CNSButton *control = [[[CNSButton alloc] initWithFrame: contentRect] autorelease];
	
	if (dwStyle & BS_AUTORADIOBUTTON || dwStyle & BS_RADIOBUTTON)
	{
		[control setCButtonType:NSRadioButton];
		
		if (dwStyle & WS_GROUP)
		{
			[control setGroup:true];
		}
		
		[control setState: false];
	}
	else 
	if (dwStyle & BS_CHECKBOX || dwStyle & BS_AUTOCHECKBOX)
	{
		[control setCButtonType:NSSwitchButton];
		[control setBezelStyle:0]; //This is unnecessary. I include it merely to show that checkboxes don't have a bezel style.
	}
	else 
	{
		[control setBezelStyle: NSRoundedBezelStyle];
	}

	[control setTag:nID];
	
	if (lpszCaption)
	{
		[control setTitle: [NSString stringWithUTF8String: lpszCaption]];
	}
	
	NSObject *parentView = (NSObject *)pParentWnd->GetNSWindow();
	NSView	*pView = nil;
	
	if ([parentView isKindOfClass:[NSView class]])
	{
		pView = (NSView *)parentView;
	}
	else 
		if ([parentView isKindOfClass:[NSWindow class]])
		{
			pView = [(NSWindow *)parentView contentView];
		}
		else
		{
			assert(false);
		}
	
	[pView addSubview: control];	
	
	[control setParentWnd:pParentWnd];
	
	m_hWnd = control;
	mParentWin = pParentWnd;
	
	return TRUE;
}

void CButton::SetCheck(int nCheck)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		CNSButton *button = (CNSButton *)m_hWnd;
				
		[button setState: nCheck];
		
		if ([button getCButtonType] == NSRadioButton)
		{
			[button resetRadioButton];
		}
	}
}

void CButton::SetButtonStyle(UINT nStyle, BOOL bRedraw)
{
	NSLog(@"TO DO CButton::SetButtonStyle");
}

void CButton::SetState(BOOL bHighlight)
{
	NSLog(@"TO DO CButton::SetState");
}

int CButton::GetCheck() const
{
	NSLog(@"TO DO CButton::GetCheck");
	return 0;
}

HBITMAP CButton::SetBitmap(HBITMAP hBitmap)
{
	NSLog(@"TO DO CButton::SetBitmap");
	return 0;
}

HICON CButton::SetIcon(HICON hIcon)
{
	NSLog(@"TO DO CButton::SetIcon");
	return 0;
}
