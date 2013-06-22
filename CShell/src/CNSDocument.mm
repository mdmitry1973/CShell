//
//  CNSBox.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"

#import "CNSDocument.h"

@implementation CNSDocument


- (id)init 
{
	self = [super init];
	
	if (self)
	{
		m_doc = nil;
		m_frame = nil;
	}
	
    return self;
}

- (void)setDoc:(CDocument *)doc
{
	m_doc = doc;
}

- (void)setFrame:(CFrameWnd *)frame
{
	m_frame = frame;
}

- (CDocument *)getDoc
{
	return m_doc;
}

- (CFrameWnd *)getFrame
{
	return m_frame;
}

@end