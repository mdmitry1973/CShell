/*
 *  CString.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDir>
#include <QtXml>
#include <QDomDocument>
#include <QFile>
#include <stdio.h>
#include <stdarg.h>
#include <algorithm>


#include "CDef.h"

#include "CString.h"

std::map<int, stdString> CString::g_mapResStrimgs;

CString::CString()
{
	bufferTemp = NULL;
    m_bufferTempSize = 0;
}

CString::CString(const TCHAR *str) : stdString(str)
{
	bufferTemp = NULL;
    m_bufferTempSize = 0;
}

CString::CString(const TCHAR *s, size_t len) : stdString(s, len)
{
	bufferTemp = NULL;
    m_bufferTempSize = 0;
}

CString::CString(const CString &str) : stdString(str)
{
	bufferTemp = NULL;
    m_bufferTempSize = 0;
}

CString::CString(TCHAR ch, int nRepeat) : stdString(nRepeat, ch)
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
        QString resPath = QDir::currentPath();
        QDomDocument doc;
        QFile file(resPath + "\\Resources.xml");
        int errorLine, errorColumn;
        QString errorMsg;

        if (!file.open(QIODevice::ReadOnly))
        {
           return FALSE;
        }

        if (!doc.setContent(&file, &errorMsg, &errorLine, &errorColumn))
        {
            file.close();
            return FALSE;
        }

        file.close();

        QDomElement docElem = doc.documentElement();

        QDomElement stringTable = docElem.firstChildElement("STRINGTABLE");

        while(!stringTable.isNull())
        {
            QDomElement stringTableItem = stringTable.firstChildElement("STR");

            while(!stringTableItem.isNull())
            {
                QString strValue = stringTableItem.text();
                QDomNamedNodeMap attrs = stringTableItem.attributes();

                QDomNode idAttr = attrs.namedItem("ID");
                QDomNode idStrAttr = attrs.namedItem("IDSTR");

                int ID = -1;

                if (!idAttr.isNull())
                {
                    ID = idAttr.nodeValue().toInt();
                }

                if (ID != -1)
                {
                    strValue = strValue.replace("\\n", "\n");
                    strValue = strValue.replace("\\r", "\r");
                    strValue = strValue.replace("\\t", "\t");

                    g_mapResStrimgs[ID] = strValue.toStdWString();
                }

                stringTableItem = stringTableItem.nextSiblingElement("STR");
            }

            stringTable = stringTable.nextSiblingElement("STRINGTABLE");
        }
	}
	
    stdString str = g_mapResStrimgs[nID];
	
    *((stdString *)this) = str;
	
	return str.size();

    return 0;
}

BOOL CString::IsEmpty( ) const
{
	return (length() == 0);
}

CString CString::Format(const TCHAR *strFormat, ...)
{
    /*
    char *buffer = new char[5000];
    va_list args;
    va_start (args, strFormat);
    vsprintf (buffer, strFormat, args);
    perror (buffer);
    va_end (args);

    *this = buffer;

    delete [] buffer;
*/

    va_list argList;
	va_start(argList, strFormat);
	
    /*
    {
		NSString *str = [[NSString alloc] initWithFormat:[NSString stringWithUTF8String: strFormat] arguments:argList];
	
		(*(std::string *)this) = [str UTF8String];
	
		[str release];
    }*/

    int maxSize = 10000;
    TCHAR *buffer = new TCHAR[maxSize];
    //QString str = QString::fromWCharArray(strFormat);

    //str.vsprintf(strFormat, argList);

    vswprintf(buffer, maxSize, strFormat, argList);

	va_end(argList);

   // *this = str.toStdWString().c_str();

    *this = buffer;

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

CString operator+(const TCHAR * lpsz, const CString& string)
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

int CString::Compare(LPCTSTR lpsz) const
{
    return compare(lpsz);
}

int CString::CompareNoCase(LPCTSTR lpsz) const
{
    stdString str1 = lpsz;
    stdString str2 = *this;
	
	std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	std::transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	
	return str1.compare(str2);
}

int CString::Remove( TCHAR ch )
{
	int count = 0;
	int pos;
	
	
	do
	{
		pos = find(ch);
		
		if (pos != -1)
		{
			count++;
            *((stdString *)this) = replace(pos, 1, _T(""));
		}
	}
	while(pos != -1);
	
	return count;
}

int CString::Replace(TCHAR chOld, TCHAR chNew)
{
	int count = 0;
    stdString strNew;
	int pos;
	
	strNew += chNew;
	
	do
	{
		pos = find(chOld);
		
		if (pos != -1)
		{
			count++;
            *((stdString *)this) = replace(pos, 1, strNew);
		}
	}
	while(pos != -1);
	
	return count;
}

int CString::Replace(LPCTSTR lpszOld, LPCTSTR lpszNew)
{
	int count = 0;
    stdString strNew;
	int pos;

    strNew += lpszNew;

	do
	{
        pos = find(lpszOld);
		
		if (pos != -1)
		{
			count++;
            *((stdString *)this) = replace(pos, 1, strNew);
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
	
    bufferTemp = new TCHAR [nMinBufLength];
	m_bufferTempSize = nMinBufLength;
	
	return bufferTemp;
}

void CString::ReleaseBuffer( int nNewLength)
{
	if (bufferTemp)
	{
        QString str = QString::fromWCharArray(bufferTemp);
        *this = stdString(bufferTemp, nNewLength == -1  ? str.length() : nNewLength).c_str();
		m_bufferTempSize = 0;
		delete [] bufferTemp;
		bufferTemp = 0;
	}
}

LPTSTR CString::GetBufferSetLength( int nNewLength )
{
	if (bufferTemp)
	{
        TCHAR *tempBuffer = new TCHAR[m_bufferTempSize + 1];
		
        memcpy(tempBuffer, bufferTemp, (m_bufferTempSize + 1) * sizeof(TCHAR));
		
		if (bufferTemp)
			delete [] bufferTemp;
		
        bufferTemp = new TCHAR [nNewLength];
		
        //strncpy(bufferTemp, tempBuffer, nNewLength);
        memcpy(bufferTemp, tempBuffer, (nNewLength + 1) * sizeof(TCHAR));
		
		delete [] tempBuffer;
	}
	else 
	{
        bufferTemp = new TCHAR [nNewLength];
		m_bufferTempSize = nNewLength;
	}
	
	return bufferTemp;
}

CString CString::Tokenize(const TCHAR *pszTokens, int& iStart) const
{
	CString res;
	size_t f_pos;
	
	if (iStart == -1)
	{
        return _T("");
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

BOOL operator ==(const BYTE  *s1, const CString& s2 )
{
    return s2.compare((const TCHAR *)s1) == 0;
}


