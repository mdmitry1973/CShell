/*
 *  CWnd.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CWinApp.h"
#include "CMenu.h"
#include "CWnd.h"

#import "CNSView.h"
#import "CNSButton.h"
#import "CNSProgressIndicator.h"
#import "CNSBox.h"
#import "CNSPopUpButton.h"
#import "CNSImageView.h"
#import "CNSSlider.h"
#import "CNSStepper.h"
#import "CNSTableView.h"
#import "CNSTextField.h"
#import "CNSTabView.h"
#import "CNSWindow.h"

#import "CNSWindowHandle.h"
#import "CNSWindowDelegate.h"
#import "CNSTextFieldDelegate.h"
#import "CNSControlDelegate.h"
#import "CNSWindowController.h"
#import "CNSTabViewDelegate.h"

CWnd CWnd::wndBottom;
CWnd CWnd::wndTop;
CWnd CWnd::wndTopMost;
CWnd CWnd::wndNoTopMost;

IMPLEMENT_DYNAMIC(CWnd, CCmdTarget)

CWnd::CWnd()
{
	mWindowController = nil;
	m_hWnd = nil;
	mWindowDelegate = nil;
	mWindowHandle = nil;
	
	mParentWin = nil;
	mMainWindow = false;
	
	mFinished = false;
}

CWnd::~CWnd()
{
	KillTimer(-1);
	
	if (m_hWnd && mMainWindow)
	{
		[(NSWindow *)m_hWnd dealloc];
	}
	
	if (mWindowController)
	{
		[(NSWindowController *)mWindowController dealloc];
	}
	
	if (mWindowDelegate)
	{
		[(CNSWindowDelegate *)mWindowDelegate dealloc];
	}
	
	if (mWindowHandle)
	{
		[(CNSWindowHandle *)mWindowHandle dealloc];
	}
	
	if (mMainWindow)
	{
		//std::map<int,CWnd*>::iterator it;
		
		//for(it = m_arrTempControls.begin(); it != m_arrTempControls.end(); it++)
		//{
		//	delete it->second;
		//}
		
		//m_arrTempControls.clear();
	}
	
	std::map<int, CWnd *>::iterator it;
	
	for(it = mMapControls.begin(); it != mMapControls.end(); it++)
	{
		delete it->second;
	}
}

BOOL CWnd::Create(LPCTSTR lpszClassName, 
					LPCTSTR lpszWindowName,
					DWORD dwStyle,
					const RECT& rect,
					CWnd* pParentWnd,
					UINT nID,
					CCreateContext* pContext
					)
{
	NSLog(@"TO DO CWnd::Create");
	return TRUE;
}

void CWnd::DoDataExchange(CDataExchange* pDX)
{
	
}

BOOL CWnd::CreatFromResFile(UINT nIDTemplate, BOOL bView, CWnd *window)
{
	BOOL res = false;
	
	NSString *str = [NSString stringWithFormat: @"%d", nIDTemplate];
	
	res = CreatFromResFile([str UTF8String], bView, window);
	
	return res;
}

BOOL CWnd::CreatFromResFile(LPCTSTR lpszTemplateName, BOOL bView, CWnd *window)
{
	BOOL res = false;
	NSBundle *resBundle = [NSBundle mainBundle];
	
	if (resBundle)
	{
		NSString *resFilePath = [resBundle pathForResource: @"Resources" ofType:@"xml"];
		
		if (resFilePath)
		{
			NSError *error = nil;
			NSXMLDocument *doc = [[NSXMLDocument alloc] initWithData:[NSData dataWithContentsOfFile: resFilePath] options:NSXMLNodeOptionsNone error:&error];
			
			if (doc)
			{
				//NSLog(@"doc=%s",  [[[NSString alloc] initWithData:[doc XMLData] encoding:NSUTF8StringEncoding] UTF8String]);
				
				//<MFC_RESOURCE>
				//<DIALOGEX>
				//<ID>
				//NSString *xpath = [NSString stringWithFormat: @"/MFC_RESOURCE/*/ID[. = \"%s\"] | /MFC_RESOURCE/*/IDSTR[. = \"%s\"]", 
				//														lpszTemplateName, lpszTemplateName];
				NSString *xpath = [NSString stringWithFormat: @"/MFC_RESOURCE/*/ID[text()='%s'] | /MFC_RESOURCE/*/IDSTR[text()='%s']", 
								   lpszTemplateName, lpszTemplateName];
				NSArray *arrWindowsNode = [doc nodesForXPath:xpath error:&error];
				
				//NSLog(@"arrWindowsNode count=%d", [arrWindowsNode count] );
				
				if ([arrWindowsNode count] == 1)
				{
					//<CAPTION>About SimpleDialog2</CAPTION>
					//<STYLE>DS_SETFONT | DS_MODALFRAME | DS_FIXEDSYS | WS_POPUP | WS_CAPTION | WS_SYSMENU</STYLE>
					//<BOX>0, 0, 170, 62</BOX>
					//<ID>100</ID>
					
					NSXMLNode *idNode = [arrWindowsNode objectAtIndex:0];	
					NSXMLNode *windowNode = [idNode parent];
					
					NSString *xpathCAPTION = [NSString stringWithFormat: @"../CAPTION", lpszTemplateName, lpszTemplateName];
					NSString *xpathSTYLE = [NSString stringWithFormat: @"../STYLE", lpszTemplateName, lpszTemplateName];
					NSString *xpathBOX = [NSString stringWithFormat: @"../BOX", lpszTemplateName, lpszTemplateName];
					NSString *xpathID = [NSString stringWithFormat: @"../ID", lpszTemplateName, lpszTemplateName];
					
					NSArray	*arrNode = nil;
					
					NSXMLNode *captionNode = nil;
					NSXMLNode *stypeNode = nil;
					NSXMLNode *boxNode = nil;
					NSXMLNode *IdNode = nil;
										
					arrNode = [idNode nodesForXPath:xpathCAPTION error:&error];
					if ([arrNode count] == 1) captionNode = [arrNode objectAtIndex:0];
					
					arrNode = [idNode nodesForXPath:xpathSTYLE error:&error];
					if ([arrNode count] == 1) stypeNode = [arrNode objectAtIndex:0];
					
					arrNode = [idNode nodesForXPath:xpathBOX error:&error];
					if ([arrNode count] == 1) boxNode = [arrNode objectAtIndex:0];
					
					arrNode = [idNode nodesForXPath:xpathID error:&error];
					if ([arrNode count] == 1) IdNode = [arrNode objectAtIndex:0];
					
					if (boxNode)
					{
						int windowHeight = 0;
						NSRect contentRect;
						NSString *strBox = [boxNode stringValue];
						NSString *strID = (IdNode == 0 ? nil : [IdNode stringValue]);						
						NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
						
						contentRect.origin.x = 0;
						contentRect.origin.y = 0; 
						contentRect.size.width = 100; 
						contentRect.size.height = 100;
					
						if ([arrStrings count] >=  1)
							contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
						if ([arrStrings count] >=  2)
							contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
						if ([arrStrings count] >=  3)
							contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
						if ([arrStrings count] ==  4)
							contentRect.size.height = [[arrStrings objectAtIndex:3] intValue];
						
						windowHeight = contentRect.size.height;
						//contentRect.origin.y = contentRect.size.height; 
						
						/*
						 NSClosableWindowMask = 1 << 1,
						 NSMiniaturizableWindowMask = 1 << 2,
						 NSResizableWindowMask = 1 << 3,
						 NSTexturedBackgroundWindowMask s
						 */
						
						NSUInteger windowStyle = NSBorderlessWindowMask;						
						
						if (stypeNode)
						{
							NSString *strStyle = [stypeNode stringValue];
							
							if (strStyle && [strStyle rangeOfString: @"WS_CAPTION"].location != NSNotFound)
							{
								windowStyle = windowStyle | NSTitledWindowMask;
							}
						}
						
						/*
						 NSBackingStoreRetained     = 0,
						 NSBackingStoreNonretained  = 1,
						 NSBackingStoreBuffered     = 2
						 */
						
						NSBackingStoreType bufferingType = NSBackingStoreBuffered;
						NSString *strCaption = nil;
						
						if (captionNode)
						{
							strCaption = [captionNode stringValue];	
						}
										
						if (bView)
						{
							int idTab = 0;
							
							if (strID)
							{
								idTab = [strID intValue];								
							}
														
							m_hWnd = [[CNSView alloc] initWithFrame: contentRect];
																					
							[(CNSView *)m_hWnd setTag: idTab];	
							[(CNSView *)m_hWnd setParentWnd:window];		
							
							if (window)	
							{							
								[(NSView *)(window->GetNSWindow()) addSubview: (NSView *)m_hWnd];
							}							
						}
						else
						{
							m_hWnd = [[CNSWindow alloc] initWithContentRect:contentRect styleMask:windowStyle backing:bufferingType defer:YES];
							[(CNSWindow *)m_hWnd setContentView: [[[CNSView alloc] initWithFrame: contentRect] autorelease]];
							mMainWindow = TRUE;
							[(CNSWindow *)m_hWnd setParentWnd:nil];
						}	
						
						[(NSObject *)m_hWnd setWnd:this];
																		
						if (!bView)
						{
													
							[(NSWindow *)m_hWnd setTitle: strCaption];
							
							mWindowDelegate = [[CNSWindowDelegate alloc] init];
							[(CNSWindowDelegate *)mWindowDelegate setCWnd: this];
							[(NSWindow *)m_hWnd setDelegate: (CNSWindowDelegate *)mWindowDelegate];
							
							mWindowHandle = [[CNSWindowHandle alloc] init];
							[(CNSWindowHandle *)mWindowHandle setCWnd: this];
							
							mWindowController = [[NSWindowController alloc] initWithWindow: (NSWindow *)m_hWnd];
							
							if (!mWindowController)
							{
								assert(false);
							}	
						}
						else 
						{
							if (strCaption)
							{
								mCaptionStr = [strCaption UTF8String];
							}
						}
												
						res = TRUE;
						
						CNSView *nsView = nil;
						
						if (window)
						{
							nsView = (CNSView *)m_hWnd;
						}
						else 
						{
							if (bView)
							{
								nsView = (CNSView *)m_hWnd;
							}
							else 
							{
								nsView = [(NSWindow *)m_hWnd contentView];
							}							
						}
												
						for (int i = 0; i < [windowNode childCount]; i++)
						{
							NSXMLElement *controlNode = (NSXMLElement *)[windowNode childAtIndex:i];
							
							if (controlNode)
							{
								if ([[controlNode name] compare:@"BUTTON" options:NSCaseInsensitiveSearch] == NSOrderedSame ||
									[[controlNode name] compare:@"PUSHBUTTON" options:NSCaseInsensitiveSearch] == NSOrderedSame ||
									[[controlNode name] compare:@"DEFPUSHBUTTON" options:NSCaseInsensitiveSearch] == NSOrderedSame)
								{
									CreateButton(controlNode, nsView);									
								}
								else 
								if ([[controlNode name] compare:@"CTEXT" options:NSCaseInsensitiveSearch] == NSOrderedSame ||
									[[controlNode name] compare:@"LTEXT" options:NSCaseInsensitiveSearch] == NSOrderedSame)
								{
									CreateStaticText(controlNode, nsView);									
								}								
								else 
								if ([[controlNode name] compare:@"CONTROL" options:NSCaseInsensitiveSearch] == NSOrderedSame)
								{
									CreateControl(controlNode, nsView);									
								}							
								else 
								if ([[controlNode name] compare:@"GROUPBOX" options:NSCaseInsensitiveSearch] == NSOrderedSame)
								{
									CreateGroupBox(controlNode, nsView);									
								}						
								else 
								if ([[controlNode name] compare:@"COMBOBOX" options:NSCaseInsensitiveSearch] == NSOrderedSame)
								{
									CreateComboBox(controlNode, nsView);									
								}
								else 
								if ([[controlNode name] compare:@"EDITTEXT" options:NSCaseInsensitiveSearch] == NSOrderedSame)
								{
									CreateEditText(controlNode, nsView);									
								}
								else 
								if ([[controlNode name] compare:@"LISTBOX" options:NSCaseInsensitiveSearch] == NSOrderedSame)
								{
									CreateListBox(controlNode, nsView);									
								}
							}
						}
					}
				}
				else 
				{
					assert(false);
				}
				
				[doc dealloc];
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
	else 
	{
		assert(false);
	}
	
	return res;	
}

bool CWnd::CreateButton(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <ID></ID>
		 <IDSTR>IDOK</IDSTR>
		 <TEXT>OK</TEXT>
		 <BOX>113,41,50,14</BOX>
		 <STYLE>WS_GROUP</STYLE>
		 <DEFPUSHBUTTON/>									 
		 */
		
		NSXMLElement *controlNode = (NSXMLElement *)controlNodeIn;
		int windowHeight = 0;
		NSRect contentRect = [(NSWindow *)m_hWnd frame];
		NSString *strTitle = nil;
		NSString *strID = nil;
		NSString *strIDSTR = nil;
		NSArray *arrControlProperty = [controlNode elementsForName:@"IDSTR"];
		
		windowHeight = contentRect.size.height;
		
		if ([arrControlProperty count])
		{
			strIDSTR = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"TEXT"];
		
		if ([arrControlProperty count])
		{
			strTitle = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"ID"];
		
		if ([arrControlProperty count])
		{
			strID = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"BOX"];
		
		contentRect.origin.x = 0;
		contentRect.origin.y = 0; 
		contentRect.size.width = 100; 
		contentRect.size.height = 100;
		
		if ([arrControlProperty count])
		{
			NSString *strBox = [[arrControlProperty objectAtIndex:0] stringValue];						
			NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
			
			if ([arrStrings count] >=  1)
				contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
			if ([arrStrings count] >=  2)
				contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
			if ([arrStrings count] >=  3)
				contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
			if ([arrStrings count] ==  4)
				contentRect.size.height = [[arrStrings objectAtIndex:3] intValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"STYLE"];
		arrControlProperty = [controlNode elementsForName:@"DEFPUSHBUTTON"];
		
		CNSButton *button = [[[CNSButton alloc] initWithFrame: contentRect] autorelease];
		
		assert(button);
		
		if (strID)
		{										
			[button setTag:[strID intValue]];
		}
		else 
		if (strIDSTR)
		{
			if ([strIDSTR compare:@"IDOK"] == NSOrderedSame)
			{
				[button setTag:IDOK];
			}
			else 
			if ([strIDSTR compare:@"IDCANCEL"] == NSOrderedSame)
			{
				[button setTag:IDCANCEL];
			}
			else
			{
				NSLog(@"Cannot set id for %@", strIDSTR);
			}			
		}
		
		if (strTitle)
		{
			[button setTitle: strTitle];
		}
		
		[button setBezelStyle: NSRoundedBezelStyle];
		
		[(CNSView *)nsView addSubview: button];
		
		[button setParentWnd:this];
	}
	
	return res;
}

bool CWnd::CreateStaticText(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <CTEXT>           
		 <IDSTR>IDC_STATIC</IDSTR>
		 <TEXT>Place dialog controls here.</TEXT>
		 <BOX>10,96,300,8</BOX>
		 </CTEXT> 									 
		 */
		
		NSXMLElement *controlNode = (NSXMLElement *)controlNodeIn;
		//int windowHeight = 0;
		NSRect contentRect = [(NSWindow *)m_hWnd frame];
		NSString *strTitle = nil;
		NSString *strID = nil;
		NSString *strIDSTR = nil;
		NSArray *arrControlProperty = [controlNode elementsForName:@"IDSTR"];
		
		//windowHeight = contentRect.size.height;
		
		if ([arrControlProperty count])
		{
			strIDSTR = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"TEXT"];
		
		if ([arrControlProperty count])
		{
			strTitle = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"ID"];
		
		if ([arrControlProperty count])
		{
			strID = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"BOX"];
		
		contentRect.origin.x = 0;
		contentRect.origin.y = 0; 
		contentRect.size.width = 100; 
		contentRect.size.height = 100;
		
		if ([arrControlProperty count])
		{
			NSString *strBox = [[arrControlProperty objectAtIndex:0] stringValue];						
			NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
			
			if ([arrStrings count] >=  1)
				contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
			if ([arrStrings count] >=  2)
				contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
			if ([arrStrings count] >=  3)
				contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
			if ([arrStrings count] ==  4)
				contentRect.size.height = [[arrStrings objectAtIndex:3] intValue] + 10;
		}
		
		//contentRect.origin.y  = (windowHeight - contentRect.origin.y);
		
		arrControlProperty = [controlNode elementsForName:@"STYLE"];
		arrControlProperty = [controlNode elementsForName:@"DEFPUSHBUTTON"];
		
		CNSTextField *staticText = [[[CNSTextField alloc] initWithFrame: contentRect] autorelease];
		
		[staticText setBezeled:NO];
		[staticText setDrawsBackground:NO];
		[staticText setEditable:NO];
		[staticText setSelectable:NO];
		
		if ([[controlNode name] compare:@"CTEXT" options:NSCaseInsensitiveSearch] == NSOrderedSame)
		{
			[staticText setAlignment:NSCenterTextAlignment];
		}
		else 
		if ([[controlNode name] compare:@"LTEXT" options:NSCaseInsensitiveSearch] == NSOrderedSame)
		{
			[staticText setAlignment:NSLeftTextAlignment];
		}
		else 
		{
			
		}
		
		//NSFont *font = [NSFont fontWithName:@"Microsoft Sans Serif" size:10];
		//[staticText setFont:font];

		if (strID)
		{										
			[staticText setTag:[strID intValue]];
		}
		else 
			if (strIDSTR)
			{
				
			}
		
		if (strTitle)
		{
			[staticText setStringValue: strTitle];
		}
		
		[(CNSView *)nsView addSubview: staticText];
		
		[staticText setParentWnd:this];		
	}
	
	return res;
}

bool CWnd::CreateComboBox(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <COMBOBOX>
		 <ID>1002</ID>
		 <IDSTR>IDC_COMBO1</IDSTR>
		 <BOX>113,23,118,72</BOX>
		 <STYLE>CBS_DROPDOWNLIST | CBS_SORT | WS_VSCROLL | WS_TABSTOP</STYLE>
		 </COMBOBOX>								 
		 */
		
		NSXMLElement *controlNode = (NSXMLElement *)controlNodeIn;
		//int windowHeight = 0;
		NSRect contentRect = [(NSWindow *)m_hWnd frame];
		NSString *strTitle = nil;
		NSString *strID = nil;
		NSString *strIDSTR = nil;
		NSArray *arrControlProperty = [controlNode elementsForName:@"IDSTR"];
		
		//windowHeight = contentRect.size.height;
		
		if ([arrControlProperty count])
		{
			strIDSTR = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"TEXT"];
		
		if ([arrControlProperty count])
		{
			strTitle = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"ID"];
		
		if ([arrControlProperty count])
		{
			strID = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"BOX"];
		
		contentRect.origin.x = 0;
		contentRect.origin.y = 0; 
		contentRect.size.width = 100; 
		contentRect.size.height = 100;
		
		if ([arrControlProperty count])
		{
			NSString *strBox = [[arrControlProperty objectAtIndex:0] stringValue];						
			NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
			
			if ([arrStrings count] >=  1)
				contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
			if ([arrStrings count] >=  2)
				contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
			if ([arrStrings count] >=  3)
				contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
			if ([arrStrings count] ==  4)
				contentRect.size.height = [[arrStrings objectAtIndex:3] intValue] + 10;
		}
		
		//contentRect.origin.y  = (windowHeight - contentRect.origin.y);
		
		arrControlProperty = [controlNode elementsForName:@"STYLE"];
		arrControlProperty = [controlNode elementsForName:@"DEFPUSHBUTTON"];
		
		CNSPopUpButton *comboBox = [[[CNSPopUpButton alloc] initWithFrame: contentRect pullsDown: NO] autorelease];
		
		//[staticText setBezeled:NO];
		//[staticText setDrawsBackground:NO];
		//[staticText setEditable:NO];
		//[staticText setSelectable:NO];
		
		if (strID)
		{										
			[comboBox setTag:[strID intValue]];
		}
		else 
		if (strIDSTR)
		{
			
		}
		
		//if (strTitle)
		//{
		//	[comboBox setStringValue: strTitle];
		//}
		
		[(CNSView *)nsView addSubview: comboBox];	
		
		[comboBox setParentWnd:this];	
	}
	
	return res;
}

bool CWnd::CreateControl(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <CONTROL>
		 <ID>1001</ID>
		 <IDSTR>IDC_CHECK1</IDSTR>
		 <TEXT>Test</TEXT>
		 <BOX>33,23,30,10</BOX>
		 <CLASS>Button</CLASS>
		 <STYLE>BS_AUTOCHECKBOX | WS_TABSTOP</STYLE>
		 </CONTROL>									 
		 */
		
		NSXMLElement *controlNode = (NSXMLElement *)controlNodeIn;
		//int windowHeight = 0;
		NSRect contentRect = [(NSWindow *)m_hWnd frame];
		NSString *strTitle = nil;
		NSString *strID = nil;
		NSString *strIDSTR = nil;
		NSString *strStyle = nil;
		NSString *strClass = nil;
		NSArray *arrControlProperty = [controlNode elementsForName:@"IDSTR"];
		
		//windowHeight = contentRect.size.height;
		
		if ([arrControlProperty count])
		{
			strIDSTR = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"TEXT"];
		
		if ([arrControlProperty count])
		{
			strTitle = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"ID"];
		
		if ([arrControlProperty count])
		{
			strID = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"CLASS"];
		
		if ([arrControlProperty count])
		{
			strClass = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"BOX"];
		
		contentRect.origin.x = 0;
		contentRect.origin.y = 0; 
		contentRect.size.width = 100; 
		contentRect.size.height = 100;
		
		if ([arrControlProperty count])
		{
			NSString *strBox = [[arrControlProperty objectAtIndex:0] stringValue];						
			NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
			
			if ([arrStrings count] >=  1)
				contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
			if ([arrStrings count] >=  2)
				contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
			if ([arrStrings count] >=  3)
				contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
			if ([arrStrings count] ==  4)
				contentRect.size.height = [[arrStrings objectAtIndex:3] intValue] + 10;
		}
	
		arrControlProperty = [controlNode elementsForName:@"STYLE"];
		
		if ([arrControlProperty count])
		{
			strStyle = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"DEFPUSHBUTTON"];
		
		NSControl *control = nil;
		
		if (strClass &&
			[strClass rangeOfString:@"msctls_trackbar32" options: NSCaseInsensitiveSearch].location != NSNotFound)
		{
			control = [[[CNSSlider alloc] initWithFrame: contentRect] autorelease];
			
			if (strTitle)
			{
				[control setStringValue: strTitle];				
			}
			
			//SEL eventHandle = @selector(controlEventHandle:);
			
			//[control setTarget:control];
			//[control setAction:eventHandle];
			
			PtrNSWindowHandle	pWindowHandle = mWindowHandle;
			SEL eventHandle = @selector(controlEventHandle:);
			
			if (pWindowHandle)
			{
				[control setTarget:(CNSWindowHandle *)pWindowHandle];
				[control setAction:eventHandle];
			}
		}
		else 
		if (strClass &&
			[strClass rangeOfString:@"SysTabControl32" options: NSCaseInsensitiveSearch].location != NSNotFound)
		{
			//CNSTabView
			// CONTROL         "",IDC_TAB1,"SysTabControl32",WS_TABSTOP,7,7,256,153
			//control = [[[CNSSlider alloc] initWithFrame: contentRect] autorelease];
			
			//if (strTitle)
			//{
			//	[control setStringValue: strTitle];
			//}
			
			control = [[[CNSTabView alloc] initWithFrame: contentRect] autorelease];
			
			//if (strTitle)
			//{
			//	[control setStringValue: strTitle];
			//}
		}
		else 
		if (strClass &&
			[strClass rangeOfString:@"msctls_updown32" options: NSCaseInsensitiveSearch].location != NSNotFound)
		{
			control = [[[CNSStepper alloc] initWithFrame: contentRect] autorelease];
		}
		else 
		if (strClass &&
			[strClass rangeOfString:@"msctls_progress32" options: NSCaseInsensitiveSearch].location != NSNotFound)
		{
			control = [[[CNSProgressIndicator alloc] initWithFrame: contentRect] autorelease];
			
			[(NSProgressIndicator *)control setIndeterminate: false];
		}
		else 
		if (strClass &&
			[strClass rangeOfString:@"Static" options: NSCaseInsensitiveSearch].location != NSNotFound &&
			[strStyle rangeOfString: @"SS_BITMAP" options: NSCaseInsensitiveSearch].location != NSNotFound)
		{	
			std::map<int,CShellBitmapInfo>::iterator it;
			int id_bitmap = [strTitle intValue];
			
			CWinApp::LoadBitmapInfo();
			
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
		}
		else 
		{					
			//radio
			if ([strStyle rangeOfString: @"BS_AUTORADIOBUTTON" options: NSCaseInsensitiveSearch].location != NSNotFound)
			{
				control = [[[CNSButton alloc] initWithFrame: contentRect] autorelease];
				[(CNSButton *)control setCButtonType:NSRadioButton];
				
				if (strTitle)
				{
					[control setStringValue: strTitle];
				}
				
				//WS_GROUP
				if ([strStyle rangeOfString: @"WS_GROUP" options: NSCaseInsensitiveSearch].location != NSNotFound)
				{
					[(CNSButton *)control setGroup:true];
				}
				
				[(CNSButton *)control setState: false];
			}
			else 
			{
				//check box
				control = [[[CNSButton alloc] initWithFrame: contentRect] autorelease];
				[(CNSButton *)control setCButtonType:NSSwitchButton];
				[(CNSButton *)control setBezelStyle:0]; //This is unnecessary. I include it merely to show that checkboxes don't have a bezel style.
			
				if (strTitle)
				{
					[control setStringValue: strTitle];
				}
			}	
		}
		
		if (strID)
		{										
			[control setTag:[strID intValue]];
		}
		else 
		if (strIDSTR)
		{
			
		}
		
		[(CNSView *)nsView addSubview: control];
		
		[control setParentWnd:this];		
	}
	
	return res;
}

bool CWnd::CreateGroupBox(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <GROUPBOX>
		 <IDSTR>IDC_STATIC</IDSTR>
		 <TEXT>Group test</TEXT>
		 <BOX>58,46,212,42</BOX>
		 </GROUPBOX>								 
		 */
		
		NSXMLElement *controlNode = (NSXMLElement *)controlNodeIn;
		//int windowHeight = 0;
		NSRect contentRect = [(NSWindow *)m_hWnd frame];
		NSString *strTitle = nil;
		NSString *strID = nil;
		NSString *strIDSTR = nil;
		NSArray *arrControlProperty = [controlNode elementsForName:@"IDSTR"];
		
		//windowHeight = contentRect.size.height;
		
		if ([arrControlProperty count])
		{
			strIDSTR = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"TEXT"];
		
		if ([arrControlProperty count])
		{
			strTitle = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"ID"];
		
		if ([arrControlProperty count])
		{
			strID = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"BOX"];
		
		contentRect.origin.x = 0;
		contentRect.origin.y = 0; 
		contentRect.size.width = 100; 
		contentRect.size.height = 100;
		
		if ([arrControlProperty count])
		{
			NSString *strBox = [[arrControlProperty objectAtIndex:0] stringValue];						
			NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
			
			if ([arrStrings count] >=  1)
				contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
			if ([arrStrings count] >=  2)
				contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
			if ([arrStrings count] >=  3)
				contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
			if ([arrStrings count] ==  4)
				contentRect.size.height = [[arrStrings objectAtIndex:3] intValue] + 10;
		}
		
		//contentRect.origin.y  = (windowHeight - contentRect.origin.y);
		
		arrControlProperty = [controlNode elementsForName:@"STYLE"];
		arrControlProperty = [controlNode elementsForName:@"DEFPUSHBUTTON"];
		
		CNSBox *groupBox = [[[CNSBox alloc] initWithFrame: contentRect] autorelease];
		
		//[groupBox setBezeled:NO];
		//[staticText setDrawsBackground:NO];
		//[groupBox setEditable:NO];
		//[staticText setSelectable:NO];
		
		if (strID)
		{										
			[groupBox setTag:[strID intValue]];
		}
		else 
			if (strIDSTR)
			{
				
			}
		
		if (strTitle)
		{
			[groupBox setTitle: strTitle];
		}
		
		[(CNSView *)nsView addSubview: groupBox];
		
		[groupBox setParentWnd:this];			
	}
	
	return res;
}

bool CWnd::CreateEditText(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <CTEXT>           
		 <IDSTR>IDC_STATIC</IDSTR>
		 <TEXT>Place dialog controls here.</TEXT>
		 <BOX>10,96,300,8</BOX>
		 </CTEXT> 									 
		 */
		
		NSXMLElement *controlNode = (NSXMLElement *)controlNodeIn;
		NSRect contentRect = [(NSWindow *)m_hWnd frame];
		NSString *strID = nil;
		NSString *strIDSTR = nil;
		NSArray *arrControlProperty = [controlNode elementsForName:@"IDSTR"];
		
		if ([arrControlProperty count])
		{
			strIDSTR = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"ID"];
		
		if ([arrControlProperty count])
		{
			strID = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"BOX"];
		
		contentRect.origin.x = 0;
		contentRect.origin.y = 0; 
		contentRect.size.width = 100; 
		contentRect.size.height = 100;
		
		if ([arrControlProperty count])
		{
			NSString *strBox = [[arrControlProperty objectAtIndex:0] stringValue];						
			NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
			
			if ([arrStrings count] >=  1)
				contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
			if ([arrStrings count] >=  2)
				contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
			if ([arrStrings count] >=  3)
				contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
			if ([arrStrings count] ==  4)
				contentRect.size.height = [[arrStrings objectAtIndex:3] intValue] + 10;
		}
		
		arrControlProperty = [controlNode elementsForName:@"STYLE"];
		
		CNSTextField *editText = [[[CNSTextField alloc] initWithFrame: contentRect] autorelease];
		
		[editText setBezeled:YES];
		[editText setDrawsBackground:YES];
		[editText setEditable:YES];
		[editText setSelectable:YES];
		
		if (strID)
		{										
			[editText setTag:[strID intValue]];
		}
		else 
		if (strIDSTR)
		{
				
		}
			
		[(CNSView *)nsView addSubview: editText];	
		
		[editText setParentWnd:this];		
	}
	
	return res;
}

bool CWnd::CreateListBox(PtrNSXMLElement controlNodeIn, void *nsView)
{
	bool res = false;
	
	if (controlNodeIn &&
		m_hWnd)
	{
		/*			
		 <LISTBOX>
			 <IDSTR>IDC_LIST1</IDSTR>
			 <ID>1004</ID>
			 <BOX>191,113,122,53</BOX>
			 <STYLE>LBS_SORT | LBS_NOINTEGRALHEIGHT | WS_VSCROLL | WS_TABSTOP</STYLE>
		 </LISTBOX>									 
		 */
		
		NSXMLElement *controlNode = (NSXMLElement *)controlNodeIn;
		NSRect contentRect = [(NSWindow *)m_hWnd frame];
		NSString *strID = nil;
		NSString *strIDSTR = nil;
		NSArray *arrControlProperty = [controlNode elementsForName:@"IDSTR"];
		
		if ([arrControlProperty count])
		{
			strIDSTR = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"ID"];
		
		if ([arrControlProperty count])
		{
			strID = [[arrControlProperty objectAtIndex:0] stringValue];
		}
		
		arrControlProperty = [controlNode elementsForName:@"BOX"];
		
		contentRect.origin.x = 0;
		contentRect.origin.y = 0; 
		contentRect.size.width = 100; 
		contentRect.size.height = 100;
		
		if ([arrControlProperty count])
		{
			NSString *strBox = [[arrControlProperty objectAtIndex:0] stringValue];						
			NSArray	*arrStrings = [strBox componentsSeparatedByCharactersInSet: [NSCharacterSet characterSetWithCharactersInString: @","]];
			
			if ([arrStrings count] >=  1)
				contentRect.origin.x = [[arrStrings objectAtIndex:0] intValue];
			if ([arrStrings count] >=  2)
				contentRect.origin.y = [[arrStrings objectAtIndex:1] intValue]; 
			if ([arrStrings count] >=  3)
				contentRect.size.width = [[arrStrings objectAtIndex:2] intValue]; 
			if ([arrStrings count] ==  4)
				contentRect.size.height = [[arrStrings objectAtIndex:3] intValue] + 10;
		}
		
		arrControlProperty = [controlNode elementsForName:@"STYLE"];
		//arrControlProperty = [controlNode elementsForName:@"DEFPUSHBUTTON"];
		
		NSTableColumn *column = [[NSTableColumn alloc] initWithIdentifier: strID];
		CNSTableView *tableView = [[[CNSTableView alloc] initWithFrame: contentRect] autorelease];
		
		[tableView setDataSource: [[CNSTableViewDataSourceString alloc] init]];
		[tableView addTableColumn:column];
		
		if (strID)
		{										
			[tableView setTag:[strID intValue]];
		}
		else 
		if (strIDSTR)
		{
				
		}
		
		[(CNSView *)nsView addSubview: tableView];	
		
		[tableView setParentWnd:this];		
	}
	
	return res;	
}

void CWnd::FinaleSetup()
{
	if (!mFinished)
	{
		SetMessageMap();
		
		DoDataExchange(&mDX);
		
		if (IsDialog())
		{
			OnInitDialog();
		}
		
		mFinished = true;
	}
}

PtrNSWindowDelegate CWnd::GetWindowDelegate()
{
	return mWindowDelegate;
}

PtrNSWindow CWnd::GetNSWindow()
{
	return m_hWnd;
}

void CWnd::SetNSWindow(PtrNSWindow wnd)
{
	m_hWnd = wnd;
}

void CWnd::AddEventHandle(int objID, EventFun fun, int eventType)
{
	if (m_hWnd)
	{
		PtrNSWindowHandle	pWindowHandle = mWindowHandle;
		CCmdTEHData			*p_mapEventHandle = &(m_mapEventHandle);
		NSControl			*control= nil;
		NSView				*viewer = nil;
		
		if ([(NSObject*)m_hWnd isKindOfClass: [NSWindow class]])
		{
			if (objID != 0)
			{
				control = [[(NSWindow *)m_hWnd contentView] viewWithTag: objID];   
			}
			
			viewer = [(NSWindow *)m_hWnd contentView];
		}
		else
		if ([(NSObject*)m_hWnd isKindOfClass: [NSControl class]])
		{
			control = (NSControl *)m_hWnd;  
			
			if (objID != 0 && [control tag] != objID)
			{
				control = nil;
				assert(false);
			}
			
			if (objID == 0 && control)
			{
				objID = [control tag];
			}
			
			viewer = control;
		}
	
		CCmdTargetEventHandle handle;
		
		handle.tag			= objID;
		handle.fun			= fun;
		handle.eventType	= eventType;
		handle.control		= this;
		
		p_mapEventHandle->push_back(handle);

		if (control)
		{
			SEL eventHandle = @selector(controlEventHandle:);
			
			if (pWindowHandle)
			{
				[control setTarget:(CNSWindowHandle *)pWindowHandle];
				[control setAction:eventHandle];
			}
		}
		else 
		{						
			NSLog(@"CANNOT ADD EVENT IT IS VIEWER");
		}
	}
}

void CWnd::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)
{
	NSLog(@"TO DO CWnd::AddEventRangeHandle(int objID1, int objID2, EventFun fun, int eventType)");
}

void CWnd::AddEventHandle(void *obj, EventFun fun, int eventType)
{
	AddEventHandle([(NSView *)obj tag], fun, eventType);
}

void CWnd::DDX_Control(CDataExchange *pDX, int nIDC, CWnd &control)
{
	control.InitControl(nIDC, this);
	control.FinaleSetup();
}

void CWnd::DDX_CBIndex(CDataExchange *pDX, int nIDC, int& index)
{
	pDX->m_mapValues[nIDC] = &index;
}

void CWnd::DDX_Check(CDataExchange *pDX, int nIDC, BOOL& value)
{
	pDX->m_mapValues[nIDC] = &value;
}

void CWnd::DDX_Radio(CDataExchange* pDX, int nIDC, int& value)
{
	pDX->m_mapValues[nIDC] = &value;
}

void CWnd::DDX_Text(CDataExchange* pDX, int nIDC, CString& value)
{
	pDX->m_mapValues[nIDC] = &value;
}

void CWnd::DDV_MaxChars(CDataExchange* pDX, CString const& value, int nChars)
{
	NSLog(@"TO DO CWnd::DDV_MaxChars");
}

PtrNSWindow CWnd::GetControlByIDC(int IDC)
{
	NSControl *control = [[(NSWindow *)m_hWnd contentView] viewWithTag: IDC];
	
	return control;
}

BOOL CWnd::UpdateData(BOOL bSaveAndValidate)
{
	std::map<int, void *>::iterator it;
	
	for(it = mDX.m_mapValues.begin(); it != mDX.m_mapValues.end(); it++)		
	{
		NSControl *control = [[(NSWindow *)m_hWnd contentView] viewWithTag: it->first];
		
		if (control)
		{			
			if ([control isKindOfClass: [NSButton class]])
			{
				if (bSaveAndValidate) // get from controls
				{
					*((int *)(it->second)) = [control intValue];
				}
				else // set controls
				{
					[control setIntValue: *((int *)(it->second))];							
				}
			}
			/*
			else
			if ([control isMemberOfClass: [NSButton class]])
			{
				if (bSaveAndValidate) // get from controls
				{
					*((int *)(it->second)) = [control intValue];
				}
				else // set controls
				{
					[control setIntValue: *((int *)(it->second))];							
				}
			}
			 */
		}
	}

	return TRUE;
}

CWnd* CWnd::GetDlgItem(int nID)// const
{
	CWnd *control = nil;
	std::map<int, CWnd*>::iterator it;
	
	it = mMapControls.find(nID);
	
	if (it != mMapControls.end())
	{
		delete it->second;
	}
	
	control = new CWnd;
	
	if (!control->InitControl(nID, (CWnd* )this))
	{
		return nil;
	}
	
	mMapControls[nID] = control;
	
	return control;
}

HICON CWnd::SetIcon(HICON hIcon, BOOL bBigIcon)
{
	NSLog(@"TO DO CWnd::SetIcon");
	return hIcon;
}

CMenu* CWnd::GetSystemMenu(BOOL bRevert)// const
{
	NSMenu *rootMenu = [NSApp mainMenu];
	NSMenu *appMenu = [[rootMenu itemAtIndex:0] submenu];
	
	mMenu.SetNSMenu((void *)appMenu, this);
	
	return &mMenu;//CWnd::GetMenu(this); 
}

void CWnd::SetWindowText(LPCTSTR lpszString )
{
	if (m_hWnd && [(NSObject *)m_hWnd isKindOfClass: [NSControl class]])
	{
		[(NSControl *)m_hWnd setStringValue: [NSString stringWithUTF8String: lpszString]];
	}
	else 
	{
		mCaptionStr = lpszString;
	}
}

int CWnd::GetWindowText(LPTSTR lpszStringBuf, int nMaxCount) const
{
	if (m_hWnd && [(NSObject *)m_hWnd isKindOfClass: [NSControl class]])
	{
		NSString *str = [(NSControl *)m_hWnd stringValue];
		
		if (str)
		{
			[str getCString:lpszStringBuf maxLength:nMaxCount encoding:NSUTF8StringEncoding];
			
			return [str length];
		}
	}
	
	strncpy(lpszStringBuf, mCaptionStr.c_str(), mCaptionStr.size() > nMaxCount ? nMaxCount : mCaptionStr.size());
	return mCaptionStr.size() > nMaxCount ? nMaxCount : mCaptionStr.size();
}

void CWnd::GetWindowText(CString& rString) const
{
	if (m_hWnd && [(NSObject *)m_hWnd isKindOfClass: [NSControl class]])
	{
		NSString *str = [(NSControl *)m_hWnd stringValue];
		
		if (str)
		{
			rString = [str UTF8String];
		}
	}
	else 
	{
		rString = mCaptionStr;
	}
}

BOOL CWnd::ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags)
{
	NSLog(@"TO DO CWnd::ModifyStyle");
	
	return TRUE;	
}

void CWnd::DragAcceptFiles(BOOL bAccept)
{
	NSLog(@"TO DO CWnd::DragAcceptFiles");
}

BOOL CWnd::SetWindowPlacement(const WINDOWPLACEMENT*lpwndpl)
{
	NSLog(@"TO DO CWnd::SetWindowPlacement");
	
	return FALSE;
}

CFont* CWnd::GetFont() const
{
	NSLog(@"TO DO CWnd::GetFont");
	
	return NULL;
}

typedef void (* fnTimer)(HWND, UINT, UINT_PTR, DWORD);

@interface WinTimeHelper : NSObject
{
	CWnd	*m_win;
	fnTimer m_fn;
	int	m_id;
}

@end

@implementation WinTimeHelper

- (void)setWin:(CWnd *)win
{
	m_win = win;
}

- (void)setFun:(fnTimer)fn
{
	m_fn = fn;
}

- (void)setId:(int)i
{
	m_id = i;
}

- (void)helperMethod:(NSTimer*)theTimer
{
	if (m_fn)
	{
		m_fn(m_win, WM_TIMER, m_id, 0);
	}
	else
	if (m_win)
	{
		m_win->OnTimer(m_id);
	}
}

@end

@interface CNSTimer : NSTimer
{
	CWnd	*m_win;
	fnTimer m_fn;
	int	m_id;
}

@end

@implementation CNSTimer

- (void)setWin:(CWnd *)win
{
	m_win = win;
}

- (void)setFun:(fnTimer)fn
{
	m_fn = fn;
}

- (void)setId:(int)i
{
	m_id = i;
}

- (CWnd *)getWin
{
	return m_win;
}

- (fnTimer)getFun
{
	return m_fn;
}

- (int)getId
{
	return m_id;
}


@end

UINT_PTR CWnd::SetTimer(UINT_PTR nIDEvent, UINT nElapse, void (* lpfnTimer)(HWND, UINT, UINT_PTR, DWORD))
{
	WinTimeHelper *helper = [[WinTimeHelper alloc] init];
	
	[helper setWin: this];
	[helper setFun: lpfnTimer];
	[helper setId: nIDEvent];
	
	CNSTimer *timer = (CNSTimer *)[CNSTimer timerWithTimeInterval:nElapse/1000 target:helper selector:@selector(helperMethod:) userInfo:nil repeats:YES];
	
	[timer setWin: this];
	[timer setFun: lpfnTimer];
	[timer setId: nIDEvent];
	
	mTimerArr.push_back(timer);
	
	[timer fire];
	
	return 0;
}

BOOL CWnd::KillTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == -1)
	{
		for(int i = 0; i < mTimerArr.size(); i++)
		{
			CNSTimer *timer = (CNSTimer *)mTimerArr[i];
			
			[timer invalidate];
			[timer release];
		}
		
		mTimerArr.clear();
	}
	else 
	{
		for(int i = 0; i < mTimerArr.size(); i++)
		{
			CNSTimer *timer = (CNSTimer *)mTimerArr[i];
			
			if ([timer getId] == nIDEvent)
			{
				[timer invalidate];
				[timer release];
				
				mTimerArr.erase(mTimerArr.begin() + i);
				
				break;
			}
		}
	}
	
	return TRUE;
}

void CWnd::OnTimer(UINT nIDEvent)
{
	NSLog(@"TO DO CWnd::OnTimer");
}

BOOL CWnd::EnableToolTips(BOOL bEnable)
{
	NSLog(@"TO DO CWnd::EnableToolTips");
	
	return TRUE;
}

void CWnd::Invalidate(BOOL bErase)
{
	NSLog(@"TO DO CWnd::Invalidate");
}

void CWnd::InvalidateRect(LPCRECT lpRect, BOOL bErase )
{
	NSLog(@"TO DO CWnd::InvalidateRect");
}

void CWnd::SetFont(CFont* pFont, BOOL bRedraw)
{
	NSLog(@"TO DO CWnd::GetFont");
}

DWORD CWnd::GetStyle( ) const
{
	NSLog(@"TO DO CWnd::GetStyle");
	return 0;	
}

int CWnd::GetDlgCtrlID() const
{
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSView class]])
	{
		return [(NSView *)m_hWnd tag];
	}
	
	return 0;
}

CWnd* CWnd::GetParent() const
{
	return mParentWin;
}

void CWnd::GetClientRect(LPRECT lpRect) const
{
	lpRect->left = 0;
	lpRect->top = 0;
	lpRect->right = 0;
	lpRect->bottom = 0;
	
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSView class]])
	{
		NSRect rect = [(NSView *)m_hWnd bounds];
		
		lpRect->left = 0;
		lpRect->top = 0;
		lpRect->right = rect.size.width;
		lpRect->bottom = rect.size.height;
	}
	else
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSWindow class]])
	{
		NSRect rect = [(NSWindow *)m_hWnd frame];
		
		lpRect->left = 0;
		lpRect->top = 0;
		lpRect->right = rect.size.width;
		lpRect->bottom = rect.size.height;
	}
}

void CWnd::GetWindowRect(LPRECT lpRect) const
{
	lpRect->left = 0;
	lpRect->top = 0;
	lpRect->right = 0;
	lpRect->bottom = 0;
	
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSView class]])
	{
		NSRect rect = [(NSView *)m_hWnd frame];
		
		lpRect->left = rect.origin.x;
		lpRect->top = rect.origin.y;
		lpRect->right = rect.origin.x + rect.size.width;
		lpRect->bottom = rect.origin.y + rect.size.height;
	}
	else
	if ([(NSObject *)m_hWnd  isKindOfClass:[NSWindow class]])
	{
		NSRect rect = [(NSWindow *)m_hWnd frame];
		
		lpRect->left = rect.origin.x;
		lpRect->top = rect.origin.y;
		lpRect->right = rect.size.width;
		lpRect->bottom = rect.size.height;
	}
}

CWnd* CWnd::GetFocus()
{
	NSLog(@"TO DO CWnd::GetFocus");
	return 0;
}

CWnd* CWnd::SetFocus()
{
	NSLog(@"TO DO CWnd::SetFocus");
	return 0;
}

BOOL CWnd::ShowWindow(int nCmdShow)
{
	if (nCmdShow == SW_SHOW)
	{
		[(NSView *)m_hWnd setHidden:false];
	}
	else 
	{
		[(NSView *)m_hWnd setHidden:true];
	}

	return TRUE;
}

BOOL CWnd::EnableWindow(BOOL bEnable)
{
	BOOL res = FALSE;
	NSObject *obj = (NSObject *)m_hWnd;
	
	if ([obj isKindOfClass:[NSControl class]])
	{
		res = [(NSControl *)obj isEnabled];
		
		[(NSControl *)obj setEnabled:bEnable];
	}
	
	return res;
}

BOOL CWnd::IsIconic() const
{
	NSLog(@"TO DO CWnd::IsIconic");
	return FALSE;
}

BOOL CWnd::SetWindowPos(const CWnd* pWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags)
{
	NSLog(@"TO DO CWnd::SetWindowPos");
	return TRUE;
}

void CWnd::ScreenToClient(LPPOINT lpPoint) const
{
	NSLog(@"TO DO CWnd::ScreenToClient");
}

void CWnd::ScreenToClient(LPRECT lpRect) const
{
	NSLog(@"TO DO CWnd::ScreenToClient");
}

void CWnd::MoveWindow(int x, int y, int nWidth, int nHeight, BOOL bRepaint)
{
	NSLog(@"TO DO CWnd::MoveWindow");
}

void CWnd::MoveWindow(LPCRECT lpRect, BOOL bRepaint)
{
	NSLog(@"TO DO CWnd::MoveWindow");
}

LRESULT CWnd::SendMessage(UINT message, WPARAM wParam,LPARAM lParam)
{
	NSLog(@"TO DO CWnd::SendMessage");
	return TRUE;
}

BOOL CWnd::PostMessage(UINT message, WPARAM wParam, LPARAM lParam)
{
	NSLog(@"TO DO CWnd::SetFocus");
	return TRUE;
}

BOOL CWnd::PreTranslateMessage(MSG* pMsg)
{
	NSLog(@"TO DO CWnd::PreTranslateMessage");
	return TRUE;
}

void CWnd::PreSubclassWindow()
{
	NSLog(@"TO DO CWnd::PreSubclassWindow");
}

BOOL CWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	NSLog(@"TO DO CWnd::PreCreateWindow");
	return TRUE;
}

void CWnd::UpdateWindow()
{
	NSLog(@"TO DO CWnd::UpdateWindow");
}

int CWnd::MessageBox(LPCTSTR lpszText, LPCTSTR lpszCaption, UINT nType)
{
	int res = IDCANCEL;
	NSAlert *alert = nil;
	
	if (nType & (MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4))
	{
		NSLog(@"TO DO AfxMessageBox not support MB_DEFBUTTON1 | MB_DEFBUTTON2 | MB_DEFBUTTON3 | MB_DEFBUTTON4");
	}
	
	if (nType & (MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY))
	{
		NSLog(@"TO DO AfxMessageBox not support MB_APPLMODAL | MB_SYSTEMMODAL | MB_TASKMODAL | MB_DEFAULT_DESKTOP_ONLY");
	}
	
	if (nType & (MB_RIGHT | MB_SETFOREGROUND))
	{
		NSLog(@"TO DO AfxMessageBox not support MB_RIGHT | MB_SETFOREGROUND");
	}			
	
	if (nType & MB_OK)
	{
		alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
							   defaultButton:@"OK"
							 alternateButton:nil 
								 otherButton:nil
				   informativeTextWithFormat:@""];
	}
	else 
		if (nType & MB_OKCANCEL)
		{
			alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
								   defaultButton:@"OK"
								 alternateButton:@"Cancel" 
									 otherButton:nil
					   informativeTextWithFormat:@""];
		}
		else 
			if (nType & MB_RETRYCANCEL)
			{
				alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
									   defaultButton:@"Retry"
									 alternateButton:@"Cancel" 
										 otherButton:nil
						   informativeTextWithFormat:@""];
			}
			else 
				if (nType & MB_YESNO)
				{
					alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
										   defaultButton:@"Yes"
										 alternateButton:@"No" 
											 otherButton:nil
							   informativeTextWithFormat:@""];
				}
				else 
					if (nType & MB_YESNOCANCEL)
					{
						alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
											   defaultButton:@"Yes"
											 alternateButton:@"No" 
												 otherButton:@"Cancel"
								   informativeTextWithFormat:@""];
					}
					else 
						if (nType & MB_ABORTRETRYIGNORE)
						{
							alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
												   defaultButton:@"Abort"
												 alternateButton:@"Retry" 
													 otherButton:@"Ignore"
									   informativeTextWithFormat:@""];
						}
						else 
							if (nType & MB_CANCELTRYCONTINUE)
							{
								alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
													   defaultButton:@"Cancel"
													 alternateButton:@"Try Again" 
														 otherButton:@"Continue"
										   informativeTextWithFormat:@""];
							}
							else 
							{
								alert =[NSAlert alertWithMessageText:[NSString stringWithUTF8String: lpszText] 
													   defaultButton:@"OK"
													 alternateButton:nil 
														 otherButton:nil
										   informativeTextWithFormat:@""];	
							}
	
	if (alert)
	{
		NSInteger result;
		
		if (nType & MB_ICONEXCLAMATION)
		{
			[alert setAlertStyle: NSWarningAlertStyle];
		}
		else
			if (nType & MB_ICONWARNING)
			{
				[alert setAlertStyle: NSWarningAlertStyle];
			}
			else
				if (nType & MB_ICONINFORMATION)
				{
					[alert setAlertStyle: NSInformationalAlertStyle];
				}
				else
					if (nType & MB_ICONASTERISK)
					{
						[alert setAlertStyle: NSInformationalAlertStyle];
					}
					else
						if (nType & MB_ICONQUESTION)
						{
							[alert setAlertStyle: NSInformationalAlertStyle];
						}
						else
							if (nType & MB_ICONSTOP)
							{
								[alert setAlertStyle: NSCriticalAlertStyle];
							}
							else
								if (nType & MB_ICONERROR)
								{
									[alert setAlertStyle: NSCriticalAlertStyle];
								}
								else
									if (nType & MB_ICONHAND)
									{
										[alert setAlertStyle: NSCriticalAlertStyle];
									}
		
		result = [alert runModal];
		
		if (nType & MB_OK)
		{
			res =  IDOK;
		}
		else 
			if (nType & MB_OKCANCEL)
			{
				res =  IDCANCEL;
				
				if (result == NSAlertDefaultReturn)
				{
					res =  IDOK;
				}
			}
			else 
				if (nType & MB_RETRYCANCEL)
				{
					res =  IDRETRY;
					
					if (result == NSAlertDefaultReturn)
					{
						res =  IDCANCEL;
					}
				}
				else 
					if (nType & MB_YESNO)
					{
						res =  IDNO;
						
						if (result == NSAlertDefaultReturn)
						{
							res =  IDYES;
						}
					}
					else 
						if (nType & MB_YESNOCANCEL)
						{
							res =  IDCANCEL;
							
							if (result == NSAlertDefaultReturn)
							{
								res =  IDYES;
							}
							else 
								if (result == NSAlertAlternateReturn)
								{
									res =  IDNO;
								}
						}
						else 
							if (nType & MB_ABORTRETRYIGNORE)
							{
								res =  IDIGNORE;
								
								if (result == NSAlertDefaultReturn)
								{
									res =  IDABORT;
								}
								else 
									if (result == NSAlertAlternateReturn)
									{
										res =  IDRETRY;
									}
							}
							else 
								if (nType & MB_CANCELTRYCONTINUE)
								{
									res =  IDCONTINUE;
									
									if (result == NSAlertDefaultReturn)
									{
										res =  IDCANCEL;
									}
									else 
										if (result == NSAlertAlternateReturn)
										{
											res =  IDTRYAGAIN;
										}
								}
	}
	
	return res;
}

BOOL CWnd::SetMenu(CMenu* pMenu)
{
	NSMenu *menuBar = [NSApp menu];		
	NSArray *arrSubMenu = [menuBar itemArray];
	
	for(int i = 1; i < [arrSubMenu count]; i++)
	{
		NSMenuItem *menuItem = [arrSubMenu objectAtIndex: i];
		[menuBar removeItem:menuItem];
	}
	
	NSMenu *menuNewBar = (NSMenu *)pMenu->GetNSMenu();
	
	NSArray *arrNewSubMenu = [menuNewBar itemArray];
	
	for(int i = 0; i < [arrNewSubMenu count]; i++)
	{
		NSMenuItem *menuItem = [arrNewSubMenu objectAtIndex: i];
		[menuNewBar removeItem:menuItem];
		[menuBar addItem: menuItem];
	}
	
	return TRUE;
}

void CWnd::DrawMenuBar()
{
	NSLog(@"TO DO CWnd::DrawMenuBar");
}

CDC* CWnd::GetDC()
{
	NSLog(@"TO DO CWnd::GetDC");
	return NULL;
}

BOOL CWnd::OnInitDialog()
{
	return true;
}

void CWnd::OnOK()
{
	[NSApp stopModalWithCode:IDOK];
}

void CWnd::OnCancel()
{
	[NSApp stopModalWithCode:IDCANCEL];
}

void CWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	NSLog(@"TO DO CWnd::OnChar");
}

void CWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	NSLog(@"TO DO CWnd::OnLButtonDown");
}

void CWnd::OnRButtonDown(UINT nFlags, CPoint point)
{
	NSLog(@"TO DO CWnd::OnRButtonDown");
}

void CWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
	NSLog(@"TO DO CWnd::OnLButtonUp");
}

void CWnd::OnRButtonUp(UINT nFlags, CPoint point)
{
	NSLog(@"TO DO CWnd::OnRButtonUp");
}

void CWnd::OnKillFocus(CWnd* pNewWnd)
{
	NSLog(@"TO DO CWnd::OnKillFocus");
}

void CWnd::OnSetFocus(CWnd* pOldWnd)
{
	NSLog(@"TO DO CWnd::OnSetFocus");
}

void CWnd::OnPaint()
{
	NSLog(@"TO DO CWnd::OnPaint");
}

int	CWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	NSLog(@"TO DO CWnd::OnCreate");
	return 0;
}

void CWnd::OnSysCommand(UINT nID, LPARAM lParam)
{
	NSLog(@"TO DO CWnd::OnSysCommand");
}

void CWnd::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	NSLog(@"TO DO CWnd::OnHScroll");
}

void CWnd::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	NSLog(@"TO DO CWnd::OnVScroll");
}

BOOL CWnd::InitControl(int nIDC, CWnd *win)
{
	m_hWnd = nil;
	mParentWin = win;
	
	if (mParentWin)
	{
		if (mWindowHandle)
		{
			[(CNSWindowHandle *)mWindowHandle dealloc];
		}
		
		mWindowHandle = [[CNSWindowHandle alloc] init];
		[(CNSWindowHandle *)mWindowHandle setCWnd: this];
		
		m_hWnd = mParentWin->GetControlByIDC(nIDC);
		
		if (m_hWnd &&
			[(NSControl *)m_hWnd isKindOfClass: [CNSButton class]])
		{
			CNSButton *button = (CNSButton *)m_hWnd;
			
			[button setWnd: this];
			[button setParentWnd: mParentWin];
		}
		
		if (m_hWnd &&
			[(NSControl *)m_hWnd isKindOfClass: [CNSTextField class]])
		{
			mWindowDelegate = [[CNSTextFieldDelegate alloc] init];
			[(CNSTextFieldDelegate *)mWindowDelegate setCWnd: this];
			[(CNSTextField *)m_hWnd setDelegate: (CNSTextFieldDelegate *)mWindowDelegate];
			
			[(CNSTextField *)m_hWnd setWnd: this];
			[(CNSTextField *)m_hWnd setParentWnd: mParentWin];
		}
		
		if (m_hWnd &&
			[(NSControl *)m_hWnd isKindOfClass: [CNSTabView class]])
		{
			mWindowDelegate = [[CNSTabViewDelegate alloc] init];
			[(CNSTabViewDelegate *)mWindowDelegate setCWnd: this];
			[(CNSTabView *)m_hWnd setDelegate: (CNSTabViewDelegate *)mWindowDelegate];
			
			[(CNSTabView *)m_hWnd setWnd: this];
			[(CNSTabView *)m_hWnd setParentWnd: mParentWin];
		}
		
		PreSubclassWindow();
	}
	
	return TRUE;
}

BOOL CWnd::IsDialog()
{
	return false;
}
