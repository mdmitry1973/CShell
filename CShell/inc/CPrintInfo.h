/*
 *  CPrintInfo.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CPRINTINFO_DEFINE
#define CPRINTINFO_DEFINE 1

#include "CDef.h"

#include "CString.h"
#include "CRect.h"

class CPrintDialog;

struct CPrintInfo // Printing information structure
{
    CPrintInfo();
    ~CPrintInfo();
	
    CPrintDialog* m_pPD;     // pointer to print dialog
	
    BOOL m_bDocObject;       // TRUE if printing by IPrint interface
    BOOL m_bPreview;         // TRUE if in preview mode
    BOOL m_bDirect;          // TRUE if bypassing Print Dialog
    BOOL m_bContinuePrinting;// set to FALSE to prematurely end printing
    UINT m_nCurPage;         // Current page
    UINT m_nNumPreviewPages; // Desired number of preview pages
    CString m_strPageDesc;   // Format string for page number display
    LPVOID m_lpUserData;     // pointer to user created struct
    CRect m_rectDraw;        // rectangle defining current usable page area
	
    // these only valid if m_bDocObject
    UINT m_nOffsetPage;      // offset of first page in combined IPrint job
    DWORD m_dwFlags;         // flags passed to IPrint::Print
	
    void SetMinPage(UINT nMinPage);
    void SetMaxPage(UINT nMaxPage);
    UINT GetMinPage() const;
    UINT GetMaxPage() const;
    UINT GetFromPage() const;
    UINT GetToPage() const;
    UINT GetOffsetPage() const;
};

#endif//CPRINTINFO_DEFINE