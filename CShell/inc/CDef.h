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

#define CSELL_MAC 1

//#ifndef WIN32
//#define WIN32
//#endif

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

#define MB_OK                       0x00000000L
#define MB_OKCANCEL                 0x00000001L
#define MB_ABORTRETRYIGNORE         0x00000002L
#define MB_YESNOCANCEL              0x00000003L
#define MB_YESNO                    0x00000004L
#define MB_RETRYCANCEL              0x00000005L
#define MB_CANCELTRYCONTINUE		0x00000006L

#define MB_ICONHAND                 0x00000010L
#define MB_ICONQUESTION             0x00000020L
#define MB_ICONEXCLAMATION          0x00000030L
#define MB_ICONASTERISK             0x00000040L
#define MB_USERICON                 0x00000080L
#define MB_ICONWARNING              MB_ICONEXCLAMATION
#define MB_ICONERROR                MB_ICONHAND
#define MB_ICONINFORMATION          MB_ICONASTERISK
#define MB_ICONSTOP                 MB_ICONHAND

#define MB_DEFBUTTON1               0x00000000L
#define MB_DEFBUTTON2               0x00000100L
#define MB_DEFBUTTON3               0x00000200L
#define MB_DEFBUTTON4               0x00000300L

#define MB_APPLMODAL                0x00000000L
#define MB_SYSTEMMODAL              0x00001000L
#define MB_TASKMODAL                0x00002000L
#define MB_HELP                     0x00004000L // Help Button
#define MB_NOFOCUS                  0x00008000L
#define MB_SETFOREGROUND            0x00010000L
#define MB_DEFAULT_DESKTOP_ONLY     0x00020000L
#define MB_TOPMOST                  0x00040000L
#define MB_RIGHT                    0x00080000L
#define MB_RTLREADING               0x00100000L

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

#define GWL_EXSTYLE -20
#define GWL_HINSTANCE -6
#define GWL_HWNDPARENT -8
#define GWL_ID -12
#define GWL_STYLE -16
#define GWL_USERDATA -21
#define GWL_WNDPROC -4 

/* Menu flags */
#define MF_INSERT          0x0000
#define MF_CHANGE          0x0080
#define MF_APPEND          0x0100
#define MF_DELETE          0x0200
#define MF_REMOVE          0x1000
#define MF_END             0x0080

#define MF_ENABLED         0x0000
#define MF_GRAYED          0x0001
#define MF_DISABLED        0x0002
#define MF_STRING          0x0000
#define MF_BITMAP          0x0004
#define MF_UNCHECKED       0x0000
#define MF_CHECKED         0x0008
#define MF_POPUP           0x0010
#define MF_MENUBARBREAK    0x0020
#define MF_MENUBREAK       0x0040
#define MF_UNHILITE        0x0000
#define MF_HILITE          0x0080
#define MF_OWNERDRAW       0x0100
#define MF_USECHECKBITMAPS 0x0200
#define MF_BYCOMMAND       0x0000
#define MF_BYPOSITION      0x0400
#define MF_SEPARATOR       0x0800
#define MF_DEFAULT         0x1000
#define MF_SYSMENU         0x2000
#define MF_HELP            0x4000
#define MF_RIGHTJUSTIFY    0x4000
#define MF_MOUSESELECT     0x8000

/* Flags for extended menu item types.  */
#define MFT_STRING         MF_STRING
#define MFT_BITMAP         MF_BITMAP
#define MFT_MENUBARBREAK   MF_MENUBARBREAK
#define MFT_MENUBREAK      MF_MENUBREAK
#define MFT_OWNERDRAW      MF_OWNERDRAW
#define MFT_RADIOCHECK     0x00000200L
#define MFT_SEPARATOR      MF_SEPARATOR
#define MFT_RIGHTORDER     0x00002000L
#define MFT_RIGHTJUSTIFY   MF_RIGHTJUSTIFY

/* Flags for extended menu item states.  */
#define MFS_GRAYED          0x00000003L
#define MFS_DISABLED        MFS_GRAYED
#define MFS_CHECKED         MF_CHECKED
#define MFS_HILITE          MF_HILITE
#define MFS_ENABLED         MF_ENABLED
#define MFS_UNCHECKED       MF_UNCHECKED
#define MFS_UNHILITE        MF_UNHILITE
#define MFS_DEFAULT         MF_DEFAULT
#define MFS_MASK            0x0000108BL
#define MFS_HOTTRACKDRAWN   0x10000000L
#define MFS_CACHEDBMP       0x20000000L
#define MFS_BOTTOMGAPDROP   0x40000000L
#define MFS_TOPGAPDROP      0x80000000L
#define MFS_GAPDROP         0xC0000000L

#define ES_CENTER            0x1L
#define ES_NUMBER            0x2000L 

#define SW_HIDE 0
#define SW_SHOWNORMAL 1
#define SW_SHOWMINIMIZED 2
#define SW_MAXIMIZE 3
#define SW_SHOWMAXIMIZED 3
#define SW_SHOWNOACTIVATE 4
#define SW_SHOW 5
#define SW_MINIMIZE 6
#define SW_SHOWMINNOACTIVE 7
#define SW_SHOWNA 8
#define SW_RESTORE 9

#define BS_PUSHBUTTON       0x00000000L
#define BS_DEFPUSHBUTTON    0x00000001L
#define BS_CHECKBOX         0x00000002L
#define BS_AUTOCHECKBOX     0x00000003L
#define BS_RADIOBUTTON      0x00000004L
#define BS_3STATE           0x00000005L
#define BS_AUTO3STATE       0x00000006L
#define BS_GROUPBOX         0x00000007L
#define BS_USERBUTTON       0x00000008L
#define BS_AUTORADIOBUTTON  0x00000009L
#define BS_PUSHBOX          0x0000000AL
#define BS_OWNERDRAW        0x0000000BL
#define BS_TYPEMASK         0x0000000FL
#define BS_LEFTTEXT         0x00000020L

#define BS_TEXT             0x00000000L
#define BS_ICON             0x00000040L
#define BS_BITMAP           0x00000080L
#define BS_LEFT             0x00000100L
#define BS_RIGHT            0x00000200L
#define BS_CENTER           0x00000300L
#define BS_TOP              0x00000400L
#define BS_BOTTOM           0x00000800L
#define BS_VCENTER          0x00000C00L
#define BS_PUSHLIKE         0x00001000L
#define BS_MULTILINE        0x00002000L
#define BS_NOTIFY           0x00004000L
#define BS_FLAT             0x00008000L
#define BS_RIGHTBUTTON      BS_LEFTTEXT

#define WM_APPCOMMAND                   0x0319
#define WM_CHAR                         0x0102
#define WM_DEADCHAR                     0x0103
#define WM_HOTKEY                       0x0312
#define WM_KEYDOWN                      0x0100
#define WM_KEYUP                        0x0101
#define WM_SYSDEADCHAR                  0x010

#define WM_LBUTTONDOWN                  0x0201
#define WM_LBUTTONUP                    0x0202
#define WM_LBUTTONDBLCLK                0x0203
#define WM_RBUTTONDOWN                  0x0204
#define WM_RBUTTONUP                    0x0205
#define WM_RBUTTONDBLCLK                0x0206
#define WM_MBUTTONDOWN                  0x0207
#define WM_MBUTTONUP                    0x0208
#define WM_MBUTTONDBLCLK                0x0209
#define WM_MOUSELAST                    0x0209
#define WM_PARENTNOTIFY                 0x0210

#define SWP_ASYNCWINDOWPOS	0x4000
#define SWP_DEFERERASE		0x2000
#define SWP_DRAWFRAME		0x0020
#define SWP_FRAMECHANGED	0x0020
#define SWP_HIDEWINDOW		0x0080
#define SWP_NOACTIVATE		0x0010
#define SWP_NOCOPYBITS		0x0100
#define SWP_NOMOVE			0x0002
#define SWP_NOOWNERZORDER	0x0200
#define SWP_NOREDRAW		0x0008
#define SWP_NOREPOSITION	0x0200
#define SWP_NOSENDCHANGING	0x0400
#define SWP_NOSIZE			0x0001
#define SWP_NOZORDER		0x0004
#define SWP_SHOWWINDOW		0x0040 

#define MK_LBUTTON	0x0001
#define MK_RBUTTON	0x0002
#define MK_SHIFT	0x0004
#define MK_CONTROL	0x0008
#define MK_MBUTTON	0x0010
#define MK_ALT		0x1000

#define TCN_FIRST               (0U-550U)
#define TCN_LAST                (0U-580U)
#define TCN_KEYDOWN             (TCN_FIRST - 0)
#define TCN_SELCHANGE           (TCN_FIRST - 1)
#define TCN_SELCHANGING         (TCN_FIRST - 2)
#define TCN_GETOBJECT           (TCN_FIRST - 3)
#define TCN_FOCUSCHANGE         (TCN_FIRST - 4)

#define SC_SIZE         0xF000
#define SC_MOVE         0xF010
#define SC_MINIMIZE     0xF020
#define SC_MAXIMIZE     0xF030
#define SC_NEXTWINDOW   0xF040
#define SC_PREVWINDOW   0xF050
#define SC_CLOSE        0xF060
#define SC_VSCROLL      0xF070
#define SC_HSCROLL      0xF080
#define SC_MOUSEMENU    0xF090
#define SC_KEYMENU      0xF100
#define SC_ARRANGE      0xF110
#define SC_RESTORE      0xF120
#define SC_TASKLIST     0xF130
#define SC_SCREENSAVE   0xF140
#define SC_HOTKEY       0xF150
#define SC_DEFAULT      0xF160
#define SC_MONITORPOWER 0xF170
#define SC_CONTEXTHELP  0xF180
#define SC_SEPARATOR    0xF00F
#define SC_ICON         SC_MINIMIZE
#define SC_ZOOM         SC_MAXIMIZE

/* Window Styles */
#define WS_OVERLAPPED    0x00000000L
#define WS_POPUP         0x80000000L
#define WS_CHILD         0x40000000L
#define WS_MINIMIZE      0x20000000L
#define WS_VISIBLE       0x10000000L
#define WS_DISABLED      0x08000000L
#define WS_CLIPSIBLINGS  0x04000000L
#define WS_CLIPCHILDREN  0x02000000L
#define WS_MAXIMIZE      0x01000000L
#define WS_CAPTION       0x00C00000L
#define WS_BORDER        0x00800000L
#define WS_DLGFRAME      0x00400000L
#define WS_VSCROLL       0x00200000L
#define WS_HSCROLL       0x00100000L
#define WS_SYSMENU       0x00080000L
#define WS_THICKFRAME    0x00040000L
#define WS_GROUP         0x00020000L
#define WS_TABSTOP       0x00010000L
#define WS_MINIMIZEBOX   0x00020000L
#define WS_MAXIMIZEBOX   0x00010000L
#define WS_TILED         WS_OVERLAPPED
#define WS_ICONIC        WS_MINIMIZE
#define WS_SIZEBOX       WS_THICKFRAME
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME| WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_CHILDWINDOW (WS_CHILD)
#define WS_TILEDWINDOW (WS_OVERLAPPEDWINDOW)

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

#define LB_ERR (-3)

#define LOWORD(a) ((WORD)(a))
#define HIWORD(a) ((WORD)(((DWORD)(a) >> 16) & 0xFFFF))

typedef char CHAR;
typedef int WORD;
typedef unsigned char BYTE;
typedef unsigned long DWORD;
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
typedef unsigned long long UINT64;
typedef long long INT64;
typedef unsigned short UINT16;
typedef int INT32;
typedef char INT8;
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
typedef char *PTCHAR;
typedef BYTE *LPBYTE;
typedef long LONG;
typedef int INT_PTR;
typedef DWORD LCID; 
typedef DWORD *LPDWORD;
typedef void* HANDLE;
#ifndef Q_WINSTRICT
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
#endif
typedef long HRESULT;
typedef void* HMODULE;
typedef HANDLE HMENU;
typedef HANDLE HKEY;
typedef HANDLE HGDIOBJ;
typedef HANDLE HACCEL;
typedef HANDLE HTREEITEM;
typedef HANDLE HDROP;
typedef HANDLE IDropTarget;
typedef HANDLE HGLOBAL;
typedef void *LPOLEDOCUMENTSITE;
typedef void *LPDISPATCH;
typedef unsigned int UINT;
typedef int LPARAM;
typedef const char *LPCTSTR;
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

typedef CHAR TCHAR;
typedef CHAR *LPSTR;
typedef LONG_PTR LRESULT;
typedef ULONG_PTR DWORD_PTR;
typedef LPSTR LPTSTR;
typedef	BOOL *LPBOOL;
typedef UINT_PTR WPARAM;
typedef wchar_t WCHAR;
typedef const WCHAR *LPCWSTR;
typedef WCHAR *LPWSTR;
typedef TCHAR _TCHAR;

#define DECLARE_DYNAMIC(class_name)\
public:\
virtual CString GetClassName() const;\
virtual CString GetBaseClassName()  const;\
static CObject* CreateObjectStatic();\
virtual CObject* CreateObject();


#define IMPLEMENT_DYNAMIC(class_name, base_class_name) \
CString class_name::GetClassName() const \
{ \
	return #class_name; \
}\
CString class_name::GetBaseClassName() const \
{ \
	return #base_class_name; \
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

//DECLARE_DYNAMIC(class_name) \


#define IMPLEMENT_DYNCREATE(class_name, base_class_name) \
CString class_name::GetClassName() const \
{ \
return #class_name; \
}\
CString class_name::GetBaseClassName() const \
{ \
return #base_class_name; \
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


#ifndef _TIME64_T_DEFINED
typedef long long __time64_t;     /* 64-bit time value */
#define _TIME64_T_DEFINED
#endif

//#ifdef UNICODE
//#define _T(x) L ##x
//#else
#define _T(x) x
//#endif

typedef DWORD	COLORREF;
#define GetRValue(rgb)      ((BYTE)(rgb))
#define GetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      ((BYTE)((rgb)>>16))
#define RGB(r,g,b) \
((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))

//#define INVALID_HANDLE_VALUE 0
#define MAX_PATH 1000
//#define FILE_ATTRIBUTE_DIRECTORY 0x00000001

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

#define LOCALE_SYSTEM_DEFAULT  1
#define LOCALE_USER_DEFAULT    2

#define AFX_API_IMPORT
#define EXPORT
#define CALLBACK

#define CONST const
#ifndef CSHELLQT_LIBRARY
#define __stdcall
#endif
#define WINAPI
#define DEBUG_NEW new

#define TRY try
#define CATCH(class,e) catch(class *e)
#define CATCH_ALL(e) catch(...)
#define END_CATCH_ALL
#define END_TRY catch(...){}
#define THROW_LAST() (throw)

#define FAR

#endif//CDEF_DEFINE
