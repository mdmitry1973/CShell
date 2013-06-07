/*
 *  commdlg.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef COMMDLG_H
#define COMMDLG_H 1

#include "CDef.h"

//
//  Flags for PrintDlg and PrintDlgEx.
//
#define PD_ALLPAGES                    0x00000000
#define PD_SELECTION                   0x00000001
#define PD_PAGENUMS                    0x00000002
#define PD_NOSELECTION                 0x00000004
#define PD_NOPAGENUMS                  0x00000008
#define PD_COLLATE                     0x00000010
#define PD_PRINTTOFILE                 0x00000020
#define PD_PRINTSETUP                  0x00000040
#define PD_NOWARNING                   0x00000080
#define PD_RETURNDC                    0x00000100
#define PD_RETURNIC                    0x00000200
#define PD_RETURNDEFAULT               0x00000400
#define PD_SHOWHELP                    0x00000800
#define PD_ENABLEPRINTHOOK             0x00001000
#define PD_ENABLESETUPHOOK             0x00002000
#define PD_ENABLEPRINTTEMPLATE         0x00004000
#define PD_ENABLESETUPTEMPLATE         0x00008000
#define PD_ENABLEPRINTTEMPLATEHANDLE   0x00010000
#define PD_ENABLESETUPTEMPLATEHANDLE   0x00020000
#define PD_USEDEVMODECOPIES            0x00040000
#define PD_USEDEVMODECOPIESANDCOLLATE  0x00040000
#define PD_DISABLEPRINTTOFILE          0x00080000
#define PD_HIDEPRINTTOFILE             0x00100000
#define PD_NONETWORKBUTTON             0x00200000
#define PD_CURRENTPAGE                 0x00400000
#define PD_NOCURRENTPAGE               0x00800000
#define PD_EXCLUSIONFLAGS              0x01000000
#define PD_USELARGETEMPLATE            0x10000000

#define OFN_READONLY                 0x00000001
#define OFN_OVERWRITEPROMPT          0x00000002
#define OFN_HIDEREADONLY             0x00000004
#define OFN_NOCHANGEDIR              0x00000008
#define OFN_SHOWHELP                 0x00000010
#define OFN_ENABLEHOOK               0x00000020
#define OFN_ENABLETEMPLATE           0x00000040
#define OFN_ENABLETEMPLATEHANDLE     0x00000080
#define OFN_NOVALIDATE               0x00000100
#define OFN_ALLOWMULTISELECT         0x00000200
#define OFN_EXTENSIONDIFFERENT       0x00000400
#define OFN_PATHMUSTEXIST            0x00000800
#define OFN_FILEMUSTEXIST            0x00001000
#define OFN_CREATEPROMPT             0x00002000
#define OFN_SHAREAWARE               0x00004000
#define OFN_NOREADONLYRETURN         0x00008000
#define OFN_NOTESTFILECREATE         0x00010000
#define OFN_NONETWORKBUTTON          0x00020000
#define OFN_NOLONGNAMES              0x00040000     // force no long names for 4.x modules
#define OFN_EXPLORER                 0x00080000     // new look commdlg
#define OFN_NODEREFERENCELINKS       0x00100000
#define OFN_LONGNAMES                0x00200000     // force long names for 3.x modules
#define OFN_ENABLEINCLUDENOTIFY      0x00400000     // send include message to callback
#define OFN_ENABLESIZING             0x00800000
#define OFN_DONTADDTORECENT          0x02000000
#define OFN_FORCESHOWHIDDEN          0x10000000    // Show All files including System and hidden files
#define OFN_EX_NOPLACESBAR			0x00000001

typedef UINT_PTR (*LPOFNHOOKPROC) (HWND, UINT, WPARAM, LPARAM);

typedef struct tagOFN {
	DWORD        lStructSize;
	HWND         hwndOwner;
	HINSTANCE    hInstance;
	LPCSTR      lpstrFilter;
	LPSTR       lpstrCustomFilter;
	DWORD        nMaxCustFilter;
	DWORD        nFilterIndex;
	LPSTR       lpstrFile;
	DWORD        nMaxFile;
	LPSTR       lpstrFileTitle;
	DWORD        nMaxFileTitle;
	LPCSTR      lpstrInitialDir;
	LPCSTR      lpstrTitle;
	DWORD        Flags;
	WORD         nFileOffset;
	WORD         nFileExtension;
	LPCSTR      lpstrDefExt;
	LPARAM       lCustData;
	LPOFNHOOKPROC lpfnHook;
	LPCSTR      lpTemplateName;
	void *        pvReserved;
	DWORD        dwReserved;
	DWORD        FlagsEx;

} OPENFILENAME, *LPOPENFILENAME;

#endif//COMMDLG_H