/*
 *  CDef.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/8/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <assert.h>

#ifndef CDEF_DEFINE
#define CDEF_DEFINE 1

#if defined(CSHELLQT_LIBRARY)
#include <QtCore/QtGlobal>
#if defined(CSHELL_LIB_DLL)
#  define CSHELL_LIB_EXPORT Q_DECL_EXPORT
#else
#  define CSHELL_LIB_EXPORT Q_DECL_IMPORT
#endif
#else
#  define CSHELL_LIB_EXPORT
#endif

#ifdef Q_OS_WIN32
#include "qt_windows.h"
#endif

#if defined(CSHELLQT_LIBRARY)
#define stdString std::wstring
#define _T(x) L ##x
#else
#define stdString std::string
#define _T(x) x
#endif

#define CSELL_MAC 1

#define afx_msg
#define AFXAPI

#define AFX_CLASS_EXPORT  __attribute__((visibility("default")))
#define AFX_CLASS_IMPORT 

typedef struct __POSITION { } *POSITION;
#define BEFORE_START_POSITION ((POSITION)-1L)

#ifndef BOOL
#define BOOL signed char//int
#endif

#ifndef FALSE
	#define FALSE false
	#define TRUE true
#endif
#ifndef NULL
	#define NULL 0
#endif
///#define ASSERT(x) ns_assert(x);

#define IDOK 1
#define IDCANCEL 2

#include "afxres.h"

#define IDOK                1
#define IDCANCEL            2
#define IDABORT             3
#define IDRETRY             4
#define IDIGNORE            5
#define IDYES               6
#define IDNO                7
#define IDTRYAGAIN			10
#define IDCONTINUE			11

#define ID_APPLY_NOW                    0x3021
#define ID_WIZBACK                      0x3023
#define ID_WIZNEXT                      0x3024
#define ID_WIZFINISH                    0x3025

#define FWS_ADDTOTITLE 0x00008000L // modify title based on content. You can always try to add this line.

// Mode indicators in status bar - these are routed like commands
#define ID_INDICATOR_EXT                0xE700  // extended selection indicator
#define ID_INDICATOR_CAPS               0xE701  // cap lock indicator
#define ID_INDICATOR_NUM                0xE702  // num lock indicator
#define ID_INDICATOR_SCRL               0xE703  // scroll lock indicator
#define ID_INDICATOR_OVR                0xE704  // overtype mode indicator
#define ID_INDICATOR_REC                0xE705  // record mode indicator
#define ID_INDICATOR_KANA               0xE706  // kana lock indicator
#define ID_SEPARATOR                    0   // special separator value

#define PSWIZB_BACK             0x00000001
#define PSWIZB_NEXT             0x00000002
#define PSWIZB_FINISH           0x00000004
#define PSWIZB_DISABLEDFINISH   0x00000008

/////////////////////////////////////////////////////////////////////////////
// Command notifications for CCmdTarget notifications

#define CN_COMMAND              0               // void ()
#define CN_UPDATE_COMMAND_UI    ((UINT)(-1))    // void (CCmdUI*)
#define CN_EVENT                ((UINT)(-2))    // OLE event
#define CN_OLECOMMAND           ((UINT)(-3))    // OLE document command
#define CN_OLE_UNREGISTER       ((UINT)(-4))    // OLE unregister
// > 0 are control notifications
// < 0 are for MFC's use

#define _AFX_MRU_COUNT   4

#define TBSTYLE_FLAT 0x0800

typedef char CHAR;
typedef unsigned char BYTE;
typedef unsigned long DWORD;
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
typedef unsigned long long UINT64;
typedef long long INT64;
typedef unsigned short UINT16;
typedef int INT32;
typedef char CHAR8;
typedef unsigned char UCHAR;
typedef unsigned char UCHAR8;
typedef unsigned char UINT8;
typedef unsigned int UINT32;
typedef unsigned long ULONG; 
typedef short INT16;
typedef int INT;
typedef short SHORT;
typedef float FLOAT32;
typedef double FLOAT64;
typedef BYTE *LPBYTE;
typedef long LONG;
typedef int INT_PTR;
typedef DWORD LCID; 
typedef DWORD *LPDWORD;
typedef void* HANDLE;
typedef CHAR *LPSTR;

#ifdef __x86_64__ 
typedef unsigned long long UINT_PTR;
#else
typedef unsigned int UINT_PTR;
#endif

#ifdef __x86_64__ 
typedef long long LONG_PTR; 
#else
typedef long LONG_PTR;
#endif

#ifdef __x86_64__ 
typedef unsigned long long ULONG_PTR;
#else
typedef unsigned long ULONG_PTR;
#endif

#ifdef __x86_64__
typedef ULONG_PTR DWORD_PRT;
#else
typedef ULONG_PTR DWORD_PRT;
#endif

#ifdef __x86_64__ 
typedef unsigned long long UINT_PTR;
#else
typedef unsigned int UINT_PTR;
#endif

#ifndef CSHELLQT_LIBRARY

typedef char INT8;
typedef char *PTCHAR;
typedef int WORD;
typedef void* HICON;
typedef void* HCURSOR;
typedef void* HINSTANCE;
typedef void* HWND;
typedef void* HBRUSH;
typedef HANDLE HDC;
typedef HANDLE HBITMAP;
typedef HANDLE HFONT;
typedef HANDLE HPEN;
typedef void* HPALETTE;
typedef void* HMODULE;
typedef HANDLE HMENU;
typedef HANDLE HKEY;
typedef HANDLE HACCEL;
typedef HANDLE HDROP;
typedef HANDLE IDropTarget;
typedef void *LPDISPATCH;
typedef int LPARAM;
typedef CHAR TCHAR;
typedef LPSTR LPTSTR;
typedef	BOOL *LPBOOL;
typedef const char *LPCTSTR;

#endif

typedef LONG_PTR LRESULT;
typedef ULONG_PTR DWORD_PTR;
typedef UINT_PTR WPARAM;
typedef wchar_t WCHAR;
typedef const WCHAR *LPCWSTR;
typedef WCHAR *LPWSTR;
typedef TCHAR _TCHAR;

typedef long HRESULT;
typedef HANDLE HGDIOBJ;
typedef HANDLE HTREEITEM;
typedef HANDLE HGLOBAL;
typedef void *LPOLEDOCUMENTSITE;
typedef unsigned int UINT;
typedef const char *LPCSTR;
typedef	const char *PCSTR;
typedef void *LPVOID;
typedef void *PVOID;
typedef DWORD DROPEFFECT;
typedef unsigned long long DWORD64, *PDWORD64;
typedef WORD CLIPFORMAT;
typedef const void *LPCVOID;
typedef int *LPINT;
typedef long *LPLONG;
typedef SHORT *PSHORT;  
typedef LONG *PLONG;  
typedef unsigned short USHORT;

typedef LONG SCODE;
typedef SCODE *PSCODE;

#define UNALIGNED
#define UNALIGNED64


#define DECLARE_DYNAMIC(class_name)\
public:\
virtual CString GetClassName() const;\
virtual CString GetBaseClassName()  const;\
static CObject* CreateObjectStatic();\
virtual CObject* CreateObject();


#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
CString class_name::GetClassName() const \
{ \
    return _T(#class_name); \
}\
CString class_name::GetBaseClassName() const \
{ \
    return _T(#base_class_name); \
}\
CObject* class_name::CreateObjectStatic() \
{ return new class_name; }\
CObject* class_name::CreateObject() \
{ return new class_name; }


#define DECLARE_DYNCREATE(class_name) \
public:\
virtual CString GetClassName() const;\
virtual CString GetBaseClassName()  const;\
virtual CObject* CreateObject();\
static CObject* CreateObjectStatic();

//DECLARE_DYNAMIC(class_name)


#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
CString class_name::GetClassName() const \
{ \
return _T(#class_name); \
}\
CString class_name::GetBaseClassName() const \
{ \
return _T(#base_class_name); \
}\
CObject* class_name::CreateObjectStatic() \
{ return new class_name; }\
CObject* class_name::CreateObject() \
{ return new class_name; }\

///IMPLEMENT_DYNAMIC(class_name, base_class_name)


#define RUNTIME_CLASS(class_name) ((CRuntimeClass*)(class_name::CreateObjectStatic()))

#define DECLARE_DISPATCH_MAP()
#define DECLARE_INTERFACE_MAP()
#define DECLARE_SERIAL(x)

#ifndef CSHELLQT_LIBRARY

typedef struct tagPOINT { 
	LONG x; 
	LONG y; 
} POINT;

typedef POINT *LPPOINT;

typedef struct tagSIZE
{
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;

typedef struct tagNMHDR {
	HWND     hwndFrom;
	UINT_PTR idFrom;
	UINT     code;
} NMHDR;

typedef struct _RECT {
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECT, *PRECT;

#endif

typedef RECT *LPRECT;
typedef const RECT *LPCRECT;

typedef struct tagNMCUSTOMDRAWINFO
{
    NMHDR hdr;
    DWORD dwDrawStage;
    HDC hdc;
    RECT rc;
    DWORD_PTR dwItemSpec;  
    UINT  uItemState;
    LPARAM lItemlParam;
} NMCUSTOMDRAW, *LPNMCUSTOMDRAW;

typedef struct _NM_UPDOWN {
	NMHDR hdr;
	int   iPos;
	int   iDelta;
} NMUPDOWN, *LPNMUPDOWN;

typedef _NM_UPDOWN NM_UPDOWN;

#ifndef CSHELLQT_LIBRARY

typedef struct tagMSG {
	HWND   hwnd;
	UINT   message;
	WPARAM wParam;
	LPARAM lParam;
	DWORD  time;
	POINT  pt;
} MSG, *PMSG, *LPMSG;

typedef void* LPCDLGTEMPLATE;
typedef void* DLGPROC;
typedef void* LPFNPSPCALLBACK;

typedef struct {
	DWORD           dwSize;
	DWORD           dwFlags;
	HINSTANCE       hInstance;
	union {
		LPCSTR         pszTemplate;
		LPCDLGTEMPLATE pResource;
	};
	union {
		HICON  hIcon;
		LPCSTR pszIcon;
	};
	LPCSTR          pszTitle;
	DLGPROC         pfnDlgProc;
	LPARAM          lParam;
	LPFNPSPCALLBACK pfnCallback;
	UINT            *pcRefParent;
	LPCTSTR         pszHeaderTitle;
	LPCTSTR         pszHeaderSubTitle;
	HANDLE          hActCtx;
} PROPSHEETPAGE, *LPPROPSHEETPAGE;

typedef struct tagCREATESTRUCT {
	LPVOID    lpCreateParams;
	HINSTANCE hInstance;
	HMENU     hMenu;
	HWND      hwndParent;
	int       cy;
	int       cx;
	int       y;
	int       x;
	LONG      style;
	LPCTSTR   lpszName;
	LPCTSTR   lpszClass;
	DWORD     dwExStyle;
} CREATESTRUCT, *LPCREATESTRUCT;

#endif

#ifndef _TIME64_T_DEFINED
typedef long long __time64_t;     /* 64-bit time value */
#define _TIME64_T_DEFINED
#endif

typedef DWORD	COLORREF;
#define RGB(r,g,b) \
((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

#ifndef CSHELLQT_LIBRARY

//#define INVALID_HANDLE_VALUE 0
#define MAX_PATH 1000
//#define FILE_ATTRIBUTE_DIRECTORY 0x00000001

#define LOCALE_SYSTEM_DEFAULT  1
#define LOCALE_USER_DEFAULT    2

#define WINAPI
#define CALLBACK

#endif

#define AFX_MANAGE_STATE(x)
#define AFX_MODULE_STATE HANDLE

#define ASSERT_VALID(pOb)	DEBUG_ONLY((AfxAssertValidObject(pOb, __FILE__, __LINE__)))
#define ASSERT(pOb)	assert((pOb))

#define ASSERT_KINDOF(class_name, object) assert(dynamic_cast<class_name *>(object))

#ifdef _DEBUG
#define DEBUG_ONLY(f)      (f)
#define TRACE printf
#define TRACE1 printf
#define TRACE2 printf
#define VERIFY(f)          ASSERT(f)
#define traceAppMsg "%d %s %s"
#else
#define DEBUG_ONLY(f)  
#define TRACE
#define TRACE1
#define TRACE2
#define VERIFY(f)          ((void)(f))
#define traceAppMsg "%d %s %s"
#endif

#define _MSC_VER 1700

//#ifndef NOMINMAX

#include <algorithm>

using namespace std;
//#ifndef max
//#define max(a,b)            (((a) > (b)) ? (a) : (b))
//#define max(a,b) std::max(a,b)
//#endif
//#error ggg
//#ifndef min
//#define min(a,b) std::min(a,b)
//#define min(a,b)            (((a) < (b)) ? (a) : (b))
//#endif

//#endif 

#define _MAX_PATH   260 /* max. length of full pathname */
#define _MAX_DRIVE  3   /* max. length of drive component */
#define _MAX_DIR    256 /* max. length of path component */
#define _MAX_FNAME  256 /* max. length of file name component */
#define _MAX_EXT    256 /* max. length of extension component */

#define AFX_API_IMPORT
#define EXPORT

#define CONST const
#ifndef CSHELLQT_LIBRARY
#define __stdcall
#endif
#define DEBUG_NEW new

#define TRY try
#define CATCH(class,e) catch(class *e)
#define CATCH_ALL(e) catch(...)
#define END_CATCH_ALL
#define END_TRY catch(...){}
#define THROW_LAST() (throw)

#define FAR

#ifndef Q_CC_MINGW
#include "windows.h"
#endif

#endif//CDEF_DEFINE
