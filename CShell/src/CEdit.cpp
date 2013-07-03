/*
 *  CEdit.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QObject>
#include <QTextEdit>
#include <QLineEdit>

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
        QObject *obj = (QObject *)m_hWnd;
        QTextEdit *edit = dynamic_cast<QTextEdit *>(obj);

        if (edit)
        {
            QTextEdit *edit = (QTextEdit *)m_hWnd;
            QTextCursor c = edit->textCursor();

            nStartChar = c.selectionStart();
            nEndChar = c.selectionEnd();
        }
        else
        {
            QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(obj);

            if (lineEdit)
            {
                 nStartChar = lineEdit->selectionStart();
                 nEndChar = nStartChar + lineEdit->selectedText().size();
            }
        }

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
        QObject *obj = (QObject *)m_hWnd;
        QTextEdit *edit = dynamic_cast<QTextEdit *>(obj);

        if (edit)
        {
            QTextCursor c = edit->textCursor();

            nStartChar = c.selectionStart();
            nEndChar = c.selectionEnd();
        }
        else
        {
            QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(obj);

            if (lineEdit)
            {
                 nStartChar = lineEdit->selectionStart();
                 nEndChar = nStartChar + lineEdit->selectedText().size();
            }
        }
    }
}

void CEdit::SetSel(DWORD dwSelection, BOOL bNoScroll)
{
    assert(m_hWnd);

    if (m_hWnd)
    {
        int nStartChar;
        int nEndChar;

        nStartChar = dwSelection & 0x0000ffff;
        nEndChar = (dwSelection & 0xffff0000) >> 16;

        QObject *obj = (QObject *)m_hWnd;
        QTextEdit *edit = dynamic_cast<QTextEdit *>(obj);

        if (edit)
        {
            QTextCursor c = edit->textCursor();

            c.setPosition(nStartChar);
            c.setPosition(nEndChar, QTextCursor::KeepAnchor);
            edit->setTextCursor(c);
        }
        else
        {
            QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(obj);

            if (lineEdit)
            {
                 lineEdit->setSelection(nStartChar, nEndChar);
            }
        }
    }
}

void CEdit::SetSel(int nStartChar, int nEndChar, BOOL bNoScroll)
{
    assert(m_hWnd);

    if (m_hWnd)
    {
        QObject *obj = (QObject *)m_hWnd;
        QTextEdit *edit = dynamic_cast<QTextEdit *>(obj);

        if (edit)
        {
            QTextCursor c = edit->textCursor();

            c.setPosition(nStartChar);
            c.setPosition(nEndChar, QTextCursor::KeepAnchor);
            edit->setTextCursor(c);
        }
        else
        {
            QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(obj);

            if (lineEdit)
            {
                 lineEdit->setSelection(nStartChar, nEndChar);
            }
        }
    }
}

void CEdit::SetLimitText(UINT nMax)
{
    assert(m_hWnd);

    if (m_hWnd)
    {
        QObject *obj = (QObject *)m_hWnd;
        QTextEdit *edit = dynamic_cast<QTextEdit *>(obj);

        if (edit)
        {
            qDebug() << "TO DO CEdit::SetLimitText";
        }
        else
        {
            QLineEdit *lineEdit = dynamic_cast<QLineEdit *>(obj);

            if (lineEdit)
            {
                 lineEdit->setMaxLength(nMax);
            }
        }
    }
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

