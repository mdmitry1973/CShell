/*
 *  winbase.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "winuser.h"
#include "winnt.h"
#include "winbase.h"
#include "shlobj.h"

#include <libkern/OSAtomic.h>
#import <Cocoa/Cocoa.h>
#include <dlfcn.h>
#include <string>

#import "CNSApplicationDelegate.h"

extern CNSApplicationDelegate	*pMainAppCocoa;

class CMemoryPool
{
public:
	
	CMemoryPool();
	virtual ~CMemoryPool();
	
	void PoolDrain();
	
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
		pool = nil;
	}
	NSLog(@"RELEASE NSAutoreleasePool");
}

void CMemoryPool::PoolDrain()
{
	if (pool)
	{
		[pool drain]; 
	}
}

void CMemoryPoolDrain()
{
	CMemoryPool::initMemoryPool.PoolDrain();
}


LONG InterlockedDecrement(LONG volatile *Addend)
{
	return OSAtomicDecrement32((int32_t*)Addend);
}

LONG InterlockedIncrement(LONG volatile *Addend)
{
	return OSAtomicIncrement32((int32_t*)Addend);
}

HANDLE CreateMutex(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCTSTR lpName)
{
	NSLog(@"to do CreateMutex");
	
	return 0;
}

HANDLE OpenMutex(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCTSTR lpName)
{
	NSLog(@"to do OpenMutex");
	
	return 0;
}

DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds)
{
	NSLog(@"to do WaitForSingleObject");
	
	return 0;
}

BOOL CreateProcess(LPCTSTR lpApplicationName, LPTSTR lpCommandLine,
				   LPSECURITY_ATTRIBUTES lpProcessAttributes,
				   LPSECURITY_ATTRIBUTES lpThreadAttributes,
				   BOOL bInheritHandles, DWORD dwCreationFlags,
				   LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory,
				   LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	NSLog(@"to do CreateProcess");
	
	return FALSE;
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

int _rmdir(const char *dirname)
{
	NSFileManager *fileManager= [NSFileManager defaultManager]; 
	
	bool res = [fileManager removeItemAtPath:[NSString stringWithUTF8String: dirname] 
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

void SHChangeNotify(LONG wEventId, UINT uFlags, LPCVOID dwItem1, LPCVOID dwItem2)
{
	
}

BOOL PeekMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
	NSLog(@"TO DO PeekMessage");
	
	return FALSE;
}

LRESULT DispatchMessage(const MSG *lpmsg)
{
	NSLog(@"TO DO DispatchMessage");
	
	return 0;
}

DWORD GetTickCount()
{
	NSLog(@"TO DO GetTickCount");
	
	return 0;
}

void _splitpath( const char *str, char *drive, char *dir, char *fname, char *ext )
{
	NSString *path = [NSString stringWithUTF8String: str];
	NSArray *pathComponents = [path pathComponents];
	
	if (pathComponents && [pathComponents count])
	{
		strncpy(drive, [[pathComponents objectAtIndex: 0] UTF8String], _MAX_DRIVE);
		
		if ([pathComponents count] > 1)
		{
			strncpy(dir, [[pathComponents objectAtIndex: [pathComponents count] - 2] UTF8String], _MAX_DIR);
		}
	}
	
	strncpy(fname, [[path lastPathComponent] UTF8String], _MAX_FNAME);
	strncpy(ext, [[path pathExtension] UTF8String], _MAX_EXT);
}

char *strupr(char *str)
{
	std::string s = str;
	std::for_each(s.begin(), s.end(), std::toupper);
	strcpy(str, s.c_str());
	
	return str;
}

HMODULE LoadLibrary(LPCSTR lpLibFileName)
{
	void *handle = dlopen(lpLibFileName, RTLD_LAZY | RTLD_GLOBAL);
	
	if (!handle)
	{
		NSLog(@"%s", dlerror());
		return 0;
	}
	
	return handle;
}

BOOL FreeLibrary(HMODULE hLibModule)
{
	if (dlclose(hLibModule))
	{
		NSLog(@"%s", dlerror());
		
		return FALSE;
	}
	
	return TRUE;
}

void *GetProcAddress (HMODULE hModule, LPCSTR lpProcName)
{
	return dlsym(hModule, lpProcName);
}

void ZeroMemory(void *obj, int size)
{
	memset(obj, 0, size);
}

void AfxOleLockApp()
{
	
}

DWORD GetCurrentDirectory(DWORD nBufferLength, LPSTR lpBuffer)
{
	NSFileManager *fm = [NSFileManager defaultManager];
	NSString *str = [fm currentDirectoryPath];
	
	strncpy(lpBuffer, [str UTF8String], nBufferLength);
	
	return [str length];
}

BOOL SetCurrentDirectory(LPCSTR lpPathName)
{
	NSFileManager *fm = [NSFileManager defaultManager];
	BOOL res = [fm changeCurrentDirectoryPath:[NSString stringWithUTF8String: lpPathName]];
	
	return res;
}

BOOL SHGetSpecialFolderPath( HWND hwnd, LPSTR pszPath,  int csidl,  BOOL fCreate)
{
	NSSearchPathDirectory search;
	NSSearchPathDomainMask domain = NSUserDomainMask | NSLocalDomainMask;
	
	switch(csidl)
	{
		case CSIDL_DESKTOP: search = NSDesktopDirectory; break;
		case CSIDL_INTERNET: search = NSSharedPublicDirectory; break;
		case CSIDL_PROGRAMS: search = NSApplicationDirectory; break;
		case CSIDL_CONTROLS: search = NSPreferencePanesDirectory; break;
		case CSIDL_PRINTERS: search = NSPrinterDescriptionDirectory; break;
		//case CSIDL_PERSONAL: search = NSUserDirectory; break;
		case CSIDL_FAVORITES: search = NSDesktopDirectory; break;
		case CSIDL_STARTUP: search = NSDesktopDirectory; break;
		case CSIDL_RECENT: search = NSDesktopDirectory; break;
		case CSIDL_SENDTO: search = NSDesktopDirectory; break;
		case CSIDL_BITBUCKET: search = NSDesktopDirectory; break;
		case CSIDL_STARTMENU: search = NSDesktopDirectory; break;
		case CSIDL_MYDOCUMENTS: search = NSDocumentDirectory; break;
		case CSIDL_MYMUSIC: search = NSMusicDirectory; break;
		case CSIDL_MYVIDEO: search = NSMoviesDirectory; break;
		case CSIDL_DESKTOPDIRECTORY: search = NSDesktopDirectory; break;
		case CSIDL_DRIVES: search = NSDesktopDirectory; break;
		case CSIDL_NETWORK: search = NSDesktopDirectory; break;
		case CSIDL_NETHOOD: search = NSDesktopDirectory; break;
		case CSIDL_FONTS: search = NSDesktopDirectory; break;
	}
	
	NSFileManager *fm = [NSFileManager defaultManager];
	NSURL *url = [fm URLForDirectory:search inDomain: domain appropriateForURL:(NSURL *)url create:fCreate ? YES : NO error:nil];
	
	if (url)
	{
		NSString *str = [url path];
		
		strcpy(pszPath, [str UTF8String]);
		
		return TRUE;
	}
	
	return FALSE;
}

BOOL IsDBCSLeadByte(BYTE  TestChar)
{
	return FALSE;
}

HANDLE LoadImage(HINSTANCE hInst,
				 LPCSTR name,
				 UINT type,
				 int cx,
				 int cy,
				 UINT fuLoad)
{
	NSLog(@"to do LoadImage");
	return 0;
}

UINT MapVirtualKey(UINT uCode, UINT uMapType)
{
	return uCode;
	
	/*
	UINT res = uCode;
	
	switch(uCode)
	{
		case VK_RETURN:		res = NSEnterCharacter; break;			
		case VK_BACK:		res = NSBackspaceCharacter; break;
		case VK_TAB:		res = NSTabCharacter; break;
		//case VK_RETURN:		res = NSNewlineCharacter; break;
		//case VK_RETURN:		res = NSFormFeedCharacter; break;
		//case VK_RETURN:		res = NSCarriageReturnCharacter; break;
		//case VK_BACK:		res = NSBackTabCharacter; break;
		case VK_DELETE:		res = NSDeleteCharacter; break;
		case VK_SEPARATOR:	res = NSLineSeparatorCharacter; break;
		//case VK_SEPARATOR:	res = NSParagraphSeparatorCharacter; break;
			
			
			 
			 #define VK_LBUTTON 0x01
			 #define VK_RBUTTON 0x02
			 #define VK_CANCEL 0x03
			 #define VK_MBUTTON 0x04 
			 
#define VK_NUMPAD0 0x60
#define VK_NUMPAD1 0x61
#define VK_NUMPAD2 0x62
#define VK_NUMPAD3 0x63
#define VK_NUMPAD4 0x64
#define VK_NUMPAD5 0x65
#define VK_NUMPAD6 0x66
#define VK_NUMPAD7 0x67
#define VK_NUMPAD8 0x68
#define VK_NUMPAD9 0x69
#define VK_MULTIPLY 0x6A
#define VK_ADD 0x6B
#define VK_SUBTRACT 0x6D
#define VK_DECIMAL 0x6E
#define VK_DIVIDE 0x6F
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_F3 0x72
#define VK_F4 0x73
#define VK_F5 0x74
#define VK_F6 0x75
#define VK_F7 0x76
#define VK_F8 0x77
#define VK_F9 0x78
#define VK_F10 0x79
#define VK_F11 0x7A
#define VK_F12 0x7B
#define VK_F13 0x7C
#define VK_F14 0x7D
#define VK_F15 0x7E
#define VK_F16 0x7F
#define VK_F17 0x80
#define VK_F18 0x81
#define VK_F19 0x82
#define VK_F20 0x83
#define VK_F21 0x84
#define VK_F22 0x85
#define VK_F23 0x86
#define VK_F24 0x87
			 
			
	}
	
	return res;
	 */
}

int GetKeyNameText(LONG lParam, LPSTR lpString,int cchSize)
{
	NSString *str;
	unichar ch;
	
	strcpy(lpString, "");

	switch(lParam)
	{
		case VK_RETURN: ch = NSCarriageReturnCharacter;	str = [NSString stringWithCharacters: &ch length: 1]; strcpy(lpString, [str UTF8String]); break;			
		case VK_BACK:	ch = NSBackspaceCharacter; str = [NSString stringWithCharacters: &ch length: 1]; strcpy(lpString, [str UTF8String]); break;
		case VK_TAB:	ch = NSBackTabCharacter; str = [NSString stringWithCharacters: &ch length: 1]; strcpy(lpString, [str UTF8String]); break;
		case VK_DELETE:	ch = NSDeleteCharacter;	str = [NSString stringWithCharacters: &ch length: 1]; strcpy(lpString, [str UTF8String]); break;
		case VK_SEPARATOR:	ch = NSLineSeparatorCharacter;	str = [NSString stringWithCharacters: &ch length: 1]; strcpy(lpString, [str UTF8String]); break;
										
		case VK_LBUTTON:	strcpy(lpString, ""); break;
		case VK_RBUTTON:	strcpy(lpString, ""); break;
		case VK_CANCEL:		strcpy(lpString, ""); break;
		case VK_MBUTTON:	strcpy(lpString, ""); break;
		case VK_NUMPAD0:	strcpy(lpString, "0"); break;
		case VK_NUMPAD1:	strcpy(lpString, "1"); break;
		case VK_NUMPAD2:	strcpy(lpString, "2"); break;
		case VK_NUMPAD3:	strcpy(lpString, "3"); break;
		case VK_NUMPAD4:	strcpy(lpString, "4"); break;
		case VK_NUMPAD5:	strcpy(lpString, "5"); break;
		case VK_NUMPAD6:	strcpy(lpString, "6"); break;
		case VK_NUMPAD7:	strcpy(lpString, "7"); break;
		case VK_NUMPAD8:	strcpy(lpString, "8"); break;
		case VK_NUMPAD9:	strcpy(lpString, "9"); break;
		case VK_MULTIPLY:	strcpy(lpString, ""); break;
		case VK_ADD:		strcpy(lpString, ""); break;
		case VK_SUBTRACT:	strcpy(lpString, ""); break;
		case VK_DECIMAL:	strcpy(lpString, ""); break;
		case VK_DIVIDE:		strcpy(lpString, ""); break;
		case VK_F1:			strcpy(lpString, "F1"); break;
		case VK_F2:			strcpy(lpString, "F2"); break;
		case VK_F3:			strcpy(lpString, "F3"); break;
		case VK_F4:			strcpy(lpString, "F4"); break;
		case VK_F5:			strcpy(lpString, "F5"); break;
		case VK_F6:			strcpy(lpString, "F6"); break;
		case VK_F7:			strcpy(lpString, "F7"); break;
		case VK_F8:			strcpy(lpString, "F8"); break;
		case VK_F9:			strcpy(lpString, "F9"); break;
		case VK_F10:		strcpy(lpString, "F10"); break;
		case VK_F11:		strcpy(lpString, "F11"); break;
		case VK_F12:		strcpy(lpString, "F12"); break;
		case VK_F13:		strcpy(lpString, "F13"); break;
		case VK_F14:		strcpy(lpString, "F14"); break;
		case VK_F15:		strcpy(lpString, "F15"); break;
		case VK_F16:		strcpy(lpString, "F16"); break;
		case VK_F17:		strcpy(lpString, "F17"); break;
		case VK_F18:		strcpy(lpString, "F18"); break;
		case VK_F19:		strcpy(lpString, "F19"); break;
		case VK_F20:		strcpy(lpString, "F20"); break;
		case VK_F21:		strcpy(lpString, "F21"); break;
		case VK_F22:		strcpy(lpString, "F22"); break;
		case VK_F23:		strcpy(lpString, "F23"); break;
		case VK_F24:		strcpy(lpString, "F24"); break;
			 
			
	}
	
	return strlen(lpString);
}

HMENU CreateMenu()
{
	NSMenu *menu = [NSMenu alloc];
	
	return menu;
}

int GetMenuItemCount(HMENU hMenu)
{
	NSMenu *menu = (NSMenu *)hMenu;
	
	if (menu)
	{
		return [menu numberOfItems];
	}
	
	return 0;
}

UINT  GetMenuState( HMENU hMenu, UINT uId,  UINT uFlags)
{
	UINT state = 0;
	
	if (hMenu)
	{
		NSMenu *menu = (NSMenu *)hMenu;		
		NSMenuItem *item = [menu itemAtIndex: uId];
		
		if (item)
		{
			if ([item state] == NSOnState ||
				[item state] == NSMixedState)
			{
				state = state | MF_CHECKED;
			}
				
			if ([item isSeparatorItem])
			{
				state = state | MF_SEPARATOR;
			}
				
			if ([item submenu])
			{
				state = state | MF_POPUP;	
			}
			
			if (![item isEnabled])
			{
				state = state | MF_DISABLED;
			}			
		}
	}
	
	return state;
}

BOOL AppendMenu(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCTSTR lpNewItem)
{
	if (hMenu)
	{
		NSMenu *menu = (NSMenu *)hMenu;
		//assert(m_NMenu || m_owner);
		
		//nFlags
		//MF_OWNERDRAW Contains an application-supplied 32-bit value that the application can use to maintain additional data associated with the menu item. This 32-bit value is available to the application when it processes WM_MEASUREITEM and WM_DRAWITEM messages. The value is stored in the itemData member of the structure supplied with those messages.
		//MF_STRING Contains a pointer to a null-terminated string. This is the default interpretation.
		//MF_SEPARATOR The lpszNewItem parameter is ignored (not needed).
		//&About SimpleDialog2...
		NSString *strItem = nil;
		NSMenuItem *menuNewItem = nil;
		NSInteger mask = 0;
		NSString *strItemKeyCommand = nil;
		
		if (lpNewItem)
		{
			strItem = [NSString stringWithUTF8String: lpNewItem];
			strItem = [strItem stringByReplacingOccurrencesOfString: @"&" withString: @""];
		}
		
		NSArray *arrTabs = [strItem componentsSeparatedByString:@"\\t"];
		
		if ([arrTabs count] < 2)
		{
			arrTabs = [strItem componentsSeparatedByString:@"\t"];
		}
		
		if ([arrTabs count] == 2)
		{
			strItem = [arrTabs objectAtIndex: 0];
			
			NSString *menuItemKeyCommand = [arrTabs objectAtIndex: 1];			
			NSArray *arrKeys = [menuItemKeyCommand componentsSeparatedByString:@"+"];
			
			for(int i = 0; i < [arrKeys count]; i++)
			{
				NSString *strKeyCommand = [arrKeys objectAtIndex: i];
				
				if ([strKeyCommand caseInsensitiveCompare:@"Ctrl"] == 0)
				{
					mask = mask | NSCommandKeyMask;
				}
				else
					if ([strKeyCommand caseInsensitiveCompare:@"Shift"] == 0)
					{
						mask = mask | NSShiftKeyMask;
					}					
					else
						if ([strKeyCommand caseInsensitiveCompare:@"Alt"] == 0)
						{
							mask = mask | NSAlternateKeyMask;
						}
						else 
						{
							if (mask == NSCommandKeyMask)
							{
								strItemKeyCommand = [strKeyCommand lowercaseString];
							}
							//[menuItem setKeyEquivalent: strKeyCommand];
						}
				
				//NSControlKeyMask
			}
			
			//[menuItem setKeyEquivalentModifierMask: mask];
		}
		
		if (uIDNewItem == 0x0010 && uFlags != MF_POPUP)//IDM_ABOUTBOX)
		{
			NSMenuItem *menuItem = [menu itemAtIndex:0];
			
			if (menuItem && uFlags == MF_STRING)
			{
				//CNSWindowDelegate *dlg = (CNSWindowDelegate *)m_owner->GetWindowDelegate();
				//CNSWindow *win = (CNSWindow *)m_owner->GetNSWindow();
				
				//NSMenu *mennn = [NSApp windowsMenu];
				
				//[NSApp setWindowsMenu:[NSApp mainMenu]];
				
				[menuItem setTitle: strItem];
				
				//[dlg setMenuAction: menuItem];
				
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
			if (uFlags & MF_POPUP)
			{
				NSMenu *menuPop = (NSMenu *)uIDNewItem;
				
				menuNewItem = [[NSMenuItem alloc] autorelease];//[menu addItemWithTitle:strItem action:NULL /*[dlg getMenuCall]*/ keyEquivalent: @""];
				
				[menuNewItem setTitle:strItem];
				[menuPop setTitle:strItem];
				[menu addItem: menuNewItem];
				[menuNewItem setSubmenu: menuPop];
			}
			else
			if (uFlags & MF_STRING || uFlags & MF_OWNERDRAW)
			{
				menuNewItem = [menu addItemWithTitle:strItem action:NULL /*[dlg getMenuCall]*/ keyEquivalent: @""];
				[menuNewItem setKeyEquivalentModifierMask: mask];
				
				if (strItemKeyCommand)
				{
					[menuNewItem setKeyEquivalent: strItemKeyCommand];
				}
				
				[menuNewItem setTag: uIDNewItem];
				[menuNewItem setTarget:pMainAppCocoa];
				[menuNewItem setAction:@selector(menuEventHandle:)];
			}
			else 
			if (uFlags & MF_SEPARATOR)
			{
				NSMenuItem *sep = [NSMenuItem separatorItem];				
				[menu addItem: sep];
			}
			else
			{
				NSLog(@"Cannot add menu item");				
			}
		}
		
		if (menuNewItem)
		{
			[menu setAutoenablesItems:NO];
			[menuNewItem setEnabled:true];
		}
		
		return TRUE;
	}
	
	return FALSE;
}

BOOL RemoveMenu(HMENU hMenu, UINT uPosition, UINT uFlags)
{
	if (hMenu)
	{
		NSMenu *menu = (NSMenu *)hMenu;		
		
		[menu removeItemAtIndex: uPosition];
		
		
		return TRUE;
	}
	
	return FALSE;
}

BOOL DestroyMenu(HMENU hMenu)
{
	NSMenu *menu = (NSMenu *)hMenu;
	
	if (menu)
	{
		[menu release];
		
		return TRUE;
	}
	
	return FALSE;
}

BOOL DestroyAcceleratorTable(HACCEL hAccel)
{
	NSLog(@"to do LoadImage");
	return 0;
}

