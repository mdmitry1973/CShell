/*
 *  winbase.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef WIN_BASE
#define WIN_BASE 1

#include "CDef.h"

#define NOPARITY            0
#define ODDPARITY           1
#define EVENPARITY          2
#define MARKPARITY          3
#define SPACEPARITY         4

#define ONESTOPBIT          0
#define ONE5STOPBITS        1
#define TWOSTOPBITS         2

#define IGNORE              0       // Ignore signal
#define INFINITE            0xFFFFFFFF  // Infinite timeout

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
} PROCESS_INFORMATION, *PPROCESS_INFORMATION, *LPPROCESS_INFORMATION;

typedef struct _STARTUPINFO {
    DWORD   cb;
    LPSTR  lpReserved;
    LPSTR  lpDesktop;
    LPSTR  lpTitle;
    DWORD   dwX;
    DWORD   dwY;
    DWORD   dwXSize;
    DWORD   dwYSize;
    DWORD   dwXCountChars;
    DWORD   dwYCountChars;
    DWORD   dwFillAttribute;
    DWORD   dwFlags;
    WORD    wShowWindow;
    WORD    cbReserved2;
    LPBYTE  lpReserved2;
    HANDLE  hStdInput;
    HANDLE  hStdOutput;
    HANDLE  hStdError;
} STARTUPINFO, *LPSTARTUPINFO;

LONG InterlockedDecrement(LONG volatile *Addend);
LONG InterlockedIncrement(LONG volatile *Addend);

//char *_fullpath(char *absPath, const char *relPath, size_t maxLength);
int _mkdir(const char *dirname);
int _rmdir(const char *dirname);
int _access(const char *path, int mode);
DWORD GetModuleFileName(HMODULE hModule, LPTSTR lpFilename, DWORD nSize);
DWORD GetLongPathName(LPCTSTR lpszShortPath, LPTSTR lpszLongPath, DWORD cchBuffer);
DWORD GetTempPath(DWORD nBufferLength, LPTSTR lpBuffer);

typedef struct _FILETIME {
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

typedef struct _WIN32_FIND_DATA {
	DWORD    dwFileAttributes;
	FILETIME ftCreationTime;
	FILETIME ftLastAccessTime;
	FILETIME ftLastWriteTime;
	DWORD    nFileSizeHigh;
	DWORD    nFileSizeLow;
	DWORD    dwReserved0;
	DWORD    dwReserved1;
	TCHAR    cFileName[MAX_PATH];
	TCHAR    cAlternateFileName[14];
} WIN32_FIND_DATA, *PWIN32_FIND_DATA, *LPWIN32_FIND_DATA;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5

#define INVALID_HANDLE_VALUE ((HANDLE)(LONG_PTR)-1)
#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)

#define FS_CASE_IS_PRESERVED            FILE_CASE_PRESERVED_NAMES
#define FS_CASE_SENSITIVE               FILE_CASE_SENSITIVE_SEARCH
#define FS_UNICODE_STORED_ON_DISK       FILE_UNICODE_ON_DISK
#define FS_PERSISTENT_ACLS              FILE_PERSISTENT_ACLS
#define FS_VOL_IS_COMPRESSED            FILE_VOLUME_IS_COMPRESSED
#define FS_FILE_COMPRESSION             FILE_FILE_COMPRESSION
#define FS_FILE_ENCRYPTION              FILE_SUPPORTS_ENCRYPTION

HANDLE CreateMutex(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCTSTR lpName);
HANDLE OpenMutex(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCTSTR lpName);
DWORD WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);

BOOL CreateProcess(LPCTSTR lpApplicationName, LPTSTR lpCommandLine,
				   LPSECURITY_ATTRIBUTES lpProcessAttributes,
				   LPSECURITY_ATTRIBUTES lpThreadAttributes,
				   BOOL bInheritHandles, DWORD dwCreationFlags,
				   LPVOID lpEnvironment, LPCTSTR lpCurrentDirectory,
				   LPSTARTUPINFO lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);

HANDLE FindFirstFile(LPCTSTR lpFileName,LPWIN32_FIND_DATA lpFindFileData);
BOOL FindNextFile(HANDLE hFindFile, LPWIN32_FIND_DATA lpFindFileData);
BOOL FindClose(HANDLE hFindFile);
BOOL CopyFile(LPCTSTR lpExistingFileName, LPCTSTR lpNewFileName, BOOL bFailIfExists);
BOOL DeleteFile(LPCTSTR lpFileName);
BOOL RemoveDirectory(LPCTSTR lpPathName);
DWORD GetFullPathName(LPCTSTR lpFileName, DWORD nBufferLength,
					LPTSTR lpBuffer, LPTSTR *lpFilePart);
UINT GetTempFileName(LPCTSTR lpPathName,
					LPCTSTR lpPrefixString,
					UINT uUnique, LPTSTR lpTempFileName);
BOOL GetVolumeInformation(LPCSTR lpRootPathName, LPSTR lpVolumeNameBuffer,
					  DWORD nVolumeNameSize,
					  LPDWORD lpVolumeSerialNumber,
					LPDWORD lpMaximumComponentLength,
					  LPDWORD lpFileSystemFlags,
					  LPSTR lpFileSystemNameBuffer,
					  DWORD nFileSystemNameSize);
DWORD GetFileAttributes(LPCSTR lpFileName);
BOOL SetFileAttributes(LPCSTR lpFileName, DWORD dwFileAttributes);
HANDLE CreateFile(LPCSTR lpFileName,
			  DWORD dwDesiredAccess,
			 DWORD dwShareMode,
			 LPSECURITY_ATTRIBUTES lpSecurityAttributes,
			  DWORD dwCreationDisposition,
			   DWORD dwFlagsAndAttributes,
			 HANDLE hTemplateFile
			);

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

//
//  Time Flags for GetTimeFormat.
//
#define TIME_NOMINUTESORSECONDS   0x00000001  // do not use minutes or seconds
#define TIME_NOSECONDS            0x00000002  // do not use seconds
#define TIME_NOTIMEMARKER         0x00000004  // do not use time marker
#define TIME_FORCE24HOURFORMAT    0x00000008  // always use 24 hour format


//
//  Date Flags for GetDateFormat.
//
#define DATE_SHORTDATE            0x00000001  // use short date picture
#define DATE_LONGDATE             0x00000002  // use long date picture
#define DATE_USE_ALT_CALENDAR     0x00000004  // use alternate calendar (if any)

int GetTimeFormat(LCID Locale, DWORD dwFlags,
				  const SYSTEMTIME *lpTime, LPCTSTR lpFormat,
				  LPTSTR lpTimeStr, int cchTime);

int GetDateFormat(LCID Locale, DWORD dwFlags, SYSTEMTIME *lpDate,
			   LPCSTR lpFormat, LPSTR lpDateStr, int cchDate);
BOOL SystemTimeToFileTime(SYSTEMTIME *lpSystemTime, LPFILETIME lpFileTime);
BOOL GetFileTime(HANDLE hFile,
			 LPFILETIME lpCreationTime,
			 LPFILETIME lpLastAccessTime,
			 LPFILETIME lpLastWriteTime);
BOOL SetFileTime(HANDLE hFile,
			 const FILETIME *lpCreationTime,
			 const FILETIME *lpLastAccessTime,
			 const FILETIME *lpLastWriteTime);
BOOL LocalFileTimeToFileTime(const FILETIME *lpLocalFileTime, LPFILETIME lpFileTime);
DWORD SearchPath(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension,  DWORD nBufferLength,
			LPSTR lpBuffer, LPSTR *lpFilePart);

UINT GetProfileInt(LPCSTR lpAppName, LPCSTR lpKeyName, INT nDefault);
DWORD GetPrivateProfileString(LPCSTR lpAppName,
						  LPCSTR lpKeyName,
						  LPCSTR lpDefault,
						 LPSTR lpReturnedString,
						      DWORD nSize,
						  LPCSTR lpFileName);

DWORD GetCurrentDirectory(DWORD nBufferLength, LPSTR lpBuffer);
BOOL SetCurrentDirectory(LPCSTR lpPathName);

#if defined(CSHELLQT_LIBRARY)

#define lstrcpy strcpy
#define lstrlen strlen
#define lstrcpyn  strncpy
#define _strdup wcsdup
#define _tcsdup wcsdup
#define _tcsdec strdec
#define _unlink remove
#define _tcsrchr strchr

#define _stprintf sprintf
#define _tcscmp strcmp
#define _tcscpy strcpy

#define _fgetts fgets
#define _TEOF EOF
#define _tcslen strlen
#define _ttol atol

#else

#define lstrcpy strcpy
#define lstrlen strlen
#define lstrcpyn  strncpy
#define _strdup strdup
#define _tcsdup strdup
#define _tcsdec strdec
#define _unlink remove
#define _tcsrchr strchr

#define _stprintf sprintf
#define _tcscmp strcmp
#define _tcscpy strcpy

#define _fgetts fgets
#define _TEOF EOF
#define _tcslen strlen
#define _ttol atol

#endif

char *strupr(char *str);
void _splitpath( const char *path, char *drive, char *dir, char *fname, char *ext );

BOOL CloseHandle(HANDLE hObject);
DWORD GetLastError();

LPSTR CharUpper(LPSTR lpsz);
BOOL PathIsUNC( LPCSTR pszPath);
BOOL PathStripToRoot( LPSTR pszPath);

//DWORD GetVersion();

HMODULE LoadLibrary(LPCSTR lpLibFileName);
BOOL FreeLibrary(HMODULE hLibModule);
void *GetProcAddress (HMODULE hModule, LPCSTR lpProcName);

HANDLE GetCurrentProcess();
DWORD GetCurrentProcessId();

HANDLE GetCurrentThread();
DWORD GetCurrentThreadId();


void SHChangeNotify(LONG wEventId, UINT uFlags, LPCVOID dwItem1, LPCVOID dwItem2);

BOOL PeekMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
LRESULT DispatchMessage(const MSG *lpmsg);

DWORD GetTickCount();

void ZeroMemory(void *obj, int size);

void AfxOleLockApp();

void CMemoryPoolDrain();

HANDLE LoadImage(HINSTANCE hInst,
		    LPCSTR name,
		    UINT type,
		    int cx,
		    int cy,
		    UINT fuLoad);


BOOL IsDBCSLeadByte(BYTE  TestChar);

UINT MapVirtualKey(UINT uCode, UINT uMapType);

int GetKeyNameText( LONG lParam,LPSTR lpString,int cchSize);

HMENU CreateMenu();
int GetMenuItemCount(HMENU hMenu);
UINT  GetMenuState( HMENU hMenu, UINT uId,  UINT uFlags);
BOOL AppendMenu(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCTSTR lpNewItem);
BOOL RemoveMenu(HMENU hMenu, UINT uPosition, UINT uFlags);
BOOL DestroyMenu(HMENU hMenu);
BOOL DestroyAcceleratorTable(HACCEL hAccel);

#endif//WIN_BASE