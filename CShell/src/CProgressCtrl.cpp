/*
 *  CProgressCtrl.mm
 *  CShell
 *
 *  Created by Dmitry Mikhaevich on 12/25/11.
 *  Copyright 2011 Dmitry Mikhaevich. All rights reserved.
 *
 */

#import <QProgressBar>

#include "CProgressCtrl.h"


CProgressCtrl::CProgressCtrl() : CWnd()
{
	
}

BOOL CProgressCtrl::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	return CreateEx(0, dwStyle, rect, pParentWnd, nID);
}

BOOL CProgressCtrl::CreateEx(DWORD dwExStyle, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
    QWidget *parentView = (QWidget *)pParentWnd->GetNSWindow();
    QProgressBar *progressBox = new QProgressBar(parentView);
    QRect contentRect(rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top);

    progressBox->move (contentRect.x(), contentRect.y());
    progressBox->resize(contentRect.width(), contentRect.height());

    progressBox->setAccessibleName(QString().setNum(nID));

    m_hWnd = progressBox;
    mParentWin = pParentWnd;

	return TRUE;
}

void CProgressCtrl::SetRange(short nLower, short nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QProgressBar *progressBox = (QProgressBar *)m_hWnd;

        progressBox->setMinimum(nLower);
        progressBox->setMaximum(nUpper);
	}
}

void CProgressCtrl::SetRange32(int nLower, int nUpper)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QProgressBar *progressBox = (QProgressBar *)m_hWnd;

        progressBox->setMinimum(nLower);
        progressBox->setMaximum(nUpper);
	}
}

int CProgressCtrl::SetPos(int nPos)
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QProgressBar *progressBox = (QProgressBar *)m_hWnd;

        progressBox->setValue(nPos);
	}
	
	return 0;
}

int CProgressCtrl::GetPos()
{
	assert(m_hWnd);
	
	if (m_hWnd)
	{
        QProgressBar *progressBox = (QProgressBar *)m_hWnd;

        return progressBox->value();
	}
	
	return 0;
}
