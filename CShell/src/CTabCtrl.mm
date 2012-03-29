/*
 *  CTabCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CTabCtrl.h"

#import "CNSTabView.h"

@interface CNSTabViewItem : NSTabViewItem
{

}

@end

@implementation CNSTabViewItem

- (id)init 
{
	self = [super init];
	
    return self;
}

- (id)initWithIdentifier:(id)identifier
{
	self = [super initWithIdentifier:identifier];
	
    return self;
}

- (void)drawLabel:(BOOL)shouldTruncateLabel inRect:(NSRect)tabRect{
	
	/*
    std::map<int,CShellBitmapInfo> &bmp_map =  CWinApp::GetBitmapInfoMap();
	
	if (id_bitmap &&
		(it = bmp_map.find(id_bitmap)) != bmp_map.end())
	{
		NSBundle *resBundle = [NSBundle mainBundle];
		
		if (resBundle)
		{
			NSString *strFullFileName = [NSString stringWithUTF8String: it->second.name.c_str()];
			NSString *strFileName = [strFullFileName stringByReplacingOccurrencesOfString: [strFullFileName pathExtension] withString: @""];
			
			strFileName = [strFileName stringByReplacingOccurrencesOfString: @"." withString: @""];
			
			NSString *resFilePath = [resBundle pathForResource:strFileName ofType: [strFullFileName pathExtension]];
			
			NSImage *imageFromBundle = [[NSImage alloc] initWithContentsOfFile:resFilePath];
			
			if (imageFromBundle)
			{
				control = [[[CNSImageView alloc] initWithFrame: contentRect] autorelease];
				
				[(CNSImageView *)control setImage:imageFromBundle];
				[imageFromBundle release];
			}
			else 
			{
				assert(false);					
			}
		}
		else 
		{
			assert(false);					
		}
	}
	
	
	// do we have an image to draw
    NSImage *pImage = [pDelegate imageForCell];
	
    [[NSGraphicsContext currentContext] saveGraphicsState];
    NSAffineTransform* xform = [NSAffineTransform transform];
    [xform translateXBy:0.0 yBy: tabRect.size.height];
    [xform scaleXBy:1.0 yBy:-1.0];
    [xform concat]; 
	
	
    CGFloat x_Offset =0;
    if(pImage){
        [pImage drawInRect:NSMakeRect(tabRect.origin.x-8,-6,16, 16)fromRect:NSZeroRect
                 operation:NSCompositeSourceOver
                  fraction:1.0];
        x_Offset =  16;
    }
	[[NSGraphicsContext currentContext] restoreGraphicsState];
	
	*/
	
    [super drawLabel:shouldTruncateLabel inRect:tabRect];
}

@end

CTabCtrl::CTabCtrl() : CWnd()
{
	
}

BOOL CTabCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CreateEx(0, dwStyle, rect, pParentWnd, nID);
}

BOOL CTabCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	NSRect contentRect;
	
	contentRect.origin.x = rect.left;
	contentRect.origin.y = rect.top; 
	contentRect.size.width = rect.right - rect.left; 
	contentRect.size.height = rect.bottom - rect.top;
	
	CNSTabView *control = [[[CNSTabView alloc] initWithFrame: contentRect] autorelease];
	
	[control setTag:nID];
	
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

int CTabCtrl::GetCurFocus() const
{
	return [(CNSTabView *)m_hWnd indexOfTabViewItem: [(CNSTabView *)m_hWnd selectedTabViewItem]];
}

int CTabCtrl::GetCurSel() const
{
	return [(CNSTabView *)m_hWnd indexOfTabViewItem: [(CNSTabView *)m_hWnd selectedTabViewItem]];
}

int CTabCtrl::SetCurSel(int nItem)
{
	[(CNSTabView *)m_hWnd selectTabViewItemAtIndex: nItem];
	
	return GetCurFocus();
}

LONG CTabCtrl::InsertItem(int nItem, TCITEM* pTabCtrlItem)
{
	NSTabViewItem *tabItem = [[NSTabViewItem alloc] initWithIdentifier:nil];
	
	if (pTabCtrlItem &&
		pTabCtrlItem->pszText)
	{
		[tabItem setLabel: [NSString stringWithUTF8String: pTabCtrlItem->pszText]];
	}
	
	[(CNSTabView *)m_hWnd addTabViewItem: tabItem];
	
	return nItem;
}

LONG CTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem)
{
	NSTabViewItem *tabItem = [[NSTabViewItem alloc] initWithIdentifier:nil];
	
	if (lpszItem)
	{
		[tabItem setLabel: [NSString stringWithUTF8String: lpszItem]];
	}
									
	[(CNSTabView *)m_hWnd addTabViewItem: tabItem];
	
	return nItem;
}

LONG CTabCtrl::InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
{
	CNSTabViewItem *tabItem = [[CNSTabViewItem alloc] initWithIdentifier:nil];
	
	if (lpszItem)
	{
		[tabItem setLabel: [NSString stringWithUTF8String: lpszItem]];
	}
	
	[(CNSTabView *)m_hWnd addTabViewItem: tabItem];
	
	return nItem;
}

LONG CTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam)
{
	CNSTabViewItem *tabItem = [[CNSTabViewItem alloc] initWithIdentifier:nil];
	
	if (lpszItem)
	{
		[tabItem setLabel: [NSString stringWithUTF8String: lpszItem]];
	}
	
	[(CNSTabView *)m_hWnd addTabViewItem: tabItem];
	
	return nItem;
}

LONG CTabCtrl::InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, int nImage, LPARAM lParam, DWORD dwState, DWORD dwStateMask)
{
	CNSTabViewItem *tabItem = [[CNSTabViewItem alloc] initWithIdentifier:nil];
	
	if (lpszItem)
	{
		[tabItem setLabel: [NSString stringWithUTF8String: lpszItem]];
	}
	
	[(CNSTabView *)m_hWnd addTabViewItem: tabItem];
	
	return nItem;
}

BOOL CTabCtrl::GetItemRect(int nItem, LPRECT lpRect) const
{
	NSArray *arrViewers = [(CNSTabView *)m_hWnd subviews];
	
	if ([arrViewers count] > nItem)
	{
		NSRect frameRect;
		NSView *view = [arrViewers objectAtIndex: nItem];
		
		frameRect.origin.x = lpRect->left;
		frameRect.origin.y = lpRect->top;
		frameRect.size.width = lpRect->right - lpRect->left;
		frameRect.size.height = lpRect->bottom - lpRect->top;
		
		[view setFrame:frameRect];
	}
	else 
	{
		assert(FALSE);
		return FALSE;
	}
	
	return TRUE;
}

BOOL CTabCtrl::DeleteItem(int nItem)
{
	[(CNSTabView *)m_hWnd removeTabViewItem: [(CNSTabView *)m_hWnd tabViewItemAtIndex: nItem]];
	
	return TRUE;
}

void CTabCtrl::AdjustRect(BOOL bLarger, LPRECT lpRect)
{
	NSLog(@"TO DO CTabCtrl::AdjustRect");
}

