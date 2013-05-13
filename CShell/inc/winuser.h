/*
 *  winuser.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef WIN_USER
#define WIN_USER 1

#include "CDef.h"

/*
 * Commands to pass to WinHelp()
 */
#define HELP_CONTEXT      0x0001L  /* Display topic in ulTopic */
#define HELP_QUIT         0x0002L  /* Terminate help */
#define HELP_INDEX        0x0003L  /* Display index */
#define HELP_CONTENTS     0x0003L
#define HELP_HELPONHELP   0x0004L  /* Display help on using help */
#define HELP_SETINDEX     0x0005L  /* Set current Index for multi index help */
#define HELP_SETCONTENTS  0x0005L
#define HELP_CONTEXTPOPUP 0x0008L
#define HELP_FORCEFILE    0x0009L
#define HELP_KEY          0x0101L  /* Display topic for keyword in offabData */
#define HELP_COMMAND      0x0102L
#define HELP_PARTIALKEY   0x0105L
#define HELP_MULTIKEY     0x0201L
#define HELP_SETWINPOS    0x0203L

/*
 * Color Types
 */
#define CTLCOLOR_MSGBOX         0
#define CTLCOLOR_EDIT           1
#define CTLCOLOR_LISTBOX        2
#define CTLCOLOR_BTN            3
#define CTLCOLOR_DLG            4
#define CTLCOLOR_SCROLLBAR      5
#define CTLCOLOR_STATIC         6
#define CTLCOLOR_MAX            7

#define COLOR_SCROLLBAR         0
#define COLOR_BACKGROUND        1
#define COLOR_ACTIVECAPTION     2
#define COLOR_INACTIVECAPTION   3
#define COLOR_MENU              4
#define COLOR_WINDOW            5
#define COLOR_WINDOWFRAME       6
#define COLOR_MENUTEXT          7
#define COLOR_WINDOWTEXT        8
#define COLOR_CAPTIONTEXT       9
#define COLOR_ACTIVEBORDER      10
#define COLOR_INACTIVEBORDER    11
#define COLOR_APPWORKSPACE      12
#define COLOR_HIGHLIGHT         13
#define COLOR_HIGHLIGHTTEXT     14
#define COLOR_BTNFACE           15
#define COLOR_BTNSHADOW         16
#define COLOR_GRAYTEXT          17
#define COLOR_BTNTEXT           18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT      20

#define COLOR_3DDKSHADOW        21
#define COLOR_3DLIGHT           22
#define COLOR_INFOTEXT          23
#define COLOR_INFOBK            24

#define COLOR_HOTLIGHT          26
#define COLOR_GRADIENTACTIVECAPTION 27
#define COLOR_GRADIENTINACTIVECAPTION 28

#define COLOR_MENUHILIGHT       29
#define COLOR_MENUBAR           30

#define COLOR_DESKTOP           COLOR_BACKGROUND
#define COLOR_3DFACE            COLOR_BTNFACE
#define COLOR_3DSHADOW          COLOR_BTNSHADOW
#define COLOR_3DHIGHLIGHT       COLOR_BTNHIGHLIGHT
#define COLOR_3DHILIGHT         COLOR_BTNHIGHLIGHT
#define COLOR_BTNHILIGHT        COLOR_BTNHIGHLIGHT

DWORD GetSysColor(int nIndex);

BOOL DestroyIcon(HICON hIcon);

//shellapi.h

// Shell File Operations

#define FO_MOVE                    0x0001
#define FO_COPY                    0x0002
#define FO_DELETE                  0x0003
#define FO_RENAME                  0x0004

#define FOF_MULTIDESTFILES         0x0001
#define FOF_CONFIRMMOUSE           0x0002
#define FOF_SILENT                 0x0004  // don't display progress UI (confirm prompts may be displayed still)
#define FOF_RENAMEONCOLLISION      0x0008  // automatically rename the source files to avoid the collisions
#define FOF_NOCONFIRMATION         0x0010  // don't display confirmation UI, assume "yes" for cases that can be bypassed, "no" for those that can not
#define FOF_WANTMAPPINGHANDLE      0x0020  // Fill in SHFILEOPSTRUCT.hNameMappings
// Must be freed using SHFreeNameMappings
#define FOF_ALLOWUNDO              0x0040  // enable undo including Recycle behavior for IFileOperation::Delete()
#define FOF_FILESONLY              0x0080  // only operate on the files (non folders), both files and folders are assumed without this
#define FOF_SIMPLEPROGRESS         0x0100  // means don't show names of files
#define FOF_NOCONFIRMMKDIR         0x0200  // don't dispplay confirmatino UI before making any needed directories, assume "Yes" in these cases
#define FOF_NOERRORUI              0x0400  // don't put up error UI, other UI may be displayed, progress, confirmations
#define FOF_NOCOPYSECURITYATTRIBS  0x0800  // dont copy file security attributes (ACLs)
#define FOF_NORECURSION            0x1000  // don't recurse into directories for operations that would recurse
#define FOF_NO_CONNECTED_ELEMENTS  0x2000  // don't operate on connected elements ("xxx_files" folders that go with .htm files)
#define FOF_WANTNUKEWARNING        0x4000  // during delete operation, warn if nuking instead of recycling (partially overrides FOF_NOCONFIRMATION)

#define FOF_NORECURSEREPARSE       0x8000  // deprecated; the operations engine always does the right thing on FolderLink objects (symlinks, reparse points, folder shortcuts)

#define FOF_NO_UI                   (FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR) // don't display any UI at all


typedef WORD FILEOP_FLAGS;

// implicit parameters are:
//      if pFrom or pTo are unqualified names the current directories are
//      taken from the global current drive/directory settings managed
//      by Get/SetCurrentDrive/Directory
//
//      the global confirmation settings

typedef struct _SHFILEOPSTRUCT
{
    HWND            hwnd;
    UINT            wFunc;
    LPCSTR          pFrom;
    LPCSTR          pTo;
    FILEOP_FLAGS    fFlags;
    BOOL            fAnyOperationsAborted;
    LPVOID          hNameMappings;
    LPCSTR          lpszProgressTitle; // only used if FOF_SIMPLEPROGRESS
} SHFILEOPSTRUCT, *LPSHFILEOPSTRUCT;

typedef struct tagWINDOWPLACEMENT {
    UINT  length;
    UINT  flags;
    UINT  showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT  rcNormalPosition;
} WINDOWPLACEMENT;
typedef WINDOWPLACEMENT *PWINDOWPLACEMENT, *LPWINDOWPLACEMENT;

/*
 * MEASUREITEMSTRUCT for ownerdraw
 */
typedef struct tagMEASUREITEMSTRUCT {
    UINT       CtlType;
    UINT       CtlID;
    UINT       itemID;
    UINT       itemWidth;
    UINT       itemHeight;
    ULONG_PTR  itemData;
} MEASUREITEMSTRUCT, *PMEASUREITEMSTRUCT, *LPMEASUREITEMSTRUCT;

typedef struct tagHELPINFO      /* Structure pointed to by lParam of WM_HELP */
{
    UINT    cbSize;             /* Size in bytes of this struct  */
    int     iContextType;       /* Either HELPINFO_WINDOW or HELPINFO_MENUITEM */
    int     iCtrlId;            /* Control Id or a Menu item Id. */
    HANDLE  hItemHandle;        /* hWnd of control or hMenu.     */
    DWORD_PTR dwContextId;      /* Context Id associated with this item */
    POINT   MousePos;           /* Mouse Position in screen co-ordinates */
}  HELPINFO, *LPHELPINFO;

UINT ExtractIconEx(LPCSTR lpszFile, int nIconIndex, HICON *phiconLarge, HICON *phiconSmall, UINT nIcons);
int SHFileOperation(LPSHFILEOPSTRUCT lpFileOp);


#endif//WIN_USER