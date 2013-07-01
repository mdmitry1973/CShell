/*
 *  CEdit.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QTextEdit>

#include "CEdit.h"


CEdit::CEdit() : CWnd()
{
	
}

CEdit::~CEdit()
{

}

BOOL CEdit::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    QWidget *parentView = (QWidget *)pParentWnd->GetNSWindow();
    QTextEdit *edit = NULL;
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    edit = new QTextEdit(parentView);

    edit->move (contentRect.x(), contentRect.y());
    edit->resize(contentRect.width(), contentRect.height());

    edit->setAccessibleName(QString().setNum(nID));

    m_hWnd = edit;
    mParentWin = pParentWnd;

	return TRUE;
}

DWORD CEdit::GetSel() const
{
    int nStartChar;
    int nEndChar;
    DWORD res = 0;

    assert(m_hWnd);

    if (m_hWnd)
    {
        QTextEdit *edit = (QTextEdit *)m_hWnd;
        QTextCursor c = edit->textCursor();

        nStartChar = c.selectionStart();
        nEndChar = c.selectionEnd();

        res = (short)nStartChar;
        res = ((short)nEndChar << 16) | res;
    }
	
	return res;
}

void CEdit::GetSel(int& nStartChar, int& nEndChar) const
{
    assert(m_hWnd);

    if (m_hWnd)
    {
        QTextEdit *edit = (QTextEdit *)m_hWnd;
        QTextCursor c = edit->textCursor();

        nStartChar = c.selectionStart();
        nEndChar = c.selectionEnd();
    }
}

void CEdit::SetSel(DWORD dwSelection, BOOL bNoScroll)
{
    assert(m_hWnd);

    if (m_hWnd)
    {
        int nStartChar;
        int nEndChar;
        QTextEdit *edit = (QTextEdit *)m_hWnd;
        QTextCursor c = edit->textCursor();

        nStartChar = dwSelection & 0x0000ffff;
        nEndChar = (dwSelection & 0xffff0000) >> 16;

        c.setPosition(nStartChar);
        c.setPosition(nEndChar, QTextCursor::KeepAnchor);
        edit->setTextCursor(c);
    }
}

void CEdit::SetSel(int nStartChar, int nEndChar, BOOL bNoScroll)
{
    assert(m_hWnd);

    if (m_hWnd)
    {
        QTextEdit *edit = (QTextEdit *)m_hWnd;
        QTextCursor c = edit->textCursor();

        c.setPosition(nStartChar);
        c.setPosition(nEndChar, QTextCursor::KeepAnchor);
        edit->setTextCursor(c);
    }
}

void CEdit::SetLimitText(UINT nMax)
{
    qDebug() << "TO DO CEdit::SetLimitText";
}

BOOL CEdit::SetCueBanner(LPCWSTR lpcwText)
{
    qDebug() << "TO DO CEdit::SetLimitText";
	
	return TRUE;
}

void CEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        //NSRange range;
		
        //range = [[((CNSTextField *)m_hWnd) currentEditor] selectedRange];
        ///[[((CNSTextField *)m_hWnd) currentEditor] replaceCharactersInRange:range
        //											withString:[NSString stringWithFormat: @"%c", nChar]];
        //[((CNSTextField *)m_hWnd) setSkipChar: true];
	}
}

