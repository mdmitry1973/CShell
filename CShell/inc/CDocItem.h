/*
 *  CDocItem.h
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include "CDef.h"
#include "CWnd.h"

#ifndef CDOCITEM_DEFINE
#define CDOCITEM_DEFINE 1

class CDocument;

class CDocItem : public CCmdTarget
{
	//DECLARE_SERIAL(CDocItem)
	
	// Constructors
protected:      // abstract class
	CDocItem();
	
	// Attributes
public:
	CDocument* GetDocument() const; // return container document
	
	// Overridables
public:
	// Raw data access (native format)
	virtual BOOL IsBlank() const;
	
	// Implementation
//protected:
//	COleDocument* m_pDocument;
	
public:
	virtual void Serialize(CArchive& ar);   // for Native data
	virtual ~CDocItem();

	//friend class COleDocument;              // for access to back pointer
};


#endif//CDOCITEM_DEFINE