/*
 *  CFileFind.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#import <Cocoa/Cocoa.h>

#include "CFileFind.h"

CFileFind::CFileFind()
{
	dirEnum = NULL;
	localFileManager = NULL;
	all = FALSE;
}

CFileFind::~CFileFind()
{
	if (localFileManager)
		[(NSFileManager *)localFileManager release];
}

ULONGLONG CFileFind::GetLength() const
{
	NSLog(@"TO DO CFileFind::GetLength");
	
	return 0;
}

CString CFileFind::GetFileName() const
{
	NSString *str = [NSString stringWithUTF8String: res.c_str()];
	
	return [[str lastPathComponent] UTF8String];
}

CString CFileFind::GetFilePath() const
{
	return res.c_str();
}

CString CFileFind::GetFileTitle() const
{
	NSLog(@"TO DO CFileFind::GetFileTitle");
	return "";
}

CString CFileFind::GetFileURL() const
{
	NSLog(@"TO DO CFileFind::GetFileURL");
	return "";
}

CString CFileFind::GetRoot() const
{
	NSLog(@"TO DO CFileFind::GetRoot");
	return "";
}

BOOL CFileFind::GetLastWriteTime(FILETIME* pTimeStamp) const
{
	NSLog(@"TO DO CFileFind::GetLastWriteTime");
	return TRUE;
}

BOOL CFileFind::GetLastAccessTime(FILETIME* pTimeStamp) const
{
	NSLog(@"TO DO CFileFind::GetLastAccessTime");
	return TRUE;
}

BOOL CFileFind::GetCreationTime(FILETIME* pTimeStamp) const
{
	NSLog(@"TO DO CFileFind::GetCreationTime");
	return TRUE;
}

BOOL CFileFind::GetLastWriteTime(CTime& refTime) const
{
	NSLog(@"TO DO CFileFind::GetLastWriteTime");
	return TRUE;
}

BOOL CFileFind::GetLastAccessTime(CTime& refTime) const
{
	NSLog(@"TO DO CFileFind::GetLastAccessTime");
	return TRUE;
}

BOOL CFileFind::GetCreationTime(CTime& refTime) const
{
	NSLog(@"TO DO CFileFind::GetCreationTime");
	return TRUE;
}

BOOL CFileFind::MatchesMask(DWORD dwMask) const
{
	NSLog(@"TO DO CFileFind::MatchesMask");
	return FALSE;
}

BOOL CFileFind::IsDots() const
{
	NSLog(@"TO DO CFileFind::IsDots");
	return FALSE;
}

/*
BOOL CFileFind::IsReadOnly() const;
 */

BOOL CFileFind::IsDirectory() const
{
	NSLog(@"TO DO CFileFind::IsDirectory");
	return FALSE;
}
/*
BOOL CFileFind::IsCompressed() const;
BOOL CFileFind::IsSystem() const;
BOOL CFileFind::IsHidden() const;
BOOL CFileFind::IsTemporary() const;
BOOL CFileFind::IsNormal() const;
BOOL CFileFind::IsArchived() const;


void CFileFind::Close();
 */

BOOL CFileFind::FindFile(LPCTSTR pstrName, DWORD dwUnused)
{
	NSString *searchPath = [NSString stringWithUTF8String: pstrName];
	
	searchPath = [searchPath stringByReplacingOccurrencesOfString:@"\\" withString:@"/"];
	
	windCard = [[searchPath lastPathComponent] UTF8String];
	NSString *path = [searchPath stringByDeletingLastPathComponent];
	
	localFileManager = [[NSFileManager alloc] init];
	NSURL *searchUrl = [NSURL fileURLWithPath: path];
	
	dirEnum = (NSDirectoryEnumerator *)[(NSFileManager*)localFileManager enumeratorAtURL: searchUrl
												includingPropertiesForKeys:nil//[NSArray arrayWithObjects:NSURLNameKey,
																				//		NSURLIsDirectoryKey,nil]
												options:NSDirectoryEnumerationSkipsSubdirectoryDescendants 
												errorHandler:nil];
	
	if (dirEnum)
	{
		if (windCard.find("*"))
		{
			all = TRUE;
		}
		else 
		{		
			extension = windCard.substr(2, windCard.length());
		}
		
		return TRUE;
	}
	
	return FALSE;
}

BOOL CFileFind::FindNextFile()
{
	NSString *file;
	
again:
	
	NSDirectoryEnumerator *dirEnumNS = (NSDirectoryEnumerator *)dirEnum;
	
	file = [dirEnumNS nextObject];
		
	if (file)
	{
		res = [[file path] UTF8String];
		
		if (all)
		{
			return TRUE;
		}
		
		NSString *ext = [file pathExtension];
		
		if ([ext isEqualToString: [NSString stringWithUTF8String: extension.c_str()]]) 
		{
			return TRUE;
		}
		
		goto again;
	}
	
	return FALSE;
}
