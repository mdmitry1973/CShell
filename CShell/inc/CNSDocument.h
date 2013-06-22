//
//  CNSDocument.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#include "CDocument.h"
#include "CFrameWnd.h"

@interface CNSDocument : NSDocument
{
	CDocument	*m_doc;
	CFrameWnd	*m_frame;
}

- (void)setDoc:(CDocument *)doc;
- (void)setFrame:(CFrameWnd *)frame;

- (CDocument *)getDoc;
- (CFrameWnd *)getFrame;

@end
