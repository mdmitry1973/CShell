//
//  CNSTableView.h
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 CShell. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CNSTableViewDataSourceString : NSObject <NSTableViewDataSource>
{
	NSMutableArray *mStrArray;
}

- (NSMutableArray *)getArr;

- (int)addItem:(NSString *)str;
- (int)insertItem:(NSString *)str index:(int)index;
- (int)removeItem:(int )index;

@end

@interface CNSTableView : NSTableView
{
	CSHELL_DEF_STANDARD_VAL
}

CSHELL_DEF_STANDARD_METHOD

- (int)addItem:(NSString *)str;
- (int)insertItem:(NSString *)str index:(int)index;
- (int)removeItem:(int)index;

- (int)findItem:(int)nStartAfter itemStr:(NSString *)lpszItem;
- (int)count;

@end