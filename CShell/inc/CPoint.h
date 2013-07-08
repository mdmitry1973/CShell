/*
 *  CPoint.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 11/27/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#ifndef CPOINT_DEFINE
#define CPOINT_DEFINE 1

class CSHELL_LIB_EXPORT CPoint : public POINT
{
	
public:
	
	CPoint();
	virtual ~CPoint();
	
	CPoint( int initX, int initY);
	CPoint( POINT initPt);
	CPoint( SIZE initSize);
	CPoint( LPARAM dwPoint);
	
	
	// Operations
	
	// translate the point
	void Offset(int xOffset, int yOffset) ;
	void Offset( POINT point) ;
	void Offset( SIZE size) ;
	void SetPoint( int X,int Y) ;
	
	/*
	BOOL operator==( POINT point) const throw();
	BOOL operator!=( POINT point) const throw();
	void operator+=( SIZE size) throw();
	void operator-=( SIZE size) throw();
	void operator+=( POINT point) throw();
	void operator-=( POINT point) throw();
	
	// Operators returning CPoint values
	CPoint operator+( SIZE size) const throw();
	CPoint operator-( SIZE size) const throw();
	CPoint operator-() const throw();
	CPoint operator+( POINT point) const throw();
	
	// Operators returning CSize values
	CSize operator-( POINT point) const throw();
	
	// Operators returning CRect values
	CRect operator+( const RECT* lpRect) const throw();
	CRect operator-( const RECT* lpRect) const throw();
	 */
};

#endif//CPOINT_DEFINE
