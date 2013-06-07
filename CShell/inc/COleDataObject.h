/*
 *  COleDataObject.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef COLEDATAOBJECT_DEFINE
#define COLEDATAOBJECT_DEFINE 1

#include "CDef.h"


class COleDataObject
{
	// Constructors
public:
	COleDataObject();
	
	// Operations
	//void Attach(LPDATAOBJECT lpDataObject, BOOL bAutoRelease = TRUE);
	//LPDATAOBJECT Detach();  // detach and get ownership of m_lpDataObject
	//void Release(); // detach and Release ownership of m_lpDataObject
	//BOOL AttachClipboard(); // attach to current clipboard object
	
	// Attributes
	//void BeginEnumFormats();
	//BOOL GetNextFormat(LPFORMATETC lpFormatEtc);
	//CFile* GetFileData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);
	//HGLOBAL GetGlobalData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);
	//BOOL GetData(CLIPFORMAT cfFormat, LPSTGMEDIUM lpStgMedium,
	//			 LPFORMATETC lpFormatEtc = NULL);
	//BOOL IsDataAvailable(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);
	
	// Implementation
public:
	//LPDATAOBJECT m_lpDataObject;
	//LPENUMFORMATETC m_lpEnumerator;
	~COleDataObject();
	
	// advanced use and implementation
	//LPDATAOBJECT GetIDataObject(BOOL bAddRef);
	//void EnsureClipboardObject();
	//BOOL m_bClipboard;      // TRUE if represents the Win32 clipboard
	
protected:
	//BOOL m_bAutoRelease;    // TRUE if destructor should call Release
	
private:
	// Disable the copy constructor and assignment by default so you will get
	//   compiler errors instead of unexpected behaviour if you pass objects
	//   by value or assign objects.
	COleDataObject(const COleDataObject&);  // no implementation
	void operator=(const COleDataObject&);  // no implementation
};


#endif//COLEDATAOBJECT_DEFINE