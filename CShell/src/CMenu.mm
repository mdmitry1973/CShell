/*
 *  CMenu.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CBitmap.h"
#include "CMenu.h"
#include "CWnd.h"

#import "CNSWindowDelegate.h"
#import "CNSWindow.h"
#import "CNSApplicationDelegate.h"

extern CNSApplicationDelegate	*pMainAppCocoa;

CMenu::CMenu()
{
	m_NMenu = nil;
	m_owner = nil;
}

CMenu::~CMenu()
{
	
}

BOOL CMenu::AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, LPCTSTR lpszNewItem)
{
	assert(m_NMenu || m_owner);
	
	//nFlags
	//MF_OWNERDRAW Contains an application-supplied 32-bit value that the application can use to maintain additional data associated with the menu item. This 32-bit value is available to the application when it processes WM_MEASUREITEM and WM_DRAWITEM messages. The value is stored in the itemData member of the structure supplied with those messages.
	//MF_STRING Contains a pointer to a null-terminated string. This is the default interpretation.
	//MF_SEPARATOR The lpszNewItem parameter is ignored (not needed).
	//&About SimpleDialog2...
	NSString *strItem = nil;
	NSMenuItem *menuItem = nil;
	
	if (lpszNewItem)
	{
		strItem = [NSString stringWithUTF8String: lpszNewItem];
		strItem = [strItem stringByReplacingOccurrencesOfString: @"&" withString: @""];
	}

	if (nIDNewItem == 0x0010)//IDM_ABOUTBOX)
	{
		NSMenuItem *menuItem = [(NSMenu *)m_NMenu itemAtIndex:0];
		
		if (menuItem && nFlags == MF_STRING)
		{
			CNSWindowDelegate *dlg = (CNSWindowDelegate *)m_owner->GetWindowDelegate();
			//CNSWindow *win = (CNSWindow *)m_owner->GetNSWindow();
			
			//NSMenu *mennn = [NSApp windowsMenu];
			
			//[NSApp setWindowsMenu:[NSApp mainMenu]];
			
			[menuItem setTitle: strItem];
			
			[dlg setMenuAction: menuItem];
			
			//NSMenuItem *menuItem2 = [(NSMenu *)m_NMenu addItemWithTitle:@"test menu item" action:@selector(menuEventHandle:) keyEquivalent: @""];
			//
			//[dlg setMenuAction: menuItem2];
			//[menuItem2 setRepresentedObject:NSApp];
			//[menuItem2 setTarget: NSApp];
			//[menuItem2 setEnabled:true];
			
			//NSMenuItem* newItem = [[NSMenuItem allocWithZone:[NSMenu menuZone]] initWithTitle:@"test test" action:@selector(menuEventHandle:) keyEquivalent:@""];
			//[newItem setTarget: dlg];
			//[(NSMenu *)m_NMenu addItem:newItem];
			//[newItem release];
			
			
			//[(NSMenu *)m_NMenu setDelegate:dlg];
			
			//#1	0x92137a26 in -[NSApplication sendAction:to:from:]
			//[menuItem setTarget: dlg];
			//[menuItem setAction:@selector(menuEventHandle:)];//[dlg getMenuCall]];
		}
	}
	else 
	{
		if (nFlags == MF_STRING)
		{
			CNSWindowDelegate *dlg = (CNSWindowDelegate *)m_owner->GetWindowDelegate();
			//CNSWindow *win = (CNSWindow *)m_owner->GetNSWindow();
			 
			menuItem = [(NSMenu *)m_NMenu addItemWithTitle:strItem action:NULL /*[dlg getMenuCall]*/ keyEquivalent: @""];
			
			[dlg setMenuAction: menuItem];
			
			//[(NSMenu *)m_NMenu setDelegate:dlg];
			//[menuItem setRepresentedObject: dlg];
			//[menuItem setTarget: dlg];
			//[menuItem setAction:@selector(menuEventHandle:)];//[dlg getMenuCall]];
		}
		else 
		if (nFlags == MF_SEPARATOR)
		{
			menuItem = [(NSMenu *)m_NMenu addItemWithTitle:@"-" action:nil keyEquivalent: @""];
		}
	}
	
	if (menuItem)
	{
		[(NSMenu *)m_NMenu setAutoenablesItems:NO];
		[menuItem setEnabled:true];
	}
	
	return TRUE;
}

BOOL CMenu::AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp)
{
	NSLog(@"TO DO CMenu::AppendMenu");
	return TRUE;
}

BOOL CMenu::InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem, LPCTSTR lpszNewItem)
{
	NSLog(@"TO DO CMenu::InsertMenu");
	return TRUE;
}

BOOL CMenu::InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp)
{
	NSLog(@"TO DO CMenu::InsertMenu");
	return TRUE;
}

BOOL CMenu::MenuParser(void *currentMenuVoid, void *rootMenuNodeVoid)
{
	NSMenu *currentMenu = (NSMenu *)currentMenuVoid;
	NSXMLElement *rootMenuNode = (NSXMLElement *)rootMenuNodeVoid;
	
	for(int i = 0; i < [rootMenuNode childCount]; i++)
	{
		NSXMLNode *node = [rootMenuNode childAtIndex:i];
		NSString *nodeName = [node name];							
		
		if ([nodeName compare: @"POPUP"] == NSOrderedSame)
		{
			NSXMLNode *attr = [(NSXMLElement *)node attributeForName:@"Name"];
			
			if (attr)
			{				
				NSString *menuName = [attr stringValue];
				NSMenu *menu = [[NSMenu alloc] autorelease];
				NSMenuItem *menuItem = [[NSMenuItem alloc] autorelease];
				
				menuName = [menuName stringByReplacingOccurrencesOfString:@"&" withString:@""];
				
				[menuItem setTitle:menuName];
				[menu setTitle:menuName];
				[menu setAutoenablesItems: NO];
				
				[currentMenu addItem: menuItem];
				[menuItem setSubmenu: menu];
				
				//[menuItem setState: NSOnState];
				[menuItem setEnabled: YES];
								
				MenuParser(menu, node);				
			}
		}
		else 
		if ([nodeName compare: @"MENUITEM"] == NSOrderedSame)
		{
			NSXMLNode *attrName = [(NSXMLElement *)node attributeForName:@"Name"];
			NSXMLNode *attrID = [(NSXMLElement *)node attributeForName:@"ID"];
			NSXMLNode *attrStrID = [(NSXMLElement *)node attributeForName:@"IDSTR"];
			
			NSString *menuItemName = [attrName stringValue];
			NSMenuItem *menuItem = [[NSMenuItem alloc] autorelease];
			
			if (menuItemName)
			{
				menuItemName = [menuItemName stringByReplacingOccurrencesOfString:@"&" withString:@""];
				[menuItem setTitle:menuItemName];
			}
			
			if (attrID)
			{			
				[menuItem setTag: [[attrID stringValue] intValue]];
				
				[menuItem setTarget:pMainAppCocoa];
				[menuItem setAction:@selector(menuEventHandle:)];
			}
			
			if (attrStrID)
			{
			
			}
			
			//[menuItem setState: NSOnState];			[
			[menuItem setEnabled: YES];
			
			[currentMenu addItem: menuItem];	
		}
		else 
		if ([nodeName compare: @"SEPARATOR"] == NSOrderedSame)
		{
			NSMenuItem *menuItem = [NSMenuItem separatorItem];
			[currentMenu addItem: menuItem];	
		}
	}
	
	return TRUE;
}

BOOL CMenu::LoadMenu(LPCTSTR lpszResourceName)
{
	BOOL res = FALSE;
	
	//if (g_mapResStrimgs.size() == 0)
	{		
		NSBundle *resBundle = [NSBundle mainBundle];
		
		if (resBundle)
		{
			NSString *resFilePath = [resBundle pathForResource: @"Resources" ofType:@"xml"];
			
			if (resFilePath)
			{
				NSError *error = nil;
				NSXMLDocument *doc = [[NSXMLDocument alloc] initWithData:[NSData dataWithContentsOfFile: resFilePath] options:NSXMLDocumentTidyXML error:&error];
				
				if (doc)
				{
					//<MFC_RESOURCE>
					//<MENU IDSTR="IDR_MAINFRAME" ID="128">
					//<POPUP Name="&amp;File">
					//<MENUITEM Name="E&amp;xit" IDSTR="ID_APP_EXIT">
					//</MENUITEM>
					//<SEPARATOR>
					//</SEPARATOR>
					//</POPUP>
					
					NSString *xpath = [NSString stringWithFormat: @"/MFC_RESOURCE/MENU[@ID='%s']", lpszResourceName];
					NSArray *arrWindowsNode = [doc nodesForXPath:xpath error:&error];
					
					if ([arrWindowsNode count])
					{
						NSXMLElement *rootMenuNode = [arrWindowsNode objectAtIndex: 0];
						NSMenu *menubar = [[NSMenu alloc] autorelease];
						
						[menubar setAutoenablesItems: NO];
						
						if (MenuParser(menubar, rootMenuNode))
						{
							m_NMenu = menubar;
							
							res = TRUE;
						}
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
		
	}
	
	return res;
}

BOOL CMenu::LoadMenu(UINT nIDResource)
{
	NSString *str = [NSString stringWithFormat: @"%d", nIDResource];
	
	return LoadMenu([str UTF8String]);
}

void CMenu::SetNSMenu(void *menu, CWnd *owner)
{
	m_NMenu = menu;
	m_owner = owner;
}

void *CMenu::GetNSMenu()
{
	return m_NMenu;
}

