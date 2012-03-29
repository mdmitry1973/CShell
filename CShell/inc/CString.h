/*
 *  CString.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <string>
#include <map>

#ifndef CSTRING_DEFINE
#define CSTRING_DEFINE 1

class CString : public std::string
{
	
public:
	
	CString();
	CString(const char *);
	virtual ~CString();
	
	BOOL LoadString(HINSTANCE hInstance, UINT nID, WORD wLanguageID);
	BOOL LoadString(HINSTANCE hInstance, UINT nID);
	BOOL LoadString(UINT nID);
	
	BOOL IsEmpty( ) const;
	
	CString Format(const char *, ...);
	
	int GetLength() const;
	
	void Empty();
	
	int Find(TCHAR ch) const;
	int Find(LPCTSTR lpszSub) const;
	int Find(TCHAR ch, int nStart) const;
	int Find(LPCTSTR pstr, int nStart) const;
	
	operator LPCTSTR() const;      // as a UTF8 string
	
	CString Mid(int nFirst) const;	
	CString Mid(int nFirst, int nCount) const;	
	int Replace(TCHAR chOld, TCHAR chNew);	
	int Replace(LPCTSTR lpszOld, LPCTSTR lpszNew);
	CString Left(int nCount) const;
	CString Right(int nCount) const;
	
	char operator[](int nIndex) const;
	

protected:
	
	static std::map<int, std::string> g_mapResStrimgs;
};


#endif//CSTRING_DEFINE