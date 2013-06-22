//
//  MyDocument.m
//  ConvertorResToXml
//
//  Created by Dmitry Mikhaevich on 11/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "MyDocument.h"

#define WIN_DPI_TO_MAC_X 1.55//(96.0/72.0)
#define WIN_DPI_TO_MAC_Y 1.7//(96.0/72.0)

@implementation MyDocument

- (id)init
{
    self = [super init];
    if (self) {
    
        // Add your subclass-specific initialization here.
        // If an error occurs here, send a [self release] message and return nil.
    
    }
    return self;
}

- (NSString *)windowNibName
{
    // Override returning the nib file name of the document
    // If you need to use a subclass of NSWindowController or if your document supports multiple NSWindowControllers, you should remove this method and override -makeWindowControllers instead.
    return @"MyDocument";
}

- (void)shouldCloseWindowController:(NSWindowController *)windowController delegate:(id)delegate shouldCloseSelector:(SEL)shouldCloseSelector contextInfo:(void *)contextInfo
{
	NSURL *urlResFile = [pathControl URL];
	NSURL *urlOutputFile = [pathOutputControl URL];
	NSURL *urlHeaderFile = [pathResHControl URL];
	
	NSXMLElement *root = [NSXMLNode  elementWithName: @"root"];	
	NSXMLDocument *doc = [NSXMLDocument documentWithRootElement: root];
	
	NSXMLElement *elResFile = [NSXMLNode elementWithName:@"urlResFile" stringValue: [urlResFile path]];
	[root addChild: elResFile];
	
	NSXMLElement *elOutputFile = [NSXMLNode elementWithName:@"urlOutputFile" stringValue: [urlOutputFile path]];
	[root addChild: elOutputFile];
	
	NSXMLElement *elHeaderFile = [NSXMLNode elementWithName:@"urlHeaderFile" stringValue: [urlHeaderFile path]];
	[root addChild: elHeaderFile];
	
	NSData *data = [doc XMLData];
		
	NSFileManager *fm = [NSFileManager defaultManager];
	NSString *currentpath;
	
	currentpath = [fm currentDirectoryPath];
	currentpath = [currentpath stringByAppendingPathComponent:@"pref.xml"];
	
	[data writeToFile:currentpath atomically:false];
}

- (void)windowControllerDidLoadNib:(NSWindowController *) aController
{
    [super windowControllerDidLoadNib:aController];
    // Add any code here that needs to be executed once the windowController has loaded the document's window.
	
	NSFileManager *fm = [NSFileManager defaultManager];
	NSString *currentpath;
	
	currentpath = [fm currentDirectoryPath];
	currentpath = [currentpath stringByAppendingPathComponent:@"pref.xml"];
	
	if ([fm fileExistsAtPath:currentpath])
	{
	 
		NSXMLDocument *doc = [[NSXMLDocument alloc] initWithContentsOfURL:[NSURL fileURLWithPath: currentpath] 
														  options:NSXMLNodeOptionsNone  error:nil];
		
		if (doc)
		{
			NSXMLElement *root = [doc rootElement];		
			
			NSArray *arr = [root elementsForName:@"urlResFile"];
			
			if ([arr count])
			{
				NSXMLElement *elResFile = [arr objectAtIndex: 0];
				
				[pathControl setURL: [NSURL fileURLWithPath:[elResFile stringValue]]];
				
				
			}
			
			arr = [root elementsForName:@"urlOutputFile"];
			
			if ([arr count])
			{
				NSXMLElement *elResFile = [arr objectAtIndex: 0];
				
				[pathOutputControl setURL: [NSURL fileURLWithPath:[elResFile stringValue]]];				
			}
			
			arr = [root elementsForName:@"urlHeaderFile"];
			
			if ([arr count])
			{
				NSXMLElement *elResFile = [arr objectAtIndex: 0];
				
				[pathResHControl setURL: [NSURL fileURLWithPath:[elResFile stringValue]]];				
			}
			
			 [doc release];
		}
	}
}

- (NSData *)dataOfType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to write your document to data of the specified type. If the given outError != NULL, ensure that you set *outError when returning nil.

    // You can also choose to override -fileWrapperOfType:error:, -writeToURL:ofType:error:, or -writeToURL:ofType:forSaveOperation:originalContentsURL:error: instead.

    // For applications targeted for Panther or earlier systems, you should use the deprecated API -dataRepresentationOfType:. In this case you can also choose to override -fileWrapperRepresentationOfType: or -writeToFile:ofType: instead.

    if ( outError != NULL ) {
		*outError = [NSError errorWithDomain:NSOSStatusErrorDomain code:unimpErr userInfo:NULL];
	}
	return nil;
}

- (BOOL)readFromData:(NSData *)data ofType:(NSString *)typeName error:(NSError **)outError
{
    // Insert code here to read your document from the given data of the specified type.  If the given outError != NULL, ensure that you set *outError when returning NO.

    // You can also choose to override -readFromFileWrapper:ofType:error: or -readFromURL:ofType:error: instead. 
    
    // For applications targeted for Panther or earlier systems, you should use the deprecated API -loadDataRepresentation:ofType. In this case you can also choose to override -readFromFile:ofType: or -loadFileWrapperRepresentation:ofType: instead.
    
    if ( outError != NULL ) {
		*outError = [NSError errorWithDomain:NSOSStatusErrorDomain code:unimpErr userInfo:NULL];
	}
    return YES;
}

- (IBAction)browserButton:(id)sender
{
	NSOpenPanel *openDialog = [NSOpenPanel openPanel];
	
	[openDialog setCanChooseDirectories:false];
	[openDialog setCanChooseFiles:true];
	[openDialog setAllowsMultipleSelection:false];
	
	//[openDialog setDirectoryURL:[pathControl URL]];
	//[openDialog setNameFieldStringValue: @"Resources.xml"];
	
	if ([openDialog runModal] == NSFileHandlingPanelOKButton)
	{
		NSURL *url = [openDialog URL];
		
		[pathControl setURL:url];
		
		NSString *path = [url path];
		
		[pathOutputControl setURL: [[url URLByDeletingLastPathComponent]URLByAppendingPathComponent: @"Resources.xml"] ];
		[pathResHControl setURL:[NSURL fileURLWithPath:[[path stringByDeletingLastPathComponent] stringByAppendingPathComponent: @"Resource.h"]]];
	}
}

- (IBAction)browserResHButton:(id)sender
{
	NSOpenPanel *openDialog = [NSOpenPanel openPanel];
	
	[openDialog setCanChooseDirectories:false];
	[openDialog setCanChooseFiles:true];
	[openDialog setAllowsMultipleSelection:false];
	
	if ([openDialog runModal] == NSFileHandlingPanelOKButton)
	{
		[pathResHControl setURL:[openDialog URL]];
	}
}

- (IBAction)browserOutputButton:(id)sender
{
	NSSavePanel *saveDialog = [NSSavePanel savePanel];
	
	//[saveDialog setCanChooseDirectories:true];
	//[saveDialog setCanChooseFiles:true];
	//[saveDialog setAllowsMultipleSelection:false];
	
	[saveDialog setDirectoryURL:[pathOutputControl URL]];
	[saveDialog setNameFieldStringValue: @"Resources.xml"];
	
	if ([saveDialog runModal] == NSFileHandlingPanelOKButton)
	{
		[pathOutputControl setURL:[saveDialog URL]];
	}
}

- (void)createIdMap
{
	NSFileManager *fm = [NSFileManager defaultManager];
	NSURL *urlResHFile = [pathResHControl URL];
	
	m_map_id.clear();
	
	if ([fm fileExistsAtPath: [urlResHFile path]])
	{
		NSError *error = nil;
		NSString *strResH = [NSString stringWithContentsOfFile:[urlResHFile path] 
													 encoding:NSISOLatin1StringEncoding error: &error];
		NSArray *strResHLines = [strResH componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"\n\r"]];
		
		for(int i = 0; strResHLines && i < [strResHLines count]; i++)
		{
			NSRange findPos;
			NSString *line = [strResHLines objectAtIndex:i];
			
			if ((findPos = [line rangeOfString:@"#define"]).location != NSNotFound)
			{
				NSArray *strLineComponents = [line  componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@" \n\r\t"]];
				int index = 0;
				NSString *strStrID = nil;
				NSString *strID = nil;
				
				for(int n = 0; strLineComponents && n < [strLineComponents count]; n++)
				{
					NSString *lineComponent = [strLineComponents objectAtIndex:n];
					
					if ([lineComponent length] != 0)
					{
						index++;
						
						if (index == 2)
						{
							strStrID = [NSString stringWithFormat: @"%@", lineComponent];
						}
						
						if (index == 3)
						{
							strID = [NSString stringWithFormat: @"%@", lineComponent];
							
							break;
						}
					}
				}	
				
				if (strStrID && strID)
				{
					if ((findPos = [strID rangeOfString:@"0x"]).location != NSNotFound)
					{
						unsigned int value = 0;
						NSScanner *scanHex = [NSScanner scannerWithString: strID];// scanHexInt:
						
						[scanHex scanHexInt: &value];
						
						strID = [NSString stringWithFormat: @"%d", value];
					}
					
					NSLog([NSString stringWithFormat: @"name=\"%@\" id=\"%@\"", strStrID, strID]);
					m_map_id[[strStrID UTF8String]] = [strID UTF8String];
				}
			}
		}
	}
	else 
	{
		[logControl setStringValue: @"reh H file doest exists\n"];
	}
}

- (NSString *)getID:(NSString *)strStrID
{
	std::map<std::string,std::string>::iterator it;
	
	it = m_map_id.find([strStrID UTF8String]);
	
	if (it != m_map_id.end())
	{
		return [NSString stringWithFormat: @"%s", it->second.c_str()];
	}
	
	return nil;
}

-(int)AddBitmaps:(NSArray *)strLines root:(NSXMLElement *)root bitmapTableNode:(NSXMLElement *)bitmapTableNode index:(int)i findPos:(NSRange)findPos
{
	//IDB_BITMAP1             BITMAP                  "J:\\MFC2Mac\\MFC2Cocao\\SimpleDialog2\\bitmap1.bmp"					
	NSString *strLine = [strLines objectAtIndex:i];
	
	if (bitmapTableNode == nil)
	{
		bitmapTableNode = [NSXMLNode elementWithName:@"BITMAPTABLE"];
		[root addChild:bitmapTableNode];					
	}
	
	if (bitmapTableNode)
	{
		NSArray *arrProperties = [strLine componentsSeparatedByCharactersInSet:
								  [NSCharacterSet characterSetWithCharactersInString:@" \t\n\r"]];
		
		NSString *strSTRID	= nil;//[arrProperties objectAtIndex:0];
		NSString *strBITMAP = nil;//[arrProperties objectAtIndex:1];
		NSString *strPATH	= nil;//[arrProperties objectAtIndex:2];
		int count = 0;
		
		for(int ii = 0; ii < [arrProperties count]; ii++)
		{
			if ([[arrProperties objectAtIndex:ii] length])
			{
				if (count == 0)
				{
					strSTRID	= [arrProperties objectAtIndex:ii];
				}
				else 
					if (count == 1)
					{
						strBITMAP	= [arrProperties objectAtIndex:ii];
					}
					else 
						if (count == 2)
						{
							strPATH	= [arrProperties objectAtIndex:ii];
						}
				
				count++;
			}
		}
		
		if (strSTRID && strBITMAP && strPATH &&
			[strSTRID length] && [strBITMAP length] && [strPATH length])
		{
			NSXMLElement *bitmapNode = [NSXMLNode elementWithName:@"BITMAP"];
			
			[bitmapTableNode addChild:bitmapNode];
			
			[bitmapNode addAttribute:[NSXMLNode attributeWithName:@"IDSTR" stringValue:strSTRID]];
			
			NSString *strID = [self getID: strSTRID];
			
			if (strID)
			{
				[bitmapNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
			}
			
			strPATH = [strPATH stringByReplacingOccurrencesOfString:@"\\\\" withString:@"/"];
			strPATH = [strPATH stringByReplacingOccurrencesOfString:@"\"" withString:@""];
			
			[bitmapNode addAttribute:[NSXMLNode attributeWithName:@"NAME" stringValue:[strPATH lastPathComponent]]];
		}
	}
	
	return i;
}

-(int)AddStrings:(NSArray *)strLines root:(NSXMLElement *)root stringTableNode:(NSXMLElement *)stringTableNode index:(int)i findPos:(NSRange)findPos
{
	//STRINGTABLE
	//BEGIN
	//IDS_ABOUTBOX            "&About SimpleDialog2..."
	//END
	
	if ([strLines count] < i)
	{
		return i++;
	}
	
	if (stringTableNode == nil)
	{
		stringTableNode = [NSXMLNode elementWithName:@"STRINGTABLE"];
		[root addChild:stringTableNode];
	}
	
	if (stringTableNode)
	{
		//<STRINGTABLE>
		//<STR ID="101" IDSTR="IDS_ABOUTBOX">About SimpleDialog2...</STR>
		//<STR ID="102" IDSTR="IDS_STRING102">test1</STR>
		//<STR ID="103" IDSTR="IDS_STRING103">test2</STR>
		//<STR ID="104" IDSTR="IDS_STRING104">test3</STR>
		//</STRINGTABLE>
		
		NSLog(@"%@", [strLines objectAtIndex:i]);
		
		//strings
		while(i < [strLines count] &&
			  ([[strLines objectAtIndex:i] rangeOfString:@"BEGIN"]).location == NSNotFound)
		{
			NSLog(@"%@", [strLines objectAtIndex:i]);
			i++;								
		}
		
		i++;
		
		//strings
		while(i < [strLines count] &&
			  ([[strLines objectAtIndex:i] rangeOfString:@"END"]).location == NSNotFound)
		{
			if ([strLines count] < i)
			{
				return i++;
			}
			
			NSString *strStringLine = [strLines objectAtIndex:i];
			
			if ([strStringLine length] == 0)
			{
				i++;
				continue;
			}
			
			NSRange aRangeStart;
			NSRange aRangeStartId;
			
			while([strStringLine characterAtIndex: 0] == ' ')
			{
				aRangeStart.location = 1;
				aRangeStart.length = [strStringLine length] - 1;
				strStringLine = [strStringLine substringWithRange: aRangeStart];
			}
			
			aRangeStartId = [strStringLine rangeOfString:@" "];
			
			aRangeStart.location = aRangeStartId.location + 1;
			aRangeStart.length = ([strStringLine length] - aRangeStartId.location) - 1;
			
			aRangeStartId.length = aRangeStartId.location;
			aRangeStartId.location = 0;
			
			NSString *strSTRID = [strStringLine substringWithRange:aRangeStartId];
			NSString *strText = [strStringLine substringWithRange:aRangeStart];
			
			if ([strText length] == 0)
			{
				i++;
				continue;
			}
			
			NSLog(@"strText=%@", strText);
			
			while([strText characterAtIndex: 0] != '"')
			{
				aRangeStart.location = 1;
				aRangeStart.length = [strText length] - 1;
				strText = [strText substringWithRange: aRangeStart];
				
				if ([strText length] == 0)
				{
					break;
				}
			}
			
			NSLog(@"strText=%@", strText);
			
			if ([strText length] == 0)
			{
				i++;
				continue;
			}
			
			while([strText characterAtIndex: [strText length] - 1] != '"')
			{
				aRangeStart.location = 0;
				aRangeStart.length = [strText length] - 2;
				strText = [strText substringWithRange: aRangeStart];
			}
			
			strText = [strText stringByReplacingOccurrencesOfString:@"\"" withString:@""];
			
			NSXMLElement *strNode = [NSXMLNode elementWithName:@"STR"];
			
			strSTRID = [strSTRID stringByReplacingOccurrencesOfString:@" " withString:@""];
			strSTRID = [strSTRID stringByReplacingOccurrencesOfString:@"\t" withString:@""];
			
			[strNode addAttribute:[NSXMLNode attributeWithName:@"IDSTR" stringValue:strSTRID]];
			[strNode setStringValue: strText];
			
			[stringTableNode addChild:strNode];
			
			NSString *strID = [self getID: strSTRID];
			
			if (strID)
			{
				[strNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
			}
			
			i++;
		}
		
		i++;
	}
	
	return i;
}

-(int)AddIcon:(NSArray *)strLines root:(NSXMLElement *)root iconTableNode:(NSXMLElement *)iconTableNode index:(int)i findPos:(NSRange)findPos
{
	//IDR_MAINFRAME           ICON                    "res\\SimpleDialog2.ico"
	
	NSString *strLine = [strLines objectAtIndex:i];
	
	if (iconTableNode == nil)
	{
		iconTableNode = [NSXMLNode elementWithName:@"ICONTABLE"];
		[root addChild:iconTableNode];					
	}
	
	if (iconTableNode)
	{
		NSArray *arrProperties = [strLine componentsSeparatedByCharactersInSet:
								  [NSCharacterSet characterSetWithCharactersInString:@" \t\n\r"]];
		
		NSString *strSTRID	= nil;//[arrProperties objectAtIndex:0];
		NSString *strICON = nil;//[arrProperties objectAtIndex:1];
		NSString *strPATH	= nil;//[arrProperties objectAtIndex:2];
		int count = 0;
		
		for(int ii = 0; ii < [arrProperties count]; ii++)
		{
			if ([[arrProperties objectAtIndex:ii] length])
			{
				if (count == 0)
				{
					strSTRID	= [arrProperties objectAtIndex:ii];
				}
				else 
					if (count == 1)
					{
						strICON	= [arrProperties objectAtIndex:ii];
					}
					else 
						if (count == 2)
						{
							strPATH	= [arrProperties objectAtIndex:ii];
						}
				
				count++;
			}
		}
		
		if (strSTRID && strICON && strPATH &&
			[strSTRID length] && [strICON length] && [strPATH length])
		{
			NSXMLElement *iconNode = [NSXMLNode elementWithName:@"ICON"];
			
			[iconTableNode addChild:iconNode];
			
			[iconNode addAttribute:[NSXMLNode attributeWithName:@"IDSTR" stringValue:strSTRID]];
			
			NSString *strID = [self getID: strSTRID];
			
			if (strID)
			{
				[iconNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
			}
			
			strPATH = [strPATH stringByReplacingOccurrencesOfString:@"\\\\" withString:@"/"];
			strPATH = [strPATH stringByReplacingOccurrencesOfString:@"\"" withString:@""];
			
			[iconNode addAttribute:[NSXMLNode attributeWithName:@"NAME" stringValue:[strPATH lastPathComponent]]];
		}
	}
	
	return i;
}

-(int)AddAccelerators:(NSArray *)strLines root:(NSXMLElement *)root index:(int)i findPos:(NSRange)findPos
{
	//IDR_MAINFRAME ACCELERATORS PRELOAD MOVEABLE PURE 
	//BEGIN
    //"N",            ID_FILE_NEW,            VIRTKEY, CONTROL
    //"O",            ID_FILE_OPEN,           VIRTKEY, CONTROL
    //VK_BACK,        ID_EDIT_UNDO,           VIRTKEY, ALT
	//VK_DELETE,      ID_EDIT_CUT,            VIRTKEY, SHIFT
    //VK_INSERT,      ID_EDIT_COPY,           VIRTKEY, CONTROL
    //VK_INSERT,      ID_EDIT_PASTE,          VIRTKEY, SHIFT
    //VK_F6,          ID_NEXT_PANE,           VIRTKEY 
    //VK_F6,          ID_PREV_PANE,           VIRTKEY, SHIFT
	//END
	
	NSXMLElement *KeyTableNode = nil;
	
	KeyTableNode = [NSXMLNode elementWithName:@"ACCELERATORS"];
	[root addChild:KeyTableNode];
	
	i++;
	
	//optional-statements
	while(i < [strLines count] &&
		  ([[strLines objectAtIndex:i] rangeOfString:@"END"]).location == NSNotFound)
	{
		NSString *line = [strLines objectAtIndex:i];
		
		if ((findPos = [line rangeOfString:@"BEGIN"]).location == NSNotFound &&
			(findPos = [line rangeOfString:@"END"]).location == NSNotFound &&
			[line length])
		{			
			NSArray *strKeyAttrLines = [line componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@", \t"]];
			
			if ([strKeyAttrLines count])
			{			
				NSXMLElement *KeyNode = nil;
				KeyNode = [NSXMLNode elementWithName:@"ITEM"];
				int indexItem = 0;
				
				for(int i = 0; i < [strKeyAttrLines count]; i++)
				{
					NSString *strItem = [strKeyAttrLines objectAtIndex:i];
					
					if (strItem &&
						[strItem length])
					{
						strItem = [strItem stringByReplacingOccurrencesOfString:@" " withString:@""];
						strItem = [strItem stringByReplacingOccurrencesOfString:@"\t" withString:@""];
						
						if (indexItem == 0)
						{
							[KeyNode addAttribute:[NSXMLNode attributeWithName:@"Key" stringValue:strItem]];
						}
						else
						if (indexItem == 1)
						{
							[KeyNode addAttribute:[NSXMLNode attributeWithName:@"StrID" stringValue:strItem]];
							
							NSString *strID = [self getID: strItem];
														
							if (strID)
							{
								[KeyNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
							}
						}
						else
						if (indexItem == 2)
						{
							[KeyNode addAttribute:[NSXMLNode attributeWithName:@"KeySys1" stringValue:strItem]];
						}
						else
						if (indexItem == 3)
						{
							[KeyNode addAttribute:[NSXMLNode attributeWithName:@"KeySys2" stringValue:strItem]];
						}
						else
						if (indexItem == 4)
						{
							[KeyNode addAttribute:[NSXMLNode attributeWithName:@"KeySys3" stringValue:strItem]];
						}
						
						indexItem++;
					}
				}
				
				[KeyTableNode addChild:KeyNode];
			}
		}
		
		i++;
	}
	
	i++;
	
	return i;
}

-(int)AddMenu:(NSArray *)strLines root:(NSXMLElement *)root index:(int)i findPos:(NSRange)findPos
{
	//IDR_MAINFRAME MENU PRELOAD DISCARDABLE 
	//BEGIN
    //POPUP "&File"
    //BEGIN
	//MENUITEM "E&xit",                       ID_APP_EXIT
    //END
    //POPUP "&View"
    //BEGIN
	//MENUITEM "&Combo Dialog...",            ID_VIEW_COMBO_DIALOG
	//MENUITEM SEPARATOR
	//MENUITEM "&Toolbar",                    ID_VIEW_TOOLBAR
	//MENUITEM "&Status Bar",                 ID_VIEW_STATUS_BAR
    //END
    //POPUP "&Help"
    //BEGIN
	//MENUITEM "&About ComboWizard...",       ID_APP_ABOUT
    //END
	//END
	
	NSXMLElement *MenuTableNode = nil;
	NSArray *strMenuAttrLines = [[strLines objectAtIndex:i]  componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@" \t"]];
	
	MenuTableNode = [NSXMLNode elementWithName:@"MENU"];
	[root addChild:MenuTableNode];
	
	if ([strMenuAttrLines count])
	{
		NSString *idMenu = [strMenuAttrLines objectAtIndex: 0];
		[MenuTableNode addAttribute:[NSXMLNode attributeWithName:@"IDSTR" stringValue:idMenu]];
		
		NSString *strID = [self getID: idMenu];
		
		if (strID)
		{
			[MenuTableNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
		}
	}
	
	NSLog([strLines objectAtIndex:i]);
	
	i++;
	
	while(i < [strLines count] &&
		  ([[strLines objectAtIndex:i] rangeOfString:@"END"]).location == NSNotFound)
	{
		NSString *line = [strLines objectAtIndex:i];
		
		NSLog(line);
		
		if ((findPos = [line rangeOfString:@"POPUP"]).location != NSNotFound)
		{	
			findPos = [line rangeOfString:@"\""];
			NSString *strName = [line substringFromIndex:findPos.location + 1];
			
			findPos = [strName rangeOfString:@"\""];
			strName = [strName substringToIndex:findPos.location];
			
			NSXMLElement *popupNode = nil;
			popupNode = [NSXMLNode elementWithName:@"POPUP"];
			[MenuTableNode addChild:popupNode];
			
			[popupNode addAttribute:[NSXMLNode attributeWithName:@"Name" stringValue:strName]];
			
			i++;		
			
			while(i < [strLines count] &&
				  ([[strLines objectAtIndex:i] rangeOfString:@"END"]).location == NSNotFound)
			{
				NSString *line = [strLines objectAtIndex:i];
				
				NSLog(line);
				
				if ((findPos = [line rangeOfString:@"MENUITEM"]).location != NSNotFound)
				{					
					NSString *nameMenuItem = [NSString stringWithUTF8String: "MENUITEM"];
					
					if ((findPos = [line rangeOfString:@"SEPARATOR"]).location != NSNotFound)
					{
						nameMenuItem = [NSString stringWithUTF8String: "SEPARATOR"];
					}
					
					NSXMLElement *menuItemNode = nil;
					menuItemNode = [NSXMLNode elementWithName:nameMenuItem];
					[popupNode addChild:menuItemNode];
					
					findPos = [line rangeOfString:@"\""];
					
					if (findPos.location != NSNotFound)
					{
						strName = [line substringFromIndex:findPos.location + 1];
						
						findPos = [strName rangeOfString:@"\""];
						strName = [strName substringToIndex:findPos.location];
						
						[menuItemNode addAttribute:[NSXMLNode attributeWithName:@"Name" stringValue:strName]];
					}
					
					findPos = [line rangeOfString:@"\","];
					
					if (findPos.location != NSNotFound)
					{
						NSString *strID = [line substringFromIndex:findPos.location + 2];
						strID = [strID stringByReplacingOccurrencesOfString:@" " withString:@""];
						strID = [strID stringByReplacingOccurrencesOfString:@"\t" withString:@""];
						strID = [strID stringByReplacingOccurrencesOfString:@"\n" withString:@""];
						strID = [strID stringByReplacingOccurrencesOfString:@"\r" withString:@""];
						
						[menuItemNode addAttribute:[NSXMLNode attributeWithName:@"IDSTR" stringValue:strID]];
						
						strID = [self getID: strID];
						 
						if (strID)
						{
							[menuItemNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
						}
					}
				}
				
				i++;
			}
		}
		
		i++;
	}
	
	i++;
	
	return i;
}

-(int)AddToolBar:(NSArray *)strLines root:(NSXMLElement *)root index:(int)i findPos:(NSRange)findPos
{
	//IDR_MAINFRAME TOOLBAR DISCARDABLE  16, 15
	//BEGIN
    //BUTTON      ID_FILE_NEW
    //BUTTON      ID_FILE_OPEN
    //BUTTON      ID_FILE_SAVE
    //SEPARATOR
    //BUTTON      ID_EDIT_CUT
	//END
	
	NSXMLElement *toolBarNode = nil;
	NSArray *strToolAttrLines = [[strLines objectAtIndex:i]  componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@" \t"]];
	
	toolBarNode = [NSXMLNode elementWithName:@"TOOLBAR"];
	[root addChild:toolBarNode];
	
	NSArray *strToolBarAttrLines = [[strLines objectAtIndex:i]  componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@", \t"]];
	int indexAdd = 0;
	
	if ([strToolAttrLines count])
	{
		NSString *idTool = [strToolAttrLines objectAtIndex: 0];
		[toolBarNode addAttribute:[NSXMLNode attributeWithName:@"IDSTR" stringValue:idTool]];
		
		NSString *strID = [self getID: idTool];
		
		if (strID)
		{
			[toolBarNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
		}
	}
	
	for(int n = 0; n < [strToolBarAttrLines count]; n++)
	{
		NSString *line = [strToolBarAttrLines objectAtIndex:n];
		
		if ([line rangeOfString:@"DISCARDABLE"].location != NSNotFound)
		{
			indexAdd++;
		}
		
		if ([line length] == 0)
		{
			indexAdd++;
			continue;
		}
		
		if (n == 0)//ID
		{
			NSXMLElement *IDSTRNode = nil;
			IDSTRNode = [NSXMLNode elementWithName:@"IDSTR"];
			line = [line stringByReplacingOccurrencesOfString:@" " withString:@""];
			[IDSTRNode setStringValue: line];
			[toolBarNode addChild:IDSTRNode];
			
			NSString *strID = [self getID: line];
			
			if (strID)
			{
				NSXMLElement *IDNode = nil;
				IDNode = [NSXMLNode elementWithName:@"ID"];
				[IDNode setStringValue: strID];
				[toolBarNode addChild:IDNode];
			}
		}
		else
			if (n == 2 + indexAdd)//x
			{
				NSXMLElement *IDSTRNode = nil;
				IDSTRNode = [NSXMLNode elementWithName:@"X"];
				line = [line stringByReplacingOccurrencesOfString:@" " withString:@""];
				[IDSTRNode setStringValue: line];
				[toolBarNode addChild:IDSTRNode];
			}
			else
				if (n == 3 + indexAdd)//y
				{
					NSXMLElement *IDSTRNode = nil;
					IDSTRNode = [NSXMLNode elementWithName:@"Y"];
					line = [line stringByReplacingOccurrencesOfString:@" " withString:@""];
					[IDSTRNode setStringValue: line];
					[toolBarNode addChild:IDSTRNode];
				}
	}
	
	//optional-statements
	while(i < [strLines count] &&
		  ([[strLines objectAtIndex:i] rangeOfString:@"END"]).location == NSNotFound)
	{
		NSString *line = [strLines objectAtIndex:i];
		
		if ((findPos = [line rangeOfString:@"BUTTON"]).location != NSNotFound)
		{
			NSXMLElement *BUTTONNode = nil;
			BUTTONNode = [NSXMLNode elementWithName:@"BUTTON"];
			
			
			findPos.location = findPos.location + strlen("BUTTON");
			findPos.length = [line length] - findPos.location;
			NSString *strVal = [line substringWithRange:findPos];
			strVal = [strVal stringByReplacingOccurrencesOfString:@" " withString:@""];
			strVal = [strVal stringByReplacingOccurrencesOfString:@"\t" withString:@""];
			
			[BUTTONNode addAttribute:[NSXMLNode attributeWithName:@"strID" stringValue:strVal]];
			
			NSString *strID = [self getID: strVal];
			
			if (strID)
			{
				[BUTTONNode addAttribute:[NSXMLNode attributeWithName:@"ID" stringValue:strID]];
			}
			
			[toolBarNode addChild:BUTTONNode];
		}
		else
			if ((findPos = [line rangeOfString:@"SEPARATOR"]).location != NSNotFound)
			{
				NSXMLElement *SEPARATORNode = nil;
				SEPARATORNode = [NSXMLNode elementWithName:@"SEPARATOR"];
				[toolBarNode addChild:SEPARATORNode];
			}
		
		i++;
	}
	
	i++;
	
	return i;
}

- (IBAction)convertButton:(id)sender
{
	NSFileManager *fm = [NSFileManager defaultManager];
	NSURL *source = [pathControl URL];
	NSURL *output = [pathOutputControl URL];
	//BOOL isDirectory = false;
	
	[logControl setStringValue: @"Start convert\n"];
	
	if ([fm fileExistsAtPath: [source path]])
	{
		[self createIdMap];
		
		NSError *error = nil;
		NSString *strRes = [NSString stringWithContentsOfFile:[source path] 
													 encoding:NSISOLatin1StringEncoding error: &error];
		
		//NSString *sourceName = [[source path] lastPathComponent];		
		//NSString *outputName = [sourceName stringByReplacingOccurrencesOfString:@".rc" withString:@".xml"];
		
		NSXMLElement *root = [NSXMLNode elementWithName:@"MFC_RESOURCE"];
		NSXMLDocument *doc = [[NSXMLDocument alloc] initWithRootElement:root];
		NSXMLElement *stringTableNode = nil;
		NSXMLElement *bitmapTableNode = nil;
		NSXMLElement *iconTableNode = nil;
		
		[doc setCharacterEncoding:@"UTF-8"];
		[doc setVersion:@"1.0"];
	
		if (strRes)
		{
			NSArray *strLines = [strRes componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"\n\r"]];
			
			for(int i = 0; strLines && i < [strLines count]; i++)
			{
				NSRange findPos;
				NSString *strResLine = [strLines objectAtIndex:i];
				
				NSLog(strResLine);
				 
				if ((findPos = [strResLine rangeOfString:@"GUIDELINES"]).location == 0)//skip
				{
					//strings
					while(i < [strLines count] &&
						  ([[strLines objectAtIndex:i] rangeOfString:@"END"]).location != 0)
					{
						NSLog(@"%@", [strLines objectAtIndex:i]);
						i++;								
					}					
				}//GUIDELINES
				else
				if ((findPos = [strResLine rangeOfString:@" DIALOGEX "]).location != NSNotFound ||
					(findPos = [strResLine rangeOfString:@" DIALOG "]).location != NSNotFound)//dialog
				{
					//nameID DIALOGEX x, y, width, height [ , helpID] [optional-statements]  {control-statements}
					//nameID DIALOG x, y, width, height  [optional-statements] {control-statement  . . . }
					//IDD_SIMPLEDIALOG2_DIALOG DIALOGEX  0, 0, 320, 200
					//STYLE DS_SHELLFONT | WS_POPUP | WS_VISIBLE | WS_CAPTION
					//| WS_THICKFRAME
					//| WS_SYSMENU
					//EXSTYLE WS_EX_APPWINDOW
					//CAPTION "SimpleDialog2"
					//FONT 8, "MS Shell Dlg"
					//BEGIN
					//END
					
					
					NSXMLElement *dialogNode = nil;
					
					if ((findPos = [strResLine rangeOfString:@"DIALOGEX"]).location != NSNotFound)
					{
						dialogNode = [NSXMLNode elementWithName:@"DIALOGEX"];
					}
					else 
					{
						dialogNode = [NSXMLNode elementWithName:@"DIALOG"];						
					}

					
					[root addChild:dialogNode];
					
					NSArray *strDialogAttrLines = [[strLines objectAtIndex:i]  componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@" \t"]];
					
					int indexAdd = 0;
					
					for(int n = 0; n < [strDialogAttrLines count]; n++)
					{
						NSString *line = [strDialogAttrLines objectAtIndex:n];
						
						if ([line rangeOfString:@"DISCARDABLE"].location != NSNotFound)
						{
							indexAdd++;
						}
						
						if ([line length] == 0)
						{
							indexAdd++;
						}
						
						if (n == 0)//nameID
						{
							NSXMLElement *IDSTRNode = nil;
							IDSTRNode = [NSXMLNode elementWithName:@"IDSTR"];
							line = [line stringByReplacingOccurrencesOfString:@" " withString:@""];
							[IDSTRNode setStringValue: line];
							[dialogNode addChild:IDSTRNode];
							
							NSString *strID = [self getID: line];
							
							if (strID)
							{
								NSXMLElement *IDNode = nil;
								IDNode = [NSXMLNode elementWithName:@"ID"];
								[IDNode setStringValue: strID];
								[dialogNode addChild:IDNode];
							}
						}
						else
						if (n == 1)//DIALOGEX
						{
							
						}
						else
						if (n == 2 + indexAdd)//x, y, width, height
						{
							NSXMLElement *BOXNode = nil;
							BOXNode = [NSXMLNode elementWithName:@"BOX"];
							
							double f_x = (double)([line intValue]) * WIN_DPI_TO_MAC_X;
							double f_y = (double)([[strDialogAttrLines objectAtIndex:n + 1] intValue]) * WIN_DPI_TO_MAC_Y;
							double f_width = (double)([[strDialogAttrLines objectAtIndex:n + 2] intValue]) * WIN_DPI_TO_MAC_X;
							double f_height = (double)([[strDialogAttrLines objectAtIndex:n + 3] intValue]) * WIN_DPI_TO_MAC_Y;
							
							//NSString *boxStr = [line stringByAppendingString: [strDialogAttrLines objectAtIndex:n + 1]];
							//boxStr = [boxStr stringByAppendingString: [strDialogAttrLines objectAtIndex:n + 2]];
							//boxStr = [boxStr stringByAppendingString: [strDialogAttrLines objectAtIndex:n + 3]];
							[BOXNode setStringValue: [NSString stringWithFormat:@"%d,%d,%d,%d", 
															(int)f_x, (int)f_y,
															(int)f_width, (int)f_height]];
							[dialogNode addChild:BOXNode];
						}
					}
					
					//optional-statements
					while(i < [strLines count] &&
						  ([[strLines objectAtIndex:i] rangeOfString:@"BEGIN"]).location == NSNotFound)
					{
						NSString *line = [strLines objectAtIndex:i];
						
						if ((findPos = [line rangeOfString:@"STYLE"]).location == 0)
						{
							NSXMLElement *STYLENode = nil;
							STYLENode = [NSXMLNode elementWithName:@"STYLE"];
							NSRange aRange = [line rangeOfString:@" "];
							aRange.length = [line length] - aRange.location;
							NSString *strVal = [line substringWithRange:aRange];
							[STYLENode setStringValue: strVal];
							[dialogNode addChild:STYLENode];
						}
						else
						if ((findPos = [line rangeOfString:@"EXSTYLE"]).location == 0)
						{
							NSXMLElement *EXSTYLENode = nil;
							EXSTYLENode = [NSXMLNode elementWithName:@"EXSTYLE"];
							NSRange aRange = [line rangeOfString:@" "];
							aRange.length = [line length] - aRange.location;
							NSString *strVal = [line substringWithRange:aRange];
							[EXSTYLENode setStringValue: strVal];
							[dialogNode addChild:EXSTYLENode];
						}
						else
						if ((findPos = [line rangeOfString:@"CAPTION"]).location == 0)
						{
							NSXMLElement *CAPTIONNode = nil;
							CAPTIONNode = [NSXMLNode elementWithName:@"CAPTION"];
							NSArray *strCAPTIONLines = [line  componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"\""]];
							[CAPTIONNode setStringValue: [strCAPTIONLines objectAtIndex:1]];
							[dialogNode addChild:CAPTIONNode];
						}
						else
						if ((findPos = [line rangeOfString:@"FONT"]).location == 0)
						{
							NSXMLElement *FONTNode = nil;
							FONTNode = [NSXMLNode elementWithName:@"FONT"];
							NSRange aRange = [line rangeOfString:@" "];
							aRange.length = [line length] - aRange.location;
							NSString *strVal = [line substringWithRange:aRange];
							[FONTNode setStringValue: strVal];
							[dialogNode addChild:FONTNode];
						}
						
						i++;
					}
					
					i++;
					
					//control-statements
					while(i < [strLines count] &&
						  ([[strLines objectAtIndex:i] rangeOfString:@"END"]).location == NSNotFound)
					{
						NSString *line = [strLines objectAtIndex:i];
						
						NSLog(line);
						
						//line = [line stringByReplacingOccurrencesOfString:@" " withString:@""];
						
						//NSLog(line);
						
						if ((findPos = [line rangeOfString:@"DEFPUSHBUTTON"]).location != NSNotFound ||
							(findPos = [line rangeOfString:@"PUSHBUTTON"]).location != NSNotFound ||
							(findPos = [line rangeOfString:@"CTEXT"]).location != NSNotFound ||
							(findPos = [line rangeOfString:@"LTEXT"]).location != NSNotFound ||
							(findPos = [line rangeOfString:@"GROUPBOX"]).location != NSNotFound)
						{
							//DEFPUSHBUTTON text, id, x, y, width, height [, style [, extended-style]]
							//PUSHBUTTON text, id, x, y, width, height [, style [, extended-style]]
							//CTEXT text, id, x, y, width, height [, style [, extended-style]] the default style is SS_CENTER | WS_GROUP
							//LTEXT text, id, x, y, width, height [, style [, extended-style]] the default style is SS_LEFT | WS_GROUP
							//GROUPBOX text, id, x, y, width, height [, style [, extended-style]]
															
							//CTEXT           "TODO: Place dialog controls here.",IDC_STATIC,10,96,300,8
							
							
							NSRange aRangeStart = {0, [line length]};
							NSRange aEndStart = {0, [line length]};
							
							while([line characterAtIndex: aRangeStart.location] == ' ')
							{
								aRangeStart = [line rangeOfString:@" " options:NSCaseInsensitiveSearch range:aRangeStart];	
								aRangeStart.location++; 
								aRangeStart.length = [line length] - aRangeStart.location;
							}
							
							aEndStart = [line rangeOfString:@" " options:NSCaseInsensitiveSearch range:aRangeStart];	
							
							aRangeStart.length = aEndStart.location - aRangeStart.location;
							
							NSString *strName = [line substringWithRange:aRangeStart];
							aRangeStart.location = aEndStart.location + 1;
							aRangeStart.length = [line length] - aRangeStart.location;
							NSString *strProperties =  [line substringWithRange:aRangeStart];
							
							
							NSXMLElement *controlNode = nil;
							
							strName = [strName stringByReplacingOccurrencesOfString:@" " withString:@""];
							strName = [strName stringByReplacingOccurrencesOfString:@"\t" withString:@""];
							
							controlNode = [NSXMLNode elementWithName: strName];
							
							if (controlNode)
							{
								[dialogNode addChild:controlNode];
								
								NSArray *arrProperties = [strProperties componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@","]];
								
								NSString *strPropertyVal = nil;									
								NSString *strStyles = nil;
								NSXMLElement *controlPropertyNode = nil; 
								
								if ([arrProperties count] > 0)
								{
									strPropertyVal = [arrProperties objectAtIndex:0];
									controlPropertyNode = [NSXMLNode elementWithName: @"TEXT"];
									
									[controlNode addChild:controlPropertyNode];
									
									NSArray *strPropertyValLines = [strPropertyVal  componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"\""]];
									
									if ([strPropertyValLines count] > 1)
									{
										NSString *strVal = [[strPropertyValLines objectAtIndex:1] stringByReplacingOccurrencesOfString:@"\"" withString:@""];
										
										[controlPropertyNode setStringValue: strVal];
									}
									else 
									{
										NSLog(@"Out array");
									}
								}
								
								if ([arrProperties count] > 1)
								{
									strPropertyVal = [arrProperties objectAtIndex:1];
									strPropertyVal = [strPropertyVal stringByReplacingOccurrencesOfString:@" " withString:@""];
									controlPropertyNode = [NSXMLNode elementWithName: @"IDSTR"];
									
									[controlNode addChild:controlPropertyNode];
									
									[controlPropertyNode setStringValue: strPropertyVal];
									
									NSString *strID = [self getID: strPropertyVal];
									
									if (strID)
									{
										NSXMLElement *IDNode = nil;
										IDNode = [NSXMLNode elementWithName:@"ID"];
										[IDNode setStringValue: strID];
										[controlNode addChild:IDNode];
									}
								}
								
								if ([arrProperties count] >= 6)
								{
									NSXMLElement *BOXNode = nil;
									BOXNode = [NSXMLNode elementWithName:@"BOX"];
									
									double f_x = (double)([[arrProperties objectAtIndex:2] intValue]) * WIN_DPI_TO_MAC_X;
									double f_y = (double)([[arrProperties objectAtIndex:3] intValue]) * WIN_DPI_TO_MAC_Y;
									double f_width = (double)([[arrProperties objectAtIndex:4] intValue]) * WIN_DPI_TO_MAC_X;
									double f_height = (double)([[arrProperties objectAtIndex:5] intValue]) * WIN_DPI_TO_MAC_Y;
									
									[BOXNode setStringValue: [NSString stringWithFormat: @"%d,%d,%d,%d", 
															  (int)f_x, (int)f_y,
															  (int)f_width, (int)f_height]];
									
									[controlNode addChild:BOXNode];
								}
								
								if ([arrProperties count] >= 7)
								{
									strPropertyVal = [arrProperties objectAtIndex:6];
									controlPropertyNode = [NSXMLNode elementWithName: @"STYLE"];
									
									[controlNode addChild:controlPropertyNode];
									
									[controlPropertyNode setStringValue: strPropertyVal];
								}
									
								strStyles = [arrProperties objectAtIndex:5];
							}
						}
						else
						if ((findPos = [line rangeOfString:@"LISTBOX"]).location != NSNotFound ||
							(findPos = [line rangeOfString:@"EDITTEXT"]).location != NSNotFound ||
							(findPos = [line rangeOfString:@"COMBOBOX"]).location != NSNotFound)
						{
							//LISTBOX id, x, y, width, height [, style [, extended-style]]
							//EDITTEXT id, x, y, width, height [, style [, extended-style]]
							//COMBOBOX id, x, y, width, height [, style [, extended-style]]
							
							//CTEXT    IDC_STATIC,10,96,300,8
							
							
							NSRange aRangeStart = {0, [line length]};
							NSRange aEndStart = {0, [line length]};
							
							while([line characterAtIndex: aRangeStart.location] == ' ')
							{
								aRangeStart = [line rangeOfString:@" " options:NSCaseInsensitiveSearch range:aRangeStart];	
								aRangeStart.location++; 
								aRangeStart.length = [line length] - aRangeStart.location;
							}
							
							aEndStart = [line rangeOfString:@" " options:NSCaseInsensitiveSearch range:aRangeStart];	
							
							aRangeStart.length = aEndStart.location - aRangeStart.location;
							
							NSString *strName = [line substringWithRange:aRangeStart];
							aRangeStart.location = aEndStart.location + 1;
							aRangeStart.length = [line length] - aRangeStart.location;
							NSString *strProperties =  [line substringWithRange:aRangeStart];
							
							
							NSXMLElement *controlNode = nil;
							
							controlNode = [NSXMLNode elementWithName: strName];
							
							if (controlNode)
							{
								[dialogNode addChild:controlNode];
								
								NSArray *arrProperties = [strProperties componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@","]];
								
								NSString *strPropertyVal = nil;									
								NSString *strStyles = nil;
								NSXMLElement *controlPropertyNode = nil; 
																	
								if ([arrProperties count] > 0)
								{
									strPropertyVal = [arrProperties objectAtIndex:0];
									strPropertyVal = [strPropertyVal stringByReplacingOccurrencesOfString:@" " withString:@""]; 
									controlPropertyNode = [NSXMLNode elementWithName: @"IDSTR"];
									
									[controlNode addChild:controlPropertyNode];
									
									[controlPropertyNode setStringValue: strPropertyVal];
									
									NSString *strID = [self getID: strPropertyVal];
									
									if (strID)
									{
										NSXMLElement *IDNode = nil;
										IDNode = [NSXMLNode elementWithName:@"ID"];
										[IDNode setStringValue: strID];
										[controlNode addChild:IDNode];
									}
									else 
									{
										NSLog([NSString stringWithFormat: @"Cant find name=\"%@\"", strPropertyVal]);											
									}
								}
								
								if ([arrProperties count] >= 5)
								{
									NSXMLElement *BOXNode = nil;
									BOXNode = [NSXMLNode elementWithName:@"BOX"];
									
									double f_x = (double)([[arrProperties objectAtIndex:1] intValue]) * WIN_DPI_TO_MAC_X;
									double f_y = (double)([[arrProperties objectAtIndex:2] intValue]) * WIN_DPI_TO_MAC_Y;
									double f_width = (double)([[arrProperties objectAtIndex:3] intValue]) * WIN_DPI_TO_MAC_X;
									double f_height = (double)([[arrProperties objectAtIndex:4] intValue]) * WIN_DPI_TO_MAC_Y;
									
									[BOXNode setStringValue: [NSString stringWithFormat: @"%d,%d,%d,%d", 
															  (int)f_x, (int)f_y,
															  (int)f_width, (int)f_height]];
									
									[controlNode addChild:BOXNode];
								}
								
								if ([arrProperties count] >= 6)
								{
									strPropertyVal = [arrProperties objectAtIndex:5];
									controlPropertyNode = [NSXMLNode elementWithName: @"STYLE"];
									
									[controlNode addChild:controlPropertyNode];
									
									[controlPropertyNode setStringValue: strPropertyVal];
								}
								
								strStyles = [arrProperties objectAtIndex:5];
							}
						}
						else
						if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@"CONTROL"]).location != NSNotFound)
						{
							//CONTROL text, id, class, style, x, y, width, height [, extended-style]
							
							//CONTROL         "Test",IDC_CHECK1,"Button",BS_AUTOCHECKBOX | WS_TABSTOP,19,28,30,10
							NSString *strControl = [NSString stringWithString: line];
							
							if ([strControl hasSuffix:@","])
							{
								i++;
								NSString *str = [NSString stringWithString:[strLines objectAtIndex:i]];
								
								while([str hasPrefix: @" "])
								{
									str = [str substringFromIndex: 1];
								}
								
								while([str hasPrefix: @"\t"])
								{
									str = [str substringFromIndex: 1];
								}
								
								strControl = [strControl stringByAppendingString: str];
							}
							
							if ([strControl hasSuffix:@"| "])
							{
								i++;
								
								NSString *str = [NSString stringWithString:[strLines objectAtIndex:i]];
								
								while([str hasPrefix: @" "])
								{
									str = [str substringFromIndex: 1];
								}
								
								while([str hasPrefix: @"\t"])
								{
									str = [str substringFromIndex: 1];
								}
								
								strControl = [strControl stringByAppendingString: str];
							}
							
							NSRange aRangeStart = {0, [strControl length]};
							NSRange aEndStart = {0, [strControl length]};
							
							while([strControl characterAtIndex: aRangeStart.location] == ' ')
							{
								aRangeStart = [strControl rangeOfString:@" " options:NSCaseInsensitiveSearch range:aRangeStart];	
								aRangeStart.location++; 
								aRangeStart.length = [strControl length] - aRangeStart.location;
							}
							
							aEndStart = [strControl rangeOfString:@" " options:NSCaseInsensitiveSearch range:aRangeStart];	
							
							aRangeStart.length = aEndStart.location - aRangeStart.location;
							
							NSString *strName = [strControl substringWithRange:aRangeStart];
							aRangeStart.location = aEndStart.location + 1;
							aRangeStart.length = [strControl length] - aRangeStart.location;
							NSString *strProperties =  [strControl substringWithRange:aRangeStart];
							
							NSXMLElement *controlNode = nil;
							
							controlNode = [NSXMLNode elementWithName: strName];
							
							if (controlNode)
							{
								[dialogNode addChild:controlNode];
								
								NSArray *arrProperties = [strProperties componentsSeparatedByCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@","]];
								
								NSString *strPropertyVal = nil;									
								NSString *strStyles = nil;
								NSXMLElement *controlPropertyNode = nil; 
								
								if ([arrProperties count] > 0)
								{
									strPropertyVal = [arrProperties objectAtIndex:0];
									controlPropertyNode = [NSXMLNode elementWithName: @"TEXT"];
									
									[controlNode addChild:controlPropertyNode];
									
									strPropertyVal = [strPropertyVal stringByReplacingOccurrencesOfString:@"\"" withString:@""];
									
									while([strPropertyVal hasPrefix: @" "])
									{
										strPropertyVal = [strPropertyVal substringFromIndex: 1];
									}
									
									while([strPropertyVal hasPrefix: @"\t"])
									{
										strPropertyVal = [strPropertyVal substringFromIndex: 1];
									}
									
									[controlPropertyNode setStringValue: strPropertyVal];
								}
								
								if ([arrProperties count] > 1)
								{
									strPropertyVal = [arrProperties objectAtIndex:1];
									strPropertyVal = [strPropertyVal stringByReplacingOccurrencesOfString:@" " withString:@""];
									controlPropertyNode = [NSXMLNode elementWithName: @"IDSTR"];
									
									[controlNode addChild:controlPropertyNode];
									
									[controlPropertyNode setStringValue: strPropertyVal];
									
									NSString *strID = [self getID: strPropertyVal];
									
									if (strID)
									{
										NSXMLElement *IDNode = nil;
										IDNode = [NSXMLNode elementWithName:@"ID"];
										[IDNode setStringValue: strID];
										[controlNode addChild:IDNode];
									}
								}
								
								if ([arrProperties count] > 2)
								{
									strPropertyVal = [arrProperties objectAtIndex:2];
									controlPropertyNode = [NSXMLNode elementWithName: @"CLASS"];
									
									[controlNode addChild:controlPropertyNode];
									
									strPropertyVal = [strPropertyVal stringByReplacingOccurrencesOfString:@"\"" withString:@""];
									
									[controlPropertyNode setStringValue: strPropertyVal];
								}
								
								if ([arrProperties count] > 3)
								{
									strPropertyVal = [arrProperties objectAtIndex:3];
									controlPropertyNode = [NSXMLNode elementWithName: @"STYLE"];
									
									[controlNode addChild:controlPropertyNode];
									
									[controlPropertyNode setStringValue: strPropertyVal];
								}
								
								if ([arrProperties count] >= 8)
								{
									NSXMLElement *BOXNode = nil;
									BOXNode = [NSXMLNode elementWithName:@"BOX"];
									
									double f_x = (double)([[arrProperties objectAtIndex:4] intValue]) * WIN_DPI_TO_MAC_X;
									double f_y = (double)([[arrProperties objectAtIndex:5] intValue]) * WIN_DPI_TO_MAC_Y;
									double f_width = (double)([[arrProperties objectAtIndex:6] intValue]) * WIN_DPI_TO_MAC_X;
									double f_height = (double)([[arrProperties objectAtIndex:7] intValue]) * WIN_DPI_TO_MAC_Y;
									
									[BOXNode setStringValue: [NSString stringWithFormat: @"%d,%d,%d,%d", 
															  (int)f_x, (int)f_y,
															  (int)f_width, (int)f_height]];
															  
									[controlNode addChild:BOXNode];
								}									
								
								strStyles = [arrProperties objectAtIndex:5];
							}
						}
						
						i++;
					}
					
					i++;
				}
				else 
				if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@"GUIDELINES DESIGNINFO"]).location != NSNotFound)//dialog guidelines
				{
					//GUIDELINES DESIGNINFO
					//BEGIN
					//IDD_ABOUTBOX, DIALOG
					//BEGIN
					//LEFTMARGIN, 7
					//RIGHTMARGIN, 163
					//TOPMARGIN, 7
					//BOTTOMMARGIN, 55
					//END
					//IDD_SIMPLEDIALOG2_DIALOG, DIALOG
					//BEGIN
					//LEFTMARGIN, 7
					//RIGHTMARGIN, 313
					//TOPMARGIN, 7
					//BOTTOMMARGIN, 193
					//END
					//END
				}
				else 
				if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@"STRINGTABLE"]).location != NSNotFound)//string table
				{
					i = [self AddStrings:strLines root:root stringTableNode:stringTableNode index:i findPos:findPos];
				}
				else//STRINGTABLE
				if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@" BITMAP "]).location != NSNotFound)//bitmap  table
				{
					i = [self AddBitmaps:strLines root:root bitmapTableNode:bitmapTableNode index:i findPos:findPos];					
				}
				else//BITMAP
				if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@" ICON "]).location != NSNotFound)//icon table
				{
					i = [self AddIcon:strLines root:root iconTableNode:iconTableNode index:i findPos:findPos];					
				}//ICON	
				else 
				if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@" TOOLBAR "]).location != NSNotFound)//tool bar
				{
					i = [self AddToolBar: strLines root:root index:i findPos:findPos];					
				}//TOOLBAR	
				if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@" ACCELERATORS "]).location != NSNotFound)//accelerators
				{
					i = [self AddAccelerators: strLines root:root index:i findPos:findPos];					
				}//ACCELERATORS	
				if ((findPos = [[strLines objectAtIndex:i] rangeOfString:@" MENU "]).location != NSNotFound)//menu
				{
					i = [self AddMenu: strLines root:root index:i findPos:findPos];					
				}//MENU	
			}				
			
			NSString *strXML = [doc XMLString];
			
			strXML = [strXML stringByReplacingOccurrencesOfString:@"><" withString:@">\n<"];
			
			if (![strXML writeToFile:[output path] atomically:NO encoding:NSUTF8StringEncoding error:nil])
			{
				[logControl setStringValue: [[logControl stringValue] 
											 stringByAppendingString: @"Error write\n\r"]];
			}
			
			//NSData *data = [doc XMLData];//XMLDataWithOptions: NSXMLDocumentTidyHTML];
			//[data writeToFile:[output path] atomically:NO];
		}	
		
		[doc dealloc];
		
		[logControl setStringValue: [[logControl stringValue] 
									 stringByAppendingString: @"Finished convert\n\r"]];
	}
	else 
	{
		[logControl setStringValue: [[logControl stringValue] 
						stringByAppendingString: @"Cannot conver because some of paths not exists."]];
	}
}

@end
