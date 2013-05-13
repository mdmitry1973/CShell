//
//  CNSTableView.mm
//  CShell
//
//  Created by Dmitry Mikhaevich on 1/19/12.
//  Copyright 2012 Dmitry Mikhaevich. All rights reserved.
//

#include "CDef.h"
#include "CWnd.h"

#import "CNSTableView.h"

@implementation CNSTableViewDataSourceString

- (id)init
{
    self = [super init];
	
	mStrArray = [NSMutableArray array];
	
	return self;
}

- (void)dealloc 
{
    [super dealloc];
}

- (NSMutableArray *)getArr
{
	return mStrArray;
}

- (int)addItem:(NSString *)str
{
	if (mStrArray)
	{
		[mStrArray addObject: str];
		return [mStrArray count];
	}
	
	return LB_ERR;
}

- (int)insertItem:(NSString *)str index:(int)index
{
	if (mStrArray)
	{
		[mStrArray insertObject: str atIndex:index];
		return index;
	}
	
	return LB_ERR;
}

- (int)removeItem:(int )index
{
	if (mStrArray)
	{
		[mStrArray removeObjectAtIndex: index];
		return [mStrArray count];
	}
	
	return LB_ERR;
}

- (NSInteger)numberOfRowsInTableView:(NSTableView *)tableView 
{
	if (mStrArray)
	{
		return [mStrArray count];
	}
	
	return 0;
}

- (id)tableView:(NSTableView *)tableView objectValueForTableColumn:(NSTableColumn *)tableColumn row:(NSInteger)row 
{
	if (mStrArray)
	{
		return [mStrArray objectAtIndex: row];
	}
	
	return 0;
}

@end

@implementation CNSTableView

CSHELL_IMPL_STANDARD_METHOD
CSHELL_IMPL_CONTROL_STANDARD_METHOD

- (id)init 
{
	self = [super init];
	
    return self;
}

- (int)addItem:(NSString *)str
{
	CNSTableViewDataSourceString *data = [self dataSource];
	
	int res = [data addItem: str];
	
	[self reloadData];
	
	return res;
}

- (int)insertItem:(NSString *)str index:(int)index
{
	CNSTableViewDataSourceString *data = [self dataSource];
	
	int res = [data insertItem: str index:index];
	
	[self reloadData];
	
	return res;
}

- (int)removeItem:(int )index
{
	CNSTableViewDataSourceString *data = [self dataSource];
	
	int res = [data removeItem: index];
	
	[self reloadData];
	
	return res;
}

- (void)removeAll
{
	CNSTableViewDataSourceString *data = [self dataSource];
	
	[[data getArr ]removeAllObjects];
}

- (int)findItem:(int)nStartAfter itemStr:(NSString *)lpszItem
{
	CNSTableViewDataSourceString *data = [self dataSource];
	NSMutableArray *arr = [data getArr];
	int res = LB_ERR;
	
	for(int i = nStartAfter; i < [arr count]; i++)
	{
		if ([(NSString *)([arr objectAtIndex: i]) compare: lpszItem] == NSOrderedSame)
		{
			return i;
		}
	}
	
	return res;
}

- (int)count
{
	CNSTableViewDataSourceString *data = [self dataSource];
	NSMutableArray *arr = [data getArr];
	
	return [arr count];
}

@end