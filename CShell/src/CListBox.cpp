/*
 *  CListBox.cpp
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/12/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#include <QListWidget>

#include "CListBox.h"


CListBox::CListBox() : CWnd()
{
	
}

BOOL CListBox::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    QWidget *parentView = (QWidget *)pParentWnd->GetNSWindow();
    QListWidget *listBox = new QListWidget(parentView);
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    listBox->move (contentRect.x(), contentRect.y());
    listBox->resize(contentRect.width(), contentRect.height());

    listBox->setAccessibleName(QString().setNum(nID));

    m_hWnd = listBox;
    mParentWin = pParentWnd;
	
	return TRUE;
}

int CListBox::AddString(LPCTSTR lpszItem)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;

        listBox->addItem(QString::fromWCharArray(lpszItem));

        return listBox->count();
	}
	
	return LB_ERR;
}

int CListBox::InsertString(int nIndex, LPCTSTR lpszItem)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;

        listBox->insertItem(nIndex, QString::fromWCharArray(lpszItem));

        return nIndex;
	}
	
	return LB_ERR;
}

int CListBox::DeleteString(UINT nIndex)
{
	assert(m_hWnd);

	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;
        QListWidgetItem *item = listBox->item(nIndex);
        listBox->removeItemWidget(item);

        return listBox->count();
	}

	return LB_ERR;
}

int CListBox::FindString(int nStartAfter, LPCTSTR lpszItem) const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;

        for(int i = 0; i < listBox->count(); i++)
        {
            QListWidgetItem *item = listBox->item(i);

            if (item->text() == QString::fromWCharArray(lpszItem))
            {
                return i;
            }
        }
	}
	
	return LB_ERR;
}

int CListBox::GetCount() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;

        return listBox->count();
	}
	
	return LB_ERR;
}

int CListBox::GetCurSel() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;

        return listBox->currentRow();
	}
	
	return LB_ERR;
}

int CListBox::GetSelCount() const
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;
        QList<QListWidgetItem *> listItems = listBox->selectedItems();

        return listItems.count();
	}
	
	return LB_ERR;
}

int CListBox::SetCurSel(int nSelect)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;

        listBox->setCurrentRow(nSelect);

        return listBox->currentRow();
	}
	
	return LB_ERR;
}

void CListBox::GetText(int nIndex, CString& rString) const
{

    if (m_hWnd)
    {
        QListWidget *listBox = (QListWidget *)m_hWnd;
        QString str = listBox->item(nIndex)->text();

        rString = str.toStdWString().c_str();
    }
}

void CListBox::ResetContent()
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QListWidget *listBox = (QListWidget *)m_hWnd;

        listBox->clear();
	}
}
