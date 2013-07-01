/*
 *  CMenu.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>

#include "CDef.h"
#include "CBitmap.h"
#include "CMenu.h"
#include "CWnd.h"

//#import "CNSWindowDelegate.h"
//#import "CNSWindow.h"
//#import "CNSApplicationDelegate.h"

//extern CNSApplicationDelegate	*pMainAppCocoa;

static std::map<std::string, long> g_menu_id_map;

CMenu::CMenu()
{
    m_NMenu = NULL;
    m_owner = NULL;
	
	if (!g_menu_id_map.size())
	{
		g_menu_id_map["ID_FILE_NEW"] = 0xE100;
		g_menu_id_map["ID_FILE_OPEN"] = 0xE101;
		g_menu_id_map["ID_FILE_CLOSE"] = 0xE102;
		g_menu_id_map["ID_FILE_SAVE"] = 0xE103;
		g_menu_id_map["ID_FILE_SAVE_AS"] = 0xE104;
		g_menu_id_map["ID_FILE_PAGE_SETUP"] = 0xE105;
		g_menu_id_map["ID_FILE_PRINT_SETUP"] = 0xE106;
		g_menu_id_map["ID_FILE_PRINT"] = 0xE107;
		g_menu_id_map["ID_FILE_PRINT_DIRECT"] = 0xE108;
		g_menu_id_map["ID_FILE_PRINT_PREVIEW"] = 0xE109;
		g_menu_id_map["ID_FILE_UPDATE"] = 0xE10A;
		g_menu_id_map["ID_FILE_SAVE_COPY_AS"] = 0xE10B;
		g_menu_id_map["ID_FILE_SEND_MAIL"] = 0xE10C;
	
		g_menu_id_map["ID_FILE_MRU_FIRST"] = 0xE110;
		g_menu_id_map["ID_FILE_MRU_FILE1"] = 0xE110;         // range - 16 max
		g_menu_id_map["ID_FILE_MRU_FILE2"] = 0xE111;
		g_menu_id_map["ID_FILE_MRU_FILE3"] = 0xE112;
		g_menu_id_map["ID_FILE_MRU_FILE4"] = 0xE113;
		g_menu_id_map["ID_FILE_MRU_FILE5"] = 0xE114;
		g_menu_id_map["ID_FILE_MRU_FILE6"] = 0xE115;
		g_menu_id_map["ID_FILE_MRU_FILE7"] = 0xE116;
		g_menu_id_map["ID_FILE_MRU_FILE8"] = 0xE117;
		g_menu_id_map["ID_FILE_MRU_FILE9"] = 0xE118;
		g_menu_id_map["ID_FILE_MRU_FILE10"] = 0xE119;
		g_menu_id_map["ID_FILE_MRU_FILE11"] = 0xE11A;
		g_menu_id_map["ID_FILE_MRU_FILE12"] = 0xE11B;
		g_menu_id_map["ID_FILE_MRU_FILE13"] = 0xE11C;
		g_menu_id_map["ID_FILE_MRU_FILE14"] = 0xE11D;
		g_menu_id_map["ID_FILE_MRU_FILE15"] = 0xE11E;
		g_menu_id_map["ID_FILE_MRU_FILE16"] = 0xE11F;
		g_menu_id_map["ID_FILE_MRU_LAST"] = 0xE11F;
	
		// Edit commands
		g_menu_id_map["ID_EDIT_CLEAR"] = 0xE120;
		g_menu_id_map["ID_EDIT_CLEAR_ALL"] = 0xE121;
		g_menu_id_map["ID_EDIT_COPY"] = 0xE122;
		g_menu_id_map["ID_EDIT_CUT"] = 0xE123;
		g_menu_id_map["ID_EDIT_FIND"] = 0xE124;
		g_menu_id_map["ID_EDIT_PASTE"] = 0xE125;
		g_menu_id_map["ID_EDIT_PASTE_LINK"] = 0xE126;
		g_menu_id_map["ID_EDIT_PASTE_SPECIAL"] = 0xE127;
		g_menu_id_map["ID_EDIT_REPEAT"] = 0xE128;
		g_menu_id_map["ID_EDIT_REPLACE"] = 0xE129;
		g_menu_id_map["ID_EDIT_SELECT_ALL"] = 0xE12A;
		g_menu_id_map["ID_EDIT_UNDO"] = 0xE12B;
		g_menu_id_map["ID_EDIT_REDO"] = 0xE12C;
	
		// Window commands
		g_menu_id_map["ID_WINDOW_NEW"] = 0xE130;
		g_menu_id_map["ID_WINDOW_ARRANGE"] = 0xE131;
		g_menu_id_map["ID_WINDOW_CASCADE"] = 0xE132;
		g_menu_id_map["ID_WINDOW_TILE_HORZ"] = 0xE133;
		g_menu_id_map["ID_WINDOW_TILE_VERT"] = 0xE134;
		g_menu_id_map["ID_WINDOW_SPLIT"] = 0xE135;
		g_menu_id_map["AFX_IDM_WINDOW_FIRST"] = 0xE130;
		g_menu_id_map["AFX_IDM_WINDOW_LAST"] = 0xE13F;
		g_menu_id_map["AFX_IDM_FIRST_MDICHILD"] = 0xFF00;  // window list starts here
	
		// Help and App commands
		g_menu_id_map["ID_APP_ABOUT"] = 0xE140;
		g_menu_id_map["ID_APP_EXIT"] = 0xE141;
		g_menu_id_map["ID_HELP_INDEX"] = 0xE142;
		g_menu_id_map["ID_HELP_FINDER"] = 0xE143;
		g_menu_id_map["ID_HELP_USING"] = 0xE144;
		g_menu_id_map["ID_CONTEXT_HELP"] = 0xE145;      // shift-F1
		// special commands for processing help
		g_menu_id_map["ID_HELP"] = 0xE146;      // first attempt for F1
		g_menu_id_map["ID_DEFAULT_HELP"] = 0xE147;      // last attempt
	
		// Misc
		g_menu_id_map["ID_NEXT_PANE"] = 0xE150;
		g_menu_id_map["ID_PREV_PANE"] = 0xE151;
	
		// Format
		g_menu_id_map["ID_FORMAT_FONT"] = 0xE160;
	
		// OLE commands
		g_menu_id_map["ID_OLE_INSERT_NEW"] = 0xE200;
		g_menu_id_map["ID_OLE_EDIT_LINKS"] = 0xE201;
		g_menu_id_map["ID_OLE_EDIT_CONVERT"] = 0xE202;
		g_menu_id_map["ID_OLE_EDIT_CHANGE_ICON"] = 0xE203;
		g_menu_id_map["ID_OLE_EDIT_PROPERTIES"] = 0xE204;
		g_menu_id_map["ID_OLE_VERB_FIRST"] = 0xE210;     // range - 16 max
		g_menu_id_map["ID_OLE_VERB_LAST"] = 0xE21F;
	
		// for print preview dialog bar
		g_menu_id_map["AFX_ID_PREVIEW_CLOSE"] = 0xE300;
		g_menu_id_map["AFX_ID_PREVIEW_NUMPAGE"] = 0xE301;     // One/Two Page button
		g_menu_id_map["AFX_ID_PREVIEW_NEXT"] = 0xE302;
		g_menu_id_map["AFX_ID_PREVIEW_PREV"] = 0xE303;
		g_menu_id_map["AFX_ID_PREVIEW_PRINT"] = 0xE304;
		g_menu_id_map["AFX_ID_PREVIEW_ZOOMIN"] = 0xE305;
		g_menu_id_map["AFX_ID_PREVIEW_ZOOMOUT"] = 0xE306;
	
		// View commands (same number used as IDW used for control bar)
		g_menu_id_map["ID_VIEW_TOOLBAR"] = 0xE800;
		g_menu_id_map["ID_VIEW_STATUS_BAR"] = 0xE801;
		g_menu_id_map["ID_VIEW_REBAR"] = 0xE804;
		g_menu_id_map["ID_VIEW_AUTOARRANGE"] = 0xE805;
		// E810 -> E81F must be kept in order for RANGE macros
		g_menu_id_map["ID_VIEW_SMALLICON"] = 0xE810;
		g_menu_id_map["ID_VIEW_LARGEICON"] = 0xE811;
		g_menu_id_map["ID_VIEW_LIST"] = 0xE812;
		g_menu_id_map["ID_VIEW_DETAILS"] = 0xE813;
		g_menu_id_map["ID_VIEW_LINEUP"] = 0xE814;
		g_menu_id_map["ID_VIEW_BYNAME"] = 0xE815;
		g_menu_id_map["FX_ID_VIEW_MINIMUM"] = ID_VIEW_SMALLICON;
		g_menu_id_map["AFX_ID_VIEW_MAXIMUM"] = ID_VIEW_BYNAME;
		// E800 -> E8FF reserved for other control bar commands
	
		// RecordForm commands
		g_menu_id_map["ID_RECORD_FIRST"] = 0xE900;
		g_menu_id_map["ID_RECORD_LAST"] = 0xE901;
		g_menu_id_map["ID_RECORD_NEXT"] = 0xE902;
		g_menu_id_map["ID_RECORD_PREV"] = 0xE903;
	}
}

CMenu::~CMenu()
{
	
}

BOOL CMenu::AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, LPCTSTR lpszNewItem)
{
	assert(m_NMenu || m_owner);

	
	return TRUE;
}

BOOL CMenu::AppendMenu(UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp)
{
     qDebug() << "TO DO CMenu::AppendMenu";
	return TRUE;
}

BOOL CMenu::InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem, LPCTSTR lpszNewItem)
{
     qDebug() << "TO DO CMenu::InsertMenu";
	return TRUE;
}

BOOL CMenu::InsertMenu(UINT nPosition, UINT nFlags, UINT_PTR nIDNewItem, const CBitmap* pBmp)
{
     qDebug() << "TO DO CMenu::InsertMenu";
	return TRUE;
}

BOOL CMenu::MenuParser(void *currentMenuVoid, void *rootMenuNodeVoid)
{
    /*
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
			else
			if (attrStrID)
			{
				std::map<std::string, long>::iterator it;
								
				it = g_menu_id_map.find([[attrStrID stringValue] UTF8String]);
				
				if (it != g_menu_id_map.end())
				{
					[menuItem setTag: it->second];
					[menuItem setTarget:pMainAppCocoa];
					[menuItem setAction:@selector(menuEventHandle:)];
				}
				else 
				{
					NSLog(@"Cannot find ID for menu item");
				}
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
    */
	return TRUE;
}

BOOL CMenu::LoadMenu(LPCTSTR lpszResourceName)
{
	BOOL res = FALSE;
	
    /*
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
    */
	return res;
}

BOOL CMenu::LoadMenu(UINT nIDResource)
{
    //NSString *str = [NSString stringWithFormat: @"%d", nIDResource];
	
    //return LoadMenu([str UTF8String]);
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

