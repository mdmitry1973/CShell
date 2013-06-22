/*
 *  CRecentFileList.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <vector>

#ifndef CRECENTFILELIST_DEFINE
#define CRECENTFILELIST_DEFINE 1

#define AFX_ABBREV_FILENAME_LEN 30

class CRecentFileList
{
	// Constructors
public:
	CRecentFileList();
	CRecentFileList(UINT nStart, LPCTSTR lpszSection,
					LPCTSTR lpszEntryFormat, int nSize,
					int nMaxDispLen = AFX_ABBREV_FILENAME_LEN);
	
	virtual ~CRecentFileList();
	
	// Attributes
	int GetSize() const;
	CString& operator[](int nIndex);
	
	// Operations
	virtual void Remove(int nIndex);
	virtual void Add(LPCTSTR lpszPathName);
	
	/// <summary>
	/// Adds a file to the MRU file list.</summary>
	/// <param name="lpszPathName"> Pathname to be added to the list.</param>
	/// <param name="lpszAppID"> Specifies Application User Model ID for the application.</param>
	virtual void Add(LPCTSTR lpszPathName, LPCTSTR lpszAppID);
	virtual BOOL GetDisplayName(CString& strName, int nIndex,
								LPCTSTR lpszCurDir, int nCurDir, BOOL bAtLeastName = TRUE) const;
	//virtual void UpdateMenu(CCmdUI* pCmdUI);
	//virtual void ReadList();    // reads from registry or ini file
	//virtual void WriteList();   // writes to registry or ini file
	
	/// <summary>
	/// Adds a file to the MRU file list.</summary>
	/// <param name="pItem"> Specifies a pointer to Shell Item to be added to the list.</param>
	/// <param name="lpszAppID"> Specifies Application User Model ID for the application.</param>
	//void Add(IShellItem* pItem, LPCTSTR lpszAppID);
	
	/// <summary>
	/// Adds a file to the MRU file list.</summary>
	/// <param name="pLink"> Specifies a pointer to Shell Link to be added to the list.</param>
	/// <param name="lpszAppID"> Specifies Application User Model ID for the application.</param>
	//void Add(IShellLink* pLink, LPCTSTR lpszAppID);
	
	/// <summary>
	/// Adds a file to the MRU file list.</summary>
	/// <param name="pidl"> Specifies the IDLIST for the shell item that should be added to the recent docs folder.</param>
	/// <param name="lpszAppID"> Specifies Application User Model ID for the application.</param>
	//void Add(PIDLIST_ABSOLUTE pidl, LPCTSTR lpszAppID);
	
	// Implementation
	
	
	//int m_nSize;                // contents of the MRU list
	//CString* m_arrNames;
	//CString m_strSectionName;   // for saving
	//CString m_strEntryFormat;
	//UINT m_nStart;              // for displaying
	//int m_nMaxDisplayLength;
	//CString m_strOriginal;      // original menu item contents
};

#endif//CRECENTFILELIST_DEFINE