// NumEdit.cpp : implementation file
//

#include "stdafx.h"
#include "NumEdit.h"
#include "Float.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumEdit

IMPLEMENT_DYNAMIC(CNumEdit, CEdit)

CNumEdit::CNumEdit()
{
	m_NumberOfNumberAfterPoint = 0;
	m_Verbose = FALSE;
	m_MinValue = -FLT_MAX;
	m_MaxValue = FLT_MAX;
	m_Delta = FLT_ROUNDS;
}

CNumEdit::~CNumEdit()
{
}


BEGIN_MESSAGE_MAP(CNumEdit, CEdit)
	//{{AFX_MSG_MAP(CNumEdit)
	ON_WM_CHAR()
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumEdit message handlers

float CNumEdit::GetValue() const
{
	float f = m_MinValue;
	if (IsValid(FALSE) == VALID)
	{
		CString str;
		GetWindowText(str);
		sscanf(str, _T("%f"), &f);
	}
	return f;
}

BOOL CNumEdit::SetValue(float val)
{
	if (val > m_MaxValue || val < m_MinValue) return FALSE;
	CString str, s;
	str.Format(ConstructFormat(s, val), val);
	SetWindowText(str);
	return TRUE;
}

int CNumEdit::IsValid(BOOL show_message) const
{
	CString str;
	GetWindowText(str);
	int res = VALID;
	float f;
	char lp[10];
	
	if ((str.GetLength() == 1) && ((str[0] == '+') || (str[0] == '-'))) 
		res = MINUS_PLUS;
	else
	if (sscanf(str, _T("%f%s"), &f, lp) != 1) 
		res = INVALID_CHAR;
	else
	if (f > m_MaxValue) 
	{
		res = OUT_OF_RANGE_MAX;
	}
	else
	if (f < m_MinValue) 
	{
		res = OUT_OF_RANGE_MIN;
	}

	if (show_message && m_Verbose && (res != VALID) && (res != MINUS_PLUS))
	{
		str.Empty();
		if ((res & OUT_OF_RANGE_MAX) || (res & OUT_OF_RANGE_MIN)) 
		{
			CString str2;
			
			str += _T("Given value is out of range.");
			
			str2.Format(_T(" Min=%.2f Max=%.2f\n"), m_MinValue, m_MaxValue);

			str += str2;
		}
		if (res & INVALID_CHAR) 
			str += _T("Characters must be a number.\n");
		AfxMessageBox(str, MB_OK | MB_ICONSTOP);
	}

	return res;
}

int CNumEdit::IsValidSymble()const
{
	CString str;
	GetWindowText(str);
	int res = VALID;
	float f;
	char lp[10];
	if ((str.GetLength() == 1) && ((str[0] == '+') || (str[0] == '-'))) 
		res = MINUS_PLUS;
	else
	if (sscanf(str, _T("%f%s"), &f, lp) != 1) 
		res = INVALID_CHAR;
	
	return res;
}

int CNumEdit::IsValid(const CString &str) const
{
	int res = VALID;
	float f;
	char lp[10];

	if ((str.GetLength() == 1) && ((str[0] == '+') || (str[0] == '-'))) 
		res = MINUS_PLUS;
	else 
	if (sscanf(str, _T("%f%s"), &f, lp) != 1) 
		res = INVALID_CHAR;
	else 
	if (f > m_MaxValue) 
		res = OUT_OF_RANGE_MAX;
	else
	if (f < m_MinValue) 
		res = OUT_OF_RANGE_MIN;

	if (m_Verbose && (res != VALID) && (res != MINUS_PLUS))
	{
		CString msg;
	
		if ((res & OUT_OF_RANGE_MAX) || (res & OUT_OF_RANGE_MIN)) 
		{
			CString str2;

			msg += _T("Given value is out of range.");

			str2.Format(_T(" Min=%.2f Max=%.2f\n"), m_MinValue, m_MaxValue);

			msg += str2;
		}

		if (res & INVALID_CHAR) 
			msg += _T("Characters must be a number.\n");

		if (!msg.IsEmpty())
		{
			AfxMessageBox(str, MB_OK | MB_ICONSTOP);
		}
	}

	return res;
}

void CNumEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if (nChar == ' ') return;
	float oldValue;
	oldValue = GetValue();
	CEdit::OnChar(nChar, nRepCnt, nFlags);
	int val = IsValidSymble();

	if (m_Verbose && (val != VALID) && (val != MINUS_PLUS))
	{
		CString str;
		
		if (val & INVALID_CHAR) 
		{
			SetValue(oldValue);
			SetSel(0, -1);
			str += _T("Characters must be a number.\n");
			AfxMessageBox(str, MB_OK | MB_ICONSTOP);
		}
	}

	CString s;
	switch (val)
	{
		case VALID:
			//ConstructFormat(s, GetValue());
			break;
		case MINUS_PLUS: break;
		default:
			SetValue(oldValue);
			SetSel(0, -1);
			MSG msg;
			while (::PeekMessage(&msg, m_hWnd, WM_CHAR, WM_CHAR, PM_REMOVE));
			break;
	}
}

void CNumEdit::OnKillFocus(CWnd* win) 
{
	CEdit::OnKillFocus(win);
	
	int res = IsValid(TRUE);
	
	if (res != VALID) 
	{
		if ((res & OUT_OF_RANGE_MAX))
		{
			SetValue(m_MaxValue);
		}
		else
		if ((res & OUT_OF_RANGE_MIN))
		{
			SetValue(m_MinValue);
		}
	}
}

BOOL CNumEdit::Verbose() const
{
	return m_Verbose;
}

void CNumEdit::Verbose(BOOL v)
{
	m_Verbose = v;
}

void CNumEdit::SetRange(float min, float max)
{
	m_MinValue = min;
	m_MaxValue = max;
}

void CNumEdit::GetRange(float & min, float & max) const
{
	min = m_MinValue;
	max = m_MaxValue;
}

void CNumEdit::SetDelta(float delta)
{
	m_Delta = delta;
}

float CNumEdit::GetDelta()
{
	return m_Delta;
}

void CNumEdit::SetNumberOfNumberAfterPoint(BYTE nNumberOfNumberAfterPoint)
{
	m_NumberOfNumberAfterPoint = nNumberOfNumberAfterPoint;
}

void CNumEdit::ChangeAmount(int step)
{
	float f = GetValue() + step * m_Delta;
	if (f > m_MaxValue) f = m_MaxValue;
	else if (f < m_MinValue) f = m_MinValue;
	SetValue(f);
}

CString& CNumEdit::ConstructFormat(CString &str, float num)
{
	str.Format(_T("%G"), num);
	int n = str.Find('.');
	if (n >= 0)
	{
		n = str.GetLength() - n - 1;
		if (n > m_NumberOfNumberAfterPoint) m_NumberOfNumberAfterPoint = n;
	}
	str.Format(_T("%%.%df"), m_NumberOfNumberAfterPoint);
	return str;
}
