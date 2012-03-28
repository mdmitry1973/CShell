//
//  CNSTabViewDelegate.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 CShell. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSTabViewDelegate : NSTabView<NSTabViewDelegate>
{
	CWnd *mWindow;
}

-(void)setCWnd:(CWnd *)window;

@end

