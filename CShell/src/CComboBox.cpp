/*
 *  CComboBox.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/12/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QComboBox>

#include "CComboBox.h"

CComboBox::CComboBox() : CWnd()
{
    //type = eNSPopUpButton;
}

BOOL CComboBox::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    QWidget *parentView = (QWidget *)pParentWnd->GetNSWindow();
    QComboBox *comboBox = new QComboBox(parentView);
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    comboBox->move (contentRect.x(), contentRect.y());
    comboBox->resize(contentRect.width(), contentRect.height());

    comboBox->setAccessibleName(QString().setNum(nID));

    m_hWnd = comboBox;
    mParentWin = pParentWnd;

    return TRUE;
}

int CComboBox::AddString(LPCTSTR lpszString)
{
	int index = CB_ERR;
	
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QComboBox *comboBox = (QComboBox *)m_hWnd;

        comboBox->addItem(QString::fromStdWString(lpszString));

        index = comboBox->count();
	}
	
	return index;
}

int CComboBox::GetCount() const
{
	int res = 0;
	
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QComboBox *comboBox = (QComboBox *)m_hWnd;

        res = comboBox->count();
	}
	
	return res;
}

int CComboBox::GetCurSel() const
{
	int res = 0;
	
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QComboBox *comboBox = (QComboBox *)m_hWnd;

        res = comboBox->currentIndex();
	}
	
	return res;
}

int CComboBox::SetCurSel(int nSelect)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QComboBox *comboBox = (QComboBox *)m_hWnd;

        comboBox->setCurrentIndex(nSelect);
	}
	
	return GetCurSel();
}

int CComboBox::SelectString(int nStartAfter, LPCTSTR lpszString)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
		int count = GetCount();
		int start = nStartAfter != -1 ? nStartAfter : 0;
		CString rString;
		
		for(int i = start; i < count; i++)
		{
			GetLBText(i, rString);
			
			if (rString == lpszString)
			{
				SetCurSel(i);
				return i;
			}
		}
	}
	
	return CB_ERR;
}

int CComboBox::InsertString(int nIndex, LPCTSTR lpszString)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QComboBox *comboBox = (QComboBox *)m_hWnd;

        comboBox->insertItem(nIndex, QString::fromStdWString(lpszString));
		
		return nIndex + 1;
	}
	
	return CB_ERR;
}

int CComboBox::GetLBText(int nIndex, LPTSTR lpszText) const
{
    QString text;

    assert(m_hWnd);

    if (m_hWnd)
    {
       QComboBox *comboBox = (QComboBox *)m_hWnd;
       text = comboBox->itemText(nIndex);
       wcscpy(lpszText, text.toStdWString().c_str());
    }

    return text.length();
}

void CComboBox::GetLBText(int nIndex, CString& rString) const
{
    assert(m_hWnd);
	
	if (m_hWnd)
	{
        QString text;
        QComboBox *comboBox = (QComboBox *)m_hWnd;
        text = comboBox->itemText(nIndex);

        rString = text.toStdWString().c_str();
	}
}

int CComboBox::GetLBTextLen(int nIndex) const
{
    assert(m_hWnd);

    if (m_hWnd)
    {
        QString text;
        QComboBox *comboBox = (QComboBox *)m_hWnd;
        text = comboBox->itemText(nIndex);

        return text.length();
    }

	return 0;
}

