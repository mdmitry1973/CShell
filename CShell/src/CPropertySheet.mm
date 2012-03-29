/*
 *  CPropertySheet.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/26/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */
 
#include "CPropertyPage.h"
#include "CTabCtrl.h"

#include "CPropertySheet.h"

#import "CNSTabView.h"
#import "CNSWindow.h"

#import "CNSWindowHandle.h"
#import "CNSWindowDelegate.h"
#import "CNSTextFieldDelegate.h"
#import "CNSControlDelegate.h"
#import "CNSWindowController.h"
#import "CNSTabViewDelegate.h"

/*
@interface CNSPropertySheetDelegate : NSTabView<NSTabViewDelegate>//NSObject
{
	CPropertySheet *mWindow;
}

-(void)setCWnd:(CPropertySheet *)window;

@end

@implementation CNSPropertySheetDelegate

- (id)init 
{
	mWindow = nil;
	
    return [super init];
}

-(void)setCWnd:(CPropertySheet *)window
{
	mWindow = window;//EVENT_TYPE_COMMAND_RANGE
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
		NSInteger index = [tabView indexOfTabViewItem:tabViewItem];
		
		if (mWindow)
		{
			CPropertyPage *page = mWindow->GetPage(index);
		
			if (page)
			{
				if (!mWindow->SendEventHandle(page->GetDlgCtrlID(), tabView, EVENT_TYPE_COMMAND_RANGE))
				{
					mWindow->SetActivePage(index);
				}
			}
		}
		
		mWindow->SendEventHandle([tabView tag], tabView, TCN_SELCHANGE);
	}
}

@end

*/

CPropertySheet::CPropertySheet() : CWnd()
{
	mParentWin = 0;
	m_hTab = 0;
	mISelectPage = 0;
	mPropertySheetDelegate = nil;
}

CPropertySheet::CPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage) : CWnd()
{
	mCaptionStr.LoadString(nIDCaption);
	mParentWin = pParentWnd;
	mISelectPage = iSelectPage;
	m_hTab = 0;
	mPropertySheetDelegate = nil;
}

CPropertySheet::CPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage) : CWnd()
{
	mCaptionStr = pszCaption;
	mParentWin = pParentWnd;
	mISelectPage = iSelectPage;
	m_hTab = 0;
	mPropertySheetDelegate = nil;
}

CPropertySheet::CPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark, HBITMAP hbmHeader) : CWnd()
{
	mCaptionStr.LoadString(nIDCaption);
	mParentWin = pParentWnd;
	mISelectPage = iSelectPage;
	mHbmWatermark = hbmWatermark; 
	mHpalWatermark = hpalWatermark;
	mHbmHeader = hbmHeader;
	m_hTab = 0;
	mPropertySheetDelegate = nil;
}

CPropertySheet::CPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage, HBITMAP hbmWatermark, HPALETTE hpalWatermark, HBITMAP hbmHeader) : CWnd()
{
	mCaptionStr = pszCaption;
	mParentWin = pParentWnd;
	mISelectPage = iSelectPage;
	mHbmWatermark = hbmWatermark;
	mHpalWatermark = hpalWatermark;
	mHbmHeader = hbmHeader;
	m_hTab = 0;
	mPropertySheetDelegate = nil;
} 

CPropertySheet::~CPropertySheet()
{
	if (mPropertySheetDelegate)
	{
		[(CNSTabViewDelegate *)mPropertySheetDelegate dealloc];
	}
}

BOOL CPropertySheet::Create(CWnd* pParentWnd, DWORD dwStyly, DWORD dwExStyle)
{	
	NSRect boundsRect = NSMakeRect(0, 0, 0, 0);
	BOOL res = FALSE;
	NSUInteger windowStyle = NSBorderlessWindowMask;
	NSBackingStoreType bufferingType = NSBackingStoreBuffered;						
	
	windowStyle = windowStyle | NSTitledWindowMask;
	
	for(int i = 0; i < m_arrPages.size(); i++)
	{
		RECT	rect;
		NSRect	bRect;
		
		m_arrPages[i]->GetClientRect(&rect);
		
		bRect.origin.x = rect.left;
		bRect.origin.y = rect.top;
		bRect.size.width = rect.right - rect.left;
		bRect.size.height = rect.bottom - rect.top;
		
		boundsRect = NSUnionRect(boundsRect, bRect);
	}
	
	m_hWnd = [[CNSWindow alloc] initWithContentRect:boundsRect styleMask:windowStyle backing:bufferingType defer:YES];
	m_hTab = [[[NSTabView alloc] initWithFrame: boundsRect] autorelease];
	[(CNSWindow *)m_hWnd setContentView: (CNSTabView *)m_hTab];
	[(CNSWindow *)m_hWnd setParentWnd:pParentWnd];
	[(CNSWindow *)m_hWnd setWnd:this];
	[(CNSWindow *)m_hWnd setStyleMask:windowStyle];
	
	[(CNSWindow *)m_hWnd setTitle: [NSString stringWithUTF8String: mCaptionStr.c_str()]];
	mWindowDelegate = [[CNSWindowDelegate alloc] init];
	[(CNSWindowDelegate *)mWindowDelegate setCWnd: this];
	[(CNSWindow *)m_hWnd setDelegate: (CNSWindowDelegate *)mWindowDelegate];
	mWindowHandle = [[CNSWindowHandle alloc] init];
	[(CNSWindowHandle *)mWindowHandle setCWnd: this];
	mWindowController = [[NSWindowController alloc] initWithWindow: (NSWindow *)m_hWnd];
	
	mPropertySheetDelegate = [[CNSTabViewDelegate alloc] init];
	[(NSTabView *)m_hTab setDelegate: (CNSTabViewDelegate *)mPropertySheetDelegate];
	[(CNSTabViewDelegate *)mPropertySheetDelegate setCWnd: this];
			  
	mMainWindow = TRUE;
	res = TRUE;
	
	for(int i = 0; i < m_arrPages.size(); i++)
	{
		NSTabViewItem *tabViewItem = [[NSTabViewItem alloc] initWithIdentifier: nil];	
		CString str;
		
		m_arrPages[i]->GetWindowText(str);
		
		[tabViewItem setLabel: [NSString stringWithUTF8String: str.c_str()]];
		[tabViewItem setView: (NSView *)(m_arrPages[i]->GetNSWindow())];
		//[(CNSTabView *)m_hTab addSubview: (NSView *)(m_arrPages[i]->GetNSWindow())];
		[(NSTabView *)m_hTab addTabViewItem: tabViewItem];
	}
	
	return res;
}

INT_PTR CPropertySheet::DoModal()
{
	NSInteger endCode = 0;
	
	if (Create(mParentWin) && mWindowController)
	{
		FinaleSetup();
		
		NSModalSession session = [NSApp beginModalSessionForWindow:[(NSWindowController *)mWindowController window]];
		
		for (;;) 
		{
			if ([NSApp runModalSession:session] != NSRunContinuesResponse)
			{
				break;
			}			
		}
		
		[NSApp endModalSession:session];
	}
	else 
	{
		assert(false);
	}
	
	return endCode;
}

BOOL CPropertySheet::OnInitDialog()
{
	NSLog(@"TO DO CPropertySheet::OnInitDialog");
	return FALSE;
}

void CPropertySheet::AddPage(CPropertyPage *pPage)
{
	m_arrPages.push_back(pPage);
}

BOOL CPropertySheet::SetActivePage(int nPage)
{
	for(int i = 0; i < m_arrPages.size(); i++)
	{
		if (i == nPage)
		{
			m_arrPages[i]->ShowWindow(SW_SHOW);
		}
		else 
		{
			m_arrPages[i]->ShowWindow(SW_HIDE);			
		}
	}
	
	return TRUE;
}

BOOL CPropertySheet::SetActivePage(CPropertyPage* pPage)
{
	for(int i = 0; i < m_arrPages.size(); i++)
	{
		if (m_arrPages[i] == pPage)
		{
			m_arrPages[i]->ShowWindow(SW_SHOW);
		}
		else 
		{
			m_arrPages[i]->ShowWindow(SW_HIDE);			
		}
	}
	
	return TRUE;
}

void CPropertySheet::RemovePage(CPropertyPage *pPage)
{
	NSLog(@"TO DO CPropertySheet::RemovePage");
}

void CPropertySheet::RemovePage(int nPage )
{
	NSLog(@"TO DO CPropertySheet::RemovePage");
}

int CPropertySheet::GetPageCount() const
{
	return m_arrPages.size();
}

CPropertyPage* CPropertySheet::GetPage(int nPage) const
{
	return m_arrPages[nPage];
}

CPropertyPage* CPropertySheet::GetActivePage() const
{
	NSLog(@"TO DO CPropertySheet::GetActivePage");
	return NULL;
}

int CPropertySheet::GetActiveIndex() const
{
	NSLog(@"TO DO CPropertySheet::GetActiveIndex");
	return 0;
}

int CPropertySheet::GetPageIndex(CPropertyPage* pPage)
{
	NSLog(@"TO DO CPropertySheet::GetPageIndex");
	return 0;
}

CTabCtrl* CPropertySheet::GetTabControl() const
{
	NSLog(@"TO DO CPropertySheet::GetTabControl");
	return NULL;
}

void CPropertySheet::SetWizardButtons(DWORD dwFlags)
{
	NSLog(@"TO DO CPropertySheet::SetWizardButtons");
}

void CPropertySheet::SetFinishText(LPCTSTR lpszText)
{
	NSLog(@"TO DO CPropertySheet::SetFinishText");
}

void CPropertySheet::SetTitle(LPCTSTR lpszText, UINT nStyle)
{
	NSLog(@"TO DO CPropertySheet::SetTitle");
}

void CPropertySheet::SetWizardMode()
{
	NSLog(@"TO DO CPropertySheet::SetWizardMode");
}

BOOL CPropertySheet::IsDialog()
{
	return true;
}



