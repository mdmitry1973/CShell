/*
 *  winbase.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "winnt.h"
#include "winbase.h"

#include <libkern/OSAtomic.h>
#import <Cocoa/Cocoa.h>
#include <dlfcn.h>
#include <string>

//#define NSAssert(condition, desc, ...)

//void ns_assert()
//{
	
//}

class CMemoryPool
{
public:
	
	CMemoryPool();
	virtual ~CMemoryPool();
	
	static  __attribute__ ((visibility("default"))) CMemoryPool initMemoryPool;
	
	///static int m_counter;
	NSAutoreleasePool *pool;
};

CMemoryPool CMemoryPool::initMemoryPool;
//CMemoryPool::m_counter = 0;

CMemoryPool::CMemoryPool()
{
	pool = [[NSAutoreleasePool alloc] init]; // pool is created
	NSLog(@"INIT NSAutoreleasePool");
	//m_counter++;
}

CMemoryPool::~CMemoryPool()
{
	//m_counter--;
	if (pool)
	{
		[pool release]; // all your autoreleased objects are released
	}
	NSLog(@"RELEASE NSAutoreleasePool");
}


LONG InterlockedDecrement(LONG volatile *Addend)
{
	return OSAtomicDecrement32((int32_t*)Addend);
}

LONG InterlockedIncrement(LONG volatile *Addend)
{
	return OSAtomicIncrement32((int32_t*)Addend);
}

int _mkdir(const char *dirname)
{
	NSFileManager *fileManager= [NSFileManager defaultManager]; 
	
	bool res = [fileManager createDirectoryAtPath:[NSString stringWithUTF8String: dirname] 
					  withIntermediateDirectories:TRUE 
									   attributes:nil 
											error:nil];
	
	return res == TRUE ? 0 : -1;
}

int _access(const char *path, int mode)
{
	//0 Existence only
	//02 Write-only
	//04 Read-only	
	//06 Read and write
	
	NSFileManager *fileManager= [NSFileManager defaultManager];
	
	int modeRes = -1;
	
	bool exists = [fileManager fileExistsAtPath:[NSString stringWithUTF8String: path]];
	
	if (mode == 0 && exists)
	{
		return 0;
	}
	
	if (exists)
		modeRes = 0;
	
	if ([fileManager isReadableFileAtPath:[NSString stringWithUTF8String: path]])
	{
		modeRes = modeRes | 4;
	}
	
	if ([fileManager isWritableFileAtPath:[NSString stringWithUTF8String: path]])
	{
		modeRes = modeRes | 2;
	}
	
	return modeRes;
}

#include <mach-o/dyld.h>

DWORD GetModuleFileName(HMODULE hModule, LPTSTR lpFilename, DWORD nSize)
{
	char buf[3000];
	int length;

	getcwd(buf, sizeof(buf));
	
	length = strlen(buf);	

	
	/* Catch some errors: */
	if (length < 0)
	{
		return length;
	}

	strncpy(lpFilename, buf, nSize);
	
	Dl_info info;
	std::string moduleName;
	if (hModule)
	{
		if (dladdr((const void *) hModule , &info)) 
		{
			moduleName = info.dli_fname;
		}
	}
	else 
	{
		if (dladdr((const void *) GetModuleFileName, &info)) 
		{
			moduleName = info.dli_fname;
		}
	}
	
	if (moduleName.length())
	{
		int pos;
		if ((pos = moduleName.rfind("/")) != -1)
		{
			std::string Name = moduleName.substr(pos + 1, moduleName.length());
			strcat(lpFilename, "/");
			strcat(lpFilename, Name.c_str());
		}
	}
	
	return strlen(lpFilename);
}

DWORD GetLongPathName(LPCTSTR lpszShortPath, LPTSTR lpszLongPath, DWORD cchBuffer)
{
	NSLog(@"TO DO GetLongPathName");
	return 0;
}
 
DWORD GetTempPath(DWORD nBufferLength, LPTSTR lpBuffer)
{
	NSString *str = NSTemporaryDirectory();
	
	strncpy(lpBuffer, [str UTF8String], nBufferLength);
	
	return [str length];
}

HANDLE FindFirstFile(LPCTSTR lpFileName,LPWIN32_FIND_DATA lpFindFileData)
{
	NSLog(@"TO DO FindFirstFile");
	return 0;
}

BOOL FindNextFile(HANDLE hFindFile, LPWIN32_FIND_DATA lpFindFileData)
{
	NSLog(@"TO DO FindNextFile");
	return 0;
}

BOOL FindClose(HANDLE hFindFile)
{
	NSLog(@"TO DO FindClose");
	return 0;
}

BOOL CopyFile(LPCTSTR lpExistingFileName, LPCTSTR lpNewFileName, BOOL bFailIfExists)
{
	NSLog(@"TO DO CopyFile");
	return 0;
}

BOOL DeleteFile(LPCTSTR lpFileName)
{
	NSLog(@"TO DO CopyFile");
	return 0;
}

BOOL RemoveDirectory(LPCTSTR lpPathName)
{
	NSLog(@"TO DO RemoveDirectory");
	return 0;
}

DWORD GetFullPathName(LPCTSTR lpFileName, DWORD nBufferLength,
					  LPTSTR lpBuffer, LPTSTR *lpFilePart)
{
	NSLog(@"TO DO GetFullPathName");
	return 0;
}

UINT GetTempFileName(LPCTSTR lpPathName,
					 LPCTSTR lpPrefixString,
					 UINT uUnique, LPTSTR lpTempFileName)
{
	NSLog(@"TO DO GetTempFileName");
	return 0;
}

BOOL GetVolumeInformation(LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer,
						  DWORD nVolumeNameSize,
						  LPDWORD lpVolumeSerialNumber,
						  LPDWORD lpMaximumComponentLength,
						  LPDWORD lpFileSystemFlags,
						  LPSTR lpFileSystemNameBuffer,
						  DWORD nFileSystemNameSize)
{
	NSLog(@"TO DO GetVolumeInformation");
	return 0;
}

DWORD GetFileAttributes(LPCSTR lpFileName)
{
	NSLog(@"TO DO GetFileAttributes");
	return 0;
}

BOOL SetFileAttributes(LPCSTR lpFileName, DWORD dwFileAttributes)
{
	NSLog(@"TO DO SetFileAttributes");
	return 0;
}

HANDLE CreateFile(LPCSTR lpFileName,
				  DWORD dwDesiredAccess,
				  DWORD dwShareMode,
				  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
				  DWORD dwCreationDisposition,
				  DWORD dwFlagsAndAttributes,
				  HANDLE hTemplateFile
				  )
{
	NSLog(@"TO DO CreateFile");
	return 0;
}

int GetTimeFormat(LCID Locale, DWORD dwFlags,
				  const SYSTEMTIME *lpTime, LPCTSTR lpFormat,
				  LPTSTR lpTimeStr, int cchTime)
{
	NSLog(@"TO DO GetTimeFormat");
	return 0;
}

int GetDateFormat(LCID Locale, DWORD dwFlags, SYSTEMTIME *lpDate,
				  LPCSTR lpFormat, LPSTR lpDateStr, int cchDate)
{
	NSLog(@"TO DO GetDateFormat");
	return 0;
}

void UnixTimeToFileTime(time_t t, LPFILETIME pft)
{
	// Note that LONGLONG is a 64-bit value
	LONGLONG ll;
	
	ll = Int32x32To64(t, 10000000) + 116444736000000000;
	pft->dwLowDateTime = (DWORD)ll;
	pft->dwHighDateTime = ll >> 32;
}

BOOL SystemTimeToFileTime(SYSTEMTIME *lpSystemTime, LPFILETIME lpFileTime)
{
	struct tm *timeinfo;
	time_t rawtime;
	
	time ( &rawtime );
	
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year	= lpSystemTime->wYear - 1900;
	timeinfo->tm_mon	= lpSystemTime->wMonth - 1;
	timeinfo->tm_mday	= lpSystemTime->wDay;
	timeinfo->tm_hour	= lpSystemTime->wHour;
	timeinfo->tm_min	= lpSystemTime->wMinute;
	timeinfo->tm_sec	= lpSystemTime->wSecond;
	timeinfo->tm_wday	= lpSystemTime->wDayOfWeek;
	
	time_t t = mktime (timeinfo);
	
	UnixTimeToFileTime(t, lpFileTime);
	
	return 0;
}

BOOL GetFileTime(HANDLE hFile,
				 LPFILETIME lpCreationTime,
				 LPFILETIME lpLastAccessTime,
				 LPFILETIME lpLastWriteTime)
{
	NSLog(@"TO DO GetFileTime");
	return 0;
}

BOOL SetFileTime(HANDLE hFile,
				 const FILETIME *lpCreationTime,
				 const FILETIME *lpLastAccessTime,
				 const FILETIME *lpLastWriteTime)
{
	NSLog(@"TO DO SetFileTime");
	return 0;
}

BOOL LocalFileTimeToFileTime(const FILETIME *lpLocalFileTime, LPFILETIME lpFileTime)
{
	NSLog(@"TO DO LocalFileTimeToFileTime");
	return 0;
	
}

BOOL CloseHandle(HANDLE hObject)
{
	NSLog(@"TO DO CloseHandle");
	return 0;
}

DWORD GetLastError()
{
	NSLog(@"TO DO GetLastError");
	return 0;
}

LPSTR CharUpper(LPSTR lpsz)
{
	NSLog(@"TO DO CharUpper");
	return 0;
}

BOOL PathIsUNC( LPCSTR pszPath)
{
	NSLog(@"TO DO PathIsUNC");
	return 0;
}

BOOL PathStripToRoot( LPSTR pszPath)
{
	NSLog(@"TO DO PathStripToRoot");
	return 0;
}
/*
DWORD GetVersion()
{
	NSLog(@"TO DO GetVersion");
	return 0;
}
 */
