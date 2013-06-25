/*
 *  CString.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */


#ifndef CSTRING_DEFINE
#define CSTRING_DEFINE 1

#include <string>
#include <map>

#include "CDef.h"

class CSHELL_LIB_EXPORT CString : public std::string
{
	
public:
	
	CString();
	CString(const char *);
	CString(const char *s, size_t len);
	CString(const CString &str);
	CString(char ch, int nRepeat = 1);
	virtual ~CString();
	
	BOOL LoadString(HINSTANCE hInstance, UINT nID, WORD wLanguageID);
	BOOL LoadString(HINSTANCE hInstance, UINT nID);
	BOOL LoadString(UINT nID);
	
	BOOL IsEmpty( ) const;
	
	CString Format( UINT nFormatID, ... );
	CString Format(const char *, ...);
	
	int GetLength() const;
	
	void Empty();
	
	int Find(TCHAR ch) const;
	int Find(LPCTSTR lpszSub) const;
	int Find(TCHAR ch, int nStart) const;
	int Find(LPCTSTR pstr, int nStart) const;
	int ReverseFind(TCHAR ch) const;
	int FindOneOf( LPCTSTR lpszCharSet ) const;
	
	int Compare( LPCTSTR lpsz ) const;
	int CompareNoCase(LPCTSTR lpsz) const;
	
	operator LPCTSTR() const;      // as a UTF8 string
	
	CString Mid(int nFirst) const;	
	CString Mid(int nFirst, int nCount) const;	
	int Replace(TCHAR chOld, TCHAR chNew);	
	int Replace(LPCTSTR lpszOld, LPCTSTR lpszNew);
	CString Left(int nCount) const;
	CString Right(int nCount) const;
	
	char operator[](int nIndex) const;
	
	LPTSTR GetBuffer( int nMinBufLength );
	void ReleaseBuffer( int nNewLength = -1 );
	LPTSTR GetBufferSetLength( int nNewLength );
	
	friend CString operator+(const CString& string1,	const CString& string2);
	friend CString operator+(const CString& string,		TCHAR ch);
	friend CString operator+(TCHAR ch, 					const CString& string);
	friend CString operator+(const CString& string,		const TCHAR * lpsz);
	friend CString operator+(const TCHAR * lpsz,		const CString& string);
	
	CString Tokenize(const char *pszTokens, int& iStart) const;
	
	int Remove( TCHAR ch );
	
	int Delete( int nIndex, int nCount = 1); 

protected:
	
	static std::map<int, std::string> g_mapResStrimgs;
	
	char	*bufferTemp;
	int		m_bufferTempSize;
};

BOOL operator ==(const BYTE  *s1, const CString& s2 );


#endif//CSTRING_DEFINE