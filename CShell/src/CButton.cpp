/*
 *  CButton.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QDebug>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>

#include "CButton.h"

CButton::CButton() : CWnd()
{
	
}

CButton::~CButton()
{
	
}

BOOL CButton::Create(LPCTSTR lpszCaption,
					DWORD dwStyle,
					const RECT& rect,
					CWnd* pParentWnd,
					UINT nID 
					)
{
    QWidget *parentView = (QWidget *)pParentWnd->GetNSWindow();
    QAbstractButton *button = NULL;
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    if (dwStyle & BS_AUTORADIOBUTTON || dwStyle & BS_RADIOBUTTON)
    {
        button = new QRadioButton(parentView);

    }
    else
    if (dwStyle & BS_CHECKBOX || dwStyle & BS_AUTOCHECKBOX)
    {
        button = new QCheckBox(parentView);
    }
    else
    {
        button = new QPushButton(parentView);
    }

    button->move (contentRect.x(), contentRect.y());
    button->resize(contentRect.width(), contentRect.height());
    button->setText(QString::fromWCharArray(lpszCaption));

    button->setAccessibleName(QString().setNum(nID));

    m_hWnd = button;
    mParentWin = pParentWnd;

	return TRUE;
}

void CButton::SetCheck(int nCheck)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QAbstractButton *button = (QAbstractButton *)m_hWnd;

        button->setChecked(nCheck);
	}
}

void CButton::SetButtonStyle(UINT nStyle, BOOL bRedraw)
{
    qDebug() << "TO DO CButton::SetButtonStyle";
}

void CButton::SetState(BOOL bHighlight)
{
    qDebug() << "TO DO CButton::SetState";
}

int CButton::GetCheck() const
{
    qDebug() << "TO DO CButton::GetCheck";
	return 0;
}

HBITMAP CButton::SetBitmap(HBITMAP hBitmap)
{
    qDebug() << "TO DO CButton::SetBitmap";
	return 0;
}

HICON CButton::SetIcon(HICON hIcon)
{
    qDebug() << "TO DO CButton::SetIcon";
	return 0;
}
