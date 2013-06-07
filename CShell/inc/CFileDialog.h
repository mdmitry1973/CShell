/*
 *  CFileDialog.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CFILEDIALOG_DEFINE
#define CFILEDIALOG_DEFINE 1

#include "CDef.h"

#include "CommDlg.h"
#include "winnt.h"

class CFileDialog
{
	
public:
	
	// Attributes
	OPENFILENAME m_ofn;
	const OPENFILENAME& GetOFN() const;
	OPENFILENAME& GetOFN();
	LPOPENFILENAME m_pOFN;
	
	CFileDialog();
	CFileDialog(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
				LPCTSTR lpszDefExt = NULL,
				LPCTSTR lpszFileName = NULL,
				DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
				LPCTSTR lpszFilter = NULL,
				CWnd* pParentWnd = NULL,
				DWORD dwSize = 0,
				BOOL bVistaStyle = TRUE);
	~CFileDialog();
	
	virtual INT_PTR DoModal();
	
	// Helpers for parsing file name after successful return
	// or during Overridable callbacks if OFN_EXPLORER is set
	CString GetPathName() const;  // return full path and filename
	CString GetFileName() const;  // return only filename
	CString GetFileExt() const;   // return only ext
	CString GetFileTitle() const; // return file title
	BOOL GetReadOnlyPref() const; // return TRUE if readonly checked
	
	// Other operations available while the dialog is visible
	CString GetFolderPath() const; // return full path
	
private:
	
	void	*mPanel;
	BOOL	mSave;
	
};


#endif//CFILEDIALOG_DEFINE