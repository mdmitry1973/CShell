// document4View.h : interface of the Cdocument4View class
//


#pragma once


class Cdocument4View : public CView
{
protected: // create from serialization only
	Cdocument4View();
	DECLARE_DYNCREATE(Cdocument4View)

// Attributes
public:
	Cdocument4Doc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cdocument4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in document4View.cpp
inline Cdocument4Doc* Cdocument4View::GetDocument() const
   { return reinterpret_cast<Cdocument4Doc*>(m_pDocument); }
#endif

