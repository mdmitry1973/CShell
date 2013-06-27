/*
 *  winreg.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef WIN_REG
#define WIN_REG 1

#include "CDef.h"

#include "afxwin.h"

typedef LONG LSTATUS;

//
//
// Predefined Value Types.
//

#define REG_NONE                    0   // No value type
#define REG_SZ                      1   // Unicode nul terminated string
#define REG_EXPAND_SZ               2   // Unicode nul terminated string
// (with environment variable references)
#define REG_BINARY                  3   // Free form binary
#define REG_DWORD                   4   // 32-bit number
#define REG_DWORD_LITTLE_ENDIAN     4   // 32-bit number (same as REG_DWORD)
#define REG_DWORD_BIG_ENDIAN        5   // 32-bit number
#define REG_LINK                    6   // Symbolic Link (unicode)
#define REG_MULTI_SZ                ( 7 )   // Multiple Unicode strings
#define REG_RESOURCE_LIST           ( 8 )   // Resource list in the resource map
#define REG_FULL_RESOURCE_DESCRIPTOR ( 9 )  // Resource list in the hardware description
#define REG_RESOURCE_REQUIREMENTS_LIST ( 10 )
#define REG_QWORD                   ( 11 )  // 64-bit number
#define REG_QWORD_LITTLE_ENDIAN     ( 11 )  // 64-bit number (same as REG_QWORD)

typedef ACCESS_MASK REGSAM;
typedef HKEY *PHKEY;

//
// Reserved Key Handles.
//

extern const void *nsSTR_HKEY_CLASSES_ROOT;
extern const void *nsSTR_HKEY_CURRENT_USER;
extern const void *nsSTR_HKEY_LOCAL_MACHINE;
extern const void *nsSTR_HKEY_USERS;
extern const void *nsSTR_HKEY_PERFORMANCE_DATA;
extern const void *nsSTR_HKEY_PERFORMANCE_TEXT;
extern const void *nsSTR_HKEY_PERFORMANCE_NLSTEXT;
extern const void *nsSTR_HKEY_CURRENT_CONFIG;
extern const void *nsSTR_HKEY_DYN_DATA;
extern const void *nsSTR_HKEY_CURRENT_USER_LOCAL_SETTINGS;

#define HKEY_CLASSES_ROOT                   (( HKEY ) nsSTR_HKEY_CLASSES_ROOT)//(ULONG_PTR)((LONG)0x80000000) )
#define HKEY_CURRENT_USER                   (( HKEY ) nsSTR_HKEY_CURRENT_USER)//(ULONG_PTR)((LONG)0x80000001) )
#define HKEY_LOCAL_MACHINE                  (( HKEY ) nsSTR_HKEY_LOCAL_MACHINE)//(ULONG_PTR)((LONG)0x80000002) )
#define HKEY_USERS                          (( HKEY ) nsSTR_HKEY_USERS)//(ULONG_PTR)((LONG)0x80000003) )
#define HKEY_PERFORMANCE_DATA               (( HKEY ) nsSTR_HKEY_PERFORMANCE_DATA)//(ULONG_PTR)((LONG)0x80000004) )
#define HKEY_PERFORMANCE_TEXT               (( HKEY ) nsSTR_HKEY_PERFORMANCE_TEXT)//(ULONG_PTR)((LONG)0x80000050) )
#define HKEY_PERFORMANCE_NLSTEXT            (( HKEY ) nsSTR_HKEY_PERFORMANCE_NLSTEXT)//(ULONG_PTR)((LONG)0x80000060) )
#define HKEY_CURRENT_CONFIG                 (( HKEY ) nsSTR_HKEY_CURRENT_CONFIG)//(ULONG_PTR)((LONG)0x80000005) )
#define HKEY_DYN_DATA                       (( HKEY ) nsSTR_HKEY_DYN_DATA)//(ULONG_PTR)((LONG)0x80000006) )
#define HKEY_CURRENT_USER_LOCAL_SETTINGS    (( HKEY ) nsSTR_HKEY_CURRENT_USER_LOCAL_SETTINGS)//(ULONG_PTR)((LONG)0x80000007) )

HKEY createNSKey(const char *);

LSTATUS RegCreateKeyEx(HKEY hKey,
				  LPCSTR lpSubKey,
				  DWORD Reserved,
				  LPSTR lpClass,
				  DWORD dwOptions,
				  REGSAM samDesired,
				  const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
				  PHKEY phkResult,
				  LPDWORD lpdwDisposition
				 );
LSTATUS RegOpenKeyEx(HKEY hKey,
			    LPCSTR lpSubKey,
			    DWORD ulOptions,
			    REGSAM samDesired,
			    PHKEY phkResult
			   );
LSTATUS RegQueryValueEx(HKEY hKey,
				   LPCSTR lpValueName,
				   LPDWORD lpReserved,
				   LPDWORD lpType,
				   LPBYTE lpData,
				   LPDWORD lpcbData
				  );

LSTATUS RegQueryValueEx( HKEY hKey,
				   LPCSTR lpValueName,
				   LPDWORD lpReserved,
				   LPDWORD lpType,
				  LPBYTE lpData,
						LPDWORD lpcbData);
LSTATUS RegSetValueEx ( HKEY hKey,
				 LPCSTR lpValueName,
				 DWORD Reserved,
				 DWORD dwType,
				const BYTE* lpData,
				 DWORD cbData
				);
LSTATUS RegCloseKey(HKEY hKey);
LSTATUS RegDeleteKey(HKEY hKey, LPCSTR lpSubKey);
LSTATUS RegDeleteValue(HKEY hKey, LPCSTR lpValueName);

LSTATUS RegSaveKey(HKEY hKey, LPCSTR lpFile, const LPSECURITY_ATTRIBUTES lpSecurityAttributes);
LSTATUS RegRestoreKey(HKEY hKey, LPCSTR lpFile, DWORD dwFlags);
LSTATUS RegEnumKeyEx(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName,
			    LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime);
LSTATUS RegEnumKey(HKEY hKey, DWORD dwIndex, LPSTR lpName, DWORD cchName);
LSTATUS RegOpenKey (HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult);
LSTATUS RegSetValue(
			   HKEY hKey,
			   LPCSTR lpSubKey,
			   DWORD dwType,
			  LPCSTR lpData,
			   DWORD cbData);
LSTATUS RegCreateKey ( HKEY hKey,
			    LPCSTR lpSubKey,
			    PHKEY phkResult);
LSTATUS RegEnumValue (HKEY hKey, DWORD dwIndex, LPSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData);
LSTATUS  SHDeleteKey(HKEY hkey, LPCSTR pszSubKey);
LSTATUS RegQueryValue ( HKEY hKey, LPCSTR lpSubKey, LPSTR lpData, PLONG lpcbData);

#endif//WIN_REG