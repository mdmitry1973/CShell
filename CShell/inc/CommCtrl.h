/*
 *  commctrl.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef COMMCTRL_GDI
#define COMMCTRL_GDI 1

#include "CDef.h"

#define TVI_ROOT                ((HTREEITEM)(ULONG_PTR)-0x10000)
#define TVI_FIRST               ((HTREEITEM)(ULONG_PTR)-0x0FFFF)
#define TVI_LAST                ((HTREEITEM)(ULONG_PTR)-0x0FFFE)
#define TVI_SORT                ((HTREEITEM)(ULONG_PTR)-0x0FFFD)

#define CLR_NONE                0xFFFFFFFFL
#define CLR_DEFAULT             0xFF000000L

#define CMB_MASKED              0x02
#define TBSTATE_CHECKED         0x01
#define TBSTATE_PRESSED         0x02
#define TBSTATE_ENABLED         0x04
#define TBSTATE_HIDDEN          0x08
#define TBSTATE_INDETERMINATE   0x10
#define TBSTATE_WRAP            0x20
#define TBSTATE_ELLIPSES        0x40
#define TBSTATE_MARKED          0x80

#define TBSTYLE_BUTTON          0x0000  // obsolete; use BTNS_BUTTON instead
#define TBSTYLE_SEP             0x0001  // obsolete; use BTNS_SEP instead
#define TBSTYLE_CHECK           0x0002  // obsolete; use BTNS_CHECK instead
#define TBSTYLE_GROUP           0x0004  // obsolete; use BTNS_GROUP instead
#define TBSTYLE_CHECKGROUP      (TBSTYLE_GROUP | TBSTYLE_CHECK)     // obsolete; use BTNS_CHECKGROUP instead
#define TBSTYLE_DROPDOWN        0x0008  // obsolete; use BTNS_DROPDOWN instead
#define TBSTYLE_AUTOSIZE        0x0010  // obsolete; use BTNS_AUTOSIZE instead
#define TBSTYLE_NOPREFIX        0x0020  // obsolete; use BTNS_NOPREFIX instead

typedef struct tagTVITEMEX {
    UINT      mask;
    HTREEITEM hItem;
    UINT      state;
    UINT      stateMask;
    LPSTR     pszText;
    int       cchTextMax;
    int       iImage;
    int       iSelectedImage;
    int       cChildren;
    LPARAM    lParam;
    int       iIntegral;
    UINT      uStateEx;
    HWND      hwnd;
    int       iExpandedImage;
    int       iReserved;
} TVITEMEX, *LPTVITEMEX;

typedef struct tagTVITEM{
    UINT      mask;
    HTREEITEM hItem;
    UINT      state;
    UINT      stateMask;
    LPSTR     pszText;
    int       cchTextMax;
    int       iImage;
    int       iSelectedImage;
    int       cChildren;
    LPARAM    lParam;
} TVITEM, *LPTVITEM;

typedef struct tagTVINSERTSTRUCT {
    HTREEITEM hParent;
    HTREEITEM hInsertAfter;

    union
    {
        TVITEMEX itemex;
        TVITEM  item;
    } DUMMYUNIONNAME;

} TVINSERTSTRUCT, *LPTVINSERTSTRUCT;

#define  LPTVINSERTSTRUCT       LPTVINSERTSTRUCT

typedef struct tagTOOLINFO {
    UINT cbSize;
    UINT uFlags;
    HWND hwnd;
    UINT_PTR uId;
    RECT rect;
    HINSTANCE hinst;
    LPWSTR lpszText;
    LPARAM lParam;
    void *lpReserved;
} TTTOOLINFO,  *PTOOLINFO, *LPTTTOOLINFO;

#define TOOLINFO        TTTOOLINFO

typedef struct _TTGETTITLE
{
    DWORD dwSize;
    UINT uTitleBitmap;
    UINT cch;
    WCHAR* pszTitle;
} TTGETTITLE, *PTTGETTITLE;

#define LPSTR_TEXTCALLBACK    ((LPSTR)-1L)

typedef struct {
    int   iButton;
    DWORD dwFlags;
} TBINSERTMARK, * LPTBINSERTMARK;

typedef struct {
    UINT cbSize;
    DWORD dwMask;
    int idCommand;
    int iImage;
    BYTE fsState;
    BYTE fsStyle;
    WORD cx;
    DWORD_PTR lParam;
    LPSTR pszText;
    int cchText;
} TBBUTTONINFO, *LPTBBUTTONINFO;

typedef struct _TBBUTTON {
    int iBitmap;
    int idCommand;
    BYTE fsState;
    BYTE fsStyle;
    BYTE bReserved[2];          // padding for alignment
    DWORD_PTR dwData;
    INT_PTR iString;
} TBBUTTON, *PTBBUTTON, *LPTBBUTTON;
typedef const TBBUTTON *LPCTBBUTTON;


typedef struct {
    HINSTANCE       hInstOld;
    UINT_PTR        nIDOld;
    HINSTANCE       hInstNew;
    UINT_PTR        nIDNew;
    int             nButtons;
} TBREPLACEBITMAP, *LPTBREPLACEBITMAP;


typedef UINT_PTR (CALLBACK *LPPRINTHOOKPROC) (HWND, UINT, WPARAM, LPARAM);
typedef UINT_PTR (CALLBACK *LPSETUPHOOKPROC) (HWND, UINT, WPARAM, LPARAM);

typedef struct tagPD {
	DWORD            lStructSize;
	HWND             hwndOwner;
	HGLOBAL          hDevMode;
	HGLOBAL          hDevNames;
	HDC              hDC;
	DWORD            Flags;
	WORD             nFromPage;
	WORD             nToPage;
	WORD             nMinPage;
	WORD             nMaxPage;
	WORD             nCopies;
	HINSTANCE        hInstance;
	LPARAM           lCustData;
	LPPRINTHOOKPROC  lpfnPrintHook;
	LPSETUPHOOKPROC  lpfnSetupHook;
	LPCSTR          lpPrintTemplateName;
	LPCSTR          lpSetupTemplateName;
	HGLOBAL          hPrintTemplate;
	HGLOBAL          hSetupTemplate;
} PRINTDLG, *LPPRINTDLG;

#endif//COMMCTRL_GDI