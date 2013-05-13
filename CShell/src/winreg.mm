/*
 *  winbase.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "winreg.h"

#include <libkern/OSAtomic.h>
#import <Cocoa/Cocoa.h>

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
	NSLog(@"TO DO RegCreateKeyEx");
	return 0;
}

LSTATUS RegOpenKeyEx(HKEY hKey,
					 LPCSTR lpSubKey,
					 DWORD ulOptions,
					 REGSAM samDesired,
					 PHKEY phkResult
					 )
{
	NSLog(@"TO DO RegOpenKeyEx");
	return 0;
}

LSTATUS RegQueryValueEx(HKEY hKey,
						LPCSTR lpValueName,
						LPDWORD lpReserved,
						LPDWORD lpType,
						LPBYTE lpData,
						LPDWORD lpcbData
						)
{
	NSLog(@"TO DO RegQueryValueEx");
	return 0;
}


LSTATUS RegSetValueEx ( HKEY hKey,
					   LPCSTR lpValueName,
					   DWORD Reserved,
					   DWORD dwType,
					   const BYTE* lpData,
					   DWORD cbData
					   )
{
	NSLog(@"TO DO RegSetValueEx");
	return 0;
}

LSTATUS RegCloseKey(HKEY hKey)
{
	NSLog(@"TO DO RegCloseKey");
	return 0;
}

LSTATUS RegDeleteKey(HKEY hKey, LPCSTR lpSubKey)
{
	NSLog(@"TO DO RegDeleteKey");
	return 0;
}

LSTATUS RegDeleteValue(HKEY hKey, LPCSTR lpValueName)
{
	NSLog(@"TO DO RegDeleteValue");
	return 0;
}

LSTATUS RegSaveKey(HKEY hKey, LPCSTR lpFile, const LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	NSLog(@"TO DO RegSaveKey");
	return 0;
}

LSTATUS RegRestoreKey(HKEY hKey, LPCSTR lpFile, DWORD dwFlags)
{
	NSLog(@"TO DO RegRestoreKey");
	return 0;
}

LSTATUS RegEnumKeyEx(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName,
					 LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime)
{
	NSLog(@"TO DO RegEnumKeyEx");
	return 0;
}