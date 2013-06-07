/*
 *  CFileDialog.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CString.h"
#include "CWnd.h"
#include "commdlg.h"

#include "CFileDialog.h"

CFileDialog::CFileDialog()
{
	mPanel = NULL;
	mSave = true;
}

CFileDialog::CFileDialog(BOOL bOpenFileDialog,
			LPCTSTR lpszDefExt,
			LPCTSTR lpszFileName,
			DWORD dwFlags,
			LPCTSTR lpszFilter,
			CWnd* pParentWnd,
			DWORD dwSize,
			BOOL bVistaStyle)
{
	mSave = !bOpenFileDialog;
	
	if (!mSave)
	{
		NSOpenPanel *panel;
		
		panel = [NSOpenPanel openPanel];
		
		mPanel = panel;
	}
	else 
	{
		NSSavePanel *panel;
		
		panel = [NSSavePanel savePanel];
			
		mPanel = panel;
	}
}

CFileDialog::~CFileDialog()
{
	
}

INT_PTR CFileDialog::DoModal()
{
	NSInteger res = [(NSSavePanel*)mPanel runModal];
	
	if (res == NSFileHandlingPanelOKButton)
	{
		return IDOK;
	}
	
	return IDCANCEL;
}

CString CFileDialog::GetPathName() const
{
	NSURL *url = [(NSSavePanel*)mPanel URL];
	
	return [[url path] UTF8String];
}

CString CFileDialog::GetFileName() const
{
	NSURL *url = [(NSSavePanel*)mPanel URL];
	
	return [[url lastPathComponent] UTF8String];
}

CString CFileDialog::GetFileExt() const
{
	NSURL *url = [(NSSavePanel*)mPanel URL];
	
	return [[url pathExtension] UTF8String];
}

CString CFileDialog::GetFileTitle() const
{
	NSURL *url = [(NSSavePanel*)mPanel URL];
	
	CString ext = [[url pathExtension] UTF8String];
	CString name = [[url lastPathComponent] UTF8String];
	
	name.Replace(ext, "");
	
	return name;
}

BOOL CFileDialog::GetReadOnlyPref() const
{
	NSLog(@"to do CFileDialog::GetReadOnlyPref");
	
	return FALSE;
}

CString CFileDialog::GetFolderPath() const
{
	NSURL *url = [(NSSavePanel*)mPanel URL];
	
	url = [url URLByDeletingLastPathComponent];
	
	return [[url path] UTF8String];
}

const OPENFILENAME& CFileDialog::GetOFN() const
{
	return m_ofn;
}

OPENFILENAME& CFileDialog::GetOFN()
{
	return m_ofn;
}
