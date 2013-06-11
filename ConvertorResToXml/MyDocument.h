//
//  MyDocument.h
//  ConvertorResToXml
//
//  Created by Dmitry Mikhaevich on 11/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#import <Cocoa/Cocoa.h>

#include <string>
#include <map>

@interface MyDocument : NSDocument
{
	IBOutlet NSPathControl		*pathControl;
	IBOutlet NSPathControl		*pathOutputControl;
	IBOutlet NSPathControl		*pathResHControl;
	IBOutlet NSTextField		*logControl;
	
	std::map<std::string, std::string> m_map_id;
}

- (IBAction)browserButton:(id)sender;
- (IBAction)browserResHButton:(id)sender;
- (IBAction)browserOutputButton:(id)sender;
- (IBAction)convertButton:(id)sender;
//- (IBAction)performClose:(id)sender;

@end
