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
	
}

CString::CString(const char *str) : std::string(str)
{
	
}

CString::~CString()
{

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

