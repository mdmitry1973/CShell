/*
 *  winbase.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "winerror.h"
#include "winreg.h"

#include <libkern/OSAtomic.h>
#import <Cocoa/Cocoa.h>

#define STR_HKEY_CLASSES_ROOT	"com.CShell.STR_HKEY_CLASSES_ROOT"
#define STR_HKEY_CURRENT_CONFIG "com.CShell.STR_HKEY_CLASSES_ROOT"
#define STR_HKEY_CURRENT_USER	"com.CShell.STR_HKEY_CLASSES_ROOT"
#define STR_HKEY_LOCAL_MACHINE	"com.CShell.STR_HKEY_CLASSES_ROOT"
#define STR_HKEY_USERS			"com.CShell.STR_HKEY_CLASSES_ROOT"

@interface HKEY_DATA : NSObject
{
	NSString *name;
	NSString *sub_name;
	NSMutableDictionary *dic;
	NSMutableDictionary *arr;
}

- (void)setName:(NSString*)n;
- (void)setSubName:(NSString*)sn;
- (void)setDic:(NSMutableDictionary*)d;
- (void)setArr:(NSMutableDictionary*)a;

- (NSString*)getName;
- (NSString*)getSubName;
- (NSMutableDictionary*)getDic;
- (NSMutableDictionary*)getArr;

@end

@implementation HKEY_DATA

- (id)init
{
	self = [super init];
	
	if (self)
	{
		name = nil; 
		sub_name = nil; 
		dic = nil; 
		arr = nil;
	}
	
    return self;
}

- (id)initWithName:(NSString *) n
{
	self = [super init];
	
	if (self)
	{
		name = n; 
		sub_name = nil;
		dic = nil; 
		arr = nil;
	}
	
    return self;
}

- (bool)isSubKey
{
    return (name && sub_name && dic && arr);
}

- (void)setName:(NSString*)n
{
	name = n; 
}

- (void)setSubName:(NSString*)sn
{
	sub_name = sn; 
}

- (void)setDic:(NSMutableDictionary*)d
{
	dic = d;
}

- (void)setArr:(NSMutableDictionary*)a
{
	arr = a;
}

- (NSString*)getName
{
	return name;
}

- (NSString*)getSubName
{
	return sub_name;
}

- (NSMutableDictionary*)getDic
{
	return dic;
}

- (NSMutableDictionary*)getArr
{
	return arr;
}

@end

HKEY createNSKey(const char *name)
{
	return [[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: name]];
}

const void *nsSTR_HKEY_CLASSES_ROOT					= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CLASSES_ROOT]] autorelease];
const void *nsSTR_HKEY_CURRENT_USER					= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CURRENT_USER]] autorelease];
const void *nsSTR_HKEY_LOCAL_MACHINE				= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_LOCAL_MACHINE]] autorelease];
const void *nsSTR_HKEY_USERS						= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_USERS]] autorelease];
const void *nsSTR_HKEY_PERFORMANCE_DATA				= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CLASSES_ROOT]] autorelease];
const void *nsSTR_HKEY_PERFORMANCE_TEXT				= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CLASSES_ROOT]] autorelease];
const void *nsSTR_HKEY_PERFORMANCE_NLSTEXT			= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CLASSES_ROOT]] autorelease];
const void *nsSTR_HKEY_CURRENT_CONFIG				= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CURRENT_CONFIG]] autorelease];
const void *nsSTR_HKEY_DYN_DATA						= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CLASSES_ROOT]] autorelease];
const void *nsSTR_HKEY_CURRENT_USER_LOCAL_SETTINGS	= [[[HKEY_DATA alloc] initWithName: [NSString stringWithUTF8String: STR_HKEY_CLASSES_ROOT]] autorelease];


LSTATUS RegCreateKeyEx(HKEY hKey,
					   LPCSTR lpSubKey,
					   DWORD Reserved,
					   LPSTR lpClass,
					   DWORD dwOptions,
					   REGSAM samDesired,
					   const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
					   PHKEY phkResult,
					   LPDWORD lpdwDisposition
					   )
{
	return RegCreateKey(hKey, lpSubKey, phkResult);
}

LSTATUS RegOpenKeyEx(HKEY hKey,
					 LPCSTR lpSubKey,
					 DWORD ulOptions,
					 REGSAM samDesired,
					 PHKEY phkResult
					 )
{
	HKEY_DATA *key = (HKEY_DATA *)hKey;	
	NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
	NSMutableDictionary *dic = [defaults objectForKey: [key getName]];
	
	if (!dic)
	{
		dic = [NSMutableDictionary dictionary];
		[defaults setObject:dic forKey: [key getName]];
	}
	
	NSMutableDictionary *dir_work = [dic mutableCopy];
	
	id object = [dir_work objectForKey: [NSString stringWithUTF8String: lpSubKey]];
	
	if (!object)
	{
		object = [NSMutableDictionary dictionary];		
		[dir_work setObject: object forKey: [NSString stringWithUTF8String: lpSubKey]];
	}
	
	HKEY_DATA *data = [[HKEY_DATA alloc] init];
	
	[data setName: [key getName]];
	[data setSubName: [NSString stringWithUTF8String: lpSubKey]];
	[data setDic: dir_work];
	[data setArr: object];
	
	*phkResult = (PHKEY)data;
	
	return ERROR_SUCCESS;
}

LSTATUS RegQueryValueEx(HKEY hKey,
						LPCSTR lpValueName,
						LPDWORD lpReserved,
						LPDWORD lpType,
						LPBYTE lpData,
						LPDWORD lpcbData
						)
{
	HKEY_DATA *hkey_data = (HKEY_DATA *)hKey;
	
	NSMutableDictionary *arr = [hkey_data getArr];
	
	id ob = nil; 
	
	if (lpValueName)
	{
		ob = [arr objectForKey:[NSString stringWithUTF8String: lpValueName]];
	}
	else 
	{
		if ([arr count])
		{
			NSArray *name = [arr allKeys];
			
			if (name)
			{
				ob = [arr objectForKey:name];	
			}
		}
	}

	
	if (!ob)
	{
		return ERROR_FILE_NOT_FOUND;
	}
	
	if ([ob class] == [NSString class])
	{
		*lpType = REG_SZ;
		NSString *str = (NSString *)ob;
		*lpcbData = [str length];
		
		if (lpData)
		{
			strcpy((char *)lpData, [str UTF8String]);
		}
	}
	else
	if ([ob class] == [NSData class])
	{
		*lpType = REG_BINARY;
		NSData *data = (NSData *)ob;
		
		*lpcbData = [data length];
		
		memcpy(lpData, [data bytes], [data length]);
	}
	
	return ERROR_SUCCESS;
}


LSTATUS RegSetValueEx ( HKEY hKey,
					   LPCSTR lpValueName,
					   DWORD Reserved,
					   DWORD dwType,
					   const BYTE* lpData,
					   DWORD cbData
					   )
{
	HKEY_DATA *hkey_data = (HKEY_DATA *)hKey;
	
	NSMutableDictionary *arr = [hkey_data getArr];
	
	switch (dwType)
	{
		case REG_NONE:{ ASSERT(NULL); }break;
			
		case REG_SZ:
		{ 
			[arr setObject: [NSString stringWithUTF8String: (char *)lpData] forKey: [NSString stringWithUTF8String: lpValueName]]; 
		}
		break;
			
		case REG_EXPAND_SZ:
		{ 
			[arr setObject: [NSString stringWithUTF8String: (char *)lpData] forKey: [NSString stringWithUTF8String: lpValueName]]; 
		}
		break;
			
		case REG_BINARY:
		{ 
			NSData *data = [NSData dataWithBytes:lpData length:cbData];
			[arr setObject: data forKey: [NSString stringWithUTF8String: lpValueName]];
		}
		break;
			
		case REG_DWORD:
		{ 
			NSData *data = [NSData dataWithBytes:lpData length:cbData];
			[arr setObject: data forKey: [NSString stringWithUTF8String: lpValueName]];
		}
		break;
		//case REG_DWORD_LITTLE_ENDIAN:{ }break;
			
		case REG_DWORD_BIG_ENDIAN:
		{ 
			NSData *data = [NSData dataWithBytes:lpData length:cbData];
			[arr setObject: data forKey: [NSString stringWithUTF8String: lpValueName]];
		}
		break;
			
		case REG_LINK:{ ASSERT(NULL); }break;
		case REG_MULTI_SZ:
		{ 
			[arr setObject: [NSString stringWithUTF8String: (char *)lpData] forKey: [NSString stringWithUTF8String: lpValueName]]; 
		}
		break;
		case REG_RESOURCE_LIST:{ ASSERT(NULL); }break;
		case REG_FULL_RESOURCE_DESCRIPTOR:{ ASSERT(NULL); }break;
		case REG_RESOURCE_REQUIREMENTS_LIST:{ ASSERT(NULL); }break;
		case REG_QWORD:
		{ 
			NSData *data = [NSData dataWithBytes:lpData length:cbData];
			[arr setObject: data forKey: [NSString stringWithUTF8String: lpValueName]];
		}
		break;
		//case REG_QWORD_LITTLE_ENDIAN:{ }break;
	}
	
	return ERROR_SUCCESS;
}

LSTATUS RegCloseKey(HKEY hKey)
{
	HKEY_DATA *hkey_data = (HKEY_DATA *)hKey;
	
	if ([hkey_data isSubKey])
	{
		
	}
	else 
	{
		
	}
	
	NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
	
	if ([hkey_data getDic])
	{
		[defaults setObject:[hkey_data getDic] forKey: [hkey_data getName]];
	}
	
	[defaults synchronize];
	
	[hkey_data release];
	
	return ERROR_SUCCESS;
}

LSTATUS RegDeleteKey(HKEY hKey, LPCSTR lpSubKey)
{
	HKEY_DATA *key = (HKEY_DATA *)hKey;	
	NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
	NSMutableDictionary *dic = [defaults objectForKey: [key getName]];
	NSMutableDictionary *dir_work = [dic mutableCopy];
	NSString *subKey = [NSString stringWithUTF8String: lpSubKey];
	
	if (!dir_work)
	{
		return ERROR_SUCCESS;
	}
	
	NSArray *arr = [dir_work allKeys];
	
	for(int i = 0; i < [arr count]; i++)
	{
		NSString *name = [NSString stringWithString:[arr objectAtIndex: i]];		
		NSRange range = [name rangeOfString: subKey];
		
		if (range.location == 0)
		{
			//NSMutableDictionary *kye_dic = [dic objectForKey: name];
			//[kye_dic release];
			[dir_work removeObjectForKey: name];
		}
	}
	
	//if (dir_work)
	//{
		[defaults setObject: dir_work forKey: [key getName]];
	//}

	[defaults synchronize];
	
	return ERROR_SUCCESS;
}

LSTATUS RegDeleteValue(HKEY hKey, LPCSTR lpValueName)
{
	HKEY_DATA *data = (HKEY_DATA *)hKey;
	
	if (![data getDic])
	{
		return ERROR_SUCCESS;
	}
	
	NSMutableDictionary *object = (NSMutableDictionary *)[data getArr];
	
	if (!object)
	{
		return ERROR_SUCCESS;
	}
	
	[object removeObjectForKey: [NSString stringWithUTF8String: lpValueName]];
	
	NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
	
	if ([data getDic])
	{
		[defaults setObject:[data getDic] forKey: [data getName]];
	}
	
	[defaults synchronize];
	
	return ERROR_SUCCESS;
}

LSTATUS RegSaveKey(HKEY hKey, LPCSTR lpFile, const LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	HKEY_DATA *data = (HKEY_DATA *)hKey;
	
	if (![data getDic])
	{
		return -1;
	}
	
	NSMutableDictionary *object = (NSMutableDictionary *)[data getArr];
	
	if (!object)
	{
		return -1;
	}

	[object writeToFile:[NSString stringWithUTF8String: lpFile] atomically:NO];
	
	return ERROR_SUCCESS;
}

LSTATUS RegRestoreKey(HKEY hKey, LPCSTR lpFile, DWORD dwFlags)
{
	HKEY_DATA *data = (HKEY_DATA *)hKey;
	
	if (![data getDic])
	{
		return -1;
	}
	
	NSMutableDictionary *object = (NSMutableDictionary *)[data getArr];
	
	object = [NSMutableDictionary dictionaryWithContentsOfFile:[NSString stringWithUTF8String: lpFile]];
	
	return ERROR_SUCCESS;
}

LSTATUS RegEnumKeyEx(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName,
					 LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime)
{
	return RegEnumValue(hKey, dwIndex, lpName, lpcchName, lpReserved, 0, 0, 0);
}

LSTATUS RegSetValue(HKEY hKey,
					LPCSTR lpSubKey,
					DWORD dwType,
					LPCSTR lpData,
					DWORD cbData)
{
	LSTATUS res;
	PHKEY phkResult;
	
	NSString *s = [NSString stringWithUTF8String: lpSubKey];	
	NSArray *a = [s componentsSeparatedByString:@"\\"];
	NSString *last = [a lastObject];
	NSRange range;
	range.location = 0;
    range.length = [a count] - 1;
	NSArray *a2 = [a subarrayWithRange:range];
	
	s = [a2 componentsJoinedByString:@"\\"];
	
	//- (NSString *)lastPathComponent
	//(NSString *)stringByDeletingLastPathComponent
	
	//res = RegOpenKeyEx(hKey, lpSubKey, 0, 0, phkResult);
	
	res = RegCreateKey(hKey, [s UTF8String], phkResult);
	
	if (res != ERROR_SUCCESS)
	{
		return res;
	}
	
	res = RegSetValueEx(phkResult, [last UTF8String], 0, dwType, (BYTE *)lpData, cbData);
	
	return res;
}

LSTATUS RegCreateKey ( HKEY hKey,
					  LPCSTR lpSubKey,
					  PHKEY phkResult)
{
	HKEY_DATA *key = (HKEY_DATA *)hKey;	
	NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
	NSMutableDictionary *dic = [defaults objectForKey: [key getName]];
	
	if (!dic)
	{
		dic = [NSMutableDictionary dictionary];
		[defaults setObject:dic forKey: [key getName]];
	}
	
	NSMutableDictionary *object = [dic objectForKey: [NSString stringWithUTF8String: lpSubKey]];
	
	if (!object)
	{
		object = [NSMutableDictionary dictionary];		
		[dic setObject: object forKey: [NSString stringWithUTF8String: lpSubKey]];
	}
	
	HKEY_DATA *data = [[HKEY_DATA alloc]init] ;
	
	[data setName:[key getName]];
	[data setSubName:[NSString stringWithUTF8String: lpSubKey]];
	[data setDic: dic];
	[data setArr: object];
	
	*phkResult = (PHKEY)data;
		
	return ERROR_SUCCESS;
}

LSTATUS RegEnumValue(HKEY hKey, DWORD dwIndex, LPSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData)
{
	HKEY_DATA *data = (HKEY_DATA *)hKey;
	
	NSMutableDictionary *dir = (NSMutableDictionary *)[data getArr];
	
	NSArray *arr = [dir allKeys];
	
	if (![arr count])
	{
		return -1;
	}
	
	if (dwIndex > [arr count] - 1)
	{
		return -1;
	}
	
	NSString *str = [arr objectAtIndex: dwIndex];
	
	strcpy(lpValueName, [str UTF8String]);
	
	//PHKEY phkResult;
	//LSTATUS res;
	
	//res = RegOpenKeyEx(hKey, lpSubKey, 0, 0, phkResult);
	
	//if (res != ERROR_SUCCESS)
	//{
	//	return res;
	//}
	
	//RegCloseKey(phkResult);
	
	return ERROR_SUCCESS;
}

LSTATUS  SHDeleteKey(HKEY hkey, LPCSTR pszSubKey)
{
	return RegDeleteKey(hkey, pszSubKey);
}