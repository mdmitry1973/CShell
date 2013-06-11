// document4Doc.cpp : implementation of the Cdocument4Doc class
//

#include "stdafx.h"
#include "document4.h"

#include "document4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cdocument4Doc

IMPLEMENT_DYNCREATE(Cdocument4Doc, CDocument)

BEGIN_MESSAGE_MAP(Cdocument4Doc, CDocument)
END_MESSAGE_MAP()


// Cdocument4Doc construction/destruction

Cdocument4Doc::Cdocument4Doc()
{
	// TODO: add one-time construction code here

}

Cdocument4Doc::~Cdocument4Doc()
{
}

BOOL Cdocument4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// Cdocument4Doc serialization

void Cdocument4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// Cdocument4Doc diagnostics

#ifdef _DEBUG
void Cdocument4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cdocument4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cdocument4Doc commands
