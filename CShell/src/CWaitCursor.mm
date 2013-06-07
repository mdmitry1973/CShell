/*
 *  CWaitCursor.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CWaitCursor.h"

@interface WaitHelper : NSObject

{
	
	CWaitCursor *m_wait;
}

@end

@implementation WaitHelper

- (void)wait:(CWaitCursor*)theWait
{
	m_wait = theWait;
}

- (void)helperMethod:(NSTimer*)theTimer
{
	if ([NSApp runModalSession:*((NSModalSession *)(m_wait->m_session))] != NSRunContinuesResponse)
	{
		
	}	
}

- (void)helperStopMethod:(NSTimer*)theTimer
{
	[NSApp stopModalWithCode: NSRunContinuesResponse];	
}

@end

CWaitCursor::CWaitCursor()
{
	NSBackingStoreType bufferingType = NSBackingStoreBuffered;
	NSUInteger windowStyle = NSBorderlessWindowMask;						
	NSRect contentRect;

	contentRect.origin.x = 0;
	contentRect.origin.y = 0; 
	contentRect.size.width = 50; 
	contentRect.size.height = 50;
	
	NSWindow *hWnd = [[NSWindow alloc] initWithContentRect:contentRect styleMask:windowStyle backing:bufferingType defer:YES];
	[hWnd setContentView: [[[NSView alloc] initWithFrame: contentRect] autorelease]];
	NSView *view = [hWnd contentView];
	NSProgressIndicator *progress = [[[NSProgressIndicator alloc] initWithFrame: contentRect] autorelease];
	
	[progress setStyle: NSProgressIndicatorSpinningStyle ];
	[hWnd center];
	[hWnd setLevel: NSFloatingWindowLevel];
	
	[view addSubview: progress];
	
	NSWindowController *mWindowController = [[NSWindowController alloc] initWithWindow: hWnd];
	
	[progress startAnimation:hWnd];
	
	m_hWnd = hWnd;
	
	[mWindowController showWindow: nil];
	m_mWindowController = mWindowController;
	
	//[hWnd makeMainWindow];
	
	NSModalSession session = [NSApp beginModalSessionForWindow:[(NSWindowController *)mWindowController window]];
	m_session = new	NSModalSession;	
	(*(NSModalSession *)m_session) = session;
	
	WaitHelper *helper = [WaitHelper alloc];
	
	[helper wait: this];
	
	NSTimer *timer = [NSTimer timerWithTimeInterval:1 target:helper selector:@selector(helperMethod:) userInfo:nil repeats:YES];
	
	//[NSApp endModalSession:session];
	
	m_helper = helper;
	m_timer = timer;
	
	[timer fire];
}

CWaitCursor::~CWaitCursor()
{
	[(NSTimer *)m_timer invalidate];
	
	[NSApp endModalSession: *((NSModalSession*)m_session)];
	delete (NSModalSession*)m_session;
	
	if (m_mWindowController)
	{
		[(NSWindowController *)m_mWindowController close];
		[(NSWindowController *)m_mWindowController release];
	}
	
	if (m_hWnd)
	{
		[(NSWindow *)m_hWnd dealloc];
	}
}

void CWaitCursor::Restore()
{
	NSLog(@"TO DO CWaitCursor::Restore");
}
