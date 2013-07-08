/*
 *  CSize.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CSIZE_DEFINE
#define CSIZE_DEFINE 1

class CSHELL_LIB_EXPORT CSize : public SIZE
{
	
public:
	
	CSize();
	virtual ~CSize();
	
	CSize(int initCX, int initCY);
	CSize( SIZE initSize);
	CSize( POINT initPt);
	CSize( DWORD dwSize);
	
	/*
	// Operations
	BOOL operator==( SIZE size) const throw();
	BOOL operator!=( SIZE size) const throw();
	void operator+=( SIZE size) throw();
	void operator-=( SIZE size) throw();
	void SetSize( int CX,  int CY) throw();
	
	// Operators returning CSize values
	CSize operator+( SIZE size) const throw();
	CSize operator-( SIZE size) const throw();
	CSize operator-() const throw();
	
	// Operators returning CPoint values
	CPoint operator+( POINT point) const throw();
	CPoint operator-( POINT point) const throw();
	
	// Operators returning CRect values
	CRect operator+( const RECT* lpRect) const throw();
	CRect operator-( const RECT* lpRect) const throw();
	 
	 */
};

#endif//CSIZE_DEFINE
