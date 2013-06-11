// document4Doc.h : interface of the Cdocument4Doc class
//


#pragma once

class Cdocument4Doc : public CDocument
{
protected: // create from serialization only
	Cdocument4Doc();
	DECLARE_DYNCREATE(Cdocument4Doc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~Cdocument4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


