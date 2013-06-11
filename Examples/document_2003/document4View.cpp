// document4View.cpp : implementation of the Cdocument4View class
//

#include "stdafx.h"
#include "document4.h"

#include "document4Doc.h"
#include "document4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cdocument4View

IMPLEMENT_DYNCREATE(Cdocument4View, CView)

BEGIN_MESSAGE_MAP(Cdocument4View, CView)
	// Standard printing commands
	//ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	//ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	//ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cdocument4View construction/destruction

Cdocument4View::Cdocument4View()
{
	// TODO: add construction code here

}

Cdocument4View::~Cdocument4View()
{
}

BOOL Cdocument4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cdocument4View drawing

void Cdocument4View::OnDraw(CDC* /*pDC*/)
{
	Cdocument4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cdocument4View printing

BOOL Cdocument4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cdocument4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cdocument4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cdocument4View diagnostics

#ifdef _DEBUG
void Cdocument4View::AssertValid() const
{
	CView::AssertValid();
}

void Cdocument4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cdocument4Doc* Cdocument4View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cdocument4Doc)));
	return (Cdocument4Doc*)m_pDocument;
}
#endif //_DEBUG


// Cdocument4View message handlers
