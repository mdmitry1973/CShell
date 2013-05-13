/*
 *  CString.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"

#include "CString.h"

std::map<int, std::string> CString::g_mapResStrimgs;

CString::CString()
{
	bufferTemp = NULL;
	m_bufferTempSize = 0;
}

CString::CString(const char *str) : std::string(str)
{
	bufferTemp = NULL;
	m_bufferTempSize = 0;
}

CString::CString(const char *s, size_t len) : std::string(s, len)
{
	bufferTemp = NULL;
	m_bufferTempSize = 0;
}

CString::CString(const CString &str) : std::string(str)
{
	bufferTemp = NULL;
	m_bufferTempSize = 0;
}

CString::CString(char ch, int nRepeat) : std::string (nRepeat, ch)
{
	bufferTemp = NULL;
	m_bufferTempSize = 0;
}

CString::~CString()
{
	if (bufferTemp)
		delete [] bufferTemp;
}

BOOL CString::LoadString(HINSTANCE hInstance, UINT nID, WORD wLanguageID)
{
	return LoadString(nID);
}

BOOL CString::LoadString(HINSTANCE hInstance, UINT nID)
{
	return LoadString(hInstance, nID, -1);
}

BOOL CString::LoadString(UINT nID)
{
	if (g_mapResStrimgs.size() == 0)
	{		
		NSBundle *resBundle = [NSBundle mainBundle];
		
		if (resBundle)
		{
			NSString *resFilePath = [resBundle pathForResource: @"Resources" ofType:@"xml"];
			
			if (resFilePath)
			{
				NSError *error = nil;
				NSXMLDocument *doc = [[NSXMLDocument alloc] initWithData:[NSData dataWithContentsOfFile: resFilePath] options:NSXMLDocumentTidyXML error:&error];
				
				if (doc)
				{
					//<MFC_RESOURCE>
					//<STRINGTABLE>
					//<STR ID="101" IDSTR="IDS_ABOUTBOX">About SimpleDialog2...</STR>
					
					NSString *xpath = [NSString stringWithFormat: @"/MFC_RESOURCE/STRINGTABLE/STR"];
					NSArray *arrWindowsNode = [doc nodesForXPath:xpath error:&error];
					
					for(int i = 0; i < [arrWindowsNode count]; i++)
					{
						NSXMLElement *StrNode = [arrWindowsNode objectAtIndex:i];	
						
						NSXMLNode *attrID = [StrNode attributeForName: @"ID"];
						//NSXMLNode *attrIDSTR = [StrNode attributeForName: @"IDSTR"];
						NSString *strValue = [StrNode stringValue];
						int ID = -1;
						
						if (attrID)
						{
							ID = [[attrID stringValue] intValue];
						}
						
						if (ID != -1)
						{
							strValue = [strValue stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"];
							strValue = [strValue stringByReplacingOccurrencesOfString:@"\\r" withString:@"\r"];
							strValue = [strValue stringByReplacingOccurrencesOfString:@"\\t" withString:@"\t"];
							
							g_mapResStrimgs[ID] = [strValue UTF8String];
						}
					}
					
					[doc dealloc];
				}
				else 
				{
					assert(false);
				}
			}
			else 
			{
				assert(false);
			}
		}
		else 
		{
			assert(false);
		}
		
	}
	
	std::string str = g_mapResStrimgs[nID];
	
	*((std::string *)this) = str;
	
	return str.size();
}

BOOL CString::IsEmpty( ) const
{
	return (length() == 0);
}

CString CString::Format(const char *strFormat, ...)
{
	va_list argList;
	va_start(argList, strFormat);
	
	{
		NSString *str = [[NSString alloc] initWithFormat:[NSString stringWithUTF8String: strFormat] arguments:argList];
	
		(*(std::string *)this) = [str UTF8String];
	
		[str release];
	}
	
	va_end(argList);
	return (*this);
}

int CString::GetLength( ) const
{
	return length();
}

void CString::Empty()
{
	*((std::string *)this) = "";
}

CString::operator LPCTSTR() const
{
	return this->c_str();
}

CString operator+(const CString& string1, const CString& string2)
{
	CString str = string1;
	
	str += string2.c_str();
	
	return str;
}

CString operator+(const CString& string, TCHAR ch)
{
	CString str = string; 
	
	str += ch;
	
	return str;
}

CString operator+(TCHAR ch, const CString& string)
{
	CString str((char)ch);
	
	str += string;
	
	return str;
}

CString operator+(const CString& string, const TCHAR * lpsz)
{
	CString str = string;
	
	str += lpsz;
	
	return str;
}

CString operator+(const TCHAR * lpsz,		const CString& string)
{
	CString str = lpsz;
	
	str += string;
	
	return str;
}

int CString::Find(TCHAR ch) const
{
	return find(ch);
}

int CString::Find(LPCTSTR lpszSub) const
{
	return find(lpszSub);
}

int CString::Find(TCHAR ch, int nStart) const
{
	return find(ch, nStart);
}

int CString::Find(LPCTSTR pstr, int nStart) const
{
	return find(pstr, nStart);
}

int CString::FindOneOf( LPCTSTR lpszCharSet ) const
{
	return find_first_of(lpszCharSet);
}

CString CString::Mid(int nFirst) const
{
	return substr(nFirst, length()).c_str();
}

CString CString::Mid(int nFirst, int nCount) const
{
	return substr(nFirst, nCount).c_str();
}

int CString::Replace(TCHAR chOld, TCHAR chNew)
{
	int count = 0;
	std::string strNew;
	int pos;
	
	strNew += chNew;
	
	do
	{
		pos = find(chOld);
		
		if (pos != -1)
		{
			count++;
			*((std::string *)this) = replace(pos, 1, strNew);	
		}
	}
	while(pos != -1);
	
	return count;
}

int CString::Replace(LPCTSTR lpszOld, LPCTSTR lpszNew)
{
	int count = 0;
	std::string strNew;
	int pos;
	
	strNew += lpszNew;
	
	do
	{
		pos = find(lpszOld);
		
		if (pos != -1)
		{
			count++;
			*((std::string *)this) = replace(pos, 1, strNew);	
		}
	}
	while(pos != -1);
	
	return count;
}

CString CString::Left(int nCount) const
{
	return substr(0, nCount).c_str();
}

CString CString::Right(int nCount) const
{
	return substr(length() - nCount - 1, nCount).c_str();
}

char CString::operator[](int nIndex) const
{		
	return at(nIndex);
}

int CString::ReverseFind(TCHAR ch) const
{
	return rfind(ch);
}

LPTSTR CString::GetBuffer( int nMinBufLength )
{
	if (bufferTemp)
		delete [] bufferTemp;
	
	bufferTemp = new char [nMinBufLength];
	m_bufferTempSize = nMinBufLength;
	
	return bufferTemp;
}

void CString::ReleaseBuffer( int nNewLength)
{
	if (bufferTemp)
	{
		*this = std::string(bufferTemp, nNewLength == -1  ? strlen(bufferTemp) : nNewLength).c_str();
		m_bufferTempSize = 0;
		delete [] bufferTemp;
		bufferTemp = 0;
	}
}

LPTSTR CString::GetBufferSetLength( int nNewLength )
{
	if (bufferTemp)
	{
		char *tempBuffer = new char[m_bufferTempSize + 1];
		
		strcpy(tempBuffer, bufferTemp);
		
		if (bufferTemp)
			delete [] bufferTemp;
		
		bufferTemp = new char [nNewLength];
		
		strncpy(bufferTemp, tempBuffer, nNewLength);
		
		delete [] tempBuffer;
	}
	else 
	{
		bufferTemp = new char [nNewLength];
		m_bufferTempSize = nNewLength;
	}
	
	return bufferTemp;
}

CString CString::Tokenize(const char *pszTokens, int& iStart) const
{
	CString res;
	size_t f_pos;
	
	if (iStart == -1)
	{
		return "";
	}
	
	f_pos = find(pszTokens, iStart);
	
	if (f_pos != -1)
	{
		res = substr(iStart, f_pos - iStart).c_str();
		iStart = f_pos + 1;
	}
	else
	{
		res = substr(iStart, length()).c_str();
		iStart = -1;
	}
	
	return res;
}


